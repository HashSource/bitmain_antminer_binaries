
float get_avg_matrix(float *matrix,int len)

{
  int len_local;
  float *matrix_local;
  int i;
  float total;
  
  total = 0.0;
  for (i = 0; i < len; i = i + 1) {
    total = total + matrix[i];
  }
  return total / (float)(longlong)len;
}

