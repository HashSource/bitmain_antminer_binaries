
void * restart_thread(void *userdata)

{
  void *userdata_local;
  char tmp42 [2048];
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","restart_thread",0x134d);
  _mutex_unlock(&quit_restart_lock,"api-btm.c","restart_thread",0x134e);
  if (((opt_debug != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    builtin_strncpy(tmp42,"API: restarting cgminer",0x18);
    _applog(7,tmp42,false);
  }
  app_restart();
  return (void *)0x0;
}

