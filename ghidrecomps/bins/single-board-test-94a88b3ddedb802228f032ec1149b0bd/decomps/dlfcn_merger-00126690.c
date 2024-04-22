
char * dlfcn_merger(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 1 - (int)param_3;
  if ((char *)0x1 < param_3) {
    iVar4 = 0;
  }
  if (param_2 == (char *)0x0 && param_3 == (char *)0x0) {
    ERR_put_error(0x25,0x82,0x43,DAT_00126778,0x124);
    return (char *)0x0;
  }
  if (iVar4 == 0) {
    if (param_2 == (char *)0x0) {
      sVar1 = strlen(param_3);
      pcVar3 = (char *)CRYPTO_malloc(sVar1 + 1,DAT_00126778,0x137);
      iVar4 = 0x139;
      if (pcVar3 != (char *)0x0) {
        strcpy(pcVar3,param_3);
        return pcVar3;
      }
      goto LAB_00126766;
    }
    if (*param_2 != '/') {
      sVar1 = strlen(param_3);
      sVar2 = strlen(param_2);
      iVar4 = sVar2 + sVar1;
      if ((sVar1 != 0) && (param_3[sVar1 - 1] == '/')) {
        sVar1 = sVar1 - 1;
        iVar4 = iVar4 + -1;
      }
      pcVar3 = (char *)CRYPTO_malloc(iVar4 + 2,DAT_00126778,0x14e);
      if (pcVar3 != (char *)0x0) {
        strcpy(pcVar3,param_3);
        pcVar3[sVar1] = '/';
        strcpy(pcVar3 + sVar1 + 1,param_2);
        return pcVar3;
      }
      iVar4 = 0x150;
      pcVar3 = (char *)0x0;
      goto LAB_00126766;
    }
  }
  sVar1 = strlen(param_2);
  pcVar3 = (char *)CRYPTO_malloc(sVar1 + 1,DAT_00126778,300);
  iVar4 = 0x12e;
  if (pcVar3 != (char *)0x0) {
    strcpy(pcVar3,param_2);
    return pcVar3;
  }
LAB_00126766:
  ERR_put_error(0x25,0x82,0x41,DAT_00126778,iVar4);
  return pcVar3;
}

