int cread_alt(int *xp)
{
  int t = 0;
  int * p = xp ? xp : &t;
  return *p;
}
