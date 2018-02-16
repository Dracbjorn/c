#include <stdio.h>
#include <string.h>

char myChar[20];

int main(int argc, char **argv){
  memset(myChar, 0, sizeof(myChar));
  myChar = "Kent";
}
