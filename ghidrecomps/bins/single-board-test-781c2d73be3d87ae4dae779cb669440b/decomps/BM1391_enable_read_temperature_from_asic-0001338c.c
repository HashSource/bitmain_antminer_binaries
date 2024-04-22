
/* WARNING: Unknown calling convention */

void BM1391_enable_read_temperature_from_asic(uchar which_chain,uchar asic_addr)

{
  BM1391_set_config(which_chain,asic_addr,'\x18',gBM1391_MISC_CONTROL_reg | 0x4030,false);
  return;
}

