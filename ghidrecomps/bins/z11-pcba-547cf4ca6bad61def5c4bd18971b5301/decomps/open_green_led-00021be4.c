
int open_green_led(void)

{
  char local_410 [24];
  undefined2 local_3f8;
  
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if ((green_led_fd < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    builtin_strncpy(local_410,"open green led failed!!!",0x18);
    local_3f8 = 10;
    _applog(2,local_410,0);
  }
  return green_led_fd;
}

