/*
    File: client_MP6.cpp

    Author: J. Higginbotham
    Department of Computer Science
    Texas A&M University
    Date  : 2016/05/21

    Based on original code by: Dr. R. Bettati, PhD
    Department of Computer Science
    Texas A&M University
    Date  : 2013/01/31

    MP6 for Dr. //Tyagi's
    Ahmed's sections of CSCE 313.
 */

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */
    /* -- This might be a good place to put the size of
        of the patient response buffers -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*
    As in MP7 no additional includes are required
    to complete the assignment, but you're welcome to use
    any that you think would help.
*/
/*--------------------------------------------------------------------------*/

#include <cassert>
#include <cstring>
#include <sys/stat.h>
#include <errno.h>
#include <sstream>
#include <sys/time.h>
#include <assert.h>
#include <fstream>
#include <numeric>
#include <vector>
#include "bounded_buffer.h"
/*
    This next file will need to be written from scratch, along with
    semaphore.h and (if you choose) their corresponding .cpp files.
 */



/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */
/*--------------------------------------------------------------------------*/


/*
    This class can be used to write to standard output
    in a multithreaded environment. It's primary purpose
    is printing debug messages while multiple threads
    are in execution.
 */
class atomic_standard_output {
    pthread_mutex_t console_lock;
public:
    atomic_standard_output() { pthread_mutex_init(&console_lock, NULL); }
    ~atomic_standard_output() { pthread_mutex_destroy(&console_lock); }
    void print(std::string s){
        pthread_mutex_lock(&console_lock);
        std::cout << s << std::endl;
        pthread_mutex_unlock(&console_lock);
    }
};

atomic_standard_output threadsafe_standard_output;

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* HELPER FUNCTIONS */
/*--------------------------------------------------------------------------*/

std::string make_histogram(std::string name, std::vector<int> *data) {
    std::string results = "Frequency count for " + name + ":\n";
    for(int i = 0; i < data->size(); ++i) {
        results += std::to_string(i * 10) + "-" + std::to_string((i * 10) + 9) + ": " + std::to_string(data->at(i)) + "\n";
    }
    return results;
}


void* request_thread_function(void* arg)
{
    Params* p = (Params*)arg;

    for(int i = 0; i < p->n; ++i)
    {
        p->request_buffer->push(p->data_pushed);
    }

    pthread_exit(0);
}

void* worker_thread_function(void* arg)
{
    Params* p = (Params*)arg;
    string request, response;

    
    int i = 1;
    while(true)
    {
        
        request = p->request_buffer->pop();

        
        response = p->chan->send_request(request);
        //cout << request << " " << i++ << endl;
        if(request == "data John Smith")
        {
           p->john_buffer->push(response); //Fill John's Response Buffer

        }
        else if(request == "data Jane Smith") 
        {
            p->jane_buffer->push(response); //Fill Jane's Response Buff

        }
        else if(request == "data Joe Smith") 
        {
            p->joe_buffer->push(response); //Fill Joe's Response Buff

        }
        else if(request == "quit")
        {
            break;
        }
    }
    
    pthread_exit(0);
    
}

void* stat_thread_function(void* arg)
{
    Params* p = (Params*)arg;
    for(int i =0; i < p->n; i++)
    {
        if(p->response_name == "John Smith")
        {
            string tmp = p->john_buffer->pop();
            p->john_frequency_count->at(stoi(tmp) / 10) += 1;
        }
        else if(p->response_name == "Jane Smith") 
        {
            string tmp = p->jane_buffer->pop();
            p->jane_frequency_count->at(stoi(tmp) / 10) += 1;
        }
        else if(p->response_name == "Joe Smith") 
        {
            string tmp = p->joe_buffer->pop();
            p->joe_frequency_count->at(stoi(tmp) / 10) += 1;
        }
    }
    
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
    Params params;
    bool USE_ALTERNATE_FILE_OUTPUT = false;
    int opt = 0;
    while ((opt = getopt(argc, argv, "n:b:w:m:h")) != -1) {
        switch (opt) {
            case 'n':
                params.n = atoi(optarg);
                break;
            case 'b':
                params.b = atoi(optarg);
                break;
            case 'w':
                params.w = atoi(optarg);
                break;
            case 'm':
                if(atoi(optarg) == 2) USE_ALTERNATE_FILE_OUTPUT = true;
                break;
            case 'h':
            default:
                std::cout << "This program can be invoked with the following flags:" << std::endl;
                std::cout << "-n [int]: number of requests per patient" << std::endl;
                std::cout << "-b [int]: size of request buffer" << std::endl;
                std::cout << "-w [int]: number of worker threads" << std::endl;
                std::cout << "-m 2: use output2.txt instead of output.txt for all file output" << std::endl;
                std::cout << "-h: print this message and quit" << std::endl;
                std::cout << "Example: ./client_solution -n 10000 -b 50 -w 120 -m 2" << std::endl;
                std::cout << "If a given flag is not used, a default value will be given" << std::endl;
                std::cout << "to its corresponding variable. If an illegal option is detected," << std::endl;
                std::cout << "behavior is the same as using the -h flag." << std::endl;
                exit(0);
        }
    }
    
    
    //Initilize Buffers
    params.request_buffer = new Bounded_Buffer();
    params.john_buffer = new Bounded_Buffer();
    params.jane_buffer = new Bounded_Buffer();
    params.joe_buffer = new Bounded_Buffer();
    
    params.john_frequency_count = new std::vector<int>(10,0);
    params.jane_frequency_count = new std::vector<int>(10,0);
    params.joe_frequency_count = new std::vector<int>(10,0);
    
    //Initilize bound
    params.request_buffer->emptySlots.count = params.b;
    params.john_buffer->emptySlots.count = params.b;
    params.joe_buffer->emptySlots.count = params.b;
    params.jane_buffer->emptySlots.count = params.b;
    
    int pid = fork();
    if(pid == 0){
        struct timeval start_time;
        struct timeval finish_time;
        int64_t start_usecs;
        int64_t finish_usecs;
        ofstream ofs;
        if(USE_ALTERNATE_FILE_OUTPUT) ofs.open("output2.txt", ios::out | ios::app);
        else ofs.open("output.txt", ios::out | ios::app);
        
        std::cout << "n == " << params.n << std::endl;
        std::cout << "b == " << params.b << std::endl;
        std::cout << "w == " << params.w << std::endl;
        
        std::cout << "CLIENT STARTED:" << std::endl;
        std::cout << "Establishing control channel... " << std::flush;
        RequestChannel *chan = new RequestChannel("control", RequestChannel::CLIENT_SIDE);
        params.chan = chan;
        std::cout << "done." << std::endl;
        gettimeofday(&start_time, NULL);
    /*************************************************
     *             Data Threads                      *
     *************************************************/
        cout << "Starting Data Threads: \n";
        Params temp[3];
        pthread_t threads[3]; //create 3 threads
        
        //John Smith thread
        temp[0] = params;
        temp[0].data_pushed = "data John Smith";
        pthread_create (&threads[0], NULL, request_thread_function, (void *) &temp[0]);
        
        //Jane Smith thread
        temp[1] = params;
        temp[1].data_pushed = "data Jane Smith";
        pthread_create (&threads[1], NULL, request_thread_function, (void *) &temp[1]);
        
        //Joe Smith thread
        temp[2] = params;
        temp[2].data_pushed = "data Joe Smith";
        pthread_create (&threads[2], NULL, request_thread_function, (void *) &temp[2]);
        
        
 
        
    /*************************************************
     *                Worker Threads                 *
     *************************************************/
        cout << "Starting Worker Threads: \n";
        pthread_t W_threads[params.w]; //create w threads
        Params w_temp[params.w];
        for(int i = 0; i < params.w; i++)
        {
            string s = chan->send_request("newthread");
            w_temp[i] = params;
            w_temp[i].chan = new RequestChannel(s, RequestChannel::CLIENT_SIDE);
            if( pthread_create (&W_threads[i], NULL, worker_thread_function, (void *) &w_temp[i]))
            {
               cout<< "Error Creating Thread\n";
               return 1;
            }

        }
       
    /*************************************************
     *               Stat Threads                    *
     *************************************************/
        cout << "Starting Stat Threads: \n";
        pthread_t S_threads[3]; //create 3 threads
        Params s_temp[3];
        
        //John Smith thread
        s_temp[0] = params;
        s_temp[0].response_name = "John Smith";
        pthread_create (&S_threads[0], NULL, stat_thread_function, (void *) &s_temp[0]);
        
        //Jane Smith thread
        s_temp[1] = params;
        s_temp[1].response_name = "Jane Smith";
        pthread_create (&S_threads[1], NULL, stat_thread_function, (void *) &s_temp[1]);
        
        //Joe Smith thread
        s_temp[2] = params;
        s_temp[2].response_name = "Joe Smith";
        pthread_create (&S_threads[2], NULL, stat_thread_function, (void *) &s_temp[2]);
        
        cout << "done\n";
        
        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);
        pthread_join(threads[2], NULL);
        
        for(int i = 0; i < params.w; ++i)
        {
            params.request_buffer->push("quit");
        }
        
        for(int i = 0; i < params.w; i++)
        {
            
            pthread_join(W_threads[i], NULL);
        }
   
        pthread_join(S_threads[0], NULL);
        pthread_join(S_threads[1], NULL);
        pthread_join(S_threads[2], NULL);
        
        gettimeofday(&finish_time, NULL); 
        start_usecs = (start_time.tv_sec * 1e6) + start_time.tv_usec;
        finish_usecs = (finish_time.tv_sec * 1e6) + finish_time.tv_usec;
        std::cout << "Finished!\n" << std::endl;
        
        
        
        std::string john_results = make_histogram("John Smith", params.john_frequency_count);
        std::string jane_results = make_histogram("Jane Smith", params.jane_frequency_count);
        std::string joe_results = make_histogram("Joe Smith", params.joe_frequency_count);
        
        std::cout << "Results for n == " << params.n << ", w == " << params.w  <<", b == " << params.b << std::endl;
        std::cout << "Time to completion: " << std::to_string(finish_usecs - start_usecs) << " usecs" << std::endl;
        std::cout << "\nJohn Smith total: " << accumulate(params.john_frequency_count->begin(), params.john_frequency_count->end(), 0) << std::endl;
        std::cout << john_results << std::endl;
        std::cout << "Jane Smith total: " << accumulate(params.jane_frequency_count->begin(), params.jane_frequency_count->end(), 0) << std::endl;
        std::cout << jane_results << std::endl;
        std::cout << "Joe Smith total: " << accumulate(params.joe_frequency_count->begin(), params.joe_frequency_count->end(), 0) << std::endl;
        std::cout << joe_results << std::endl;
        

       

        ofs.close();
        std::cout << "Sleeping..." << std::endl;
        usleep(10000);
        std::string finale = chan->send_request("quit");
        std::cout << "Finale: " << finale << std::endl;
        delete params.request_buffer;
        delete params.john_buffer;
        delete params.jane_buffer;
        delete params.joe_buffer;
        delete params.john_frequency_count;
        delete params.jane_frequency_count;
        delete params.joe_frequency_count;
        
        for(int i = 0; i < params.w; i++)
        {
            delete w_temp[i].chan;
        }
        
    }
    else if(pid != 0) execl("dataserver", NULL);
}
