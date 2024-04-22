
void clear_pool_work(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *__format;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_838;
  int local_82c;
  char acStack_828 [2052];
  
  iVar1 = pthread_mutex_lock(stgd_lock);
  uVar8 = DAT_00021e90;
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar9 = 0x1c8f;
    uVar8 = DAT_00021e90;
    goto LAB_00021e22;
  }
  local_82c = staged_work;
  if (staged_work != 0) {
    local_838 = 0;
    iVar1 = *(int *)(staged_work + 0x160);
    do {
      iVar4 = staged_work;
      if (*(undefined4 **)(local_82c + 0x104) == param_1) {
        iVar5 = *(int *)(local_82c + 0x15c);
        if (iVar5 == 0) {
          iVar4 = *(int *)(local_82c + 0x160);
          if (iVar4 != 0) {
            iVar7 = *(int *)(staged_work + 0x158);
            iVar3 = iVar4;
            staged_work = iVar4;
            if (local_82c == *(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 0x14)) {
              *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x14);
            }
            goto LAB_00021cd2;
          }
          free(**(void ***)(staged_work + 0x158));
          free(*(void **)(staged_work + 0x158));
          staged_work = iVar4;
        }
        else {
          iVar7 = *(int *)(staged_work + 0x158);
          iVar3 = iVar5 + *(int *)(iVar7 + 0x14);
          if (local_82c == *(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 0x14)) {
            *(int *)(iVar7 + 0x10) = iVar3;
          }
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(local_82c + 0x160);
          iVar3 = *(int *)(local_82c + 0x160);
LAB_00021cd2:
          piVar2 = *(int **)(iVar4 + 0x158);
          if (iVar3 != 0) {
            *(int *)(piVar2[5] + iVar3 + 4) = iVar5;
          }
          iVar3 = *piVar2;
          uVar6 = *(uint *)(local_82c + 0x174) & piVar2[1] - 1U;
          iVar4 = iVar3 + uVar6 * 0xc;
          iVar5 = *(int *)(iVar3 + uVar6 * 0xc);
          *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
          iVar4 = *(int *)(local_82c + 0x168);
          if (iVar5 == local_82c + 0x158) {
            *(int *)(iVar3 + uVar6 * 0xc) = iVar4;
          }
          iVar5 = *(int *)(local_82c + 0x164);
          if (iVar5 != 0) {
            *(int *)(iVar5 + 0x10) = iVar4;
            iVar4 = *(int *)(local_82c + 0x168);
          }
          if (iVar4 != 0) {
            *(int *)(iVar4 + 0xc) = iVar5;
          }
          piVar2[3] = piVar2[3] + -1;
        }
        local_838 = local_838 + 1;
        _free_work(&local_82c,"cgminer.c",uVar8,0x1c95);
      }
      local_82c = iVar1;
      if (iVar1 == 0) goto LAB_00021d3e;
      iVar1 = *(int *)(iVar1 + 0x160);
    } while( true );
  }
  iVar1 = pthread_mutex_unlock(stgd_lock);
  if (iVar1 == 0) {
    (*selective_yield)();
    return;
  }
  goto LAB_00021e3c;
LAB_00021d3e:
  iVar1 = pthread_mutex_unlock(stgd_lock);
  if (iVar1 == 0) {
    (*selective_yield)();
    if ((local_838 != 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
      snprintf(acStack_828,0x800,"Cleared %d work items due to stratum disconnect on pool %d",
               local_838,*param_1);
      _applog(6,acStack_828,0);
    }
    return;
  }
LAB_00021e3c:
  uVar8 = DAT_00021e90;
  piVar2 = __errno_location();
  iVar1 = *piVar2;
  __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  uVar9 = 0x1c99;
LAB_00021e22:
  snprintf(acStack_828,0x800,__format,iVar1,"cgminer.c",uVar8,uVar9);
  _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

