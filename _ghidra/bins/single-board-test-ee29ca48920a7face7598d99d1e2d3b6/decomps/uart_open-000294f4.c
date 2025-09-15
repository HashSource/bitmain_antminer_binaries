
undefined4 uart_open(undefined4 param_1,undefined4 *param_2)

{
  char acStack_40c [1024];
  undefined4 *local_c;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_c = param_2;
    snprintf(acStack_40c,0x400,"%s name=%s baudrate=%d\n","uart_open",param_1,*param_2);
    _applog(2,acStack_40c,0);
  }
  return 0;
}

