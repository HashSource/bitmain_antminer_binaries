
/* WARNING: Unknown calling convention */

void set_working_uart_baud(void)

{
  set_baud('\x01',1);
  return;
}

