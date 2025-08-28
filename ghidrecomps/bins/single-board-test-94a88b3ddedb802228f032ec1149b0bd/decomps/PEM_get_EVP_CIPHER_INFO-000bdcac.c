
int PEM_get_EVP_CIPHER_INFO(char *header,EVP_CIPHER_INFO *cipher)

{
  byte bVar1;
  uchar *puVar2;
  byte *pbVar3;
  int iVar4;
  EVP_CIPHER *pEVar5;
  uchar *puVar6;
  uchar *puVar7;
  byte *pbVar8;
  uint uVar9;
  char cVar10;
  int iVar11;
  char *__s1;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  
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
  iVar4 = strncmp(header,"Proc-Type: ",0xb);
  if (iVar4 != 0) {
    ERR_put_error(9,0x6b,0x6b,"pem_lib.c",499);
    return 0;
  }
  if (header[0xb] != '4') {
    return 0;
  }
  if (header[0xc] != ',') {
    return 0;
  }
  __s1 = header + 0xd;
  iVar4 = strncmp(__s1,"ENCRYPTED",9);
  if (iVar4 != 0) {
    ERR_put_error(9,0x6b,0x6a,"pem_lib.c",0x1fe);
    return 0;
  }
  cVar10 = header[0xd];
  if (cVar10 != '\n' && cVar10 != '\0') {
    do {
      __s1 = __s1 + 1;
      cVar10 = *__s1;
    } while (cVar10 != '\0' && cVar10 != '\n');
  }
  if (cVar10 == '\0') {
    ERR_put_error(9,0x6b,0x70,"pem_lib.c",0x203);
    return 0;
  }
  iVar4 = strncmp(__s1 + 1,"DEK-Info: ",10);
  if (iVar4 != 0) {
    ERR_put_error(9,0x6b,0x69,"pem_lib.c",0x208);
    return 0;
  }
  pbVar3 = (byte *)(__s1 + 0xb);
  do {
    pbVar8 = pbVar3;
    bVar1 = *pbVar8;
    uVar9 = (uint)bVar1;
    bVar15 = 0x2c < uVar9;
    if (uVar9 != 0x2d) {
      bVar15 = 0x18 < uVar9 - 0x41;
    }
    pbVar3 = pbVar8 + 1;
  } while ((!bVar15 || (uVar9 == 0x2d || uVar9 - 0x41 == 0x19)) || (uVar9 - 0x30 < 10));
  uVar9 = 0;
  *pbVar8 = 0;
  pEVar5 = EVP_get_cipherbyname(__s1 + 0xb);
  cipher->cipher = pEVar5;
  *pbVar8 = bVar1;
  if (pEVar5 == (EVP_CIPHER *)0x0) {
    ERR_put_error(9,0x6b,0x72,"pem_lib.c",0x220);
    return 0;
  }
  uVar14 = pEVar5->iv_len;
  puVar6 = cipher->iv;
  if (0 < (int)uVar14) {
    uVar12 = uVar14 >> 2;
    if (uVar12 != 0 && 3 < uVar14) {
      uVar9 = 0;
      puVar7 = puVar6;
      if (8 < uVar12) {
        puVar2 = cipher[1].iv + 0xc;
        do {
          puVar7 = puVar2;
          uVar13 = uVar9 + 9;
          uVar9 = uVar9 + 8;
          HintPreloadData(puVar7 + 0x80);
          *(undefined4 *)(puVar7 + -0x20) = 0;
          *(undefined4 *)(puVar7 + -0x1c) = 0;
          *(undefined4 *)(puVar7 + -0x18) = 0;
          *(undefined4 *)(puVar7 + -0x14) = 0;
          *(undefined4 *)(puVar7 + -0x10) = 0;
          *(undefined4 *)(puVar7 + -0xc) = 0;
          *(undefined4 *)(puVar7 + -8) = 0;
          ((EVP_CIPHER_INFO *)(puVar7 + -4))->cipher = (EVP_CIPHER *)0x0;
          puVar2 = puVar7 + 0x20;
        } while (uVar13 < uVar12 - 7);
      }
      do {
        uVar9 = uVar9 + 1;
        puVar7[0] = '\0';
        puVar7[1] = '\0';
        puVar7[2] = '\0';
        puVar7[3] = '\0';
        puVar7 = puVar7 + 4;
      } while (uVar9 < uVar12);
      uVar9 = uVar12 << 2;
      if (uVar14 == uVar12 << 2) goto LAB_000bdd74;
    }
    uVar12 = uVar9 + 1;
    if ((int)uVar9 < (int)uVar14 && (int)(uVar9 + 1) < (int)(uVar14 - 0x1f)) {
      puVar7 = cipher->iv + uVar9;
      uVar13 = uVar9;
      do {
        puVar6[uVar13] = '\0';
        HintPreloadData(cipher[2].iv + uVar13);
        uVar9 = uVar13 + 0x20;
        puVar7[1] = '\0';
        uVar12 = uVar13 + 0x21;
        puVar7[2] = '\0';
        puVar7[3] = '\0';
        puVar7[4] = '\0';
        puVar7[5] = '\0';
        puVar7[6] = '\0';
        puVar7[7] = '\0';
        puVar7[8] = '\0';
        puVar7[9] = '\0';
        puVar7[10] = '\0';
        puVar7[0xb] = '\0';
        puVar7[0xc] = '\0';
        puVar7[0xd] = '\0';
        puVar7[0xe] = '\0';
        puVar7[0xf] = '\0';
        puVar7[0x10] = 0;
        puVar7[0x11] = 0;
        puVar7[0x12] = 0;
        puVar7[0x13] = 0;
        puVar7[0x14] = 0;
        puVar7[0x15] = 0;
        puVar7[0x16] = 0;
        puVar7[0x17] = 0;
        puVar7[0x18] = 0;
        puVar7[0x19] = 0;
        puVar7[0x1a] = 0;
        puVar7[0x1b] = 0;
        puVar7[0x1c] = 0;
        puVar7[0x1d] = 0;
        puVar7[0x1e] = 0;
        puVar7[0x1f] = 0;
        puVar7 = puVar7 + 0x20;
        uVar13 = uVar9;
      } while ((int)uVar12 < (int)(uVar14 - 0x1f));
    }
    do {
      uVar13 = uVar12;
      puVar6[uVar9] = '\0';
      uVar12 = uVar13 + 1;
      uVar9 = uVar13;
    } while ((int)uVar13 < (int)uVar14);
  }
LAB_000bdd74:
  if (0 < (int)(uVar14 * 2)) {
    uVar9 = 0;
    do {
      uVar13 = (uint)pbVar8[uVar9 + 1];
      uVar12 = uVar13 - 0x30;
      if (9 < (uVar12 & 0xff)) {
        uVar12 = uVar13 - 0x37;
        if ((5 < uVar13 - 0x41) && (uVar12 = uVar13 - 0x57, 5 < uVar13 - 0x61)) {
          ERR_put_error(9,0x65,0x67,"pem_lib.c",0x23a);
          return 0;
        }
      }
      iVar4 = (int)uVar9 >> 1;
      if ((uVar9 & 1) == 0) {
        iVar11 = 4;
      }
      else {
        iVar11 = 0;
      }
      uVar9 = uVar9 + 1;
      puVar6[iVar4] = (byte)(uVar12 << iVar11) | puVar6[iVar4];
    } while (uVar9 != uVar14 * 2);
  }
  return 1;
}

