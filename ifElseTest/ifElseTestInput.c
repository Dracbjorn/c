#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int age;
  char agestring[2];
  FILE input;
  printf("Enter your age: ");
  fgets(char *agestring, int *age, FILE *input);
  age = atoi(agestring);

  if (age > 50){
    printf("You are %d years old. You are OLD!\n",age);
  } else {
    printf("You are %d years old. You are YOUNG!\n",age);
  }
}
