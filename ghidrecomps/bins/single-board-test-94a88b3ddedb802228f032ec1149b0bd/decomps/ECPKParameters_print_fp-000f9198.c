
int ECPKParameters_print_fp(FILE *fp,EC_GROUP *x,int off)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x10,0x96,7,DAT_000f91e4,0x4d);
    iVar1 = 0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = ECPKParameters_print(bp,x,off);
    BIO_free(bp);
  }
  return iVar1;
}

