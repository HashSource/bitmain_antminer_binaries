
/* WARNING: Unknown calling convention */

uint8_t get_asic_index_by_nonce(uint32_t nonce,uint32_t addr_interval)

{
  uint8_t uVar1;
  
  uVar1 = __aeabi_uidiv((nonce << 7) >> 0x18);
  return uVar1;
}

