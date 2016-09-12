/*========================================================================================================================================
Chris Comeaux
cmc236
Section 507
cmc236@tamu.edu
==========================================================================================================================================*/

//Main.cpp
#include "Regex.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//Local Variables Used in Program
	string line; //hold the current line from csv
	string current_name;
	string current_email;
	int current_uin;
	int current_grade;
	
	//Hash Table and helper variables
	HashTable table;
	int size; // keep track of table size (this will be the number of lines in the input file)
	
	//File Streams
	ofstream ofs;
	ifstream ifs;
	
	try
	{
		//Creat Input Stream and Open the File
		ifs.open("input.csv");
		if(!ifs) throw 1;
		
		//Get Input File Size (must be done befor because the hash function needs to know the size)
		while (!ifs.eof())
		{
			getline(ifs, line); //acts like a loop controler
			size++;
		}
		
		//Clear eof bit and seek to beginning
		ifs.clear();
		ifs.seekg(0, ios::beg);
		
		//Resize the Table to the Correct Size
		table.resize(size);
		
		while(!ifs.eof())
		{
			getline(ifs, line);//read in line to do work on
			
			// Extract UIN and Grade
			regex_search(line, match, grade);
			current_grade = stoi(match[0]);
			regex_search(line, match, uin);
			current_uin = stoi(match[0]);
			
			//Insert Into Hash Table
			table.vec[hash_function(current_uin,size)].insert(current_uin,current_grade);
		}
		//Close Current Stream, Clear eof bit and Seek to Beginning
		ifs.close();
		ifs.clear();
		ifs.seekg(0, ios::beg);
		
		/*---------------------------------------------------------------------------------------------
		NOW READ FROM ROSTER.CSV
		-----------------------------------------------------------------------------------------------*/
				
		// Open the Necessary Input and Output Files
		ifs.open("roster.csv");
		ofs.open("output.csv");
		if(!ifs || !ofs) throw 1;
		
		while(!ifs.eof())
		{
			getline(ifs, line);//read in line to do work on
			
			// Extract All Information
			regex_search(line, match, name);
			current_name = match[0];
			regex_search(line, match, email);
			current_email = match[0];
			regex_search(line, match, uin);
			current_uin = stoi(match[0]);
			
			//Update output.csv
			if(table.vec[hash_function(current_uin,size)].search(current_uin,current_grade))
				ofs <<current_name <<"," <<current_email <<"," <<current_uin <<"," <<current_grade <<endl;
			else
				ofs <<current_name <<"," <<current_email <<"," <<current_uin <<endl;
		}
		ifs.close();
		ofs.close();
	}
	catch (int)// if the input file does not open correctly the whole program will crash so return FAIL
	{
		cerr <<"Eception: File Error...\n" <<"If one of the files is open in EXCEL please close it and try again.\n";
		return -1; 
	}
	
	//Prompt User
	cout <<"Successful...Refer to 'output.csv'\n";
	
return 0;
}

