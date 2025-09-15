
size_t BUF_strlcpy(char *dst,char *src,size_t siz)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  size_t sVar5;
  
  pcVar3 = dst;
  if (siz < 2) {
    if (siz == 0) goto LAB_000a8b66;
    sVar5 = 0;
  }
  else {
    cVar4 = *src;
    if (cVar4 == '\0') {
      sVar5 = 0;
    }
    else {
      pcVar2 = dst;
      pcVar1 = src + 1;
      do {
        src = pcVar1;
        siz = siz - 1;
        pcVar3 = pcVar2 + 1;
        *pcVar2 = cVar4;
        sVar5 = (int)pcVar3 - (int)dst;
        if (siz == 1) break;
        cVar4 = *src;
        pcVar2 = pcVar3;
        pcVar1 = src + 1;
      } while (cVar4 != '\0');
    }
  }
  *pcVar3 = '\0';
  siz = sVar5;
LAB_000a8b66:
  sVar5 = strlen(src);
  return siz + sVar5;
}

