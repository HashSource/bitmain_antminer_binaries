
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void disable_all_chain_reset(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xd,&val);
  val = val & 0xffff0000;
  fpga_write(0xd,val);
  return;
}

