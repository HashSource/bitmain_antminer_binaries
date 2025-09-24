
int NCONF_load_fp(CONF *conf,FILE *fp,long *eline)

{
  BIO *bp;
  int iVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp != (BIO *)0x0) {
    iVar1 = NCONF_load_bio(conf,bp,eline);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(0xe,0x72,7,"crypto/conf/conf_lib.c",0xdf);
  return 0;
}

