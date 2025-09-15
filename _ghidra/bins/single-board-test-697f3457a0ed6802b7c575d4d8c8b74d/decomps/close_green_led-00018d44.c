
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_green_led(void)

{
  char tmp42 [1024];
  
  close(green_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"green led closed!!!\n",0x14);
    tmp42[0x14] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}

