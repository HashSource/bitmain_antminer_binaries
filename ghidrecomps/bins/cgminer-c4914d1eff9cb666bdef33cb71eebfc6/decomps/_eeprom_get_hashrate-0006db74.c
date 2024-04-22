
_Bool _eeprom_get_hashrate(uint8_t chain,uint32_t *hash,uint8_t mode)

{
  uint8_t uVar1;
  uint32_t *hash_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t hash_rate [4];
  uint8_t hash_addr;
  int i;
  
  hash_rate[0] = '\0';
  hash_rate[1] = '\0';
  hash_rate[2] = '\0';
  hash_rate[3] = '\0';
  if (mode == '\x01') {
    hash_addr = 0xf4;
  }
  else {
    hash_addr = 'n';
  }
  for (i = 0; (uint)i < 4; i = i + 1) {
    uVar1 = array_read_one_byte(hash_addr + (char)i,chain);
    hash_rate[i] = uVar1;
  }
  *hash = ((uint)hash_rate & 0xff) + ((uint)hash_rate >> 8 & 0xff) * 0x100 +
          ((uint)hash_rate >> 0x10 & 0xff) * 0x10000 + ((uint)hash_rate & 0xff000000);
  return true;
}

