#include "float_bits.h"

float_bits float_negate(float_bits f){
  if(is_nan(f)){
    return f;
  }
  return f ^ 0x80000000;
}
