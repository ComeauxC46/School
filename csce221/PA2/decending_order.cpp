#include <iostream>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <fstream>

using namespace std;


int main()
{
    int n, i;
    int r;
	int temp_value;

    srand(time(0)); // set a seed for random-num
                    //generation
    cout << "Enter number of random numbers: ";
    cin >> n;
	int A[n+1];
    for(i = 0; i <= n; i++)
    {
		A[i] =  rand() % 65535 - 32768;
    }
	 
	for(int k = 0; k <= n-1; k++)
	{
		int index = k;
		for(int i = k+1; i <= n; i++)
		{
			if (A[i] >= A[index]) index = i;
		}
		int tmp = A[index]; // swap A[k] and A[index]
		A[index] = A[k];
		A[k] = tmp;
	}
	ofstream os;
	os.open("decending_order.txt");
	A[0] = n;
	for(i = 0; i <= n; i++)
    {
		os << A[i]<< endl; 
    }
	os.close();
    return 0;
}