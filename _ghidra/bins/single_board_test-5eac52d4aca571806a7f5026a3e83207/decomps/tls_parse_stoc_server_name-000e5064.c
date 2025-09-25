
undefined4 tls_parse_stoc_server_name(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  if (*(char **)(param_1 + 0x538) == (char *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x247,0x44,"ssl/statem/extensions_clnt.c",0x53d);
  }
  else {
    if (*(int *)(param_2 + 4) != 0) {
      ossl_statem_fatal(param_1,0x32,0x247,0x6e,"ssl/statem/extensions_clnt.c",0x543);
      return 0;
    }
    if (*(int *)(param_1 + 0x8c) != 0) {
      return 1;
    }
    iVar3 = *(int *)(param_1 + 0x474);
    if (*(int *)(iVar3 + 0x1cc) == 0) {
      pcVar1 = CRYPTO_strdup(*(char **)(param_1 + 0x538),"ssl/statem/extensions_clnt.c",0x54d);
      iVar2 = *(int *)(param_1 + 0x474);
      *(char **)(iVar3 + 0x1cc) = pcVar1;
      if (*(int *)(iVar2 + 0x1cc) != 0) {
        return 1;
      }
      ossl_statem_fatal(param_1,0x50,0x247,0x44,"ssl/statem/extensions_clnt.c",0x550);
    }
    else {
      ossl_statem_fatal(param_1,0x50,0x247,0x44,"ssl/statem/extensions_clnt.c",0x54a);
    }
  }
  return 0;
}

