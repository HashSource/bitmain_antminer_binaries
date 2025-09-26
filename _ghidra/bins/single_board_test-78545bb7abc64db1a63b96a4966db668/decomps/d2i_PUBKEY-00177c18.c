
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  X509_PUBKEY *key;
  EVP_PKEY *pEVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  key = d2i_X509_PUBKEY((X509_PUBKEY **)0x0,local_1c,length);
  if (key != (X509_PUBKEY *)0x0) {
    pEVar1 = X509_PUBKEY_get(key);
    X509_PUBKEY_free(key);
    if (pEVar1 != (EVP_PKEY *)0x0) {
      *pp = local_1c[0];
      if (a == (EVP_PKEY **)0x0) {
        return pEVar1;
      }
      EVP_PKEY_free(*a);
      *a = pEVar1;
      return pEVar1;
    }
  }
  return (EVP_PKEY *)0x0;
}

