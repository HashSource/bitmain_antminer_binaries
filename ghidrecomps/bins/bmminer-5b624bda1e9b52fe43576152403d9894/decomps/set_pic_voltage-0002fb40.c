
/* WARNING: Unknown calling convention */

void set_pic_voltage(uchar chain,uchar voltage)

{
  uint uVar1;
  
  uVar1 = (uint)chain;
  if (*DAT_0002fb70 < 0xe) {
    if ((uVar1 - (uVar1 / 3 + ((uint)((ulonglong)uVar1 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) & 0xff)
        == 0) goto LAB_0002fb6a;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002fb6a:
    set_pic_voltage_T9_18(chain);
    return;
  }
  return;
}

