
void set_frequency(undefined4 param_1)

{
  char acStack_418 [1024];
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  get_plldata(param_1,&local_10);
  local_18 = 0;
  local_17 = 1;
  local_16 = 0xc;
  local_14 = local_10;
  g_pll_parameter = local_10;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"%s %d, pll %08x\n","set_frequency",param_1,local_10);
      _applog(2,acStack_418,0);
    }
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),1,&local_18);
  }
  return;
}

