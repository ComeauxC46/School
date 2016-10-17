/* 
    File: Shell.h

    Author: Clifton Sims, Chris Comeaux
            Department of Computer Science
            Texas A&M University
    Date  : 10/5/2016
	
	This file contains the declaration of the module "Shell.cpp".

*/


/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include <unistd.h>     /*fork and exec */
#include <sys/types.h>  /*pid_t*/
#include <sys/wait.h>   /*wait & waitpid*/
#include <errno.h>      /*errno*/
#include <string.h>     /*strerror*/
#include <fcntl.h>      /*file open function*/
#include <ctime>        /*current time*/
#include <exception>    /*exceptions*/
#include <iostream>     /*input and output*/
using namespace std;


/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE SHELL */
/*--------------------------------------------------------------------------*/


void derterminePrompt (bool& prompt, bool& customPrompt, int argc, char ** argv); /*Function dertermins which promt to output*/

void printPrompt(const bool prompt, const bool customPrompt);  /*Function takes in 2 bools initilized during startup and determins which prompt to print output*/

void parse(char* cmdLine, char** arg, bool& cd, bool& fOut, bool& fIn, bool& awk, bool& pipe, bool& bckgrnd, int& pipeProcs, string& file); /*Parses the user input using grammer:

										valid string = unix command PIPE unix command || unix command REDIRECTION filename || unix command AMP || unix command || special command

										*unix command = command name ARGS
										
										*special command = cd DIRECTORY || exit
										
										*command name = any valid executable/interpreted file name
										
										*AMP = &
										
										*ARG = string
										
										*ARGS = ARG ARGS || ARG
										
										*DIRECTORY = absolute path || relative path
										
										*PIPE = |
										
										*REDIRECTION = < || >
									    */	

									   
									   
									   
	