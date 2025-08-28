
undefined4 open_key(void)

{
  char local_410 [1024];
  
  cgpu._44_4_ = open("/sys/class/gpio/gpio943/value",0x800);
  if (((int)cgpu._44_4_ < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    builtin_strncpy(local_410,"open key failed!!!\n",0x14);
    _applog(2,local_410,0);
  }
  return cgpu._44_4_;
}

