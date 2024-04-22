
void inc_hw_errors_with_diff(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  char acStack_818 [2052];
  
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  }
  else {
    snprintf(acStack_818,0x800,"%s%d: invalid nonce - HW error",
             *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 4) + 8),
             *(undefined4 *)(*(int *)(param_1 + 0x24) + 8));
    _applog(3,acStack_818,0);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
  }
  if (iVar1 == 0) {
    hw_errors = hw_errors + param_2;
    *(int *)(*(int *)(param_1 + 0x24) + 0x2c) = param_2 + *(int *)(*(int *)(param_1 + 0x24) + 0x2c);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
    uVar3 = DAT_0002167c;
    if (iVar1 == 0) {
      (*selective_yield)();
      (**(code **)(*(int *)(*(int *)(param_1 + 0x24) + 4) + 0x54))(param_1);
      return;
    }
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar4 = 0x21eb;
  }
  else {
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar4 = 0x21e8;
    uVar3 = DAT_0002167c;
  }
  snprintf(acStack_818,0x800,__format,iVar1,"cgminer.c",uVar3,uVar4);
  _applog(3,acStack_818,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

