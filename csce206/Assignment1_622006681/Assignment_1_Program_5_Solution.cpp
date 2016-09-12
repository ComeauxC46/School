//Chris COmeaux 622006681
//section 501
//Word Game

#include <iostream>
#include <string>
using namespace std;

int main()
{
		//Program that plays a word game
		
		//Variables
		string name;    //holds users name
		int age;        //holds users age
		string city;    //holds city name
		string college; //holds college name
		string prof;    //holds name of profession
		string animal;  //hold type of animal
		string pname;   // holds a pet's name
		
			//ask user for input
			cout << "Hello, today we will be playing a word game!\n";
			cout << "Please enter your name.\n";
			getline(cin, name);
			cout << "Please enter your age.\n";
			cin >> age;
			cin.ignore();
			cout << "Please enter the name of a city.\n";
			getline(cin, city);
			cout << "Please enter the name of a college.\n";
			getline(cin, college);
			cout << "Please enter the name of a profession.\n";
			getline(cin, prof);
			cout << "Please enter the name of an animal.\n";
			getline(cin, animal);
			cout << "Please enter the name of a pet's name.\n";
			getline(cin, pname);
			
	//program output to print story
	cout << "\n";
	cout << "There once was a person named " <<name <<" who lived in " <<city <<". At the age of " << age <<"," <<endl;
	cout << ""<<name << " went to college at " <<college <<". " <<name <<" graduated and went to work\n";
	cout << "as a " <<prof <<". Then, " <<name <<" adopted a(n) " <<animal <<" named " <<pname <<"." <<endl;
	cout << "They both lived happily ever after!\n";
	cout << "\n";
	cout << "If the above story gets displayed correctly, then I have successfully coded this Word game. Whoop!";
	
return 0;
}