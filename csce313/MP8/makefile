# makefile

all: dataserver client
NetworkRequestChannel.o: NetworkRequestChannel.h NetworkRequestChannel.cpp
	g++ -std=c++11 -c -g NetworkRequestChannel.cpp -lpthread

dataserver: dataserver.cpp NetworkRequestChannel.o 
	g++ -std=c++11 -g -o dataserver dataserver.cpp NetworkRequestChannel.o -lpthread
	
client: client.cpp NetworkRequestChannel.o
	g++ -std=c++11 -g -o client client.cpp bounded_buffer.cpp NetworkRequestChannel.o -lpthread
	
clean:
	rm *.o fifo* dataserver client output*