
/* WARNING: Unknown calling convention */

int32_t get_chain_error_flag(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = send_get_status_command(which_chain,'\x01',0,0x48);
  return iVar1;
}

