
int NCONF_get_number_e(CONF *conf,char *group,char *name,long *result)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  int iVar6;
  
  if (result == (long *)0x0) {
    ERR_put_error(0xe,0x70,0x43,"crypto/conf/conf_lib.c",0x129);
    return 0;
  }
  pcVar2 = NCONF_get_string(conf,group,name);
  if (pcVar2 != (char *)0x0) {
    if (conf == (CONF *)0x0) {
      pcVar5 = (_func_3813 *)0x192fb1;
      pcVar4 = (code *)0x192fb9;
    }
    else {
      pcVar4 = conf->meth->is_number;
      if (pcVar4 == (_func_3812 *)0x0) {
        pcVar4 = (code *)0x192fb9;
      }
      pcVar5 = conf->meth->to_int;
      if (pcVar5 == (_func_3813 *)0x0) {
        pcVar5 = (code *)0x192fb1;
      }
    }
    iVar6 = 0;
    while( true ) {
      iVar3 = (*pcVar4)(conf,*pcVar2);
      if (iVar3 == 0) break;
      iVar3 = (*pcVar5)(conf,*pcVar2);
      bVar1 = (0x7fffffff - iVar3) / 10 < iVar6;
      pcVar2 = pcVar2 + 1;
      iVar6 = iVar3 + iVar6 * 10;
      if (bVar1) {
        ERR_put_error(0xe,0x70,0x79,"crypto/conf/conf_lib.c",0x13c);
        return 0;
      }
    }
    pcVar2 = (char *)0x1;
    *result = iVar6;
  }
  return (int)pcVar2;
}

