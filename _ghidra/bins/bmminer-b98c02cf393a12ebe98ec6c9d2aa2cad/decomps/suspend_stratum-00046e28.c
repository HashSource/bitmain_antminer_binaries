
void suspend_stratum(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  char acStack_818 [2052];
  
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xb0));
  }
  else {
    snprintf(acStack_818,0x800,"Closing socket for stratum pool %d",*param_1);
    _applog(6,acStack_818,0);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xb0));
  }
  if (iVar1 == 0) {
    __suspend_stratum(param_1);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xb0));
  }
  else {
    piVar2 = __errno_location();
    snprintf(acStack_818,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"util.c",
             "suspend_stratum",0xc0f);
    _applog(3,acStack_818,1);
    _quit(1);
    __suspend_stratum(param_1);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xb0));
  }
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_818,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"util.c",
             "suspend_stratum",0xc11);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  (*selective_yield)();
  return;
}

