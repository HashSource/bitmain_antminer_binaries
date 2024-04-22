
undefined4 test_pool_thread(int *param_1)

{
  int iVar1;
  int iVar2;
  pthread_t __th;
  int *piVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  char acStack_810 [2052];
  
  if (*(char *)((int)param_1 + 0x6b) == '\0') {
    __th = pthread_self();
    pthread_detach(__th);
  }
  while( true ) {
    if (*(char *)((int)param_1 + 0x69) != '\0') {
      return 0;
    }
    iVar1 = pool_active(param_1,0);
    if (iVar1 != 0) break;
    pool_died(param_1);
    if (*(char *)((int)param_1 + 0x6b) != '\0') {
LAB_00023118:
      *(undefined *)(param_1 + 0x47) = 0;
      return 0;
    }
    sleep(0x1e);
  }
  pool_tclear(param_1,(int)param_1 + 0x61);
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)control_lock);
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_wrlock(DAT_000231e0);
    uVar4 = DAT_000231e4;
    if (iVar1 == 0) {
      iVar1 = 0;
      if (pools_active == '\0') {
        iVar1 = *param_1;
        pools_active = '\x01';
        currentpool = param_1;
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
      iVar2 = pthread_rwlock_unlock(DAT_000231e0);
      uVar4 = DAT_000231e4;
      if (iVar2 == 0) {
        iVar2 = pthread_mutex_unlock((pthread_mutex_t *)control_lock);
        uVar4 = DAT_000231e4;
        if (iVar2 == 0) {
          (*selective_yield)();
          if ((iVar1 != 0) &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))) {
            snprintf(acStack_810,0x800,"Switching to pool %d %s - first alive pool",*param_1,
                     param_1[0x29]);
            _applog(5,acStack_810,0);
          }
          pool_resus(param_1);
          switch_pools(0);
          goto LAB_00023118;
        }
        piVar3 = __errno_location();
        iVar1 = *piVar3;
        __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar5 = 0x29b4;
      }
      else {
        piVar3 = __errno_location();
        iVar1 = *piVar3;
        __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar5 = 0x29b4;
      }
    }
    else {
      piVar3 = __errno_location();
      iVar1 = *piVar3;
      __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar5 = 0x29a6;
    }
  }
  else {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar5 = 0x29a6;
    uVar4 = DAT_000231e4;
  }
  snprintf(acStack_810,0x800,__format,iVar1,"cgminer.c",uVar4,uVar5);
  _applog(3,acStack_810,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

