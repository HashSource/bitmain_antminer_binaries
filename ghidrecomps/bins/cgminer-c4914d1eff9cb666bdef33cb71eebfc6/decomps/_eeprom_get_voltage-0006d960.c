
_Bool _eeprom_get_voltage(uint8_t chain,double *voltage,uint8_t mode)

{
  byte bVar1;
  uint8_t address;
  double *voltage_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t voltage_addr;
  uint32_t vol;
  
  if (mode == '\x01') {
    address = 0x87;
  }
  else {
    address = '\x01';
  }
  bVar1 = array_read_one_byte(address,chain);
  *voltage = ((double)(ulonglong)(bVar1 + 300) + (double)(ulonglong)(bVar1 + 300)) / DAT_0006d9c0;
  return true;
}

