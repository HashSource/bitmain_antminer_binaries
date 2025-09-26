
lhash_st_CONF_VALUE * CONF_load(lhash_st_CONF_VALUE *conf,char *file,long *eline)

{
  BIO *bp;
  int iVar1;
  lhash_st_CONF_VALUE *plVar2;
  CONF local_24;
  
  bp = BIO_new_file(file,"rb");
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,100,2,"conf_lib.c",0x69);
    plVar2 = (lhash_st_CONF_VALUE *)0x0;
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&local_24);
    local_24.data = conf;
    iVar1 = (*(local_24.meth)->load_bio)(&local_24,bp,eline);
    plVar2 = local_24.data;
    if (iVar1 == 0) {
      plVar2 = (lhash_st_CONF_VALUE *)0x0;
    }
    BIO_free(bp);
  }
  return plVar2;
}

