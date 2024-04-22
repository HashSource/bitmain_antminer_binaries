
undefined4 add_next_timeout(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int **ppiVar5;
  
  ppiVar5 = *(int ***)(param_4 + 0x866c);
  piVar2 = *ppiVar5;
  if (*ppiVar5 != (int *)0x0) {
    do {
      piVar4 = (int *)piVar2[2];
      iVar1 = curlx_tvdiff(*(undefined4 *)*piVar2,((undefined4 *)*piVar2)[1],param_1,param_2);
      if (0 < iVar1) break;
      Curl_llist_remove(ppiVar5,piVar2);
      piVar2 = piVar4;
    } while (piVar4 != (int *)0x0);
    piVar2 = *ppiVar5;
    if (piVar2 != (int *)0x0) {
      uVar3 = ((undefined4 *)*piVar2)[1];
      *(undefined4 *)(param_4 + 0x864c) = *(undefined4 *)*piVar2;
      *(undefined4 *)(param_4 + 0x8650) = uVar3;
      Curl_llist_remove(ppiVar5,piVar2,0);
      uVar3 = Curl_splayinsert(*(undefined4 *)(param_4 + 0x864c),*(undefined4 *)(param_4 + 0x8650),
                               *(undefined4 *)(param_3 + 0x44),param_4 + 0x8654);
      *(undefined4 *)(param_3 + 0x44) = uVar3;
      return 0;
    }
  }
  *(undefined4 *)(param_4 + 0x8650) = 0;
  *(undefined4 *)(param_4 + 0x864c) = 0;
  return 0;
}

