#include "float_bits.h"

float_bits float_half(float_bits f){
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if(exp == 0){
    return (sign << 31) | ((frac >> 1) + ((frac & 1) && ((frac >> 1) & 1)));
  }
  else if(exp == 1){
    return sign << 31 | (((1 << 22) | (frac >> 1)) + ((frac & 1) && ((frac >> 1) & 1))) ;
  }
  else if(exp < 255){
    return sign<<31 | (exp-1) << 23 | frac;
  }
  else{
    return f;               // NaN
  }
}
