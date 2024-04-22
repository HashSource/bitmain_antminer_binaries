
void bm174x_set_core_timeout(int fd,uint32_t timeout)

{
  uint32_t timeout_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set core timeout %u\n",timeout);
    _applog(2,tmp42,false);
  }
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '(';
  reg_value.core_timeout = timeout;
  item.data = timeout;
  bm174x_ioctl(fd,1,&item);
  return;
}

