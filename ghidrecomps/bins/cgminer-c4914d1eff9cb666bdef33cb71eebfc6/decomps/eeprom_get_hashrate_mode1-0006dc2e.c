
_Bool eeprom_get_hashrate_mode1(uint8_t chain,uint32_t *hash)

{
  _Bool _Var1;
  uint32_t *hash_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_get_hashrate(chain,hash);
  return _Var1;
}

