
/* WARNING: Unknown calling convention */

void enable_pic_dac(uchar chain)

{
  uint uVar1;
  
  uVar1 = (uint)chain;
  if (*DAT_0002f8d4 < 0xe) {
    chain = (uchar)(uVar1 / 3);
    if ((uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) & 0xff)
        == 0) goto LAB_0002f8cc;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002f8cc:
    dsPIC33EP16GS202_enable_pic_dc_dc(chain,'\x01');
    return;
  }
  return;
}

