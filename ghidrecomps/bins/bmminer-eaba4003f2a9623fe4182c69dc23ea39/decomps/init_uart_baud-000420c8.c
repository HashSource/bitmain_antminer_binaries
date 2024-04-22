
/* WARNING: Unknown calling convention */

void init_uart_baud(void)

{
  int iVar1;
  char tmp42 [2048];
  char logstr [1024];
  int i;
  uchar bauddiv;
  uint baud;
  uint rBaudrate;
  
  iVar1 = __aeabi_uidiv(0x196e6a,dev->timeout);
  __aeabi_uidiv(0x2faf08,iVar1 << 9);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set baud=%d\n",1);
    _applog(5,tmp42,false);
  }
  set_baud('\x01',1);
  return;
}

