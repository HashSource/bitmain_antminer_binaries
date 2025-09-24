
/* WARNING: Unknown calling convention */

int32_t get_asic_hwsweep_nonce_returned_counter(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = send_get_status_command(which_chain,'\0',which_asic_address,0xe0);
  return iVar1;
}

