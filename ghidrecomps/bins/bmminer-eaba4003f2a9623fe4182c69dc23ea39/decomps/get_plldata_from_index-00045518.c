
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  plldivider1[11] = '\0';
  plldivider1[12] = '\0';
  plldivider1[13] = '\0';
  plldivider1[14] = '\0';
  plldivider1[15] = '\0';
  plldivider1[16] = '\0';
  plldivider1[17] = '\0';
  plldivider1[18] = '\0';
  plldivider1[19] = '\0';
  plldivider1[20] = '\0';
  plldivider1[21] = '\0';
  plldivider1[22] = '\0';
  plldivider1[23] = '\0';
  plldivider1[24] = '\0';
  plldivider1[25] = '\0';
  plldivider1[26] = '\0';
  plldivider1[27] = '\0';
  plldivider1[28] = '\0';
  plldivider1[29] = '\0';
  plldivider1[30] = '\0';
  plldivider1[31] = '\0';
  if (0xb2 < (uint)index) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      tmp42._0_4_ = s_freq_set_error_00077eb0._0_4_;
      tmp42._4_4_ = s_freq_set_error_00077eb0._4_4_;
      tmp42._8_4_ = s_freq_set_error_00077eb0._8_4_;
      tmp42._12_2_ = (undefined2)ram0x00077ebc;
      tmp42[14] = (char)((uint)ram0x00077ebc >> 0x10);
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

