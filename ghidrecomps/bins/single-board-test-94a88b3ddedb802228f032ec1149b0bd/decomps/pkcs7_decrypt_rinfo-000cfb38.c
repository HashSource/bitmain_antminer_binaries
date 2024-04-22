
undefined4 pkcs7_decrypt_rinfo(uchar **param_1,size_t *param_2,void *param_3,EVP_PKEY *param_4)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  uchar *out;
  undefined4 uVar2;
  size_t local_24 [2];
  
  ctx = EVP_PKEY_CTX_new(param_4,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return 0xffffffff;
  }
  iVar1 = EVP_PKEY_decrypt_init(ctx);
  if (0 < iVar1) {
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x200,4,0,param_3);
    if (iVar1 < 1) {
      ERR_put_error(0x21,0x85,0x98,DAT_000cfc38,0xd3);
      uVar2 = 0xffffffff;
      goto LAB_000cfbd8;
    }
    iVar1 = EVP_PKEY_decrypt(ctx,(uchar *)0x0,local_24,
                             (uchar *)(*(size_t **)((int)param_3 + 0xc))[2],
                             **(size_t **)((int)param_3 + 0xc));
    if (0 < iVar1) {
      out = (uchar *)CRYPTO_malloc(local_24[0],DAT_000cfc38,0xdb);
      if (out == (uchar *)0x0) {
        ERR_put_error(0x21,0x85,0x41,DAT_000cfc38,0xde);
        uVar2 = 0xffffffff;
      }
      else {
        iVar1 = EVP_PKEY_decrypt(ctx,out,local_24,(uchar *)(*(size_t **)((int)param_3 + 0xc))[2],
                                 **(size_t **)((int)param_3 + 0xc));
        if (iVar1 < 1) {
          ERR_put_error(0x21,0x85,6,DAT_000cfc38,0xe5);
          EVP_PKEY_CTX_free(ctx);
          CRYPTO_free(out);
          return 0;
        }
        if (*param_1 != (uchar *)0x0) {
          OPENSSL_cleanse(*param_1,*param_2);
          CRYPTO_free(*param_1);
        }
        uVar2 = 1;
        *param_1 = out;
        *param_2 = local_24[0];
      }
      goto LAB_000cfbd8;
    }
  }
  uVar2 = 0xffffffff;
LAB_000cfbd8:
  EVP_PKEY_CTX_free(ctx);
  return uVar2;
}

