
int get_index_from_high_pll(int freq)

{
  int freq_local;
  char tmp42 [2048];
  int i;
  
  i = 0;
  while ((((uint)i < 0x21 && (freq_high_pll_1393[i].freq != freq)) &&
         ((freq_high_pll_1393[i].freq <= (uint)freq ||
          ((uint)freq <= freq_high_pll_1393[i + -1].freq))))) {
    i = i + 1;
  }
  if (i == 0x21) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"high freq index set error,return default pll ind",0x30);
      tmp42[0x30] = 'e';
      tmp42[0x31] = 'x';
      tmp42[0x32] = '\0';
      _applog(3,tmp42,false);
    }
    i = get_index_from_high_pll(200);
  }
  return i;
}

