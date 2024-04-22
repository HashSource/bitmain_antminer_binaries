
void Curl_hash_clean_with_criterium(int *param_1,undefined4 param_2,code *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if ((param_1 != (int *)0x0) && (iVar1 = param_1[4], 0 < iVar1)) {
    iVar5 = 0;
    do {
      puVar4 = *(undefined4 **)(*param_1 + iVar5 * 4);
      puVar2 = (undefined4 *)*puVar4;
      if (puVar2 != (undefined4 *)0x0) {
        do {
          puVar3 = (undefined4 *)puVar2[2];
          if ((param_3 == (code *)0x0) ||
             (iVar1 = (*param_3)(param_2,*(undefined4 *)*puVar2), iVar1 != 0)) {
            Curl_llist_remove(puVar4,puVar2,param_1);
            param_1[5] = param_1[5] + -1;
          }
          puVar2 = puVar3;
        } while (puVar3 != (undefined4 *)0x0);
        iVar1 = param_1[4];
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
    return;
  }
  return;
}

