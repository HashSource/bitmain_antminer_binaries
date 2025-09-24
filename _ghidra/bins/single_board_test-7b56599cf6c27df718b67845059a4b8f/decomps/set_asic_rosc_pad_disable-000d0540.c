
/* WARNING: Unknown calling convention */

int32_t set_asic_rosc_pad_disable(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\0',which_asic_address,0x68,0x5aa55aa5);
  return iVar1;
}

