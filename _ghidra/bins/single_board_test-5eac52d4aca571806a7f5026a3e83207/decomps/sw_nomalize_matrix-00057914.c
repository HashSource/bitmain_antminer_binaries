
void sw_nomalize_matrix(float **matrix,int row,int column)

{
  _Bool _Var1;
  float fVar2;
  float a;
  int column_local;
  int row_local;
  float **matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  float test [110];
  int vol;
  float totalfreq;
  float total;
  float max;
  float min;
  int i_1;
  int i;
  
  memcpy(test,&DAT_001f24bc,0x1b8);
  fVar2 = get_freq_matrix_min(*matrix,column * row);
  a = (g_rt.sweep.bias + 1.0) * fVar2;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : min %f, max %f\n","sw_nomalize_matrix",SUB84((double)fVar2,0),
         (int)((ulonglong)(double)fVar2 >> 0x20),(double)a);
  snprintf(tmp1,0x100,"min %f, max %f",tmp1,(double)fVar2,(double)a);
  log_to_file(tmp1,time_stamp);
  for (i = 0; column * row - i != 0 && i <= column * row; i = i + 1) {
    _Var1 = compare(a,(*matrix)[i]);
    if (!_Var1) {
      (*matrix)[i] = a;
    }
  }
  for (i_1 = 0; column * row - i_1 != 0 && i_1 <= column * row; i_1 = i_1 + 1) {
    (*matrix)[i_1] = (*matrix)[i_1] - (float)(longlong)(g_rt.config)->freq_flex;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : fix freq by freq_flex,flex:%d\n","sw_nomalize_matrix",(g_rt.config)->freq_flex);
  snprintf(tmp1,0x100,"fix freq by freq_flex,flex:%d",(g_rt.config)->freq_flex);
  log_to_file(tmp1,time_stamp);
  dump_matrix_freq(*matrix,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
  return;
}

