int tsub_ovf(int x, int y){
  int w = sizeof(int) << 3;
  int t = x - y;
  x >>= (w-1);
  y >>= (w-1);
  t >>= (w-1);
  return (x != y) && (y == t);
}
