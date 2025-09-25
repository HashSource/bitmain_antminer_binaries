
/* WARNING: Unknown calling convention */

uint8_t get_coreid_by_nonce(uint32_t nonce)

{
  return (uint8_t)(nonce >> 0x19);
}

