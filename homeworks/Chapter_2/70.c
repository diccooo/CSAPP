int fits_bits(int x, int n){
  x >> (n -1);
  return !x || !(~x);
}
