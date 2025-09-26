
EC_KEY * d2i_EC_PUBKEY(EC_KEY **a,uchar **pp,long length)

{
  EVP_PKEY *pkey;
  ec_key_st *peVar1;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  pkey = d2i_PUBKEY((EVP_PKEY **)0x0,local_1c,length);
  if (pkey != (EVP_PKEY *)0x0) {
    peVar1 = EVP_PKEY_get1_EC_KEY(pkey);
    EVP_PKEY_free(pkey);
    if (peVar1 != (ec_key_st *)0x0) {
      *pp = local_1c[0];
      if (a == (EC_KEY **)0x0) {
        return peVar1;
      }
      EC_KEY_free(*a);
      *a = peVar1;
      return peVar1;
    }
  }
  return (EC_KEY *)0x0;
}

