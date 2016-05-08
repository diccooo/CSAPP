int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k)
{
  int j = n - 1;
  int result = 0;
  for(; j >= 0; j--)
    result += A[i][j] * B[j][k];
  return result;
}
