
char * sanitize_cookie_path(void)

{
  code **ppcVar1;
  char *pcVar2;
  size_t __n;
  char cVar3;
  int iVar4;
  bool bVar5;
  
  ppcVar1 = DAT_0003e98c;
  pcVar2 = (char *)(**DAT_0003e98c)();
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  __n = strlen(pcVar2);
  if (*pcVar2 == '\"') {
    memmove(pcVar2,pcVar2 + 1,__n);
    __n = __n - 1;
  }
  if (__n == 0) {
    if (*pcVar2 == '/') {
      return pcVar2;
    }
  }
  else {
    iVar4 = __n - 1;
    if (pcVar2[iVar4] == '\"') {
      pcVar2[iVar4] = '\0';
      if (*pcVar2 == '/') {
        if (iVar4 == 0) {
          return pcVar2;
        }
        cVar3 = pcVar2[__n - 2];
        bVar5 = cVar3 == '/';
        if (bVar5) {
          cVar3 = '\0';
        }
        if (!bVar5) {
          return pcVar2;
        }
        pcVar2[__n - 2] = cVar3;
        return pcVar2;
      }
    }
    else if (*pcVar2 == '/') {
      cVar3 = pcVar2[iVar4];
      bVar5 = cVar3 == '/';
      if (bVar5) {
        cVar3 = '\0';
      }
      if (!bVar5) {
        return pcVar2;
      }
      pcVar2[iVar4] = cVar3;
      return pcVar2;
    }
  }
  (**DAT_0003e990)(pcVar2);
  pcVar2 = (char *)(**ppcVar1)(DAT_0003e994);
  return pcVar2;
}

