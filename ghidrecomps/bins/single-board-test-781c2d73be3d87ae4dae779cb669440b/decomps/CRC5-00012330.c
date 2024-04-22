
/* WARNING: Unknown calling convention */

uchar CRC5(uchar *ptr,uchar len)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  
  if (len == '\0') {
    bVar3 = true;
    bVar9 = 0x10;
    bVar4 = true;
    bVar5 = true;
  }
  else {
    bVar9 = 0;
    cVar10 = '\0';
    uVar12 = 0x80;
    bVar8 = true;
    bVar2 = true;
    bVar3 = true;
    bVar6 = true;
    bVar4 = true;
    do {
      bVar7 = bVar4;
      bVar5 = bVar3;
      bVar1 = bVar8;
      cVar10 = cVar10 + '\x01';
      bVar9 = bVar9 + 1;
      uVar11 = *ptr & uVar12;
      uVar12 = uVar12 >> 1;
      bVar3 = bVar2;
      if (uVar11 != 0) {
        bVar3 = (bool)(bVar2 ^ 1);
      }
      if (cVar10 == '\b') {
        ptr = ptr + 1;
        cVar10 = '\0';
        uVar12 = 0x80;
      }
      bVar4 = (bool)(bVar3 ^ bVar6);
      bVar8 = bVar7;
      bVar2 = bVar1;
      bVar6 = bVar5;
    } while (bVar9 < len);
    if (bVar1) {
      ptr = (byte *)0x10;
    }
    bVar9 = (byte)ptr;
    if (!bVar1) {
      bVar9 = 0;
    }
    if (!bVar7) goto LAB_00012396;
  }
  bVar9 = bVar9 | 8;
LAB_00012396:
  if (bVar4) {
    bVar9 = bVar9 | 4;
  }
  if (bVar5) {
    bVar9 = bVar9 | 2;
  }
  if (bVar3) {
    bVar9 = bVar9 | 1;
  }
  return bVar9;
}

