/* ###################################################################

Name:               linked_list.h

Contributors:       Chris Comeaux and Clifton Sims

Last Updated:       September 8, 2016

Desctiption:        Header file for Singly-Linked List

Assignment:         Machine Problem 1: A High Performance Linked List

####################################################################*/


#ifndef _linked_list_h_
#define _linked_list_h_

struct Node
{
    Node* next;
    int key;
    int valueLen;
};

//Helper functions
void Init(int M, int b);                            //Allocates M bites of memory and initilizes variables
int Insert(int x, char* value_ptr, int value_len);  //Inserts a new Node into the list with the data provided by the user
int Free_Insert(Node* temp);						//Inserts a deleted node to free list
void Destroy();                                     //Frees the memory allocated in Init
void  Delete(int x);                                //Removes node with key 'x' from the list
char* Lookup(int x);                                //Finds node with key 'x' and returns a pointer to it
void PrintList();                                   // Prints the data stored in the list



#endif