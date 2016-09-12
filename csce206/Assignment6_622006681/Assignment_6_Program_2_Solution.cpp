//Chris Comeaux 622006681
//Section 501
//Replace Substring

#include <iostream>
#include <string>
using namespace std;

void replaceSubstring(string&, string, string);

int main()
{
	// create string variables
	string string1("if you notice this notice");
	string string2("notice");
	string string3("balance");
	cout <<"String1: " <<string1 <<endl;
	cout <<"String2: " <<string2 <<endl; 
	cout <<"String3: " <<string3 <<endl;
	
	//call function
	replaceSubstring(string1, string2, string3);
	
return 0;
}


void replaceSubstring(string& string1, string string2, string string3)
{
	
	while(string1.find(string2) != std::string::npos)
	{
		int position = string1.find(string2);
		string1.replace(position, string2.length(), string3);
	}	
		cout <<"New String1: " <<string1 <<endl;
}
	
	
