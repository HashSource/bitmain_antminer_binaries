
_Bool eeprom_get_hashrate_mode2(uint8_t chain,uint32_t *hash)

{
  _Bool _Var1;
  uint32_t *hash_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = _eeprom_get_hashrate(chain,hash,'\x01');
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

