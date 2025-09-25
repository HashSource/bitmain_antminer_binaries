
int sweep_online_mode(float *last_matrix,float freq,int *trytime,_Bool reinit,uint8_t *state)

{
  int iVar1;
  uint8_t *state_local;
  _Bool reinit_local;
  int *trytime_local;
  float freq_local;
  float *last_matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  
  if ((g_rt.sweep.range_freq[0] == freq) || (reinit)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pt_before_send_nonce=================== freq:%f, range[0]:%f trytime:%d\n",
           "sweep_online_mode",SUB84((double)freq,0),(int)((ulonglong)(double)freq >> 0x20),
           (double)g_rt.sweep.range_freq[0],*trytime);
    snprintf(tmp1,0x100,"pt_before_send_nonce=================== freq:%f, range[0]:%f trytime:%d",
             *trytime,(double)freq,(double)g_rt.sweep.range_freq[0],*trytime);
    log_to_file(tmp1,time_stamp);
    if (*trytime == 2) {
      *trytime = *trytime + 1;
    }
    iVar1 = pt_before_send_nonce(last_matrix);
    if (iVar1 != 0) {
      stop_threads();
      power_down_and_fan((g_rt.config)->chain);
      return -1;
    }
  }
  pt_send_nonce(last_matrix,freq,state);
  return 0;
}

