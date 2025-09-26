
/* WARNING: Unknown calling convention */

void enable_chain_reset(uint32_t chain_id)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xd,&val);
  val = 1 << (chain_id & 0xff) | val;
  fpga_write(0xd,val);
  return;
}

