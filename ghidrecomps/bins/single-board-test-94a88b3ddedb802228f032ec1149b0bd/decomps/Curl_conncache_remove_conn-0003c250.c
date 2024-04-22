
void Curl_conncache_remove_conn(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x470);
  if (iVar3 != 0) {
    for (piVar1 = **(int ***)(iVar3 + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if (param_2 == *piVar1) {
        Curl_llist_remove(*(int ***)(iVar3 + 8),piVar1,0);
        iVar2 = *(int *)(iVar3 + 4) + -1;
        *(int *)(iVar3 + 4) = iVar2;
        *(undefined4 *)(param_2 + 0x470) = 0;
        if (iVar2 != 0) goto LAB_0003c282;
        goto LAB_0003c28c;
      }
    }
    if (*(int *)(iVar3 + 4) == 0) {
LAB_0003c28c:
      conncache_remove_bundle(param_1,iVar3);
    }
LAB_0003c282:
    if (param_1 != 0) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    }
  }
  return;
}

