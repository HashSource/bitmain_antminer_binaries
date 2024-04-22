
/* WARNING: Unknown calling convention */

char * proxytype(proxytypes_t proxytype)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = DAT_00010ffc;
  iVar3 = DAT_00010ff4;
  if (proxytype != 0) {
    do {
      if (*(char **)(iVar3 + 8) == (char *)0x0) {
        return DAT_00010ff8;
      }
      piVar1 = (int *)(iVar3 + 0xc);
      pcVar2 = *(char **)(iVar3 + 8);
      iVar3 = iVar3 + 8;
    } while (*piVar1 != proxytype);
  }
  return pcVar2;
}

