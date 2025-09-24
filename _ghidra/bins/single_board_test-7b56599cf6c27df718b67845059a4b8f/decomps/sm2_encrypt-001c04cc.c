
uint * sm2_encrypt(EC_KEY *param_1,EVP_MD *param_2,uint *param_3,uint param_4,void *param_5,
                  size_t *param_6)

{
  uint *puVar1;
  EVP_MD_CTX *ctx;
  EC_GROUP *group;
  undefined4 uVar2;
  EC_POINT *q;
  EVP_MD_CTX *len;
  EVP_MD_CTX *pEVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  int iVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  uint *md;
  uint *data;
  byte *pbVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  size_t sVar15;
  EC_POINT *m;
  uint uVar16;
  BN_CTX *ctx_00;
  EC_POINT *r;
  EC_POINT *r_00;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  uint *local_74;
  BIGNUM *local_38;
  BIGNUM *local_34;
  ASN1_STRING *local_30;
  ASN1_OCTET_STRING *local_2c;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  group = EC_KEY_get0_group(param_1);
  uVar2 = EC_GROUP_get0_order();
  q = EC_KEY_get0_public_key(param_1);
  len = (EVP_MD_CTX *)EVP_MD_size(param_2);
  pEVar3 = ctx;
  if (ctx != (EVP_MD_CTX *)0x0) {
    pEVar3 = len;
  }
  local_2c = (ASN1_OCTET_STRING *)0x0;
  local_30 = (ASN1_STRING *)0x0;
  if ((ctx == (EVP_MD_CTX *)0x0 || len == (EVP_MD_CTX *)0x0) || (int)pEVar3 < 0) {
    ERR_put_error(0x35,0x67,0x44,"crypto/sm2/sm2_crypt.c",0x84);
  }
  else {
    pBVar4 = BN_new();
    pBVar5 = BN_new();
    pBVar6 = BN_new();
    if ((pBVar6 == (BIGNUM *)0x0 || (pBVar5 == (BIGNUM *)0x0 || pBVar4 == (BIGNUM *)0x0)) ||
       (iVar7 = EC_GROUP_get_curve(group,pBVar4,pBVar5,pBVar6,0), iVar7 == 0)) {
      BN_free(pBVar4);
      BN_free(pBVar5);
      BN_free(pBVar6);
    }
    else {
      iVar8 = BN_num_bits(pBVar4);
      iVar7 = iVar8 + 7;
      if (iVar8 + 7 < 0) {
        iVar7 = iVar8 + 0xe;
      }
      sVar15 = iVar7 >> 3;
      BN_free(pBVar4);
      BN_free(pBVar5);
      BN_free(pBVar6);
      if (sVar15 != 0) {
        r = EC_POINT_new(group);
        r_00 = EC_POINT_new(group);
        ctx_00 = BN_CTX_new();
        if (ctx_00 == (BN_CTX *)0x0 || (r_00 == (EC_POINT *)0x0 || r == (EC_POINT *)0x0)) {
          iVar7 = 0x41;
          iVar8 = 0x92;
        }
        else {
          BN_CTX_start(ctx_00);
          pBVar4 = BN_CTX_get(ctx_00);
          pBVar5 = BN_CTX_get(ctx_00);
          pBVar6 = BN_CTX_get(ctx_00);
          pBVar9 = BN_CTX_get(ctx_00);
          pBVar10 = BN_CTX_get(ctx_00);
          if (pBVar10 != (BIGNUM *)0x0) {
            local_74 = (uint *)CRYPTO_zalloc(sVar15 << 1,"crypto/sm2/sm2_crypt.c",0xa2);
            md = (uint *)CRYPTO_zalloc(len,"crypto/sm2/sm2_crypt.c",0xa3);
            m = (EC_POINT *)(uint)(md == (uint *)0x0 || local_74 == (uint *)0x0);
            if (md == (uint *)0x0 || local_74 == (uint *)0x0) {
              ERR_put_error(0x35,0x67,0x41,"crypto/sm2/sm2_crypt.c",0xa6);
              data = (uint *)0x0;
              puVar12 = (uint *)0x0;
            }
            else {
              memset(param_5,(int)m,*param_6);
              iVar7 = BN_priv_rand_range(pBVar4,uVar2);
              if (iVar7 == 0) {
                ERR_put_error(0x35,0x67,0x44,"crypto/sm2/sm2_crypt.c",0xad);
                data = (uint *)0x0;
                puVar12 = (uint *)0x0;
              }
              else {
                iVar7 = EC_POINT_mul(group,r,pBVar4,m,(BIGNUM *)m,ctx_00);
                if ((((iVar7 == 0) ||
                     (iVar7 = EC_POINT_get_affine_coordinates(group,r,pBVar5,pBVar9,ctx_00),
                     iVar7 == 0)) ||
                    (iVar7 = EC_POINT_mul(group,r_00,(BIGNUM *)0x0,q,pBVar4,ctx_00), iVar7 == 0)) ||
                   (iVar7 = EC_POINT_get_affine_coordinates(group,r_00,pBVar6,pBVar10,ctx_00),
                   iVar7 == 0)) {
                  iVar8 = 0xb5;
                  iVar7 = 0x10;
                }
                else {
                  iVar7 = BN_bn2binpad(pBVar6,local_74,sVar15);
                  if (-1 < iVar7) {
                    iVar7 = BN_bn2binpad(pBVar10,(byte *)((int)local_74 + sVar15));
                    if (-1 < iVar7) {
                      data = (uint *)CRYPTO_zalloc(param_4,"crypto/sm2/sm2_crypt.c",0xbf);
                      iVar7 = 0xc1;
                      if (data != (uint *)0x0) {
                        iVar7 = ecdh_KDF_X9_63(data,param_4,local_74,sVar15 << 1,0,0,param_2);
                        if (iVar7 == 0) {
                          ERR_put_error(0x35,0x67,6,"crypto/sm2/sm2_crypt.c",200);
                          puVar12 = (uint *)0x0;
                          goto LAB_001c057e;
                        }
                        if (param_4 != 0) {
                          if ((param_4 < 7 || data < param_3 + 1 && param_3 < data + 1) ||
                             ((((uint)param_3 | (uint)data) & 3) != 0)) {
                            pbVar11 = (byte *)((int)param_3 + -1);
                            puVar12 = data;
                            do {
                              pbVar11 = pbVar11 + 1;
                              puVar13 = (uint *)((int)puVar12 + 1);
                              *(byte *)puVar12 = *pbVar11 ^ (byte)*puVar12;
                              puVar12 = puVar13;
                            } while ((uint *)((int)data + param_4) != puVar13);
                          }
                          else {
                            uVar16 = param_4 - 4 >> 2;
                            uVar17 = uVar16 + 1;
                            uVar16 = uVar16 - 8;
                            uVar14 = uVar17 * 4;
                            if (uVar16 < 0xfffffff7) {
                              uVar16 = (uVar16 & 0xfffffff8) + 8;
                              uVar18 = 0;
                              puVar19 = data;
                              puVar1 = param_3;
                              do {
                                puVar12 = puVar1 + 8;
                                puVar13 = puVar19 + 8;
                                uVar18 = uVar18 + 8;
                                HintPreloadData(puVar19 + 0x14);
                                *puVar19 = *puVar19 ^ *puVar1;
                                puVar19[1] = puVar1[1] ^ puVar19[1];
                                puVar19[2] = puVar1[2] ^ puVar19[2];
                                puVar19[3] = puVar1[3] ^ puVar19[3];
                                puVar19[4] = puVar1[4] ^ puVar19[4];
                                puVar19[5] = puVar1[5] ^ puVar19[5];
                                puVar19[6] = puVar1[6] ^ puVar19[6];
                                puVar19[7] = puVar19[7] ^ puVar1[7];
                                puVar19 = puVar13;
                                puVar1 = puVar12;
                              } while (uVar18 != uVar16);
                            }
                            else {
                              uVar16 = 0;
                              puVar13 = data;
                              puVar12 = param_3;
                            }
                            puVar12 = puVar12 + -1;
                            puVar19 = puVar13 + -1;
                            do {
                              puVar19 = puVar19 + 1;
                              uVar16 = uVar16 + 1;
                              puVar12 = puVar12 + 1;
                              *puVar13 = *puVar12 ^ *puVar19;
                              puVar13 = puVar13 + 1;
                            } while (uVar16 < uVar17);
                            if (param_4 != uVar14) {
                              uVar16 = uVar14 + 1;
                              *(byte *)(data + uVar17) = (byte)data[uVar17] ^ (byte)param_3[uVar17];
                              if (param_4 != uVar16) {
                                uVar14 = uVar14 + 2;
                                *(byte *)((int)data + uVar16) =
                                     *(byte *)((int)data + uVar16) ^
                                     *(byte *)((int)param_3 + uVar16);
                                if (param_4 != uVar14) {
                                  *(byte *)((int)data + uVar14) =
                                       *(byte *)((int)data + uVar14) ^
                                       *(byte *)((int)param_3 + uVar14);
                                }
                              }
                            }
                          }
                        }
                        iVar7 = EVP_DigestInit(ctx,param_2);
                        if (((iVar7 == 0) ||
                            (iVar7 = EVP_DigestUpdate(ctx,local_74,sVar15), iVar7 == 0)) ||
                           ((iVar7 = EVP_DigestUpdate(ctx,param_3,param_4), iVar7 == 0 ||
                            ((iVar7 = EVP_DigestUpdate(ctx,(byte *)((int)local_74 + sVar15),sVar15),
                             iVar7 == 0 ||
                             (iVar7 = EVP_DigestFinal(ctx,(uchar *)md,(uint *)0x0), iVar7 == 0))))))
                        {
                          ERR_put_error(0x35,0x67,6,"crypto/sm2/sm2_crypt.c",0xd4);
                          puVar12 = (uint *)0x0;
                          goto LAB_001c057e;
                        }
                        local_38 = pBVar5;
                        local_34 = pBVar9;
                        local_30 = ASN1_OCTET_STRING_new();
                        local_2c = ASN1_OCTET_STRING_new();
                        if ((local_30 != (ASN1_STRING *)0x0) &&
                           (local_2c != (ASN1_OCTET_STRING *)0x0)) {
                          iVar7 = ASN1_OCTET_STRING_set(local_30,md,(int)len);
                          if ((iVar7 == 0) ||
                             (iVar7 = ASN1_OCTET_STRING_set(local_2c,data,param_4), iVar7 == 0)) {
                            iVar7 = 0xe3;
                          }
                          else {
                            sVar15 = i2d_SM2_Ciphertext(&local_38,&param_5);
                            if (-1 < (int)sVar15) {
                              *param_6 = sVar15;
                              puVar12 = (uint *)0x1;
                              goto LAB_001c057e;
                            }
                            iVar7 = 0xea;
                          }
                          ERR_put_error(0x35,0x67,0x44,"crypto/sm2/sm2_crypt.c",iVar7);
                          puVar12 = (uint *)0x0;
                          goto LAB_001c057e;
                        }
                        iVar7 = 0xde;
                      }
                      ERR_put_error(0x35,0x67,0x41,"crypto/sm2/sm2_crypt.c",iVar7);
                      puVar12 = (uint *)0x0;
                      goto LAB_001c057e;
                    }
                  }
                  iVar8 = 0xbb;
                  iVar7 = 0x44;
                }
                ERR_put_error(0x35,0x67,iVar7,"crypto/sm2/sm2_crypt.c",iVar8);
                data = (uint *)0x0;
                puVar12 = (uint *)0x0;
              }
            }
            goto LAB_001c057e;
          }
          iVar8 = 0x9e;
          iVar7 = 3;
        }
        md = (uint *)0x0;
        ERR_put_error(0x35,0x67,iVar7,"crypto/sm2/sm2_crypt.c",iVar8);
        data = md;
        puVar12 = md;
        local_74 = md;
        goto LAB_001c057e;
      }
    }
    ERR_put_error(0x35,0x67,0x44,"crypto/sm2/sm2_crypt.c",0x8a);
  }
  local_74 = (uint *)0x0;
  md = (uint *)0x0;
  r_00 = (EC_POINT *)0x0;
  r = (EC_POINT *)0x0;
  ctx_00 = (BN_CTX *)0x0;
  data = md;
  puVar12 = (uint *)0x0;
LAB_001c057e:
  ASN1_OCTET_STRING_free(local_2c);
  ASN1_OCTET_STRING_free(local_30);
  CRYPTO_free(data);
  CRYPTO_free(local_74);
  CRYPTO_free(md);
  EVP_MD_CTX_free(ctx);
  BN_CTX_free(ctx_00);
  EC_POINT_free(r);
  EC_POINT_free(r_00);
  return puVar12;
}

