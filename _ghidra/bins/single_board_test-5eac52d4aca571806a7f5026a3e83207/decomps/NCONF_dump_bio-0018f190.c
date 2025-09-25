
int NCONF_dump_bio(CONF *conf,BIO *out)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0018f196. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->dump)(conf,out);
    return iVar1;
  }
  ERR_put_error(0xe,0x69,0x69,"crypto/conf/conf_lib.c",0x158);
  return 0;
}

