
/* WARNING: Unknown calling convention */

int32_t set_core_srst(uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,_Bool is_active)

{
  int32_t iVar1;
  soft_reset_control_t soft_reset_reg;
  misc_control_t misc_reg;
  
  if (mode == '\x01') {
    get_register_cache_value(hashboard_cache_level,which_chain,0,0xa8,&soft_reset_reg.v);
    get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_reg.v);
  }
  else {
    get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0xa8,&soft_reset_reg.v)
    ;
    get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0x18,&misc_reg.v);
  }
  if (is_active) {
    soft_reset_reg.v = soft_reset_reg.v | 0x10f;
    misc_reg.v._0_3_ = (uint3)misc_reg.v & 0xf0ffff;
    misc_reg.v._3_1_ = 0;
  }
  else {
    soft_reset_reg.v._0_1_ = soft_reset_reg.v._0_1_ & 0xf0 | is_active & 0xfU;
    misc_reg.v._0_3_ = (uint3)misc_reg.v | 0xf0000;
    misc_reg.v._3_1_ = 0xff;
  }
  iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0xa8,soft_reset_reg.v);
  if (iVar1 == 0) {
    iVar1 = send_set_config_command(which_chain,mode,which_asic_address,0x18,misc_reg.v);
  }
  return iVar1;
}

