/*
//netdb.h addrinfo structure

struct addrinfo
{
  int ai_flags;             //Input flags.
  int ai_family;            //Protocol family for socket.
  int ai_socktype;          //Socket type.
  int ai_protocol;          //Protocol for socket.
  socklen_t ai_addrlen;     //Length of socket address.
  struct sockaddr *ai_addr; //Socket address for socket.
  char *ai_canonname;       //Canonical name for service location.
  struct addrinfo *ai_next; //Pointer to next in list.
};
*/


#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define IPV AF_INET           //ipv4
#define SOCK_TYPE SOCK_STREAM //two way connection based byte streams
#define PROTO 0               //All protocols allowed
#define BUFF_SIZE 1024        //Buffer size for reading byte stream

int create_socket(){
    return socket(IPV, SOCK_TYPE, PROTO);
}

/*int bind_socket(int *sockfd){
  return bind(*sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr_un));
}
*/

int main(int argc, char **argv){
  struct addrinfo socket_criteria;          //Address Info Structure criteria for socket address selection
  socklen_t peer_addr_len;
  ssize_t nread;
  struct addrinfo *socket_addr_list;         //Points to socket address structure returned by getaddrinfo
  memset(&socket_criteria, 0,
         sizeof(struct addrinfo));          //Fill struct memory with constant bytes
  socket_criteria.ai_flags = AI_PASSIVE;    //Allows binding a socket that will accept connections
  socket_criteria.ai_family = IPV;          //IPv4
  socket_criteria.ai_socktype = SOCK_TYPE;  //two way connection based byte streams
  socket_criteria.ai_protocol = PROTO;      //Allow any protocol
  socket_criteria.ai_addr = NULL;           //IP to bind to not yet initialized
  socket_criteria.ai_canonname = NULL;      //Do not resolve hostname
  socket_criteria.ai_next = NULL;           //Linked list of addrinfo structures not yet initialized
  char bind_address = NULL;                //Bind to global address 0.0.0.0
  char bind_port = "1337";                   //Bind to port 1337
  int fd;                                  //Store file descriptor for socket creation
  char buff[BUFF_SIZE];                     //Buffer for reading byte streams

  fd = create_socket();
  if ( fd == -1){
    perror("socket: unsucessful\n");
    exit(1);
  } else {
    printf("socket: success fd: %d\n", fd);
  }

  getaddrinfo(&bind_address, &bind_port, &socket_criteria, &socket_addr_list);

  /*if ( (bind_socket(*fd)) == -1){ //Assign address name to socket
    perror("bind: unsuccessful\n");
    exit(1);
  } else {
    printf("bind: successful\n")
  }
  */
  return 0;

}
