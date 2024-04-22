
uint CRC5(byte *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  
  if (param_2 == 0) {
    bVar3 = true;
    uVar11 = 0x10;
    bVar4 = true;
    bVar5 = true;
  }
  else {
    bVar12 = 0;
    cVar9 = '\0';
    uVar11 = 0x80;
    bVar8 = true;
    bVar2 = true;
    bVar3 = true;
    bVar6 = true;
    bVar4 = true;
    do {
      bVar7 = bVar4;
      bVar5 = bVar3;
      bVar1 = bVar8;
      cVar9 = cVar9 + '\x01';
      bVar12 = bVar12 + 1;
      uVar10 = *param_1 & uVar11;
      uVar11 = uVar11 >> 1;
      bVar3 = bVar2;
      if (uVar10 != 0) {
        bVar3 = (bool)(bVar2 ^ 1);
      }
      if (cVar9 == '\b') {
        param_1 = param_1 + 1;
        cVar9 = '\0';
        uVar11 = 0x80;
      }
      bVar4 = (bool)(bVar3 ^ bVar6);
      bVar8 = bVar7;
      bVar2 = bVar1;
      bVar6 = bVar5;
    } while (bVar12 < param_2);
    if (bVar1) {
      uVar11 = 0x10;
    }
    else {
      uVar11 = 0;
    }
    if (!bVar7) goto LAB_0002e37a;
  }
  uVar11 = uVar11 | 8;
LAB_0002e37a:
  if (bVar4) {
    uVar11 = uVar11 | 4;
  }
  if (bVar5) {
    uVar11 = uVar11 | 2;
  }
  if (bVar3) {
    uVar11 = uVar11 | 1;
  }
  return uVar11;
}

