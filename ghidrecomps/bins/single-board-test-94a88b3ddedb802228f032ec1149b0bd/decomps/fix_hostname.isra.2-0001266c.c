
void fix_hostname_isra_2(undefined4 param_1,int param_2)

{
  size_t sVar1;
  char cVar2;
  byte *pbVar3;
  char *__s;
  bool bVar4;
  
  __s = *(char **)(param_2 + 8);
  *(char **)(param_2 + 0xc) = __s;
  sVar1 = strlen(__s);
  if (sVar1 != 0) {
    cVar2 = __s[sVar1 - 1];
    bVar4 = cVar2 == '.';
    if (bVar4) {
      cVar2 = '\0';
    }
    if (bVar4) {
      __s[sVar1 - 1] = cVar2;
    }
  }
  pbVar3 = (byte *)(*(int *)(param_2 + 8) + -1);
  do {
    pbVar3 = pbVar3 + 1;
    if (*pbVar3 == 0) {
      return;
    }
  } while (-1 < (int)((uint)*pbVar3 << 0x18));
  Curl_infof(param_1,DAT_000126ac);
  return;
}

