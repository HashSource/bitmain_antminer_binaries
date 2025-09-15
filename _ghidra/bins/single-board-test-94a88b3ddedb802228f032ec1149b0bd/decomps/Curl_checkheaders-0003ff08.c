
undefined4 Curl_checkheaders(int *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  
  sVar1 = strlen(param_2);
  puVar3 = *(undefined4 **)(*param_1 + 0x240);
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

