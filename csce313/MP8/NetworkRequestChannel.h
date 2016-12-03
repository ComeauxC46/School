/*************************************************************************
 *                                                                       *
 * File:        Network Request Channel.h                                *
 *                                                                       *
 *                                                                       * 
 * Author:      Chris Comeaux                                            *
 *                                                                       *
 *                                                                       *
 * Date:        11/30/2016                                               *
 *                                                                       *
 * Desription:  Decloration for a Network Channel to pass information    *
 *              between 2 machines over a network.                       * 
 *                                                                       *
 *                                                                       *
 * ***********************************************************************/
 
 /**************************************
  *             Includes               *
  **************************************/
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cassert>
    #include <string.h>
    #include <sstream>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <errno.h>
    #include <arpa/inet.h>
    #include <pthread.h>

    using namespace std;



 /********************************************************
  *             Class Network Request Channel            *
  ********************************************************/


class NetworkRequestChannel
{
  
private:

    int sockfd;
    
public:    
    NetworkRequestChannel(const string _server_host_name, const unsigned short _port_no); 
    /* Creates a CLIENT-SIDE local copy of the channel. The channel is connected to the given port number at the given server host. THIS CONSTRUCTOR IS CALLED BY THE CLIENT. */ 
    
    NetworkRequestChannel(const unsigned short _port_no, void * (*connection_handler) (void *), int backlog); 
    /* Creates a SERVER-SIDE local copy of the channel that is accepting connections at the given port number. 
    
    NOTE that multiple clients can be connected to the same server-side end of the request channel. 
    Whenever a new connection comes in, it is accepted by the server, and the given connection handler is invoked.
    The parameter to the connection handler is the file descriptor of the slave socket returned by the accept call. 
    
    NOTE that the connection handler does not want to deal with closing the socket.
    You will have to close the socket once the connection handler is done. */ 
    
    NetworkRequestChannel(int fd);
    
    ~NetworkRequestChannel(); 
    /* Destructor of the local copy of the channel. */ 
    
    string send_request(string _request); 
    /* Send a string over the channel and wait for a reply. */ 
    
    string cread(); 
    /* Blocking read of data from the channel. Returns a string of characters read from the channel. Returns NULL if read failed. */ 
    
    int cwrite(string _msg); 
    /* Write the data to the channel. The function returns the number of characters written to the channel. */
    
    int read_fd();
    /* Returns the socket descriptor used from the channel. */

};
