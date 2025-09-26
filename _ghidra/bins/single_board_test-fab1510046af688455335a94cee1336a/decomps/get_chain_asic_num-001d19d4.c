
/* WARNING: Unknown calling convention */

int32_t get_chain_asic_num(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = send_get_status_command(which_chain,'\x01',0,0);
  return iVar1;
}

