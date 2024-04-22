
int Curl_unix2addr(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  undefined2 *puVar3;
  size_t sVar4;
  
  ppcVar1 = DAT_0004f8e8;
  iVar2 = (**DAT_0004f8e8)(1,0x20,param_3,*DAT_0004f8e8,param_4);
  if (iVar2 != 0) {
    puVar3 = (undefined2 *)(**ppcVar1)(1,0x6e);
    *(undefined2 **)(iVar2 + 0x18) = puVar3;
    if (puVar3 == (undefined2 *)0x0) {
      (**DAT_0004f8ec)(iVar2);
      iVar2 = 0;
    }
    else {
      sVar4 = strlen(param_1);
      ppcVar1 = DAT_0004f8ec;
      if (sVar4 < 0x6c) {
        *(undefined4 *)(iVar2 + 4) = 1;
        *(undefined4 *)(iVar2 + 8) = 1;
        *(undefined4 *)(iVar2 + 0x10) = 0x6e;
        *puVar3 = 1;
        memcpy(puVar3 + 1,param_1,sVar4 + 1);
      }
      else {
        (**DAT_0004f8ec)(puVar3);
        (**ppcVar1)(iVar2);
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

