
undefined4
sm2_do_verify(undefined4 param_1,EVP_MD *param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,void *param_6,size_t param_7)

{
  EVP_MD_CTX *ctx;
  size_t cnt;
  uchar *md;
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  cnt = EVP_MD_size(param_2);
  if ((int)cnt < 0) {
    md = (uchar *)0x0;
    ERR_put_error(0x35,100,0x66,"crypto/sm2/sm2_sign.c",0x97);
  }
  else {
    md = (uchar *)CRYPTO_zalloc(cnt,"crypto/sm2/sm2_sign.c",0x9b);
    pBVar2 = (BIGNUM *)(uint)(md == (uchar *)0x0 || ctx == (EVP_MD_CTX *)0x0);
    if (md == (uchar *)0x0 || ctx == (EVP_MD_CTX *)0x0) {
      ERR_put_error(0x35,100,0x41,"crypto/sm2/sm2_sign.c",0x9d);
    }
    else {
      iVar1 = sm2_compute_z_digest(md,param_2,param_4,param_5,param_1);
      if (iVar1 != 0) {
        iVar1 = EVP_DigestInit(ctx,param_2);
        if ((((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,md,cnt), iVar1 == 0)) ||
            (iVar1 = EVP_DigestUpdate(ctx,param_6,param_7), iVar1 == 0)) ||
           (iVar1 = EVP_DigestFinal(ctx,md,(uint *)pBVar2), iVar1 == 0)) {
          ERR_put_error(0x35,100,6,"crypto/sm2/sm2_sign.c",0xab);
        }
        else {
          pBVar2 = BN_bin2bn(md,cnt,pBVar2);
          if (pBVar2 != (BIGNUM *)0x0) {
            CRYPTO_free(md);
            EVP_MD_CTX_free(ctx);
            uVar3 = sm2_sig_verify(param_1,param_3,pBVar2);
            BN_free(pBVar2);
            return uVar3;
          }
          ERR_put_error(0x35,100,0x44,"crypto/sm2/sm2_sign.c",0xb1);
        }
      }
    }
  }
  CRYPTO_free(md);
  EVP_MD_CTX_free(ctx);
  BN_free((BIGNUM *)0x0);
  return 0;
}

