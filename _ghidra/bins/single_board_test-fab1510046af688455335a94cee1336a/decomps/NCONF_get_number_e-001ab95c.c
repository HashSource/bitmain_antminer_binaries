
int NCONF_get_number_e(CONF *conf,char *group,char *name,long *result)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  if (result == (long *)0x0) {
    ERR_put_error(0xe,0x70,0x43,"conf_lib.c",0x14f);
    iVar2 = 0;
  }
  else {
    pcVar1 = _CONF_get_string(conf,group,name);
    if (pcVar1 == (char *)0x0) {
      if (conf == (CONF *)0x0) {
        ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
      }
      else {
        ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x144);
        ERR_add_error_data(4,"group=",group," name=",name);
      }
      iVar2 = 0;
    }
    else {
      *result = 0;
      while( true ) {
        iVar2 = (*conf->meth->is_number)(conf,*pcVar1);
        if (iVar2 == 0) break;
        iVar3 = *result;
        iVar2 = (*conf->meth->to_int)(conf,*pcVar1);
        *result = iVar3 * 10 + iVar2;
        pcVar1 = pcVar1 + 1;
      }
      iVar2 = 1;
    }
  }
  return iVar2;
}

