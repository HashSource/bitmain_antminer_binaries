
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void app_restart(void)

{
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Attempting to restart %s",packagename);
    _applog(4,tmp42,false);
  }
  cg_completion_timeout(__kill_work,(void *)0x0,5000);
  clean_up(true);
  if (0 < forkpid) {
    kill(forkpid,0xf);
    forkpid = 0;
  }
  execv(*initial_args,initial_args);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    builtin_strncpy(tmp42,"Failed to restart applicatio",0x1c);
    tmp42[0x1c] = 'n';
    tmp42[0x1d] = '\0';
    _applog(4,tmp42,false);
  }
  return;
}

