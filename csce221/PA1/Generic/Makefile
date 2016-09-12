all: main.o
	c++ -std=c++11  Main.o -o main
main.o: Main.cpp My_vec.h
	c++ -std=c++11 -c -g Main.cpp
clean:
	rm *.o main
