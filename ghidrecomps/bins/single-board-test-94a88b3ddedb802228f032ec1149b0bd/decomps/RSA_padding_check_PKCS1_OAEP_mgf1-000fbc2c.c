
/* WARNING: Type propagation algorithm not settling */

size_t RSA_padding_check_PKCS1_OAEP_mgf1
                 (void *param_1,int param_2,void *param_3,size_t param_4,size_t param_5,
                 void *param_6,size_t param_7,EVP_MD *param_8,EVP_MD *param_9)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  uint len;
  uint *mask;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint num;
  size_t __n;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *__s;
  uint *puVar14;
  bool bVar15;
  bool bVar16;
  uint auStack_a8 [16];
  uchar auStack_68 [68];
  
  if (param_8 == (EVP_MD *)0x0) {
    param_8 = EVP_sha1();
  }
  if (param_9 == (EVP_MD *)0x0) {
    param_9 = param_8;
  }
  len = EVP_MD_size(param_8);
  bVar15 = param_2 < 0;
  bVar16 = param_2 == 0;
  if (0 < param_2) {
    bVar15 = (int)param_4 < 0;
    bVar16 = param_4 == 0;
  }
  if (bVar16 || bVar15) {
    return 0xffffffff;
  }
  __s = (uint *)0x0;
  mask = __s;
  if (((int)param_5 < (int)param_4) ||
     (iVar13 = len + 1, (int)(param_5 + iVar13 * -2) < 0 != SBORROW4(param_5,iVar13 * 2)))
  goto LAB_000fbc7a;
  num = (param_5 - len) - 1;
  mask = (uint *)CRYPTO_malloc(num,DAT_000fbcf0,0x97);
  __s = (uint *)CRYPTO_malloc(param_5,DAT_000fbcf0,0x98);
  if (mask == (uint *)0x0 || __s == (uint *)0x0) {
    ERR_put_error(4,0xa1,0x41,DAT_000fbcf0,0x9a);
LAB_000fbc8a:
    __n = 0xffffffff;
    if (mask == (uint *)0x0) goto LAB_000fbc9a;
  }
  else {
    memset(__s,0,param_5);
    memcpy((byte *)((param_5 - param_4) + (int)__s),param_3,param_4);
    bVar1 = *(byte *)__s;
    iVar4 = PKCS1_MGF1((uchar *)auStack_a8,len,(byte *)(iVar13 + (int)__s),num,param_9);
    if (iVar4 == 0) {
      if (0 < (int)len) {
        puVar14 = (uint *)((int)__s + 1);
        uVar8 = len >> 2;
        uVar12 = len & 0xfffffffc;
        if (uVar8 == 0 ||
            (len < 4 ||
            (((uint)puVar14 & 3) != 0 ||
            puVar14 < auStack_a8 + 1 && auStack_a8 < (uint *)((int)__s + 5)))) {
          uVar12 = 0;
        }
        else {
          if (uVar8 < 9) {
            uVar11 = 0;
            puVar6 = auStack_a8;
          }
          else {
            puVar6 = auStack_a8;
            uVar11 = 0;
            puVar3 = (uint *)((int)__s + 0x21);
            do {
              puVar14 = puVar3;
              puVar6 = puVar6 + 8;
              uVar5 = uVar11 + 9;
              uVar11 = uVar11 + 8;
              HintPreloadData(puVar6 + 0xc);
              puVar6[-8] = puVar14[-8] ^ puVar6[-8];
              puVar6[-7] = puVar14[-7] ^ puVar6[-7];
              puVar6[-6] = puVar14[-6] ^ puVar6[-6];
              puVar6[-5] = puVar14[-5] ^ puVar6[-5];
              puVar6[-4] = puVar14[-4] ^ puVar6[-4];
              puVar6[-3] = puVar14[-3] ^ puVar6[-3];
              puVar6[-2] = puVar14[-2] ^ puVar6[-2];
              puVar6[-1] = puVar14[-1] ^ puVar6[-1];
              puVar3 = puVar14 + 8;
            } while (uVar5 < uVar8 - 7);
          }
          iVar4 = 0;
          do {
            uVar11 = uVar11 + 1;
            *(uint *)((int)puVar6 + iVar4) =
                 *(uint *)((int)puVar6 + iVar4) ^ *(uint *)((int)puVar14 + iVar4);
            iVar4 = iVar4 + 4;
          } while (uVar11 < uVar8);
          if (len == uVar12) goto LAB_000fbe5c;
        }
        pbVar9 = (byte *)((int)__s + uVar12);
        do {
          pbVar9 = pbVar9 + 1;
          *(byte *)((int)auStack_a8 + uVar12) = *(byte *)((int)auStack_a8 + uVar12) ^ *pbVar9;
          uVar12 = uVar12 + 1;
        } while ((int)uVar12 < (int)len);
      }
LAB_000fbe5c:
      iVar4 = PKCS1_MGF1((uchar *)mask,num,(uchar *)auStack_a8,len,param_9);
      if (iVar4 == 0) {
        if (0 < (int)num) {
          puVar14 = (uint *)((int)__s + len + 1);
          uVar8 = num >> 2;
          uVar12 = num & 0xfffffffc;
          if (uVar8 == 0 ||
              ((((uint)puVar14 | (uint)mask) & 3) != 0 ||
              (num < 4 || puVar14 < mask + 1 && mask < (uint *)((int)__s + len + 5)))) {
            uVar12 = 0;
          }
          else {
            if (uVar8 < 9) {
              uVar11 = 0;
              puVar6 = mask;
            }
            else {
              uVar11 = 0;
              puVar2 = (uint *)((int)__s + len + 0x21);
              puVar3 = mask;
              do {
                puVar14 = puVar2;
                puVar6 = puVar3 + 8;
                uVar5 = uVar11 + 9;
                uVar11 = uVar11 + 8;
                HintPreloadData(puVar3 + 0x14);
                *puVar3 = puVar14[-8] ^ *puVar3;
                puVar3[1] = puVar14[-7] ^ puVar3[1];
                puVar3[2] = puVar14[-6] ^ puVar3[2];
                puVar3[3] = puVar14[-5] ^ puVar3[3];
                puVar3[4] = puVar14[-4] ^ puVar3[4];
                puVar3[5] = puVar14[-3] ^ puVar3[5];
                puVar3[6] = puVar14[-2] ^ puVar3[6];
                puVar3[7] = puVar14[-1] ^ puVar3[7];
                puVar2 = puVar14 + 8;
                puVar3 = puVar6;
              } while (uVar5 < uVar8 - 7);
            }
            iVar4 = 0;
            do {
              uVar11 = uVar11 + 1;
              *(uint *)((int)puVar6 + iVar4) =
                   *(uint *)((int)puVar6 + iVar4) ^ *(uint *)((int)puVar14 + iVar4);
              iVar4 = iVar4 + 4;
            } while (uVar11 < uVar8);
            if (num == uVar12) goto LAB_000fbfba;
          }
          do {
            *(byte *)((int)mask + uVar12) =
                 *(byte *)((int)mask + uVar12) ^ ((byte *)(iVar13 + (int)__s))[uVar12];
            uVar12 = uVar12 + 1;
          } while ((int)uVar12 < (int)num);
        }
LAB_000fbfba:
        uVar12 = 0;
        iVar13 = EVP_Digest(param_6,param_7,auStack_68,(uint *)0x0,param_8,(ENGINE *)0x0);
        if (iVar13 != 0) {
          uVar8 = CRYPTO_memcmp(mask,auStack_68,len);
          uVar8 = (int)(bVar1 - 1 & ~(uint)bVar1 & uVar8 - 1 & ~uVar8) >> 0x1f;
          if ((int)num <= (int)len) {
LAB_000fbc7a:
            ERR_put_error(4,0xa1,0x79,DAT_000fbcf0,0xea);
            goto LAB_000fbc8a;
          }
          uVar11 = 0;
          do {
            uVar10 = (uint)*(byte *)((int)mask + len);
            uVar5 = (int)((uVar10 ^ 1) - 1 & ~(uVar10 ^ 1)) >> 0x1f;
            uVar7 = uVar5 & ~uVar11;
            uVar11 = uVar11 | uVar5;
            uVar5 = uVar7 & len;
            len = len + 1;
            uVar12 = uVar12 & ~uVar7 | uVar5;
            uVar8 = uVar8 & (uVar11 | (int)(uVar10 - 1 & ~uVar10) >> 0x1f);
          } while (num != len);
          if ((uVar11 & uVar8) == 0) goto LAB_000fbc7a;
          __n = num - (uVar12 + 1);
          if (param_2 < (int)__n) {
            ERR_put_error(4,0xa1,0x6d,DAT_000fc088,0xdd);
            goto LAB_000fbc7a;
          }
          memcpy(param_1,(byte *)(uVar12 + 1 + (int)mask),__n);
          goto LAB_000fbc94;
        }
      }
    }
    __n = 0xffffffff;
  }
LAB_000fbc94:
  CRYPTO_free(mask);
LAB_000fbc9a:
  if (__s != (uint *)0x0) {
    CRYPTO_free(__s);
  }
  return __n;
}

