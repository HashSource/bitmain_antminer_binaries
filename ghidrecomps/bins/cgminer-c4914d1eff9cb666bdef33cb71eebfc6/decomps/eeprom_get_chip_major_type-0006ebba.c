
_Bool eeprom_get_chip_major_type(uint8_t chain,CHIP_MAJOR_TYPE *type)

{
  _Bool _Var1;
  byte bVar2;
  CHIP_MAJOR_TYPE *type_local;
  uint8_t chain_local;
  chip_info_t chip_info;
  uint8_t *p;
  
  memset(&chip_info,0,1);
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    bVar2 = array_read_one_byte(0xf8,chain);
    *type = bVar2 & 7;
  }
  return _Var1;
}

