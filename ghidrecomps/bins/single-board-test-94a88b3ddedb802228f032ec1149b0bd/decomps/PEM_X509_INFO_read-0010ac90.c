
stack_st_X509_INFO * PEM_X509_INFO_read(FILE *fp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  stack_st_X509_INFO *psVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x73,7,DAT_0010ace4,0x51);
    psVar1 = (stack_st_X509_INFO *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    psVar1 = PEM_X509_INFO_read_bio(bp,sk,cb,u);
    BIO_free(bp);
  }
  return psVar1;
}

