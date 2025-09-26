
/* WARNING: Unknown calling convention */

int32_t get_asic_hash_clock_counter(uint8_t which_chain,uint32_t which_asic_address)

{
  int32_t iVar1;
  
  iVar1 = get_core_hash_clock_counter(which_chain,'\0',which_asic_address);
  return iVar1;
}

