#include <stdio.h>

unsigned rotate_right(unsigned x, int n){
  int w = sizeof(unsigned) << 3;
  unsigned t = x << (w - n - 1) << 1;
  return t | (x >> n);
}

int main(){
  unsigned x = 0x12345678;
  printf("%x\n", rotate_right(x, 4));
  printf("%x\n", rotate_right(x, 20));
}
