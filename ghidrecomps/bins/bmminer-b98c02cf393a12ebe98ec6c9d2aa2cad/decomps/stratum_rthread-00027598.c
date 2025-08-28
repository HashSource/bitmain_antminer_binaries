
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 stratum_rthread(undefined4 *param_1)

{
  char cVar1;
  pthread_t __th;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  time_t tVar8;
  size_t sVar9;
  undefined4 *puVar10;
  uint uVar11;
  void *pvVar12;
  undefined4 uVar13;
  int *piVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  void *__ptr;
  int iVar22;
  bool bVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  int *local_a84;
  char *local_a70;
  uint local_a68;
  timeval local_a64;
  char acStack_a5c [16];
  char local_a4c [20];
  char local_a38;
  undefined1 local_a37;
  undefined1 auStack_a36 [30];
  char local_a18 [4];
  undefined2 local_a14;
  undefined1 local_a12;
  undefined1 auStack_a11 [29];
  char acStack_9f4 [60];
  undefined4 uStack_9b8;
  fd_set local_9b4;
  undefined4 local_934 [23];
  undefined1 auStack_8d8 [159];
  char cStack_839;
  uint local_838 [8];
  char local_818 [2020];
  
  __th = pthread_self();
  pthread_detach(__th);
  snprintf(acStack_a5c,0x10,"%d/RStratum",*param_1);
  RenameThread(acStack_a5c);
  do {
    cVar1 = *(char *)((int)param_1 + 0x69);
joined_r0x000275fa:
    if (cVar1 != '\0') {
      suspend_stratum();
      return 0;
    }
    iVar2 = sock_full(param_1);
    if ((iVar2 == 0) && (iVar2 = cnx_needed(param_1), iVar2 == 0)) {
      suspend_stratum(param_1);
      clear_stratum_shares(param_1);
      clear_pool_work(param_1);
      iVar2 = cnx_needed(param_1);
      while ((iVar2 == 0 &&
             ((param_1[0x19] == 0 ||
              ((puVar21 = (undefined4 *)current_pool(), param_1 != puVar21 &&
               (1 < pool_strategy - 3U))))))) {
        iVar2 = pthread_mutex_lock((pthread_mutex_t *)lp_lock);
        if (iVar2 != 0) {
          piVar4 = __errno_location();
          pcVar3 = "wait_lpcurrent";
          iVar2 = *piVar4;
          uVar13 = 0x2649;
          goto LAB_00027ab6;
        }
        pthread_cond_wait((pthread_cond_t *)lp_cond,(pthread_mutex_t *)lp_lock);
        iVar2 = pthread_mutex_unlock((pthread_mutex_t *)lp_lock);
        if (iVar2 != 0) {
          piVar4 = __errno_location();
          pcVar3 = "wait_lpcurrent";
          iVar2 = *piVar4;
          uVar13 = 0x264b;
          goto LAB_00027af4;
        }
        (*selective_yield)();
        iVar2 = cnx_needed(param_1);
      }
      while (iVar2 = restart_stratum(param_1), iVar2 == 0) {
        pool_died(param_1);
        if (*(char *)((int)param_1 + 0x69) != '\0') {
          return 0;
        }
        cgsleep_ms(5000);
      }
    }
    puVar21 = &uStack_9b8;
    do {
      puVar21 = puVar21 + 1;
      *puVar21 = 0;
    } while (local_9b4.fds_bits + 0x1f != puVar21);
    uVar16 = param_1[0x93];
    local_a64.tv_usec = 0;
    local_a64.tv_sec = 0x5a;
    uVar11 = uVar16 + 0x1f & (int)uVar16 >> 0x20;
    if (local_9b4.fds_bits + 0x1f < puVar21) {
      uVar11 = uVar16;
    }
    uVar17 = uVar16 & 0x1f;
    if ((int)uVar16 < 1) {
      uVar17 = -(-uVar16 & 0x1f);
    }
    local_9b4.fds_bits[(int)uVar11 >> 5] =
         local_9b4.fds_bits[(int)uVar11 >> 5] | 1 << (uVar17 & 0xff);
    iVar2 = sock_full(param_1);
    if ((iVar2 == 0) &&
       (iVar2 = select(param_1[0x93] + 1,&local_9b4,(fd_set *)0x0,(fd_set *)0x0,&local_a64),
       iVar2 < 1)) {
      if (opt_debug != 0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
        goto LAB_000279b6;
        snprintf((char *)local_838,0x800,"Stratum select failed on pool %d with value %d",*param_1,
                 iVar2);
        _applog(7,local_838,0);
      }
    }
    else {
      pcVar3 = (char *)recv_line(param_1);
      if (pcVar3 != (char *)0x0) {
        stratum_resumed(param_1);
        iVar2 = parse_method(param_1,pcVar3);
        if (iVar2 == 0) {
          iVar2 = json_loads(pcVar3,0,local_934);
          if (iVar2 != 0) {
            local_a84 = (int *)json_object_get(iVar2,"result");
            piVar4 = (int *)json_object_get(iVar2,"error");
            piVar5 = (int *)json_object_get(iVar2,&DAT_0005e278);
            if ((piVar5 == (int *)0x0) || (*piVar5 == 7)) {
              if (piVar4 == (int *)0x0) {
                pcVar7 = (char *)malloc(0x11);
                if (pcVar7 != (char *)0x0) {
                  builtin_strncpy(pcVar7,"(unknown reason)",0x11);
                }
              }
              else {
                pcVar7 = (char *)json_dumps(piVar4,3);
              }
              if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                snprintf((char *)local_838,0x800,"JSON-RPC non method decode failed: %s",pcVar7);
                _applog(6,local_838,0);
              }
              free(pcVar7);
            }
            else {
              iVar6 = json_object_get(local_a84,"version-rolling.mask");
              if (((iVar6 == 0) &&
                  (pcVar7 = strstr(pcVar3,"mining.configure"), pcVar7 == (char *)0x0)) &&
                 (pcVar7 = strstr(pcVar3,"mining.set_version_mask"), pcVar7 == (char *)0x0)) {
                local_a68 = json_integer_value(piVar5);
                iVar6 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
                piVar5 = stratum_shares;
                if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
                  _mutex_lock_part_47_constprop_75("parse_stratum_response",0x1c25);
                }
                uVar17 = (local_a68 & 0xff) + 0x112410d + (local_a68 & 0xff000000) +
                         (local_a68 >> 0x10 & 0xff) * 0x10000 + (local_a68 >> 8 & 0xff) * 0x100 ^
                         0x7f76d;
                uVar16 = 0x9f49bac6 - uVar17 ^ uVar17 << 8;
                uVar11 = (-0x112410d - uVar17) - uVar16 ^ uVar16 >> 0xd;
                uVar17 = (uVar17 - uVar16) - uVar11 ^ uVar11 >> 0xc;
                uVar16 = (uVar16 - uVar11) - uVar17 ^ uVar17 << 0x10;
                uVar11 = (uVar11 - uVar17) - uVar16 ^ uVar16 >> 5;
                uVar17 = (uVar17 - uVar16) - uVar11 ^ uVar11 >> 3;
                uVar16 = (uVar16 - uVar11) - uVar17 ^ uVar17 << 10;
                uVar11 = (uVar11 - uVar17) - uVar16 ^ uVar16 >> 0xf;
                if (stratum_shares != (int *)0x0) {
                  puVar21 = (undefined4 *)*stratum_shares;
                  pvVar12 = (void *)*puVar21;
                  iVar6 = *(int *)((int)pvVar12 + (puVar21[1] - 1 & uVar11) * 0xc);
                  if (iVar6 != 0) {
                    iVar18 = puVar21[5];
                    iVar22 = -iVar18;
                    do {
                      __ptr = (void *)(iVar6 + iVar22);
                      if (__ptr == (void *)0x0) break;
                      if (((uVar11 == *(uint *)((int)__ptr + 0x1c)) &&
                          (*(int *)((int)__ptr + 0x18) == 4)) &&
                         (iVar6 = memcmp(*(void **)((int)__ptr + 0x14),&local_a68,4), iVar6 == 0)) {
                        iVar6 = *(int *)((int)__ptr + 4);
                        if (iVar6 == 0) {
                          piVar14 = *(int **)((int)__ptr + 8);
                          if (piVar14 != (int *)0x0) {
                            piVar5 = piVar14;
                            stratum_shares = piVar14;
                            if (__ptr == (void *)(iVar22 + puVar21[4])) {
                              puVar21[4] = iVar18;
                            }
                            goto LAB_00027ec2;
                          }
                          free(pvVar12);
                          free((void *)*piVar5);
                          stratum_shares = piVar14;
                        }
                        else {
                          if (__ptr == (void *)(puVar21[4] + iVar22)) {
                            uVar13 = *(undefined4 *)((int)__ptr + 8);
                            puVar21[4] = iVar18 + iVar6;
                          }
                          else {
                            uVar13 = *(undefined4 *)((int)__ptr + 8);
                          }
                          *(undefined4 *)(iVar18 + iVar6 + 8) = uVar13;
                          piVar14 = *(int **)((int)__ptr + 8);
                          if (piVar14 != (int *)0x0) {
LAB_00027ec2:
                            *(int *)((int)piVar14 + *(int *)(*piVar5 + 0x14) + 4) = iVar6;
                          }
                          piVar5 = (int *)*piVar5;
                          iVar6 = *piVar5;
                          uVar11 = piVar5[1] - 1U & uVar11;
                          iVar22 = iVar6 + uVar11 * 0xc;
                          pvVar12 = *(void **)(iVar6 + uVar11 * 0xc);
                          *(int *)(iVar22 + 4) = *(int *)(iVar22 + 4) + -1;
                          if (pvVar12 == __ptr) {
                            iVar22 = *(int *)((int)__ptr + 0x10);
                            *(int *)(iVar6 + uVar11 * 0xc) = iVar22;
                          }
                          else {
                            iVar22 = *(int *)((int)__ptr + 0x10);
                          }
                          iVar6 = *(int *)((int)__ptr + 0xc);
                          if (iVar6 != 0) {
                            *(int *)(iVar6 + 0x10) = iVar22;
                            iVar22 = *(int *)((int)__ptr + 0x10);
                          }
                          if (iVar22 != 0) {
                            *(int *)(iVar22 + 0xc) = iVar6;
                          }
                          piVar5[3] = piVar5[3] + -1;
                        }
                        param_1[0xb7] = param_1[0xb7] + -1;
                        _mutex_unlock_constprop_76(sshare_lock,"parse_stratum_response",0x1c2d);
                        iVar6 = *(int *)((int)__ptr + 0x24);
                        tVar8 = time((time_t *)0x0);
                        iVar22 = tVar8 - *(int *)((int)__ptr + 0x30);
                        bVar15 = opt_debug;
                        if (0 < iVar22) {
                          bVar15 = opt_debug | 1;
                        }
                        if ((bVar15 != 0) &&
                           (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)
                            ))) {
                          snprintf((char *)local_838,0x800,
                                   "Pool %d stratum share result lag time %d seconds",
                                   **(undefined4 **)(iVar6 + 0x104),iVar22);
                          _applog(6,local_838,0);
                        }
                        pcVar7 = &cStack_839;
                        iVar22 = 0;
                        uVar11 = *(uint *)(iVar6 + 0xdc);
                        local_838[0] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xd8);
                        local_838[1] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xd4);
                        local_838[2] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xd0);
                        local_838[3] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xcc);
                        local_838[4] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 200);
                        local_838[5] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xc4);
                        local_838[6] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        uVar11 = *(uint *)(iVar6 + 0xc0);
                        local_838[7] = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                       (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                        goto LAB_00028000;
                      }
                      iVar6 = *(int *)((int)__ptr + 0x10);
                    } while (iVar6 != 0);
                  }
                }
                _mutex_unlock_constprop_76(sshare_lock,"parse_stratum_response",0x1c2d);
                if (local_a84 != (int *)0x0) {
                  iVar6 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
                  if (iVar6 != 0) {
LAB_00028826:
                    /* WARNING: Subroutine does not return */
                    _mutex_lock_part_47_constprop_75("parse_stratum_response",0x1c39);
                  }
                  iVar6 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x3b));
                  if (iVar6 != 0) {
                    _rd_lock_part_39_constprop_80("parse_stratum_response",0x1c39);
                    goto LAB_00028826;
                  }
                  iVar6 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
                  if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
                    _mutex_unlock_noyield_part_48_constprop_77("parse_stratum_response",0x1c39);
                  }
                  dVar26 = *(double *)(param_1 + 0x1c8);
                  _wr_unlock_constprop_78
                            ((pthread_rwlock_t *)(param_1 + 0x3b),"parse_stratum_response",0x1c3b);
                  if (*local_a84 == 5) {
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                      snprintf((char *)local_838,0x800,
                               "Accepted untracked stratum share from pool %d",*param_1);
                      _applog(5,local_838,0);
                    }
                    iVar6 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
                    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
                      _mutex_lock_part_47_constprop_75("parse_stratum_response",0x1c43);
                    }
                    uVar11 = param_1[2];
                    piVar4 = (int *)&total_accepted;
                    total_diff_accepted = total_diff_accepted + dVar26;
                    uVar13 = 0x1c48;
                    param_1[2] = uVar11 + 1;
                    param_1[3] = param_1[3] + (uint)(0xfffffffe < uVar11);
                    *(double *)(param_1 + 0x12) = *(double *)(param_1 + 0x12) + dVar26;
                    uVar11 = (uint)total_accepted;
                    iVar6 = total_accepted._4_4_;
                  }
                  else {
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
                      snprintf((char *)local_838,0x800,
                               "Rejected untracked stratum share from pool %d",*param_1);
                      _applog(5,local_838,0);
                    }
                    iVar6 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
                    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
                      _mutex_lock_part_47_constprop_75("parse_stratum_response",0x1c4e);
                    }
                    uVar11 = param_1[4];
                    piVar4 = (int *)&total_rejected;
                    total_diff_rejected = total_diff_rejected + dVar26;
                    uVar13 = 0x1c53;
                    param_1[4] = uVar11 + 1;
                    param_1[5] = param_1[5] + (uint)(0xfffffffe < uVar11);
                    iVar6 = total_rejected._4_4_;
                    uVar11 = (uint)total_rejected;
                    *(double *)(param_1 + 0x14) = *(double *)(param_1 + 0x14) + dVar26;
                  }
                  *piVar4 = uVar11 + 1;
                  piVar4[1] = iVar6 + (uint)(0xfffffffe < uVar11);
                  _mutex_unlock_constprop_76(stats_lock,"parse_stratum_response",uVar13);
                }
              }
            }
            if (*(int *)(iVar2 + 4) != -1) {
              iVar6 = *(int *)(iVar2 + 4) + -1;
              *(int *)(iVar2 + 4) = iVar6;
              if (iVar6 != 0) goto LAB_00027922;
              goto LAB_00027916;
            }
            goto LAB_00027922;
          }
          if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6))
          goto LAB_00027922;
          snprintf((char *)local_838,0x800,"JSON decode failed(%d): %s",local_934[0],auStack_8d8);
          _applog(6,local_838,0);
          iVar2 = parse_version_rolling_mask(param_1,pcVar3);
          if (iVar2 != 0) goto LAB_00027696;
          goto LAB_00027930;
        }
        goto LAB_00027696;
      }
    }
    if ((use_syslog == '\0') && (opt_log_output == '\0')) {
LAB_000279b6:
      if (4 < opt_log_level) goto LAB_000277b0;
    }
    else {
LAB_000277b0:
      snprintf((char *)local_838,0x800,"Stratum connection to pool %d interrupted",*param_1);
      _applog(5,local_838,0);
    }
    param_1[0x20] = param_1[0x20] + 1;
    total_go = total_go + 1;
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      pcVar3 = "supports_resume";
      iVar2 = *piVar4;
      uVar13 = 0x1ce4;
LAB_00027ab6:
      pcVar7 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
LAB_00027ac6:
      snprintf((char *)local_838,0x800,pcVar7,iVar2,"cgminer.c",pcVar3,uVar13);
      _applog(3,local_838,1);
                    /* WARNING: Subroutine does not return */
      __quit(1);
    }
    iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)(param_1 + 0x3b));
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      iVar2 = *piVar4;
      pcVar7 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      pcVar3 = "supports_resume";
      uVar13 = 0x1ce4;
      goto LAB_00027ac6;
    }
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      pcVar3 = "supports_resume";
      iVar2 = *piVar4;
      uVar13 = 0x1ce4;
LAB_00027af4:
      pcVar7 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
      goto LAB_00027ac6;
    }
    iVar6 = param_1[0x9f];
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x3b));
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      iVar2 = *piVar4;
      pcVar7 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
      pcVar3 = "supports_resume";
      uVar13 = 0x1ce6;
      goto LAB_00027ac6;
    }
    (*selective_yield)();
    if ((iVar6 == 0) || (opt_lowmem != '\0')) {
      clear_stratum_shares(param_1);
    }
    clear_pool_work(param_1);
    puVar21 = (undefined4 *)current_pool();
    if (param_1 == puVar21) {
      restart_threads();
    }
    iVar2 = restart_stratum(param_1);
    while (iVar2 == 0) {
      pool_died(param_1);
      if (*(char *)((int)param_1 + 0x69) != '\0') {
        return 0;
      }
      cgsleep_ms(5000);
      iVar2 = restart_stratum(param_1);
    }
  } while( true );
  while (iVar22 = iVar22 + 1, iVar22 != 0x1d) {
LAB_00028000:
    pcVar7 = pcVar7 + 1;
    if (*pcVar7 != '\0') break;
  }
  uVar11 = *(uint *)((int)local_838 + iVar22);
  dVar26 = round(*(double *)(iVar6 + 0x178));
  __fixunsdfdi(dVar26);
  suffix_string(*(undefined4 *)(iVar6 + 0xe8),*(undefined4 *)(iVar6 + 0xec),local_a18,0x10,0);
  pcVar7 = local_a18;
  snprintf(acStack_9f4,0x40,"%08lx Diff %s/%llu%s",
           uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 | (uVar11 >> 0x10 & 0xff) << 8 |
           uVar11 >> 0x18,pcVar7);
  puVar21 = *(undefined4 **)(iVar6 + 0x104);
  iVar22 = get_thread(*(undefined4 *)(iVar6 + 0x100));
  iVar22 = *(int *)(iVar22 + 0x24);
  if ((local_a84 == (int *)0x0) ||
     ((*local_a84 != 5 && ((*(char *)(iVar6 + 0x144) == '\0' || (*local_a84 != 7)))))) {
    iVar18 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar18 != 0) {
                    /* WARNING: Subroutine does not return */
      _mutex_lock_part_47_constprop_75("share_result",0xdca);
    }
    dVar26 = *(double *)(iVar22 + 0xd0);
    dVar25 = *(double *)(iVar6 + 0x178);
    dVar24 = *(double *)(puVar21 + 0x14);
    uVar11 = puVar21[4];
    iVar18 = puVar21[5];
    *(int *)(iVar22 + 0x28) = *(int *)(iVar22 + 0x28) + 1;
    total_diff_rejected = total_diff_rejected + dVar25;
    iVar19 = puVar21[6];
    puVar21[4] = uVar11 + 1;
    puVar21[5] = iVar18 + (uint)(0xfffffffe < uVar11);
    *(double *)(iVar22 + 0xd0) = dVar26 + dVar25;
    puVar21[6] = iVar19 + 1;
    *(double *)(puVar21 + 0x14) = dVar24 + dVar25;
    bVar23 = 0xfffffffe < (uint)total_rejected;
    total_rejected._0_4_ = (uint)total_rejected + 1;
    total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar23;
    _mutex_unlock_constprop_76(stats_lock,"share_result",0xdd2);
    if ((opt_debug != 0) &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_838[0]._0_1_ = 'P';
      local_838[0]._1_1_ = 'R';
      local_838[0]._2_1_ = 'O';
      local_838[0]._3_1_ = 'O';
      local_838[1]._0_1_ = 'F';
      local_838[1]._1_1_ = ' ';
      local_838[1]._2_1_ = 'O';
      local_838[1]._3_1_ = 'F';
      local_838[2]._0_1_ = ' ';
      local_838[2]._1_1_ = 'W';
      local_838[2]._2_1_ = 'O';
      local_838[2]._3_1_ = 'R';
      local_838[3]._0_1_ = 'K';
      local_838[3]._1_1_ = ' ';
      local_838[3]._2_1_ = 'R';
      local_838[3]._3_1_ = 'E';
      local_838[4]._0_1_ = 'S';
      local_838[4]._1_1_ = 'U';
      local_838[4]._2_1_ = 'L';
      local_838[4]._3_1_ = 'T';
      local_838[5]._0_1_ = ':';
      local_838[5]._1_1_ = ' ';
      local_838[5]._2_1_ = 'f';
      local_838[5]._3_1_ = 'a';
      local_838[6]._0_1_ = 'l';
      local_838[6]._1_1_ = 's';
      local_838[6]._2_1_ = 'e';
      local_838[6]._3_1_ = ' ';
      local_838[7]._0_1_ = '(';
      local_838[7]._1_1_ = 'b';
      local_838[7]._2_1_ = 'o';
      local_838[7]._3_1_ = 'o';
      builtin_strncpy(local_818,"ooo)",4);
      local_818[4] = 0;
      _applog(7,local_838,0);
    }
    cVar1 = opt_realquiet;
    if ((opt_quiet == '\0') && (opt_realquiet == '\0')) {
      local_a14 = 0x7463;
      builtin_strncpy(local_a18,"reje",4);
      local_a12 = 0;
      memset(auStack_a11,0,0x1d);
      local_a38 = cVar1;
      if (1 < total_pools) {
        snprintf(local_a4c,0x14,"pool %d",**(undefined4 **)(iVar6 + 0x104));
        cVar1 = local_a4c[0];
      }
      local_a4c[0] = cVar1;
      local_a70 = local_a4c;
      if (*(char *)(iVar6 + 0x144) == '\0') {
        local_a84 = (int *)json_object_get(iVar2,"reject-reason");
      }
      if (local_a84 == (int *)0x0) {
        if (piVar4 == (int *)0x0) {
          bVar15 = 0;
        }
        else {
          bVar15 = *(byte *)(iVar6 + 0x11c) & 1;
        }
        if (bVar15 != 0) {
          iVar18 = *piVar4;
          if (iVar18 == 1) {
            piVar4 = (int *)json_array_get(piVar4);
            if (piVar4 == (int *)0x0) goto LAB_000282b8;
            iVar18 = *piVar4;
          }
          if (iVar18 == 2) {
            uVar13 = json_string_value(piVar4);
            snprintf(&local_a38,0x1f," (%s)",uVar13);
          }
        }
      }
      else {
        pcVar7 = (char *)json_string_value(local_a84);
        sVar9 = strlen(pcVar7);
        if (0x1b < sVar9) {
          sVar9 = 0x1c;
        }
        local_a38 = ' ';
        local_a37 = 0x28;
        _cg_memcpy(auStack_a36,pcVar7,sVar9,"cgminer.c","share_result",0xdfa);
        auStack_a36[sVar9] = 0x29;
        auStack_a36[sVar9 + 1] = 0;
        _cg_memcpy(auStack_a11,pcVar7,sVar9,"cgminer.c","share_result",0xdff);
        local_a12 = 0x3a;
        auStack_a11[sVar9] = 0;
      }
LAB_000282b8:
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        snprintf((char *)local_838,0x800,"Rejected %s %s %d %s%s %s%s",acStack_9f4,
                 *(undefined4 *)(*(int *)(iVar22 + 4) + 8),*(undefined4 *)(iVar22 + 8),local_a70,
                 &local_a38,&DAT_000609ec,&DAT_000609ec);
        _applog(5,local_838,0);
      }
      sharelog(local_a18,iVar6);
    }
    iVar22 = puVar21[6];
    if (((10 < iVar22) && (*(char *)(iVar6 + 0x119) == '\0')) &&
       ((opt_disable_pool != '\0' &&
        ((1 < enabled_pools &&
         (dVar26 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_),
         (dVar26 / total_secs) * 60.0 * 3.0 < (double)(longlong)iVar22)))))) {
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
        snprintf((char *)local_838,0x800,"Pool %d rejected %d sequential shares, disabling!",
                 *puVar21,iVar22);
        _applog(4,local_838,0);
      }
      if (puVar21[0x19] == 1) {
        enabled_pools = enabled_pools + -1;
      }
      puVar21[0x19] = 2;
      puVar10 = (undefined4 *)current_pool();
      if (puVar21 == puVar10) {
        switch_pools(0);
      }
      puVar21[6] = 0;
    }
  }
  else {
    iVar18 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar18 != 0) {
                    /* WARNING: Subroutine does not return */
      _mutex_lock_part_47_constprop_75("share_result",0xd8b);
    }
    dVar25 = *(double *)(iVar6 + 0x178);
    dVar26 = *(double *)(iVar22 + 200);
    dVar24 = *(double *)(puVar21 + 0x12);
    uVar11 = puVar21[2];
    iVar18 = puVar21[3];
    *(int *)(iVar22 + 0x24) = *(int *)(iVar22 + 0x24) + 1;
    total_diff_accepted = total_diff_accepted + dVar25;
    puVar21[2] = uVar11 + 1;
    puVar21[3] = iVar18 + (uint)(0xfffffffe < uVar11);
    bVar23 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar23;
    *(double *)(iVar22 + 200) = dVar26 + dVar25;
    *(double *)(puVar21 + 0x12) = dVar24 + dVar25;
    _mutex_unlock_constprop_76(stats_lock,"share_result",0xd95);
    puVar21[6] = 0;
    *(undefined4 *)(iVar22 + 0xd8) = *puVar21;
    tVar8 = time((time_t *)0x0);
    bVar15 = opt_debug;
    uVar13 = *(undefined4 *)(iVar6 + 0x178);
    uVar20 = *(undefined4 *)(iVar6 + 0x17c);
    *(time_t *)(iVar22 + 0xdc) = tVar8;
    *(undefined4 *)(iVar22 + 0xe0) = uVar13;
    *(undefined4 *)(iVar22 + 0xe4) = uVar20;
    puVar21[0x58] = tVar8;
    puVar21[0x5a] = uVar13;
    puVar21[0x5b] = uVar20;
    if ((bVar15 != 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
       ) {
      local_838[0]._0_1_ = 'P';
      local_838[0]._1_1_ = 'R';
      local_838[0]._2_1_ = 'O';
      local_838[0]._3_1_ = 'O';
      local_838[1]._0_1_ = 'F';
      local_838[1]._1_1_ = ' ';
      local_838[1]._2_1_ = 'O';
      local_838[1]._3_1_ = 'F';
      local_838[2]._0_1_ = ' ';
      local_838[2]._1_1_ = 'W';
      local_838[2]._2_1_ = 'O';
      local_838[2]._3_1_ = 'R';
      local_838[3]._0_1_ = 'K';
      local_838[3]._1_1_ = ' ';
      local_838[3]._2_1_ = 'R';
      local_838[3]._3_1_ = 'E';
      local_838[4]._0_1_ = 'S';
      local_838[4]._1_1_ = 'U';
      local_838[4]._2_1_ = 'L';
      local_838[4]._3_1_ = 'T';
      local_838[5]._0_1_ = ':';
      local_838[5]._1_1_ = ' ';
      local_838[5]._2_1_ = 't';
      local_838[5]._3_1_ = 'r';
      local_838[6]._0_1_ = 'u';
      local_838[6]._1_1_ = 'e';
      local_838[6]._2_1_ = ' ';
      local_838[6]._3_1_ = '(';
      local_838[7]._0_1_ = 'y';
      local_838[7]._1_1_ = 'a';
      local_838[7]._2_1_ = 'y';
      local_838[7]._3_1_ = '!';
      builtin_strncpy(local_818,"!!)",4);
      _applog(7,local_838,0);
    }
    if ((opt_quiet == '\0') && (opt_realquiet == '\0')) {
      if (total_pools < 2) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
          pcVar7 = *(char **)(*(int *)(iVar22 + 4) + 8);
          snprintf((char *)local_838,0x800,"Accepted %s %s %d %s%s",acStack_9f4,pcVar7,
                   *(undefined4 *)(iVar22 + 8),&DAT_000609ec,&DAT_000609ec);
          _applog(5,local_838,0);
        }
      }
      else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        pcVar7 = *(char **)(*(int *)(iVar22 + 4) + 8);
        snprintf((char *)local_838,0x800,"Accepted %s %s %d pool %d %s%s",acStack_9f4,pcVar7,
                 *(undefined4 *)(iVar22 + 8),**(undefined4 **)(iVar6 + 0x104),&DAT_000609ec,
                 &DAT_000609ec);
        _applog(5,local_838,0);
      }
    }
    sharelog("accept",iVar6);
    if ((opt_shares != 0) && ((double)(longlong)opt_shares <= total_diff_accepted)) {
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
        snprintf((char *)local_838,0x800,
                 "Successfully mined %d accepted shares as requested and exiting.",opt_shares,pcVar7
                );
        _applog(4,local_838,0);
      }
      kill_work();
    }
    if (puVar21[0x19] == 2) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
LAB_0002878a:
        puVar21[0x19] = 1;
        enabled_pools = enabled_pools + 1;
      }
      else {
        snprintf((char *)local_838,0x800,"Rejecting pool %d now accepting shares, re-enabling!",
                 *puVar21);
        _applog(4,local_838,0);
        if (puVar21[0x19] != 1) goto LAB_0002878a;
      }
      switch_pools(0);
    }
    if (*(char *)(iVar6 + 0x11b) != '\0') {
      restart_threads();
    }
  }
  _free_work((int)__ptr + 0x24,"cgminer.c","parse_stratum_response",0x1c5a);
  free(__ptr);
  if ((*(int *)(iVar2 + 4) != -1) &&
     (iVar6 = *(int *)(iVar2 + 4) + -1, *(int *)(iVar2 + 4) = iVar6, iVar6 == 0)) {
    iVar6 = 1;
LAB_00027916:
    json_delete(iVar2);
    if (iVar6 == 0) {
LAB_00027922:
      iVar2 = parse_version_rolling_mask(param_1,pcVar3);
      if (iVar2 == 0) {
LAB_00027930:
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
          snprintf((char *)local_838,0x800,"Unknown stratum msg: %s",pcVar3);
          _applog(6,local_838,0);
        }
        goto LAB_000276a0;
      }
    }
  }
LAB_00027696:
  if (*(char *)(param_1 + 0xaa) != '\0') {
    local_838[0] = make_work();
    *(undefined1 *)(param_1 + 0xaa) = 0;
    gen_stratum_work(param_1,local_838[0]);
    *(undefined1 *)(local_838[0] + 0x118) = 1;
    test_work_current();
    _free_work(local_838,"cgminer.c","stratum_rthread",0x1d56);
  }
LAB_000276a0:
  free(pcVar3);
  cVar1 = *(char *)((int)param_1 + 0x69);
  goto joined_r0x000275fa;
}

