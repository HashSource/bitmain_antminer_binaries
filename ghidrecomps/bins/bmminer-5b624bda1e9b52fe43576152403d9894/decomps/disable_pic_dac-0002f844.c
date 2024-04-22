
/* WARNING: Unknown calling convention */

void disable_pic_dac(uchar chain)

{
  uint uVar1;
  int new_T9_PLUS_chainIndex;
  
  uVar1 = (uint)chain;
  if (*DAT_0002f898 < 0xe) {
    if ((uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) & 0xff)
        == 2) {
      dsPIC33EP16GS202_enable_pic_dc_dc((uchar)(uVar1 / 3),'\0');
      return;
    }
  }
  else {
    if (uVar1 - 1 < 0xd) {
      new_T9_PLUS_chainIndex._0_1_ = (uchar)*(undefined4 *)(DAT_0002f89c + (uVar1 - 1) * 4 + 0x9b8);
    }
    else {
      new_T9_PLUS_chainIndex._0_1_ = '\0';
    }
    if (((uVar1 & 0xfd) == 9) || (uVar1 == 0xd)) {
      dsPIC33EP16GS202_enable_pic_dc_dc((uchar)new_T9_PLUS_chainIndex,'\0');
      return;
    }
  }
  return;
}

