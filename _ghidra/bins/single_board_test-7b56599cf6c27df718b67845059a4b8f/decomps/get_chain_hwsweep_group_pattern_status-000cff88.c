
/* WARNING: Unknown calling convention */

int32_t get_chain_hwsweep_group_pattern_status(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = send_get_status_command(which_chain,'\x01',0,0xd8);
  return iVar1;
}

