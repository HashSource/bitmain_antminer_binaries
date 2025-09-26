
/* WARNING: Unknown calling convention */

int32_t set_asic_force_core_en(uint8_t which_chain,uint32_t which_asic_address,_Bool is_enable)

{
  int32_t iVar1;
  misc_control_t misc_reg;
  
  get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0x18,&misc_reg.v);
  if (is_enable) {
    misc_reg.v._1_1_ = misc_reg.v._1_1_ | 3;
  }
  else {
    misc_reg.v._1_1_ = misc_reg.v._1_1_ & 0xfc | is_enable;
  }
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x18,misc_reg.v);
  return iVar1;
}

