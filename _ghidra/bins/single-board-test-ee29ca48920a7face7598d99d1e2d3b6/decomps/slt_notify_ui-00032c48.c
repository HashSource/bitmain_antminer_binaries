
void slt_notify_ui(undefined4 param_1,undefined4 param_2)

{
  char acStack_408 [1024];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_408,0x400,"pass %d bin %d\n",param_1,param_2);
    _applog(2,acStack_408,0);
  }
  return;
}

