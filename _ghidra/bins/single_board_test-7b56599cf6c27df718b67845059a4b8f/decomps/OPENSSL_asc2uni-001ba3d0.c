
uchar * OPENSSL_asc2uni(char *asc,int asclen,uchar **uni,int *unilen)

{
  uchar uVar1;
  uchar *puVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int num;
  int iVar6;
  int iVar7;
  
  if (asclen == -1) {
    asclen = strlen(asc);
  }
  num = (asclen + 1U) * 2;
  puVar2 = (uchar *)CRYPTO_malloc(num,"crypto/pkcs12/p12_utl.c",0x19);
  if (puVar2 == (uchar *)0x0) {
    ERR_put_error(0x23,0x79,0x41,"crypto/pkcs12/p12_utl.c",0x1a);
  }
  else {
    if (0 < num + -2) {
      if (num < 0x23) {
        iVar3 = 0;
      }
      else {
        iVar3 = 0;
        puVar4 = puVar2 + 0x27;
        do {
          puVar4[-0x27] = '\0';
          HintPreloadData(puVar4);
          uVar1 = asc[iVar3 >> 1];
          puVar4[-0x25] = '\0';
          puVar4[-0x26] = uVar1;
          uVar1 = asc[iVar3 + 2 >> 1];
          puVar4[-0x23] = '\0';
          puVar4[-0x24] = uVar1;
          uVar1 = asc[iVar3 + 4 >> 1];
          puVar4[-0x21] = '\0';
          puVar4[-0x22] = uVar1;
          uVar1 = asc[iVar3 + 6 >> 1];
          puVar4[-0x1f] = '\0';
          puVar4[-0x20] = uVar1;
          uVar1 = asc[iVar3 + 8 >> 1];
          puVar4[-0x1d] = '\0';
          puVar4[-0x1e] = uVar1;
          uVar1 = asc[iVar3 + 10 >> 1];
          puVar4[-0x1b] = '\0';
          puVar4[-0x1c] = uVar1;
          uVar1 = asc[iVar3 + 0xc >> 1];
          puVar4[-0x19] = '\0';
          puVar4[-0x1a] = uVar1;
          uVar1 = asc[iVar3 + 0xe >> 1];
          puVar4[-0x17] = '\0';
          puVar4[-0x18] = uVar1;
          uVar1 = asc[iVar3 + 0x10 >> 1];
          puVar4[-0x15] = '\0';
          puVar4[-0x16] = uVar1;
          uVar1 = asc[iVar3 + 0x12 >> 1];
          puVar4[-0x13] = '\0';
          puVar4[-0x14] = uVar1;
          uVar1 = asc[iVar3 + 0x14 >> 1];
          iVar6 = iVar3 + 0x1a;
          puVar4[-0x11] = '\0';
          puVar4[-0x12] = uVar1;
          uVar1 = asc[iVar3 + 0x16 >> 1];
          iVar7 = iVar3 + 0x1c;
          puVar4[-0xf] = '\0';
          puVar4[-0x10] = uVar1;
          uVar1 = asc[iVar3 + 0x18 >> 1];
          iVar5 = iVar3 + 0x1e;
          puVar4[-0xd] = '\0';
          iVar3 = iVar3 + 0x20;
          puVar4[-0xe] = uVar1;
          uVar1 = asc[iVar6 >> 1];
          puVar4[-0xb] = '\0';
          puVar4[-0xc] = uVar1;
          uVar1 = asc[iVar7 >> 1];
          puVar4[-9] = '\0';
          puVar4[-10] = uVar1;
          puVar4[-8] = asc[iVar5 >> 1];
          puVar4 = puVar4 + 0x20;
        } while (iVar3 != (num - 0x23U & 0xffffffe0) + 0x20);
      }
      do {
        puVar2[iVar3] = '\0';
        iVar5 = iVar3 + 2;
        puVar2[iVar3 + 1] = asc[iVar3 >> 1];
        iVar3 = iVar5;
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

