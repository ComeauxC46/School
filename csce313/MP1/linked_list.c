/* ###################################################################

Name:               linked_list.c

Contributors:       Chris Comeaux and Clifton Sims

Last Updated:       September 8, 2016

Desctiption:        Source file for Singly-Linked List

Assignment:         Machine Problem 1: A High Performance Linked List

####################################################################*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

/*-----------------------------------------------------------------------------------------------
LinkedList Variables
-----------------------------------------------------------------------------------------------*/
Node *freeptr;
Node *headptr;
Node *tailptr;
Node *temp_headptr;         // keeps track of start of the list if the head node gets deleted
bool head_change = false;   //if the headptr changes then true 
int nodeSize;               //Holds size of the of one node

/*-----------------------------------------------------------------------------------------------
FreeList Variables
-----------------------------------------------------------------------------------------------*/
Node *free_headptr;
Node *free_freeptr;
int  freeListSize;

/*-----------------------------------------------------------------------------------------------
Misc Variables
-----------------------------------------------------------------------------------------------*/
int blockSize;              //Holds the overall size of the memory block
int maxSize;                //Holds the number of nodes a block can hold
int currentSize;            // Holds the current number of nodes
int iSize;                  //Holds the size of an integer
int cptrSize;               //Holds the size of a char pointer

/*-----------------------------------------------------------------------------------------------
Init Implementation
-----------------------------------------------------------------------------------------------*/
void Init(int M, int b)
{
    //Allocate block of memory of size M (M = memory block size)
    headptr = (Node *)malloc(M); 
    freeptr = headptr;
    tailptr = headptr;
    
    //Initilize Variables
    nodeSize = b;
    blockSize = M;
    maxSize = M/b;
    currentSize = 0;
	freeListSize = 0;
    iSize = sizeof(int);
    cptrSize = sizeof(char*);
}

/*-----------------------------------------------------------------------------------------------
Insert Implementation
-----------------------------------------------------------------------------------------------*/
int Insert(int x, char* value_ptr, int value_len)
{
    //Find how much space is left for the value
    int valueSpace = nodeSize - (cptrSize + 2*iSize);
    
    if(value_len < valueSpace)
    {
        if (currentSize == 0)
        {
            Node* n = freeptr;
            n->next = NULL;
            n->key = x;
            n->valueLen = value_len;
            memcpy((char*)n+16, value_ptr, (value_len));
            tailptr = freeptr;
            freeptr += nodeSize;
            
            currentSize++;
            return 1; //sucsessful return
        }
        
        else if (currentSize != 0 && currentSize < maxSize)
        {
            //find node before with NULL pointer
            Node* n = freeptr;
            n->next = NULL;
            n->key = x;
            n->valueLen = value_len;
            memcpy((char*)n+16, value_ptr, (value_len+1));
            tailptr->next = freeptr;
            tailptr = freeptr;
            freeptr += nodeSize;
            
            currentSize++;
            return 1; //sucsessful return
        }
    
		else if (currentSize == maxSize) //start accessing free list
		{
			if(freeListSize == 0) //if free list is empty as well return unsucsessful
			{
				printf("There is no more memory. Please delete some data.\n");
				return -1; //unsucsessful return
			}
			
			//Take node from free list and place it back into linked list
            Node* n = free_headptr;
			free_headptr = free_headptr->next; //move head to next node in free list
            n->next = NULL;
            n->key = x;
            n->valueLen = value_len;
            memcpy((char*)n+16, value_ptr, (value_len+1));
			tailptr->next = n; //reconnect node to list
			tailptr = n; //make tailptr to reconneted node
			freeptr = tailptr;
			freeptr += nodeSize; //make freeptr point to the end of the list
            
            freeListSize--;
            return 1; //sucsessful return
		}
	}
	
    else 
    {
        printf ("The value is too big and cannot be stored\n");
        return -1; //unsucsessful return
    }  
}

/*-----------------------------------------------------------------------------------------------
Destroy Implementation
-----------------------------------------------------------------------------------------------*/
void Destroy()
{
    //if headptr does not point to head of the block anymore then delete temp_headptr which points to the head
    if (head_change) 
        free(temp_headptr);
    else
        free(headptr);
}

/*-----------------------------------------------------------------------------------------------
Delete Implementation
-----------------------------------------------------------------------------------------------*/
void  Delete(int x)
{
    Node* temp = headptr;
    Node* prev = NULL;
    while (temp != NULL)
    {
        if (temp->key == x)
        {
            if(currentSize == 1)//only 1 item in list
            {
				Free_Insert(temp);
                temp_headptr = headptr; // remember the
                head_change = true;
                headptr = NULL;//list is empty
            }
            
            else if(temp->next == NULL) //end of list
			{
				Free_Insert(temp);
                prev->next = NULL;
			}
                
            else if(prev == NULL) // beginning of list
            {
				Free_Insert(temp);
                temp_headptr = headptr; // remember the beginning of the head
                headptr = temp->next; //the start of the list is now at the second node
                temp->next = NULL;
                head_change = true;
            }
                
            else
            {
				Free_Insert(temp);
                prev->next = temp->next; // breaks chain with node
                temp->next == NULL; // unlinks deleted node with the next node
            }
            
            return;
        }
        prev = temp;
        temp = temp->next;
        
    }
    
    printf ("The key %d is not in the Linked_list\n", x);
    
}

/*-----------------------------------------------------------------------------------------------
Lookup Implementation
-----------------------------------------------------------------------------------------------*/
char* Lookup(int x)
{
    Node* temp = headptr;
    while (temp != NULL)
    {
        if (temp->key == x)
            return (char*)temp + 8;
        temp = temp->next;
    }
    return NULL;
}

/*-----------------------------------------------------------------------------------------------
PrintList Implementation
-----------------------------------------------------------------------------------------------*/
void PrintList()
{
    Node* temp = headptr;
    printf("[");
    while (temp != NULL)
    {
        printf("%d(L%d)", temp->key, temp->valueLen);
        temp = temp->next;
        if(temp != NULL)
             printf(", ");
    }
    printf("]\n");
}

/*-----------------------------------------------------------------------------------------------
Free_Insert Implementation
-----------------------------------------------------------------------------------------------*/
int Free_Insert(Node* temp)
{
	if (freeListSize == 0)
    {
		// initilize link list
        free_headptr = temp;
		free_freeptr = free_headptr;
         
        freeListSize++;
        return 1; //sucsessful return
    }
        
    else 
    {
        free_freeptr->next = temp; //link node to previous node
		free_freeptr = temp;
            
        freeListSize++;
		return 1; //sucsessful return
    }
}