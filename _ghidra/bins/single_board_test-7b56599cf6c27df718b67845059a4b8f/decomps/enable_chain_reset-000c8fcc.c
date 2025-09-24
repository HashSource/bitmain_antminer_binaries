
/* WARNING: Unknown calling convention */

void enable_chain_reset(uint32_t chain_id)

{
  uint32_t uStack_c;
  
  uStack_c = 0;
  fpga_read(0xd,&uStack_c);
  uStack_c = uStack_c | 1 << (chain_id & 0xff);
  fpga_write(0xd,uStack_c);
  return;
}

