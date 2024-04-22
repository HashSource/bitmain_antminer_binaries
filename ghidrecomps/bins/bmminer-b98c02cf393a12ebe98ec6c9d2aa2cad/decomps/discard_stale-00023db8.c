
void discard_stale(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  char *__format;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_824;
  char acStack_820 [2048];
  
  iVar1 = pthread_mutex_lock(stgd_lock);
  uVar9 = DAT_0002401c;
  if (iVar1 != 0) {
    piVar4 = __errno_location();
    iVar1 = *piVar4;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar10 = 0x14b5;
    uVar9 = DAT_0002401c;
    goto LAB_00023fb0;
  }
  local_824 = staged_work;
  if (staged_work != 0) {
    iVar1 = 0;
    iVar3 = *(int *)(staged_work + 0x160);
    do {
      iVar2 = stale_work(local_824,0);
      iVar7 = staged_work;
      if (iVar2 != 0) {
        iVar2 = *(int *)(local_824 + 0x15c);
        if (iVar2 == 0) {
          iVar7 = *(int *)(local_824 + 0x160);
          if (iVar7 != 0) {
            iVar8 = *(int *)(staged_work + 0x158);
            iVar5 = iVar7;
            staged_work = iVar7;
            if (local_824 == *(int *)(iVar8 + 0x10) - *(int *)(iVar8 + 0x14)) {
              *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x14);
            }
            goto LAB_00023e32;
          }
          free(**(void ***)(staged_work + 0x158));
          free(*(void **)(staged_work + 0x158));
          staged_work = iVar7;
        }
        else {
          iVar8 = *(int *)(staged_work + 0x158);
          iVar5 = *(int *)(iVar8 + 0x14) + iVar2;
          if (local_824 == *(int *)(iVar8 + 0x10) - *(int *)(iVar8 + 0x14)) {
            *(int *)(iVar8 + 0x10) = iVar5;
          }
          *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(local_824 + 0x160);
          iVar5 = *(int *)(local_824 + 0x160);
LAB_00023e32:
          piVar4 = *(int **)(iVar7 + 0x158);
          if (iVar5 != 0) {
            *(int *)(piVar4[5] + iVar5 + 4) = iVar2;
          }
          iVar5 = *piVar4;
          uVar6 = *(uint *)(local_824 + 0x174) & piVar4[1] - 1U;
          iVar7 = iVar5 + uVar6 * 0xc;
          iVar2 = *(int *)(iVar5 + uVar6 * 0xc);
          *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + -1;
          iVar7 = *(int *)(local_824 + 0x168);
          if (iVar2 == local_824 + 0x158) {
            *(int *)(iVar5 + uVar6 * 0xc) = iVar7;
          }
          iVar2 = *(int *)(local_824 + 0x164);
          if (iVar2 != 0) {
            *(int *)(iVar2 + 0x10) = iVar7;
            iVar7 = *(int *)(local_824 + 0x168);
          }
          if (iVar7 != 0) {
            *(int *)(iVar7 + 0xc) = iVar2;
          }
          piVar4[3] = piVar4[3] + -1;
        }
        iVar1 = iVar1 + 1;
        _discard_work(&local_824,"cgminer.c",uVar9,0x14bc);
      }
      local_824 = iVar3;
      if (iVar3 == 0) goto LAB_00023eac;
      iVar3 = *(int *)(iVar3 + 0x160);
    } while( true );
  }
  pthread_cond_signal((pthread_cond_t *)gws_cond);
  iVar1 = pthread_mutex_unlock(stgd_lock);
  if (iVar1 == 0) {
    (*selective_yield)();
    return;
  }
  goto LAB_00023fca;
LAB_00023eac:
  pthread_cond_signal((pthread_cond_t *)gws_cond);
  iVar3 = pthread_mutex_unlock(stgd_lock);
  if (iVar3 == 0) {
    (*selective_yield)();
    if (((iVar1 != 0) && (opt_debug != '\0')) &&
       ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
      snprintf(acStack_820,0x800,"Discarded %d stales that didn\'t match current hash",iVar1);
      _applog(7,acStack_820,0);
    }
    return;
  }
LAB_00023fca:
  uVar9 = DAT_0002401c;
  piVar4 = __errno_location();
  iVar1 = *piVar4;
  __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  uVar10 = 0x14c2;
LAB_00023fb0:
  snprintf(acStack_820,0x800,__format,iVar1,"cgminer.c",uVar9,uVar10);
  _applog(3,acStack_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

