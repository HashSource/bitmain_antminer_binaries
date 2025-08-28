
void close_green_led(void)

{
  char local_410 [1024];
  
  close(green_led_fd);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    builtin_strncpy(local_410,"green led closed!!!\n",0x14);
    local_410[0x14] = 0;
    _applog(2,local_410,0);
  }
  return;
}

