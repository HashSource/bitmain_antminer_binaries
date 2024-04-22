
uchar AT24C02_read_freq_one_chip(uchar which_iic)

{
  uchar uVar1;
  uchar which_iic_local;
  
  uVar1 = AT24C02_read_one_byte('\0',which_iic);
  return uVar1;
}

