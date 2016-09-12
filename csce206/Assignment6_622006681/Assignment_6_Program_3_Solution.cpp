//Chris Comeaux 622006681
//section 501
//Student Record

#include <iostream>
#include <string>
using namespace std;

struct StudentRecord
{
	string stdName;
	string stdMajor;
	int stdUIN;
	int stdYear;
	double stdTotalCredits;
	double stdCreditsCompleted;
	double months;
};

void monthsBeforeGraduation(double, double, double&);

int main()
{
	// create variable and fill structure
	StudentRecord Student;
	cout<<"Please enter the student's name.\n";
	getline(cin, Student.stdName);
	cout<<"Please enter the student's major.\n";
	getline(cin, Student.stdMajor);
	cout<<"Please enter the student's UIN.\n";
	cin >>Student.stdUIN;
	cout<<"Please enter the number of years the student has been in college.\n";
	cin >>Student.stdYear;
	cout<<"Please enter how many hours the student needs to graduate.\n";
	cin >>Student.stdTotalCredits;
	cout<<"Please enter how many hours the student has completed.\n";
	cin >>Student.stdCreditsCompleted;
	
	// pass to function
	monthsBeforeGraduation(Student.stdTotalCredits, Student.stdCreditsCompleted, Student.months);
	
	cout <<"\t\tSTUDENT RECORD\n\n";
	cout <<"Name :\t\t\t\t" <<Student.stdName <<endl;
	cout <<"UIN  :\t\t\t\t" <<Student.stdUIN <<endl;
	cout <<"Major :\t\t\t\t" <<Student.stdMajor <<endl;
	cout <<"Class Year :\t\t\t" <<Student.stdYear <<endl;
	cout <<"Total Credits :\t\t\t" <<Student.stdTotalCredits <<endl;
	cout <<"Total Credits Completed :\t" <<Student.stdCreditsCompleted <<endl;
	cout <<"Months until graduation :\t" <<Student.months <<endl;
	
return 0;
}


void monthsBeforeGraduation(double total, double completed, double &months)
{
	double remaining = total - completed; // how many credits left to complete
	months = (remaining*6)/10;
	
}






