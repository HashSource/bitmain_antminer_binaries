
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void signal_work_update(void)

{
  char tmp42 [2048];
  int i;
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    builtin_strncpy(tmp42,"Work update message received",0x1c);
    tmp42[0x1c] = '\0';
    _applog(6,tmp42,false);
  }
  cgtime(&update_tv_start);
  _rd_lock(&mining_thr_lock,"cgminer.c","signal_work_update",0x1568);
  for (i = 0; i < mining_threads; i = i + 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800," %s set work_update true","signal_work_update");
      _applog(5,tmp42,false);
    }
    mining_thr[i]->work_update = true;
  }
  _rd_unlock(&mining_thr_lock,"cgminer.c","signal_work_update",0x1570);
  return;
}

