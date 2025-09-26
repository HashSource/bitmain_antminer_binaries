
/* WARNING: Unknown calling convention */

int32_t set_chain_core_srst_fast(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = set_core_srst_fast(which_chain,'\x01',0);
  return iVar1;
}

