
int NCONF_dump_bio(CONF *conf,BIO *out)

{
  int iVar1;
  
  if (conf == (CONF *)0x0) {
    ERR_put_error(0xe,0x69,0x69,DAT_0010d6d0,0x172);
    iVar1 = 0;
  }
  else {
    iVar1 = (*conf->meth->dump)(conf,out);
  }
  return iVar1;
}

