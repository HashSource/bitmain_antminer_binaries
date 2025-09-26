
/* WARNING: Unknown calling convention */

int32_t set_asic_rno_en(uint8_t which_chain,uint32_t which_asic_address,_Bool is_rno_en)

{
  int32_t iVar1;
  misc_control_t misc_ctrl;
  
  get_register_cache_value(asic_cache_level,which_chain,which_asic_address,0x18,&misc_ctrl.v);
  if (is_rno_en) {
    misc_ctrl.v = misc_ctrl.v | 0xf0000000;
  }
  else {
    misc_ctrl.v = misc_ctrl.v & 0xfffffff;
  }
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x18,misc_ctrl.v);
  return iVar1;
}

