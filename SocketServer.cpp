	#include <iostream>
	#include <sys/types.h>   // Types used in sys/socket.h and netinet/in.h
	#include <netinet/in.h>  // Internet domain address structures and functions
	#include <sys/socket.h>  // Structures and functions used for socket API
	#include <netdb.h>       // Used for domain/DNS hostname lookup
	#include <unistd.h>
	#include <errno.h>
        #include <cstdlib>
        #include <strings.h>
        #include <stdio.h>
        #include <cstring>
        #include "CGAL_Binding_Utils.h"
        #include "CGAL_Geometry_Simplifier.h"
        #include "pugixml.hpp"
        #include <fstream>
        #include "CGAL_Binding_Utils.h"
        #include "CGAL_Binding.h"
        #include "CGAL_Geometry_Simplifier.h"
        #include <mongoose.h>
	
//	using namespace std;
//        
//        
//        std::string readSocket(int socketConnection);
//        void writeSocket(int socketHandle, std::string data);
//	 
//	main()
//	{
//            
//            
//
//
//	   struct sockaddr_in socketInfo;
//	   
//	   struct hostent *hPtr;
//	   int socketHandle;
//	   int portNumber = 8080;
//	 
//	   bzero(&socketInfo, sizeof(sockaddr_in));  // Clear structure memory
//	 
//	   
//	 
//	   if((socketHandle = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//	   {
//	      close(socketHandle);
//	      exit(EXIT_FAILURE);
//	   }
//	 
//	   // Load system information into socket data structures
//	 
//	   socketInfo.sin_family = AF_INET;
//	   socketInfo.sin_addr.s_addr = htonl(INADDR_ANY); // Use any address available to the system
//	   socketInfo.sin_port = htons(portNumber);      // Set port number
//	 
//	   // Bind the socket to a local socket address
//	 
//	   if( bind(socketHandle, (struct sockaddr *) &socketInfo, sizeof(socketInfo)) < 0)
//	   {
//	      close(socketHandle);
//	      
//	      exit(EXIT_FAILURE);
//	   }
//	   
//	   listen(socketHandle, 1);
//	 
//	   int socketConnection;
//           //if you change code here change code in while loop
////           socketConnection = accept(socketHandle, NULL, NULL);
////           close(socketHandle);
//           std::string result;
////           result = readSocket(socketConnection);
////           writeSocket(socketHandle, result);
//           
//           while(1){
//               if( (socketConnection = accept(socketHandle, NULL, NULL)) < 0)
//                {
//                   close(socketHandle);
//                   if(errno == EINTR) continue;
//                   perror("balls");
//                   exit(EXIT_FAILURE);
//                }
//               switch(fork()){
//                   case -1:
//                       perror("fork");
//                       close(socketHandle);
//                       close(socketConnection);
//                   case 0:
//                       close(socketHandle);
//                       result = readSocket(socketConnection);
//                       writeSocket(socketHandle, result);
//                       
//                       exit(EXIT_SUCCESS);
//                       
//                   default:
////                       close(socketConnection);
//                       continue;
//               }
//               
//	   
//           }
//	   
//	 
//	   
//	}
//        std::string readSocket(int socketConnection){
//	   
//           int rc = 0;
//           int messageHeaderSize = 256;
//           int messageSize = 0;
//           int remainingMessageSize = 0;
//	   
//	   unsigned char *headerBuf= new unsigned char[messageHeaderSize];
//	 
//	   
//	 
//	   rc = recv(socketConnection, headerBuf, messageHeaderSize , 0);
//	 
//	   if ( rc == 0 )
//	       cerr << "Socket closed" << endl;
//	   else if ( rc == -1 )
//	       cerr << "Socket error" << endl;
//	   else if ( rc != messageHeaderSize )
//	       cerr << "Problem reading header" << endl;
//	 
//	   // Read message
//	   pugi::xml_document doc;
//           pugi::xml_parse_result result = doc.load_buffer(headerBuf, messageHeaderSize);
//           pugi::xml_node headerNode = doc.child("header");
//           messageSize = headerNode.attribute("size").as_int();
//           std::string messageAction = headerNode.attribute("action").as_string();
//           
//	   
//	   
//
//	   int messageTotalSize = messageSize;
//	   // Create storage buffer for the message
//	   unsigned char *messageTotalBuf = new unsigned char[messageTotalSize-messageHeaderSize ];
//	   
//	   
//
//	 
//	   // How much more to read
//	   remainingMessageSize = messageTotalSize - messageHeaderSize;
//	 
//	   
//
//	 
//	   
//            int flags = MSG_WAITALL;
//            rc = recv(socketConnection, messageTotalBuf, remainingMessageSize, flags);
//
//            std::string test = Bind_CGAL(messageAction, messageTotalBuf, remainingMessageSize);
//            
//            return test;
//           
//            
//            
//           }
//        
//        void writeSocket(int socketHandle, std::string data){
//            
//            char header[256];
//            int size = data.size();
//            char* stringSize;
//            sprintf(stringSize,"%d", size);
//            strcpy(header, stringSize);
//            const char* toSend = data.c_str();
//            send(socketHandle, header, 256, 0);
//            send(socketHandle, toSend, data.size(), 0);
//        }
//        
//        
