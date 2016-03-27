#include <stdio.h>

int int_shifts_are_logical(){
  int x = -1;
  int w = sizeof(int) << 3;
  x = x >> (w - 1);
  return !!~x;
}

/*
int int_shifts_are_arithmetic(){
  int x = -1;
  return (x>>1) == -1;
}
*/

int main(){
  printf("%d\n", int_shifts_are_logical());
}
