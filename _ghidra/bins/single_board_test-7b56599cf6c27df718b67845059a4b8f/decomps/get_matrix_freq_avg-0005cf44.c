
float get_matrix_freq_avg(float *matrix)

{
  float *matrix_local;
  int j;
  int i;
  float avg;
  
  avg = 0.0;
  for (i = 0; i < (g_rt.config)->domains; i = i + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      avg = avg + matrix[j + i * (g_rt.config)->asics_in_domain];
    }
  }
  return avg / (float)(longlong)((g_rt.config)->asics_in_domain * (g_rt.config)->domains);
}

