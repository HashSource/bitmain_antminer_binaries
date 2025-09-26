
char * dlfcn_merger(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 == (char *)0x0 && param_3 == (char *)0x0) {
    ERR_put_error(0x25,0x82,0x43,"crypto/dso/dso_dlfcn.c",0xc9);
    return (char *)0x0;
  }
  if (param_3 == (char *)0x0) {
LAB_001a2e0c:
    pcVar4 = CRYPTO_strdup(param_2,"crypto/dso/dso_dlfcn.c",0xd1);
    iVar3 = 0xd3;
  }
  else {
    if (param_2 != (char *)0x0) {
      if (*param_2 != '/') {
        sVar1 = strlen(param_3);
        sVar2 = strlen(param_2);
        iVar3 = sVar2 + sVar1;
        if ((sVar1 != 0) && (param_3[sVar1 - 1] == '/')) {
          sVar1 = sVar1 - 1;
          iVar3 = iVar3 + -1;
        }
        pcVar4 = (char *)CRYPTO_malloc(iVar3 + 2,"crypto/dso/dso_dlfcn.c",0xf1);
        if (pcVar4 != (char *)0x0) {
          strcpy(pcVar4,param_3);
          pcVar4[sVar1] = '/';
          strcpy(pcVar4 + sVar1 + 1,param_2);
          return pcVar4;
        }
        iVar3 = 0xf3;
        pcVar4 = (char *)0x0;
        goto LAB_001a2e2e;
      }
      goto LAB_001a2e0c;
    }
    pcVar4 = CRYPTO_strdup(param_3,"crypto/dso/dso_dlfcn.c",0xdb);
    iVar3 = 0xdd;
  }
  if (pcVar4 != (char *)0x0) {
    return pcVar4;
  }
LAB_001a2e2e:
  ERR_put_error(0x25,0x82,0x41,"crypto/dso/dso_dlfcn.c",iVar3);
  return pcVar4;
}

