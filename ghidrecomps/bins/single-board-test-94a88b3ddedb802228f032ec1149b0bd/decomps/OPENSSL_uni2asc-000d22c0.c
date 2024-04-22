
char * OPENSSL_uni2asc(uchar *uni,int unilen)

{
  uchar *puVar1;
  char *pcVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_30;
  
  local_30 = unilen / 2;
  if ((unilen == 0) || (uni[unilen + -1] != '\0')) {
    local_30 = local_30 + 1;
  }
  pcVar2 = (char *)CRYPTO_malloc(local_30,DAT_000d2414,99);
  if (pcVar2 != (char *)0x0) {
    if (0 < unilen) {
      if (unilen < 0x21) {
        iVar5 = 0;
      }
      else {
        iVar5 = 0;
        puVar4 = uni;
        do {
          pcVar2[iVar5 >> 1] = puVar4[1];
          pcVar2[iVar5 + 2 >> 1] = puVar4[3];
          HintPreloadData(uni + iVar5 + 0x33);
          pcVar2[iVar5 + 4 >> 1] = puVar4[5];
          pcVar2[iVar5 + 6 >> 1] = puVar4[7];
          pcVar2[iVar5 + 8 >> 1] = puVar4[9];
          iVar9 = iVar5 + 0x14;
          pcVar2[iVar5 + 10 >> 1] = puVar4[0xb];
          iVar10 = iVar5 + 0x16;
          pcVar2[iVar5 + 0xc >> 1] = puVar4[0xd];
          iVar8 = iVar5 + 0x18;
          pcVar2[iVar5 + 0xe >> 1] = puVar4[0xf];
          iVar7 = iVar5 + 0x1a;
          pcVar2[iVar5 + 0x10 >> 1] = puVar4[0x11];
          iVar6 = iVar5 + 0x1c;
          pcVar2[iVar5 + 0x12 >> 1] = puVar4[0x13];
          iVar3 = iVar5 + 0x1e;
          iVar5 = iVar5 + 0x20;
          pcVar2[iVar9 >> 1] = puVar4[0x15];
          pcVar2[iVar10 >> 1] = puVar4[0x17];
          pcVar2[iVar8 >> 1] = puVar4[0x19];
          pcVar2[iVar7 >> 1] = puVar4[0x1b];
          pcVar2[iVar6 >> 1] = puVar4[0x1d];
          puVar1 = puVar4 + 0x1f;
          puVar4 = puVar4 + 0x20;
          pcVar2[iVar3 >> 1] = *puVar1;
        } while (iVar5 != (unilen - 0x21U & 0xffffffe0) + 0x20);
      }
      do {
        iVar6 = iVar5 >> 1;
        iVar3 = iVar5 + 1;
        iVar5 = iVar5 + 2;
        pcVar2[iVar6] = uni[iVar3];
      } while (iVar5 < unilen);
    }
    pcVar2[local_30 + -1] = '\0';
  }
  return pcVar2;
}

