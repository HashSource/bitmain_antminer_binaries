
RSA * PEM_read_bio_RSAPrivateKey(BIO *bp,RSA **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pkey;
  rsa_st *prVar1;
  
  pkey = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,cb,u);
  if (pkey != (EVP_PKEY *)0x0) {
    prVar1 = EVP_PKEY_get1_RSA(pkey);
    EVP_PKEY_free(pkey);
    if (prVar1 != (rsa_st *)0x0) {
      if (x == (RSA **)0x0) {
        return prVar1;
      }
      RSA_free(*x);
      *x = prVar1;
      return prVar1;
    }
  }
  return (RSA *)0x0;
}

