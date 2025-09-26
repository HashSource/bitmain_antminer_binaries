
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void disable_mid_auto_gen_rx(void)

{
  fpga_write(0x21,0x10000);
  return;
}

