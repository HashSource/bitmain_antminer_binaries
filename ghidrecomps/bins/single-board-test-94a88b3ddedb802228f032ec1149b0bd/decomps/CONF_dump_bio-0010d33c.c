
int CONF_dump_bio(lhash_st_CONF_VALUE *conf,BIO *out)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  int iVar3;
  CONF local_1c;
  
  ppCVar1 = DAT_0010d368;
  pCVar2 = *DAT_0010d368;
  if (pCVar2 == (CONF_METHOD *)0x0) {
    pCVar2 = NCONF_default();
    *ppCVar1 = pCVar2;
  }
  (*pCVar2->init)(&local_1c);
  local_1c.data = conf;
  iVar3 = (*(local_1c.meth)->dump)(&local_1c,out);
  return iVar3;
}

