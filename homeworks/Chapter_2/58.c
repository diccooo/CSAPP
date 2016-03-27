#include <stdio.h>

int is_big_endian(void){
  int a = 1;
  return !*((char*)&a);
}

int main(){
  printf("%d\n", is_big_endian());
}
