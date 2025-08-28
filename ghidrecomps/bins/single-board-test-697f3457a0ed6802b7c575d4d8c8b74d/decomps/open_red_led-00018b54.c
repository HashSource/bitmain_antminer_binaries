
/* WARNING: Unknown calling convention */

int open_red_led(void)

{
  char tmp42 [1024];
  
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if ((red_led_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open red led failed!!!\n",0x18);
    _applog(2,tmp42,false);
  }
  return red_led_fd;
}

