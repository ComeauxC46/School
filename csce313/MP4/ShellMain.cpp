/* 
	File: ShellMain.cpp

    Author: Clifton Sims, Chris Comeaux
            Department of Computer Science
            Texas A&M University
    Date  : 10/5/2016
	
	Update: 
	(10/9/2016) Input redirection works, Output redirection is written but not tested, all basic commands work
				Need to work on awk function, piplining, and background functions
	(10/13/2016) Pipe works for 2 but creats zombie processes. Still need to do background and multiple pipes			
				
	
	
	This file contains the main function of the shell program.

*/


/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "Shell.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) 
{
	try
	{
		char cmdLine[1024]; /*Holds the input from user */
		char* arg[1024];    /*Holds the parsed input    */
		string file;        /*Holds file name           */
		int pipeProcs = 0;      /*Holds how many processes are in a pipped input*/
		
		/*Flags*/
		bool cd = false;
		bool fOut = false;
		bool fIn = false;
		bool awk = false;
		bool Pipe = false;
		bool bckgrnd = false;
		bool prompt;
		bool customPrompt;
		
		
		derterminePrompt(prompt, customPrompt, argc, argv);
		
		/*Get current directory*/
		const char* oldPath;/*Holds the old directory    */
		char pBuf[1024];
		if(getcwd(pBuf, sizeof(pBuf)) != NULL)
			oldPath = pBuf;

		while(true)
		{
			pid_t child_pid;
			waitpid(child_pid,NULL,WNOHANG);
			
			printPrompt(prompt, customPrompt);  /*deisplay the prompt  */
			fgets(cmdLine,1024,stdin);          /*read in command line */
			
			
			parse(cmdLine, arg, cd, fOut, fIn, awk, Pipe, bckgrnd, pipeProcs, file);	


			/*Special Case: if cd is entered*/
			if (cd)
			{
				const char* path = *arg;
				
				/*Previous Path*/
				if (path[0] == '-')
				{
					chdir(oldPath);
					cd = false;						
					continue;
				}
				
				/*Remember path */
				if(getcwd(pBuf, sizeof(pBuf)) != NULL)
					oldPath = pBuf;
				
				/*Change directory*/
				if(chdir(path) == -1)
					cout <<"Error: No such file or directory\n";
				
				
				
				cd = false;
				continue;
			}
			
			if (Pipe)
			{
				char* pipeArg[1024];
				int size = pipeProcs;
				int pfds[2];
				//pfds[0] = read end of the pipe
				//pfds[1] = write end of pipe
				int   fd_in = 0;
				
	
				for(int i = 0; i < size; i++)
				{
					//child = getpid();
					pipe(pfds); 
					if(fork()==0)
					{
						parse(arg[i], pipeArg, cd, fOut, fIn, awk, Pipe, bckgrnd, pipeProcs, file);
						//cout <<"child:" <<pipeArg[0]  <<endl;
						dup2(fd_in,0);
						if ((i+1) != size)
        					dup2(pfds[1], 1);
						close(pfds[0]);
						execvp(*pipeArg, pipeArg);
					}
					else
					{
						wait(NULL);
						close(pfds[1]);
						fd_in = pfds[0]; //save the input for the next command
					}
				}


				close(pfds[0]);
				close(pfds[1]);
				wait(NULL);
				Pipe = false;
			}
			
			if(bckgrnd)
			{
				child_pid = fork();
				if(child_pid == 0)
				{
					bckgrnd = false;
					setpgid(0,0);
					parse(*arg, arg, cd, fOut, fIn, awk, Pipe, bckgrnd, pipeProcs, file);
					cout << execvp(*arg, arg)<< endl;
					
				}
				
				else
				{
					
					bckgrnd = false;
					continue;
				}
				waitpid(child_pid, NULL, WNOHANG);
				
			}
			waitpid(child_pid, NULL, WNOHANG);
			
			
			pid_t pid = fork();
			
			if(pid == 0)
			{
				
				if(fOut)
				{
					const char* f = file.c_str();
					parse(cmdLine, arg, cd, fOut, fIn, awk, Pipe, bckgrnd, pipeProcs, file);

					errno = 0;
					int fd = open(f,O_CREAT|O_WRONLY|O_TRUNC,0666);
					
					if (fd == -1)
					{
						printf("\n open() failed with error [%s]\n",strerror(errno));
						return -1;
					}
					else
						dup2(fd,STDOUT_FILENO);
					
					close(fd);
					
				}				
				else if(fIn)
				{
				
					const char* f = file.c_str();
					parse(cmdLine, arg, cd, fOut, fIn, awk, Pipe, bckgrnd, pipeProcs, file);

					errno = 0;
					int fd = open(f,O_RDONLY);
					
					if (fd == -1)
					{
						printf("\n open() failed with error [%s]\n",strerror(errno));
						return -1;
					}
					else
						dup2(fd,STDIN_FILENO);
					
					close(fd);
				}
				

				if(!awk && (!fOut || !fIn))
				{
					/*Make sure last arg points to NULL*/
					int i=0;
					for(; *arg[i] != '\0'; i++ );
					arg[i] = NULL;
				}
			
				if(execvp(*arg, arg) == -1)
				{
					cout<< "Execution error...\n";
					return -1;
				}
				
			}
			else if (pid > 0)
			{
				fOut = false;
				fIn = false;
				awk = false;
				wait(NULL);
			}

			
			
		}
	return 0;
	}
	
	catch(int)
	{
		cerr<<"Exception: Invalid Flag \n"
		    <<"-t is used for no prompt\n"
			<<"-c is used for coustom prompt";
		return -1;
	}
	catch(...)
	{
		cerr<<"An unkown exception occurred\n";
		return -1;
	}

}