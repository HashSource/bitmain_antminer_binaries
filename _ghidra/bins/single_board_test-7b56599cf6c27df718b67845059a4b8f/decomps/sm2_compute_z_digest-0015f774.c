
void * sm2_compute_z_digest
                 (uchar *param_1,EVP_MD *param_2,void *param_3,uint param_4,EC_KEY *param_5)

{
  EC_GROUP *group;
  EVP_MD_CTX *ctx;
  BN_CTX *ctx_00;
  BIGNUM *a;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  void *d;
  EC_POINT *pEVar8;
  void *pvVar9;
  size_t cnt;
  int iVar10;
  undefined1 local_29 [5];
  
  pvVar9 = (void *)0x0;
  group = EC_KEY_get0_group(param_5);
  local_29[0] = 0;
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  ctx_00 = BN_CTX_new();
  if (ctx_00 == (BN_CTX *)0x0 || ctx == (EVP_MD_CTX *)0x0) {
    d = (void *)0x0;
    ERR_put_error(0x35,0x71,0x41,"crypto/sm2/sm2_sign.c",0x2f);
  }
  else {
    pvVar9 = (void *)0x0;
    a = BN_CTX_get(ctx_00);
    pBVar1 = BN_CTX_get(ctx_00);
    pBVar2 = BN_CTX_get(ctx_00);
    pBVar3 = BN_CTX_get(ctx_00);
    pBVar4 = BN_CTX_get(ctx_00);
    pBVar5 = BN_CTX_get(ctx_00);
    pBVar6 = BN_CTX_get(ctx_00);
    if (pBVar6 == (BIGNUM *)0x0) {
      ERR_put_error(0x35,0x71,0x41,"crypto/sm2/sm2_sign.c",0x3c);
      pvVar9 = (void *)0x0;
      d = (void *)0x0;
    }
    else {
      iVar7 = EVP_DigestInit(ctx,param_2);
      if (iVar7 == 0) {
        ERR_put_error(0x35,0x71,6,"crypto/sm2/sm2_sign.c",0x41);
        pvVar9 = (void *)0x0;
        d = (void *)0x0;
      }
      else if (param_4 < 0x1fff) {
        iVar10 = (param_4 & 0x1fff) << 3;
        local_29[0] = (undefined1)((uint)iVar10 >> 8);
        iVar7 = EVP_DigestUpdate(ctx,local_29,1);
        if (iVar7 == 0) {
          ERR_put_error(0x35,0x71,6,"crypto/sm2/sm2_sign.c",0x51);
          pvVar9 = (void *)0x0;
          d = (void *)0x0;
        }
        else {
          local_29[0] = (undefined1)iVar10;
          iVar7 = EVP_DigestUpdate(ctx,local_29,1);
          if (iVar7 == 0) {
            ERR_put_error(0x35,0x71,6,"crypto/sm2/sm2_sign.c",0x56);
            pvVar9 = (void *)0x0;
            d = (void *)0x0;
          }
          else if ((param_4 == 0) || (iVar7 = EVP_DigestUpdate(ctx,param_3,param_4), iVar7 != 0)) {
            iVar7 = EC_GROUP_get_curve(group,a,pBVar1,pBVar2,ctx_00);
            if (iVar7 == 0) {
              ERR_put_error(0x35,0x71,0x10,"crypto/sm2/sm2_sign.c",0x60);
              pvVar9 = (void *)0x0;
              d = (void *)0x0;
            }
            else {
              iVar10 = BN_num_bits(a);
              iVar7 = iVar10 + 7;
              if (iVar10 + 7 < 0) {
                iVar7 = iVar10 + 0xe;
              }
              cnt = iVar7 >> 3;
              d = (void *)CRYPTO_zalloc(cnt,"crypto/sm2/sm2_sign.c",0x65);
              if (d == (void *)0x0) {
                ERR_put_error(0x35,0x71,0x41,"crypto/sm2/sm2_sign.c",0x67);
                pvVar9 = (void *)0x0;
              }
              else {
                iVar7 = BN_bn2binpad(pBVar1,d,cnt);
                if ((((-1 < iVar7) && (iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0)) &&
                    (iVar7 = BN_bn2binpad(pBVar2,d,cnt), -1 < iVar7)) &&
                   (iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0)) {
                  pEVar8 = EC_GROUP_get0_generator(group);
                  iVar7 = EC_POINT_get_affine_coordinates(group,pEVar8,pBVar3,pBVar4,ctx_00);
                  if (((iVar7 != 0) && (iVar7 = BN_bn2binpad(pBVar3,d,cnt), -1 < iVar7)) &&
                     ((iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0 &&
                      ((iVar7 = BN_bn2binpad(pBVar4,d,cnt), -1 < iVar7 &&
                       (iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0)))))) {
                    pEVar8 = EC_KEY_get0_public_key(param_5);
                    iVar7 = EC_POINT_get_affine_coordinates(group,pEVar8,pBVar5,pBVar6,ctx_00);
                    if ((iVar7 != 0) &&
                       ((((iVar7 = BN_bn2binpad(pBVar5,d,cnt), -1 < iVar7 &&
                          (iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0)) &&
                         (iVar7 = BN_bn2binpad(pBVar6,d,cnt), -1 < iVar7)) &&
                        ((iVar7 = EVP_DigestUpdate(ctx,d,cnt), iVar7 != 0 &&
                         (iVar7 = EVP_DigestFinal(ctx,param_1,(uint *)0x0), iVar7 != 0)))))) {
                      pvVar9 = (void *)0x1;
                      goto LAB_0015f990;
                    }
                  }
                }
                pvVar9 = (void *)0x0;
                ERR_put_error(0x35,0x71,0x44,"crypto/sm2/sm2_sign.c",0x7e);
              }
            }
          }
          else {
            ERR_put_error(0x35,0x71,6,"crypto/sm2/sm2_sign.c",0x5b);
            pvVar9 = (void *)0x0;
            d = (void *)0x0;
          }
        }
      }
      else {
        ERR_put_error(0x35,0x71,0x6f,"crypto/sm2/sm2_sign.c",0x49);
        d = pvVar9;
      }
    }
  }
LAB_0015f990:
  CRYPTO_free(d);
  BN_CTX_free(ctx_00);
  EVP_MD_CTX_free(ctx);
  return pvVar9;
}

