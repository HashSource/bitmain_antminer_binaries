
int NCONF_load(CONF *conf,char *file,long *eline)

{
  int iVar1;
  
  if (conf != (CONF *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0019305e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*conf->meth->load)(conf,file,eline);
    return iVar1;
  }
  ERR_put_error(0xe,0x71,0x69,"crypto/conf/conf_lib.c",0xd2);
  return 0;
}

