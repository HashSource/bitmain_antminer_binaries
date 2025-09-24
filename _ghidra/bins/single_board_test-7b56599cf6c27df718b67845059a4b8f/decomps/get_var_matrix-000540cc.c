
float get_var_matrix(float *matrix,int len)

{
  float fVar1;
  int len_local;
  float *matrix_local;
  float avg;
  int i;
  float var;
  
  var = 0.0;
  fVar1 = get_avg_matrix(matrix,len);
  for (i = 0; i < len; i = i + 1) {
    var = var + (matrix[i] - fVar1) * (matrix[i] - fVar1);
  }
  return var / (float)(longlong)len;
}

