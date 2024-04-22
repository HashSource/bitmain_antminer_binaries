
int NCONF_load_bio(CONF *conf,BIO *bp,long *eline)

{
  int iVar1;
  
  if (conf == (CONF *)0x0) {
    ERR_put_error(0xe,0x6e,0x69,DAT_0010d468,0x11e);
    iVar1 = 0;
  }
  else {
    iVar1 = (*conf->meth->load_bio)(conf,bp,eline);
  }
  return iVar1;
}

