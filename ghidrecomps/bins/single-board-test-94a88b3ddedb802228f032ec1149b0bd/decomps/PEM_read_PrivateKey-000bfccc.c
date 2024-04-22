
EVP_PKEY * PEM_read_PrivateKey(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  EVP_PKEY *pEVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x7c,7,DAT_000bfd20,0xdd);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pEVar1 = PEM_read_bio_PrivateKey(bp,x,cb,u);
    BIO_free(bp);
  }
  return pEVar1;
}

