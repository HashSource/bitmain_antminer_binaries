
undefined4 open_lcd(void)

{
  char local_410 [1024];
  
  cgpu._36_4_ = open("/dev/bitmain-lcd",0x882);
  if (((int)cgpu._36_4_ < 1) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    builtin_strncpy(local_410,"open lcd failed!!!\n",0x14);
    _applog(2,local_410,0);
  }
  return cgpu._36_4_;
}

