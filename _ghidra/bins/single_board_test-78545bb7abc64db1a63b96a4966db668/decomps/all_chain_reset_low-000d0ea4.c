
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void all_chain_reset_low(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xd,&val);
  val = val & 0xffff0000;
  fpga_write(0xd,val);
  sleep(2);
  return;
}

