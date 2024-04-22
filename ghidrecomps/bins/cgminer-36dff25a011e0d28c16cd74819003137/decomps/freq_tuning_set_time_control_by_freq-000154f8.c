
void freq_tuning_set_time_control_by_freq(int freq)

{
  int freq_local;
  
  set_timeout(freq,0x41);
  return;
}

