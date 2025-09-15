
/* WARNING: Unknown calling convention */

void enable_pic_dac(uchar chain)

{
  uint uVar1;
  
  uVar1 = (uint)chain;
  if (fpga_version < 0xe) {
    chain = chain / 3;
    if (uVar1 % 3 == 0) goto LAB_0002f8cc;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002f8cc:
    dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\x01');
    return;
  }
  return;
}

