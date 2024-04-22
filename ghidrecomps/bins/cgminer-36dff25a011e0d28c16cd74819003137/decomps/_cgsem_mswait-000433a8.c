
int _cgsem_mswait(cgsem_t *cgsem,int ms,char *file,char *func,int line)

{
  _Bool _Var1;
  int iVar2;
  int *piVar3;
  undefined4 in_stack_fffff7b8;
  undefined4 in_stack_fffff7bc;
  char *func_local;
  char *file_local;
  int ms_local;
  cgsem_t *cgsem_local;
  char tmp42 [2048];
  timeval tv_now;
  timespec ts_now;
  timespec abs_timeout;
  int ret;
  
  cgtime(&tv_now);
  timeval_to_spec(&ts_now,&tv_now);
  ms_to_timespec(&abs_timeout,CONCAT44(in_stack_fffff7bc,in_stack_fffff7b8));
  while( true ) {
    timeraddspec(&abs_timeout,&ts_now);
    iVar2 = sem_timedwait((sem_t *)cgsem,(timespec *)&abs_timeout);
    if (iVar2 == 0) {
      return 0;
    }
    _Var1 = sock_timeout();
    if (_Var1) break;
    _Var1 = interrupted();
    if (!_Var1) {
      piVar3 = __errno_location();
      snprintf(tmp42,0x800,"Failed to sem_timedwait errno=%d cgsem=0x%p in %s %s():%d",*piVar3,cgsem
               ,file,func,line);
      _applog(3,tmp42,true);
      _quit(1);
      return 0;
    }
  }
  return 0x6e;
}

