
void inc_freq_online_pll(float *curr_matrix,float *last_matrix,int len)

{
  uint32_t timeout;
  float fVar1;
  int len_local;
  float *last_matrix_local;
  float *curr_matrix_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t Timeout;
  int PLL_2;
  int PLL_0;
  int pll_use;
  
  if (inc_freq_online_pll::curr_pll == 0) {
    pll_use = 2;
  }
  else {
    pll_use = 0;
  }
  inc_freq_with_target(curr_matrix,last_matrix,len,pll_use);
  usleep(300000);
  set_chain_clock_select_control((uint8_t)(g_rt.config)->chain,'\0',(uint8_t)pll_use);
  usleep(100000);
  inc_freq_online_pll::curr_pll = pll_use;
  if ((g_rt.config)->is_super != true) {
    fVar1 = get_freq_matrix_min(curr_matrix,(g_rt.config)->asics);
    timeout = __aeabi_uidiv(0x1ffff,(uint)(0.0 < fVar1) * (int)fVar1);
    dhash_set_timeout(timeout);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set timeout by real freq: %d\n","inc_freq_online_pll",timeout);
    snprintf(tmp1,0x800,"Set timeout by real freq: %d",timeout);
    log_to_file(tmp1,time_stamp);
    usleep(5000);
  }
  return;
}

