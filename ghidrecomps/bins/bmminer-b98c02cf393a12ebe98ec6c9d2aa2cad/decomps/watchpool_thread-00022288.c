
void watchpool_thread(void)

{
  int **ppiVar1;
  double dVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  time_t tVar6;
  undefined4 uVar7;
  int iVar8;
  int **ppiVar9;
  char *pcVar10;
  pthread_mutex_t *__mutex;
  int **ppiVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int **ppiVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  bool bVar23;
  double dVar24;
  undefined auStack_850 [8];
  int local_848 [2];
  int local_840 [2];
  char acStack_838 [2052];
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchpool");
  dVar2 = DAT_000224a8;
  set_lowprio();
  dVar3 = DAT_000224b0;
  cgtimer_time(auStack_850);
  iVar21 = 0;
  while( true ) {
    iVar21 = iVar21 + 1;
    if (0x78 < iVar21) {
      iVar21 = 0;
    }
    cgtime(local_848);
    if (0 < total_pools) break;
LAB_0002242c:
    iVar18 = current_pool();
    if (*(char *)(iVar18 + 0x61) != '\0') {
      switch_pools(0);
    }
    if ((pool_strategy == 2) &&
       (iVar18 = local_848[0] - (int)rotate_tv,
       iVar18 != opt_rotate_period * 0x3c &&
       iVar18 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar18,opt_rotate_period * 0x3c))) {
      cgtime(DAT_00022840);
      switch_pools(0);
    }
    cgsleep_ms_r(auStack_850,5000);
    cgtimer_time(auStack_850);
  }
  iVar18 = 0;
LAB_0002233c:
  puVar16 = *(undefined4 **)(pools + iVar18 * 4);
  if ((opt_benchmark == '\0') && (opt_benchfile == 0)) {
    __mutex = (pthread_mutex_t *)(puVar16 + 0x2f);
    cgtime(local_840);
    iVar5 = pthread_mutex_lock(__mutex);
    uVar17 = DAT_00022844;
    if (iVar5 != 0) {
      piVar12 = __errno_location();
      uVar7 = 0x273e;
      pcVar10 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      goto LAB_00022766;
    }
    ppiVar11 = (int **)puVar16[0x56];
    if ((int **)(puVar16 + 0x56) != ppiVar11) {
      iVar5 = puVar16[0x48];
      if (1 < iVar5) {
        iVar20 = 0;
        ppiVar9 = (int **)*ppiVar11;
        do {
          ppiVar15 = ppiVar9;
          if (local_840[0] - ((int *)ppiVar11)[2] < 0x12d) {
            ppiVar9 = (int **)*ppiVar15;
          }
          else {
            piVar12 = (int *)((int *)ppiVar11)[1];
            iVar8 = (int)*ppiVar11;
            iVar20 = iVar20 + 1;
            puVar16[0x48] = iVar5 + -1;
            *(int **)(iVar8 + 4) = piVar12;
            *piVar12 = iVar8;
            free((int *)ppiVar11 + -1);
            ppiVar9 = (int **)*ppiVar15;
          }
          if ((int **)(puVar16 + 0x56) == ppiVar15) {
            iVar5 = pthread_mutex_unlock(__mutex);
            if (iVar5 != 0) goto LAB_000227ec;
            (*selective_yield)();
            if (((iVar20 != 0) && (opt_debug != '\0')) &&
               ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
              pcVar10 = "s";
              if (iVar20 == 1) {
                pcVar10 = "";
              }
              snprintf(acStack_838,0x800,"Reaped %d curl%s from pool %d",iVar20,pcVar10,*puVar16);
              _applog(7,acStack_838,0);
            }
            break;
          }
          iVar5 = puVar16[0x48];
          ppiVar11 = ppiVar15;
        } while (1 < iVar5);
      }
LAB_00022570:
      tVar6 = time((time_t *)0x0);
      iVar5 = pthread_mutex_lock(DAT_00022838);
      uVar17 = DAT_0002283c;
      if (iVar5 != 0) {
        piVar12 = __errno_location();
        uVar7 = 0x2762;
        pcVar10 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
        goto LAB_00022766;
      }
      if (stratum_shares != (int **)0x0) {
        puVar13 = (undefined4 *)stratum_shares[9][0x41];
        uVar4 = 0;
        ppiVar15 = (int **)stratum_shares[2];
        ppiVar11 = stratum_shares;
        ppiVar9 = stratum_shares;
        do {
          ppiVar1 = ppiVar15;
          stratum_shares = ppiVar9;
          if ((puVar16 == puVar13) && ((int)(ppiVar11[0xb] + 0x1e) < tVar6)) {
            piVar12 = ppiVar11[1];
            if (piVar12 == (int *)0x0) {
              ppiVar15 = (int **)ppiVar11[2];
              stratum_shares = ppiVar15;
              if (ppiVar15 != (int **)0x0) {
                piVar22 = *ppiVar9;
                if (ppiVar11 == (int **)(piVar22[4] - piVar22[5])) {
                  piVar22[4] = piVar22[5];
                }
                goto LAB_000225e8;
              }
              stratum_shares = ppiVar9;
              free((void *)**ppiVar9);
              free(*ppiVar9);
              stratum_shares = ppiVar15;
            }
            else {
              piVar22 = *ppiVar9;
              iVar5 = piVar22[5] + (int)piVar12;
              if (ppiVar11 == (int **)(piVar22[4] - piVar22[5])) {
                piVar22[4] = iVar5;
              }
              *(int **)(iVar5 + 8) = ppiVar11[2];
              ppiVar15 = ppiVar9;
LAB_000225e8:
              piVar22 = *ppiVar15;
              if (ppiVar11[2] != (int *)0x0) {
                *(int **)((int)ppiVar11[2] + piVar22[5] + 4) = piVar12;
              }
              iVar5 = *piVar22;
              uVar19 = (uint)ppiVar11[7] & piVar22[1] - 1U;
              iVar20 = iVar5 + uVar19 * 0xc;
              ppiVar9 = *(int ***)(iVar5 + uVar19 * 0xc);
              *(int *)(iVar20 + 4) = *(int *)(iVar20 + 4) + -1;
              piVar12 = ppiVar11[4];
              if (ppiVar9 == ppiVar11) {
                *(int **)(iVar5 + uVar19 * 0xc) = piVar12;
              }
              piVar14 = ppiVar11[3];
              if (piVar14 != (int *)0x0) {
                piVar14[4] = (int)piVar12;
                piVar12 = ppiVar11[4];
              }
              if (piVar12 != (int *)0x0) {
                piVar12[3] = (int)piVar14;
              }
              piVar22[3] = piVar22[3] + -1;
            }
            uVar4 = uVar4 + 1;
            _free_work(ppiVar11 + 9,"cgminer.c",DAT_0002283c,0x2769);
            free(ppiVar11);
          }
          if (ppiVar1 == (int **)0x0) goto LAB_00022652;
          puVar13 = (undefined4 *)ppiVar1[9][0x41];
          ppiVar15 = (int **)ppiVar1[2];
          ppiVar11 = ppiVar1;
          ppiVar9 = stratum_shares;
        } while( true );
      }
      iVar5 = pthread_mutex_unlock(DAT_00022838);
      if (iVar5 == 0) {
        (*selective_yield)();
        goto LAB_00022354;
      }
      goto LAB_00022748;
    }
    iVar5 = pthread_mutex_unlock(__mutex);
    if (iVar5 == 0) {
      (*selective_yield)();
      goto LAB_00022570;
    }
LAB_000227ec:
    piVar12 = __errno_location();
    uVar7 = 0x2750;
    uVar17 = DAT_00022844;
    goto LAB_0002275a;
  }
  goto LAB_00022354;
LAB_00022652:
  iVar5 = pthread_mutex_unlock(DAT_00022838);
  if (iVar5 != 0) {
LAB_00022748:
    uVar17 = DAT_0002283c;
    piVar12 = __errno_location();
    uVar7 = 0x276f;
LAB_0002275a:
    pcVar10 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
LAB_00022766:
    snprintf(acStack_838,0x800,pcVar10,*piVar12,"cgminer.c",uVar17,uVar7);
    _applog(3,acStack_838,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  (*selective_yield)();
  if (uVar4 != 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_838,0x800,"Lost %d shares due to no stratum share response from pool %d",
               uVar4,*puVar16);
      _applog(4,acStack_838,0);
    }
    bVar23 = CARRY4((uint)total_stale,uVar4);
    total_stale._0_4_ = (uint)total_stale + uVar4;
    puVar16[0x1e] = puVar16[0x1e] + uVar4;
    total_stale._4_4_ = total_stale._4_4_ + ((int)uVar4 >> 0x1f) + (uint)bVar23;
  }
LAB_00022354:
  if (iVar21 == 0x78) {
    uVar4 = puVar16[0x26];
    uVar19 = puVar16[10];
    dVar24 = (double)__aeabi_l2d(uVar19 - uVar4,
                                 (puVar16[0xb] - ((int)uVar4 >> 0x1f)) - (uint)(uVar19 < uVar4));
    puVar16[0x26] = uVar19;
    dVar24 = (*(double *)(puVar16 + 0x24) + dVar24 * dVar2) / dVar3;
    *(double *)(puVar16 + 0x24) = dVar24;
    puVar16[0x27] = (int)(longlong)dVar24;
  }
  if ((puVar16[0x19] != 0) && (*(char *)(puVar16 + 0x47) == '\0')) {
    iVar5 = pool_active(puVar16,1);
    if (iVar5 == 0) {
      cgtime(puVar16 + 0x22);
    }
    else {
      iVar5 = pool_tclear(puVar16,(int)puVar16 + 0x61);
      if (iVar5 != 0) {
        pool_resus(puVar16);
      }
    }
    if (((*(char *)((int)puVar16 + 0x61) == '\0') && (pool_strategy == 0)) &&
       ((iVar20 = puVar16[1], iVar5 = cp_prio(), iVar20 < iVar5 &&
        (opt_pool_fallback < local_848[0] - puVar16[0x22])))) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_838,0x800,"Pool %d %s stable for >%d seconds",*puVar16,puVar16[0x29],
                 opt_pool_fallback);
        _applog(4,acStack_838,0);
      }
      iVar18 = iVar18 + 1;
      switch_pools(0);
      if (total_pools <= iVar18) goto LAB_0002242c;
      goto LAB_0002233c;
    }
  }
  iVar18 = iVar18 + 1;
  if (total_pools <= iVar18) goto LAB_0002242c;
  goto LAB_0002233c;
}

