
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 stratum_rthread(undefined4 *param_1)

{
  char cVar1;
  double dVar2;
  pthread_mutex_t *__mutex;
  undefined4 uVar3;
  undefined4 uVar4;
  pthread_t __th;
  int iVar5;
  timeval *ptVar6;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  time_t tVar12;
  int iVar13;
  size_t sVar14;
  undefined4 *puVar15;
  uint uVar16;
  void *pvVar17;
  undefined8 *puVar18;
  undefined4 uVar19;
  int **ppiVar20;
  byte bVar21;
  uint uVar22;
  uint uVar23;
  void *pvVar24;
  undefined4 *puVar25;
  int iVar26;
  undefined4 uVar27;
  void **ppvVar28;
  void *__ptr;
  int iVar29;
  int **ppiVar30;
  bool bVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  timeval *in_stack_fffff548;
  undefined4 in_stack_fffff54c;
  int *local_a84;
  char *local_a70;
  uint local_a68;
  timeval local_a64;
  char acStack_a5c [16];
  char local_a4c [20];
  char local_a38;
  undefined local_a37;
  undefined auStack_a36 [30];
  undefined8 local_a18;
  char acStack_9f4 [60];
  undefined4 uStack_9b8;
  fd_set local_9b4;
  undefined4 local_934 [23];
  timeval atStack_8d8 [19];
  char cStack_839;
  undefined4 local_838;
  undefined4 local_834;
  undefined4 local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined4 local_824;
  undefined4 local_820;
  undefined4 local_81c;
  undefined4 local_818;
  undefined local_814;
  
  __th = pthread_self();
  pthread_detach(__th);
  dVar2 = DAT_00027890;
  snprintf(acStack_a5c,0x10,"%d/RStratum",*param_1);
  RenameThread(acStack_a5c);
  do {
    cVar1 = *(char *)((int)param_1 + 0x69);
joined_r0x000275fa:
    if (cVar1 != '\0') {
      suspend_stratum();
      return 0;
    }
    iVar5 = sock_full(param_1);
    if ((iVar5 == 0) && (iVar5 = cnx_needed(param_1), iVar5 == 0)) {
      suspend_stratum(param_1);
      clear_stratum_shares(param_1);
      __mutex = DAT_00027898;
      clear_pool_work(param_1);
      iVar5 = cnx_needed(param_1);
      while ((iVar5 == 0 &&
             ((param_1[0x19] == 0 ||
              ((puVar25 = (undefined4 *)current_pool(), param_1 != puVar25 &&
               (1 < pool_strategy - 3U))))))) {
        iVar5 = pthread_mutex_lock(__mutex);
        if (iVar5 != 0) {
          piVar8 = __errno_location();
          iVar5 = *piVar8;
          uVar27 = 0x2649;
          uVar19 = DAT_00027cb4;
          goto LAB_00027ab6;
        }
        pthread_cond_wait(DAT_0002789c,__mutex);
        iVar5 = pthread_mutex_unlock(__mutex);
        if (iVar5 != 0) {
          piVar8 = __errno_location();
          iVar5 = *piVar8;
          uVar27 = 0x264b;
          uVar19 = DAT_00027cb4;
          goto LAB_00027af4;
        }
        (*selective_yield)();
        iVar5 = cnx_needed(param_1);
      }
      while (iVar5 = restart_stratum(param_1), iVar5 == 0) {
        pool_died(param_1);
        if (*(char *)((int)param_1 + 0x69) != '\0') {
          return 0;
        }
        cgsleep_ms(5000);
      }
    }
    puVar25 = &uStack_9b8;
    do {
      puVar25 = puVar25 + 1;
      *puVar25 = 0;
    } while (local_9b4.fds_bits + 0x1f != puVar25);
    uVar22 = param_1[0x93];
    local_a64.tv_usec = 0;
    local_a64.tv_sec = 0x5a;
    uVar16 = uVar22 + 0x1f & (int)uVar22 >> 0x20;
    if (local_9b4.fds_bits + 0x1f < puVar25) {
      uVar16 = uVar22;
    }
    uVar23 = uVar22 & 0x1f;
    if ((int)uVar22 < 1) {
      uVar23 = -(-uVar22 & 0x1f);
    }
    local_9b4.fds_bits[(int)uVar16 >> 5] =
         local_9b4.fds_bits[(int)uVar16 >> 5] | 1 << (uVar23 & 0xff);
    iVar5 = sock_full(param_1);
    if (iVar5 != 0) {
LAB_0002766c:
      pcVar7 = (char *)recv_line(param_1);
      if (pcVar7 != (char *)0x0) {
        stratum_resumed(param_1);
        iVar5 = parse_method(param_1,pcVar7);
        if (iVar5 == 0) {
          iVar5 = json_loads(pcVar7,0,local_934);
          if (iVar5 != 0) {
            local_a84 = (int *)json_object_get(iVar5,"result");
            piVar8 = (int *)json_object_get(iVar5,"error");
            piVar9 = (int *)json_object_get(iVar5,&DAT_0005e278);
            if ((piVar9 == (int *)0x0) || (*piVar9 == 7)) {
              if (piVar8 == (int *)0x0) {
                puVar25 = (undefined4 *)malloc(0x11);
                uVar4 = ram0x0005e28c;
                uVar3 = s__unknown_reason__0005e27c._12_4_;
                uVar27 = s__unknown_reason__0005e27c._8_4_;
                uVar19 = s__unknown_reason__0005e27c._4_4_;
                if (puVar25 != (undefined4 *)0x0) {
                  *puVar25 = s__unknown_reason__0005e27c._0_4_;
                  puVar25[1] = uVar19;
                  puVar25[2] = uVar27;
                  puVar25[3] = uVar3;
                  *(char *)(puVar25 + 4) = (char)uVar4;
                }
              }
              else {
                puVar25 = (undefined4 *)json_dumps(piVar8,3);
              }
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                snprintf((char *)&local_838,0x800,"JSON-RPC non method decode failed: %s",puVar25);
                _applog(6,&local_838,0);
              }
              free(puVar25);
            }
            else {
              iVar10 = json_object_get(local_a84,"version-rolling.mask");
              if (((iVar10 == 0) &&
                  (pcVar11 = strstr(pcVar7,"mining.configure"), pcVar11 == (char *)0x0)) &&
                 (pcVar11 = strstr(pcVar7,"mining.set_version_mask"), pcVar11 == (char *)0x0)) {
                local_a68 = json_integer_value(piVar9);
                iVar10 = pthread_mutex_lock(DAT_00027cbc);
                ppiVar30 = stratum_shares;
                if (iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
                  _mutex_lock_part_47_constprop_75(DAT_00028818,0x1c25);
                }
                uVar23 = (local_a68 & 0xff) + 0x112410d + (local_a68 & 0xff000000) +
                         (local_a68 >> 0x10 & 0xff) * 0x10000 + (local_a68 >> 8 & 0xff) * 0x100 ^
                         0x7f76d;
                uVar22 = 0x9f49bac6 - uVar23 ^ uVar23 << 8;
                uVar16 = (-0x112410d - uVar23) - uVar22 ^ uVar22 >> 0xd;
                uVar23 = (uVar23 - uVar22) - uVar16 ^ uVar16 >> 0xc;
                uVar22 = (uVar22 - uVar16) - uVar23 ^ uVar23 << 0x10;
                uVar16 = (uVar16 - uVar23) - uVar22 ^ uVar22 >> 5;
                uVar23 = (uVar23 - uVar22) - uVar16 ^ uVar16 >> 3;
                uVar22 = (uVar22 - uVar16) - uVar23 ^ uVar23 << 10;
                uVar16 = (uVar16 - uVar23) - uVar22 ^ uVar22 >> 0xf;
                if (stratum_shares != (int **)0x0) {
                  ppvVar28 = (void **)*stratum_shares;
                  pvVar17 = *ppvVar28;
                  iVar10 = *(int *)((int)pvVar17 + ((int)ppvVar28[1] - 1U & uVar16) * 0xc);
                  if (iVar10 != 0) {
                    pvVar24 = ppvVar28[5];
                    iVar29 = -(int)pvVar24;
                    do {
                      __ptr = (void *)(iVar10 + iVar29);
                      if (__ptr == (void *)0x0) break;
                      if (((uVar16 == *(uint *)((int)__ptr + 0x1c)) &&
                          (*(int *)((int)__ptr + 0x18) == 4)) &&
                         (iVar10 = memcmp(*(void **)((int)__ptr + 0x14),&local_a68,4), iVar10 == 0))
                      {
                        iVar10 = *(int *)((int)__ptr + 4);
                        if (iVar10 == 0) {
                          ppiVar20 = *(int ***)((int)__ptr + 8);
                          if (ppiVar20 != (int **)0x0) {
                            ppiVar30 = ppiVar20;
                            stratum_shares = ppiVar20;
                            if (__ptr == (void *)(iVar29 + (int)ppvVar28[4])) {
                              ppvVar28[4] = pvVar24;
                            }
                            goto LAB_00027ec2;
                          }
                          free(pvVar17);
                          free(*ppiVar30);
                          stratum_shares = ppiVar20;
                        }
                        else {
                          if (__ptr == (void *)((int)ppvVar28[4] + iVar29)) {
                            uVar19 = *(undefined4 *)((int)__ptr + 8);
                            ppvVar28[4] = (void *)((int)pvVar24 + iVar10);
                          }
                          else {
                            uVar19 = *(undefined4 *)((int)__ptr + 8);
                          }
                          *(undefined4 *)((int)(void *)((int)pvVar24 + iVar10) + 8) = uVar19;
                          ppiVar20 = *(int ***)((int)__ptr + 8);
                          if (ppiVar20 != (int **)0x0) {
LAB_00027ec2:
                            *(int *)((int)ppiVar20 + (*ppiVar30)[5] + 4) = iVar10;
                          }
                          piVar9 = *ppiVar30;
                          iVar10 = *piVar9;
                          uVar16 = piVar9[1] - 1U & uVar16;
                          iVar29 = iVar10 + uVar16 * 0xc;
                          pvVar17 = *(void **)(iVar10 + uVar16 * 0xc);
                          *(int *)(iVar29 + 4) = *(int *)(iVar29 + 4) + -1;
                          if (pvVar17 == __ptr) {
                            iVar29 = *(int *)((int)__ptr + 0x10);
                            *(int *)(iVar10 + uVar16 * 0xc) = iVar29;
                          }
                          else {
                            iVar29 = *(int *)((int)__ptr + 0x10);
                          }
                          iVar10 = *(int *)((int)__ptr + 0xc);
                          if (iVar10 != 0) {
                            *(int *)(iVar10 + 0x10) = iVar29;
                            iVar29 = *(int *)((int)__ptr + 0x10);
                          }
                          if (iVar29 != 0) {
                            *(int *)(iVar29 + 0xc) = iVar10;
                          }
                          piVar9[3] = piVar9[3] + -1;
                        }
                        uVar19 = DAT_00028220;
                        param_1[0xb7] = param_1[0xb7] + -1;
                        _mutex_unlock_constprop_76(DAT_00028224,uVar19,0x1c2d);
                        iVar10 = *(int *)((int)__ptr + 0x24);
                        tVar12 = time((time_t *)0x0);
                        ptVar6 = (timeval *)(tVar12 - *(int *)((int)__ptr + 0x30));
                        bVar21 = opt_debug;
                        if (0 < (int)ptVar6) {
                          bVar21 = opt_debug | 1;
                        }
                        if ((bVar21 != 0) &&
                           (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)
                            ))) {
                          snprintf((char *)&local_838,0x800,
                                   "Pool %d stratum share result lag time %d seconds",
                                   **(undefined4 **)(iVar10 + 0x104));
                          _applog(6,&local_838,0);
                          in_stack_fffff548 = ptVar6;
                        }
                        pcVar11 = &cStack_839;
                        iVar29 = 0;
                        uVar16 = *(uint *)(iVar10 + 0xdc);
                        local_838 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xd8);
                        local_834 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xd4);
                        local_830 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xd0);
                        local_82c = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xcc);
                        local_828 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 200);
                        local_824 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xc4);
                        local_820 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        uVar16 = *(uint *)(iVar10 + 0xc0);
                        local_81c = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 |
                                    (uVar16 >> 0x10 & 0xff) << 8 | uVar16 >> 0x18;
                        goto LAB_00028000;
                      }
                      iVar10 = *(int *)((int)__ptr + 0x10);
                    } while (iVar10 != 0);
                  }
                }
                _mutex_unlock_constprop_76(DAT_00027e78,DAT_00027e74,0x1c2d);
                if (local_a84 != (int *)0x0) {
                  iVar10 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
                  if (iVar10 != 0) {
LAB_00028826:
                    /* WARNING: Subroutine does not return */
                    _mutex_lock_part_47_constprop_75(DAT_00028844,0x1c39);
                  }
                  iVar10 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x3b));
                  if (iVar10 != 0) {
                    _rd_lock_part_39_constprop_80(DAT_00028844,0x1c39);
                    goto LAB_00028826;
                  }
                  iVar10 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
                  if (iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
                    _mutex_unlock_noyield_part_48_constprop_77(DAT_00028844,0x1c39);
                  }
                  dVar34 = *(double *)(param_1 + 0x1c8);
                  _wr_unlock_constprop_78((pthread_rwlock_t *)(param_1 + 0x3b),DAT_00027e74,0x1c3b);
                  if (*local_a84 == 5) {
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                      snprintf((char *)&local_838,0x800,
                               "Accepted untracked stratum share from pool %d",*param_1);
                      _applog(5,&local_838,0);
                    }
                    iVar10 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
                    if (iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
                      _mutex_lock_part_47_constprop_75(DAT_00028818,0x1c43);
                    }
                    uVar16 = param_1[2];
                    puVar18 = &total_accepted;
                    total_diff_accepted = total_diff_accepted + dVar34;
                    uVar19 = 0x1c48;
                    param_1[2] = uVar16 + 1;
                    param_1[3] = param_1[3] + (uint)(0xfffffffe < uVar16);
                    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + dVar34;
                    uVar16 = (uint)total_accepted;
                    iVar10 = total_accepted._4_4_;
                  }
                  else {
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                      snprintf((char *)&local_838,0x800,
                               "Rejected untracked stratum share from pool %d",*param_1);
                      _applog(5,&local_838,0);
                    }
                    iVar10 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
                    if (iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
                      _mutex_lock_part_47_constprop_75(DAT_00028844,0x1c4e);
                    }
                    uVar16 = param_1[4];
                    puVar18 = &total_rejected;
                    total_diff_rejected = total_diff_rejected + dVar34;
                    uVar19 = 0x1c53;
                    param_1[4] = uVar16 + 1;
                    param_1[5] = param_1[5] + (uint)(0xfffffffe < uVar16);
                    iVar10 = total_rejected._4_4_;
                    uVar16 = (uint)total_rejected;
                    *(double *)(param_1 + 0x14) = *(double *)(param_1 + 0x14) + dVar34;
                  }
                  *(uint *)puVar18 = uVar16 + 1;
                  *(uint *)((int)puVar18 + 4) = iVar10 + (uint)(0xfffffffe < uVar16);
                  _mutex_unlock_constprop_76(stats_lock,DAT_00027e74,uVar19);
                }
              }
            }
            if (*(int *)(iVar5 + 4) != -1) {
              iVar10 = *(int *)(iVar5 + 4) + -1;
              *(int *)(iVar5 + 4) = iVar10;
              if (iVar10 != 0) goto LAB_00027922;
              goto LAB_00027916;
            }
            goto LAB_00027922;
          }
          if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6))
          goto LAB_00027922;
          in_stack_fffff548 = atStack_8d8;
          snprintf((char *)&local_838,0x800,"JSON decode failed(%d): %s",local_934[0]);
          _applog(6,&local_838,0);
          iVar5 = parse_version_rolling_mask(param_1,pcVar7);
          if (iVar5 != 0) goto LAB_00027696;
          goto LAB_00027930;
        }
        goto LAB_00027696;
      }
      goto LAB_0002779c;
    }
    in_stack_fffff548 = &local_a64;
    ptVar6 = (timeval *)
             select(param_1[0x93] + 1,&local_9b4,(fd_set *)0x0,(fd_set *)0x0,in_stack_fffff548);
    if (0 < (int)ptVar6) goto LAB_0002766c;
    if (opt_debug != 0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
      goto LAB_000279b6;
      snprintf((char *)&local_838,0x800,"Stratum select failed on pool %d with value %d",*param_1);
      _applog(7,&local_838,0);
      in_stack_fffff548 = ptVar6;
    }
LAB_0002779c:
    if ((use_syslog == '\0') && (opt_log_output == '\0')) {
LAB_000279b6:
      if (4 < opt_log_level) goto LAB_000277b0;
    }
    else {
LAB_000277b0:
      snprintf((char *)&local_838,0x800,"Stratum connection to pool %d interrupted",*param_1);
      _applog(5,&local_838,0);
    }
    param_1[0x20] = param_1[0x20] + 1;
    total_go = total_go + 1;
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      uVar27 = 0x1ce4;
      uVar19 = DAT_00027cb8;
LAB_00027ab6:
      pcVar7 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
LAB_00027ac6:
      snprintf((char *)&local_838,0x800,pcVar7,iVar5,"cgminer.c",uVar19,uVar27);
      _applog(3,&local_838,1);
                    /* WARNING: Subroutine does not return */
      __quit(1);
    }
    iVar5 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x3b));
    uVar19 = DAT_00027cb8;
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      pcVar7 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar27 = 0x1ce4;
      goto LAB_00027ac6;
    }
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      uVar27 = 0x1ce4;
      uVar19 = DAT_00027cb8;
LAB_00027af4:
      pcVar7 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
      goto LAB_00027ac6;
    }
    iVar10 = param_1[0x9f];
    iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
    uVar19 = DAT_00027cb8;
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      pcVar7 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
      uVar27 = 0x1ce6;
      goto LAB_00027ac6;
    }
    (*selective_yield)();
    if ((iVar10 == 0) || (opt_lowmem != '\0')) {
      clear_stratum_shares(param_1);
    }
    clear_pool_work(param_1);
    puVar25 = (undefined4 *)current_pool();
    if (param_1 == puVar25) {
      restart_threads();
    }
    iVar5 = restart_stratum(param_1);
    while (iVar5 == 0) {
      pool_died(param_1);
      if (*(char *)((int)param_1 + 0x69) != '\0') {
        return 0;
      }
      cgsleep_ms(5000);
      iVar5 = restart_stratum(param_1);
    }
  } while( true );
  while (iVar29 = iVar29 + 1, iVar29 != 0x1d) {
LAB_00028000:
    pcVar11 = pcVar11 + 1;
    if (*pcVar11 != '\0') break;
  }
  uVar16 = *(uint *)((int)&local_838 + iVar29);
  round((double)CONCAT44(in_stack_fffff54c,in_stack_fffff548));
  __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff54c,in_stack_fffff548));
  suffix_string(*(undefined4 *)(iVar10 + 0xe8),*(undefined4 *)(iVar10 + 0xec),&local_a18,0x10,0);
  in_stack_fffff548 = (timeval *)&local_a18;
  snprintf(acStack_9f4,0x40,"%08lx Diff %s/%llu%s",
           uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
           uVar16 >> 0x18);
  puVar25 = *(undefined4 **)(iVar10 + 0x104);
  iVar29 = get_thread(*(undefined4 *)(iVar10 + 0x100));
  iVar29 = *(int *)(iVar29 + 0x24);
  if ((local_a84 == (int *)0x0) ||
     ((*local_a84 != 5 && ((*(char *)(iVar10 + 0x144) == '\0' || (*local_a84 != 7)))))) {
    iVar13 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar13 != 0) {
                    /* WARNING: Subroutine does not return */
      _mutex_lock_part_47_constprop_75(DAT_000284a4,0xdca);
    }
    dVar34 = *(double *)(iVar29 + 0xd0);
    dVar33 = *(double *)(iVar10 + 0x178);
    dVar32 = *(double *)(puVar25 + 0x14);
    uVar16 = puVar25[4];
    iVar13 = puVar25[5];
    *(int *)(iVar29 + 0x28) = *(int *)(iVar29 + 0x28) + 1;
    total_diff_rejected = total_diff_rejected + dVar33;
    iVar26 = puVar25[6];
    puVar25[4] = uVar16 + 1;
    puVar25[5] = iVar13 + (uint)(0xfffffffe < uVar16);
    *(double *)(iVar29 + 0xd0) = dVar34 + dVar33;
    puVar25[6] = iVar26 + 1;
    *(double *)(puVar25 + 0x14) = dVar32 + dVar33;
    bVar31 = 0xfffffffe < (uint)total_rejected;
    total_rejected._0_4_ = (uint)total_rejected + 1;
    total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar31;
    _mutex_unlock_constprop_76(stats_lock,DAT_00028228,0xdd2);
    if ((opt_debug != 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_838._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[0];
      local_838._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[1];
      local_838._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[2];
      local_838._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[3];
      local_834._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[4];
      local_834._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[5];
      local_834._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[6];
      local_834._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[7];
      local_830._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[8];
      local_830._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[9];
      local_830._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[10];
      local_830._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[11];
      local_82c._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[12];
      local_82c._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[13];
      local_82c._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[14];
      local_82c._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[15];
      local_828._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[16];
      local_828._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[17];
      local_828._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[18];
      local_828._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[19];
      local_824._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[20];
      local_824._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[21];
      local_824._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[22];
      local_824._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[23];
      local_820._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[24];
      local_820._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[25];
      local_820._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[26];
      local_820._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[27];
      local_81c._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[28];
      local_81c._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[29];
      local_81c._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[30];
      local_81c._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[31];
      local_818._0_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[32];
      local_818._1_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[33];
      local_818._2_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[34];
      local_818._3_1_ = s_PROOF_OF_WORK_RESULT__false__boo_0005e484[35];
      local_814 = (undefined)ram0x0005e4a8;
      _applog(7,&local_838,0);
    }
    cVar1 = opt_realquiet;
    if ((opt_quiet == '\0') && (opt_realquiet == '\0')) {
      local_a18._0_4_ = *DAT_0002822c;
      local_a18._4_2_ = (undefined2)DAT_0002822c[1];
      local_a18._6_1_ = (undefined)((uint)DAT_0002822c[1] >> 0x10);
      memset((void *)((int)&local_a18 + 7),0,0x1d);
      local_a38 = cVar1;
      if (1 < total_pools) {
        snprintf(local_a4c,0x14,"pool %d",**(undefined4 **)(iVar10 + 0x104));
        cVar1 = local_a4c[0];
      }
      local_a4c[0] = cVar1;
      local_a70 = local_a4c;
      if (*(char *)(iVar10 + 0x144) == '\0') {
        local_a84 = (int *)json_object_get(iVar5,"reject-reason");
      }
      if (local_a84 == (int *)0x0) {
        if (piVar8 == (int *)0x0) {
          bVar21 = 0;
        }
        else {
          bVar21 = *(byte *)(iVar10 + 0x11c) & 1;
        }
        if (bVar21 != 0) {
          iVar13 = *piVar8;
          if (iVar13 == 1) {
            piVar8 = (int *)json_array_get(piVar8);
            if (piVar8 == (int *)0x0) goto LAB_000282b8;
            iVar13 = *piVar8;
          }
          if (iVar13 == 2) {
            uVar19 = json_string_value(piVar8);
            snprintf(&local_a38,0x1f," (%s)",uVar19);
          }
        }
      }
      else {
        pcVar11 = (char *)json_string_value(local_a84);
        sVar14 = strlen(pcVar11);
        if (0x1b < sVar14) {
          sVar14 = 0x1c;
        }
        local_a38 = ' ';
        local_a37 = 0x28;
        _cg_memcpy(auStack_a36,pcVar11,sVar14,"cgminer.c",DAT_000284a4,0xdfa);
        in_stack_fffff54c = 0xdff;
        auStack_a36[sVar14] = 0x29;
        auStack_a36[sVar14 + 1] = 0;
        in_stack_fffff548 = DAT_000284a4;
        _cg_memcpy((int)&local_a18 + 7,pcVar11,sVar14,"cgminer.c");
        local_a18._6_1_ = 0x3a;
        *(undefined *)((int)&local_a18 + sVar14 + 7) = 0;
      }
LAB_000282b8:
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        in_stack_fffff54c = *(undefined4 *)(iVar29 + 8);
        in_stack_fffff548 = *(timeval **)(*(int *)(iVar29 + 4) + 8);
        snprintf((char *)&local_838,0x800,"Rejected %s %s %d %s%s %s%s",acStack_9f4,
                 in_stack_fffff548,in_stack_fffff54c,local_a70,&local_a38,&DAT_000609ec,
                 &DAT_000609ec);
        _applog(5,&local_838,0);
      }
      sharelog(&local_a18,iVar10);
    }
    ptVar6 = (timeval *)puVar25[6];
    if (((10 < (int)ptVar6) && (*(char *)(iVar10 + 0x119) == '\0')) &&
       ((opt_disable_pool != '\0' && (1 < enabled_pools)))) {
      dVar34 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_);
      dVar32 = (dVar34 / *DAT_000284a8) * dVar2 * 3.0;
      dVar34 = (double)(longlong)(int)ptVar6;
      if (dVar34 != dVar32 && dVar34 < dVar32 == (NAN(dVar34) || NAN(dVar32))) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
          snprintf((char *)&local_838,0x800,"Pool %d rejected %d sequential shares, disabling!",
                   *puVar25);
          _applog(4,&local_838,0);
          in_stack_fffff548 = ptVar6;
        }
        if (puVar25[0x19] == 1) {
          enabled_pools = enabled_pools + -1;
        }
        puVar25[0x19] = 2;
        puVar15 = (undefined4 *)current_pool();
        if (puVar25 == puVar15) {
          switch_pools(0);
        }
        puVar25[6] = 0;
      }
    }
  }
  else {
    iVar13 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar13 != 0) {
                    /* WARNING: Subroutine does not return */
      _mutex_lock_part_47_constprop_75(DAT_00028814,0xd8b);
    }
    dVar33 = *(double *)(iVar10 + 0x178);
    dVar34 = *(double *)(iVar29 + 200);
    dVar32 = *(double *)(puVar25 + 0x12);
    uVar16 = puVar25[2];
    iVar13 = puVar25[3];
    *(int *)(iVar29 + 0x24) = *(int *)(iVar29 + 0x24) + 1;
    total_diff_accepted = total_diff_accepted + dVar33;
    puVar25[2] = uVar16 + 1;
    puVar25[3] = iVar13 + (uint)(0xfffffffe < uVar16);
    uVar19 = DAT_00028814;
    bVar31 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar31;
    *(double *)(iVar29 + 200) = dVar34 + dVar33;
    *(double *)(puVar25 + 0x12) = dVar32 + dVar33;
    _mutex_unlock_constprop_76(stats_lock,uVar19,0xd95);
    puVar25[6] = 0;
    *(undefined4 *)(iVar29 + 0xd8) = *puVar25;
    tVar12 = time((time_t *)0x0);
    bVar21 = opt_debug;
    uVar19 = *(undefined4 *)(iVar10 + 0x178);
    uVar27 = *(undefined4 *)(iVar10 + 0x17c);
    *(time_t *)(iVar29 + 0xdc) = tVar12;
    *(undefined4 *)(iVar29 + 0xe0) = uVar19;
    *(undefined4 *)(iVar29 + 0xe4) = uVar27;
    puVar25[0x58] = tVar12;
    puVar25[0x5a] = uVar19;
    puVar25[0x5b] = uVar27;
    if ((bVar21 != 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
       ) {
      local_838._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[0];
      local_838._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[1];
      local_838._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[2];
      local_838._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[3];
      local_834._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[4];
      local_834._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[5];
      local_834._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[6];
      local_834._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[7];
      local_830._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[8];
      local_830._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[9];
      local_830._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[10];
      local_830._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[11];
      local_82c._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[12];
      local_82c._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[13];
      local_82c._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[14];
      local_82c._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[15];
      local_828._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[16];
      local_828._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[17];
      local_828._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[18];
      local_828._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[19];
      local_824._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[20];
      local_824._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[21];
      local_824._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[22];
      local_824._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[23];
      local_820._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[24];
      local_820._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[25];
      local_820._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[26];
      local_820._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[27];
      local_81c._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[28];
      local_81c._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[29];
      local_81c._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[30];
      local_81c._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[31];
      local_818._0_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[32];
      local_818._1_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[33];
      local_818._2_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[34];
      local_818._3_1_ = s_PROOF_OF_WORK_RESULT__true__yay__0005e3a8[35];
      _applog(7,&local_838,0);
    }
    if ((opt_quiet == '\0') && (opt_realquiet == '\0')) {
      if (total_pools < 2) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
          in_stack_fffff54c = *(undefined4 *)(iVar29 + 8);
          in_stack_fffff548 = *(timeval **)(*(int *)(iVar29 + 4) + 8);
          snprintf((char *)&local_838,0x800,"Accepted %s %s %d %s%s",acStack_9f4,in_stack_fffff548,
                   in_stack_fffff54c,&DAT_000609ec,&DAT_000609ec);
          _applog(5,&local_838,0);
        }
      }
      else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        in_stack_fffff54c = *(undefined4 *)(iVar29 + 8);
        in_stack_fffff548 = *(timeval **)(*(int *)(iVar29 + 4) + 8);
        snprintf((char *)&local_838,0x800,"Accepted %s %s %d pool %d %s%s",acStack_9f4,
                 in_stack_fffff548,in_stack_fffff54c,**(undefined4 **)(iVar10 + 0x104),&DAT_000609ec
                 ,&DAT_000609ec);
        _applog(5,&local_838,0);
      }
    }
    sharelog("accept",iVar10);
    if ((opt_shares != 0) && ((double)(longlong)opt_shares <= total_diff_accepted)) {
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
        snprintf((char *)&local_838,0x800,
                 "Successfully mined %d accepted shares as requested and exiting.");
        _applog(4,&local_838,0);
      }
      kill_work();
    }
    if (puVar25[0x19] == 2) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
LAB_0002878a:
        puVar25[0x19] = 1;
        enabled_pools = enabled_pools + 1;
      }
      else {
        snprintf((char *)&local_838,0x800,"Rejecting pool %d now accepting shares, re-enabling!",
                 *puVar25);
        _applog(4,&local_838,0);
        if (puVar25[0x19] != 1) goto LAB_0002878a;
      }
      switch_pools(0);
    }
    if (*(char *)(iVar10 + 0x11b) != '\0') {
      restart_threads();
    }
  }
  _free_work((int)__ptr + 0x24,"cgminer.c",DAT_000284ac,0x1c5a);
  free(__ptr);
  if ((*(int *)(iVar5 + 4) != -1) &&
     (iVar10 = *(int *)(iVar5 + 4) + -1, *(int *)(iVar5 + 4) = iVar10, iVar10 == 0)) {
    iVar10 = 1;
LAB_00027916:
    json_delete(iVar5);
    if (iVar10 == 0) {
LAB_00027922:
      iVar5 = parse_version_rolling_mask(param_1,pcVar7);
      if (iVar5 == 0) {
LAB_00027930:
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
          snprintf((char *)&local_838,0x800,"Unknown stratum msg: %s",pcVar7);
          _applog(6,&local_838,0);
        }
        goto LAB_000276a0;
      }
    }
  }
LAB_00027696:
  if (*(char *)(param_1 + 0xaa) != '\0') {
    local_838 = make_work();
    *(undefined *)(param_1 + 0xaa) = 0;
    gen_stratum_work(param_1,local_838);
    *(undefined *)(local_838 + 0x118) = 1;
    test_work_current();
    _free_work(&local_838,"cgminer.c",DAT_00027cb0,0x1d56);
  }
LAB_000276a0:
  free(pcVar7);
  cVar1 = *(char *)((int)param_1 + 0x69);
  goto joined_r0x000275fa;
}

