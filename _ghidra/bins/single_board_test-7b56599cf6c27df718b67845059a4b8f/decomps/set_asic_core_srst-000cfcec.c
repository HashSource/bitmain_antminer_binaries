
/* WARNING: Unknown calling convention */

int32_t set_asic_core_srst(uint8_t which_chain,uint32_t which_asic_address,_Bool is_active)

{
  int32_t iVar1;
  
  iVar1 = set_core_srst(which_chain,'\0',which_asic_address,is_active);
  return iVar1;
}

