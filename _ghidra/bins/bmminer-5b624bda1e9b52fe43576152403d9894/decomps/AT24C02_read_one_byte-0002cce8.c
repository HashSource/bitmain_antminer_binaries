
/* WARNING: Unknown calling convention */

uchar AT24C02_read_one_byte(uchar address,uchar which_iic)

{
  uchar uVar1;
  
  uVar1 = write_EEPROM_iic(true,true,address,which_iic,'\0');
  return uVar1;
}

