
char * proxytype(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (param_1 == 0) {
    pcVar1 = "http:";
  }
  else {
    pcVar1 = "http0:";
    iVar2 = DAT_00045f14;
    do {
      if (*(int *)(iVar2 + 0xc) == param_1) {
        return pcVar1;
      }
      pcVar1 = *(char **)(iVar2 + 0x10);
      iVar2 = iVar2 + 8;
    } while (pcVar1 != (char *)0x0);
    pcVar1 = "invalid";
  }
  return pcVar1;
}

