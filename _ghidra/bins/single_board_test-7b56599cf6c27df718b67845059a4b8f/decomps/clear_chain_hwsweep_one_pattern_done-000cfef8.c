
/* WARNING: Unknown calling convention */

int32_t clear_chain_hwsweep_one_pattern_done(uint8_t which_chain)

{
  int32_t iVar1;
  frequency_sweep_control_t sweep_ctrl;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xd0,&sweep_ctrl.v);
  sweep_ctrl.v = sweep_ctrl.v & 0xfffff7fd | 0x8000088;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0xd0,sweep_ctrl.v);
  return iVar1;
}

