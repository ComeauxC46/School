/*
    File        : Input_handler.h
	
    Author      : 
	
    Date        : 2017/02/01
	
	Description : Declarations of functions and variables
				  that handel and process the input

*/
#ifndef _Input_handler_H_                   // include file only once
#define _Input_handler_H_ 

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

/*--------------------------------------------------------------------------*/
/* VARIABLES */
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
/* FUNCTIONS */
/*--------------------------------------------------------------------------*/

vector<string> parser(char* input);
/* Takes a char array from user input and returns
   a vector filled with the parsed input delimited by
   a " ".
   Vector Indicies:
   
   Command   -> [0]
   2nd Input -> [1]
   3rd Input -> [2]
   so on...
   
   NOTE* For inputs with book names, the names will be parsed into seperate
		 tokens.
   
*/

void processInput(vector<string> input);
/* Takes a vector of string tokens and determines 
   what action to take.
*/

#endif