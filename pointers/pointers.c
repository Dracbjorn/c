#include <stdio.h>
#include <stdlib.h>

const int STUFF = 14;

struct myStruct{
  int myInt;
  char myChar[20];
};

struct myStruct getInfov2(struct myStruct stuff){ //Function call passing structure and returning new structure
  char age[2];
  printf("What is your age? ");
  stuff.myInt = atoi(fgets(age, 20, stdin));

  printf("What is your full name? ");
  fgets(stuff.myChar, 20, stdin);

  return stuff;
}

void getInfov1(int *age, char *name){ //Function call passing pointers to structure members and returning nothing

  char age_s[2];
  printf("What is your age? ");
  fgets(age_s, 20, stdin);
  *age = atoi(age_s);

  printf("What is your full name? ");
  fgets(name, 20, stdin);
}

int getStuff(int *a, int *b, int *c){
  *a+=10; //Compound assignment adding 10 to the value stored at the address of a
  *b+=20; //Compound assignment adding 20 to the value stored at the address of b
  *c+=30; // Compound assignment adding 30 to the value stored at the address of c
  return 0;
}

int main(int argc, char **argv){

  int stackvars[10] = {1,2,3,4,5,6,7,8,9,10};   //Declared and initialized an array of ints with a length of 10
  int stackvar = 10;                            //Declared int variable with value of 10
  int stackvar2 = 8;                            //Declared int variable with value of 8
  int *arrPtr;                                  //Declared int pointer
  void *ptr;                                    //Declared void pointer
  char *ptrStuff;                               //Declared char pointer
  ptrStuff = (char*) &STUFF;                    //Assigned the address of STUFF to ptrStuff as a char
  ptr = (void *) 5;                             //Manually assigned address stored at *ptr as 0x5
  //struct myStruct myInfo;                       //Declared myStruct structure named myInfo
  int *p = &stackvar;
  int **p2p = &p;
  arrPtr = stackvars;                           //Initialized pointer to equal the address of the array stackvars
  int *pIntv1 = (int*)malloc(sizeof(int));             //Declares 4 bytes of memory for a single integer
  int **ppInt1v1 = (int**)malloc(10*sizeof(int*));      //Declares 40 bytes of memory for 10 integers
  int *pIntv2 = (int*)calloc(1,sizeof(int));             //Initializes 4 bytes of memory for a single integer
  int **ppInt1v2 = (int**)calloc(10,sizeof(int*));      //Initializes 40 bytes of memory for 10 integers

  int (*p_getStuff)(int*, int*, int*);           //Declare a function pointer named p_getstuff
  p_getStuff = getStuff;                        //Initialize the adress stored in p_getstuff to the address of getstuff


  printf("ptr       address: %p\n", ptr);  //Prints the address of 0x5
  printf("main      address: %p\n", &main); //Prints the address of the main function
  printf("STUFF     address: %p   value:%d\n", &STUFF, STUFF);  //Prints the address of the const int STUFF
  printf("ptrStuff  address: %p   value:%d\n", ptrStuff, *ptrStuff);  //Prints the address of the const int STUFF
  printf("stackvar  address: %p   value:%d\n", &stackvar, stackvar); //Prints the address of the int stackvar
  printf("stackvar2 address: %p   value:%d\n", &stackvar2, stackvar2); //Prints the address of the int stackvar2
  printf("stackvars address: %p\n", &stackvars);        //Prints the address of the int array stackvars
  printf("p         address: %p   value:%d\n", &p, *p);
  printf("p2p       address: %p   value1:%p   value2:%d\n", &p2p, *p2p, **p2p);
  printf("stackvars[0]: %d == *arrPtr: %d\nstackvars: %p == arrPtr: %p\nstackvars[3]: %d == *(arrPtr + 3): %d\n",
          stackvars[0], *arrPtr, stackvars, arrPtr, stackvars[3], *(arrPtr + 3));

  for(int i = 0; i < 10; i++)
  {
    printf("stackvars[%d]: %d\n", i, *arrPtr);  //Print the value of stackvars[i]
    printf("address of stackvars[%d]: %p\n", i, arrPtr); //Print the address of stackvars[i]
    arrPtr++;                                   //Increment *arrPtr by the size of an int (4 bytes)
  }

  int var1, var2, var3;
  var1 = 5;
  var2 = 10;
  var3 = 15;
  printf("var1    pre-value: %d\n", var1);
  printf("var2    pre-value: %d\n", var2);
  printf("var3    pre-value: %d\n", var3);
  getStuff(&var1, &var2, &var3);
  int result = (*p_getStuff)(&var1, &var2, &var3);
  printf("var1    post-value: %d\n", var1);
  printf("var2    post-value: %d\n", var2);
  printf("var3    post-value: %d\n", var3);
  printf("result  value: %d\n", result);

  /*
  myInfo.myInt = 4;
  myInfo.myChar = "Luke Dylan Vogt";
  printf("My prev1-age:   %d", myInfo.myInt);
  printf("My prev1-name:  %s", myInfo.myChar);
  getInfov1(*myInfo);
  printf("My postv1-age:   %d", myInfo.myInt);
  printf("My postv1-name:  %s", myInfo.myChar);

  printf("My prev2-age:   %d", myInfo.myInt);
  printf("My prev2-name:  %s", myInfo.myChar);
  myInfo = getInfov2(myInfo.myInt, myInfo.myChar);
  printf("My postv2-age:   %d", myInfo.myInt);
  printf("My postv2-name:  %s", myInfo.myChar);
  */

  free(pIntv1);
  free(ppInt1v1);
  free(pIntv2);
  free(ppInt1v2);
}
