
/* WARNING: Unknown calling convention */

size_t utf8_check_first(char byte)

{
  uint uVar1;
  size_t sVar2;
  
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
      sVar2 = 4;
    }
    else {
      sVar2 = 0;
    }
    return sVar2;
  }
  return 3;
}

