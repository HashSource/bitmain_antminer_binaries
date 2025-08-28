
void * quit_thread(void *userdata)

{
  void *userdata_local;
  char tmp42 [2048];
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","quit_thread",0x133d);
  _mutex_unlock(&quit_restart_lock,"api-btm.c","quit_thread",0x133e);
  if (((opt_debug != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    builtin_strncpy(tmp42,"API: killing cgminer",0x14);
    tmp42[0x14] = '\0';
    _applog(7,tmp42,false);
  }
  kill_work();
  return (void *)0x0;
}

