
void clear_stratum_shares(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  char *__format;
  int *piVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  double dVar13;
  undefined4 uVar14;
  char acStack_830 [2052];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
  if (iVar1 == 0) {
    if (stratum_shares == (int *)0x0) {
      iVar1 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
      if (iVar1 == 0) {
        (*selective_yield)();
        return;
      }
    }
    else {
      iVar1 = stratum_shares[9];
      piVar9 = (int *)stratum_shares[2];
      dVar13 = 0.0;
      uVar10 = 0;
      piVar3 = stratum_shares;
      if (*(undefined4 **)(iVar1 + 0x104) == param_1) goto LAB_000228a6;
      while (piVar3 = piVar9, piVar9 != (int *)0x0) {
        while( true ) {
          piVar9 = (int *)piVar3[2];
          iVar1 = piVar3[9];
          if (*(undefined4 **)(iVar1 + 0x104) != param_1) break;
LAB_000228a6:
          piVar5 = stratum_shares;
          iVar4 = piVar3[1];
          if (iVar4 == 0) {
            piVar7 = (int *)piVar3[2];
            if (piVar7 != (int *)0x0) {
              iVar2 = *stratum_shares;
              piVar5 = piVar7;
              stratum_shares = piVar7;
              if (piVar3 == (int *)(*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 0x14))) {
                *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x14);
              }
              goto LAB_000228d2;
            }
            free(*(void **)*stratum_shares);
            free((void *)*piVar5);
            iVar1 = piVar3[9];
            stratum_shares = piVar7;
          }
          else {
            iVar11 = *stratum_shares;
            iVar6 = *(int *)(iVar11 + 0x14) + iVar4;
            iVar2 = piVar3[2];
            if (piVar3 == (int *)(*(int *)(iVar11 + 0x10) - *(int *)(iVar11 + 0x14))) {
              *(int *)(iVar11 + 0x10) = iVar6;
            }
            *(int *)(iVar6 + 8) = iVar2;
            piVar7 = (int *)piVar3[2];
            if (piVar7 != (int *)0x0) {
LAB_000228d2:
              *(int *)((int)piVar7 + *(int *)(*piVar5 + 0x14) + 4) = iVar4;
            }
            piVar5 = (int *)*piVar5;
            iVar2 = *piVar5;
            uVar8 = piVar3[7] & piVar5[1] - 1U;
            iVar4 = iVar2 + uVar8 * 0xc;
            piVar7 = *(int **)(iVar2 + uVar8 * 0xc);
            *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
            iVar4 = piVar3[4];
            if (piVar7 == piVar3) {
              *(int *)(iVar2 + uVar8 * 0xc) = iVar4;
            }
            iVar2 = piVar3[3];
            if (iVar2 != 0) {
              *(int *)(iVar2 + 0x10) = iVar4;
              iVar4 = piVar3[4];
            }
            if (iVar4 != 0) {
              *(int *)(iVar4 + 0xc) = iVar2;
            }
            piVar5[3] = piVar5[3] + -1;
          }
          uVar10 = uVar10 + 1;
          dVar13 = dVar13 + *(double *)(iVar1 + 0x178);
          _free_work(piVar3 + 9,"cgminer.c","clear_stratum_shares",0x1c78);
          param_1[0xb7] = param_1[0xb7] + -1;
          free(piVar3);
          piVar3 = piVar9;
          if (piVar9 == (int *)0x0) goto LAB_0002294e;
        }
      }
LAB_0002294e:
      iVar1 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
      if (iVar1 == 0) {
        (*selective_yield)();
        if (uVar10 != 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
            snprintf(acStack_830,0x800,"Lost %d shares due to stratum disconnect on pool %d",uVar10,
                     *param_1);
            _applog(4,acStack_830,0);
          }
          total_diff_stale = total_diff_stale + dVar13;
          bVar12 = CARRY4((uint)total_stale,uVar10);
          total_stale._0_4_ = (uint)total_stale + uVar10;
          total_stale._4_4_ = total_stale._4_4_ + ((int)uVar10 >> 0x1f) + (uint)bVar12;
          *(double *)(param_1 + 0x16) = *(double *)(param_1 + 0x16) + dVar13;
          param_1[0x1e] = uVar10 + param_1[0x1e];
        }
        return;
      }
    }
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar14 = 0x1c7e;
  }
  else {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar14 = 0x1c70;
  }
  snprintf(acStack_830,0x800,__format,iVar1,"cgminer.c","clear_stratum_shares",uVar14);
  _applog(3,acStack_830,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

