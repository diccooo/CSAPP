#include "float_bits.h"

float_bits float_twice(float_bits f){
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if(exp == 0){
    return (sign << 31) | (frac << 1);
  }
  else if(exp < 254){
    return sign << 31 | (exp + 1) << 23 | frac;
  }
  else if(exp == 254){
    return sign << 31 | 0xFF << 23;
  }
  else{
    return f;               // NaN
  }
}
