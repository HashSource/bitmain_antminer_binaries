
/* WARNING: Type propagation algorithm not settling */

undefined4
RSA_padding_add_PKCS1_OAEP_mgf1
          (undefined *param_1,int param_2,void *param_3,size_t param_4,void *param_5,size_t param_6,
          EVP_MD *param_7,EVP_MD *param_8)

{
  byte *pbVar1;
  byte *pbVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint num;
  int iVar6;
  uint *mask;
  uint uVar7;
  byte *pbVar8;
  uchar *buf;
  uint uVar9;
  uint uVar10;
  uchar *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint local_68 [17];
  
  param_2 = param_2 + -1;
  if (param_7 == (EVP_MD *)0x0) {
    param_7 = EVP_sha1();
  }
  if (param_8 == (EVP_MD *)0x0) {
    param_8 = param_7;
  }
  num = EVP_MD_size(param_7);
  if ((int)(num * -2 + param_2) <= (int)param_4) {
    ERR_put_error(4,0xa0,0x6e,DAT_000fc464,0x3a);
    return 0;
  }
  if (param_2 == num * 2 || (int)(param_2 + num * -2) < 0 != SBORROW4(param_2,num * 2)) {
    ERR_put_error(4,0xa0,0x78,DAT_000fc464,0x40);
    return 0;
  }
  puVar11 = param_1 + num + 1;
  *param_1 = 0;
  iVar6 = EVP_Digest(param_5,param_6,puVar11,(uint *)0x0,param_7,(ENGINE *)0x0);
  if (iVar6 == 0) {
    return 0;
  }
  buf = param_1 + 1;
  memset(puVar11 + num,0,(num * -2 + (param_2 - param_4)) - 1);
  (puVar11 + ((param_2 - param_4) - num))[-1] = '\x01';
  memcpy(puVar11 + ((param_2 - param_4) - num),param_3,param_4);
  iVar6 = RAND_bytes(buf,num);
  if (iVar6 < 1) {
    return 0;
  }
  uVar10 = param_2 - num;
  mask = (uint *)CRYPTO_malloc(uVar10,DAT_000fc464,0x55);
  if (mask == (uint *)0x0) {
    ERR_put_error(4,0xa0,0x41,DAT_000fc490,0x57);
    return 0;
  }
  iVar6 = PKCS1_MGF1((uchar *)mask,uVar10,buf,num,param_8);
  if (iVar6 < 0) {
    return 0;
  }
  if (0 < (int)uVar10) {
    uVar7 = uVar10 >> 2;
    puVar13 = (uint *)(param_1 + num + 1);
    uVar15 = 0;
    if (uVar7 != 0 &&
        ((((uint)puVar13 | (uint)mask) & 3) == 0 &&
        (3 < uVar10 && (param_1 + num + 5 <= mask || mask + 1 <= puVar13)))) {
      if (uVar7 < 9) {
        uVar15 = 0;
        puVar12 = mask;
        puVar14 = puVar13;
      }
      else {
        uVar15 = 0;
        puVar4 = (uint *)(param_1 + num + 0x21);
        puVar5 = (uint *)(param_1 + num + 0x21);
        puVar3 = mask;
        do {
          puVar14 = puVar5;
          puVar13 = puVar4;
          puVar12 = puVar3 + 8;
          uVar9 = uVar15 + 9;
          uVar15 = uVar15 + 8;
          HintPreloadData(puVar14 + 0xc);
          puVar13[-8] = *puVar3 ^ puVar14[-8];
          puVar13[-7] = puVar3[1] ^ puVar14[-7];
          puVar13[-6] = puVar3[2] ^ puVar14[-6];
          puVar13[-5] = puVar3[3] ^ puVar14[-5];
          puVar13[-4] = puVar3[4] ^ puVar14[-4];
          puVar13[-3] = puVar3[5] ^ puVar14[-3];
          puVar13[-2] = puVar3[6] ^ puVar14[-2];
          puVar13[-1] = puVar3[7] ^ puVar14[-1];
          puVar4 = puVar13 + 8;
          puVar5 = puVar14 + 8;
          puVar3 = puVar12;
        } while (uVar9 < uVar7 - 7);
      }
      iVar6 = 0;
      do {
        uVar15 = uVar15 + 1;
        *(uint *)((int)puVar13 + iVar6) =
             *(uint *)((int)puVar14 + iVar6) ^ *(uint *)((int)puVar12 + iVar6);
        iVar6 = iVar6 + 4;
      } while (uVar15 < uVar7);
      uVar15 = uVar10 & 0xfffffffc;
      if (uVar10 == (uVar10 & 0xfffffffc)) goto LAB_000fc312;
    }
    do {
      puVar11[uVar15] = puVar11[uVar15] ^ *(byte *)((int)mask + uVar15);
      uVar15 = uVar15 + 1;
    } while ((int)uVar15 < (int)uVar10);
  }
LAB_000fc312:
  iVar6 = PKCS1_MGF1((uchar *)local_68,num,puVar11,uVar10,param_8);
  if (iVar6 < 0) {
    return 0;
  }
  if (0 < (int)num) {
    uVar15 = num >> 2;
    uVar10 = num & 0xfffffffc;
    if (uVar15 == 0 || (num < 4 || ((uint)buf & 3) != 0)) {
      uVar10 = 0;
    }
    else {
      if (uVar15 < 9) {
        uVar7 = 0;
        puVar13 = local_68;
      }
      else {
        puVar13 = local_68;
        uVar7 = 0;
        puVar11 = param_1 + 0x21;
        do {
          buf = puVar11;
          puVar13 = puVar13 + 8;
          uVar9 = uVar7 + 9;
          uVar7 = uVar7 + 8;
          HintPreloadData(buf + 0x30);
          *(uint *)(buf + -0x20) = *(uint *)(buf + -0x20) ^ puVar13[-8];
          *(uint *)(buf + -0x1c) = *(uint *)(buf + -0x1c) ^ puVar13[-7];
          *(uint *)(buf + -0x18) = *(uint *)(buf + -0x18) ^ puVar13[-6];
          *(uint *)(buf + -0x14) = *(uint *)(buf + -0x14) ^ puVar13[-5];
          *(uint *)(buf + -0x10) = *(uint *)(buf + -0x10) ^ puVar13[-4];
          *(uint *)(buf + -0xc) = *(uint *)(buf + -0xc) ^ puVar13[-3];
          *(uint *)(buf + -8) = *(uint *)(buf + -8) ^ puVar13[-2];
          *(uint *)(buf + -4) = puVar13[-1] ^ *(uint *)(buf + -4);
          puVar11 = buf + 0x20;
        } while (uVar9 < uVar15 - 7);
      }
      iVar6 = 0;
      do {
        uVar7 = uVar7 + 1;
        *(uint *)(buf + iVar6) = *(uint *)((int)puVar13 + iVar6) ^ *(uint *)(buf + iVar6);
        iVar6 = iVar6 + 4;
      } while (uVar7 < uVar15);
      if (num == uVar10) goto LAB_000fc450;
    }
    pbVar8 = param_1 + uVar10;
    do {
      pbVar2 = (byte *)((int)local_68 + uVar10);
      uVar10 = uVar10 + 1;
      pbVar1 = pbVar8 + 1;
      pbVar8 = pbVar8 + 1;
      *pbVar8 = *pbVar2 ^ *pbVar1;
    } while ((int)uVar10 < (int)num);
  }
LAB_000fc450:
  CRYPTO_free(mask);
  return 1;
}

