
/* WARNING: Unknown calling convention */

int32_t get_chain_core_register(uint8_t which_chain,uint8_t core_reg)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x3c,(core_reg & 0x1f) << 8 | 0x80000000);
  return iVar1;
}

