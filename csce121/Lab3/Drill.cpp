#include "std_lib_facilities_4.h"

int main()
{
	string first_name;
	cout<< "Please enter your first name\n";
	cin>> first_name;
	cout<< "Hello, " <<first_name;
	
	cout<< "\nPlease enter the name of the person you want to write to:\n";
	cin>> first_name;
	cout<< "Dear " <<first_name <<",\n\n";
	
	cout<< "\t How are you?\n";
	cout<< "I am fine. I miss you. I hope everything is going well.\n";
	cout<< "I am enjoying college and I hope you are too.\n";
	cout<< "I can't wait too see you again.\n\n";
	
	cout<< "Please enter a name of another friend\n";
	cin>>first_name;
	char friend_sex = '0';
	cout<< "Please enter m if your friend is a male and f if your friend is a female\n";
	cin>> friend_sex;
	if(friend_sex=='m')
		cout<< "If you see " <<first_name <<" please ask him to call me\n";
	if(friend_sex=='f')
		cout<< "If you see " <<first_name <<" please ask her to call me\n";
	
	int age;
	cout<< "Please enter the age of the recipient\n";
	cin>> age;
	if(age<= 0 || age >= 110)
		simple_error("you're kidding!");
	else
		cout<< "I hear you just had a birthday and you are " <<age <<" years old\n";
	
	if(age <= 12)
		cout<< "Next year you will be " <<age+1;
	else if(age == 17)
		cout<< "Next year you will be able to vote\n";
	else if(age >= 70)
		cout<< "I hope you are enjoying retirement\n\n";
		
	cout<< "Yours sincerely\n\n";
	
return 0;
	
}