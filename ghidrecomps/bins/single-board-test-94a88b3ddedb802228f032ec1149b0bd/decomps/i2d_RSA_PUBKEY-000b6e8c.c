
int i2d_RSA_PUBKEY(RSA *a,uchar **pp)

{
  EVP_PKEY *pkey;
  X509_PUBKEY *local_14;
  
  if (a != (RSA *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0xa5,0x41,DAT_000b6ef0,0xfb);
      a = (RSA *)0x0;
    }
    else {
      EVP_PKEY_set1_RSA(pkey,a);
      local_14 = (X509_PUBKEY *)0x0;
      a = (RSA *)X509_PUBKEY_set(&local_14,pkey);
      if (a != (RSA *)0x0) {
        a = (RSA *)ASN1_item_i2d((ASN1_VALUE *)local_14,pp,DAT_000b6eec);
        ASN1_item_free((ASN1_VALUE *)local_14,DAT_000b6eec);
      }
      EVP_PKEY_free(pkey);
    }
  }
  return (int)a;
}

