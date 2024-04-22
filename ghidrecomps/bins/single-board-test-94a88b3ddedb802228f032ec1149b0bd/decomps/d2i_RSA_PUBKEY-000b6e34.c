
RSA * d2i_RSA_PUBKEY(RSA **a,uchar **pp,long length)

{
  X509_PUBKEY *key;
  EVP_PKEY *pkey;
  rsa_st *prVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  key = (X509_PUBKEY *)ASN1_item_d2i((ASN1_VALUE **)0x0,local_1c,length,DAT_000b6e88);
  if (key != (X509_PUBKEY *)0x0) {
    pkey = X509_PUBKEY_get(key);
    ASN1_item_free((ASN1_VALUE *)key,DAT_000b6e88);
    if (pkey != (EVP_PKEY *)0x0) {
      prVar1 = EVP_PKEY_get1_RSA(pkey);
      EVP_PKEY_free(pkey);
      if (prVar1 == (rsa_st *)0x0) {
        return (RSA *)0x0;
      }
      *pp = local_1c[0];
      if (a == (RSA **)0x0) {
        return prVar1;
      }
      RSA_free(*a);
      *a = prVar1;
      return prVar1;
    }
  }
  return (RSA *)0x0;
}

