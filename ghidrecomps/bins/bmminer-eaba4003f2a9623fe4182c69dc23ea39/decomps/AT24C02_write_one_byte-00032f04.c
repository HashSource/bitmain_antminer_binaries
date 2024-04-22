
void AT24C02_write_one_byte(uchar address,uchar data,uchar which_iic)

{
  uchar which_iic_local;
  uchar data_local;
  uchar address_local;
  
  write_EEPROM_iic(false,true,address,which_iic,data);
  return;
}

