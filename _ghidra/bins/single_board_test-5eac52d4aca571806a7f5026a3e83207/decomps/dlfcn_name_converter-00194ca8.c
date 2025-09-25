
char * dlfcn_name_converter(DSO *param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  int num;
  
  sVar1 = strlen(param_2);
  pcVar2 = strchr(param_2,0x2f);
  if (pcVar2 == (char *)0x0) {
    num = sVar1 + 4;
    iVar3 = DSO_flags(param_1);
    if (-1 < iVar3 << 0x1e) {
      num = sVar1 + 7;
    }
    pcVar2 = (char *)CRYPTO_malloc(num,"crypto/dso/dso_dlfcn.c",0x10b);
    if (pcVar2 != (char *)0x0) {
      iVar3 = DSO_flags(param_1);
      if (-1 < iVar3 << 0x1e) {
        sprintf(pcVar2,"lib%s.so",param_2);
        return pcVar2;
      }
      sprintf(pcVar2,"%s.so",param_2);
      return pcVar2;
    }
  }
  else {
    pcVar2 = (char *)CRYPTO_malloc(sVar1 + 1,"crypto/dso/dso_dlfcn.c",0x10b);
    if (pcVar2 != (char *)0x0) {
      strcpy(pcVar2,param_2);
      return pcVar2;
    }
  }
  ERR_put_error(0x25,0x7b,0x6d,"crypto/dso/dso_dlfcn.c",0x10d);
  return (char *)0x0;
}

