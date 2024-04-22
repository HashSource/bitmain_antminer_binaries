
/* WARNING: Unknown calling convention */
/* Local variable u:uchar[r0:1] conflicts with parameter, skipped. */

int utf8_check_first(char byte)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)byte;
  if (-1 < (int)(uVar1 << 0x18)) {
    return 1;
  }
  if (((uVar1 ^ 0x80) < 0x40) || ((uVar1 + 0x40 & 0xff) < 2)) {
    return 0;
  }
  if ((uVar1 + 0x3e & 0xff) < 0x1e) {
    return 2;
  }
  if (0xf < (uVar1 + 0x20 & 0xff)) {
    if ((uVar1 + 0x10 & 0xff) < 5) {
      iVar2 = 4;
    }
    else {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 3;
}

