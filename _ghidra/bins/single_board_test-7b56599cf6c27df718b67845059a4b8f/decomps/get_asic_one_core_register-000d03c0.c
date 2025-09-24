
/* WARNING: Unknown calling convention */

int32_t get_asic_one_core_register(uint8_t which_chain,uint32_t which_asic_address,uint8_t core_reg)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x3c,(core_reg & 0x1f) << 8);
  return iVar1;
}

