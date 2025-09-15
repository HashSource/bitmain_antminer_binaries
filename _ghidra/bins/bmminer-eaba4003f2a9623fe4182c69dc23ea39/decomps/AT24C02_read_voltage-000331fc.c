
uchar AT24C02_read_voltage(uchar which_iic)

{
  uchar uVar1;
  uchar which_iic_local;
  
  uVar1 = AT24C02_read_one_byte(0x90,which_iic);
  return uVar1;
}

