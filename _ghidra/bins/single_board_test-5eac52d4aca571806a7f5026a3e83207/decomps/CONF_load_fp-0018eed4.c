
lhash_st_CONF_VALUE * CONF_load_fp(lhash_st_CONF_VALUE *conf,FILE *fp,long *eline)

{
  BIO *bp;
  lhash_st_CONF_VALUE *plVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x67,7,"crypto/conf/conf_lib.c",0x4a);
    plVar1 = (lhash_st_CONF_VALUE *)0x0;
  }
  else {
    plVar1 = CONF_load_bio(conf,bp,eline);
    BIO_free(bp);
  }
  return plVar1;
}

