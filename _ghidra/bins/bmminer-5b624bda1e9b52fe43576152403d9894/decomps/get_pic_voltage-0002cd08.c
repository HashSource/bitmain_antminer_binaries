
/* WARNING: Unknown calling convention */

uchar get_pic_voltage(uchar chain)

{
  uchar uVar1;
  byte which_iic;
  
  if (fpga_version < 0xe) {
    which_iic = chain / 3;
  }
  else if (chain - 1 < 0xd) {
    which_iic = CSWTCH_824[(chain - 1) * 4];
  }
  else {
    which_iic = 0;
  }
  uVar1 = AT24C02_read_voltage(which_iic);
  return uVar1;
}

