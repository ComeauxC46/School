#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

using namespace std;


int main() {
int numnumbers, numbers, num;
	
	srand(time(0));
	
	ofstream myfile;
    myfile.open ("increasing_order.txt");
	
	
	cout << "How many random numbers do you want to generate? ";
	cin >> numnumbers;
	
	int A[numnumbers + 1];
	
	for (int i = 0; i <= numnumbers; ++i) {
		num = rand() %65535 - 32768;
		A[i] = num;
	}
	
	for (int k = 0; k <= numnumbers - 1; k++)
	{
		//int index = k;
		for (int i = k+1; i <= numnumbers; i++) {
				if (A[k] <= A[i]) {
					//index = i;
					int tmp = A[k]; // swap A[k] and A[index]
					A[k] = A[i];
					A[i] = tmp;
				}
				
		}
	}
	
	myfile << numnumbers << endl;
	for (int i = numnumbers; i > 0; --i) {
		myfile << A[i] << endl;
	}

	
	
	
	myfile.close();
	
}