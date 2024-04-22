
/* WARNING: Unknown calling convention */

void BM1397_enable_read_temperature_from_asic(uchar which_chain,uchar asic_addr)

{
  BM1397_set_config(which_chain,asic_addr,'\x18',gBM1397_MISC_CONTROL_reg | 0x4030,false);
  return;
}

