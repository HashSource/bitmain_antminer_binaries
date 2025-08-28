
int CONF_dump_fp(lhash_st_CONF_VALUE *conf,FILE *out)

{
  BIO *bp;
  int iVar1;
  CONF local_1c;
  
  bp = BIO_new_fp(out,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x68,7,"conf_lib.c",0xcc);
    iVar1 = 0;
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_1c);
    local_1c.data = conf;
    iVar1 = (*(local_1c.meth)->dump)(&local_1c,bp);
    BIO_free(bp);
  }
  return iVar1;
}

