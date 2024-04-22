
/* WARNING: Unknown calling convention */

void b58tobin(uchar *b58bin,char *b58)

{
  longlong lVar1;
  size_t sVar2;
  int len;
  uint *puVar3;
  uchar *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  size_t sVar8;
  uint bin32 [7];
  
  uVar6 = 0;
  bin32[0] = 0;
  bin32[1] = 0;
  bin32[2] = 0;
  bin32[3] = 0;
  bin32[4] = 0;
  bin32[5] = 0;
  bin32[6] = 0;
  sVar2 = strlen(b58);
  uVar5 = uVar6;
  if (0 < (int)sVar2) {
    sVar8 = 0;
    do {
      iVar7 = 6;
      uVar5 = *(uint *)(DAT_0001124c + (uint)(byte)b58[sVar8] * 4 + 0x46c);
      puVar3 = bin32;
      while( true ) {
        lVar1 = (ulonglong)uVar6 * 0x3a + (ulonglong)uVar5;
        iVar7 = iVar7 + -1;
        uVar5 = (uint)((ulonglong)lVar1 >> 0x20) & 0x3f;
        puVar3[6] = (uint)lVar1;
        if (iVar7 == -1) break;
        uVar6 = puVar3[5];
        puVar3 = puVar3 + -1;
      }
      sVar8 = sVar8 + 1;
      uVar6 = bin32[6];
    } while (sVar2 != sVar8);
    uVar6 = bin32[1] << 0x18 | (bin32[1] >> 8 & 0xff) << 0x10 | (bin32[1] >> 0x10 & 0xff) << 8 |
            bin32[1] >> 0x18;
    uVar5 = bin32[0] & 0xff;
  }
  puVar3 = bin32 + 1;
  puVar4 = b58bin + 5;
  *b58bin = (uchar)uVar5;
  while( true ) {
    *(uint *)(puVar4 + -4) = uVar6;
    puVar4 = puVar4 + 4;
    if (puVar4 == b58bin + 0x1d) break;
    puVar3 = puVar3 + 1;
    uVar5 = *puVar3;
    uVar6 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18;
  }
  return;
}

