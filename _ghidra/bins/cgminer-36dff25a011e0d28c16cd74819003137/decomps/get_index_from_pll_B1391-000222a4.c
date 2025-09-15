
int get_index_from_pll_B1391(int pll)

{
  int pll_local;
  char tmp42 [2048];
  int i;
  
  for (i = 0; ((uint)i < 0xb3 && (pll != freq_pll_1391[i].freq)); i = i + 1) {
  }
  if (i == 0xb3) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"freq index set error,return default pll inde",0x2c);
      tmp42[0x2c] = 'x';
      tmp42[0x2d] = '\0';
      _applog(3,tmp42,false);
    }
    i = get_index_from_pll_B1391(200);
  }
  return i;
}

