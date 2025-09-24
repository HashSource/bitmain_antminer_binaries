
/* WARNING: Unknown calling convention */

uint8_t get_asic_index_by_nonce_v2(uint32_t nonce,uint32_t asic_num)

{
  return (uint8_t)(asic_num * ((nonce << 7) >> 0x10) >> 0x10);
}

