
void _mutex_lock_constprop_4(void)

{
  int iVar1;
  int *piVar2;
  char acStack_808 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)console_lock);
  if (iVar1 == 0) {
    return;
  }
  piVar2 = __errno_location();
  snprintf(acStack_808,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"logging.c",
           "my_log_curses",0x34);
  _applog(3,acStack_808,1);
  _quit(1);
  return;
}

