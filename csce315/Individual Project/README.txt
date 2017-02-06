README.txt

Created and tested in an UNIX/Linux environment.


TO COMPILE AND RUN:

1. Run provided makefile on any linux server or device by running command "make".
2. The makefile will produce a executable file named "database".
3. Run the program using "./database".



INPUT SPECIFICATIONS:

Commands can be entered one by one into the command line, a full set of commands
can be coppied and pasted into the command line, or a .txt file of commands can 
used via input redirection (./database < file.txt).

NOTE* Commands MUST be in the format as shown in Command List below.
	  The only exception is that the command letters and input type
	  letters are NOT case sensitive. 

NOTE* Command file must be in UNIX formatting.



COMMAND LIST AND DISCRIPTIONS:

B <ISBN> <Title>
- Define a book. The ISBN is a 13 digit number. The Title is a string of arbitrary length (ending
  with a line break).
  e.g.: B 1234567890123 Programming for Programmers

D <ISBN> <A | E | D> <value>
- Define a characteristic of a book (for the book with the given ISBN. If ‘A’ is used, then the
  Author is set, and the value is name of the author (string of arbitrary length, ending with end of
  line). If ‘E’ is used, the value is the number of the edition (a positive integer). If D is used, it is
  the date of publication, where the date is in MM/YYYY format (no day).
  e.g.: D 1234567890123 D 01/2017
  
M <ISBN> <Cost> <N | U | R | E>
- Define the cost for a book. ISBN is the ISBN number, Cost is an amount, expressed as a floatingpoint
  number with 2 spaces after the decimal point. The final letter indicates whether the price
  is for a New, Used, Rented, or Electronic version of the book. A book may have a different price
  for each format.
  e.g.: M 1234567890123 39.99 N
  
C <Department Code> <Course Number> <Name>
- Define a course. The Department Code is a 4 letter code for a department. The course number
  is a 3-digit number for the course. The name is a name for the course – a string of arbitrary
  length, ended by the end of the line.
  e.g.: C CSCE 315 Programming Studio
  
A <ISBN> <Department Code> <Course Number> <Section Number> <R | O>
- Assign a book to a class. The ISBN is the ISBN number for the book. The Department Code and
  Course number are as in the definition of a course. The section number is a 3 digit integer. The
  final digit is either R for required or O for optional.
  e.g.: A 1234567890123 CSCE 315 501 R
  
GC <Department Code> <Course Number>
- Print the books required and optional for all sections of a given course

GS <Department Code> <Course Number> <Section Number>
- Print the books required and optional for a given section of a course

GB <ISBN>
- Print all information known about a particular book

PB
- Print a list of all books that are defined

PC
- Print a list of all courses that are defined

PY <MM/YYYY>
- Print all books with known publication dates in the given month/year or later. 

PD <Department Code>
- Print the list of all books used in a department, given by department code. Do not list by
  section.
  
PM <Department Code>
- Print the AVERAGE minimum and maximum costs of all books in a department. Minimum cost is
  the cost of the cheapest version of required books for a section. Maximum cost is the cost of
  the most expensive required and optional books in a course. If a book has no known costs,
  ignore it. The average is the average across all sections in a department for which there is some
  required or optional book. 