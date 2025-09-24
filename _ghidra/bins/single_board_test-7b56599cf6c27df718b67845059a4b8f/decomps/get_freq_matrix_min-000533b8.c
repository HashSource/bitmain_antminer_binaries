
float get_freq_matrix_min(float *matrix,int len)

{
  _Bool _Var1;
  int len_local;
  float *matrix_local;
  int i;
  float min;
  
  min = *matrix;
  for (i = 0; i < len; i = i + 1) {
    _Var1 = compare(min,matrix[i]);
    if (_Var1) {
      min = matrix[i];
    }
  }
  return min;
}

