
/* WARNING: Unknown calling convention */

uchar get_pic_voltage(uchar chain)

{
  uchar uVar1;
  byte which_iic;
  
  if (*DAT_0002cd38 < 0xe) {
    which_iic = chain / 3;
  }
  else if (chain - 1 < 0xd) {
    which_iic = *(byte *)(DAT_0002cd3c + (chain - 1) * 4 + 0x9b8);
  }
  else {
    which_iic = 0;
  }
  uVar1 = AT24C02_read_voltage(which_iic);
  return uVar1;
}

