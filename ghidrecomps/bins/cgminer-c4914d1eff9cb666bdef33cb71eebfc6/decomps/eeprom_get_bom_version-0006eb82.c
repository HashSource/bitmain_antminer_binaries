
_Bool eeprom_get_bom_version(uint8_t chain,uint8_t *bom_version)

{
  _Bool _Var1;
  uint8_t *bom_version_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = _eeprom_get_bom_version(chain,bom_version);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

