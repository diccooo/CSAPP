double poly(double a[], double x, int degree)
{
  long int i = 0;
  double result = 0;
  double xpwr = 1;
  double xp2 = x * x;
  double xp4 = xp2 * xp2;
  int limit = degree - 4;
  double s1, s2;
  for (i = 0; i <= limit; i += 4){
    s1 = a[i] + a[i + 1] * x;
    s2 = a[i + 2] + a[i + 3] * x;
    s1 += s2 * xp2;
    result += s1 * xpwr;
    xpwr *= xp4;
  }
  for (; i <= degree; i++){
    result += a[i] * xpwr;
    xpwr *= x;
  }
  return result;
}
