
void increase_freq_slowly_chain(int chainid,float init_freq,float final_freq,float freq_step)

{
  int index;
  float freq_step_local;
  float final_freq_local;
  float init_freq_local;
  int chainid_local;
  char tmp42 [2048];
  int local_pll_index;
  float freq_tmp;
  int steps;
  int i;
  
  steps = (int)((final_freq - init_freq) / freq_step);
  if ((int)((uint)((float)(longlong)steps * freq_step + init_freq < final_freq) << 0x1f) < 0) {
    steps = steps + 1;
  }
  for (i = 0; i < steps; i = i + 1) {
    freq_tmp = (float)(longlong)(i + 1) * freq_step + init_freq;
    if (freq_tmp != final_freq && freq_tmp < final_freq == (NAN(freq_tmp) || NAN(final_freq))) {
      freq_tmp = final_freq;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"\n\nIncrease CHAIN[%d] frequency to %.2fM\n",chainid,(double)freq_tmp);
      _applog(5,tmp42,false);
    }
    index = get_index_from_high_pll_yf((int)freq_tmp);
    change_high_pll_test((uchar)chainid,freq_tmp,index);
    sleep(2);
  }
  return;
}

