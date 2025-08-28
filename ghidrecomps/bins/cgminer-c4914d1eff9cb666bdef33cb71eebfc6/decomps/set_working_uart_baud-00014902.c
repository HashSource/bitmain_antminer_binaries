
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_working_uart_baud(void)

{
  set_baud('\x01',1);
  return;
}

