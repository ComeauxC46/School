/*My_vec.h Generic
Chris Comeaux
Header file for a vector data structure.
*/

#include <ostream>
using namespace std;

template<typename T>
class My_vec {
	
	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	My_vec();                            	   // Constructor
	~My_vec();							 	   // Destructor
	My_vec(const My_vec& vec);			 	   // Copy Constructor
	My_vec& operator=(const My_vec& vec);	   // Copy Assignment
	int get_size() const;					   // Size Access
	int get_capacity() const;				   // Capacity Access
	T& operator[](int i) const;			 	   // Constant Access Operator
	T& operator[](int i);				 	   // Access Operator
	bool is_empty() const;				       // Empty Check
	T& elem_at_rank(int r) const;			   // Access Function
	void insert_at_rank(int r, const T& elem); // Insert Data into element r
	void replace_at_rank(int r, const T& elem);// Replave data in element r
	void remove_at_rank(int r);         	   // Remoce data in element r
	
};
	template<typename T>
	ostream& operator<<(ostream& out, const My_vec<T>& vec); // Output Operator
	template<typename T>
	int find_max_index(const My_vec<T>& v,int size);         // Find index with max element
	template<typename T> 
	void sort_max(My_vec<T>& vec);                           // Sort based on max index
	
//====================================================================================================
//IMPLEMENTATION	

//Constructor
template<typename T> 
My_vec<T>::My_vec ()
{
	size=0; capacity=10;
	ptr = new T[capacity];
 }

/*---------------------------------------------------------------------------------------------------

Destructure*/
template<typename T> 
My_vec<T>::~My_vec() 
{
	delete[] ptr;
}
/*---------------------------------------------------------------------------------------------------

Copy Constructure: new vector initilazed with old vector*/
template<typename T> 
My_vec<T>::My_vec(const My_vec& vec) 
{
	size = vec.get_size(); //copy size
	capacity = vec.get_capacity(); //copy capacity
	ptr = new T[vec.get_size()]; //allocate new array with size of old array
	for(int i=0; i<vec.get_size(); i++)     // copy the data in the old vector to the new vector
		ptr[i]=vec[i];
}
/*--------------------------------------------------------------------------------------------------

Copy Assignment: old vector assigned to old vector*/	
template<typename T> 
My_vec<T>& My_vec<T>::operator=(const My_vec& vec)  
{
	delete[] ptr; // deallocate old memory
	size = vec.get_size(); // assign size
	capacity = vec.get_capacity(); // assign capacity
	ptr = new T[capacity]; //allocate new array with size of old array
	for(int i=0; i<vec.size; i++)     // assign data
		ptr[i]=vec[i];
	return *this; //return the vector
}
/*--------------------------------------------------------------------------------------------------

Size and Capacity access*/
template<typename T> 
int My_vec<T>::get_size() const {return size;}
template<typename T> 
int My_vec<T>::get_capacity() const {return capacity;}

/*--------------------------------------------------------------------------------------------------

Access Operators*/
template<typename T> 
T& My_vec<T>::operator[] (int i) const
{
	if(i<0||i>=(size)) // if no element to access
		throw runtime_error("Out of Range Access: 1");
	
	return ptr[i];
}
template<typename T> 
T& My_vec<T>::operator[] (int i)
{
	if(i<0||i>=size) //if no element to access
		throw runtime_error("Out of Range Access: 2");
	
	return ptr[i];
}
/*------------------------------------------------------------------------------------------------

Check to see if vector is empty*/ 
template<typename T> 
bool My_vec<T>::is_empty() const
{
	if(size==0)
		return true;
	return false;
}
/*------------------------------------------------------------------------------------------------

Access Function*/
template<typename T> 
T& My_vec<T>::elem_at_rank(int r) const
{
	if(r<0||r>=size) //if no element to access
		throw runtime_error("Out of Range Access: 3");
	
	return ptr[r];
}

/*-----------------------------------------------------------------------------------------------

Insert an element*/
template<typename T> 
void My_vec<T>::insert_at_rank(int r, const T& elem)
{
	if(size==capacity)
	{
		T* n_ptr = new T[capacity]; // create temparary array to hold data
		for(int i=0; i<size; i++) // copy data to temp
			n_ptr[i] = ptr[i];
		delete[] ptr;// Delete old array
		ptr = new T[capacity*2]; //double the capasity
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
		throw runtime_error("Out of Range Access: 7");
	ptr[r] = elem; //insert element
	size++;

}
/*---------------------------------------------------------------------------------------------

Replace an Element*/
template<typename T> 
void My_vec<T>::replace_at_rank(int r, const T& elem)
{
	if(r>=size) //if there is no element to replace
		throw runtime_error("Out of Range Access: 4");
	ptr[r] = elem;
}
/*---------------------------------------------------------------------------------------------

Remove Element*/
template<typename T> 
void My_vec<T>::remove_at_rank(int r)
{
	if(r>=size) //if there is no element to remove
		throw runtime_error("Out of Range Access: 5");
	for(int i=r; i<=size; i++) 
			ptr[i]=ptr[i+1];
	size--;
}
//******************************************************************************************************
//NON MEMBER FUNCTION IMPLEMENTATION

//Output Operator
template<typename T>
ostream& operator<<(ostream& out, const My_vec<T>& vec)
{
	for(int i=0; i<vec.get_size(); i++)
		out <<vec[i] <<' ';
	return out;
}
/*--------------------------------------------------------------------------------------------	

Find the index with the largest value*/	
template<typename T>
int find_max_index(const My_vec<T>& v,int size)
{
	if(size==0) // if no elements in vector
		throw range_error("No Elements to Find: 6");
	auto largest = v[0]; // starts at element 
	int max=0;
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
template<typename T>
void sort_max(My_vec<T>& vec)
{
	for(int i=0; (vec.get_size()-i)>0; i++)
	{
		//find max index first
		int max = find_max_index(vec, vec.get_size()-i);
		//set up local variables
		int bindex = vec.get_size()-1-i; // biggest index
		auto largest = vec[max];
		if(max!= bindex) //get the known max into the correct index
		{
			auto temp = vec[bindex];
			vec.replace_at_rank(bindex, vec[max]);
			vec.replace_at_rank(max, temp);
		}
	}
}



