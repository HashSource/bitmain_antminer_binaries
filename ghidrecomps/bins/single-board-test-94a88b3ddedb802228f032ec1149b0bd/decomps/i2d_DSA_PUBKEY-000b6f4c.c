
int i2d_DSA_PUBKEY(DSA *a,uchar **pp)

{
  EVP_PKEY *pkey;
  X509_PUBKEY *local_14;
  
  if (a != (DSA *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0xd,0xa1,0x41,DAT_000b6fb4,0x123);
      a = (DSA *)0x0;
    }
    else {
      EVP_PKEY_set1_DSA(pkey,a);
      local_14 = (X509_PUBKEY *)0x0;
      a = (DSA *)X509_PUBKEY_set(&local_14,pkey);
      if (a != (DSA *)0x0) {
        a = (DSA *)ASN1_item_i2d((ASN1_VALUE *)local_14,pp,DAT_000b6fb0);
        ASN1_item_free((ASN1_VALUE *)local_14,DAT_000b6fb0);
      }
      EVP_PKEY_free(pkey);
    }
  }
  return (int)a;
}

