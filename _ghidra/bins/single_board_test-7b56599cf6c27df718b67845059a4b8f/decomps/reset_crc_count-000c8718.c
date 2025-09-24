
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_crc_count(void)

{
  fpga_write(0x21,0);
  return;
}

