
/* WARNING: Unknown calling convention */

void poolpriority(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int iVar2;
  int iVar3;
  pool **pppVar4;
  pool **pppVar5;
  long paramid;
  pool *ppVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  _Bool (*pools_changed) [167071];
  char *pcVar13;
  io_data *local_30;
  uint local_2c;
  
  local_2c = (uint)isjson;
  local_30 = io_data;
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
  }
  else {
    iVar1 = -(total_pools + 7U & 0xfffffff8);
    pcVar13 = (char *)((int)&local_30 + iVar1);
    iVar2 = -(total_pools * 4 + 10U & 0xfffffff8);
    iVar11 = iVar2 + iVar1 + -0x30;
    if (0 < total_pools) {
      pcVar12 = pcVar13;
      do {
        pcVar7 = pcVar12 + 1;
        *pcVar12 = '\0';
        pcVar12 = pcVar7;
      } while (pcVar7 != pcVar13 + total_pools);
    }
    iVar9 = 0;
    do {
      pcVar7 = strchr(param,0x2c);
      pcVar12 = pcVar7;
      if (pcVar7 != (char *)0x0) {
        pcVar12 = pcVar7 + 1;
        *pcVar7 = '\0';
      }
      paramid = strtol(param,(char **)0x0,10);
      pppVar4 = pools;
      iVar3 = total_pools;
      if ((paramid < 0) || (total_pools <= paramid)) {
        *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
        message(local_30,0x1a,paramid,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
        return;
      }
      if (pcVar13[paramid] != '\0') {
        *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
        message(local_30,0x4a,paramid,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
        return;
      }
      *(int *)((int)&local_30 + paramid * 4 + iVar11 + 0x30) = iVar9;
      pcVar13[paramid] = '\x01';
      iVar9 = iVar9 + 1;
      if (pcVar12 == (char *)0x0) goto LAB_0001ab44;
      param = pcVar12;
    } while (*pcVar12 != '\0');
    if (0 < total_pools) {
LAB_0001ab44:
      pcVar7 = pcVar13 + total_pools;
      iVar8 = 0;
      pcVar12 = pcVar13;
      do {
        pcVar10 = pcVar12 + 1;
        if (*pcVar12 != '\0') {
          *(undefined4 *)(*(int *)((int)pppVar4 + iVar8) + 4) =
               *(undefined4 *)((int)&local_30 + iVar8 + iVar11 + 0x30);
        }
        pppVar5 = pools;
        iVar8 = iVar8 + 4;
        pcVar12 = pcVar10;
      } while (pcVar10 != pcVar7);
      iVar11 = 0;
      do {
        iVar8 = 0;
        do {
          if ((pcVar13[iVar8] == '\0') && (pppVar5[iVar8]->prio == iVar11)) {
            pppVar5[iVar8]->prio = iVar9;
            iVar9 = iVar9 + 1;
            pcVar13[iVar8] = '\x01';
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 != iVar3);
        iVar11 = iVar11 + 1;
      } while (iVar11 != iVar3);
    }
    ppVar6 = current_pool();
    if (ppVar6->prio != 0) {
      switch_pools((pool *)0x0);
    }
    *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
    message(local_30,0x49,0,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
  }
  return;
}

