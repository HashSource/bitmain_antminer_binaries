
undefined4 bm1740_ioctl_regtable(int param_1,int param_2)

{
  char acStack_110 [256];
  int local_10;
  int local_c;
  
  if (param_1 == 0) {
    local_c = param_2;
    bm1740_get_reg_table(*(undefined *)(param_2 + 2),param_2 + 4);
  }
  else {
    if (param_1 != 1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
        snprintf(acStack_110,0x100,"%s failed\n","bm1740_ioctl_regtable");
        _applog(1,acStack_110,0);
      }
      return 1;
    }
    local_10 = param_2;
    bm1740_set_reg_table(*(undefined *)(param_2 + 2),*(undefined4 *)(param_2 + 4));
  }
  return 0;
}

