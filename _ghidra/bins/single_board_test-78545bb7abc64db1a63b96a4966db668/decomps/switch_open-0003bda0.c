
int32_t switch_open(uint32_t which_chain)

{
  uint32_t uVar1;
  uint32_t which_chain_local;
  iic_init_param_t param;
  int32_t ret;
  
  if ((_g_switch_state[which_chain].switch_fd == 0) ||
     (_g_switch_state[which_chain].chain_has_opened == 0)) {
    param.master_addr = 0;
    param.slave_high = '\x0e';
    param.slave_low = (uint8_t)which_chain;
    param.chain_id = which_chain;
    uVar1 = iic_init(&param);
    if (-1 < (int)uVar1) {
      _g_switch_state[which_chain].switch_fd = uVar1;
      _g_switch_state[which_chain].chain_has_opened = 1;
    }
  }
  else {
    uVar1 = _g_switch_state[which_chain].switch_fd;
  }
  return uVar1;
}

