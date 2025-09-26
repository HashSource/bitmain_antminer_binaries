
/* WARNING: Unknown calling convention */

int32_t set_chain_rosc_pad_disable(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0x68,0x5aa55aa5);
  return iVar1;
}

