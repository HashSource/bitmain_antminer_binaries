
void Curl_debug(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  size_t sVar1;
  int iVar2;
  char acStack_b8 [164];
  
  if ((((*(char *)(param_1 + 0x2f8) != '\0') && (param_5 != 0)) && (*(int *)(param_5 + 0x9c) != 0))
     && (param_2 - 1U < 4)) {
    iVar2 = (param_2 - 1U) * 4;
    if (*(int *)(CSWTCH_24 + iVar2) != 0) {
      curl_msnprintf(acStack_b8,0xa0,"[%s %s %s]",*(undefined4 *)(CSWTCH_25 + iVar2),
                     *(int *)(CSWTCH_24 + iVar2),*(int *)(param_5 + 0x9c));
      sVar1 = strlen(acStack_b8);
      iVar2 = showit(param_1,0,acStack_b8,sVar1);
      if (iVar2 != 0) {
        return;
      }
    }
  }
  showit(param_1,param_2,param_3,param_4);
  return;
}

