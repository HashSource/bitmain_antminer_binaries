
_Bool eeprom_get_freq_mode1(uint8_t chain,uint32_t *buf)

{
  _Bool _Var1;
  uint32_t *buf_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_get_freq(chain,buf);
  return _Var1;
}

