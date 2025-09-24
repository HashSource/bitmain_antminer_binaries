
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void enable_work_send(void)

{
  fpga_write(0x2d,0xffffffff);
  return;
}

