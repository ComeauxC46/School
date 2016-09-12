// Chris Comeaux 622006681
// Section 501
// Probability Machine

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void BinaryFlip ();

int flipNum = 1; // holds number of times coin is flipped
int ranNum; // holds either 0 or 1

int main ()
{
    // set up random numbers
	srand(time(0));
	int tosses; // holds number of tosses the user would like
	
	cout <<"Enter the number of tosses...\n";
	cin >> tosses;
	cout <<endl;
	
	for (flipNum; flipNum <= tosses; flipNum++)
	{
		ranNum = rand()%2;
		BinaryFlip ();	
	}
return 0;
}
	
void BinaryFlip ()
{
	static int hNum; // counter variable for number of times heads come up
	static int tNum; // counter variable for number of times tails come up
	string side; // what side came up
	double hAnswer; // holds probability of heads
	double tAnswer; // holds probability of tails

		if (ranNum == 0)
		{
			side = "Heads";
			hNum++;
		}
		
		else if (ranNum == 1)
		{
			side = "Tails";
			tNum++;
		}
		
		hAnswer = (static_cast<double>(hNum))/flipNum;
		tAnswer = (static_cast<double>(tNum))/flipNum;

		cout <<flipNum <<"\t" <<side <<"\tP(H) = ";
		cout <<hAnswer <<"\tP(T) = " <<tAnswer <<endl;
}