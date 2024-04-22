
int CONF_dump_fp(lhash_st_CONF_VALUE *conf,FILE *out)

{
  CONF_METHOD **ppCVar1;
  BIO *bp;
  CONF_METHOD *pCVar2;
  int iVar3;
  CONF local_1c;
  
  bp = BIO_new_fp(out,0);
  ppCVar1 = DAT_0010d334;
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xe,0x68,7,DAT_0010d338,0xcc);
    iVar3 = 0;
  }
  else {
    pCVar2 = *DAT_0010d334;
    if (pCVar2 == (CONF_METHOD *)0x0) {
      pCVar2 = NCONF_default();
      *ppCVar1 = pCVar2;
    }
    (*pCVar2->init)(&local_1c);
    local_1c.data = conf;
    iVar3 = (*(local_1c.meth)->dump)(&local_1c,bp);
    BIO_free(bp);
  }
  return iVar3;
}

