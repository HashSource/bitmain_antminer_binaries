
/* WARNING: Unknown calling convention */

uint32_t BM1397_get_core_id(uint32_t nonce)

{
  return nonce >> 0x1f | ((nonce << 1) >> 0x17) << 1;
}

