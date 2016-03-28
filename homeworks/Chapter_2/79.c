int fiveeighths(int x){
  int w = sizeof(int) << 3;
  int r = (x >> 1) + (x >> 3);
  int f = ((x << 2) & 7) + (x & 7);
  return r += ((r >> (w - 1)) && f);
}
