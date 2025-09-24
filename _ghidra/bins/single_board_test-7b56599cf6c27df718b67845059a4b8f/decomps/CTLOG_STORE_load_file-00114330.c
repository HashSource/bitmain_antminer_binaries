
undefined4 CTLOG_STORE_load_file(undefined4 param_1,char *param_2)

{
  undefined4 *arg;
  CONF *pCVar1;
  int iVar2;
  char *list;
  undefined4 uVar3;
  
  arg = (undefined4 *)CRYPTO_zalloc(0xc,"crypto/ct/ct_log.c",0x3b);
  if (arg == (undefined4 *)0x0) {
    ERR_put_error(0x32,0x7a,0x41,"crypto/ct/ct_log.c",0x3e);
    return 0;
  }
  *arg = param_1;
  pCVar1 = NCONF_new((CONF_METHOD *)0x0);
  arg[1] = pCVar1;
  if (pCVar1 == (CONF *)0x0) {
    pCVar1 = (CONF *)0x0;
    uVar3 = 0;
    goto LAB_001143a6;
  }
  iVar2 = NCONF_load(pCVar1,param_2,(long *)0x0);
  if (iVar2 < 1) {
    iVar2 = 0xd1;
  }
  else {
    list = NCONF_get_string((CONF *)arg[1],(char *)0x0,"enabled_logs");
    if (list == (char *)0x0) {
      ERR_put_error(0x32,0x7b,0x6d,"crypto/ct/ct_log.c",0xd7);
      pCVar1 = (CONF *)arg[1];
      uVar3 = 0;
      goto LAB_001143a6;
    }
    iVar2 = CONF_parse_list(list,0x2c,1,(list_cb *)0x1141cd,arg);
    if ((iVar2 != 0) && (arg[2] == 0)) {
      pCVar1 = (CONF *)arg[1];
      uVar3 = 1;
      goto LAB_001143a6;
    }
    iVar2 = 0xdd;
  }
  ERR_put_error(0x32,0x7b,0x6d,"crypto/ct/ct_log.c",iVar2);
  pCVar1 = (CONF *)arg[1];
  uVar3 = 0;
LAB_001143a6:
  NCONF_free(pCVar1);
  CRYPTO_free(arg);
  return uVar3;
}

