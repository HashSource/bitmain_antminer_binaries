
int Curl_unix2addr(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  size_t sVar3;
  
  iVar1 = (*Curl_ccalloc)(1,0x20,param_3,Curl_ccalloc,param_4);
  if (iVar1 != 0) {
    puVar2 = (undefined2 *)(*Curl_ccalloc)(1,0x6e);
    *(undefined2 **)(iVar1 + 0x18) = puVar2;
    if (puVar2 == (undefined2 *)0x0) {
      (*Curl_cfree)(iVar1);
      iVar1 = 0;
    }
    else {
      sVar3 = strlen(param_1);
      if (sVar3 < 0x6c) {
        *(undefined4 *)(iVar1 + 4) = 1;
        *(undefined4 *)(iVar1 + 8) = 1;
        *(undefined4 *)(iVar1 + 0x10) = 0x6e;
        *puVar2 = 1;
        memcpy(puVar2 + 1,param_1,sVar3 + 1);
      }
      else {
        (*Curl_cfree)(puVar2);
        (*Curl_cfree)(iVar1);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

