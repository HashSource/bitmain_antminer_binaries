
int sweep_online_mode(float *curr_matrix,float *last_matrix,float freq,int *trytime,_Bool reinit,
                     uint8_t *state)

{
  int iVar1;
  _Bool reinit_local;
  int *trytime_local;
  float freq_local;
  float *last_matrix_local;
  float *curr_matrix_local;
  char tmp42 [256];
  
  if (reinit) {
    snprintf(tmp42,0x100,"pt_before_send_nonce=================== freq:%f, range[0]:%f trytime:%d",
             *trytime,(double)freq,(double)g_rt.sweep.range_freq[0],*trytime);
    puts(tmp42);
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
  pt_send_nonce(curr_matrix,last_matrix,freq,state);
  return 0;
}

