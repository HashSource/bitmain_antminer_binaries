
void sw_normalize_matrix(float **matrix,int row,int column)

{
  _Bool _Var1;
  float fVar2;
  float a;
  int column_local;
  int row_local;
  float **matrix_local;
  char tmp42 [256];
  int vol;
  float totalfreq;
  float total;
  float max;
  float min;
  int i;
  
  fVar2 = get_freq_matrix_min(*matrix,column * row);
  a = (g_rt.sweep.bias + 1.0) * fVar2;
  snprintf(tmp42,0x100,"min %f, max %f",tmp42,(double)fVar2,(double)a);
  puts(tmp42);
  for (i = 0; column * row - i != 0 && i <= column * row; i = i + 1) {
    _Var1 = compare(a,(*matrix)[i]);
    if (!_Var1) {
      (*matrix)[i] = a;
    }
  }
  puts("normalized sweep result");
  dump_matrix_freq(*matrix,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
  return;
}

