
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum){
  int r = word << ((3 - bytenum) << 3);
  return r >> 24;
}
