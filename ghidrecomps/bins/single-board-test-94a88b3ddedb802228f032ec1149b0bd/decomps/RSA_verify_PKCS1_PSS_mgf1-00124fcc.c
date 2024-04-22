
int RSA_verify_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,uchar *EM,int sLen)

{
  uint *puVar1;
  size_t sVar2;
  size_t cnt;
  int iVar3;
  int iVar4;
  uint *mask;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint num;
  uint *puVar13;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  EVP_MD_CTX_init(&EStack_80);
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    sVar2 = cnt;
    if (sLen != -1) {
      sVar2 = sLen;
      if ((sLen != -2) && (sLen + 2 < 0 != SCARRY4(sLen,2))) {
        ERR_put_error(4,0x95,0x88,DAT_0012532c,0x6f);
        goto LAB_0012504e;
      }
    }
    sLen = sVar2;
    iVar3 = BN_num_bits(rsa->n);
    iVar4 = RSA_size(rsa);
    uVar12 = iVar3 - 1U & 7;
    if ((0xff << uVar12 & (uint)*EM) == 0) {
      if (uVar12 == 0) {
        iVar4 = iVar4 + -1;
        EM = EM + 1;
      }
      if ((int)(cnt + sLen + 1) < iVar4) {
        if (EM[iVar4 + -1] == 0xbc) {
          num = (iVar4 - cnt) - 1;
          mask = (uint *)CRYPTO_malloc(num,DAT_0012532c,0x87);
          if (mask != (uint *)0x0) {
            iVar3 = PKCS1_MGF1((uchar *)mask,num,EM + num,cnt,mgf1Hash);
            if (iVar3 < 0) {
LAB_0012527c:
              iVar3 = 0;
            }
            else {
              if (0 < (int)num) {
                uVar8 = num >> 2;
                uVar9 = num & 0xfffffffc;
                if (uVar8 == 0 ||
                    ((((uint)mask | (uint)EM) & 3) != 0 ||
                    (num < 4 || mask < EM + 4 && EM < mask + 1))) {
                  uVar9 = 0;
                }
                else {
                  if (uVar8 < 9) {
                    uVar11 = 0;
                    puVar7 = mask;
                    puVar13 = (uint *)EM;
                  }
                  else {
                    uVar11 = 0;
                    puVar6 = (uint *)EM;
                    puVar1 = mask;
                    do {
                      puVar7 = puVar1 + 8;
                      puVar13 = puVar6 + 8;
                      uVar5 = uVar11 + 9;
                      uVar11 = uVar11 + 8;
                      HintPreloadData(puVar1 + 0x14);
                      *puVar1 = *puVar6 ^ *puVar1;
                      puVar1[1] = puVar6[1] ^ puVar1[1];
                      puVar1[2] = puVar6[2] ^ puVar1[2];
                      puVar1[3] = puVar6[3] ^ puVar1[3];
                      puVar1[4] = puVar6[4] ^ puVar1[4];
                      puVar1[5] = puVar6[5] ^ puVar1[5];
                      puVar1[6] = puVar6[6] ^ puVar1[6];
                      puVar1[7] = puVar6[7] ^ puVar1[7];
                      puVar6 = puVar13;
                      puVar1 = puVar7;
                    } while (uVar5 < uVar8 - 7);
                  }
                  iVar3 = 0;
                  do {
                    uVar11 = uVar11 + 1;
                    *(uint *)((int)puVar7 + iVar3) =
                         *(uint *)((int)puVar13 + iVar3) ^ *(uint *)((int)puVar7 + iVar3);
                    iVar3 = iVar3 + 4;
                  } while (uVar11 < uVar8);
                  if (num == uVar9) goto LAB_00125212;
                }
                do {
                  *(byte *)((int)mask + uVar9) = *(byte *)((int)mask + uVar9) ^ EM[uVar9];
                  uVar9 = uVar9 + 1;
                } while ((int)uVar9 < (int)num);
              }
LAB_00125212:
              if (uVar12 == 0) {
                uVar12 = (uint)*(byte *)mask;
              }
              else {
                uVar12 = (uint)*(byte *)mask & 0xff >> (8 - uVar12 & 0xff);
                *(byte *)mask = (byte)uVar12;
              }
              if (uVar12 == 0) {
                iVar3 = (iVar4 - cnt) + -2;
                if (0 < iVar3) {
                  puVar7 = mask;
                  iVar4 = 0;
                  do {
                    puVar7 = (uint *)((int)puVar7 + 1);
                    uVar12 = (uint)*(byte *)puVar7;
                    iVar10 = iVar4 + 1;
                    if (uVar12 != 0) {
                      uVar8 = iVar4 + 2;
                      goto LAB_0012524a;
                    }
                    iVar4 = iVar10;
                  } while (iVar10 != iVar3);
                }
              }
              else {
                uVar8 = 1;
LAB_0012524a:
                if (uVar12 == 1) {
                  if ((sLen < 0) || (num - uVar8 == sLen)) {
                    iVar3 = EVP_DigestInit_ex(&EStack_80,Hash,(ENGINE *)0x0);
                    if ((((iVar3 == 0) ||
                         ((iVar3 = EVP_DigestUpdate(&EStack_80,DAT_00125330,8), iVar3 == 0 ||
                          (iVar3 = EVP_DigestUpdate(&EStack_80,mHash,cnt), iVar3 == 0)))) ||
                        ((num != uVar8 &&
                         (iVar3 = EVP_DigestUpdate(&EStack_80,(byte *)((int)mask + uVar8),
                                                   num - uVar8), iVar3 == 0)))) ||
                       (iVar3 = EVP_DigestFinal_ex(&EStack_80,auStack_68,(uint *)0x0), iVar3 == 0))
                    goto LAB_0012527c;
                    iVar3 = memcmp(auStack_68,EM + num,cnt);
                    if (iVar3 == 0) {
                      iVar3 = 1;
                    }
                    else {
                      ERR_put_error(4,0x95,0x68,DAT_0012532c,0xa6);
                      iVar3 = 0;
                    }
                  }
                  else {
                    iVar3 = 0;
                    ERR_put_error(4,0x95,0x88,DAT_0012532c,0x98);
                  }
                  goto LAB_0012526e;
                }
              }
              ERR_put_error(4,0x95,0x87,DAT_0012532c,0x94);
              iVar3 = 0;
            }
LAB_0012526e:
            CRYPTO_free(mask);
            goto LAB_00125050;
          }
          ERR_put_error(4,0x95,0x41,DAT_0012532c,0x89);
        }
        else {
          ERR_put_error(4,0x95,0x86,DAT_0012532c,0x82);
        }
      }
      else {
        ERR_put_error(4,0x95,0x6d,DAT_0012532c,0x7e);
      }
    }
    else {
      ERR_put_error(4,0x95,0x85,DAT_0012532c,0x76);
    }
  }
LAB_0012504e:
  iVar3 = 0;
LAB_00125050:
  EVP_MD_CTX_cleanup(&EStack_80);
  return iVar3;
}

