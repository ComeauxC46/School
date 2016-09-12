//Random Number Generator
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{ 
	//create seed fir true random numbers
	srand(time(0));
	
	int quantity; // number of intergers
	//get number of integers
	cout << "How many integers?\n";
	cin >> quantity;
	
	//creat output stream object and open the file
	ofstream os;		
	os.open("random_order.txt");
	os <<quantity <<endl;   // first line holds the amout of numbers
	
	//output the random number to file
	for(int i=0; i<quantity; i++)
		os <<rand()%65535 - 32768 <<endl; //range of all possible number that can be stored in int
	os.close();
		
return 0;
}