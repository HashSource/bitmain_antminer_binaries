
char * Strcasestr(char *haystack,char *needle)

{
  int iVar1;
  char *pcVar2;
  char *needle_local;
  char *haystack_local;
  int ofs;
  char *ret;
  char *lowneedle;
  char *lowhay;
  int nlen;
  int hlen;
  int i;
  
  if ((haystack == (char *)0x0) || (needle == (char *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    haystack_local = haystack;
    hlen = strlen(haystack);
    nlen = strlen(needle);
    if ((hlen == 0) || (nlen == 0)) {
      pcVar2 = (char *)0x0;
    }
    else {
      iVar1 = -(hlen + 0xeU & 0xfffffff8);
      lowhay = (char *)((int)&needle_local + iVar1);
      lowneedle = (char *)((int)&needle_local + (iVar1 - (nlen + 0xeU & 0xfffffff8)));
      for (i = 0; i < hlen; i = i + 1) {
        pcVar2 = lowhay + i;
        iVar1 = tolower((uint)(byte)haystack_local[i]);
        *pcVar2 = (char)iVar1;
      }
      for (i = 0; i < nlen; i = i + 1) {
        pcVar2 = lowneedle + i;
        iVar1 = tolower((uint)(byte)needle[i]);
        *pcVar2 = (char)iVar1;
      }
      pcVar2 = strstr(lowhay,lowneedle);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = (char *)0x0;
      }
      else {
        pcVar2 = haystack_local + ((int)pcVar2 - (int)lowhay);
      }
    }
  }
  return pcVar2;
}

