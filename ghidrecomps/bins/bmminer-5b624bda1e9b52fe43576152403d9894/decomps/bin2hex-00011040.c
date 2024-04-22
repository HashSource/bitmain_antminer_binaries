
/* WARNING: Unknown calling convention */
/* Local variable s:char *[r0:4] conflicts with parameter, skipped. */

char * bin2hex(uchar *p,size_t len)

{
  byte *pbVar1;
  int iVar2;
  ssize_t slen;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  
  iVar2 = len * 2 + 1;
  pcVar3 = (char *)_cgcalloc((4 - iVar2 % 4) + iVar2,1,DAT_000110b8,DAT_000110bc,0x315);
  iVar2 = DAT_000110c0;
  pcVar5 = pcVar3;
  if (0 < (int)len) {
    sVar4 = 0;
    do {
      *pcVar5 = *(char *)(iVar2 + (uint)(p[sVar4] >> 4) + 0x454);
      pbVar1 = p + sVar4;
      sVar4 = sVar4 + 1;
      pcVar5[1] = *(char *)((*pbVar1 & 0xf) + iVar2 + 0x454);
      pcVar5 = pcVar5 + 2;
    } while (sVar4 != len);
    pcVar5 = pcVar3 + len * 2;
  }
  *pcVar5 = '\0';
  return pcVar3;
}

