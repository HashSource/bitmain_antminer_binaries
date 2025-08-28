
/* WARNING: Type propagation algorithm not settling */

size_t RSA_padding_check_PKCS1_OAEP_mgf1
                 (void *param_1,int param_2,void *param_3,size_t param_4,size_t param_5,
                 void *param_6,size_t param_7,EVP_MD *param_8,EVP_MD *param_9)

{
  uint *puVar1;
  uint *puVar2;
  byte *pbVar3;
  uint len;
  uint *mask;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint num;
  size_t __n;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *__s;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  uint uStack_a8;
  uint auStack_a4 [7];
  undefined1 local_88 [32];
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
  mask = (uint *)CRYPTO_malloc(num,"rsa_oaep.c",0x97);
  __s = (uint *)CRYPTO_malloc(param_5,"rsa_oaep.c",0x98);
  if (mask == (uint *)0x0 || __s == (uint *)0x0) {
    ERR_put_error(4,0xa1,0x41,"rsa_oaep.c",0x9a);
LAB_000fbc8a:
    __n = 0xffffffff;
    if (mask == (uint *)0x0) goto LAB_000fbc9a;
  }
  else {
    memset(__s,0,param_5);
    memcpy((byte *)((param_5 - param_4) + (int)__s),param_3,param_4);
    uVar11 = *__s;
    iVar4 = PKCS1_MGF1((uchar *)&uStack_a8,len,(byte *)(iVar13 + (int)__s),num,param_9);
    if (iVar4 == 0) {
      if (0 < (int)len) {
        pbVar14 = (byte *)((int)__s + 1);
        uVar7 = len >> 2;
        uVar12 = uVar7 << 2;
        if (uVar7 == 0 ||
            (len < 4 ||
            (((uint)pbVar14 & 3) != 0 || pbVar14 < auStack_a4 && &uStack_a8 < (uint *)((int)__s + 5)
            ))) {
          uVar12 = 0;
        }
        else {
          if (uVar7 < 9) {
            uVar9 = 0;
            puVar10 = &uStack_a8;
          }
          else {
            uVar9 = 0;
            pbVar3 = (byte *)((int)__s + 0x21);
            puVar6 = auStack_a4 + 7;
            do {
              puVar10 = puVar6;
              pbVar14 = pbVar3;
              uVar5 = uVar9 + 9;
              uVar9 = uVar9 + 8;
              HintPreloadData(puVar10 + 0xc);
              puVar10[-8] = *(uint *)(pbVar14 + 0xffffffe0) ^ puVar10[-8];
              puVar10[-7] = *(uint *)(pbVar14 + 0xffffffe4) ^ puVar10[-7];
              puVar10[-6] = *(uint *)(pbVar14 + 0xffffffe8) ^ puVar10[-6];
              puVar10[-5] = *(uint *)(pbVar14 + 0xffffffec) ^ puVar10[-5];
              puVar10[-4] = *(uint *)(pbVar14 + 0xfffffff0) ^ puVar10[-4];
              puVar10[-3] = *(uint *)(pbVar14 + 0xfffffff4) ^ puVar10[-3];
              puVar10[-2] = *(uint *)(pbVar14 + 0xfffffff8) ^ puVar10[-2];
              puVar10[-1] = *(uint *)(pbVar14 + 0xfffffffc) ^ puVar10[-1];
              pbVar3 = pbVar14 + 0x20;
              puVar6 = puVar10 + 8;
            } while (uVar5 < uVar7 - 7);
          }
          iVar4 = 0;
          do {
            uVar9 = uVar9 + 1;
            *(uint *)((int)puVar10 + iVar4) =
                 *(uint *)((int)puVar10 + iVar4) ^ *(uint *)(pbVar14 + iVar4);
            iVar4 = iVar4 + 4;
          } while (uVar9 < uVar7);
          if (len == uVar12) goto LAB_000fbe5c;
        }
        pbVar14 = (byte *)((int)__s + uVar12);
        do {
          pbVar14 = pbVar14 + 1;
          *(byte *)((int)&uStack_a8 + uVar12) = *(byte *)((int)&uStack_a8 + uVar12) ^ *pbVar14;
          uVar12 = uVar12 + 1;
        } while ((int)uVar12 < (int)len);
      }
LAB_000fbe5c:
      iVar4 = PKCS1_MGF1((uchar *)mask,num,(uchar *)&uStack_a8,len,param_9);
      if (iVar4 == 0) {
        if (0 < (int)num) {
          puVar10 = (uint *)((int)__s + len + 1);
          uVar7 = num >> 2;
          uVar12 = uVar7 << 2;
          if (uVar7 == 0 ||
              ((((uint)puVar10 | (uint)mask) & 3) != 0 ||
              (num < 4 || puVar10 < mask + 1 && mask < (uint *)((int)__s + len + 5)))) {
            uVar12 = 0;
          }
          else {
            if (uVar7 < 9) {
              uVar9 = 0;
              puVar6 = mask;
            }
            else {
              uVar9 = 0;
              puVar2 = (uint *)((int)__s + len + 0x21);
              puVar1 = mask;
              do {
                puVar10 = puVar2;
                puVar6 = puVar1 + 8;
                uVar5 = uVar9 + 9;
                uVar9 = uVar9 + 8;
                HintPreloadData(puVar1 + 0x14);
                *puVar1 = puVar10[-8] ^ *puVar1;
                puVar1[1] = puVar10[-7] ^ puVar1[1];
                puVar1[2] = puVar10[-6] ^ puVar1[2];
                puVar1[3] = puVar10[-5] ^ puVar1[3];
                puVar1[4] = puVar10[-4] ^ puVar1[4];
                puVar1[5] = puVar10[-3] ^ puVar1[5];
                puVar1[6] = puVar10[-2] ^ puVar1[6];
                puVar1[7] = puVar10[-1] ^ puVar1[7];
                puVar2 = puVar10 + 8;
                puVar1 = puVar6;
              } while (uVar5 < uVar7 - 7);
            }
            iVar4 = 0;
            do {
              uVar9 = uVar9 + 1;
              *(uint *)((int)puVar6 + iVar4) =
                   *(uint *)((int)puVar6 + iVar4) ^ *(uint *)((int)puVar10 + iVar4);
              iVar4 = iVar4 + 4;
            } while (uVar9 < uVar7);
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
          uVar7 = CRYPTO_memcmp(mask,auStack_68,len);
          uVar11 = (int)((byte)uVar11 - 1 & ~(uint)(byte)uVar11 & uVar7 - 1 & ~uVar7) >> 0x1f;
          if ((int)num <= (int)len) {
LAB_000fbc7a:
            ERR_put_error(4,0xa1,0x79,"rsa_oaep.c",0xea);
            goto LAB_000fbc8a;
          }
          uVar7 = 0;
          do {
            uVar8 = (uint)*(byte *)((int)mask + len);
            uVar9 = (int)((uVar8 ^ 1) - 1 & ~(uVar8 ^ 1)) >> 0x1f;
            uVar5 = uVar9 & ~uVar7;
            uVar7 = uVar7 | uVar9;
            uVar9 = uVar5 & len;
            len = len + 1;
            uVar12 = uVar12 & ~uVar5 | uVar9;
            uVar11 = uVar11 & (uVar7 | (int)(uVar8 - 1 & ~uVar8) >> 0x1f);
          } while (num != len);
          if ((uVar7 & uVar11) == 0) goto LAB_000fbc7a;
          __n = num - (uVar12 + 1);
          if (param_2 < (int)__n) {
            ERR_put_error(4,0xa1,0x6d,"rsa_oaep.c",0xdd);
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

