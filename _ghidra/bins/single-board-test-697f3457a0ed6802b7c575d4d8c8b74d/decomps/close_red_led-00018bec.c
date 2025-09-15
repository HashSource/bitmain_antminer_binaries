
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_red_led(void)

{
  char tmp42 [1024];
  
  close(red_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"red led closed!!",0x10);
    tmp42[0x10] = '!';
    tmp42[0x11] = '\n';
    tmp42[0x12] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}

