//Chris Comeaux 622006681
// Section 501
// Cricket - Ashes Series

#include <iostream>
#include <string>
using namespace std;

struct PlayerRecord
{
	string name;
	int runs;
	int wickets;
};

int main()
{
	// create struct array
	int size = 11;
	PlayerRecord player[size];
	
	
		
	for(int count = 0; count < size; count++)
	{
		if(count != 0)
			cin.ignore();
		cout <<"Please enter the name of player " << (count+1) <<"\n";
		getline(cin, player[count].name);
		cout <<"Please enter the number of runs player " <<(count+1) <<" has scored\n";
		cin >> player[count].runs;
		cout <<"Please enter the number of wickets player " <<(count+1) <<" has taken\n";
		cin >> player[count].wickets;
	}
	
	for(int count2 = 0; count2 < size; count2++)
	{
		if(count2 == 0)
			cout <<"SI  Name\t\tRuns\tWickets\n";
		cout <<(count2+1) <<"  " <<player[count2].name;
			if (player[count2].name.length() >= 13)
				cout <<"\t"; 
			else
				cout <<"\t\t";
		cout <<player[count2].runs <<"\t" <<player[count2].wickets <<endl;
	}
	
	int totalRuns = 0; //accumulator for runs
	
	for(int i = 0; i < size; i++)
		totalRuns += player[i].runs;
	cout <<"The total number of runs scored is " <<totalRuns <<endl;
	
	//find highest runs and wickets
	int highestRuns = player[0].runs;
	int RunsIndex = 0;
	int highestWickets = player[0].wickets;
	int wicketsIndex = 0;
	
	for(int c = 1; c < size; c++)
	{
		if(player[c].runs > highestRuns)
		{
			highestRuns = player[c].runs;
			RunsIndex = c;
		}
	
		if(player[c].wickets > highestWickets)
		{
			highestWickets = player[c].wickets;
			wicketsIndex = c;
		}
		
	}
	
	cout <<player[RunsIndex].name <<" had the most runs with ";
	cout <<highestRuns <<" runs\n";
	cout <<player[wicketsIndex].name <<" had the most wickets taken with ";
	cout <<highestWickets <<" wickets\n";
return 0;
}
	
	
	
	