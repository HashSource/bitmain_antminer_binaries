
undefined4
_cgsem_mswait(sem_t *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  timespec local_838;
  timeval local_830;
  char acStack_828 [2052];
  
  gettimeofday(&local_830,(__timezone_ptr_t)0x0);
  ms_to_timespec(&local_838,local_830.tv_usec,param_2,param_2 >> 0x1f);
  do {
    iVar3 = local_838.tv_nsec + local_830.tv_usec * 1000;
    iVar2 = local_838.tv_sec + local_830.tv_sec;
    local_838.tv_nsec = iVar3;
    local_838.tv_sec = iVar2;
    if (iVar3 < 1000000000) {
      for (; local_838.tv_nsec < 0; local_838.tv_nsec = local_838.tv_nsec + 1000000000) {
        local_838.tv_sec = local_838.tv_sec + -1;
      }
    }
    else {
      local_838.tv_nsec = iVar3 + -1000000000;
      local_838.tv_sec = iVar2 + 1;
      if (999999999 < local_838.tv_nsec) {
        local_838.tv_nsec = iVar3 + -2000000000;
        local_838.tv_sec = iVar2 + 2;
      }
    }
    iVar2 = sem_timedwait(param_1,&local_838);
    if (iVar2 == 0) {
      return 0;
    }
    piVar1 = __errno_location();
    iVar2 = *piVar1;
    if (iVar2 == 0x6e) {
      return 0x6e;
    }
  } while (iVar2 == 4);
  snprintf(acStack_828,0x800,"Failed to sem_timedwait errno=%d cgsem=0x%p in %s %s():%d",iVar2,
           param_1,param_3,param_4,param_5);
  _applog(3,acStack_828,1);
  _quit(1);
  return 0;
}

