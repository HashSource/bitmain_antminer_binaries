
/* WARNING: Unknown calling convention */

int utf8_check_full(char *buffer,int size,int32_t *codepoint)

{
  uchar *u;
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = (uint)(byte)*buffer;
  if (size == 2) {
    uVar3 = uVar3 & 0x1f;
  }
  else if (size == 3) {
    uVar3 = uVar3 & 0xf;
  }
  else {
    if (size != 4) {
      return 0;
    }
    uVar3 = uVar3 & 7;
  }
  uVar2 = (uint)(byte)buffer[1];
  if ((uVar2 ^ 0x80) < 0x40) {
    iVar1 = 1;
    do {
      iVar1 = iVar1 + 1;
      uVar3 = (uVar2 & 0x3f) + uVar3 * 0x40;
      if (size <= iVar1) {
        if (0x10ffff < (int)uVar3) {
          return 0;
        }
        if (uVar3 - 0xd800 < 0x800) {
          return 0;
        }
        bVar4 = uVar3 == 0x7f;
        if ((int)uVar3 < 0x80) {
          bVar4 = size == 2;
        }
        if (bVar4) {
          return 0;
        }
        bVar4 = uVar3 == 0x7ff;
        if ((int)uVar3 < 0x800) {
          bVar4 = size == 3;
        }
        if (!bVar4) {
          if (size == 4 && (int)uVar3 < 0x10000) {
            return 0;
          }
          if (codepoint == (int32_t *)0x0) {
            return 1;
          }
          *codepoint = uVar3;
          return 1;
        }
        return 0;
      }
      uVar2 = (uint)(byte)buffer[iVar1];
    } while ((uVar2 ^ 0x80) < 0x40);
  }
  return 0;
}

