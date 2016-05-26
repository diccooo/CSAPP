void inner4b(vec_ptr x, vec_ptr y, data_t *dest)
{
  long int i;
  int length = vec_length(x);
  int limit = length - 2;
  data_t *xdata = get_vec_start(x);
  data_t *ydata = get_vec_start(y);
  data_t sum = (data_t) 0;
  data_t s1, s2, s3;

  for (i = 0; i < limit; i += 3){
    s1 = xdata[i] * ydata[i];
    s2 = xdata[i + 1] * ydata[i + 1];
    s3 = xdata[i + 2] * ydata[i + 2];
    sum += (s1 + s2 + s3);
  }
  for (; i < length; i++){
    sum += xdata[i] * ydata[i];
  }
  *dest = sum;
}
