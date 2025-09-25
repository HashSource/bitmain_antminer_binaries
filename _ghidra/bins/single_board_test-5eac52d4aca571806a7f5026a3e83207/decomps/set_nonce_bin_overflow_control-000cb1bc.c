
/* WARNING: Unknown calling convention */

int32_t set_nonce_bin_overflow_control
                  (uint8_t which_chain,uint8_t mode,uint32_t which_asic_address,
                  _Bool is_enable_nonce_bin_overflow)

{
  int32_t iVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  if (is_enable_nonce_bin_overflow) {
    uVar2 = 0xfffffffe;
  }
  iVar1 = send_set_config_command
                    (which_chain,mode,which_asic_address,0x3c,uVar2 & 0xef | 0x80008d04);
  return iVar1;
}

