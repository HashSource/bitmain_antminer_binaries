
void get_plldata_from_index(int index,uchar *vil_pll)

{
  _Bool _Var1;
  size_t sVar2;
  uchar *vil_pll_local;
  int index_local;
  char tmp42 [2048];
  char plldivider1 [32];
  
  plldivider1[0] = '\0';
  plldivider1[1] = '\0';
  plldivider1[2] = '\0';
  plldivider1[3] = '\0';
  plldivider1[4] = '\0';
  plldivider1[5] = '\0';
  plldivider1[6] = '\0';
  plldivider1[7] = '\0';
  plldivider1[8] = '\0';
  plldivider1[9] = '\0';
  plldivider1[10] = '\0';
  plldivider1[0xb] = '\0';
  plldivider1[0xc] = '\0';
  plldivider1[0xd] = '\0';
  plldivider1[0xe] = '\0';
  plldivider1[0xf] = '\0';
  plldivider1[0x10] = '\0';
  plldivider1[0x11] = '\0';
  plldivider1[0x12] = '\0';
  plldivider1[0x13] = '\0';
  plldivider1[0x14] = '\0';
  plldivider1[0x15] = '\0';
  plldivider1[0x16] = '\0';
  plldivider1[0x17] = '\0';
  plldivider1[0x18] = '\0';
  plldivider1[0x19] = '\0';
  plldivider1[0x1a] = '\0';
  plldivider1[0x1b] = '\0';
  plldivider1[0x1c] = '\0';
  plldivider1[0x1d] = '\0';
  plldivider1[0x1e] = '\0';
  plldivider1[0x1f] = '\0';
  if (0xb2 < (uint)index) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"freq set err",0xc);
      tmp42[0xc] = 'o';
      tmp42[0xd] = 'r';
      tmp42[0xe] = '\0';
      _applog(3,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  sprintf(plldivider1,"%08x",freq_pll_1393[index].vilpll);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"vil pll data:%s",plldivider1);
    _applog(5,tmp42,false);
  }
  sVar2 = strlen(plldivider1);
  _Var1 = hex2bin(vil_pll,plldivider1,sVar2 >> 1);
  if (!_Var1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"hex2bin failed in %s","get_plldata_from_index");
      _applog(4,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  return;
}

