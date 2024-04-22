
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  uchar *puVar4;
  byte *pbVar5;
  int iVar6;
  byte *name;
  EVP_CIPHER *pEVar7;
  uchar *puVar8;
  uint uVar9;
  EVP_CIPHER *pEVar10;
  uint uVar11;
  uchar *puVar12;
  byte *pbVar13;
  uint uVar14;
  char cVar15;
  int iVar16;
  EVP_CIPHER *__s1;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  
  cipher->cipher = (EVP_CIPHER *)0x0;
  if (header == (char *)0x0) {
    return 1;
  }
  if (*header == '\0') {
    return 1;
  }
  if (*header == '\n') {
    return 1;
  }
  iVar6 = strncmp(header,DAT_000bdf48,0xb);
  if (iVar6 != 0) {
    ERR_put_error(9,0x6b,0x6b,DAT_000bdf54,499);
    return 0;
  }
  if (header[0xb] != '4') {
    return 0;
  }
  if (header[0xc] != ',') {
    return 0;
  }
  __s1 = (EVP_CIPHER *)(header + 0xd);
  iVar6 = strncmp((char *)__s1,DAT_000bdf4c,9);
  if (iVar6 != 0) {
    ERR_put_error(9,0x6b,0x6a,DAT_000bdf54,0x1fe);
    return 0;
  }
  cVar15 = header[0xd];
  if (cVar15 != '\n' && cVar15 != '\0') {
    do {
      __s1 = (EVP_CIPHER *)((int)&__s1->nid + 1);
      cVar15 = *(char *)&__s1->nid;
    } while (cVar15 != '\0' && cVar15 != '\n');
  }
  if (cVar15 == '\0') {
    ERR_put_error(9,0x6b,0x70,DAT_000bdf54,0x203);
    return 0;
  }
  iVar6 = strncmp((char *)((int)&__s1->nid + 1),DAT_000bdf50,10);
  if (iVar6 != 0) {
    ERR_put_error(9,0x6b,0x69,DAT_000bdf54,0x208);
    return 0;
  }
  name = (byte *)((int)&__s1->key_len + 3);
  pbVar5 = name;
  do {
    pbVar13 = pbVar5;
    bVar1 = *pbVar13;
    uVar14 = (uint)bVar1;
    bVar19 = 0x2c < uVar14;
    if (uVar14 != 0x2d) {
      bVar19 = 0x18 < uVar14 - 0x41;
    }
    pbVar5 = pbVar13 + 1;
  } while ((!bVar19 || (uVar14 == 0x2d || uVar14 - 0x41 == 0x19)) || (uVar14 - 0x30 < 10));
  uVar14 = 0;
  *pbVar13 = 0;
  pEVar7 = EVP_get_cipherbyname((char *)name);
  cipher->cipher = pEVar7;
  *pbVar13 = bVar1;
  if (pEVar7 == (EVP_CIPHER *)0x0) {
    ERR_put_error(9,0x6b,0x72,DAT_000bdf54,0x220);
    return 0;
  }
  uVar17 = pEVar7->iv_len;
  puVar8 = cipher->iv;
  if (0 < (int)uVar17) {
    pEVar7 = (EVP_CIPHER *)(uVar17 >> 2);
    bVar18 = pEVar7 == (EVP_CIPHER *)0x0;
    bVar2 = uVar17 < 3;
    bVar19 = uVar17 == 3;
    if ((bVar18 || !bVar2) && (!bVar18 && !bVar19)) {
      __s1 = (EVP_CIPHER *)0x0;
    }
    if (!bVar18 && bVar2 || (bVar18 || bVar19)) {
      __s1 = (EVP_CIPHER *)0x1;
    }
    if ((bVar18 || !bVar2) && (!bVar18 && !bVar19)) {
      pEVar10 = __s1;
      puVar12 = puVar8;
      if ((EVP_CIPHER *)0x8 < pEVar7) {
        puVar4 = cipher[1].iv + 0xc;
        do {
          puVar12 = puVar4;
          piVar3 = &pEVar10->key_len;
          pEVar10 = (EVP_CIPHER *)&pEVar10->key_len;
          HintPreloadData(puVar12 + 0x80);
          *(EVP_CIPHER **)(puVar12 + -0x20) = __s1;
          *(EVP_CIPHER **)(puVar12 + -0x1c) = __s1;
          *(EVP_CIPHER **)(puVar12 + -0x18) = __s1;
          *(EVP_CIPHER **)(puVar12 + -0x14) = __s1;
          *(EVP_CIPHER **)(puVar12 + -0x10) = __s1;
          *(EVP_CIPHER **)(puVar12 + -0xc) = __s1;
          *(EVP_CIPHER **)(puVar12 + -8) = __s1;
          ((EVP_CIPHER_INFO *)(puVar12 + -4))->cipher = __s1;
          puVar4 = puVar12 + 0x20;
        } while ((undefined *)((int)piVar3 + 1) < (undefined *)((int)&pEVar7[-1].ctrl + 1));
      }
      do {
        pEVar10 = (EVP_CIPHER *)((int)&pEVar10->nid + 1);
        *(undefined4 *)puVar12 = 0;
        puVar12 = puVar12 + 4;
      } while (pEVar10 < pEVar7);
      uVar14 = uVar17 & 0xfffffffc;
      if (uVar17 == (uVar17 & 0xfffffffc)) goto LAB_000bdd74;
    }
    uVar9 = uVar14 + 1;
    if ((int)uVar14 < (int)uVar17 && (int)(uVar14 + 1) < (int)(uVar17 - 0x1f)) {
      puVar12 = cipher->iv + uVar14;
      uVar11 = uVar14;
      do {
        puVar8[uVar11] = '\0';
        HintPreloadData(cipher[2].iv + uVar11);
        uVar14 = uVar11 + 0x20;
        puVar12[1] = '\0';
        uVar9 = uVar11 + 0x21;
        puVar12[2] = '\0';
        puVar12[3] = '\0';
        puVar12[4] = '\0';
        puVar12[5] = '\0';
        puVar12[6] = '\0';
        puVar12[7] = '\0';
        puVar12[8] = '\0';
        puVar12[9] = '\0';
        puVar12[10] = '\0';
        puVar12[0xb] = '\0';
        puVar12[0xc] = '\0';
        puVar12[0xd] = '\0';
        puVar12[0xe] = '\0';
        puVar12[0xf] = '\0';
        puVar12[0x10] = 0;
        puVar12[0x11] = 0;
        puVar12[0x12] = 0;
        puVar12[0x13] = 0;
        puVar12[0x14] = 0;
        puVar12[0x15] = 0;
        puVar12[0x16] = 0;
        puVar12[0x17] = 0;
        puVar12[0x18] = 0;
        puVar12[0x19] = 0;
        puVar12[0x1a] = 0;
        puVar12[0x1b] = 0;
        puVar12[0x1c] = 0;
        puVar12[0x1d] = 0;
        puVar12[0x1e] = 0;
        puVar12[0x1f] = 0;
        puVar12 = puVar12 + 0x20;
        uVar11 = uVar14;
      } while ((int)uVar9 < (int)(uVar17 - 0x1f));
    }
    do {
      uVar11 = uVar9;
      puVar8[uVar14] = '\0';
      uVar9 = uVar11 + 1;
      uVar14 = uVar11;
    } while ((int)uVar11 < (int)uVar17);
  }
LAB_000bdd74:
  if (0 < (int)(uVar17 * 2)) {
    uVar14 = 0;
    do {
      uVar11 = (uint)pbVar13[uVar14 + 1];
      uVar9 = uVar11 - 0x30;
      if (9 < (uVar9 & 0xff)) {
        uVar9 = uVar11 - 0x37;
        if ((5 < uVar11 - 0x41) && (uVar9 = uVar11 - 0x57, 5 < uVar11 - 0x61)) {
          ERR_put_error(9,0x65,0x67,DAT_000bdf54,0x23a);
          return 0;
        }
      }
      iVar6 = (int)uVar14 >> 1;
      if ((uVar14 & 1) == 0) {
        iVar16 = 4;
      }
      else {
        iVar16 = 0;
      }
      uVar14 = uVar14 + 1;
      puVar8[iVar6] = (byte)(uVar9 << iVar16) | puVar8[iVar6];
    } while (uVar14 != uVar17 * 2);
  }
  return 1;
}

