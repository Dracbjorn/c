#include <stdio.h>

void question1(void);
void question2(void);


void reverse(int *ptr, int length);

int main(int argc, char **argv){

  int a[7] = {1,2,3,4,5,6,7};


  reverse(a, 7);

}


void reverse(int *ptr, int length)
{
  for (int i = length - 1; i >= 0; i--)
  {
    printf("%d\n", ptr[i]);
  }
}


char *pChar;
int *pInt;
float *pFloat;

sizeof(pChar);
sizeof(pInt);
sizeof(pFloat);

#include "stdlib.h"
int main()
{
 int *pInt;
 int **ppInt1;
 int **ppInt2;

 int *x = (int *) malloc(sizeof(int));

 pInt = (int*)malloc(sizeof(int));
 ppInt1 = (int**)malloc(10*sizeof(int*));
 ppInt2 = (int**)malloc(10*sizeof(int*));

 ppInt2[0] = x;
 free(pInt);
 free(ppInt1);
 free(x);
 return 0;
}


//free(*ppInt2) is not correct. It’ll give compile time error.
//free(*ppInt2) is not correct. It’ll give run time error.
//No issue with any of the malloc() and free() i.e. no compile/run time errorinte
