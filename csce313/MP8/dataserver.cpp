/* 
    File: dataserver.C

    Author: R. Bettati
            Department of Computer Science
            Texas A&M University
    Date  : 2012/07/16
	
	Modified: Chris Comeaux (12/2/2016)
	

    Dataserver main program for MP3 in CSCE 313
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <cassert>
#include <cstring>
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "bounded_buffer.h"

using namespace std;

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* VARIABLES */
/*--------------------------------------------------------------------------*/

static int nthreads = 0;

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

void handle_process_loop(NetworkRequestChannel & _channel);

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- SUPPORT FUNCTIONS */
/*--------------------------------------------------------------------------*/

string int2string(int number) {
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- THREAD FUNCTIONS */
/*--------------------------------------------------------------------------*/

void * connection_handler(void * args) {

  NetworkRequestChannel* data_channel =  (NetworkRequestChannel*)args;

  // -- Handle client requests on this channel. 
  
  handle_process_loop(*data_channel);

  // -- Client has quit. We remove channel.
 
  delete data_channel;
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- INDIVIDUAL REQUESTS */
/*--------------------------------------------------------------------------*/

void process_hello(NetworkRequestChannel& _channel, const string & _request) {
  _channel.cwrite("hello to you too");
}

void process_data(NetworkRequestChannel& _channel, const string &  _request) {
  usleep(1000 + (rand() % 5000));
  _channel.cwrite(int2string(rand() % 100));
}

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS -- THE PROCESS REQUEST LOOP */
/*--------------------------------------------------------------------------*/

void process_request(NetworkRequestChannel& _channel, const string & _request) {

  if (_request.compare(0, 5, "hello") == 0) {
    process_hello(_channel, _request);
  }
  else if (_request.compare(0, 4, "data") == 0) {
    process_data(_channel, _request);
  }
  else {
    _channel.cwrite("unknown request");
  }

}

void handle_process_loop(NetworkRequestChannel& _channel) {

  for(;;) {

    cout << flush;
    string request = _channel.cread();
    if (request.compare("quit") == 0) {
      _channel.cwrite("bye");
      usleep(10000);          // give the other end a bit of time.
      break;                  // break out of the loop;
    }

    process_request(_channel, request);
  }
  
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
    Params params;
    int opt = 0;
    while ((opt = getopt(argc, argv, "b:p:h")) != -1) {
        switch (opt) {
            case 'b':
                params.backlog = atoi(optarg);
                break;
            case 'p':
                params.p = atoi(optarg);
                break;
            case 'h':
            default:
                std::cout << "This program can be invoked with the following flags:" << std::endl;
                std::cout << "-b [int]: size of the backlog" << std::endl;
                std::cout << "-p [int]: port number" << std::endl;
                std::cout << "If a given flag is not used, a default value will be given" << std::endl;
                std::cout << "to its corresponding variable. If an illegal option is detected," << std::endl;
                std::cout << "behavior is the same as using the -h flag." << std::endl;
                exit(0);
        }
    }

  cout << "SERVER STARTED: " << endl;
  
  NetworkRequestChannel dataserver (params.p, connection_handler, params.backlog);

  //Make sure the Channel is destroyed
  dataserver.~NetworkRequestChannel();

}

