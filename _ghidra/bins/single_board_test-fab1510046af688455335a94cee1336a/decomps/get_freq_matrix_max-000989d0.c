
float get_freq_matrix_max(float *matrix,int len)

{
  _Bool _Var1;
  int len_local;
  float *matrix_local;
  int i;
  float max;
  
  max = *matrix;
  for (i = 0; i < len; i = i + 1) {
    _Var1 = compare(max,matrix[i]);
    if (!_Var1) {
      max = matrix[i];
    }
  }
  return max;
}

