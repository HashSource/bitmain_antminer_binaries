
int SCT_CTX_set1_issuer_pubkey(int param_1,X509_PUBKEY *param_2)

{
  uchar *data;
  size_t count;
  EVP_MD *type;
  uchar *md;
  int iVar1;
  uchar *local_20;
  uint uStack_1c;
  
  md = *(uchar **)(param_1 + 0xc);
  local_20 = (uchar *)0x0;
  if (((md == (uchar *)0x0) || (*(uint *)(param_1 + 0x10) < 0x20)) &&
     (md = (uchar *)CRYPTO_malloc(0x20,"crypto/ct/ct_sct_ctx.c",0xce), md == (uchar *)0x0)) {
    iVar1 = 0;
  }
  else {
    count = i2d_X509_PUBKEY(param_2,&local_20);
    data = local_20;
    if ((int)count < 1) {
      iVar1 = 0;
    }
    else {
      type = EVP_sha256();
      iVar1 = EVP_Digest(data,count,md,&uStack_1c,type,(ENGINE *)0x0);
      if (iVar1 != 0) {
        if (md == *(uchar **)(param_1 + 0xc)) {
          iVar1 = 1;
          md = (uchar *)0x0;
        }
        else {
          iVar1 = 1;
          CRYPTO_free(*(uchar **)(param_1 + 0xc));
          *(uchar **)(param_1 + 0xc) = md;
          *(undefined4 *)(param_1 + 0x10) = 0x20;
          md = (uchar *)0x0;
        }
      }
    }
  }
  CRYPTO_free(md);
  CRYPTO_free(local_20);
  return iVar1;
}

