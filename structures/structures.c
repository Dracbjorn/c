#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global constants
const int age_length = 5; //Maximum length of age input
const int name_length = 20; //Maximum length of name input

//Custom Structures
struct myStruct{
  int myInt;  //Used to store an age
  char myChar[20];  //Used to store a name
};

//Functions

//custom stdin reader that allows for dynamic size of input without including newlines
//This is superior to fgets()
void readline(char *string, int maxlen){ //Receive pointer to char and max length integer
  char ch;  //Stores character from buffer
  int stringLength = 0; //Starting string Length
  int chars_remain = 1; // Boolean used to determine end of string

  while (chars_remain){
    ch = getchar(); //Get a single character from the stdin buffer
    if ((ch == '\n') || (ch == EOF)){ //if the character is not a newline or EOF assign it to *string
      chars_remain = 0;
    } else if (stringLength < maxlen -1) {
      string[stringLength] = ch;  //Assign character by reference to string char array
      stringLength++;
      continue;
    }
  }

  string[stringLength + 1] = '\0';  //Add null terminator once newline or EOF is read
}

void getInfov1(struct myStruct *myInfo){ //returns no value due to pass by reference
  char age[age_length]; //Temp char array to read age

  printf("What is your age? ");
  readline(age,age_length); //Pass temp char array by reference to store age
  myInfo->myInt = atoi(age);  //Convert age to integer and assign to referenced myInfo.myInt

  printf("What is your full name? ");
  readline(myInfo->myChar,name_length); //Pass myInfo.myChar by reference to store name

}

struct myStruct getInfov2(struct myStruct myInfo){ //Creates new local copy of myStruct myInfo
  char age[age_length]; //Temp char array to read age

  printf("What is your age? ");
  readline(age,age_length); //Pass temp char array by reference to store age
  myInfo.myInt = atoi(age); //Convert age to integer and assign to myStruct myInfo.myInt

  printf("What is your full name? ");
  readline(myInfo.myChar,name_length);  //Pass myStruct myInfo.myChar by reference to store name

  return myInfo;
}

void clear_struct(struct myStruct *m){ //wipe all memory for structure pased by reference
  memset(m,1,sizeof(struct myStruct));
}

int main(int argc, char **argv){

  struct myStruct myInfo; //Declare custom myStruct named myInfo
  int *age = &myInfo.myInt; //Create int pointer to myInfo.myInt
  char *name = *(&myInfo.myChar); //Create char pointer to myInfo.myChar

  //Print values manually assigned to structure members
  *age = 4; //Set value of myInfo.myInt using dereference
  strcpy(name, "Luke Dylan Vogt");  //Set value of myInfo.myChar *name == name
  printf("Pre-getInfov1-age is:   %d\n", myInfo.myInt);
  printf("Pre-getInfov1-name is:  %s\n", myInfo.myChar);

  clear_struct(&myInfo); //Wipe structure clean

  //Get and Print values assigned to structure members using getInfov1 (pass by reference)
  getInfov1(&myInfo); //Pass struct by reference
  printf("Post-getInfov1-age:   %d\n", myInfo.myInt);
  printf("Post-getInfov1-name:  %s\n", myInfo.myChar);

  clear_struct(&myInfo); //Wipe structure clean

  //Get and Print values assigned to structure members using getInfov2 (pass by value)
  myInfo = getInfov2(myInfo); //Pass struct by value
  printf("Post-getInfov2-age:   %d\n", myInfo.myInt);
  printf("Post-getInfov2-name:  %s\n", myInfo.myChar);

  clear_struct(&myInfo); //Wipe structure clean

  return 0;
}
