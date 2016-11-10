#include "bounded_buffer.h"

/********************************************************************
 *                   Semaphore Class Implemetation                  * 
 ********************************************************************/

void Semaphore::p()
{
    pthread_mutex_lock(&lock);
    count--;
    if(count < 0)
        pthread_cond_wait(&condition, &lock); //Put to sleep
    pthread_mutex_unlock(&lock);
}

void Semaphore::v()
{
    pthread_mutex_lock(&lock);
    if(count < 0)
        pthread_cond_signal(&condition);
    count++;
    pthread_mutex_unlock(&lock);
}




/********************************************************************
 *              Bounded_Buffer Class Implemetation                  * 
 ********************************************************************/

string Bounded_Buffer::pop() //Consumer
{
    fullSlots.p();
    mutex.p();
    string tmp = request_buffer.front();
    request_buffer.pop();
    mutex.v();
    emptySlots.v();
    return tmp;
}

 void Bounded_Buffer::push(string data)//Producer
{
    emptySlots.p();
    mutex.p();
    request_buffer.push(data);
    mutex.v();
    fullSlots.v();
}