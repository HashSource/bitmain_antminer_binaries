
_Bool _eeprom_set_voltage(uint8_t chain,double voltage,uint8_t mode)

{
  _Bool _Var1;
  uint8_t address;
  float fVar2;
  double voltage_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t voltage_addr;
  uint8_t vol;
  
  fVar2 = roundf((float)(voltage * 100.0));
  fVar2 = fVar2 / 2.0 - 300.0;
  if (mode == '\x01') {
    address = 0x87;
  }
  else {
    address = '\x01';
  }
  array_write_one_byte(address,(0.0 < fVar2) * (char)(int)fVar2,chain);
  _Var1 = array_update_crc(chain);
  return _Var1;
}

