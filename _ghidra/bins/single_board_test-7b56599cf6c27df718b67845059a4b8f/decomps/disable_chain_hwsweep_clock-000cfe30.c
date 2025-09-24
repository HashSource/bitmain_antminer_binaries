
/* WARNING: Unknown calling convention */

int32_t disable_chain_hwsweep_clock(uint8_t which_chain)

{
  int32_t iVar1;
  misc_control_t misc_ctrl;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_ctrl.v);
  misc_ctrl.v = misc_ctrl.v & 0xfffffffb;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x18,misc_ctrl.v);
  return iVar1;
}

