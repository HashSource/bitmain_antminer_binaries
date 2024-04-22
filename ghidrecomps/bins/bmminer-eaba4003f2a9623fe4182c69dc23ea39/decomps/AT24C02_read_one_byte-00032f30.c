
uchar AT24C02_read_one_byte(uchar address,uchar which_iic)

{
  uchar uVar1;
  uchar which_iic_local;
  uchar address_local;
  uchar data;
  
  uVar1 = write_EEPROM_iic(true,true,address,which_iic,'\0');
  return uVar1;
}

