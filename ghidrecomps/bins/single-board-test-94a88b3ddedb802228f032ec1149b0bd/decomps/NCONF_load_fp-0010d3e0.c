
int NCONF_load_fp(CONF *conf,FILE *fp,long *eline)

{
  BIO *bp;
  int iVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x72,7,DAT_0010d43c,0x112);
    iVar1 = 0;
  }
  else {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x6e,0x69,DAT_0010d43c,0x11e);
      iVar1 = 0;
    }
    else {
      iVar1 = (*conf->meth->load_bio)(conf,bp,eline);
    }
    BIO_free(bp);
  }
  return iVar1;
}

