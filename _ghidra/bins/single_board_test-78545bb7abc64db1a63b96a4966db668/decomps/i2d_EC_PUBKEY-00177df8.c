
int i2d_EC_PUBKEY(EC_KEY *a,uchar **pp)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (a != (EC_KEY *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0xb5,0x41,"crypto/x509/x_pubkey.c",0x14b);
      iVar1 = -1;
    }
    else {
      EVP_PKEY_set1_EC_KEY(pkey,a);
      iVar1 = i2d_PUBKEY(pkey,pp);
      EVP_PKEY_free(pkey);
    }
    return iVar1;
  }
  return 0;
}

