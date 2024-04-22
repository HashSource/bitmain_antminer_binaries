
_Bool eeprom_set_freq_mode1(uint8_t chain,uint32_t *buf)

{
  _Bool _Var1;
  uint32_t *buf_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_set_freq(chain,buf);
  return _Var1;
}

