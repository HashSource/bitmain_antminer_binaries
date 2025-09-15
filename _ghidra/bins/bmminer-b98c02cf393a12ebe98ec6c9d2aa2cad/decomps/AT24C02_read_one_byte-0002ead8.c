
void AT24C02_read_one_byte(undefined4 param_1,undefined4 param_2)

{
  write_EEPROM_iic(1,1,param_1,param_2,0);
  return;
}

