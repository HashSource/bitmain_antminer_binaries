
void matrix_add(float *matrix,float add)

{
  float add_local;
  float *matrix_local;
  float avg;
  int j;
  int i;
  
  for (i = 0; i < (g_rt.config)->domains; i = i + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      matrix[j + i * (g_rt.config)->asics_in_domain] =
           matrix[j + i * (g_rt.config)->asics_in_domain] + add;
    }
  }
  return;
}

