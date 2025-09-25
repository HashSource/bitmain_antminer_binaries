
/* WARNING: Unknown calling convention */

int32_t set_core_rec_reg(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,_Bool enable)

{
  int32_t iVar1;
  misc_control_t misc_reg;
  
  if (mode == '\x01') {
    get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_reg.v);
  }
  else {
    get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0x18,&misc_reg.v);
  }
  if (enable) {
    misc_reg.v = misc_reg.v | 0xf0f0000;
  }
  else {
    misc_reg.v._2_1_ = misc_reg.v._2_1_ & 0xf0 | enable & 0xfU;
    misc_reg.v._3_1_ = misc_reg.v._3_1_ & 0xf0 | enable & 0xfU;
  }
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x18,misc_reg.v);
  return iVar1;
}

