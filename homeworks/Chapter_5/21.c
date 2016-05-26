void psum1b(float a[], float p[], long int n)
{
  long int i;
  float v1, v2;
  float val = 0;
  for (i = 0; i < n - 1; i += 2){
    v1 = a[i];
    v2 = a[i + 1];
    val += v1;
    p[i] = val;
    val += v2;
    p[i + 1] = val;
  }
  for (; i < n; i++){
    val += a[i];
    p[i] = val;
  }
}
