/* 
    File: my_allocator.c

    Author: Clifton Sims, Chris Comeaux
            Department of Computer Science
            Texas A&M University
    Date  : 9/22/2016

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "my_allocator.h"

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

struct Header
{
    Header* next;
    int size;
    
};

Header** freeList;

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/
int basicBlockSize;
int totalSize;
int freeListSize;
int headsize = sizeof(Header);
uintptr_t head; //keeps the adress of the begining of the allocated memory
                //also this will be used to minipulate the adress for buddy pairs


/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

void* splitOperation(int freeIndex, int currentIndex)
{
    Addr address;
    while(freeIndex != currentIndex)
    {
        
        //printf("Temp:  %d\n", freeIndex);
        int newSize = (basicBlockSize*pow(2.0,freeIndex))/2;
        int newIndex = freeIndex-1;
        freeList[newIndex] = freeList[freeIndex];
        
        //Take care of old index
        if(freeList[freeIndex]->next !=NULL)
           freeList[freeIndex] = freeList[freeIndex]->next;
        else
            freeList[freeIndex] = NULL;
        
        //Initilize new blocks
        Header* newBlock = (Header*)((char*)freeList[newIndex] + newSize);    
        freeList[newIndex]->size = newSize;
        freeList[newIndex]->next = newBlock;
        newBlock->size = newSize;
        newBlock->next = NULL;
        
        freeIndex--;
    }
    address = (void*)((char*)freeList[freeIndex]+headsize); 
    
    //unlink allocated block from free list
    if(freeList[freeIndex]->next !=NULL)
       freeList[freeIndex] = freeList[freeIndex]->next;
    else
        freeList[freeIndex] = NULL;
        
    return address;
}



unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length)
{
    //Initilize Varibles
    basicBlockSize = _basic_block_size;
    totalSize = _length;
    
    //First check if we have a acceptable block size
    if ((basicBlockSize%2) != 0)
    {
        printf("basicBlockSize is not a multiple of 2\n");
        return 0; //return fail
    }
    
    //This will deal with lengths that are not mulitples of  basic block size
    int rem = totalSize%basicBlockSize;  
    if (rem != 0)
    {
        totalSize -= rem; //subtract the memory that will not totally fit into the total size 
        totalSize +=basicBlockSize; // add one block to make up for the subtracted bits
    }
    
    // Initilize Free List
    freeListSize = log2(totalSize/basicBlockSize);
    freeList = (Header**)malloc(freeListSize*sizeof(Header*)); // freelist points to the first head pointer
    for(int i = 0; i<=freeListSize; i++)
        freeList[i] = NULL;
    
    //Initilize the block of memory
    freeList[freeListSize]  = (Header*)malloc(totalSize); //allocate the block of memory and have the first free list element point to it
    head = (uintptr_t)freeList[freeListSize];
    freeList[freeListSize]->next = NULL;
    freeList[freeListSize]->size = basicBlockSize*pow(2.0,freeListSize);
    
    return totalSize;
}

int release_allocator()
{
    printf("All memory released\n");
    free((void*)head); //Free the memory allocated for my_malloc
    free((void*)freeList);//Free memory allocated for freeList
    return 0;
}


extern Addr my_malloc(unsigned int _length) 
{
    
    Addr address;
    //Find the correct free list index that corresponds to the size requsted
    int currentIndex = 0;
    while (_length>basicBlockSize*pow(2.0,currentIndex)-headsize)
        currentIndex++;
    if(currentIndex>=freeListSize) //if the user tries to allocate too big of a chunk return NULL
    {
        printf("length %d\n",_length);
        printf("That excedes the biggest memory block\n");
        return NULL;
    }

    //Find index with next free block
    int freeIndex = currentIndex;
    while (freeList[freeIndex] == NULL)
    {
        freeIndex++;
        if (freeIndex > freeListSize) //Check if all memory has been used
        {
            printf("Memory Error: Out of memory, use free to reallocate memory\n");
            return NULL;
        }
    }
    

       
    //No split needed... Just allocate
    if (freeIndex == currentIndex) 
    {
        freeList[currentIndex]->size = basicBlockSize*pow(2.0,currentIndex); 
        freeList[currentIndex]->next = NULL;
        address = (void*)(((char*)freeList[currentIndex])+headsize);
        
        //unlink allocated block from free list
        if(freeList[currentIndex]->next !=NULL)
           freeList[currentIndex] = freeList[currentIndex]->next;
        else
            freeList[currentIndex] = NULL;

        return address;
    }
    
   //Split the block
    else if (freeIndex != currentIndex)
        return splitOperation(freeIndex,currentIndex);
    
    
  return NULL;
 
}


void mergeOperation(int freedIndex)
{
    int freedAddress;
    bool buddyFound = false;
    
    Header* freeTemp = freeList[freedIndex];
    while (freeTemp->next != NULL)
    {
        freeTemp = freeTemp->next;
    }
    uintptr_t freedPtr = (long int)freeTemp - head;

    Header* buddyTemp = freeList[freedIndex];
    int i = 1;
    while (buddyTemp->next != NULL)
    {
        
        uintptr_t buddyPtr = (long int)buddyTemp - head;
        
        uintptr_t buddy = freedPtr ^ buddyPtr;
        
        if(buddy == buddyTemp->size) //BUDDY FOUND YAY!!!
        {
            buddyFound = true;
            break; 
        }
        i++;
        buddyTemp = buddyTemp->next;
    }
    
    if(!buddyFound) //exits out if no buddy was found
        return;
    
    
    //removes the freed pointer
    Header* temp = freeList[freedIndex];
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    
    //removes the buddy pointer and keeps chain together
    if(freeList[freedIndex] == buddyTemp)
    {
        freeList[freedIndex] = buddyTemp->next;
    }
    else
    {
        temp = freeList[freedIndex];
        while(temp != buddyTemp)
        {
            if(temp->next == buddyTemp)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    
    
    //checks case of which is front
    long int isFront = (long int)(freeTemp - buddyTemp);
    if(isFront > 0) //buddy is front
    {
        buddyTemp->size = buddyTemp->size * 2;
        Addr merged = (Header*)((char*)buddyTemp + headsize);
        my_free(merged);
    }
    else //freed is front
    {
        freeTemp->size = freeTemp->size * 2;
        Addr merged = (Header*)((char*)freeTemp + headsize);
        my_free(merged);
    }
}

extern int my_free(Addr _a) 
{
    //Take in Addr and make it a point to the header and find correct index
    Header* ptr = (Header*)((char*)_a - headsize);
    int freedindex = log2(ptr->size/basicBlockSize);

    //If the free list is empty for that index link it back to the free list
    if (freeList[freedindex] == NULL)
    {
        ptr->next = NULL;
        freeList[freedindex] = ptr; 
    }
    else if (freeList[freedindex] != NULL)
    {
        Header* temp = freeList[freedindex];
        while (temp->next != NULL)
            temp = temp->next;
        ptr->next = NULL; //unlink
        temp->next = ptr;
        
        mergeOperation(freedindex);
    }
        
    return 0;
}



void PrintList()
{
    Header* ptr; 
    int itemp = freeListSize;
    for (;itemp>=0;itemp--)
    {
        ptr = freeList[itemp];
        int count = 0;
        if(ptr != NULL)
        {
            int size = ptr->size;
            while(ptr != NULL)
            {
                count++;
                ptr = ptr->next;
            }
            printf("blocksize = %d, free blocks = %d\n", size,count);
        }
    }
    printf("\n");
}

