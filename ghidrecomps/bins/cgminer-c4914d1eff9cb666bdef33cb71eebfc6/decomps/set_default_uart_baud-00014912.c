
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_default_uart_baud(void)

{
  gBM1393_MISC_CONTROL_reg = 0x3a01;
  return;
}

