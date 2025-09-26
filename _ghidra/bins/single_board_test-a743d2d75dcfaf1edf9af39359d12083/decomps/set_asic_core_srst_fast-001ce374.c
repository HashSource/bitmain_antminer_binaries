
/* WARNING: Unknown calling convention */

int32_t set_asic_core_srst_fast(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = set_core_srst_fast(which_chain,'\0',which_asic_address);
  return iVar1;
}

