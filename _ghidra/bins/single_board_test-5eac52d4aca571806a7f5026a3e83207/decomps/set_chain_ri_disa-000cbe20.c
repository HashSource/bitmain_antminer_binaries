
/* WARNING: Unknown calling convention */

int32_t set_chain_ri_disa(uint8_t which_chain,uint8_t ri_disa)

{
  int32_t iVar1;
  misc_control_t misc_reg;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_reg.v);
  misc_reg.v._0_1_ = misc_reg.v._0_1_ & 0xf7 | (ri_disa & 1) << 3;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x18,misc_reg.v);
  return iVar1;
}

