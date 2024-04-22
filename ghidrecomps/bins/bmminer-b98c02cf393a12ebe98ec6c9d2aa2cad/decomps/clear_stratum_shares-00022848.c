
void clear_stratum_shares(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int **ppiVar4;
  uint uVar5;
  char *__format;
  int *piVar6;
  int **__ptr;
  int **ppiVar7;
  uint uVar8;
  int **ppiVar9;
  int *piVar10;
  int iVar11;
  bool bVar12;
  double dVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  char acStack_830 [2052];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
  uVar14 = DAT_00022adc;
  if (iVar1 == 0) {
    if (stratum_shares == (int **)0x0) {
      iVar1 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
      if (iVar1 == 0) {
        (*selective_yield)();
        return;
      }
    }
    else {
      piVar6 = stratum_shares[9];
      ppiVar7 = (int **)stratum_shares[2];
      uVar8 = 0;
      __ptr = stratum_shares;
      dVar13 = DAT_00022ad0;
      if ((undefined4 *)piVar6[0x41] == param_1) goto LAB_000228a6;
      while (__ptr = ppiVar7, ppiVar7 != (int **)0x0) {
        while( true ) {
          ppiVar7 = (int **)__ptr[2];
          piVar6 = __ptr[9];
          if ((undefined4 *)piVar6[0x41] != param_1) break;
LAB_000228a6:
          ppiVar9 = stratum_shares;
          piVar3 = __ptr[1];
          if (piVar3 == (int *)0x0) {
            ppiVar4 = (int **)__ptr[2];
            if (ppiVar4 != (int **)0x0) {
              piVar2 = *stratum_shares;
              ppiVar9 = ppiVar4;
              stratum_shares = ppiVar4;
              if (__ptr == (int **)(piVar2[4] - piVar2[5])) {
                piVar2[4] = piVar2[5];
              }
              goto LAB_000228d2;
            }
            free((void *)**stratum_shares);
            free(*ppiVar9);
            piVar6 = __ptr[9];
            stratum_shares = ppiVar4;
          }
          else {
            piVar10 = *stratum_shares;
            iVar1 = piVar10[5] + (int)piVar3;
            piVar2 = __ptr[2];
            if (__ptr == (int **)(piVar10[4] - piVar10[5])) {
              piVar10[4] = iVar1;
            }
            *(int **)(iVar1 + 8) = piVar2;
            ppiVar4 = (int **)__ptr[2];
            if (ppiVar4 != (int **)0x0) {
LAB_000228d2:
              *(int **)((int)ppiVar4 + (*ppiVar9)[5] + 4) = piVar3;
            }
            piVar2 = *ppiVar9;
            iVar11 = *piVar2;
            uVar5 = (uint)__ptr[7] & piVar2[1] - 1U;
            iVar1 = iVar11 + uVar5 * 0xc;
            ppiVar9 = *(int ***)(iVar11 + uVar5 * 0xc);
            *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + -1;
            piVar3 = __ptr[4];
            if (ppiVar9 == __ptr) {
              *(int **)(iVar11 + uVar5 * 0xc) = piVar3;
            }
            piVar10 = __ptr[3];
            if (piVar10 != (int *)0x0) {
              piVar10[4] = (int)piVar3;
              piVar3 = __ptr[4];
            }
            if (piVar3 != (int *)0x0) {
              piVar3[3] = (int)piVar10;
            }
            piVar2[3] = piVar2[3] + -1;
          }
          uVar8 = uVar8 + 1;
          dVar13 = dVar13 + *(double *)(piVar6 + 0x5e);
          _free_work(__ptr + 9,"cgminer.c",uVar14,0x1c78);
          param_1[0xb7] = param_1[0xb7] + -1;
          free(__ptr);
          __ptr = ppiVar7;
          if (ppiVar7 == (int **)0x0) goto LAB_0002294e;
        }
      }
LAB_0002294e:
      iVar1 = pthread_mutex_unlock(DAT_00022ad8);
      if (iVar1 == 0) {
        (*selective_yield)();
        if (uVar8 != 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
            snprintf(acStack_830,0x800,"Lost %d shares due to stratum disconnect on pool %d",uVar8,
                     *param_1);
            _applog(4,acStack_830,0);
          }
          total_diff_stale = total_diff_stale + dVar13;
          bVar12 = CARRY4((uint)total_stale,uVar8);
          total_stale._0_4_ = (uint)total_stale + uVar8;
          total_stale._4_4_ = total_stale._4_4_ + ((int)uVar8 >> 0x1f) + (uint)bVar12;
          *(double *)(param_1 + 0x16) = *(double *)(param_1 + 0x16) + dVar13;
          param_1[0x1e] = uVar8 + param_1[0x1e];
        }
        return;
      }
    }
    uVar14 = DAT_00022adc;
    piVar6 = __errno_location();
    iVar1 = *piVar6;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar15 = 0x1c7e;
  }
  else {
    piVar6 = __errno_location();
    iVar1 = *piVar6;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar15 = 0x1c70;
    uVar14 = DAT_00022adc;
  }
  snprintf(acStack_830,0x800,__format,iVar1,"cgminer.c",uVar14,uVar15);
  _applog(3,acStack_830,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

