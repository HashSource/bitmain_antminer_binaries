
int CRYPTO_memcmp(void *a,void *b,size_t len)

{
  byte *pbVar1;
  byte *pbVar2;
  void *pvVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar11;
  uint uVar12;
  void *pvVar10;
  
  if (len == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = len >> 2;
    sVar4 = uVar7 * 4;
    if (uVar7 == 0 || (len < 4 || (((uint)b | (uint)a) & 3) != 0)) {
      sVar4 = 0;
      uVar7 = sVar4;
    }
    else {
      if (uVar7 < 9) {
        uVar5 = 0;
        uVar6 = 0;
        pvVar10 = a;
        puVar11 = (uint *)b;
      }
      else {
        uVar6 = 0;
        pvVar3 = (void *)((int)a + 0x20);
        puVar9 = (uint *)((int)b + 0x20);
        uVar12 = 0;
        do {
          puVar11 = puVar9;
          pvVar10 = pvVar3;
          uVar5 = uVar12 + 8;
          uVar8 = uVar12 + 9;
          HintPreloadData((int)pvVar10 + 0x3c);
          uVar6 = puVar11[-8] ^ *(uint *)((int)pvVar10 + -0x20) | uVar6 |
                  puVar11[-7] ^ *(uint *)((int)pvVar10 + -0x1c) |
                  *(uint *)((int)pvVar10 + -0x18) ^ puVar11[-6] |
                  *(uint *)((int)pvVar10 + -0x14) ^ puVar11[-5] |
                  *(uint *)((int)pvVar10 + -0x10) ^ puVar11[-4] |
                  *(uint *)((int)pvVar10 + -0xc) ^ puVar11[-3] |
                  *(uint *)((int)pvVar10 + -8) ^ puVar11[-2] |
                  *(uint *)((int)pvVar10 + -4) ^ puVar11[-1];
          pvVar3 = (void *)((int)pvVar10 + 0x20);
          puVar9 = puVar11 + 8;
          uVar12 = uVar5;
        } while (uVar8 < uVar7 - 7);
      }
      puVar9 = (uint *)((int)pvVar10 + -4);
      do {
        uVar5 = uVar5 + 1;
        puVar9 = puVar9 + 1;
        uVar6 = *puVar11 ^ *puVar9 | uVar6;
        puVar11 = puVar11 + 1;
      } while (uVar5 < uVar7);
      uVar7 = (uVar6 | uVar6 >> 8 | uVar6 >> 0x10) & 0xff | uVar6 >> 0x18;
      if (len == sVar4) {
        return uVar7;
      }
    }
    do {
      pbVar1 = (byte *)((int)b + sVar4);
      pbVar2 = (byte *)((int)a + sVar4);
      sVar4 = sVar4 + 1;
      uVar7 = uVar7 | *pbVar1 ^ *pbVar2;
    } while (sVar4 < len);
  }
  return uVar7;
}

