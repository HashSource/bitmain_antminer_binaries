
uchar * OPENSSL_asc2uni(char *asc,int asclen,uchar **uni,int *unilen)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int num;
  int iVar7;
  
  if (asclen == -1) {
    asclen = strlen(asc);
  }
  num = (asclen + 1U) * 2;
  puVar2 = (uchar *)CRYPTO_malloc(num,DAT_000d22bc,0x4a);
  if (puVar2 != (uchar *)0x0) {
    if (0 < num + -2) {
      if (num < 0x23) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        puVar3 = puVar2;
        do {
          puVar2[iVar4] = '\0';
          uVar1 = asc[iVar4 >> 1];
          puVar3[2] = '\0';
          HintPreloadData(puVar2 + iVar4 + 0x27);
          puVar3[1] = uVar1;
          uVar1 = asc[iVar4 + 2 >> 1];
          puVar3[4] = '\0';
          puVar3[3] = uVar1;
          uVar1 = asc[iVar4 + 4 >> 1];
          puVar3[6] = '\0';
          puVar3[5] = uVar1;
          uVar1 = asc[iVar4 + 6 >> 1];
          puVar3[8] = '\0';
          puVar3[7] = uVar1;
          uVar1 = asc[iVar4 + 8 >> 1];
          puVar3[10] = '\0';
          puVar3[9] = uVar1;
          uVar1 = asc[iVar4 + 10 >> 1];
          puVar3[0xc] = '\0';
          puVar3[0xb] = uVar1;
          uVar1 = asc[iVar4 + 0xc >> 1];
          puVar3[0xe] = '\0';
          puVar3[0xd] = uVar1;
          uVar1 = asc[iVar4 + 0xe >> 1];
          puVar3[0x10] = '\0';
          puVar3[0xf] = uVar1;
          uVar1 = asc[iVar4 + 0x10 >> 1];
          puVar3[0x12] = '\0';
          puVar3[0x11] = uVar1;
          uVar1 = asc[iVar4 + 0x12 >> 1];
          puVar3[0x14] = '\0';
          puVar3[0x13] = uVar1;
          iVar7 = iVar4 + 0x1a;
          puVar3[0x15] = asc[iVar4 + 0x14 >> 1];
          puVar3[0x16] = '\0';
          uVar1 = asc[iVar4 + 0x16 >> 1];
          iVar6 = iVar4 + 0x1c;
          puVar3[0x18] = '\0';
          puVar3[0x17] = uVar1;
          uVar1 = asc[iVar4 + 0x18 >> 1];
          iVar5 = iVar4 + 0x1e;
          puVar3[0x1a] = '\0';
          iVar4 = iVar4 + 0x20;
          puVar3[0x19] = uVar1;
          uVar1 = asc[iVar7 >> 1];
          puVar3[0x1c] = '\0';
          puVar3[0x1b] = uVar1;
          uVar1 = asc[iVar6 >> 1];
          puVar3[0x1e] = '\0';
          puVar3[0x1d] = uVar1;
          puVar3[0x1f] = asc[iVar5 >> 1];
          puVar3 = puVar3 + 0x20;
        } while (iVar4 != (num - 0x23U & 0xffffffe0) + 0x20);
      }
      do {
        puVar2[iVar4] = '\0';
        iVar5 = iVar4 + 2;
        puVar2[iVar4 + 1] = asc[iVar4 >> 1];
        iVar4 = iVar5;
      } while (iVar5 < num + -2);
    }
    puVar2[num + -2] = '\0';
    puVar2[num + -1] = '\0';
    if (unilen != (int *)0x0) {
      *unilen = num;
    }
    if (uni != (uchar **)0x0) {
      *uni = puVar2;
    }
  }
  return puVar2;
}

