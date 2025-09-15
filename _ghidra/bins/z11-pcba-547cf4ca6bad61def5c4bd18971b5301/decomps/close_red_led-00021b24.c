
void close_red_led(void)

{
  char local_410 [16];
  undefined2 local_400;
  undefined1 local_3fe;
  
  close(red_led_fd);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    builtin_strncpy(local_410,"red led closed!!",0x10);
    local_400 = 0xa21;
    local_3fe = 0;
    _applog(2,local_410,0);
  }
  return;
}

