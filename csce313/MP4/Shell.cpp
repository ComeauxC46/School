/* 
    File: Shell.h

    Author: Clifton Sims, Chris Comeaux
            Department of Computer Science
            Texas A&M University
    Date  : 10/5/2016
	
	This file contains the implementation of the module "Shell.h".

*/


/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "Shell.h"
#include <stdio.h>




/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE SHELL */
/*--------------------------------------------------------------------------*/

void derterminePrompt (bool& prompt, bool& customPrompt, int argc, char ** argv)
{
	/*Variables Used in Function*/
    string input;
	
	//if the user inputs more than one flag
	if (argc > 2) 
	    throw -1; //Throw error

	//if the user inputs the correct number of falgs
    else if (argc == 2)  
	{
		input = argv[1];//
		if (input == "-t")
			prompt = false;
		else if(input == "-c")
			customPrompt = true;
		else 
			throw -1; //Throw error
	}
	
	//default
	else
	{
		prompt = true;
		customPrompt = false;
	}
	
}


void printPrompt(const bool prompt, const bool customPrompt)
{
	/*Variables Used in Function*/
	string user_name = " "; // initilized to space incase getlogin fails
    string current_dir = " "; // initilized to space incase getcwd fails
    string currentT_D = " "; //holds current time and date
	
	
	if (prompt)
        {
            char* user = getlogin(); //get user name
            if (user!= NULL)
                user_name = (string)user;
            
	        cout << "\n[" <<user_name << "]->Shell\n:: ";
        }
	    else if (customPrompt)
	    {
	        //Get working directory
	        char buf[1024];
	        if (getcwd(buf, sizeof(buf)) != NULL)
	            current_dir = (string)buf;
	            
	        //Get user name     
	        char* user = getlogin(); //get user name
            if (user!= NULL)
                user_name = (string)user;
                
            //Get time and date
            time_t rawtime;
            struct tm* t_info;
            char buffer[80];
            time (&rawtime);
            t_info = localtime(&rawtime);
            strftime(buffer,80,"(%m/%d/%Y %I:%M:%S)",t_info);
            currentT_D = (string)buffer;
            
	        cout <<"\n[" << user_name <<"]->Shell:"
	             << current_dir << " "
	             << currentT_D <<"\n:: ";
		}
	    else
			cout <<endl;
}


void parse(char* cmdLine, char** arg, bool& cd, bool& fOut, bool& fIn, bool& awk, bool& pipe, bool& bckgrnd, int& pipeProcs, string& file)
{
	/*Special Case: if cd is entered*/
	char* temp = cmdLine;
	if(*temp++	== 'c' && *temp++ == 'd')
	{
		if(*temp == ' ')
			temp = cmdLine + 3;
		else 
			temp = cmdLine + 2;
		*arg = temp;
		while(*temp != '\0')   /* replace special characters with \0*/
		{	
			if (*temp == '\n')
				*temp =  '\0';
			*temp++;
		}
		cd = true;
		return;
	}
	temp = cmdLine; //reset temp
	
	/*Special Case: background &*/
	while(*temp != '\0')
	{
		*arg = cmdLine;
		if (*temp == '&')
		{
			*temp = '\0'; //get rid of ampersand 
			if(*(temp-1) == ' ')
				*(temp-1) = '\0'; //get rid of space
			if(*(temp+1) == ' ' || *(temp+1) == '\n')
				*(temp+1) = '\0';
			// replace special characters with \0
			while(*temp != '\0')   
			{	
				if (*temp == '\n')
					*temp =  '\0';
				*temp++;
			}
			bckgrnd = true;
			return;
		}
		temp++;
	}
	
	*arg = NULL; //reset arg if not background
	temp = cmdLine; //reset temp
	
	/*Special Case: Pipe*/
	while(*temp != '\0')
	{
		if (*temp++ == '|')
		{
			temp = cmdLine;
			char* t;
		
			pipeProcs = 0;
			for (char *p = strtok(temp,"|"); p != NULL; p = strtok(NULL, "|"))
			{
				*arg = strdup(p);
				t = *arg;
				if(*t == ' ')
					*arg = (t+1);
				while(*t != '\0')
				{
					if((*(t+1) == '\0' && *t == ' ') || *t == '\n')
						*t = '\0';
					t++;
				}
				*arg++;
				pipeProcs++;
			}
			//cout <<pipeProcs<<endl;
			pipe = true;
			return;
		}
	}
	
	*arg = NULL; //reset arg if not pipe
	temp = cmdLine; //reset temp
	
	/*Special Case: awk*/
	if(*temp++ == 'a' && *temp++ == 'w' && *temp++ == 'k')
	{
		awk = true;
		*arg++ = cmdLine; 
		if(*temp == ' ')
		{
			*temp = '\0';
			temp = cmdLine + 4;
		}
			
		else
			temp = cmdLine + 3;
		if(*temp == (char)39) //ascii symbol for '
		{
			*temp++ = '\0'; //remove beginning '
			*arg++ = temp;
			
			while(*temp != (char)39)
				*temp++;
			*temp++ = '\0'; //remove ending '
			*arg = ++temp;
			
			/* replace special characters with \0*/
			while(*temp != '\0')   
			{	
				if (*temp == '\n')
					*temp =  '\0';
				*temp++;
			}
			return;
		}
		else
		{
			if(*temp == ' ')
			{
				*temp = '\0';
				*arg = (temp+1);
				cout <<"here2"<<endl;
			}
			else
				*arg = temp;
			while(*temp != '\0' || *temp != '\n')
				*temp++;
			*temp = '\0';
			return;
		}
	}
	temp = cmdLine;//reset temp
	
	/*File Output*/
	while(*temp++ != '\0')
	{
		*arg = cmdLine; 
		if (*temp == '"')
			break;
			
		if (*temp == '>')
		{
			fOut = true;

			/*Get file name*/
			if(*(temp + 1) = ' ')
				file = (string)(temp+2); //record file name
			else
				file = (string)(temp+1); //record file name
			for(int i = 0; file[i] != '\0'; i++)
			{
				if(file[i] == '\n')
					file[i] = '\0';
			}		

			/*Get argument*/
			if(*(temp - 1) = ' ')
				temp = temp - 1; //make everything after the command NULL 
			while(*temp++ != '\0') //replace everything else with NULL
				*temp = '\0';
			return;
		}
	}
	temp = cmdLine;//reset temp
	*arg = NULL; //reset arg if not file I/O
	
	/*File Input*/
	while(*temp++ != '\0')
	{
		*arg = cmdLine; 
		if (*temp == '"')
			break;
			
		else if (*temp == '<')
		{
			fIn = true;

			/*Get file name*/
			if(*(temp + 1) = ' ')
				file = (string)(temp+2); //record file name
			else
				file = (string)(temp+1); //record file name
			for(int i = 0; file[i] != '\0'; i++)
			{
				if(file[i] == '\n')
					file[i] = '\0';
			}		

			/*Get argument*/
			if(*(temp - 1) = ' ')
				temp = temp - 1; //make everything after the command NULL 
			while(*temp++ != '\0') //replace everything else with NULL
				*temp = '\0';
			return;
		}
	}
	
	
	*arg = NULL; //reset arg if not file I/O
	while(*cmdLine != '\0')
	{		
		while(*cmdLine == ' ' || *cmdLine == '\t' || *cmdLine == '\n' || *cmdLine == '"')   /* replace special characters with 0*/
		{	
			*cmdLine =  '\0';
			*cmdLine++;
		}
		*arg++ = cmdLine;
		while (*cmdLine != '\0' && *cmdLine != '\n' && *cmdLine != ' ' && *cmdLine != '\t')
		{
			if(*cmdLine ==  '"')
			{
				*cmdLine =  '\0';
				cmdLine++;
			}
			else cmdLine++; /* find next arguement  */
		}
	}
	*arg = NULL; //end of argument list
}