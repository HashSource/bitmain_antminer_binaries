
int SSL_CTX_use_RSAPrivateKey_ASN1(SSL_CTX *ctx,uchar *d,long len)

{
  RSA *r;
  int iVar1;
  EVP_PKEY *pkey;
  uchar *local_14;
  
  local_14 = d;
  r = d2i_RSAPrivateKey((RSA **)0x0,&local_14,len);
  if (r == (RSA *)0x0) {
    ERR_put_error(0x14,0xb2,0xd,DAT_00081eec,0x241);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xb1,0x41,DAT_00081eec,0x1fe);
      iVar1 = 0;
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xb1,6,DAT_00081eec,0x202);
        iVar1 = 0;
      }
      else {
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        iVar1 = ssl_set_pkey(ctx->cert,pkey);
        EVP_PKEY_free(pkey);
      }
    }
    RSA_free(r);
  }
  return iVar1;
}

