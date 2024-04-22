
int checkhttpprefix(int param_1,undefined4 param_2)

{
  size_t sVar1;
  int iVar2;
  char **ppcVar3;
  char *__s;
  
  ppcVar3 = *(char ***)(param_1 + 0x2d4);
  while( true ) {
    if (ppcVar3 == (char **)0x0) {
      iVar2 = Curl_raw_nequal(DAT_0003fb88,param_2,5);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      return iVar2;
    }
    __s = *ppcVar3;
    sVar1 = strlen(__s);
    iVar2 = Curl_raw_nequal(__s,param_2,sVar1);
    if (iVar2 != 0) break;
    ppcVar3 = (char **)ppcVar3[1];
  }
  return 1;
}

