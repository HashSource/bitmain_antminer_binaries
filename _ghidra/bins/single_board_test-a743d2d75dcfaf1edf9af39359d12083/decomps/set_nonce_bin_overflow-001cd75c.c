
/* WARNING: Unknown calling convention */

int32_t set_nonce_bin_overflow
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                  _Bool is_enable_nonce_bin_overflow)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,mode,which_asic_address,0x3c,
                     !is_enable_nonce_bin_overflow | 0x80008700);
  return iVar1;
}

