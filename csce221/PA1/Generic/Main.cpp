// Main.cpp (Generic)
//Tests all functionality of the My_vec class for doubles

#include <iostream>
#include <stdexcept> 
#include "My_vec.h"

int main(){
try{
	cout<<"Test Character\n";
	//create my_vec and test is_empty(), output operator and get_size()
    My_vec<char> v;                   
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
	My_vec<char> v1(v);							
	cout <<"v1: "<<v1 <<endl;								
    v1.replace_at_rank(1,'P');						
	cout <<"v1: "<<v1 <<endl;							

	//New vector and add elements
	My_vec<char> v2;								
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
	try
	{
		v2.replace_at_rank(14,'z');
	}
	catch(runtime_error &error)	
	{
	cerr << "Error: " << error.what() << endl;
	}
	
	
	//---------------------------------------------------------------------------------------------
	
	//TEST DOUBLE
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"Test Double\n";
	//create my_vec and test is_empty(), output operator and get_size()
    My_vec<double> v3;                   
	cout<<"Is v3 empty: " <<v3.is_empty()<<endl;			
    v3.insert_at_rank(0,1.0);				
	cout <<"v3: " <<v3<<endl;
	cout <<"Is v3 empty now: " <<v3.is_empty() <<endl;		
    cout <<"Size: " <<v3.get_size() <<endl;			
	
	//test insert at rank and see if get_capacity works
	v3.insert_at_rank(1,3.0);	
	v3.insert_at_rank(2,2.0);
	v3.insert_at_rank(2,5.0);
	v3.insert_at_rank(2,7.0);
	v3.insert_at_rank(2,6.0);
	v3.insert_at_rank(2,9.0);
	v3.insert_at_rank(2,10.0);
	v3.insert_at_rank(2,11.0);
	v3.insert_at_rank(2,8.0);
	cout <<"Capacity: "<<v3.get_capacity()<<endl;

	//make size==capacity and see if capacity doubles 
	v3.insert_at_rank(0,12.0);   						
	cout <<"v3: "<<v3 <<endl; 								
	cout <<"Capacity: "<<v3.get_capacity() <<endl;		 			
	cout <<"Size: "<<v3.get_size() <<endl;
	
	// Test find max index and sort
	cout <<"Max Index: "<<find_max_index(v3, v3.get_size())<<endl;   
	sort_max(v3);                                    
	cout <<"Sorted: "<<v3<<endl;

	//Furthure Testing using v3
	v3.insert_at_rank(10,1007.456); 					
	cout <<"v3: "<<v3 <<endl;         						
	cout <<"Size: "<<v3.get_size() <<endl;						

	// Test Remove funtion
	v3.remove_at_rank(2);							
	cout <<"v3: "<<v3 <<endl; 								
	cout <<"Size: "<<v3.get_size() <<endl;						

	//Test replace
	v3.replace_at_rank(1,27.0);						
	cout <<"v3: "<<v3 <<endl; 								
	cout <<"Size: "<<v3.get_size() <<endl;						
	
	//test copy constructor and replace for v4
	My_vec<double> v4(v3);							
	cout <<"v4: "<<v4 <<endl;								
    v4.replace_at_rank(1,46.0);						
	cout <<"v4: "<<v4 <<endl;							

	//New vector and add elements
	My_vec<double> v5;								
	v5.insert_at_rank(0,64.0);						
	cout <<"v5: "<<v5 <<endl;								
    cout <<"Size: "<<v5.get_size() <<endl;					

	//Test copy assignment
    v5=v4;											
	cout <<"v5: "<<v5 <<endl;								
	cout <<"Size: "<<v5.get_size() <<endl;				

	//test find max and sort after copy assignment
	cout <<"v5 max: "<<find_max_index(v5, v5.get_size()) <<endl; 
	sort_max(v5);					  				 
	cout <<"Sort: "<<v5 <<endl<<endl;      

	//Test RANGE ERROR
	try
	{
		v5.replace_at_rank(14,14.0);
	}
	catch(runtime_error &error)
	{
	cerr << "Error: " << error.what() << endl;
	}
	
	
	//-------------------------------------------------------------------------------------------
	
	//TEST INTEGER
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"Test Integer\n";
	//create my_vec and test is_empty(), output operator and get_size()
    My_vec<int> v6;                   
	cout<<"Is v6 empty: " <<v6.is_empty()<<endl;			
    v6.insert_at_rank(0,1);				
	cout <<"v6: " <<v6<<endl;
	cout <<"Is v6 empty now: " <<v6.is_empty() <<endl;		
    cout <<"Size: " <<v6.get_size() <<endl;			
	
	//test insert at rank and see if get_capacity works
	v6.insert_at_rank(1,3);	
	v6.insert_at_rank(2,2);
	v6.insert_at_rank(2,5);
	v6.insert_at_rank(2,7);
	v6.insert_at_rank(2,6);
	v6.insert_at_rank(2,9);
	v6.insert_at_rank(2,10);
	v6.insert_at_rank(2,11);
	v6.insert_at_rank(2,8);
	cout <<"Capacity: "<<v6.get_capacity()<<endl;

	//make size==capacity and see if capacity doubles 
	v6.insert_at_rank(0,12);   						
	cout <<"v6: "<<v6 <<endl; 								
	cout <<"Capacity: "<<v6.get_capacity() <<endl;		 			
	cout <<"Size: "<<v6.get_size() <<endl;
	
	// Test find max index and sort
	cout <<"Max Index: "<<find_max_index(v6, v6.get_size())<<endl;   
	sort_max(v6);                                    
	cout <<"Sorted: "<<v6<<endl;

	//Furthure Testing using v
	v6.insert_at_rank(10,1000); 					
	cout <<"v6: "<<v6 <<endl;         						
	cout <<"Size: "<<v6.get_size() <<endl;						

	// Test Remove funtion
	v6.remove_at_rank(2);							
	cout <<"v6: "<<v6 <<endl; 								
	cout <<"Size: "<<v6.get_size() <<endl;						

	//Test replace
	v6.replace_at_rank(1,27);						
	cout <<"v: "<<v6 <<endl; 								
	cout <<"Size: "<<v6.get_size() <<endl;						
	
	//test copy constructor and replace for v7
	My_vec<int> v7(v6);							
	cout <<"v7: "<<v7 <<endl;								
    v7.replace_at_rank(1,46);						
	cout <<"v7: "<<v7 <<endl;							

	//New vector and add elements
	My_vec<int> v8;								
	v8.insert_at_rank(0,64);						
	cout <<"v8: "<<v8 <<endl;								
    cout <<"Size: "<<v8.get_size() <<endl;					

	//Test copy assignment
    v8=v7;											
	cout <<"v8: "<<v8 <<endl;								
	cout <<"Size: "<<v8.get_size() <<endl;				

	//test find max and sort after copy assignment
	cout <<"v8 max: "<<find_max_index(v8, v8.get_size()) <<endl; 
	sort_max(v8);					  				 
	cout <<"Sort: "<<v8 <<endl<<endl;      

	//Test RANGE ERROR
	try
	{
		v8.replace_at_rank(14,14);
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
