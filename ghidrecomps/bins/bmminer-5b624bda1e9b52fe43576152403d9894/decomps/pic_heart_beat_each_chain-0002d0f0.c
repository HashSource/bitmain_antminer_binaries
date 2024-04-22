
/* WARNING: Unknown calling convention */

void pic_heart_beat_each_chain(uchar chain)

{
  uint uVar1;
  
  uVar1 = (uint)chain;
  if (*DAT_0002d120 < 0xe) {
    chain = (uchar)(uVar1 / 3);
    if ((uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) & 0xff)
        == 0) goto LAB_0002d11c;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002d11c:
    dsPIC33EP16GS202_pic_heart_beat(chain);
    return;
  }
  return;
}

