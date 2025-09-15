
/* WARNING: Unknown calling convention */

void disable_pic_dac(uchar chain)

{
  uint uVar1;
  uchar which_iic;
  
  uVar1 = (uint)chain;
  if (fpga_version < 0xe) {
    if (uVar1 % 3 == 2) {
      dsPIC33EP16GS202_enable_pic_dc_dc(chain / 3,'\0');
      return;
    }
  }
  else {
    if (uVar1 - 1 < 0xd) {
      which_iic = (uchar)*(undefined4 *)(CSWTCH_824 + (uVar1 - 1) * 4);
    }
    else {
      which_iic = '\0';
    }
    if (((uVar1 & 0xfd) == 9) || (uVar1 == 0xd)) {
      dsPIC33EP16GS202_enable_pic_dc_dc(which_iic,'\0');
      return;
    }
  }
  return;
}

