/*
    File        : Input_handler.cpp
	
    Author      : 
	
    Date        : 2017/02/01
	
	Description : Implementation of the Input_handler header

*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "Book.h"
#include "Input_handler.h"

/*--------------------------------------------------------------------------*/
/* IMPLEMENTATION */
/*--------------------------------------------------------------------------*/

vector<string> parser(char* input)
{
	char* tok;
	vector<string> inputTok;

	/*Parse using " " as delimiter*/
	tok = strtok(input, " ");
	
	while (tok != NULL)
	{
		inputTok.push_back(tok);
		tok = strtok(NULL, " ");
	}
	
	return inputTok;
}


void processInput(vector<string> input)
{
	/*Transform all commands to uppercase to allow for lowercase input*/
	transform(input[0].begin(), input[0].end(), input[0].begin(), ::toupper);
	
	/*Determine command and respond with appropriate function*/
	if (input[0] == "B")
	{
		cout << "Adding " << input[1] << " to the database...";
		B(input);
		cout << "done\n";
	}
	
	else if (input[0] == "D")
	{
		cout << "Updating " << input [1] << "...";
		D(input);
		cout << "done\n";
	}
	
	else if (input[0] == "M")
	{
		cout << "Updating " << input [1] << "...";
		M(input);
		cout << "done\n";
	}
		
	else if (input[0] == "C")
	{
		cout << "Defining class: " << input[1] << " " << input[2] << "... ";
		C(input);
		cout << "done\n";
	}
		
	else if (input[0] == "A")
	{
		cout << "Adding book to class... ";
		A(input);
		cout << "done\n";
	}
		
	else if (input[0] == "GC")
	{
		cout << "Books for " << input[1] << " "  << input[2] << ":\n";
		GC(input);
	}
		
	else if (input[0] == "GS")
	{
		cout << "Books for " << input[1] << " " << input[2] << " "  << input[3] << ":\n";
		GS(input);
	}
	
	else if (input[0] == "GB")
	{
		cout << "Information for " << input[1] << ":";
		GB(input);
	}
		
	else if (input[0] == "PB")
	{
		cout << "Books: ";
		PB();
	}
		
	else if (input[0] == "PC")
	{
		cout << "Classes: \n";
		PC();
	}

	else if (input[0] == "PY")
	{
		cout << "Books published on or after " << input[1] << ":";
		PY(input);
	}
	
	else if (input[0] == "PD")
	{
		cout << "Books in Department " << input[1] << ":";
		PD(input);
	}
	
	else if (input[0] == "PM")
	{
		PM(input);
	}
	
	else
	{
		cout <<"Malformed Command...\nReference the Command_List.txt.\n";
		return;
	}
}
	
		
	
	
	
	