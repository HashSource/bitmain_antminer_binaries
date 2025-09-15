
void AT24C02_save_voltage(undefined4 param_1,undefined4 param_2)

{
  write_EEPROM_iic(0,1,0x90,param_1,param_2);
  return;
}

