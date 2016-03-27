#include <stdio.h>

unsigned put_byte(unsigned x, unsigned char b, int i){
  unsigned r;
  unsigned m = 0xFF;
  r = x & (~(m << (8 * i)));
  r |= (b << (8 * i));
  return r;
}

int main(){
  printf("%X\n", put_byte(0x12345678, 0xAB, 2));
  printf("%X\n", put_byte(0x12345678, 0xAB, 0));
}
