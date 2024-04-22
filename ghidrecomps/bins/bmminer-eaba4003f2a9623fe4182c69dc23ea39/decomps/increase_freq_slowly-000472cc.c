
void increase_freq_slowly(float init_freq,float final_freq,float freq_step)

{
  float freq_step_local;
  float final_freq_local;
  float init_freq_local;
  char tmp42 [2048];
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
      snprintf(tmp42,0x800,"\n\nIncrease frequency to %.2fM\n",tmp42,(double)freq_tmp);
      _applog(5,tmp42,false);
    }
    set_freq_yf(freq_tmp);
    sleep(2);
  }
  return;
}

