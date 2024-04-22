
DSA * d2i_DSA_PUBKEY(DSA **a,uchar **pp,long length)

{
  X509_PUBKEY *key;
  EVP_PKEY *pkey;
  dsa_st *pdVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  key = (X509_PUBKEY *)ASN1_item_d2i((ASN1_VALUE **)0x0,local_1c,length,DAT_000b6f48);
  if (key != (X509_PUBKEY *)0x0) {
    pkey = X509_PUBKEY_get(key);
    ASN1_item_free((ASN1_VALUE *)key,DAT_000b6f48);
    if (pkey != (EVP_PKEY *)0x0) {
      pdVar1 = EVP_PKEY_get1_DSA(pkey);
      EVP_PKEY_free(pkey);
      if (pdVar1 == (dsa_st *)0x0) {
        return (DSA *)0x0;
      }
      *pp = local_1c[0];
      if (a == (DSA **)0x0) {
        return pdVar1;
      }
      DSA_free(*a);
      *a = pdVar1;
      return pdVar1;
    }
  }
  return (DSA *)0x0;
}

