
int i2d_RSA_PUBKEY(RSA *a,uchar **pp)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (a != (RSA *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0xa5,0x41,"crypto/x509/x_pubkey.c",0xfc);
      iVar1 = -1;
    }
    else {
      EVP_PKEY_set1_RSA(pkey,a);
      iVar1 = i2d_PUBKEY(pkey,pp);
      EVP_PKEY_free(pkey);
    }
    return iVar1;
  }
  return 0;
}

