/*========================================================================================================================================
Chris Comeaux
cmc236
Section 507
cmc236@tamu.edu
==========================================================================================================================================*/

//HashTable.h
#include "SinglyLinkedList.h"
#include <vector>
using namespace std;

struct HashTable
{
	vector<SLinkedList> vec;
	void resize(int i) {this->vec.resize(i);}
};
int hash_function(int key, int s) {return key%s;} //UIN mod size 