
int checkhttpprefix(int param_1,undefined4 param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__s;
  
  puVar3 = *(undefined4 **)(param_1 + 0x2d4);
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = Curl_raw_nequal("HTTP/",param_2,5);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      return iVar2;
    }
    __s = (char *)*puVar3;
    sVar1 = strlen(__s);
    iVar2 = Curl_raw_nequal(__s,param_2,sVar1);
    if (iVar2 != 0) break;
    puVar3 = (undefined4 *)puVar3[1];
  }
  return 1;
}

