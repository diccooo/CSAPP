#include <stdio.h>

int sra(int x, int k){
  int xsrl = (unsigned) x >> k;
  int w = sizeof(int) << 3;
  unsigned z = 1 << (w - k - 1);   //the (w-k)th bit, should left shift (w-k-1)
  unsigned mask = z - 1;
  unsigned right = mask & xsrl;
  unsigned left = ~mask & (~(z & xsrl) + z);
  return left | right;
}

unsigned srl(unsigned x, int k){
  unsigned xsra = (int) x >> k;
  int w = sizeof(int) << 3;
  unsigned z = 1 << (w - k - 1);
  unsigned mask = z - 1;
  return mask & xsra;
}

int main(){
  printf("%d\n", sra(-1, 1));
  printf("%d\n", srl(-1, 1));
}
