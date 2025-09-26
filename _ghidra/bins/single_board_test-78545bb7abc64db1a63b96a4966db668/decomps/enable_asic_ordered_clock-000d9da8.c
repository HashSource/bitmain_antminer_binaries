
/* WARNING: Unknown calling convention */

int32_t enable_asic_ordered_clock(uint8_t which_chain,uint32_t which_asic_address,_Bool is_enable)

{
  int32_t iVar1;
  uint32_t reg_data;
  
  reg_data = 3;
  if (!is_enable) {
    reg_data = 0;
  }
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x20,reg_data);
  return iVar1;
}

