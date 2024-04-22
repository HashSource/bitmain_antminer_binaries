
int Curl_ftpsendf(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  bool bVar5;
  int local_430;
  undefined4 *local_42c;
  undefined2 uStack_428;
  undefined auStack_426 [1026];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar4 = &uStack_428;
  local_42c = &uStack_8;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar2 = curl_mvsnprintf(puVar4,0x3fd,param_2,local_42c);
  local_430 = 0;
  iVar3 = iVar2 + 2;
  uVar1 = *(undefined *)(DAT_0005e8f8 + 1);
  *(undefined2 *)((int)puVar4 + iVar2) = *DAT_0005e8f8;
  *(undefined *)((int)&uStack_428 + iVar2 + 2) = uVar1;
  do {
    while( true ) {
      iVar2 = Curl_write(param_1,param_1[0x55],puVar4,iVar3,&local_430);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (*(char *)(*param_1 + 0x310) != '\0') break;
      bVar5 = iVar3 == local_430;
      puVar4 = (undefined2 *)((int)puVar4 + local_430);
      iVar3 = iVar3 - local_430;
      if (bVar5) {
        return 0;
      }
    }
    Curl_debug(*param_1,2,puVar4,local_430,param_1);
    bVar5 = iVar3 != local_430;
    puVar4 = (undefined2 *)((int)puVar4 + local_430);
    iVar3 = iVar3 - local_430;
  } while (bVar5);
  return 0;
}

