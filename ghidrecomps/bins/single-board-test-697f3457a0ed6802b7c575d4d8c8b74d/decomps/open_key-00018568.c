
/* WARNING: Unknown calling convention */

int open_key(void)

{
  char tmp42 [1024];
  
  cgpu.key_fd = open("/sys/class/gpio/gpio943/value",0x800);
  if ((cgpu.key_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open key failed!!!\n",0x14);
    _applog(2,tmp42,false);
  }
  return cgpu.key_fd;
}

