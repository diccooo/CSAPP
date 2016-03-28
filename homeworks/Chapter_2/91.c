#include "float_bits.h"
#include <math.h>

float_bits float_absval(float_bits f){
  if(is_nan(f)){
    return f;
  }
  return f & 0x7FFFFFFF;
}

float float_abs(float f){
  if(is_nan(f2b(f))){
    return f;
  }
  return fabs(f);
}

int main(){
  fbtest(float_absval, float_abs);
}
