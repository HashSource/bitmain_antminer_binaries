
/* WARNING: Unknown calling convention */

void set_default_uart_baud(void)

{
  gBM1393_MISC_CONTROL_reg = 0x3a01;
  return;
}

