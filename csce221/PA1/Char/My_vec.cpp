#include "My_vec.h"
/*My_vec(CHAR) IMPLAMENTATION
-----------------------------------------------------------------------------------------------------

Default condtructure with default capacity of 10*/
My_vec::My_vec ():size(0), capacity(10), ptr(new char[10]){}

/*---------------------------------------------------------------------------------------------------

Destructure*/
My_vec::~My_vec() 
{
	delete[] ptr;
}
/*---------------------------------------------------------------------------------------------------

Copy Constructure: new vector initilazed with old vector*/
My_vec::My_vec(const My_vec& vec) 
{
	size = vec.get_size(); //copy size
	capacity = vec.get_capacity(); //copy capacity
	ptr = new char[vec.get_size()]; //allocate new array with size of old array
	for(int i=0; i<vec.get_size(); i++)     // copy the data in the old vector to the new vector
		ptr[i]=vec[i];
}
/*--------------------------------------------------------------------------------------------------

Copy Assignment: old vector assigned to old vector*/	
My_vec& My_vec::operator=(const My_vec& vec)  
{
	delete[] ptr; // deallocate old memory
	size = vec.get_size(); // assign size
	capacity = vec.get_capacity(); // assign capacity
	ptr = new char[capacity]; //allocate new array with size of old array
	for(int i=0; i<vec.size; i++)     // assign data
		ptr[i]=vec[i];
	return *this; //return the vector
}
/*--------------------------------------------------------------------------------------------------

Size and Capacity access*/
int My_vec::get_size() const {return size;}
int My_vec::get_capacity() const {return capacity;}

/*--------------------------------------------------------------------------------------------------

Access Operators*/
char& My_vec::operator[] (int i) const
{
	if(i<0||i>=(size))
		throw runtime_error("Out of Range Access1");
	
	return ptr[i];
}
char& My_vec::operator[] (int i)
{
	if(i<0||i>=size)
		throw runtime_error("Out of Range Access2");
	
	return ptr[i];
}
/*------------------------------------------------------------------------------------------------

Check to see if vector is empty*/ 
bool My_vec::is_empty() const
{
	if(size==0)
		return true;
	return false;
}
/*------------------------------------------------------------------------------------------------

Access Function*/
char& My_vec::elem_at_rank(int r) const
{
	if(r<0||r>=size)
		throw runtime_error("Out of Range Access3");
	
	return ptr[r];
}

/*-----------------------------------------------------------------------------------------------

Insert an element*/
void My_vec::insert_at_rank(int r, const char& elem)
{
	if(size==capacity)
	{
		char* n_ptr = new char[capacity]; // create temparary array to hold data
		for(int i=0; i<size; i++) // copy data to temp
			n_ptr[i] = ptr[i];
		delete[] ptr;// Delete old array
		ptr = new char[capacity*2]; //double the capasity
		for(int i=0; i<size; i++) //move data back to origional array
			ptr[i] = n_ptr[i];
		capacity *= 2; // update capacity
		delete[] n_ptr; // delete temperary array
	}
	if(r!=size && r<=size) // if inserting to an element that already has data
	{
		for(int i=size; i>r; i--) // move existing data right to make space for new element
			ptr[i]=ptr[i-1];
	}
	if(size==0 && r!=0 || r>size) //if you try to insert an element at a rank other than 0 when empty or at a rank that does not proceed another filled element
		throw runtime_error("Out of Range Access7");
	ptr[r] = elem; //insert element
	size++;

}
/*---------------------------------------------------------------------------------------------

Replace an Element*/
void My_vec::replace_at_rank(int r, const char& elem)
{
	if(r>=size) //if there is no element to replace
		throw runtime_error("Out of Range Access4");
	ptr[r] = elem;
}
/*---------------------------------------------------------------------------------------------

Remove Element*/
void My_vec::remove_at_rank(int r)
{
	if(r>=size) //if there is no element to remove
		throw runtime_error("Out of Range Access5");
	for(int i=r; i<=size; i++) 
			ptr[i]=ptr[i+1];
	size--;
}
//******************************************************************************************************
//NON MEMBER FUNCTION IMPLEMENTATION

//Output Operator
ostream& operator<<(ostream& out, const My_vec& vec)
{
	for(int i=0; i<vec.get_size(); i++)
		out <<vec[i] <<' ';
	return out;
}
/*--------------------------------------------------------------------------------------------	

Find the index with the largest value*/	
int find_max_index(const My_vec& v,int size)
{
	if(size==0)
		throw range_error("No Elements to Find6");
	char largest = v[0];
	int max=0;
	char temp;
	for(int i=1; i<size; i++)
	{
		if(v[i]>largest)
		{
			largest = v[i];
			max = i;
		}
	}
	return max;
}
/*--------------------------------------------------------------------------------------------

Sort my_vec using find_max_index*/
void sort_max(My_vec& vec)
{
	for(int i=0; (vec.get_size()-i)>0; i++)
	{
		//find max index first
		int max = find_max_index(vec, vec.get_size()-i);
		//set up local variables
		int bindex = vec.get_size()-1-i; // biggest index
		char largest = vec[max];
		if(max!= bindex) //get the known max into the correct index
		{
			char temp = vec[bindex];
			vec.replace_at_rank(bindex, vec[max]);
			vec.replace_at_rank(max, temp);
		}
	}	
}




