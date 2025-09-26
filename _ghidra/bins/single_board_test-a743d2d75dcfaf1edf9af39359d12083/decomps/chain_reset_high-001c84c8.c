
/* WARNING: Unknown calling convention */

void chain_reset_high(uint32_t chain_id)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xd,&val);
  val = val & ~(1 << (chain_id & 0xff));
  fpga_write(0xd,val);
  return;
}

