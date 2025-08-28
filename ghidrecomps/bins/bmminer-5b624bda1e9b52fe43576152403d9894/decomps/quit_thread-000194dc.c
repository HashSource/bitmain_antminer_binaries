
/* WARNING: Unknown calling convention */

void * quit_thread(void *userdata)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"quit_thread",(char *)0x1355,func,line);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&quit_restart_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"quit_thread",(char *)0x1356,func_00,line_00);
  }
  (*selective_yield)();
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"API: killing bmminer",0x14);
    tmp42[0x14] = '\0';
    _applog(7,tmp42,false);
  }
  kill_work();
  return (void *)0x0;
}

