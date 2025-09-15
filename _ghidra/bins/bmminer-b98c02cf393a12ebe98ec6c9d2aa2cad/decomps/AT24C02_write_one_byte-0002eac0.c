
void AT24C02_write_one_byte(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write_EEPROM_iic(0,1,param_1,param_3,param_2);
  return;
}

