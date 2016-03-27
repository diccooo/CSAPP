#include <stdio.h>

int leftmost_one(unsigned x){
  x |= (x >> 1);
  x |= (x >> 2);
  x |= (x >> 4);
  x |= (x >> 8);
  x |= (x >> 16);
  return x ^ (x >> 1);
}

int main(){
  unsigned x1 = 0xFF00;
  unsigned x2 = 0x6600;
  printf("%x\n", leftmost_one(x1));
  printf("%x\n", leftmost_one(x2));
}
