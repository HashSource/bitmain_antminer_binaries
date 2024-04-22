
/* WARNING: Unknown calling convention */

void single_BM1391_set_baud(uchar which_chain,uchar chip_addr,uchar asic_baud,_Bool mode)

{
  gBM1391_MISC_CONTROL_reg = gBM1391_MISC_CONTROL_reg & 0xffffe0ff | (uint)asic_baud << 8;
  BM1391_set_config(which_chain,chip_addr,'\x18',gBM1391_MISC_CONTROL_reg,mode);
  return;
}

