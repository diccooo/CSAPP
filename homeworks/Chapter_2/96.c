#include "float_bits.h"

int float_f2i(float_bits f){
  unsigned sign = f >> 31;
  int exp = f >> 23 & 0xFF;
  int frac = (f & 0x7FFFFF) | (1 << 23);
  exp -= 127;
  if(exp < 0){
    return 0;
  }
  if(exp >= 31){
    return 0x80000000;
  }
  if(exp > 23){
    frac <<= (exp - 23);
  }
  else{
    frac >>= (23 - exp);
  }
  return sign ? -frac : frac;
}
