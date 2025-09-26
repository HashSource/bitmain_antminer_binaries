
char * dlfcn_name_converter(DSO *param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *__format;
  
  sVar1 = strlen(param_2);
  pcVar2 = strchr(param_2,0x2f);
  if (pcVar2 == (char *)0x0) {
    iVar3 = DSO_flags(param_1);
    if (iVar3 << 0x1e < 0) {
      iVar3 = sVar1 + 4;
    }
    else {
      iVar3 = sVar1 + 7;
    }
    pcVar2 = (char *)CRYPTO_malloc(iVar3,"dso_dlfcn.c",0x170);
    if (pcVar2 != (char *)0x0) {
      uVar4 = DSO_flags(param_1);
      if ((uVar4 & 2) == 0) {
        __format = "lib%s.so";
      }
      else {
        __format = "%s.so";
      }
      sprintf(pcVar2,__format,param_2);
      return pcVar2;
    }
  }
  else {
    pcVar2 = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",0x170);
    if (pcVar2 != (char *)0x0) {
      strcpy(pcVar2,param_2);
      return pcVar2;
    }
  }
  ERR_put_error(0x25,0x7b,0x6d,"dso_dlfcn.c",0x172);
  return (char *)0x0;
}

