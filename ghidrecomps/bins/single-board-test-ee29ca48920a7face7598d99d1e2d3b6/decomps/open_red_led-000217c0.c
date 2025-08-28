
int open_red_led(void)

{
  char local_410 [1024];
  
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if ((red_led_fd < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    builtin_strncpy(local_410,"open red led failed!!!\n",0x18);
    _applog(2,local_410,0);
  }
  return red_led_fd;
}

