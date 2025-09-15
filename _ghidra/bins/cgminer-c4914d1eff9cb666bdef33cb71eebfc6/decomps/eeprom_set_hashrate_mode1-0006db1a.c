
_Bool eeprom_set_hashrate_mode1(uint8_t chain,uint32_t hash)

{
  _Bool _Var1;
  uint32_t hash_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_set_hashrate(chain,hash);
  return _Var1;
}

