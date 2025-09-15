
/* WARNING: Unknown calling convention */

int open_green_led(void)

{
  char tmp42 [1024];
  
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if ((green_led_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open green led failed!!!",0x18);
    tmp42[0x18] = '\n';
    tmp42[0x19] = '\0';
    _applog(2,tmp42,false);
  }
  return green_led_fd;
}

