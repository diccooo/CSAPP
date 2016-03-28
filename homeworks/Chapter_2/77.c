int divide_power2(int x, int k){
  int w = sizeof(int) << 3;
  int r = x >> k;
  int f = (x >> (w - 1)) && (x & ((1 << k) - 1));
  return r += f;
}
