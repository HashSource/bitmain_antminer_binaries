
undefined4 restart_thread(void)

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
             "restart_thread",0x13a8);
    _applog(3,local_810,1);
    _quit(1);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
  }
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_810,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,"api.c",
             "restart_thread",0x13a9);
    _applog(3,local_810,1);
    _quit(1);
  }
  (*selective_yield)();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_810,"API: restarting bmminer",0x18);
    _applog(7,local_810,0);
    app_restart();
    return 0;
  }
  app_restart();
  return 0;
}

