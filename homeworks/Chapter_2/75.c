unsigned unsigned_high_prod(unsigned x, unsigned y);

int signed_high_prod(int x, int y){
  int w = sizeof(int) << 3;
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;
  int xm = x >> (w - 1);
  int ym = y >> (w - 1);
  return unsigned_high_prod(ux, uy) - (xm & y) - (ym & x) - (xm & ym);
}
