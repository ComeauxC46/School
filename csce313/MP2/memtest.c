#include "ackerman.h"
#include "my_allocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char ** argv) {

  //Default inputs
    int b = 128;       // 128b
	int s = 5242880;  // 512Kb
	long int input;
	
    while ((input = getopt(argc, argv, "b:s:")) != -1) 
    {
        switch (input) 
        {
            case 'b':
                b = atoi(optarg);
                break;
            case 's':
                s = atoi(optarg);
                break;
            default:
                abort();
        }
    }
  
    init_allocator(b,s);
	ackerman_main();
    atexit((void(*)())release_allocator);
}
