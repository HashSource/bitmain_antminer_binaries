
/* WARNING: Unknown calling convention */

int32_t set_chain_ret_work_err(uint8_t which_chain,_Bool is_enable)

{
  int32_t iVar1;
  misc_control_t misc_reg;
  
  iVar1 = get_register_cache_value(hashboard_cache_level,which_chain,0,0x18,&misc_reg.v);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    if (is_enable) {
      misc_reg.v = misc_reg.v | 0x80;
    }
    else {
      misc_reg.v = misc_reg.v & 0xffffff7f;
    }
    iVar1 = send_set_config_command(which_chain,'\x01',0,0x18,misc_reg.v);
  }
  return iVar1;
}

