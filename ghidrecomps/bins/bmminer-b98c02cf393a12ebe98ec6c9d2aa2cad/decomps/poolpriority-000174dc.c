
void poolpriority(int param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 local_38;
  char cStack_31;
  int local_30 [3];
  
  local_38 = param_4;
  local_30[0] = param_1;
  local_30[1] = param_4;
  if (total_pools == 0) {
    message(param_1,8,0);
  }
  else if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x19,0);
  }
  else {
    iVar1 = -(total_pools + 7U & 0xfffffff8);
    pcVar12 = (char *)((int)local_30 + iVar1);
    iVar2 = -(total_pools * 4 + 10U & 0xfffffff8);
    puVar13 = (undefined4 *)((int)local_30 + iVar2 + iVar1);
    if (0 < total_pools) {
      pcVar9 = pcVar12;
      do {
        pcVar7 = pcVar9 + 1;
        *pcVar9 = '\0';
        pcVar9 = pcVar7;
      } while (pcVar7 != pcVar12 + total_pools);
    }
    iVar11 = 0;
    do {
      pcVar7 = strchr(param_3,0x2c);
      pcVar9 = pcVar7;
      if (pcVar7 != (char *)0x0) {
        pcVar9 = pcVar7 + 1;
        *pcVar7 = '\0';
      }
      lVar5 = strtol(param_3,(char **)0x0,10);
      piVar4 = pools;
      iVar3 = total_pools;
      iVar14 = iVar11 + 1;
      if ((lVar5 < 0) || (total_pools <= lVar5)) {
        *(int *)((int)&local_38 + iVar2 + iVar1) = local_30[1];
        message(local_30[0],0x1a,lVar5,0);
        return;
      }
      if (pcVar12[lVar5] != '\0') {
        *(int *)((int)&local_38 + iVar2 + iVar1) = local_30[1];
        message(local_30[0],0x4a,lVar5,0);
        return;
      }
      puVar13[lVar5] = iVar11;
      pcVar12[lVar5] = '\x01';
    } while ((pcVar9 != (char *)0x0) && (iVar11 = iVar14, param_3 = pcVar9, *pcVar9 != '\0'));
    pcVar7 = pcVar12 + total_pools;
    pcVar9 = pcVar12;
    piVar10 = pools;
    do {
      pcVar6 = pcVar9 + 1;
      if (*pcVar9 != '\0') {
        *(undefined4 *)(*piVar10 + 4) = *puVar13;
      }
      piVar10 = piVar10 + 1;
      puVar13 = puVar13 + 1;
      pcVar9 = pcVar6;
    } while (pcVar7 != pcVar6);
    iVar11 = 0;
    do {
      iVar8 = 0;
      pcVar9 = &cStack_31 + iVar1;
      do {
        pcVar9 = pcVar9 + 1;
        if ((*pcVar9 == '\0') && (*(int *)(piVar4[iVar8] + 4) == iVar11)) {
          *(int *)(piVar4[iVar8] + 4) = iVar14;
          iVar14 = iVar14 + 1;
          pcVar12[iVar8] = '\x01';
          break;
        }
        iVar8 = iVar8 + 1;
      } while (iVar3 != iVar8);
      iVar11 = iVar11 + 1;
    } while (iVar3 != iVar11);
    iVar11 = current_pool();
    if (*(int *)(iVar11 + 4) != 0) {
      switch_pools(0);
    }
    *(int *)((int)&local_38 + iVar2 + iVar1) = local_30[1];
    message(local_30[0],0x49,0);
  }
  return;
}

