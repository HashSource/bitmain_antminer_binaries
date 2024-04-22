
int uart_init(int comport,int baud)

{
  int baud_local;
  int comport_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chain=%d baudrate=%d\n","uart_init",comport,baud);
    _applog(2,tmp42,false);
  }
  return (uint)gChain;
}

