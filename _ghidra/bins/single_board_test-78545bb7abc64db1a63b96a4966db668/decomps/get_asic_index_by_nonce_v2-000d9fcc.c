
/* WARNING: Unknown calling convention */

uint8_t get_asic_index_by_nonce_v2(uint32_t nonce,uint32_t asic_num)

{
  return (uint8_t)(((nonce << 7) >> 0x10) * asic_num >> 0x10);
}

