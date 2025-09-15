
void app_restart(void)

{
  char local_810 [28];
  undefined2 local_7f4;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf(local_810,0x800,"Attempting to restart %s",packagename);
    _applog(4,local_810,0);
  }
  cg_completion_timeout(0x20795,0,5000);
  clean_up(1);
  if (0 < forkpid) {
    kill(forkpid,0xf);
    forkpid = 0;
  }
  execv(*initial_args,initial_args);
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
    return;
  }
  builtin_strncpy(local_810,"Failed to restart applicatio",0x1c);
  local_7f4 = 0x6e;
  _applog(4,local_810,0);
  return;
}

