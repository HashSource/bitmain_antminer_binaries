
/* WARNING: Unknown calling convention */

int32_t set_chain_core_nonce_overflow_control
                  (uint8_t which_chain,_Bool is_enable_nonce_bin_overflow)

{
  int32_t iVar1;
  
  iVar1 = set_nonce_bin_overflow_control(which_chain,'\x01',0,is_enable_nonce_bin_overflow);
  return iVar1;
}

