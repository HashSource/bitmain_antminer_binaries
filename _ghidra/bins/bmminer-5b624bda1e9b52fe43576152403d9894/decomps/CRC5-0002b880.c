
/* WARNING: Unknown calling convention */

uchar CRC5(uchar *ptr,uchar len)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  uchar uVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  
  if (len == '\0') {
    bVar7 = 1;
    bVar9 = 1;
    bVar11 = 1;
    bVar5 = 1;
  }
  else {
    cVar4 = '\0';
    uVar6 = '\0';
    uVar3 = 0x80;
    bVar1 = 1;
    bVar10 = 1;
    bVar11 = 1;
    bVar5 = 1;
    bVar2 = 1;
    do {
      bVar7 = bVar2;
      bVar2 = bVar5;
      bVar5 = bVar11;
      bVar9 = bVar1;
      cVar4 = cVar4 + '\x01';
      uVar6 = uVar6 + '\x01';
      uVar8 = *ptr & uVar3;
      uVar3 = uVar3 >> 1;
      if (uVar8 != 0) {
        bVar7 = bVar7 ^ 1;
      }
      if (cVar4 == '\b') {
        ptr = ptr + 1;
        cVar4 = '\0';
        uVar3 = 0x80;
      }
      bVar11 = bVar10 ^ bVar7;
      bVar1 = bVar7;
      bVar10 = bVar9;
    } while (uVar6 != len);
    if (bVar2 == 0) goto LAB_0002b8dc;
  }
  bVar2 = 0x10;
LAB_0002b8dc:
  if (bVar5 != 0) {
    bVar2 = bVar2 | 8;
  }
  if (bVar11 != 0) {
    bVar2 = bVar2 | 4;
  }
  if (bVar9 != 0) {
    bVar2 = bVar2 | 2;
  }
  if (bVar7 != 0) {
    bVar2 = bVar2 | 1;
  }
  return bVar2;
}

