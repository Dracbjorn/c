#include <stdio.h>

int main(int argc, char **argv){
  int i;
  for (i = 0; i < argc; i++){
    printf("Hello World! argc=%d arg %d is %s\n",argc,i,argv[i]);
  }
}
