
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void get_plldata_from_index(int index,uint8_t *vil_pll)

{
  _Bool _Var1;
  size_t sVar2;
  uint8_t *vil_pll_local;
  int index_local;
  char tmp42 [2048];
  char plldivider1 [32];
  
  memset(plldivider1,0,0x20);
  if (0xb2 < (uint)index) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      tmp42[0] = s_freq_set_error_0009a704[0];
      tmp42[1] = s_freq_set_error_0009a704[1];
      tmp42[2] = s_freq_set_error_0009a704[2];
      tmp42[3] = s_freq_set_error_0009a704[3];
      tmp42[4] = s_freq_set_error_0009a704[4];
      tmp42[5] = s_freq_set_error_0009a704[5];
      tmp42[6] = s_freq_set_error_0009a704[6];
      tmp42[7] = s_freq_set_error_0009a704[7];
      tmp42[8] = s_freq_set_error_0009a704[8];
      tmp42[9] = s_freq_set_error_0009a704[9];
      tmp42[10] = s_freq_set_error_0009a704[10];
      tmp42[11] = s_freq_set_error_0009a704[11];
      tmp42._12_2_ = (undefined2)ram0x0009a710;
      tmp42[14] = (char)((uint)ram0x0009a710 >> 0x10);
      _applog(3,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  sprintf(plldivider1,"%08x",freq_pll_1391[index].vilpll);
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

