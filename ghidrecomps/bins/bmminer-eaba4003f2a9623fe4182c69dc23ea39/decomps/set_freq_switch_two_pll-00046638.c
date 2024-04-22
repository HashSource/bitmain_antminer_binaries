
void set_freq_switch_two_pll(float freq,float nextfreq)

{
  uchar chain_00;
  float nextfreq_local;
  float freq_local;
  char tmp42 [2048];
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"\n\nset_freq_switch_two_pll  curr freq %.2fM , next %.2fM\n",tmp42,
             (double)freq,(double)nextfreq);
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      chain_00 = (uchar)chain;
      if (set_freq_switch_two_pll::current_pll[chain] == 0) {
        set_freq_switch_two_pll::current_pll[chain] = 1;
        change_high_pll_by_pll_no(chain_00,freq,0);
        change_high_pll_by_pll_no(chain_00,nextfreq,1);
        set_core_clock_sel(chain_00,'\0');
      }
      else if (set_freq_switch_two_pll::current_pll[chain] == 1) {
        set_freq_switch_two_pll::current_pll[chain] = 2;
        set_core_clock_sel(chain_00,'\x04');
        change_high_pll_by_pll_no(chain_00,nextfreq,0);
      }
      else if (set_freq_switch_two_pll::current_pll[chain] == 2) {
        set_freq_switch_two_pll::current_pll[chain] = 1;
        set_core_clock_sel(chain_00,'\0');
        change_high_pll_by_pll_no(chain_00,nextfreq,1);
      }
    }
  }
  return;
}

