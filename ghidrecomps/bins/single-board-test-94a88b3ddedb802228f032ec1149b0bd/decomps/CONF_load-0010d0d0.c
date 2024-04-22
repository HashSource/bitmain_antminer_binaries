
lhash_st_CONF_VALUE * CONF_load(lhash_st_CONF_VALUE *conf,char *file,long *eline)

{
  CONF_METHOD **ppCVar1;
  BIO *bp;
  CONF_METHOD *pCVar2;
  int iVar3;
  lhash_st_CONF_VALUE *plVar4;
  CONF local_24;
  
  bp = BIO_new_file(file,DAT_0010d130);
  ppCVar1 = DAT_0010d134;
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,100,2,DAT_0010d138,0x69);
    plVar4 = (lhash_st_CONF_VALUE *)0x0;
  }
  else {
    pCVar2 = *DAT_0010d134;
    if (pCVar2 == (CONF_METHOD *)0x0) {
      pCVar2 = NCONF_default();
      *ppCVar1 = pCVar2;
    }
    (*pCVar2->init)(&local_24);
    local_24.data = conf;
    iVar3 = (*(local_24.meth)->load_bio)(&local_24,bp,eline);
    plVar4 = local_24.data;
    if (iVar3 == 0) {
      plVar4 = (lhash_st_CONF_VALUE *)0x0;
    }
    BIO_free(bp);
  }
  return plVar4;
}

