
/* WARNING: Unknown calling convention */

int32_t set_asic_core_enable(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = set_core_enable(which_chain,'\0','\x01',which_asic_address,0);
  return iVar1;
}

