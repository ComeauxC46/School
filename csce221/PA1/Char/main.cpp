// main.cpp (char)
//Tests all functionality of the My_vec class for doubles

#include <iostream>
#include <stdexcept> 
#include "My_vec.h"

int main(){
try{
	//create my_vec and test is_empty(), output operator and get_size()
    My_vec v;                   
	cout<<"Is v empty: " <<v.is_empty()<<endl;			
    v.insert_at_rank(0,'B');				
	cout <<"v: " <<v<<endl;
	cout <<"Is v empty now: " <<v.is_empty() <<endl;		
    cout <<"Size: " <<v.get_size() <<endl;			
	
	//test insert at rank and see if get_capacity works
	v.insert_at_rank(1,'C');	
	v.insert_at_rank(2,'E');
	v.insert_at_rank(2,'G');
	v.insert_at_rank(2,'J');
	v.insert_at_rank(2,'A');
	v.insert_at_rank(2,'F');
	v.insert_at_rank(2,'D');
	v.insert_at_rank(2,'H');
	v.insert_at_rank(2,'K');
	cout <<"Capacity: "<<v.get_capacity()<<endl;

	//make size==capacity and see if capacity doubles 
	v.insert_at_rank(0,'I');   						
	cout <<"v: "<<v <<endl; 								
	cout <<"Capacity: "<<v.get_capacity() <<endl;		 			
	cout <<"Size: "<<v.get_size() <<endl;
	
	// Test find max index and sort
	cout <<"Max Index: "<<find_max_index(v, v.get_size())<<endl;   
	sort_max(v);                                    
	cout <<"Sorted: "<<v<<endl;

	//Furthure Testing using v
	v.insert_at_rank(10,'z'); 					
	cout <<"v: "<<v <<endl;         						
	cout <<"Size: "<<v.get_size() <<endl;						

	// Test Remove funtion
	v.remove_at_rank(2);							
	cout <<"v: "<<v <<endl; 								
	cout <<"Size: "<<v.get_size() <<endl;						

	//Test replace
	v.replace_at_rank(1,'Y');						
	cout <<"v: "<<v <<endl; 								
	cout <<"Size: "<<v.get_size() <<endl;						
	
	//test copy constructor and replace for v1
	My_vec v1(v);							
	cout <<"v1: "<<v1 <<endl;								
    v1.replace_at_rank(1,'P');						
	cout <<"v1: "<<v1 <<endl;							

	//New vector and add elements
	My_vec v2;								
	v2.insert_at_rank(0,'o');						
	cout <<"v2: "<<v2 <<endl;								
    cout <<"Size: "<<v2.get_size() <<endl;					

	//Test copy assignment
    v2=v1;											
	cout <<"v2: "<<v2 <<endl;								
	cout <<"Size: "<<v2.get_size() <<endl;				

	//test find max and sort after copy assignment
	cout <<"v2 max: "<<find_max_index(v2, v2.get_size()) <<endl; 
	sort_max(v2);					  				 
	cout <<"Sort: "<<v2 <<endl<<endl;      

	//Test RANGE ERROR
	try{
		v2.replace_at_rank(14,'z');
	}
	catch(runtime_error &error)
	{
	cerr << "Error: " << error.what() << endl;
	}
}

catch(runtime_error &error){
	cerr << "Error: " << error.what() << endl;
}
}
