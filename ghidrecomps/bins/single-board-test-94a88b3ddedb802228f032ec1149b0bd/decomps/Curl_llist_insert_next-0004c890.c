
undefined4 Curl_llist_insert_next(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(**DAT_0004c8dc)(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    iVar4 = param_1[3];
    *puVar1 = param_3;
    if (iVar4 == 0) {
      *param_1 = (int)puVar1;
      puVar1[1] = 0;
      puVar1[2] = 0;
      param_1[1] = (int)puVar1;
    }
    else if (param_2 == 0) {
      iVar3 = *param_1;
      puVar1[1] = 0;
      puVar1[2] = iVar3;
      *(undefined4 **)(iVar3 + 4) = puVar1;
      *param_1 = (int)puVar1;
    }
    else {
      uVar2 = *(undefined4 *)(param_2 + 8);
      puVar1[1] = param_2;
      puVar1[2] = uVar2;
      if (*(int *)(param_2 + 8) == 0) {
        param_1[1] = (int)puVar1;
      }
      else {
        *(undefined4 **)(*(int *)(param_2 + 8) + 4) = puVar1;
      }
      *(undefined4 **)(param_2 + 8) = puVar1;
    }
    param_1[3] = iVar4 + 1;
    return 1;
  }
  return 0;
}

