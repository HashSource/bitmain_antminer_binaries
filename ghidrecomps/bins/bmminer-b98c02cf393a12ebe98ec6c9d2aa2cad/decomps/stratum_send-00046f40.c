
bool stratum_send(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  pthread_mutex_t *__mutex;
  char local_818 [28];
  undefined4 uStack_7fc;
  char local_7f8 [16];
  undefined2 local_7e8;
  
  if ((opt_protocol != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))) {
    snprintf(local_818,0x800,"SEND: %s",param_2);
    _applog(5,local_818,0);
  }
  __mutex = (pthread_mutex_t *)(param_1 + 0xb0);
  iVar2 = pthread_mutex_lock(__mutex);
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf(local_818,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,"util.c",
             "stratum_send",0x698);
    _applog(3,local_818,1);
    _quit(1);
  }
  if (*(char *)((int)param_1 + 0x281) == '\0') {
    iVar4 = 3;
    iVar2 = pthread_mutex_unlock(__mutex);
    if (iVar2 == 0) {
      (*selective_yield)();
      goto LAB_00046ffe;
    }
LAB_00046fb4:
    piVar3 = __errno_location();
    snprintf(local_818,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,"util.c",
             "stratum_send",0x69e);
    _applog(3,local_818,1);
    _quit(1);
  }
  else {
    iVar4 = __stratum_send(param_1,param_2,param_3);
    iVar2 = pthread_mutex_unlock(__mutex);
    if (iVar2 != 0) goto LAB_00046fb4;
  }
  (*selective_yield)();
  if (iVar4 == 2) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_818,"Failed to send in stratum_se",0x1c);
      uStack_7fc = CONCAT13(uStack_7fc._3_1_,0x646e);
      _applog(7,local_818,0);
      suspend_stratum(param_1);
      return false;
    }
  }
  else {
    if (iVar4 == 3) {
LAB_00046ffe:
      cVar1 = opt_debug;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (cVar1 = '\0', 6 < opt_log_level))))
      {
        builtin_strncpy(local_818,"Stratum send failed due to n",0x1c);
        uStack_7fc._0_1_ = 'o';
        uStack_7fc._1_1_ = ' ';
        uStack_7fc._2_1_ = 'p';
        uStack_7fc._3_1_ = 'o';
        builtin_strncpy(local_7f8,"ol stratum_activ",0x10);
        local_7e8 = 0x65;
        _applog(7,local_818,0);
        cVar1 = '\0';
      }
      return (bool)cVar1;
    }
    if (iVar4 != 1) {
      return iVar4 == 0;
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_818,0x800,"Write select failed on pool %d sock",*param_1);
      _applog(7,local_818,0);
    }
  }
  suspend_stratum(param_1);
  return false;
}

