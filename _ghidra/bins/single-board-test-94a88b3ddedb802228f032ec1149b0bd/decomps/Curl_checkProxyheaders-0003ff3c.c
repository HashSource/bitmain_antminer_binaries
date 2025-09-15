
undefined4 Curl_checkProxyheaders(int *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  
  sVar1 = strlen(param_2);
  iVar2 = *param_1;
  if ((*(char *)((int)param_1 + 0x1ef) == '\0') || (*(char *)(iVar2 + 0x24c) == '\0')) {
    puVar3 = *(undefined4 **)(iVar2 + 0x240);
  }
  else {
    puVar3 = *(undefined4 **)(iVar2 + 0x244);
  }
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = Curl_raw_nequal(*puVar3,param_2,sVar1);
    if (iVar2 != 0) break;
    puVar3 = (undefined4 *)puVar3[1];
  }
  return *puVar3;
}

