
/* WARNING: Unknown calling convention */

int32_t do_chain_chip_reset(uint8_t which_chain)

{
  int32_t iVar1;
  soft_reset_control_t soft_reset_reg;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xa8,&soft_reset_reg.v);
  soft_reset_reg.v = soft_reset_reg.v | 0x400;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0xa8,soft_reset_reg.v);
  return iVar1;
}

