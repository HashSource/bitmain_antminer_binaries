
/* WARNING: Unknown calling convention */

int32_t set_chain_hwsweep_nonce_return_timeout(uint8_t which_chain,uint32_t timeout)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command(which_chain,'\x01',0,0xdc,timeout);
  return iVar1;
}

