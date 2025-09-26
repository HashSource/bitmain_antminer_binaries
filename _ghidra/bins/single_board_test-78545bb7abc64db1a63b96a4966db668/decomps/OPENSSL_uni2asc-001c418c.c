
char * OPENSSL_uni2asc(uchar *uni,int unilen)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int num;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (-1 < unilen << 0x1f) {
    num = unilen / 2;
    if ((unilen == 0) || (uni[unilen + -1] != '\0')) {
      num = num + 1;
    }
    pcVar1 = (char *)CRYPTO_malloc(num,"crypto/pkcs12/p12_utl.c",0x37);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x23,0x7c,0x41,"crypto/pkcs12/p12_utl.c",0x38);
    }
    else {
      if (0 < unilen) {
        if (unilen < 0x21) {
          iVar5 = 0;
        }
        else {
          iVar5 = 0;
          puVar4 = uni + 0x2f;
          do {
            HintPreloadData(puVar4);
            pcVar1[iVar5 >> 1] = puVar4[-0x2e];
            pcVar1[iVar5 + 2 >> 1] = puVar4[-0x2c];
            pcVar1[iVar5 + 4 >> 1] = puVar4[-0x2a];
            pcVar1[iVar5 + 6 >> 1] = puVar4[-0x28];
            pcVar1[iVar5 + 8 >> 1] = puVar4[-0x26];
            iVar7 = iVar5 + 0x14;
            pcVar1[iVar5 + 10 >> 1] = puVar4[-0x24];
            iVar6 = iVar5 + 0x16;
            pcVar1[iVar5 + 0xc >> 1] = puVar4[-0x22];
            iVar8 = iVar5 + 0x18;
            pcVar1[iVar5 + 0xe >> 1] = puVar4[-0x20];
            iVar9 = iVar5 + 0x1a;
            pcVar1[iVar5 + 0x10 >> 1] = puVar4[-0x1e];
            iVar2 = iVar5 + 0x1c;
            pcVar1[iVar5 + 0x12 >> 1] = puVar4[-0x1c];
            iVar3 = iVar5 + 0x1e;
            iVar5 = iVar5 + 0x20;
            pcVar1[iVar7 >> 1] = puVar4[-0x1a];
            pcVar1[iVar6 >> 1] = puVar4[-0x18];
            pcVar1[iVar8 >> 1] = puVar4[-0x16];
            pcVar1[iVar9 >> 1] = puVar4[-0x14];
            pcVar1[iVar2 >> 1] = puVar4[-0x12];
            pcVar1[iVar3 >> 1] = puVar4[-0x10];
            puVar4 = puVar4 + 0x20;
          } while (iVar5 != (unilen - 0x21U & 0xffffffe0) + 0x20);
        }
        do {
          iVar3 = iVar5 >> 1;
          iVar2 = iVar5 + 1;
          iVar5 = iVar5 + 2;
          pcVar1[iVar3] = uni[iVar2];
        } while (iVar5 < unilen);
      }
      pcVar1[num + -1] = '\0';
    }
    return pcVar1;
  }
  return (char *)0x0;
}

