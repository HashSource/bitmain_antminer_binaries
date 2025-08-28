
void watchpool_thread(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  time_t tVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  pthread_mutex_t *__mutex;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  double dVar19;
  undefined1 auStack_850 [8];
  int local_848 [2];
  int local_840 [2];
  char acStack_838 [2052];
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchpool");
  set_lowprio();
  cgtimer_time(auStack_850);
  iVar17 = 0;
  while( true ) {
    iVar17 = iVar17 + 1;
    if (0x78 < iVar17) {
      iVar17 = 0;
    }
    cgtime(local_848);
    if (0 < total_pools) break;
LAB_0002242c:
    iVar14 = current_pool();
    if (*(char *)(iVar14 + 0x61) != '\0') {
      switch_pools(0);
    }
    if ((pool_strategy == 2) &&
       (iVar14 = local_848[0] - (int)rotate_tv,
       iVar14 != opt_rotate_period * 0x3c &&
       iVar14 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar14,opt_rotate_period * 0x3c))) {
      cgtime(&rotate_tv);
      switch_pools(0);
    }
    cgsleep_ms_r(auStack_850,5000);
    cgtimer_time(auStack_850);
  }
  iVar14 = 0;
LAB_0002233c:
  puVar12 = *(undefined4 **)(pools + iVar14 * 4);
  if ((opt_benchmark == '\0') && (opt_benchfile == 0)) {
    __mutex = (pthread_mutex_t *)(puVar12 + 0x2f);
    cgtime(local_840);
    iVar3 = pthread_mutex_lock(__mutex);
    if (iVar3 != 0) {
      piVar9 = __errno_location();
      uVar5 = 0x273e;
      pcVar13 = "reap_curl";
      pcVar8 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      goto LAB_00022766;
    }
    piVar9 = (int *)puVar12[0x56];
    if (puVar12 + 0x56 != piVar9) {
      iVar3 = puVar12[0x48];
      if (1 < iVar3) {
        iVar16 = 0;
        piVar10 = (int *)*piVar9;
        do {
          piVar7 = piVar10;
          if (local_840[0] - piVar9[2] < 0x12d) {
            piVar10 = (int *)*piVar7;
          }
          else {
            piVar10 = (int *)piVar9[1];
            iVar6 = *piVar9;
            iVar16 = iVar16 + 1;
            puVar12[0x48] = iVar3 + -1;
            *(int **)(iVar6 + 4) = piVar10;
            *piVar10 = iVar6;
            free(piVar9 + -1);
            piVar10 = (int *)*piVar7;
          }
          if (puVar12 + 0x56 == piVar7) {
            iVar3 = pthread_mutex_unlock(__mutex);
            if (iVar3 != 0) goto LAB_000227ec;
            (*selective_yield)();
            if (((iVar16 != 0) && (opt_debug != '\0')) &&
               ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
              pcVar8 = "s";
              if (iVar16 == 1) {
                pcVar8 = "";
              }
              snprintf(acStack_838,0x800,"Reaped %d curl%s from pool %d",iVar16,pcVar8,*puVar12);
              _applog(7,acStack_838,0);
            }
            break;
          }
          iVar3 = puVar12[0x48];
          piVar9 = piVar7;
        } while (1 < iVar3);
      }
LAB_00022570:
      tVar4 = time((time_t *)0x0);
      iVar3 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
      if (iVar3 != 0) {
        piVar9 = __errno_location();
        uVar5 = 0x2762;
        pcVar13 = "prune_stratum_shares";
        pcVar8 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
        goto LAB_00022766;
      }
      if (stratum_shares != (int *)0x0) {
        puVar11 = *(undefined4 **)(stratum_shares[9] + 0x104);
        uVar2 = 0;
        piVar7 = (int *)stratum_shares[2];
        piVar9 = stratum_shares;
        piVar10 = stratum_shares;
        do {
          piVar1 = piVar7;
          stratum_shares = piVar10;
          if ((puVar12 == puVar11) && (piVar9[0xb] + 0x78 < tVar4)) {
            iVar3 = piVar9[1];
            if (iVar3 == 0) {
              piVar7 = (int *)piVar9[2];
              stratum_shares = piVar7;
              if (piVar7 != (int *)0x0) {
                iVar16 = *piVar10;
                if (piVar9 == (int *)(*(int *)(iVar16 + 0x10) - *(int *)(iVar16 + 0x14))) {
                  *(int *)(iVar16 + 0x10) = *(int *)(iVar16 + 0x14);
                }
                goto LAB_000225e8;
              }
              stratum_shares = piVar10;
              free(*(void **)*piVar10);
              free((void *)*piVar10);
              stratum_shares = piVar7;
            }
            else {
              iVar6 = *piVar10;
              iVar16 = *(int *)(iVar6 + 0x14) + iVar3;
              if (piVar9 == (int *)(*(int *)(iVar6 + 0x10) - *(int *)(iVar6 + 0x14))) {
                *(int *)(iVar6 + 0x10) = iVar16;
              }
              *(int *)(iVar16 + 8) = piVar9[2];
              piVar7 = piVar10;
LAB_000225e8:
              piVar7 = (int *)*piVar7;
              if (piVar9[2] != 0) {
                *(int *)(piVar9[2] + piVar7[5] + 4) = iVar3;
              }
              iVar3 = *piVar7;
              uVar15 = piVar9[7] & piVar7[1] - 1U;
              iVar16 = iVar3 + uVar15 * 0xc;
              piVar10 = *(int **)(iVar3 + uVar15 * 0xc);
              *(int *)(iVar16 + 4) = *(int *)(iVar16 + 4) + -1;
              iVar16 = piVar9[4];
              if (piVar10 == piVar9) {
                *(int *)(iVar3 + uVar15 * 0xc) = iVar16;
              }
              iVar3 = piVar9[3];
              if (iVar3 != 0) {
                *(int *)(iVar3 + 0x10) = iVar16;
                iVar16 = piVar9[4];
              }
              if (iVar16 != 0) {
                *(int *)(iVar16 + 0xc) = iVar3;
              }
              piVar7[3] = piVar7[3] + -1;
            }
            uVar2 = uVar2 + 1;
            _free_work(piVar9 + 9,"cgminer.c","prune_stratum_shares",0x2769);
            free(piVar9);
          }
          if (piVar1 == (int *)0x0) goto LAB_00022652;
          puVar11 = *(undefined4 **)(piVar1[9] + 0x104);
          piVar7 = (int *)piVar1[2];
          piVar9 = piVar1;
          piVar10 = stratum_shares;
        } while( true );
      }
      iVar3 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
      if (iVar3 == 0) {
        (*selective_yield)();
        goto LAB_00022354;
      }
      goto LAB_00022748;
    }
    iVar3 = pthread_mutex_unlock(__mutex);
    if (iVar3 == 0) {
      (*selective_yield)();
      goto LAB_00022570;
    }
LAB_000227ec:
    piVar9 = __errno_location();
    pcVar13 = "reap_curl";
    uVar5 = 0x2750;
    goto LAB_0002275a;
  }
  goto LAB_00022354;
LAB_00022652:
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
  if (iVar3 != 0) {
LAB_00022748:
    pcVar13 = "prune_stratum_shares";
    piVar9 = __errno_location();
    uVar5 = 0x276f;
LAB_0002275a:
    pcVar8 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
LAB_00022766:
    snprintf(acStack_838,0x800,pcVar8,*piVar9,"cgminer.c",pcVar13,uVar5);
    _applog(3,acStack_838,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  (*selective_yield)();
  if (uVar2 != 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_838,0x800,"Lost %d shares due to no stratum share response from pool %d",
               uVar2,*puVar12);
      _applog(4,acStack_838,0);
    }
    bVar18 = CARRY4((uint)total_stale,uVar2);
    total_stale._0_4_ = (uint)total_stale + uVar2;
    puVar12[0x1e] = puVar12[0x1e] + uVar2;
    total_stale._4_4_ = total_stale._4_4_ + ((int)uVar2 >> 0x1f) + (uint)bVar18;
  }
LAB_00022354:
  if (iVar17 == 0x78) {
    uVar2 = puVar12[0x26];
    uVar15 = puVar12[10];
    dVar19 = (double)__aeabi_l2d(uVar15 - uVar2,
                                 (puVar12[0xb] - ((int)uVar2 >> 0x1f)) - (uint)(uVar15 < uVar2));
    puVar12[0x26] = uVar15;
    dVar19 = (*(double *)(puVar12 + 0x24) + dVar19 * 0.63) / 1.63;
    *(double *)(puVar12 + 0x24) = dVar19;
    puVar12[0x27] = (int)(longlong)dVar19;
  }
  if ((puVar12[0x19] != 0) && (*(char *)(puVar12 + 0x47) == '\0')) {
    iVar3 = pool_active(puVar12,1);
    if (iVar3 == 0) {
      cgtime(puVar12 + 0x22);
    }
    else {
      iVar3 = pool_tclear(puVar12,(int)puVar12 + 0x61);
      if (iVar3 != 0) {
        pool_resus(puVar12);
      }
    }
    if (((*(char *)((int)puVar12 + 0x61) == '\0') && (pool_strategy == 0)) &&
       ((iVar16 = puVar12[1], iVar3 = cp_prio(), iVar16 < iVar3 &&
        (opt_pool_fallback < local_848[0] - puVar12[0x22])))) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_838,0x800,"Pool %d %s stable for >%d seconds",*puVar12,puVar12[0x29],
                 opt_pool_fallback);
        _applog(4,acStack_838,0);
      }
      iVar14 = iVar14 + 1;
      switch_pools(0);
      if (total_pools <= iVar14) goto LAB_0002242c;
      goto LAB_0002233c;
    }
  }
  iVar14 = iVar14 + 1;
  if (total_pools <= iVar14) goto LAB_0002242c;
  goto LAB_0002233c;
}

