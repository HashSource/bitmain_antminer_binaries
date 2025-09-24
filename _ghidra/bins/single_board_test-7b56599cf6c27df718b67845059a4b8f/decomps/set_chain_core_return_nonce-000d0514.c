
/* WARNING: Unknown calling convention */

int32_t set_chain_core_return_nonce(uint8_t which_chain,_Bool enable)

{
  int32_t iVar1;
  
  iVar1 = set_core_rec_nonce(which_chain,'\x01',0,enable);
  return iVar1;
}

