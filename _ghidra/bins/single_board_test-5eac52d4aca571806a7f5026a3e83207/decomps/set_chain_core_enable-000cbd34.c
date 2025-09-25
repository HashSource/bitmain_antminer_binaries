
/* WARNING: Unknown calling convention */

int32_t set_chain_core_enable(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = set_core_enable(which_chain,'\x01','\x01',0,0);
  return iVar1;
}

