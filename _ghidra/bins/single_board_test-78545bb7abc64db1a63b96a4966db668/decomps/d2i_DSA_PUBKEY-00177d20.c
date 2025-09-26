
DSA * d2i_DSA_PUBKEY(DSA **a,uchar **pp,long length)

{
  EVP_PKEY *pkey;
  dsa_st *pdVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  pkey = d2i_PUBKEY((EVP_PKEY **)0x0,local_1c,length);
  if (pkey != (EVP_PKEY *)0x0) {
    pdVar1 = EVP_PKEY_get1_DSA(pkey);
    EVP_PKEY_free(pkey);
    if (pdVar1 != (dsa_st *)0x0) {
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

