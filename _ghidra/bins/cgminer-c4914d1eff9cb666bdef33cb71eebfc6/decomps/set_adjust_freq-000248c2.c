
/* WARNING: Unknown calling convention */

float set_adjust_freq(void)

{
  float low_freq_00;
  float high_freq_00;
  float high_freq;
  float low_freq;
  float max_freq;
  
  low_freq_00 = screen_freq_from_array(freq_adjust_index[0],false);
  high_freq_00 = screen_freq_from_array(freq_adjust_index[0],true);
  increase_freq_slowly_by_index(init_freq,low_freq_00,high_freq_00);
  return high_freq_00;
}

