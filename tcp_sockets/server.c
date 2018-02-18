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

struct sockaddr {
   sa_family_t sa_family;
   char        sa_data[14];
}

*/

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define IPV AF_INET           //ipv4
#define SOCK_TYPE SOCK_STREAM //two way connection based byte streams
#define PROTO 0               //All protocols allowed
#define BUFF_SIZE 1024        //Buffer size for reading byte stream

int create_socket(struct addrinfo *socket_criteria){
   //int socket(int domain, int type, int protocol);

    return socket(socket_criteria->ai_family,
                  socket_criteria->ai_socktype,
                  socket_criteria->ai_protocol);
}

int bind_socket(int *sockfd, struct addrinfo *socket_addr_list){
  //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

  return bind(*sockfd, socket_addr_list->ai_addr,
              socket_addr_list->ai_addrlen);
}

int main(int argc, char **argv){

  int addrinfo_structure_list;
  struct addrinfo socket_criteria;          //Address Info Structure criteria for socket address selection
  socklen_t peer_addr_len;
  ssize_t nread;
  struct addrinfo *socket_addr_results;        //Points to socket address structure returned by getaddrinfo
  struct addrinfo *socket_addr_list;
  memset(&socket_criteria, 0,
         sizeof(struct addrinfo));          //Fill struct memory with constant bytes
  socket_criteria.ai_flags = AI_PASSIVE;    //Allows binding a socket that will accept connections
  socket_criteria.ai_family = IPV;          //IPv4
  socket_criteria.ai_socktype = SOCK_TYPE;  //two way connection based byte streams
  socket_criteria.ai_protocol = PROTO;      //Allow any protocol
  socket_criteria.ai_addr = NULL;           //IP to bind to not yet initialized
  socket_criteria.ai_canonname = NULL;      //Do not resolve hostname
  socket_criteria.ai_next = NULL;           //Linked list of addrinfo structures not yet initialized
  char bind_address = 0;                    //Bind to global address 0.0.0.0
  char *bind_port = "1337";
  int fd;                                   //Store file descriptor for socket creation
  char buff[BUFF_SIZE];                     //Buffer for reading byte streams
  memset(&buff, 0, sizeof(char));

  fd = create_socket(&socket_criteria);
  if ( fd == -1){
    perror("socket: unsucessful\n");
    exit(1);
  } else {
    printf("socket: success fd: %d\n", fd);
  }

  socket_addr_list = socket_addr_results;

  addrinfo_structure_list = getaddrinfo(&bind_address,
                                        bind_port,
                                        &socket_criteria,
                                        &socket_addr_results);

  if ( (bind_socket(&fd, socket_addr_list)) == -1){ //Assign address name to socket
    perror("bind: unsuccessful\n");
    exit(1);
  } else {
    printf("bind: successful addrlist: %d\n", addrinfo_structure_list);
  }

  close(fd);
  return 0;

}
