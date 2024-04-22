
int multi_socket(int param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined auStack_140 [144];
  undefined auStack_b0 [148];
  
  curlx_tvnow(&local_148);
  if (param_2 != 0) {
    iVar3 = curl_multi_perform(param_1,param_5);
    if (iVar3 == 1) {
      return 1;
    }
    for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      singlesocket(param_1,piVar1);
    }
    return iVar3;
  }
  if (param_3 == -1) {
    *(undefined *)(param_1 + 0xbc) = 0;
    *(undefined *)(param_1 + 0xbd) = 0;
    *(undefined *)(param_1 + 0xbe) = 0;
    *(undefined *)(param_1 + 0xbf) = 0;
    *(undefined *)(param_1 + 0xc0) = 0;
    *(undefined *)(param_1 + 0xc1) = 0;
    *(undefined *)(param_1 + 0xc2) = 0;
    *(undefined *)(param_1 + 0xc3) = 0;
    iVar3 = 0;
    goto LAB_0003b668;
  }
  piVar1 = (int *)sh_getentry(param_1 + 0x48,param_3);
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
    goto LAB_0003b668;
  }
  iVar5 = *piVar1;
  if (*(int *)(iVar5 + 0x879c) != -0x3f212453) {
    return 4;
  }
  iVar3 = *(int *)(iVar5 + 8);
  if (iVar3 != 0) {
    if (((((param_4 & 2) != 0) && (*(int ***)(iVar3 + 600) != (int **)0x0)) &&
        (piVar1 = **(int ***)(iVar3 + 600), piVar1 != (int *)0x0)) ||
       ((((param_4 & 1) != 0 && (*(int ***)(iVar3 + 0x25c) != (int **)0x0)) &&
        (piVar1 = **(int ***)(iVar3 + 0x25c), piVar1 != (int *)0x0)))) {
      iVar5 = *piVar1;
      iVar3 = *(int *)(iVar5 + 8);
      if (iVar3 == 0) goto LAB_0003b71e;
    }
    if (-1 < *(int *)(*(int *)(iVar3 + 0x218) + 0x40) << 0x1c) {
      *(uint *)(iVar3 + 0x450) = param_4;
    }
  }
LAB_0003b71e:
  sigpipe_ignore_isra_2(*(undefined *)(iVar5 + 0x324),auStack_140);
  iVar3 = multi_runsingle(param_1,local_148,uStack_144,iVar5);
  sigpipe_restore(auStack_140);
  iVar4 = *(int *)(iVar5 + 8);
  if ((iVar4 != 0) && ((*(uint *)(*(int *)(iVar4 + 0x218) + 0x40) & 8) == 0)) {
    *(undefined4 *)(iVar4 + 0x450) = 0;
  }
  if (iVar3 < 1) {
    singlesocket(param_1,iVar5);
  }
  curlx_tvnow(&local_148);
LAB_0003b668:
  while( true ) {
    uVar2 = Curl_splaygetbest(local_148,uStack_144,*(undefined4 *)(param_1 + 0x44),&local_14c);
    *(undefined4 *)(param_1 + 0x44) = uVar2;
    if (local_14c == 0) break;
    iVar5 = *(int *)(local_14c + 0x14);
    add_next_timeout(local_148,uStack_144,param_1,iVar5);
    if (local_14c == 0) break;
    if (iVar5 != 0) {
      sigpipe_ignore_isra_2(*(undefined *)(iVar5 + 0x324),auStack_b0);
      iVar3 = multi_runsingle(param_1,local_148,uStack_144,iVar5);
      sigpipe_restore(auStack_b0);
      if (iVar3 < 1) {
        singlesocket(param_1,iVar5);
      }
    }
  }
  *param_5 = *(undefined4 *)(param_1 + 0x10);
  return iVar3;
}

