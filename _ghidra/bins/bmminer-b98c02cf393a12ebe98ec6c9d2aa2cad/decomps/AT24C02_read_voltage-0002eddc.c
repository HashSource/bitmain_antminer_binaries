
void AT24C02_read_voltage(undefined4 param_1)

{
  write_EEPROM_iic(1,1,0x90,param_1,0);
  return;
}

