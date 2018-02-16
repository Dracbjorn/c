#include <stdio.h>



int main(int argc, char **argv){
  const int num = 3;
  void *ptr;
  ptr = (void*)&num*sizeof(num);
  printf("%p\n",&num);
  //*ptr = 5;
  printf("%p\n",&ptr);
  return 0;

}
