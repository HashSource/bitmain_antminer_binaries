
/* WARNING: Unknown calling convention */

int restart_wait(thr_info *thr,uint mstime)

{
  int iVar1;
  timespec *__abstime;
  int line;
  uint line_00;
  int rc;
  timeval now;
  timespec abstime;
  
  cgtime(&now);
  __abstime = (timespec *)0xfff0bdc0;
  abstime.tv_sec = mstime / 1000 + now.tv_sec;
  iVar1 = (mstime / 1000) * -1000000 + mstime * 1000 + now.tv_usec;
  line = 1000;
  if (999999 < iVar1) {
    abstime.tv_sec = abstime.tv_sec + 1;
    iVar1 = iVar1 + -1000000;
  }
  abstime.tv_nsec = iVar1 * 1000;
  iVar1 = pthread_mutex_lock(DAT_00020458);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00020464,(char *)0x14c9,(char *)__abstime,line);
  }
  line_00 = (uint)thr->work_restart;
  rc = 0;
  if (line_00 == 0) {
    __abstime = (timespec *)&abstime;
    rc = pthread_cond_timedwait(DAT_0002045c,DAT_00020458,__abstime);
  }
  iVar1 = pthread_mutex_unlock(DAT_00020458);
  if (iVar1 != 0) {
    _mutex_unlock_noyield(DAT_00020464,(char *)0x14d3,(char *)__abstime,line_00);
  }
  (**DAT_00020460)();
  return rc;
}

