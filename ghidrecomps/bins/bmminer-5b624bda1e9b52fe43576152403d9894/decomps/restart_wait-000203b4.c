
/* WARNING: Unknown calling convention */

int restart_wait(thr_info *thr,uint mstime)

{
  int iVar1;
  int iVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  timeval now;
  timespec abstime;
  
  cgtime(&now);
  abstime.tv_sec = mstime / 1000 + now.tv_sec;
  iVar2 = (mstime / 1000) * -1000000 + mstime * 1000 + now.tv_usec;
  if (999999 < iVar2) {
    abstime.tv_sec = abstime.tv_sec + 1;
    iVar2 = iVar2 + -1000000;
  }
  abstime.tv_nsec = iVar2 * 1000;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&restart_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"restart_wait",(char *)0x14c9,func,line);
  }
  iVar2 = 0;
  if (thr->work_restart == false) {
    iVar2 = pthread_cond_timedwait
                      ((pthread_cond_t *)&restart_cond,(pthread_mutex_t *)&restart_lock,
                       (timespec *)&abstime);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&restart_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"restart_wait",(char *)0x14d3,func_00,line_00);
  }
  (*selective_yield)();
  return iVar2;
}

