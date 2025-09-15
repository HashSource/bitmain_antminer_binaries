
char * sanitize_cookie_path(void)

{
  char *pcVar1;
  size_t __n;
  char cVar2;
  int iVar3;
  bool bVar4;
  
  pcVar1 = (char *)(*Curl_cstrdup)();
  if (pcVar1 == (char *)0x0) {
    return (char *)0x0;
  }
  __n = strlen(pcVar1);
  if (*pcVar1 == '\"') {
    memmove(pcVar1,pcVar1 + 1,__n);
    __n = __n - 1;
  }
  if (__n == 0) {
    if (*pcVar1 == '/') {
      return pcVar1;
    }
  }
  else {
    iVar3 = __n - 1;
    if (pcVar1[iVar3] == '\"') {
      pcVar1[iVar3] = '\0';
      if (*pcVar1 == '/') {
        if (iVar3 == 0) {
          return pcVar1;
        }
        cVar2 = pcVar1[__n - 2];
        bVar4 = cVar2 == '/';
        if (bVar4) {
          cVar2 = '\0';
        }
        if (!bVar4) {
          return pcVar1;
        }
        pcVar1[__n - 2] = cVar2;
        return pcVar1;
      }
    }
    else if (*pcVar1 == '/') {
      cVar2 = pcVar1[iVar3];
      bVar4 = cVar2 == '/';
      if (bVar4) {
        cVar2 = '\0';
      }
      if (!bVar4) {
        return pcVar1;
      }
      pcVar1[iVar3] = cVar2;
      return pcVar1;
    }
  }
  (*Curl_cfree)(pcVar1);
  pcVar1 = (char *)(*Curl_cstrdup)(&DAT_00135588);
  return pcVar1;
}

