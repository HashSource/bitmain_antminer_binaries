
/* WARNING: Unknown calling convention */

uchar AT24C02_read_voltage(uchar which_iic)

{
  uchar uVar1;
  
  uVar1 = AT24C02_read_one_byte(0x90,which_iic);
  return uVar1;
}

