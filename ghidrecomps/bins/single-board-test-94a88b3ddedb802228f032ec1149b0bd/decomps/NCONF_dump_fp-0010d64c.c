
int NCONF_dump_fp(CONF *conf,FILE *out)

{
  BIO *bp;
  int iVar1;
  
  bp = BIO_new_fp(out,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x6a,7,DAT_0010d6a4,0x166);
    iVar1 = 0;
  }
  else {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x69,0x69,DAT_0010d6a4,0x172);
      iVar1 = 0;
    }
    else {
      iVar1 = (*conf->meth->dump)(conf,bp);
    }
    BIO_free(bp);
  }
  return iVar1;
}

