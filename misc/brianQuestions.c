#include <stdio.h>

void question1(void);
void question2(void);

int main(int argc, char argv**){

  question1();
  question2();
}


void question1(void)
{

  int a = 10;
  int b = 20;

  int *ptr = NULL;

  ptr = &b;

  printf("value 1: %d\n", a + ptr);
}

void question2(void)
{
  char name[] = "abcdefghijklmnopqrstuvwxyz";
  char *ptr = &(name[5]);

  printf("value 1 is: %c\n", *ptr);
  printf("value 2 is: %d\n", *ptr);
}
