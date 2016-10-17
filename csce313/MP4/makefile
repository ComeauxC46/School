# makefile

all: Shell

ShellMain.o : ShellMain.cpp
	g++ -std=c++17 -c -g ShellMain.cpp

Shell.o: Shell.cpp 
	g++ -std=c++17 -c -g Shell.cpp

Shell: Shell.o ShellMain.o
	g++ -std=c++17 -o Shell ShellMain.o Shell.o 

