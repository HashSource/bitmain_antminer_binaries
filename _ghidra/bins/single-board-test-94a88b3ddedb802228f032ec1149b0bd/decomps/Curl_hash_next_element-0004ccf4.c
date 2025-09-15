
undefined4 Curl_hash_next_element(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_1[2] != 0) {
    puVar4 = *(undefined4 **)(param_1[2] + 8);
    param_1[2] = (int)puVar4;
    if (puVar4 != (undefined4 *)0x0) goto LAB_0004cd02;
  }
  iVar3 = param_1[1];
  iVar5 = ((int *)*param_1)[4];
  if (iVar5 <= iVar3) {
    return 0;
  }
  iVar1 = *(int *)*param_1;
  puVar2 = (undefined4 *)(iVar1 + iVar3 * 4);
  puVar4 = (undefined4 *)**(int **)(iVar1 + iVar3 * 4);
  while (puVar4 == (undefined4 *)0x0) {
    iVar3 = iVar3 + 1;
    if (iVar3 == iVar5) {
      return 0;
    }
    puVar2 = puVar2 + 1;
    puVar4 = *(undefined4 **)*puVar2;
  }
  param_1[2] = (int)puVar4;
  param_1[1] = iVar3 + 1;
LAB_0004cd02:
  return *puVar4;
}

