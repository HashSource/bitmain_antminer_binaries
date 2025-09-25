
undefined4 SCT_CTX_set1_pubkey(undefined4 *param_1,X509_PUBKEY *param_2)

{
  uchar *data;
  EVP_PKEY *pkey;
  size_t count;
  EVP_MD *type;
  int iVar1;
  uchar *md;
  uchar *local_20;
  uint uStack_1c;
  
  pkey = X509_PUBKEY_get(param_2);
  if (pkey != (EVP_PKEY *)0x0) {
    md = (uchar *)param_1[1];
    local_20 = (uchar *)0x0;
    if ((((md != (uchar *)0x0) && (0x1f < (uint)param_1[2])) ||
        (md = (uchar *)CRYPTO_malloc(0x20,"crypto/ct/ct_sct_ctx.c",0xce), md != (uchar *)0x0)) &&
       (count = i2d_X509_PUBKEY(param_2,&local_20), data = local_20, 0 < (int)count)) {
      type = EVP_sha256();
      iVar1 = EVP_Digest(data,count,md,&uStack_1c,type,(ENGINE *)0x0);
      if (iVar1 != 0) {
        if (md != (uchar *)param_1[1]) {
          CRYPTO_free((uchar *)param_1[1]);
          param_1[1] = md;
          param_1[2] = 0x20;
        }
        CRYPTO_free((void *)0x0);
        CRYPTO_free(local_20);
        EVP_PKEY_free((EVP_PKEY *)*param_1);
        *param_1 = pkey;
        return 1;
      }
    }
    CRYPTO_free(md);
    CRYPTO_free(local_20);
    EVP_PKEY_free(pkey);
  }
  return 0;
}

