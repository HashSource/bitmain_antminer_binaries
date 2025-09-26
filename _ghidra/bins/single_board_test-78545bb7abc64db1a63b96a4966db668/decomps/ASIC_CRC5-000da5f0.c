
/* WARNING: Unknown calling convention */

uint8_t ASIC_CRC5(uint8_t *pdata,uint32_t length)

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
  uint uVar13;
  
  if (length == 0) {
    bVar3 = true;
    bVar9 = 0x10;
    bVar4 = true;
    bVar5 = true;
  }
  else {
    cVar10 = '\0';
    uVar12 = 0;
    uVar13 = 0x80;
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
      uVar12 = uVar12 + 1 & 0xff;
      uVar11 = *pdata & uVar13;
      uVar13 = uVar13 >> 1;
      bVar3 = bVar2;
      if (uVar11 != 0) {
        bVar3 = (bool)(bVar2 ^ 1);
      }
      if (cVar10 == '\b') {
        pdata = pdata + 1;
        cVar10 = '\0';
        uVar13 = 0x80;
      }
      bVar4 = (bool)(bVar6 ^ bVar3);
      bVar8 = bVar7;
      bVar2 = bVar1;
      bVar6 = bVar5;
    } while (uVar12 < length);
    if (!bVar1) {
      pdata = (byte *)0x0;
    }
    bVar9 = (byte)pdata;
    if (bVar1) {
      bVar9 = 0x10;
    }
    if (!bVar7) goto LAB_000da652;
  }
  bVar9 = bVar9 | 8;
LAB_000da652:
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

