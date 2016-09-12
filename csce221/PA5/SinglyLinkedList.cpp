/*========================================================================================================================================
Chris Comeaux
cmc236
Section 507
cmc236@tamu.edu
==========================================================================================================================================*/

//SinglyLinkedList.cpp
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

/*---------------------------------------------------------------------------------------------
Insert
-----------------------------------------------------------------------------------------------*/
void SLinkedList::insert(int key, int value)
{
	SListNode* newNode = new SListNode(NULL, key, value);
	if(this->isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

/*---------------------------------------------------------------------------------------------
Remove all
-----------------------------------------------------------------------------------------------*/
void SLinkedList::remove_all()
{
	SListNode* node = this->head;
	tail = NULL;
	while (node!=NULL)
	{
		this->head = node->next;
		delete node;
		node = this->head;
	}
	
}

/*---------------------------------------------------------------------------------------------
Search
-----------------------------------------------------------------------------------------------*/
bool SLinkedList::search(int Key, int& grade)
{
	if (this->isEmpty())
		return false;
	SListNode* node = this->head;
	while (node!=NULL)
	{
		if(Key == node->key)
		{
			grade = node->value;
			return true;
		}
		else
			node = node->next;
	}
	return false; //search unsucsessful
}
			