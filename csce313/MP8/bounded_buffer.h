#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <queue>
#include <iostream>
#include "NetworkRequestChannel.h"
using namespace std;

class Semaphore
{
public:
  //Members
  int count;
  pthread_mutex_t lock;
  pthread_cond_t condition;
  //queue<pthread_t> wait_queue;
  
  //Constructor Destructor
  Semaphore()// Constructor
  {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init (&condition, NULL);
  }
  
  Semaphore(int c)// Constructor
  {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init (&condition, NULL);
    count = c;
  } 

  ~Semaphore()
  {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&condition);
  }

  //Member Functions
  void p(); //Decrease count
  void v(); //Increase count
};

class Bounded_Buffer
{
public:
    //Members
    queue<string> request_buffer;
    pthread_t *threads;
    Semaphore fullSlots=0;
    Semaphore emptySlots=0; //NEEDS TO BE INITILIZED AT START
    Semaphore mutex=1;

    //Member Functions
    string pop();
    void push(string data);
    
};

struct Params
{
    //Default Arguments
    int n = 10; //default number of requests per "patient"
    int b = 50; //default size of request_buffer
    int w = 10; //default number of worker threads
    string h = "linux.cse.tamu.edu";
    int p = 6969; //default port
    int backlog = 10; //default backlog
    
    //Members
    string data_pushed = "data John Smith";
    pthread_mutex_t lock;
    vector<NetworkRequestChannel*> chan;
    
    //Stat Buffers
    Bounded_Buffer* john_buffer;
    Bounded_Buffer* jane_buffer;
    Bounded_Buffer* joe_buffer;
    string response_name = "John Smith";
    vector<int>* john_frequency_count;
    vector<int>* jane_frequency_count;
    vector<int>* joe_frequency_count;
    
    //Make a Request Buffer
    Bounded_Buffer* request_buffer;
    
    
};
