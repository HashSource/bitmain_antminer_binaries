
/* WARNING: Unknown calling convention */

int32_t set_asic_core_enable_by_coreId
                  (uint8_t which_chain,uint32_t which_asic_address,uint32_t which_core)

{
  int32_t iVar1;
  
  iVar1 = set_core_enable(which_chain,'\0','\0',which_asic_address,which_core);
  return iVar1;
}

