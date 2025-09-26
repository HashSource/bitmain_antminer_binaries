
undefined4
sm2_decrypt(EC_KEY *param_1,EVP_MD *param_2,undefined4 param_3,undefined4 param_4,
           undefined1 *param_5,uint *param_6)

{
  size_t sVar1;
  EC_GROUP *group;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  size_t len;
  EVP_MD_CTX *pEVar7;
  uint cnt;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *ptr;
  EVP_MD_CTX *d;
  EVP_MD_CTX *md;
  uint uVar8;
  byte *pbVar9;
  EVP_MD_CTX *pEVar10;
  ENGINE **ppEVar11;
  EVP_MD_CTX *pEVar12;
  ENGINE **ppEVar13;
  size_t cnt_00;
  void *b;
  void *d_00;
  uint uVar15;
  EVP_MD_CTX *r;
  uint uVar16;
  undefined4 uVar17;
  undefined4 local_2c [2];
  ENGINE **ppEVar14;
  
  local_2c[0] = param_3;
  group = EC_KEY_get0_group(param_1);
  pBVar2 = BN_new();
  pBVar3 = BN_new();
  pBVar4 = BN_new();
  if ((pBVar4 == (BIGNUM *)0x0 || (pBVar3 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0)) ||
     (iVar5 = EC_GROUP_get_curve(group,pBVar2,pBVar3,pBVar4,0), iVar5 == 0)) {
    BN_free(pBVar2);
    BN_free(pBVar3);
    BN_free(pBVar4);
    EVP_MD_size(param_2);
LAB_001ca6d6:
    pEVar7 = (EVP_MD_CTX *)0x0;
    ctx = pEVar7;
    r = pEVar7;
    ptr = pEVar7;
    d = pEVar7;
    md = pEVar7;
    pEVar10 = pEVar7;
  }
  else {
    iVar6 = BN_num_bits(pBVar2);
    iVar5 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar5 = iVar6 + 0xe;
    }
    cnt_00 = iVar5 >> 3;
    BN_free(pBVar2);
    BN_free(pBVar3);
    BN_free(pBVar4);
    len = EVP_MD_size(param_2);
    sVar1 = cnt_00;
    if (cnt_00 != 0) {
      sVar1 = len;
    }
    if ((cnt_00 == 0 || len == 0) || (int)sVar1 < 0) goto LAB_001ca6d6;
    r = (EVP_MD_CTX *)0x0;
    memset(param_5,0xff,*param_6);
    pEVar7 = (EVP_MD_CTX *)d2i_SM2_Ciphertext(0,local_2c,param_4);
    if (pEVar7 == (EVP_MD_CTX *)0x0) {
      ERR_put_error(0x35,0x66,100,"crypto/sm2/sm2_crypt.c",0x11d);
      ctx = (EVP_MD_CTX *)0x0;
      r = (EVP_MD_CTX *)0x0;
      ptr = (EVP_MD_CTX *)0x0;
      d = (EVP_MD_CTX *)0x0;
      md = (EVP_MD_CTX *)0x0;
      pEVar10 = (EVP_MD_CTX *)0x0;
      goto LAB_001ca6e2;
    }
    pEVar10 = r;
    if (len == *(size_t *)pEVar7->flags) {
                    /* WARNING: Load size is inaccurate */
      cnt = *pEVar7->md_data;
      if (*param_6 < cnt) {
        iVar6 = 0x12a;
        iVar5 = 0x6b;
        goto LAB_001ca7b6;
      }
      pEVar12 = *(EVP_MD_CTX **)((int)pEVar7->md_data + 8);
      b = (void *)((size_t *)pEVar7->flags)[2];
      ctx = (EVP_MD_CTX *)BN_CTX_new();
      if (ctx == (EVP_MD_CTX *)0x0) {
        ERR_put_error(0x35,0x66,0x41,"crypto/sm2/sm2_crypt.c",0x130);
        r = (EVP_MD_CTX *)0x0;
        ptr = (EVP_MD_CTX *)0x0;
        d = (EVP_MD_CTX *)0x0;
        md = (EVP_MD_CTX *)0x0;
        pEVar10 = (EVP_MD_CTX *)0x0;
      }
      else {
        BN_CTX_start((BN_CTX *)ctx);
        pBVar2 = BN_CTX_get((BN_CTX *)ctx);
        pBVar3 = BN_CTX_get((BN_CTX *)ctx);
        if (pBVar3 == (BIGNUM *)0x0) {
          ERR_put_error(0x35,0x66,3,"crypto/sm2/sm2_crypt.c",0x139);
          r = (EVP_MD_CTX *)0x0;
          ptr = (EVP_MD_CTX *)0x0;
          d = (EVP_MD_CTX *)0x0;
          md = (EVP_MD_CTX *)0x0;
          pEVar10 = (EVP_MD_CTX *)0x0;
        }
        else {
          ptr = (EVP_MD_CTX *)CRYPTO_zalloc(cnt,"crypto/sm2/sm2_crypt.c",0x13d);
          d = (EVP_MD_CTX *)CRYPTO_zalloc(cnt_00 << 1,"crypto/sm2/sm2_crypt.c",0x13e);
          md = (EVP_MD_CTX *)CRYPTO_zalloc(len,"crypto/sm2/sm2_crypt.c",0x13f);
          if (md == (EVP_MD_CTX *)0x0 || (d == (EVP_MD_CTX *)0x0 || ptr == (EVP_MD_CTX *)0x0)) {
            ERR_put_error(0x35,0x66,0x41,"crypto/sm2/sm2_crypt.c",0x142);
          }
          else {
            r = (EVP_MD_CTX *)EC_POINT_new(group);
            if (r == (EVP_MD_CTX *)0x0) {
              ERR_put_error(0x35,0x66,0x41,"crypto/sm2/sm2_crypt.c",0x148);
              pEVar10 = (EVP_MD_CTX *)0x0;
            }
            else {
              iVar5 = EC_POINT_set_affine_coordinates(group,r,pEVar7->digest,pEVar7->engine,ctx);
              if (iVar5 != 0) {
                pBVar4 = EC_KEY_get0_private_key(param_1);
                iVar5 = EC_POINT_mul(group,(EC_POINT *)r,(BIGNUM *)0x0,(EC_POINT *)r,pBVar4,
                                     (BN_CTX *)ctx);
                if ((iVar5 != 0) &&
                   (iVar5 = EC_POINT_get_affine_coordinates(group,r,pBVar2,pBVar3,ctx), iVar5 != 0))
                {
                  iVar5 = BN_bn2binpad(pBVar2,d,cnt_00);
                  if (-1 < iVar5) {
                    d_00 = (void *)((int)&d->digest + cnt_00);
                    iVar5 = BN_bn2binpad(pBVar3,d_00,cnt_00);
                    if (-1 < iVar5) {
                      uVar16 = 0;
                      iVar5 = ecdh_KDF_X9_63(ptr,cnt,d,cnt_00 << 1,0,0,param_2);
                      if (iVar5 != 0) {
                        if (cnt != 0) {
                          if (((cnt < 7 ||
                               pEVar12 < (EVP_MD_CTX *)(param_5 + 4) && param_5 < &pEVar12->engine)
                               || param_5 < &ptr->engine && ptr < (EVP_MD_CTX *)(param_5 + 4)) ||
                             ((((uint)param_5 | (uint)pEVar12 | (uint)ptr) & 3) != 0)) {
                            uVar16 = 0;
                            do {
                              param_5[uVar16] =
                                   *(byte *)((int)&ptr->digest + uVar16) ^
                                   *(byte *)((int)&pEVar12->digest + uVar16);
                              uVar16 = uVar16 + 1;
                            } while (cnt != uVar16);
                          }
                          else {
                            uVar15 = cnt - 4 >> 2;
                            uVar8 = uVar15 * 4 + 4;
                            do {
                              *(uint *)(param_5 + uVar16 * 4) =
                                   (uint)(&pEVar12->digest)[uVar16] ^ (uint)(&ptr->digest)[uVar16];
                              uVar16 = uVar16 + 1;
                            } while (uVar16 < uVar15 + 1);
                            if (cnt != uVar8) {
                              pbVar9 = param_5 + uVar8;
                              ppEVar11 = &ptr->engine + uVar15;
                              ppEVar14 = &pEVar12->engine + uVar15;
                              do {
                                ppEVar13 = (ENGINE **)((int)ppEVar14 + 1);
                                *pbVar9 = *(byte *)ppEVar14 ^ *(byte *)ppEVar11;
                                pbVar9 = pbVar9 + 1;
                                ppEVar11 = (ENGINE **)((int)ppEVar11 + 1);
                                ppEVar14 = ppEVar13;
                              } while (ppEVar13 != (ENGINE **)((int)&pEVar12->digest + cnt));
                            }
                          }
                        }
                        pEVar10 = (EVP_MD_CTX *)EVP_MD_CTX_new();
                        if (pEVar10 == (EVP_MD_CTX *)0x0) {
                          ERR_put_error(0x35,0x66,0x41,"crypto/sm2/sm2_crypt.c",0x162);
                        }
                        else {
                          iVar5 = EVP_DigestInit(pEVar10,param_2);
                          if ((((iVar5 == 0) ||
                               (iVar5 = EVP_DigestUpdate(pEVar10,d,cnt_00), iVar5 == 0)) ||
                              (iVar5 = EVP_DigestUpdate(pEVar10,param_5,cnt), iVar5 == 0)) ||
                             ((iVar5 = EVP_DigestUpdate(pEVar10,d_00,cnt_00), iVar5 == 0 ||
                              (iVar5 = EVP_DigestFinal(pEVar10,(uchar *)md,(uint *)0x0), iVar5 == 0)
                              ))) {
                            ERR_put_error(0x35,0x66,6,"crypto/sm2/sm2_crypt.c",0x16b);
                          }
                          else {
                            iVar5 = CRYPTO_memcmp(md,b,len);
                            if (iVar5 == 0) {
                              uVar17 = 1;
                              *param_6 = cnt;
                              goto LAB_001ca6f2;
                            }
                            ERR_put_error(0x35,0x66,0x66,"crypto/sm2/sm2_crypt.c",0x170);
                          }
                        }
                        goto LAB_001ca6e2;
                      }
                    }
                  }
                  ERR_put_error(0x35,0x66,0x44,"crypto/sm2/sm2_crypt.c",0x159);
                  pEVar10 = (EVP_MD_CTX *)0x0;
                  goto LAB_001ca6e2;
                }
              }
              ERR_put_error(0x35,0x66,0x10,"crypto/sm2/sm2_crypt.c",0x151);
              pEVar10 = (EVP_MD_CTX *)0x0;
            }
          }
        }
      }
    }
    else {
      iVar6 = 0x122;
      iVar5 = 0x68;
LAB_001ca7b6:
      ERR_put_error(0x35,0x66,iVar5,"crypto/sm2/sm2_crypt.c",iVar6);
      ctx = r;
      ptr = r;
      d = r;
      md = r;
    }
  }
LAB_001ca6e2:
  uVar17 = 0;
  memset(param_5,0,*param_6);
LAB_001ca6f2:
  CRYPTO_free(ptr);
  CRYPTO_free(d);
  CRYPTO_free(md);
  EC_POINT_free((EC_POINT *)r);
  BN_CTX_free((BN_CTX *)ctx);
  SM2_Ciphertext_free(pEVar7);
  EVP_MD_CTX_free(pEVar10);
  return uVar17;
}

