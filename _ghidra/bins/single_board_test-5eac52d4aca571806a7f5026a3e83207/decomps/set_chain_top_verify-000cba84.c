
/* WARNING: Unknown calling convention */

int32_t set_chain_top_verify(uint8_t which_chain,_Bool is_enable)

{
  int32_t iVar1;
  misc_control_t misc_reg;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_reg.v);
  if (is_enable) {
    misc_reg.v = misc_reg.v | 0x8000;
  }
  else {
    misc_reg.v = misc_reg.v & 0xffff7fff;
  }
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x18,misc_reg.v);
  return iVar1;
}

