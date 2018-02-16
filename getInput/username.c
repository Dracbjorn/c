#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getinput(char *username){

  char firstname[16];
  char middlename[16];
  char lastname[16];

  memset(firstname, 0, sizeof(firstname));
  memset(middlename, 0, sizeof(middlename));
  memset(lastname, 0, sizeof(lastname));

  printf("Enter first name: ");
  fgets(firstname, 10,  stdin);

  printf("Enter middle name: ");
  fgets(middlename, 10, stdin);

  printf("Enter last name: ");
  fgets(lastname, 10, stdin);

  //Create username using:

  //first character of firstname
  username[0] = tolower(firstname[0]);

  //first character of middle name
  username[1] = tolower(middlename[0]);

  //first five characters of last name
  for (int i = 0; i <= 4; i++){
      username[i + 2] = tolower(lastname[i]);
  }
}

int main(int argc, char **argv){

  char username[8];
  memset(username, 0, sizeof(username));

  printf("Creating username...\n");
  getinput(username);
  printf("Your username is: %s\n",username);

  return 0;
}
