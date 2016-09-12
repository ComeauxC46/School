/*========================================================================================================================================
Chris Comeaux
cmc236
Section 507
cmc236@tamu.edu
==========================================================================================================================================*/

//SinglyLinkedList.h
#include <iostream>
using namespace std;

class SListNode
{
	int key; //UIN
	int value; //GRADE
	SListNode* next;
	friend class SLinkedList;
public:
	SListNode (SListNode* next = NULL, int key = 0, int value = 0)
			   :next(next), key(key), value(value){}
	SListNode* getNext() {return this->next;}
};

class SLinkedList
{
	SListNode *head, *tail;
public:
	SLinkedList(): head(NULL), tail(NULL){head=tail; tail=head;}
	~SLinkedList(){remove_all();}
	void insert(int key, int value); //insert into the end of the linked list
	SListNode* getFirst() {return this->head;}
	bool isEmpty() {return head==NULL;}
	void remove_all();
	bool search(int Key, int& grade);
};
