
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  int *piVar3;
  int local_14;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xae,0x43,"ssl/ssl_rsa.c",0x1f6);
    return 0;
  }
  piVar3 = (int *)ctx->verify_mode;
  iVar1 = ssl_cert_lookup_by_pkey(pkey,&local_14);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xc1,0xf7,"ssl/ssl_rsa.c",0x85);
    iVar1 = 0;
  }
  else {
    iVar2 = local_14 * 4;
    if (piVar3[local_14 * 5 + 5] != 0) {
      to = (EVP_PKEY *)X509_get0_pubkey();
      if (to == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc1,0x41,"ssl/ssl_rsa.c",0x8d);
        return 0;
      }
      EVP_PKEY_copy_parameters(to,pkey);
      ERR_clear_error();
      iVar1 = X509_check_private_key((X509 *)piVar3[local_14 * 5 + 5],pkey);
      iVar2 = local_14 << 2;
      if (iVar1 == 0) {
        X509_free((X509 *)piVar3[local_14 * 5 + 5]);
        piVar3[local_14 * 5 + 5] = 0;
        return 0;
      }
    }
    iVar1 = 1;
    EVP_PKEY_free((EVP_PKEY *)piVar3[local_14 + iVar2 + 6]);
    EVP_PKEY_up_ref(pkey);
    piVar3[local_14 * 5 + 6] = (int)pkey;
    *piVar3 = (int)(piVar3 + local_14 * 5 + 5);
  }
  return iVar1;
}

