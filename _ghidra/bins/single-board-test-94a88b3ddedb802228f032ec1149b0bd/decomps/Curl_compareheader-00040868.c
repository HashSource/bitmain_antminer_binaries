
int Curl_compareheader(int param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  ushort **ppuVar3;
  char *pcVar4;
  char *__s;
  uint uVar5;
  
  sVar1 = strlen(param_2);
  iVar2 = Curl_raw_nequal(param_1,param_2,sVar1);
  if (iVar2 != 0) {
    uVar5 = (uint)*(byte *)(param_1 + sVar1);
    __s = (char *)(param_1 + sVar1);
    if (uVar5 != 0) {
      ppuVar3 = __ctype_b_loc();
      do {
        pcVar4 = __s + 1;
        if (-1 < (int)((uint)(*ppuVar3)[uVar5] << 0x12)) break;
        uVar5 = (uint)(byte)__s[1];
        __s = pcVar4;
      } while (uVar5 != 0);
    }
    pcVar4 = strchr(__s,0xd);
    if ((pcVar4 == (char *)0x0) && (pcVar4 = strchr(__s,10), pcVar4 == (char *)0x0)) {
      pcVar4 = (char *)__rawmemchr(__s);
    }
    uVar5 = (int)pcVar4 - (int)__s;
    sVar1 = strlen(param_3);
    if (uVar5 < sVar1) {
      return 0;
    }
    while( true ) {
      uVar5 = uVar5 - 1;
      iVar2 = Curl_raw_nequal(__s,param_3,sVar1);
      if (iVar2 != 0) break;
      __s = __s + 1;
      if (uVar5 < sVar1) {
        return 0;
      }
    }
    iVar2 = 1;
  }
  return iVar2;
}

