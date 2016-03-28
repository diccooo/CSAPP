#include "float_bits.h"

float_bits float_i2f(int i){
  if(i == 0){
    return 0;
  }
  unsigned x = i > 0 ? i : -i;
  unsigned sign = i > 0 ? 0 : 1;
  int w = sizeof(int) << 3;
  int j;
  for(j = w - 1; j >= 0; j--){
    if( (x >> j) & 1) break;
  }
  unsigned bias = 127;
  unsigned exp, frac;
  exp = bias + j;
  if(j <= 23){
    frac = x << (23 - j);
  }
  else{
    frac = x >> (j - 23);
    unsigned mask = (1 << (j - 23)) - 1;
    if((x & mask) > (unsigned)(1 << (j - 24))){
      frac++;
    }
    else if((x & mask) == (unsigned)(1 << (j - 24))  &&  (frac & 1)){
      frac++;
    }
    if(frac == (1 << 24)){
      exp++;                //may happened when round
    }
  }
  frac &= 0x7FFFFF;         //frac == (1 << 24)
  return sign << 31 | exp << 23 | frac;
}
