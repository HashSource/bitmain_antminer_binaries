
void show_sweep_summary(float *matrix)

{
  float fVar1;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : online_case_time[%lld], end_case_time[%lld], validate_case_time[%lld]\n",
         "show_sweep_summary",(uint)g_rt.sweep.sweep_online_time - (uint)g_rt.sweep.sweep_start_time
         ,(g_rt.sweep.sweep_online_time._4_4_ - g_rt.sweep.sweep_start_time._4_4_) -
          (uint)((uint)g_rt.sweep.sweep_online_time < (uint)g_rt.sweep.sweep_start_time),
         (uint)g_rt.sweep.sweep_end_time - (uint)g_rt.sweep.sweep_start_time,
         (g_rt.sweep.sweep_end_time._4_4_ - g_rt.sweep.sweep_start_time._4_4_) -
         (uint)((uint)g_rt.sweep.sweep_end_time < (uint)g_rt.sweep.sweep_start_time),
         (uint)g_rt.sweep.sweep_end_time - (uint)g_rt.sweep.sweep_online_time,
         (g_rt.sweep.sweep_end_time._4_4_ - g_rt.sweep.sweep_online_time._4_4_) -
         (uint)((uint)g_rt.sweep.sweep_end_time < (uint)g_rt.sweep.sweep_online_time));
  snprintf(tmp1,0x100,"online_case_time[%lld], end_case_time[%lld], validate_case_time[%lld]",tmp1,
           (uint)g_rt.sweep.sweep_online_time - (uint)g_rt.sweep.sweep_start_time,
           (g_rt.sweep.sweep_online_time._4_4_ - g_rt.sweep.sweep_start_time._4_4_) -
           (uint)((uint)g_rt.sweep.sweep_online_time < (uint)g_rt.sweep.sweep_start_time),
           (uint)g_rt.sweep.sweep_end_time - (uint)g_rt.sweep.sweep_start_time,
           (g_rt.sweep.sweep_end_time._4_4_ - g_rt.sweep.sweep_start_time._4_4_) -
           (uint)((uint)g_rt.sweep.sweep_end_time < (uint)g_rt.sweep.sweep_start_time),
           (uint)g_rt.sweep.sweep_end_time - (uint)g_rt.sweep.sweep_online_time,
           (g_rt.sweep.sweep_end_time._4_4_ - g_rt.sweep.sweep_online_time._4_4_) -
           (uint)((uint)g_rt.sweep.sweep_end_time < (uint)g_rt.sweep.sweep_online_time));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix online freq min[%f]\n","show_sweep_summary",
         SUB84((double)g_rt.sweep.sweep_online_min,0),
         (int)((ulonglong)(double)g_rt.sweep.sweep_online_min >> 0x20));
  snprintf(tmp1,0x100,"matrix online freq min[%f]",tmp1,(double)g_rt.sweep.sweep_online_min);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix online freq max[%f]\n","show_sweep_summary",
         SUB84((double)g_rt.sweep.sweep_online_max,0),
         (int)((ulonglong)(double)g_rt.sweep.sweep_online_max >> 0x20));
  snprintf(tmp1,0x100,"matrix online freq max[%f]",tmp1,(double)g_rt.sweep.sweep_online_max);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix online freq avg[%f]\n","show_sweep_summary",
         SUB84((double)g_rt.sweep.sweep_online_avg,0),
         (int)((ulonglong)(double)g_rt.sweep.sweep_online_avg >> 0x20));
  snprintf(tmp1,0x100,"matrix online freq avg[%f]",tmp1,(double)g_rt.sweep.sweep_online_avg);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix online freq var[%f]\n","show_sweep_summary",
         SUB84((double)g_rt.sweep.sweep_online_var,0),
         (int)((ulonglong)(double)g_rt.sweep.sweep_online_var >> 0x20));
  snprintf(tmp1,0x100,"matrix online freq var[%f]",tmp1,(double)g_rt.sweep.sweep_online_var);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix online sweep to max freq board nonce rate [%f]\n","show_sweep_summary",
         SUB84((double)g_rt.sweep.sweep_online_nonce_rate,0),
         (int)((ulonglong)(double)g_rt.sweep.sweep_online_nonce_rate >> 0x20));
  snprintf(tmp1,0x100,"matrix online sweep to max freq board nonce rate [%f]",tmp1,
           (double)g_rt.sweep.sweep_online_nonce_rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  fVar1 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
  printf("%s : matrix freq min[%f]\n","show_sweep_summary",SUB84((double)fVar1,0),
         (int)((ulonglong)(double)fVar1 >> 0x20));
  fVar1 = get_freq_matrix_min(matrix,(g_rt.config)->asics);
  snprintf(tmp1,0x100,"matrix freq min[%f]",tmp1,(double)fVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  fVar1 = get_freq_matrix_max(matrix,(g_rt.config)->asics);
  printf("%s : matrix freq max[%f]\n","show_sweep_summary",SUB84((double)fVar1,0),
         (int)((ulonglong)(double)fVar1 >> 0x20));
  fVar1 = get_freq_matrix_max(matrix,(g_rt.config)->asics);
  snprintf(tmp1,0x100,"matrix freq max[%f]",tmp1,(double)fVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  fVar1 = get_avg_matrix(matrix,(g_rt.config)->asics);
  printf("%s : matrix freq avg[%f]\n","show_sweep_summary",SUB84((double)fVar1,0),
         (int)((ulonglong)(double)fVar1 >> 0x20));
  fVar1 = get_avg_matrix(matrix,(g_rt.config)->asics);
  snprintf(tmp1,0x100,"matrix freq avg[%f]",tmp1,(double)fVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  fVar1 = get_var_matrix(matrix,(g_rt.config)->asics);
  printf("%s : matrix freq var[%f]\n","show_sweep_summary",SUB84((double)fVar1,0),
         (int)((ulonglong)(double)fVar1 >> 0x20));
  fVar1 = get_var_matrix(matrix,(g_rt.config)->asics);
  snprintf(tmp1,0x100,"matrix freq var[%f]",tmp1,(double)fVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matrix sweep to max freq board nonce rate [%f]\n","show_sweep_summary",
         SUB84((double)g_rt.nonce_rate,0),(int)((ulonglong)(double)g_rt.nonce_rate >> 0x20));
  snprintf(tmp1,0x100,"matrix sweep to max freq board nonce rate [%f]",tmp1,(double)g_rt.nonce_rate)
  ;
  log_to_file(tmp1,time_stamp);
  return;
}

