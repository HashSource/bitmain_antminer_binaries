
/* WARNING: Unknown calling convention */

int32_t set_chain_core_srst(uint8_t which_chain,_Bool is_active)

{
  int32_t iVar1;
  
  iVar1 = set_core_srst(which_chain,'\x01',0,is_active);
  return iVar1;
}

