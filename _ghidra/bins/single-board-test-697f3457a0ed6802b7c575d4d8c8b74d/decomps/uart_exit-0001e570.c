
int uart_exit(int fd)

{
  int fd_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s fd=%d\n","uart_exit",fd);
    _applog(2,tmp42,false);
  }
  return 0;
}

