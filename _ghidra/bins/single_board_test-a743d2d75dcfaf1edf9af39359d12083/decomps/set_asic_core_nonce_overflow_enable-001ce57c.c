
/* WARNING: Unknown calling convention */

int32_t set_asic_core_nonce_overflow_enable
                  (uint8_t which_chain,uint32_t which_asic_address,
                  _Bool is_enable_nonce_bin_overflow)

{
  int32_t iVar1;
  
  iVar1 = set_nonce_bin_overflow(which_chain,'\0',which_asic_address,is_enable_nonce_bin_overflow);
  return iVar1;
}

