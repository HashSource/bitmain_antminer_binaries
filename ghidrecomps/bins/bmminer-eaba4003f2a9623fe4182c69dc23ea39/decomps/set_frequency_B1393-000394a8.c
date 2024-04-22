
void set_frequency_B1393(uint freq)

{
  int iVar1;
  uint freq_local;
  char tmp42 [2048];
  char logstr [1024];
  uint cmd_buf [3];
  uchar buf [9];
  int divider;
  uint reg_data_vil;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  int step_down;
  int max_freq_index;
  int i;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"\n--- %s\n","set_frequency_B1393");
    _applog(5,tmp42,false);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"begin to set frequency, chain %d, freq %d\n",i,
                 freq_pll_1393[freq_one_board[i]].freq);
        _applog(5,tmp42,false);
      }
      iVar1 = set_frequency_with_addr(freq_pll_1393[freq_one_board[i]].freq,'\x01','\0',(uchar)i);
      usleep(500);
      set_divider(iVar1 - 1,i,1,'\0');
      usleep(500);
      set_frequency_with_addr(freq_pll_1393[freq_one_board[i]].freq,'\x01','\0',(uchar)i);
      usleep(500);
    }
  }
  return;
}

