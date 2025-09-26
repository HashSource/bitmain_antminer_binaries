
/* WARNING: Unknown calling convention */

int32_t set_chain_core_enable_by_coreId(uint8_t which_chain,uint32_t which_core)

{
  int32_t iVar1;
  
  iVar1 = set_core_enable(which_chain,'\x01','\0',0,which_core);
  return iVar1;
}

