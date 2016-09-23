//Chris Comeaux 
//CSCE 121 - 501
// Due: September 22, 2015
// hw2pr4.cpp
// amendments found at http://totallyhistory.com/list-of-27-amendments-to-the-u-s-constitution/

#include "std_lib_facilities_4.h"

void get_amends(int);// prototype for function that initilizes and outputs amendments 
string badI = "This input is not valid. Please run the program again and enter an number between 1-27\n";// used to throw an exception

//variables
int choice; // both global so all function can use it
vector<string>amends(28);// string vector with size 28, this is because we want to have the ammentment number corespond to the 

int main()
{
	//get input from user
	int choice;
	cout<< "Please enter the number (1-27) that corresponds to the amendment you would like to view\n";
	if(cin>>choice)//tests to see if first input is a non number
	{
		while(cin) // always true and stopped by user using control c or bad input
		{	
			try
			{
				get_amends(choice);
			}
			catch(string x)
			{
				cerr<<x;
				break;
			}
		cin>>choice; // pauses loop to get next input
		if(!cin) // tests to see if the second input is a non number
		{
		 try
			{
				get_amends(0);
			}
			catch(string x)
			{
				cerr<<x;
			}
				}
		}
	}
	else// if choice is a non number
	{	
		try
		{
			get_amends(0);
		}
		catch(string x)
		{
			cerr<<x;
		}
	}
	

return 0;
}

void get_amends(int i)
{
	//initilize array
	amends[0]= "n/a"; // not used because amendments start at 1
	amends[1]= "Guarantees the right to the freedoms of speech, press, and religion. Protects the right to petition the government.";
	amends[2]= "Guarantees the people’s right to own and bear arms for their defense.";
	amends[3]= "Citizens cannot be forced to quarter soldiers during times of peace.";
	amends[4]= "Citizens cannot be forced to subject themselves to seizure and search without a search warrant and probable cause.";
	amends[5]= "Prohibits abuse of governmental authority in legal procedures. Establishes rules for indictment by eminent domain and grand jury. Guarantees the due process rights. Protects citizens from self-incrimination and double jeopardy.";
	amends[6]= "Guarantees fair and speedy jury trial and the rights to know the accusation, the accuser, and to find counsel and witnesses.";
	amends[7]= "Reserves individuals’ rights to jury trial depending on the civil case, and cases already examined by not be re-opened by another court.";
	amends[8]= "Forbids exorbitant bails and fines and punishment that is unusual or cruel.";
	amends[9]= "Reserves the rights of citizens which are not specifically mentioned by the U.S. Constitution.";
	amends[10]= "Reserves powers that are not given to the U.S. government under the Constitution, nor prohibited to a State of the U.S., to the people and the States.";
	amends[11]= "State sovereign immunity. States are protected from suits by citizens living in another state or foreigners that do not reside within the state borders";
	amends[12]= "Modifies and clarifies the procedure for electing vice-presidents and presidents.";
	amends[13]= "Except as punishment for criminal offense, forbids forced-slavery and involuntary servitude.";
	amends[14]= "Details Equal Protection Clause, Due Process Clause, Citizenship Clause, and clauses dealing with the Confederacy and its officials.";
	amends[15]= "Reserves citizens the suffrage rights regardless of their race, color, or previous slave status.";
	amends[16]= "Reserves the U.S. government the right to tax income.";
	amends[17]= "Establishes popular voting as the process under which senators are elected.";
	amends[18]= "Denied the sale and consumption of alcohol.";
	amends[19]= "Reserves women’s suffrage rights.";
	amends[20]= "Establishes date of term starts for Congress (January 3) & the President (January 20).";
	amends[21]= "Details the repeal of the Eighteenth Amendment. State laws over alcohol are to remain.";
	amends[22]= "Limit the terms that an individual can be elected as president (at most two terms). Individuals who have served over two years of someone else’s term may not be elected more than once.";
	amends[23]= "Reserves the right of citizens residing in the District of Columbia to vote for their own Electors for presidential elections.";
	amends[24]= "Citizens cannot be denied the suffrage rights for not paying a poll tax or any other taxes.";
	amends[25]= "Establishes the procedures for a successor of a President.";
	amends[26]= "Reserves the right for citizens 18 and older to vote.";
	amends[27]= "Denies any laws that vary the salaries of Congress members until the beginning of the next terms of office for Representatives.";
	
	if(i <=0 || i >= 28)//tests to see if number is out of range
		throw badI;
	
	cout<< "\t\tAMENDMENT" <<i <<"\n";
	cout<< amends[i] <<endl;
	cout<< "\nPlease enter another number or CTRL + C or an invalid input to exit\n"; // ask user if they cant to view another
			
}