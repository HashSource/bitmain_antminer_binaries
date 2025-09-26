
EC_KEY * PEM_read_ECPrivateKey(FILE *fp,EC_KEY **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pkey;
  ec_key_st *peVar1;
  
  pkey = PEM_read_PrivateKey(fp,(EVP_PKEY **)0x0,cb,u);
  if (pkey != (EVP_PKEY *)0x0) {
    peVar1 = EVP_PKEY_get1_EC_KEY(pkey);
    EVP_PKEY_free(pkey);
    if (peVar1 != (ec_key_st *)0x0) {
      if (x == (EC_KEY **)0x0) {
        return peVar1;
      }
      EC_KEY_free(*x);
      *x = peVar1;
      return peVar1;
    }
  }
  return (EC_KEY *)0x0;
}

