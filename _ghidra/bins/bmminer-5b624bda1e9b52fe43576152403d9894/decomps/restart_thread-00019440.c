
/* WARNING: Unknown calling convention */

void * restart_thread(void *userdata)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"restart_thread",(char *)0x1363,func,line);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"restart_thread",(char *)0x1364,func_00,line_00);
  }
  (*selective_yield)();
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"API: restarting bmminer",0x18);
    _applog(7,tmp42,false);
  }
  app_restart();
  return (void *)0x0;
}

