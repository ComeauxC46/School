//Chris Comeaux 
//CSCE 121 - 501
// Due: September 22, 2015
// hw2pr1.cpp
// amendments found at http://totallyhistory.com/list-of-27-amendments-to-the-u-s-constitution/

#include "std_lib_facilities_4.h"

int get_choice();//prototype to get the choice
int choice;// global so every function has acces to it

//used for exceptions
class e{}; // used to throw and exit function
string badI = "This input is not valid. Please run the program again witn valid input\n";// used to throw an execption

int main()
{
	

	try
	{
		choice = get_choice();

		while(cin) // keeps taking input until user is finished with program and exits with a 'q'
		{
			switch(choice)
			{
				case 1:
					cout<< "\t\tAMENDMENT 1\n";
					cout<< "Guarantees the right to the freedoms of speech, press, and religion."; 
					cout<< "Protects the right to petition the government.\n";
					break;
				case 2:
					cout<< "\t\tAMENDMENT 2\n";
					cout<< "Guarantees the people’s right to own and bear arms for their defense.\n";
					break;
				case 3:
					cout<< "\t\tAMENDMENT 3\n";
					cout<< "Citizens cannot be forced to quarter soldiers during times of peace.\n";
					break;		
				case 4:
					cout<< "\t\tAMENDMENT 4\n";
					cout<< "Citizens cannot be forced to subject themselves to seizure and search without a search warrant and probable cause.\n";
					break;
				case 5:
					cout<< "\t\tAMENDMENT 5\n";
					cout<< "Prohibits abuse of governmental authority in legal procedures. ";
					cout<< "Establishes rules for indictment by eminent domain and grand jury."; 
					cout<< " Guarantees the due process rights. Protects citizens from self-incrimination and double jeopardy.\n";
					break;
				case 6:
					cout<< "\t\tAMENDMENT 6\n";
					cout<< "Guarantees fair and speedy jury trial and the rights to know the accusation, the accuser, and to find counsel and witnesses.\n";
					break;
				case 7:
					cout<< "\t\tAMENDMENT 7\n";
					cout<< "Reserves individuals’ rights to jury trial depending on the civil case, and cases already examined by not be re-opened by another court.\n";
					break;
				case 8:
					cout<< "\t\tAMENDMENT 8\n";
					cout<< "Forbids exorbitant bails and fines and punishment that is unusual or cruel.\n";
					break;
				case 9:
					cout<< "\t\tAMENDMENT 9\n";
					cout<< "Reserves the rights of citizens which are not specifically mentioned by the U.S. Constitution.\n";
					break;		
				case 10:
					cout<< "\t\tAMENDMENT 10\n";
					cout<< "Reserves powers that are not given to the U.S. government under the Constitution, nor prohibited to a State of the U.S., to the people and the States.\n";
					break;		
				case 11:
					cout<< "\t\tAMENDMENT 11\n";
					cout<< "State sovereign immunity. States are protected from suits by citizens living in another state or foreigners that do not reside within the state borders\n";
					break;		
				case 12:
					cout<< "\t\tAMENDMENT 12\n";
					cout<< "Modifies and clarifies the procedure for electing vice-presidents and presidents.\n";
					break;
				case 13:
					cout<< "\t\tAMENDMENT 13\n";
					cout<< "Except as punishment for criminal offense, forbids forced-slavery and involuntary servitude.\n";
					break;
				case 14:
					cout<< "\t\tAMENDMENT 14\n";
					cout<< "Details Equal Protection Clause, Due Process Clause, Citizenship Clause, and clauses dealing with the Confederacy and its officials.\n";
					break;
				case 15:
					cout<< "\t\tAMENDMENT 15\n";
					cout<< "Reserves citizens the suffrage rights regardless of their race, color, or previous slave status.\n";
					break;
				case 16:
					cout<< "\t\tAMENDMENT 16\n";
					cout<< "Reserves the U.S. government the right to tax income.\n";
					break;
				case 17:
					cout<< "\t\tAMENDMENT 17\n";
					cout<< "Establishes popular voting as the process under which senators are elected.\n";
					break;
				case 18:
					cout<< "\t\tAMENDMENT 18\n";
					cout<< "Denied the sale and consumption of alcohol.\n";
					break;		
				case 19:
					cout<< "\t\tAMENDMENT 19\n";
					cout<< "Reserves women’s suffrage rights.\n";
					break;
				case 20:
					cout<< "\t\tAMENDMENT 20\n";
					cout<< "Establishes date of term starts for Congress (January 3) & the President (January 20).\n";
					break;
				case 21:
					cout<< "\t\tAMENDMENT 21\n";
					cout<< "Details the repeal of the Eighteenth Amendment. State laws over alcohol are to remain.\n";
					break;
				case 22:
					cout<< "\t\tAMENDMENT 22\n";
					cout<< "Limit the terms that an individual can be elected as president (at most two terms).";
					cout<< "Individuals who have served over two years of someone else’s term may not be elected more than once.\n";
					break;
				case 23:
					cout<< "\t\tAMENDMENT 23\n";
					cout<< "Reserves the right of citizens residing in the District of Columbia to vote for their own Electors for presidential elections.\n";
					break;
				case 24:
					cout<< "\t\tAMENDMENT 24\n";
					cout<< "Citizens cannot be denied the suffrage rights for not paying a poll tax or any other taxes.\n";
					break;
				case 25:
					cout<< "\t\tAMENDMENT 25\n";
					cout<< "Establishes the procedures for a successor of a President.\n";
					break;
				case 26:
					cout<< "\t\tAMENDMENT 26\n";
					cout<< "Reserves the right for citizens 18 and older to vote.\n";
					break;
				case 27:
					cout<< "\t\tAMENDMENT 27\n";
					cout<< "Denies any laws that vary the salaries of Congress members until the beginning of the next terms of office for Representatives.\n";
					break;
			}		
	
			choice = get_choice(); // test second input

		}
	}
	catch (string x)
	{
		cerr<< x;
	}
	catch(...)
	{
		exit(1);
	}
return 0;
}

int get_choice()
{

	cout<< "\nPlease enter the number (1-27) that corresponds to the amendment you would like to view or anything else to exit\n";
	cin>>choice;
	if (!cin)
		throw e{};
	if (choice <= 0 || choice >= 28)
		throw badI;
	
	return choice;
}
