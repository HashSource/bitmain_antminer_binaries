
/* WARNING: Unknown calling convention */

void poolpriority(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  long paramid;
  pool *ppVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *next;
  int iVar9;
  int iVar10;
  int (*new_prio) [167096];
  int iVar11;
  char *pcVar12;
  char *ptr;
  _Bool (*pools_changed) [167071];
  char *pcVar13;
  int iVar14;
  io_data *local_30;
  uint local_2c;
  
  piVar3 = DAT_0001abec;
  local_2c = (uint)isjson;
  iVar6 = *DAT_0001abec;
  local_30 = io_data;
  if (iVar6 == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x19,0,(char *)0x0,isjson);
  }
  else {
    iVar1 = -(iVar6 + 7U & 0xfffffff8);
    pcVar13 = (char *)((int)&local_30 + iVar1);
    iVar2 = -(iVar6 * 4 + 10U & 0xfffffff8);
    iVar11 = iVar2 + iVar1 + -0x30;
    if (0 < iVar6) {
      pcVar12 = pcVar13;
      do {
        pcVar7 = pcVar12 + 1;
        *pcVar12 = '\0';
        pcVar12 = pcVar7;
      } while (pcVar7 != pcVar13 + iVar6);
    }
    iVar6 = 0;
    ptr = param;
    do {
      pcVar7 = strchr(ptr,0x2c);
      pcVar12 = pcVar7;
      if (pcVar7 != (char *)0x0) {
        pcVar12 = pcVar7 + 1;
        *pcVar7 = '\0';
      }
      paramid = strtol(ptr,(char **)0x0,10);
      piVar4 = DAT_0001abf0;
      if ((paramid < 0) || (iVar8 = *piVar3, iVar8 <= paramid)) {
        *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
        message(local_30,0x1a,paramid,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
        return;
      }
      if (pcVar13[paramid] != '\0') {
        *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
        message(local_30,0x4a,paramid,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
        return;
      }
      *(int *)((int)&local_30 + paramid * 4 + iVar11 + 0x30) = iVar6;
      pcVar13[paramid] = '\x01';
      iVar6 = iVar6 + 1;
      if (pcVar12 == (char *)0x0) goto LAB_0001ab44;
      ptr = pcVar12;
    } while (*pcVar12 != '\0');
    if (0 < iVar8) {
LAB_0001ab44:
      iVar9 = 0;
      iVar14 = *DAT_0001abf0;
      pcVar12 = pcVar13;
      do {
        pcVar7 = pcVar12 + 1;
        if (*pcVar12 != '\0') {
          *(undefined4 *)(*(int *)(iVar14 + iVar9) + 4) =
               *(undefined4 *)((int)&local_30 + iVar9 + iVar11 + 0x30);
        }
        iVar9 = iVar9 + 4;
        pcVar12 = pcVar7;
      } while (pcVar7 != pcVar13 + iVar8);
      iVar9 = *piVar4;
      iVar11 = 0;
      do {
        iVar14 = 0;
        do {
          if ((pcVar13[iVar14] == '\0') &&
             (iVar10 = *(int *)(iVar9 + iVar14 * 4), *(int *)(iVar10 + 4) == iVar11)) {
            *(int *)(iVar10 + 4) = iVar6;
            iVar6 = iVar6 + 1;
            pcVar13[iVar14] = '\x01';
            break;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 != iVar8);
        iVar11 = iVar11 + 1;
      } while (iVar11 != iVar8);
    }
    ppVar5 = current_pool();
    if (ppVar5->prio != 0) {
      switch_pools((pool *)0x0);
    }
    *(uint *)(&stack0xffffffc8 + iVar2 + iVar1) = local_2c;
    message(local_30,0x49,0,(char *)0x0,(_Bool)(&stack0xffffffc8)[iVar2 + iVar1]);
  }
  return;
}

