
/* WARNING: Unknown calling convention */

void AT24C02_write_one_byte(uchar address,uchar data,uchar which_iic)

{
  write_EEPROM_iic(false,true,address,which_iic,data);
  return;
}

