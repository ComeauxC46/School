/*
    File        : main.cpp

    Author      : 
	
    Date        : 2017/02/01
	
	Description : Program keeps track of textbooks
				  required and recommended for classes
				  and the cost of the textbooks

*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <cstring>				    //strtok
#include "Input_handler.h"

/*--------------------------------------------------------------------------*/
/* MAIN*/
/*--------------------------------------------------------------------------*/

int main()
{
	int BUFFSIZE = 1028;
	char input[BUFFSIZE];
	vector<string> inputTok;
	
	while(true)
	{
		//Main program loop
		cout << "\n\n> ";
		if(!(cin.getline(input, BUFFSIZE)))
		{
			/*If stdin redirected to an input file, read until EOF*/
			cout << "END OF FILE REACHED\n";
			break;
		}
		inputTok = parser(input);
		processInput(inputTok);
	}
		
	
return 0;

}
