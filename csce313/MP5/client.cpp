/*
    File: client.cpp

	Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2013/01/31

 */

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*
    This assignment does not require any additional includes,
    though you are free to add any that you find helpful.
*/
/*--------------------------------------------------------------------------*/

#include <cassert>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "reqchannel.h"
#include <pthread.h>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <assert.h>
#include <cmath>
#include <numeric>
#include <list>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */
/*--------------------------------------------------------------------------*/

struct Buffer
{
    pthread_mutex_t lock;
    queue<string> request_buffer;
    pthread_t *threads;
    Buffer()
    { 
        pthread_mutex_init(&lock, NULL);
        
    }
    
    ~Buffer()
    { 
        pthread_mutex_destroy(&lock);
        
    }
    
    string pop()
    {
        pthread_mutex_lock(&lock);
        string tmp = request_buffer.front();
        request_buffer.pop();
        pthread_mutex_unlock(&lock);
        return tmp;
    }
    
    void push(string data)
    {
        pthread_mutex_lock(&lock);
        request_buffer.push(data);
        pthread_mutex_unlock(&lock);
    }

};

struct PARAMS {
    /*
        This is a helpful struct to have,
        but you can implement the program
        some other way it you'd like.
     
        For example, it can hold pointers to
        the containers that hold the histogram information
        so that all the threads combine their data
        instead of assembling "w" different histograms,
        as well as pointers to RequestChannels and
        to synchronization objects.
     */
     
    pthread_mutex_t p_lock;
    
    
    
     
    int n = 100; //default number of requests per "patient"
    int w = 1;
    string data_pushed = "";
    Buffer *buffer = new Buffer(); 
    RequestChannel *chan;
    
    vector<int> john_frequency_count{vector<int> (10, 0)};
    vector<int> jane_frequency_count{vector<int> (10, 0)};
    vector<int> joe_frequency_count{vector<int> (10, 0)};
    
    PARAMS(){pthread_mutex_init(&p_lock, NULL);}
    
};

/*
    The class below allows any thread in this program to use
    the variable "atomic_standard_output" down below to write output to the
    console without it getting jumbled together with the output
    from other threads.
    For example:
    thread A {
        atomic_standard_output.print("Hello ");
    }
    thread B {
        atomic_standard_output.print("World!\n");
    }
    The output could be:
    Hello World!
    or...
    World!
    Hello 
    ...but it will NOT be something like:
    HelWorllo d!
 */

class atomic_standard_output {
    /*
         Note that this class provides an example
         of the usage of mutexes, which are a crucial
         synchronization type. You will probably not
         be able to write the worker thread function
         without using these.
     */
    pthread_mutex_t console_lock;
public:
    atomic_standard_output() { pthread_mutex_init(&console_lock, NULL); }
    void print(std::string s){
        pthread_mutex_lock(&console_lock);
        std::cout << s << std::endl;
        pthread_mutex_unlock(&console_lock);
    }
};

atomic_standard_output threadsafe_standard_output;

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

void* worker_thread_function(void* arg) {
    /*
        Fill in the loop. Make sure
        it terminates when, and not before,
        all the requests have been processed.
        
        Each thread must have its own dedicated
        RequestChannel. Make sure that if you
        construct a RequestChannel (or any object)
        using "new" that you "delete" it properly,
        and that you send a "quit" request for every
        RequestChannel you construct regardless of
        whether you used "new" for it.
     */
    
    PARAMS* p = (PARAMS*)arg;
    
    pthread_mutex_lock(&p->p_lock);
    string request, response;
    RequestChannel *chan = new RequestChannel("control", RequestChannel::CLIENT_SIDE);
    string s = chan->send_request("newthread");
    RequestChannel *workerChannel = new RequestChannel(s, RequestChannel::CLIENT_SIDE);
    pthread_mutex_unlock(&p->p_lock);
    
    
    int i = 1;
    while(true)
    {
        
        request = p->buffer->pop();
        
        
        response = workerChannel->send_request(request);
        //cout << request << " " << i++ << endl;
        if(request == "data John Smith") {
            pthread_mutex_lock(&p->p_lock);
            p->john_frequency_count.at(stoi(response) / 10) += 1;
            //cout << " got in" << endl;
            pthread_mutex_unlock(&p->p_lock);
        }
        else if(request == "data Jane Smith") {
            pthread_mutex_lock(&p->p_lock);
            p->jane_frequency_count.at(stoi(response) / 10) += 1;
            pthread_mutex_unlock(&p->p_lock);
        }
        else if(request == "data Joe Smith") {
            pthread_mutex_lock(&p->p_lock);
            p->joe_frequency_count.at(stoi(response) / 10) += 1;
            pthread_mutex_unlock(&p->p_lock);
        }
        else if(request == "quit") {
            delete workerChannel;
            break;
        }
    }
    
            
    delete chan;
    
    
    
    pthread_exit(0);
    
   
    
}

void* data_thread_function (void* arg)
{
   
    PARAMS* p = (PARAMS*)arg;

    
    for(int i = 0; i < p->n; ++i)
    {
        p->buffer->push(p->data_pushed);
    }
    

    pthread_exit(0);
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
    /*
        Note that the assignment calls for n = 10000.
        That is far too large for a single thread to accomplish quickly,
        but you will still have to test it for w = 1 once you finish
        filling in the worker thread function.
     */
    //int n = 100; //default number of requests per "patient"
    //int w = 1; //default number of worker threads
    
    PARAMS params;
    
    
    int opt = 0;
    while ((opt = getopt(argc, argv, "n:w:h")) != -1) {
        switch (opt) {
            case 'n':
                params.n = atoi(optarg);
                break;
            case 'w':
                //This won't do a whole lot until you fill in the worker thread function
                params.w = atoi(optarg);
                break;
            case 'h':
            default:
                std::cout << "This program can be invoked with the following flags:" << std::endl;
                std::cout << "-n [int]: number of requests per patient" << std::endl;
                std::cout << "-w [int]: number of worker threads" << std::endl;
                std::cout << "-h: print this message and quit" << std::endl;
                std::cout << "Example: ./client_solution -n 10000 -w 120 -v 1" << std::endl;
                std::cout << "If a given flag is not used, or given an invalid value," << std::endl;
                std::cout << "a default value will be given to the corresponding variable." << std::endl;
                std::cout << "If an illegal option is detected, behavior is the same as using the -h flag." << std::endl;
                exit(0);
        }
    }
    
    int pid = fork();
    if(pid == 0){
        
        struct timeval start_time;
        struct timeval finish_time;
        int64_t start_usecs;
        int64_t finish_usecs;
        
        std::cout << "n == " << params.n << std::endl;
        std::cout << "w == " << params.w << std::endl;
        
        std::cout << "CLIENT STARTED:" << std::endl;
        std::cout << "Establishing control channel... " << std::flush;
        params.chan = new RequestChannel("control", RequestChannel::CLIENT_SIDE);
        std::cout << "done." << std::endl;
        
        /*
            All worker threads will use these,
            but the current implementation puts
            them on the stack in main as opposed
            to global scope. They can be moved to
            global scope, but you could also pass
            pointers to them to your thread functions.
         */
        std::list<std::string> request_buffer;
        
        
        /*-------------------------------------------*/
        /* START TIMER HERE */
        /*-------------------------------------------*/
        gettimeofday(&start_time, NULL);
/*--------------------------------------------------------------------------*/
/* BEGIN "MODIFY AT YOUR OWN RISK" SECTION */
/*
    But please remember to comment out the output statements
    while gathering data for your report. They throw off the timer.
*/
/*--------------------------------------------------------------------------*/
        
        
        
        std::cout << "Populating request buffer... ";
        fflush(NULL);
        
        PARAMS temp[3];
        
        pthread_t threads[3]; //create 3 threads
        
        //John Smith thread
        params.data_pushed = "data John Smith";
        temp[0] = params;
        pthread_create (&threads[0], NULL, data_thread_function, (void *) &temp[0]);
        
        //Jane Smith thread
        params.data_pushed = "data Jane Smith";
        temp[1] = params;
        pthread_create (&threads[1], NULL, data_thread_function, (void *) &temp[1]);
        
        //Joe Smith thread
        params.data_pushed = "data Joe Smith";
        temp[2] = params;
        pthread_create (&threads[2], NULL, data_thread_function, (void *) &temp[2]);
        
        
        pthread_join(threads[0], NULL);
        
        pthread_join(threads[1], NULL);
        
        pthread_join(threads[2], NULL);
        
        std::cout << "done." << std::endl;

        std::cout << "Pushing quit requests... ";
        fflush(NULL);
        for(int i = 0; i < params.w; ++i) {
            params.buffer->push("quit");
        }
        std::cout << "done." << std::endl;
        
        // WORKS
        /*int i = 1;
        while(!(params.buffer->request_buffer.empty()))
        {
            string t = params.buffer->request_buffer.front();
            cout <<i++ <<":   " <<t <<endl;
            params.buffer->pop();
        }*/
        
/*--------------------------------------------------------------------------*/
/* END "MODIFY AT YOUR OWN RISK" SECTION    */
/*--------------------------------------------------------------------------*/
        
/*--------------------------------------------------------------------------*/
/*  BEGIN CRITICAL SECTION  */
/*
    Most of the changes you make will be
    to this section of code and to the
    worker thread function from earlier, unless
    you also decide to utilize the PARAMS struct (which is
    *highly* recommended) and then you'll need
    to fill that in as well.
 
    You will modify the program so that client.cpp
    uses w threads to process the requests, instead of
    sequentially using a single loop.
*/
/*--------------------------------------------------------------------------*/

        /* Worker Threads */
        pthread_t W_threads[params.w]; //create w threads
        for(int i = 0; i < params.w; i++)
        {
           if( pthread_create (&W_threads[i], NULL, worker_thread_function, (void *) &params))
           {
               cout<< "Error Creating Thread\n";
               return 1;
           }

        }
        for(int i = 0; i < params.w; i++)
        {
            pthread_join(W_threads[i], NULL);            
        }
        
        /*std::string s = chan->send_request("newthread");
        RequestChannel *workerChannel = new RequestChannel(s, RequestChannel::CLIENT_SIDE);
        
        while(true) {
            std::string request = request_buffer.front();
            request_buffer.pop_front();
            std::string response = workerChannel->send_request(request);
            
            if(request == "data John Smith") {
                john_frequency_count.at(stoi(response) / 10) += 1;
            }
            else if(request == "data Jane Smith") {
                jane_frequency_count.at(stoi(response) / 10) += 1;
            }
            else if(request == "data Joe Smith") {
                joe_frequency_count.at(stoi(response) / 10) += 1;
            }
            else if(request == "quit") {
                delete workerChannel;
                break;
            }
        }*/
/*--------------------------------------------------------------------------*/
/*  END CRITICAL SECTION    */
/*--------------------------------------------------------------------------*/
        
        /*
            By the point at which you end the timer,
            all worker threads should have terminated.
            Note that the containers from earlier
            are still in scope, so threads can use them
            if they have a pointer to them.
         */
        
        /*-------------------------------------------*/
        /* END TIMER HERE   */
        /*-------------------------------------------*/
        gettimeofday(&finish_time, NULL);
        /*
            You may want to eventually add file output
            to this section of the code to make it easier
            to assemble the timing data from different iterations
            of the program.
         */
        start_usecs = (start_time.tv_sec * 1e6) + start_time.tv_usec;
        finish_usecs = (finish_time.tv_sec * 1e6) + finish_time.tv_usec;
        std::cout << "Finished!\n" << std::endl;
        
        std::string john_results = make_histogram("John Smith", &params.john_frequency_count);
        std::string jane_results = make_histogram("Jane Smith", &params.jane_frequency_count);
        std::string joe_results = make_histogram("Joe Smith", &params.joe_frequency_count);
        
        std::cout << "Results for n == " << params.n << ", w == " << params.w << std::endl;
        std::cout << "Time to completion: " << std::to_string(finish_usecs - start_usecs) << " usecs" << std::endl;
        std::cout << "\nJohn Smith total: " << accumulate(params.john_frequency_count.begin(), params.john_frequency_count.end(), 0) << std::endl;
        std::cout << john_results << std::endl;
        std::cout << "Jane Smith total: " << accumulate(params.jane_frequency_count.begin(), params.jane_frequency_count.end(), 0) << std::endl;
        std::cout << jane_results << std::endl;
        std::cout << "Joe Smith total: " << accumulate(params.joe_frequency_count.begin(), params.joe_frequency_count.end(), 0) << std::endl;
        std::cout << joe_results << std::endl;
        
        std::cout << "Sleeping..." << std::endl;
        usleep(10000);
        
        /*
            EVERY RequestChannel must send a "quit"
            request before program termination, and
            the destructor for RequestChannel must be
            called somehow.
         */
        std::string finale = params.chan->send_request("quit");
        delete params.chan;
        std::cout << "Finale: " << finale << std::endl; //However, this line is optional.
    }
    else if(pid != 0) execl("dataserver", NULL);
}
