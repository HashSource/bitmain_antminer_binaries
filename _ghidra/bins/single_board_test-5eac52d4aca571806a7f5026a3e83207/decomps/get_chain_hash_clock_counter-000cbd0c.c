
/* WARNING: Unknown calling convention */

int32_t get_chain_hash_clock_counter(uint8_t which_chain)

{
  int32_t iVar1;
  
  iVar1 = get_core_hash_clock_counter(which_chain,'\x01',0);
  return iVar1;
}

