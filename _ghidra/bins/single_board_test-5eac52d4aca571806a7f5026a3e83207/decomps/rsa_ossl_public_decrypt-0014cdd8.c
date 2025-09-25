
size_t rsa_ossl_public_decrypt(int param_1,uchar *param_2,uchar *param_3,int param_4,int param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *r;
  int iVar2;
  uchar *f;
  BIGNUM *pBVar3;
  BN_MONT_CTX *pBVar4;
  uint *puVar5;
  size_t __n;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    ERR_put_error(4,0x67,0x69,"crypto/rsa/rsa_ossl.c",0x1ff);
    return 0xffffffff;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    iVar1 = 0x204;
LAB_0014ceae:
    ERR_put_error(4,0x67,0x65,"crypto/rsa/rsa_ossl.c",iVar1);
    return 0xffffffff;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar1) && (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar1)) {
    iVar1 = 0x20b;
    goto LAB_0014ceae;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    __n = 0xffffffff;
    iVar1 = 0;
    f = (uchar *)0x0;
    goto LAB_0014ce78;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar1 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar1 = iVar2 + 0xe;
  }
  iVar1 = iVar1 >> 3;
  f = (uchar *)CRYPTO_malloc(iVar1,"crypto/rsa/rsa_ossl.c",0x216);
  if (f == (uchar *)0x0 || r == (BIGNUM *)0x0) {
    ERR_put_error(4,0x67,0x41,"crypto/rsa/rsa_ossl.c",0x218);
    __n = 0xffffffff;
    goto LAB_0014ce78;
  }
  if (iVar1 < param_1) {
    __n = 0xffffffff;
    ERR_put_error(4,0x67,0x6c,"crypto/rsa/rsa_ossl.c",0x221);
    goto LAB_0014ce78;
  }
  pBVar3 = BN_bin2bn(param_2,param_1,ret);
  if (pBVar3 != (BIGNUM *)0x0) {
    iVar2 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (-1 < iVar2) {
      ERR_put_error(4,0x67,0x84,"crypto/rsa/rsa_ossl.c",0x22a);
      __n = 0xffffffff;
      goto LAB_0014ce78;
    }
    if (((-1 < *(int *)(param_4 + 0x40) << 0x1e) ||
        (pBVar4 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x44),*(int *)(param_4 + 0x5c),
                             *(BIGNUM **)(param_4 + 0x10),ctx), pBVar4 != (BN_MONT_CTX *)0x0)) &&
       (iVar2 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                          (r,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10),ctx
                           ,*(undefined4 *)(param_4 + 0x44)), iVar2 != 0)) {
      if (param_5 == 5) {
        puVar5 = (uint *)bn_get_words(r);
        if (((*puVar5 & 0xf) != 0xc) &&
           (iVar2 = BN_sub(r,*(BIGNUM **)(param_4 + 0x10),r), iVar2 == 0)) goto LAB_0014cf4a;
        iVar2 = BN_bn2binpad(r,f,iVar1);
        __n = RSA_padding_check_X931(param_3,iVar1,f,iVar2,iVar1);
      }
      else {
        __n = BN_bn2binpad(r,f,iVar1);
        if (param_5 == 1) {
          __n = RSA_padding_check_PKCS1_type_1(param_3,iVar1,f,__n,iVar1);
        }
        else {
          if (param_5 != 3) {
            __n = 0xffffffff;
            ERR_put_error(4,0x67,0x76,"crypto/rsa/rsa_ossl.c",0x248);
            goto LAB_0014ce78;
          }
          memcpy(param_3,f,__n);
        }
      }
      if ((int)__n < 0) {
        ERR_put_error(4,0x67,0x72,"crypto/rsa/rsa_ossl.c",0x24c);
      }
      goto LAB_0014ce78;
    }
  }
LAB_0014cf4a:
  __n = 0xffffffff;
LAB_0014ce78:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  CRYPTO_clear_free(f,iVar1,"crypto/rsa/rsa_ossl.c",0x251);
  return __n;
}

