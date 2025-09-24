
/* WARNING: Unknown calling convention */

int32_t trigger_chain_hwsweep_pattern_test(uint8_t which_chain)

{
  int32_t iVar1;
  frequency_sweep_control_t sweep_ctrl;
  
  get_register_cache_value(hashboard_cache_level,which_chain,0,0xd0,&sweep_ctrl.v);
  sweep_ctrl.v = sweep_ctrl.v & 0xfffff7ff | 0x800008a;
  iVar1 = send_set_config_command(which_chain,'\x01',0,0xd0,sweep_ctrl.v);
  return iVar1;
}

