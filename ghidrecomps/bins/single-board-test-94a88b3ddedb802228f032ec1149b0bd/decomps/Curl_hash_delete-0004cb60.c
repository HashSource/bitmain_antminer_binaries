
undefined4 Curl_hash_delete(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  
  iVar2 = *param_1;
  iVar1 = (*(code *)param_1[1])(param_2,param_3,param_1[4],(code *)param_1[1],param_4);
  ppiVar4 = *(int ***)(iVar2 + iVar1 * 4);
  piVar3 = *ppiVar4;
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return 1;
    }
    iVar1 = (*(code *)param_1[2])
                      (*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),param_2,param_3);
    if (iVar1 != 0) break;
    piVar3 = (int *)piVar3[2];
  }
  Curl_llist_remove(ppiVar4,piVar3,param_1);
  param_1[5] = param_1[5] + -1;
  return 0;
}

