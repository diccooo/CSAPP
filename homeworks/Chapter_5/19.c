typedef unsigned int size_t;

void *advanced_memset(void *s, int c, size_t n)
{
  size_t cnt = 0;
  unsigned char *schar = s;
  unsigned K = sizeof(unsigned long);
  unsigned char cc = (unsigned char) c;
  unsigned long cl = 0;
  unsigned i;
  for (i = 0; i < K; i++){
    cl += cc << (8 * i);
  }
  while ((unsigned) schar % K && (cnt < n)){
    *schar++ = cc;
    cnt++;
  }
  unsigned long *slong = (unsigned long *) schar;
  while (cnt < n - K){
    *slong++ = cl;
    cnt += K;
  }
  schar = (unsigned char *) slong;
  while (cnt < n){
    *schar++ = cc;
    cnt++;
  }
  return s;
}
