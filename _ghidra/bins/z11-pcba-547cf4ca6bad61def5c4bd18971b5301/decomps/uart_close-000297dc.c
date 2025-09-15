
undefined4 uart_close(undefined4 param_1)

{
  char acStack_408 [1024];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_408,0x400,"%s fd=%d\n","uart_close",param_1);
    _applog(2,acStack_408,0);
  }
  return 0;
}

