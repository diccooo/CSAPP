#include <stdio.h>

int lower_bits(int x, int n){
  unsigned mask = (2 << (n - 1)) - 1;
  return x & mask;
}

int main(){
  int x = 0x78ABCDEF;
  printf("%x\n", lower_bits(x, 8));
  printf("%x\n", lower_bits(x, 16));
}
