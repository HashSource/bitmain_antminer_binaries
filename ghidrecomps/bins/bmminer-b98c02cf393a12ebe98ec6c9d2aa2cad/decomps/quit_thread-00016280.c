
undefined4 quit_thread(void)

{
  int iVar1;
  int *piVar2;
  char local_810 [2052];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)quit_restart_lock);
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_810,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
             "quit_thread",0x139a);
    _applog(3,local_810,1);
    _quit(1);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
  }
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_810,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
             "quit_thread",0x139b);
    _applog(3,local_810,1);
    _quit(1);
  }
  (*selective_yield)();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_810,"API: killing bmminer",0x14);
    local_810[0x14] = 0;
    _applog(7,local_810,0);
    kill_work();
    return 0;
  }
  kill_work();
  return 0;
}

