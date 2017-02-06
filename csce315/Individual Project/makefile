# makefile

all: database
Book.o: Book.h Book.cpp
	g++ -std=c++11 -c -g Book.cpp

Input_handler.o: Input_handler.h Input_handler.cpp 
	g++ -std=c++11 -c -g Input_handler.cpp
	
database: main.cpp Input_handler.o Book.o
	g++ -std=c++11 -g -o database main.cpp Input_handler.o Book.o
	
clean:
	rm *.o database