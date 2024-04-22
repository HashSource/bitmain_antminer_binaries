
int NCONF_load(CONF *conf,char *file,long *eline)

{
  int iVar1;
  
  if (conf == (CONF *)0x0) {
    ERR_put_error(0xe,0x71,0x69,DAT_0010d3dc,0x105);
    iVar1 = 0;
  }
  else {
    iVar1 = (*conf->meth->load)(conf,file,eline);
  }
  return iVar1;
}

