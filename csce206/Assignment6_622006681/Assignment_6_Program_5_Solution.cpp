// Chris Comeaux 62200681
// Section 501
// Word Counter

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int WordCounter(const char*, int);

int main()
{
	//get input from user
	string input;
	cout <<"Please enter a string(do not enter a white space following last word)\n";
	getline(cin, input);
	
	int length = input.length();
	const char* inputPTR = input.c_str();
	
	//pass to 
	int words = WordCounter(inputPTR, length);
	cout <<"The string contains " <<words <<" words\n";
return 0;
}

int WordCounter (const char* ptr, int l)
{
	int i = 1; //counter for words
	while(*ptr != '\0')
	{
		if(*ptr == ' ')
			i++;
		ptr++;
	}
		i+1; //account for one off error with counting spaces instead of words

	return i;
}