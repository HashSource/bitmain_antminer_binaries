
_Bool _eeprom_set_hashrate(uint8_t chain,uint32_t hash,uint8_t mode)

{
  _Bool _Var1;
  char cVar2;
  uint32_t hash_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t hash_rate [4];
  uint8_t hash_addr;
  int i;
  
  hash_rate = (uint8_t  [4])hash;
  if (mode == '\x01') {
    cVar2 = -0xc;
  }
  else {
    cVar2 = 'n';
  }
  for (i = 0; (uint)i < 4; i = i + 1) {
    array_write_one_byte(cVar2 + (char)i,hash_rate[i],chain);
  }
  _Var1 = array_update_crc(chain);
  return _Var1;
}

