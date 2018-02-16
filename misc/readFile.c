#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)

{

  char file[] = "/etc/passwd";

  char buff[1024] = {0};

  //if(argc != 2) { fprintf(stderr, "%s", "not enought arguments\n"); exit(-1); }

  int fd = open(file, O_RDONLY);

  lseek(fd, 20, SEEK_SET);

  read(fd, buff, 10);

  printf("%s",buff);

  close(fd);

  // read / write / seek
}
