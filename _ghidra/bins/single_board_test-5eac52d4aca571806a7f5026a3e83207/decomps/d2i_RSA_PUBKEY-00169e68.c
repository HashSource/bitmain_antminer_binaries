
RSA * d2i_RSA_PUBKEY(RSA **a,uchar **pp,long length)

{
  EVP_PKEY *pkey;
  rsa_st *prVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  pkey = d2i_PUBKEY((EVP_PKEY **)0x0,local_1c,length);
  if (pkey != (EVP_PKEY *)0x0) {
    prVar1 = EVP_PKEY_get1_RSA(pkey);
    EVP_PKEY_free(pkey);
    if (prVar1 != (rsa_st *)0x0) {
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

