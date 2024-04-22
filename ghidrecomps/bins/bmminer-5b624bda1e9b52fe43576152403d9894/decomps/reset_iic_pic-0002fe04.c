
/* WARNING: Unknown calling convention */

uchar reset_iic_pic(uchar chain)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)chain;
  if (*DAT_0002fe3c < 0xe) {
    chain = (uchar)(uVar1 / 3);
    if ((uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) & 0xff)
        == 0) goto LAB_0002fe34;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002fe34:
    iVar2 = dsPIC33EP16GS202_reset_pic(chain);
    return (uchar)iVar2;
  }
  return '\x01';
}

