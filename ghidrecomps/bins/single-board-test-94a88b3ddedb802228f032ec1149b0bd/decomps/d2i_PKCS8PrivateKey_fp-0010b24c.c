
EVP_PKEY * d2i_PKCS8PrivateKey_fp(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  BIO *bp;
  EVP_PKEY *pEVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x79,7,DAT_0010b28c,0xf5);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar1 = d2i_PKCS8PrivateKey_bio(bp,x,cb,u);
    BIO_free(bp);
  }
  return pEVar1;
}

