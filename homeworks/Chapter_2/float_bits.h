#include <stdio.h>

typedef unsigned float_bits;

float b2f(float_bits x){
  return *((float *) &x);
}

float_bits f2b(float x){
  return *((float_bits *) &x);
}

int is_nan(float_bits x){
  unsigned exp = x >> 23 & 0xFF;
  unsigned frac = x & 0x7FFFFF;
  return exp == 0xFF && frac != 0;
}

int is_inf(float_bits x){
  unsigned exp = x >> 23 & 0xFF;
  unsigned frac = x & 0x7FFFFF;
  return exp == 0xFF && frac == 0;
}

int is_float_bits_equal(float_bits x, float f){
  return f2b(f) == x;
}

void fbtest(float_bits(*f1)(float_bits), float(*f2)(float)){
  unsigned i = 0;
  do{
    float_bits x = f1(i);
    float f = f2(b2f(i));
    if(!is_float_bits_equal(x, f)){
      printf("%x error\n", i);
    }
    i++;
  }
  while(i != 0);
  printf("OK\n");
}
