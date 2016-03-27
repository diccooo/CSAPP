#include <limits.h>

int saturating_add(int x, int y){
  int w = sizeof(int) << 3;
  int t = x + y;
  int ans = x + y;
  x >>= (w - 1);
  y >>= (w - 1);
  t >>= (w - 1);
  int pos_ovf = ~x & ~y & t;
  int neg_ovf = x & y & ~t;
  int novf = ~(pos_ovf | neg_ovf);
  return (pos_ovf & INT_MAX) | (novf & ans) | (neg_ovf & INT_MIN);
}
