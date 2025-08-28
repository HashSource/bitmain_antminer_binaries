
/* WARNING: Unknown calling convention */

char * bin2hex(uchar *p,size_t len)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  
  iVar2 = len * 2 + 1;
  pcVar3 = (char *)_cgcalloc((4 - iVar2 % 4) + iVar2,1,"util.c","bin2hex",0x315);
  pcVar5 = pcVar3;
  if (0 < (int)len) {
    sVar4 = 0;
    do {
      *pcVar5 = "0123456789abcdef"[p[sVar4] >> 4];
      pbVar1 = p + sVar4;
      sVar4 = sVar4 + 1;
      pcVar5[1] = "0123456789abcdef"[*pbVar1 & 0xf];
      pcVar5 = pcVar5 + 2;
    } while (sVar4 != len);
    pcVar5 = pcVar3 + len * 2;
  }
  *pcVar5 = '\0';
  return pcVar3;
}

