
/* WARNING: Unknown calling convention */

void get_pic_software_version(uchar chain,uchar *version)

{
  uchar which_iic;
  
  if (fpga_version < 0xe) {
    dsPIC33EP16GS202_get_pic_sw_version(chain / 3,version);
    return;
  }
  if (chain - 1 < 0xd) {
    which_iic = CSWTCH_824[(chain - 1) * 4];
  }
  else {
    which_iic = '\0';
  }
  dsPIC33EP16GS202_get_pic_sw_version(which_iic,version);
  return;
}

