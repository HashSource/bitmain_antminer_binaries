
int Curl_ftpsendf(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  bool bVar4;
  int local_430;
  undefined4 *local_42c;
  undefined2 uStack_428;
  undefined1 auStack_426 [1026];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar3 = &uStack_428;
  local_42c = &uStack_8;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = curl_mvsnprintf(puVar3,0x3fd,param_2,local_42c);
  local_430 = 0;
  iVar2 = iVar1 + 2;
  *(undefined2 *)((int)puVar3 + iVar1) = 0xa0d;
  auStack_426[iVar1] = 0;
  do {
    while( true ) {
      iVar1 = Curl_write(param_1,param_1[0x55],puVar3,iVar2,&local_430);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (*(char *)(*param_1 + 0x310) != '\0') break;
      bVar4 = iVar2 == local_430;
      puVar3 = (undefined2 *)((int)puVar3 + local_430);
      iVar2 = iVar2 - local_430;
      if (bVar4) {
        return 0;
      }
    }
    Curl_debug(*param_1,2,puVar3,local_430,param_1);
    bVar4 = iVar2 != local_430;
    puVar3 = (undefined2 *)((int)puVar3 + local_430);
    iVar2 = iVar2 - local_430;
  } while (bVar4);
  return 0;
}

