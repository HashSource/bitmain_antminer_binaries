
void pool_resus(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char acStack_810 [2052];
  
  iVar1 = pool_strategy;
  param_1[7] = 0;
  if ((iVar1 == 0) && (iVar2 = param_1[1], iVar1 = cp_prio(), iVar2 < iVar1)) {
    if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
      snprintf(acStack_810,0x800,"Pool %d %s alive, testing stability",*param_1,param_1[0x29]);
      _applog(4,acStack_810,0);
      return;
    }
  }
  else {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return;
    }
    snprintf(acStack_810,0x800,"Pool %d %s alive",*param_1,param_1[0x29]);
    _applog(6,acStack_810,0);
  }
  return;
}

