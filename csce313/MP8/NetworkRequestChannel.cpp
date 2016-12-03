/*************************************************************************
 *                                                                       *
 * File:        Network Request Channel.c                                *
 *                                                                       *
 *                                                                       * 
 * Author:      Chris Comeaux                                            *
 *                                                                       *
 *                                                                       *
 * Date:        11/30/2016                                               *
 *                                                                       *
 * Desription:  Implementaion of a Network Channel to pass information   *
 *              between 2 machines over a network.                       * 
 *                                                                       *
 *                                                                       *
 * ***********************************************************************/
 
 /**************************************
  *             Includes               *
  **************************************/
  #include "NetworkRequestChannel.h"
  
  /*************************************
   *            Counters               * 
   *************************************/
  int c_socks = 1;
 
  /****************************************************************
  *             Implementation Network Request Channel            *
  *****************************************************************/
  
    //Client-Side Constructure  
    NetworkRequestChannel::NetworkRequestChannel(const string _server_host_name, const unsigned short _port_no)
    {
        // Data Structures
        struct addrinfo info, *resp;
        
        //Variables and Streams
        int status;
        string port = to_string(_port_no);
		
        
        memset(&info, 0, sizeof(info));
        info.ai_family = AF_UNSPEC;
        info.ai_socktype = SOCK_STREAM;
        
        if((status = getaddrinfo(_server_host_name.c_str(), port.c_str(), &info, &resp)) != 0)
        {
            perror("Error getting address info\n");
            return;
        }
 	
       
        //Make the Socket
		cout << "\nCreating Client Socket " <<c_socks <<endl;
        sockfd = socket(resp->ai_family, resp->ai_socktype, resp->ai_protocol);
		cout <<"Socket fd of " <<c_socks++ <<": " <<sockfd <<endl;
        if (sockfd <= -1)
        {
            perror("Error creating socket\n");
            return;
        }
		cout <<"done\n";
      
        //Connect
		cerr << "Connecting Client Socket...";
        if (connect(sockfd, resp->ai_addr, resp->ai_addrlen)<0)
    	{
    		perror ("Connect error\n");
    		return;
    	}
		cout << "done\n";
        
    }
   
    //Server-Side Constructure
    NetworkRequestChannel::NetworkRequestChannel(const unsigned short _port_no, void * (*connection_handler) (void *), int backlog)
    {
        //Data Structures
        struct addrinfo info, *serv;        
        //Variables
        int rv;
        string port = to_string(_port_no);
        int master;
        
        memset(&info, 0, sizeof(info));
        info.ai_family = AF_UNSPEC;
        info.ai_socktype = SOCK_STREAM;
        info.ai_flags = AI_PASSIVE;
        
        if((rv = getaddrinfo(NULL, port.c_str(), &info, &serv)) != 0)
        {
            perror("Error getting Information\n");
            return;
        }
        
        if((master = socket(serv->ai_family, serv->ai_socktype, serv->ai_protocol)) == -1)
        {
            perror("Error on creating Server Socket\n");
            return;
        }
    
        if(bind(master, serv->ai_addr, serv->ai_addrlen) < 0)
        {
            close(master);
            perror("Server failed to Bind\n");
            return;
        }
        
        freeaddrinfo(serv);
        
        if(listen(master, backlog) < 0)
        {
            perror("Listen Error\n");
            return;
        }
        
		cout << "Waiting for a client...\n";
        for(;;)
        {
            pthread_t connection_thread;
            int temp;
			          
            //Create slave
            temp = accept(master,(struct sockaddr*)NULL, NULL);
            NetworkRequestChannel* slave = new NetworkRequestChannel (temp);
            if(temp == -1)
            {
                perror("Accept error..retrying\n");
                continue; //retry
            }
            
            //Create the thread
            pthread_create(&connection_thread, NULL, connection_handler, (void*) slave);
            
        }        
    }
    
    //Constructor
    NetworkRequestChannel::NetworkRequestChannel(int fd)
    {
        sockfd = fd;
    }

    //Destructure
    NetworkRequestChannel::~NetworkRequestChannel()
    {
        close(sockfd);
    }
    
    /*---------------------------------------------------------*/
    /*                      Helper Functions                   */
    /*---------------------------------------------------------*/
    const int MAX_MESSAGE = 255;
    
    string NetworkRequestChannel::send_request(string _request)
    {
      cwrite(_request);
      string s = cread();
      return s;
    }

    string NetworkRequestChannel::cread()
    {
      char buf[MAX_MESSAGE];
    
      if (read(sockfd, buf, MAX_MESSAGE) < 0) 
      {
        perror("Channel Read Error\n");
      }
      string s = buf;
      return s;
    }


    int NetworkRequestChannel::cwrite(string _msg)
    {

      if (_msg.length() >= MAX_MESSAGE)
      {
        cerr << "Message too long for Channel!\n";
        return -1;
      }
    
      const char * s = _msg.c_str();
    
      if (write(sockfd, s, strlen(s)+1) < 0) 
      {
        perror("Channel Write Error\n");
      }

    }
    
    int NetworkRequestChannel::read_fd() {return sockfd;}
        