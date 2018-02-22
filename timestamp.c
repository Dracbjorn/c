#include <time.h>
void timestamp()
{
    time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
}
On my PC, it just prints

Wed Mar 07 12:27:29 2012

==================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* get_timestamp(){
   time_t rawtime;
   struct tm * timeinfo;
   char buffer[16];
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   strftime (buffer,16,"%G%m%d%H%M%S",timeinfo);
   puts(buffer);
   return buffer; 
}

int main() 
{
   puts(get_timestamp());
   return 0;
}

You are returning a pointer to a stack variable and therefore it is not valid to use after the function returns:

 char buffer[16];
Will be allocated on the stack in the function. When you return the stack is cleaned up and buffer is no longer valid. With minimal changes this is probably a better function signature:

void get_timestamp( char *buffer, size_t buffLen  )
The assumption being that you have properly allocated space for buffer before calling get_timestamp.

=================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char date[9];
  time_t t = time(0);
  struct tm *tm;

  tm = gmtime(&t);
  strftime(date, sizeof(date), "%Y%m%d", tm);
  printf("log.%s\n", date);
  return EXIT_SUCCESS;
}

==================================

/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* Return a character string representing the current date and time.  */

char* get_timestamp ()
{
  time_t now = time (NULL);
  return asctime (localtime (&now));
}

int main (int argc, char* argv[])
{
  /* The file to which to append the timestamp.  */
  char* filename = argv[1];
  /* Get the current timestamp.  */
  char* timestamp = get_timestamp ();
  /* Open the file for writing.  If it exists, append to it;
     otherwise, create a new file.  */
  int fd = open (filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
  /* Compute the length of the timestamp string.  */
  size_t length = strlen (timestamp);
  /* Write the timestamp to the file.  */
  write (fd, timestamp, length);
  /* All done.  */
  close (fd);
  return 0;
}