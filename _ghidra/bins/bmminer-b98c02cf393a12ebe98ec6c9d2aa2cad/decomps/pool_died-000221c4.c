
void pool_died(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char acStack_808 [2048];
  
  iVar1 = pool_tset(param_1,(int)param_1 + 0x61);
  if (iVar1 == 0) {
    cgtime(param_1 + 0x22);
    puVar2 = (undefined4 *)current_pool();
    if (param_1 == puVar2) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_808,0x800,"Pool %d %s not responding!",*param_1,param_1[0x29]);
        _applog(4,acStack_808,0);
      }
      switch_pools(0);
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf(acStack_808,0x800,"Pool %d %s failed to return work",*param_1,param_1[0x29]);
      _applog(6,acStack_808,0);
      return;
    }
  }
  return;
}

