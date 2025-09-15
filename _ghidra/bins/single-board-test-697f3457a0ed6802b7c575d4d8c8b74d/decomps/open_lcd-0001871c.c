
/* WARNING: Unknown calling convention */

int open_lcd(void)

{
  char tmp42 [1024];
  
  cgpu.lcd_fd = open("/dev/bitmain-lcd",0x882);
  if ((cgpu.lcd_fd < 1) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open lcd failed!!!\n",0x14);
    _applog(2,tmp42,false);
  }
  return cgpu.lcd_fd;
}

