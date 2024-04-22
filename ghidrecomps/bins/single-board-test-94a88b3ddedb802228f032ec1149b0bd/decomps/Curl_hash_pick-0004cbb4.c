
undefined4 Curl_hash_pick(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    iVar1 = (*(code *)param_1[1])(param_2,param_3,param_1[4],(code *)param_1[1],param_4);
    for (puVar3 = (undefined4 *)**(int **)(iVar2 + iVar1 * 4); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[2]) {
      puVar4 = (undefined4 *)*puVar3;
      iVar1 = (*(code *)param_1[2])(puVar4[1],puVar4[2],param_2,param_3);
      if (iVar1 != 0) {
        return *puVar4;
      }
    }
  }
  return 0;
}

