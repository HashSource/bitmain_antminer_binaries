
void _mutex_unlock_noyield_constprop_3(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  char acStack_810 [2052];
  
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)console_lock);
  if (iVar1 == 0) {
    return;
  }
  piVar2 = __errno_location();
  snprintf(acStack_810,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"logging.c"
           ,"my_log_curses",param_1);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

