
/* WARNING: Unknown calling convention */

int _cgsem_mswait(cgsem_t *cgsem,int ms,char *file,char *func,int line)

{
  int iVar1;
  int ret;
  int *piVar2;
  undefined4 in_stack_fffff7c0;
  undefined4 in_stack_fffff7c4;
  timespec abs_timeout;
  timespec ts_now;
  timeval tv_now;
  char tmp42 [2048];
  
  cgtime(&tv_now);
  ts_now.tv_nsec = tv_now.tv_usec * 1000;
  ts_now.tv_sec = tv_now.tv_sec;
  ms_to_timespec(&abs_timeout,CONCAT44(in_stack_fffff7c4,in_stack_fffff7c0));
  while( true ) {
    timeraddspec(&abs_timeout,&ts_now);
    iVar1 = sem_timedwait((sem_t *)cgsem,(timespec *)&abs_timeout);
    if (iVar1 == 0) {
      return 0;
    }
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    if (iVar1 == 0x6e) break;
    if (iVar1 != 4) {
      snprintf(tmp42,0x800,DAT_000125d8,iVar1,cgsem,file,func,line);
      _applog(3,tmp42,true);
      _quit(1);
      return 0;
    }
  }
  return 0x6e;
}

