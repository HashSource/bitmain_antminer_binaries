
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 stratum_sthread(undefined4 *param_1)

{
  char cVar1;
  pthread_t __th;
  int iVar2;
  int *piVar3;
  time_t tVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  byte bVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  undefined4 *puVar23;
  char *pcVar24;
  pthread_rwlock_t *__rwlock;
  bool bVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  int local_ca8;
  void *local_ca4;
  int local_c6c;
  int local_c68;
  uint local_c64;
  int local_c60;
  int iStack_c5c;
  undefined1 auStack_c58 [12];
  char acStack_c4c [16];
  undefined1 auStack_c3c [20];
  char acStack_c28 [1024];
  char local_828 [40];
  undefined4 uStack_800;
  char acStack_7fc [4];
  undefined4 local_7f8;
  undefined2 local_7f4;
  
  __th = pthread_self();
  pthread_detach(__th);
  snprintf(acStack_c4c,0x10,"%d/SStratum",*param_1);
  RenameThread(acStack_c4c);
  iVar2 = tq_new();
  param_1[0xb6] = iVar2;
  if (iVar2 == 0) {
    local_828[0] = 'F';
    local_828[1] = 'a';
    local_828[2] = 'i';
    local_828[3] = 'l';
    local_828[4] = 'e';
    local_828[5] = 'd';
    local_828[6] = ' ';
    local_828[7] = 't';
    local_828[8] = 'o';
    local_828[9] = ' ';
    local_828[10] = 'c';
    local_828[0xb] = 'r';
    local_828[0xc] = 'e';
    local_828[0xd] = 'a';
    local_828[0xe] = 't';
    local_828[0xf] = 'e';
    pcVar24 = " stratum_q in stratum_sthread";
    pcVar13 = local_828 + 0x10;
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x69);
    iVar5 = 0;
    iVar11 = 0;
    iVar18 = 0;
    while( true ) {
      if (cVar1 != '\0') {
        tq_freeze();
        return 0;
      }
      local_c68 = tq_pop(iVar2);
      if (local_c68 == 0) break;
      if (*(uint *)(local_c68 + 0x130) < 9) {
        iVar9 = *(int *)(local_c68 + 0x4c);
        iVar15 = *(int *)(local_c68 + 0x128);
        iVar20 = *(int *)(local_c68 + 300);
        local_c6c = iVar9;
        local_c60 = iVar15;
        iStack_c5c = iVar20;
        if (iVar11 == iVar9 && (iVar18 == iVar20 && iVar5 == iVar15)) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf(local_828,0x800,"Filtering duplicate share to pool %d",*param_1);
            _applog(6,local_828,0);
          }
          _free_work(&local_c68,"cgminer.c","stratum_sthread",0x1d99);
          iVar9 = iVar11;
          iVar15 = iVar5;
          iVar20 = iVar18;
        }
        else {
          __bin2hex(auStack_c58,&local_c6c,4);
          __bin2hex(auStack_c3c,&local_c60,*(undefined4 *)(local_c68 + 0x130));
          piVar3 = (int *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1da2);
          iVar2 = local_c68;
          tVar4 = time((time_t *)0x0);
          piVar3[0xb] = tVar4;
          piVar3[9] = local_c68;
          memset(acStack_c28,0,0x400);
          iVar5 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
          if (iVar5 != 0) {
            piVar3 = __errno_location();
            iVar2 = *piVar3;
            uVar21 = 0x1dab;
LAB_000247ea:
            pcVar13 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
LAB_00024800:
            snprintf(local_828,0x800,pcVar13,iVar2,"cgminer.c","stratum_sthread",uVar21);
            _applog(3,local_828,1);
                    /* WARNING: Subroutine does not return */
            __quit(1);
          }
          piVar3[10] = swork_id;
          swork_id = swork_id + 1;
          uVar6 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
          if (uVar6 != 0) {
            piVar3 = __errno_location();
            iVar2 = *piVar3;
            uVar21 = 0x1dae;
LAB_0002482e:
            pcVar13 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
            goto LAB_00024800;
          }
          (*selective_yield)();
          local_c64 = uVar6;
          hex2bin(&local_c64,param_1 + 0x1bd,4);
          if (*(char *)(param_1 + 0xa1) == '\0') {
            puVar27 = auStack_c58;
            puVar26 = auStack_c3c;
            uVar6 = piVar3[10];
            uVar21 = *(undefined4 *)(local_c68 + 0x134);
            snprintf(acStack_c28,0x400,
                     "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
                     ,param_1[0x2b],*(undefined4 *)(local_c68 + 0x120),puVar26,uVar21,puVar27,uVar6)
            ;
          }
          else {
            puVar27 = auStack_c58;
            uVar6 = *(uint *)(local_c68 + 0x1bc) & ~local_c64;
            uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                    uVar6 >> 0x18;
            puVar26 = auStack_c3c;
            uVar21 = *(undefined4 *)(local_c68 + 0x134);
            snprintf(acStack_c28,0x400,
                     "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
                     ,param_1[0x2b],*(undefined4 *)(local_c68 + 0x120),puVar26,uVar21,puVar27,uVar6,
                     piVar3[10]);
          }
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf(local_828,0x800,"Submitting share %08lx to pool %d",
                     *(undefined4 *)(iVar2 + 0xd8),*param_1,puVar26,uVar21,puVar27,uVar6);
            _applog(6,local_828,0);
          }
          while (iVar2 = piVar3[0xb], tVar4 = time((time_t *)0x0), tVar4 <= iVar2 + 0x77) {
            sVar7 = strlen(acStack_c28);
            iVar2 = stratum_send(param_1,acStack_c28,sVar7);
            if (iVar2 != 0) {
              iVar2 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
              piVar17 = stratum_shares;
              if (iVar2 == 0) {
                piVar3[6] = 4;
                uVar16 = *(byte *)(piVar3 + 10) + 0x112410d +
                         (uint)*(byte *)((int)piVar3 + 0x2b) * 0x1000000 +
                         (uint)*(byte *)((int)piVar3 + 0x2a) * 0x10000 +
                         (uint)*(byte *)((int)piVar3 + 0x29) * 0x100 ^ 0x7f76d;
                piVar3[5] = (int)(piVar3 + 10);
                uVar10 = 0x9f49bac6 - uVar16 ^ uVar16 << 8;
                uVar6 = (-0x112410d - uVar16) - uVar10 ^ uVar10 >> 0xd;
                uVar16 = (uVar16 - uVar10) - uVar6 ^ uVar6 >> 0xc;
                uVar10 = (uVar10 - uVar6) - uVar16 ^ uVar16 << 0x10;
                uVar6 = (uVar6 - uVar16) - uVar10 ^ uVar10 >> 5;
                uVar16 = (uVar16 - uVar10) - uVar6 ^ uVar6 >> 3;
                uVar10 = (uVar10 - uVar6) - uVar16 ^ uVar16 << 10;
                uVar6 = (uVar6 - uVar16) - uVar10 ^ uVar10 >> 0xf;
                piVar3[7] = uVar6;
                if (piVar17 == (int *)0x0) {
                  piVar3[2] = 0;
                  piVar3[1] = 0;
                  stratum_shares = piVar3;
                  pvVar8 = malloc(0x2c);
                  *piVar3 = (int)pvVar8;
                  if (pvVar8 == (void *)0x0) goto LAB_00024b5a;
                  memset(pvVar8,0,0x2c);
                  puVar23 = (undefined4 *)*piVar3;
                  puVar23[4] = piVar3;
                  puVar23[5] = 0;
                  puVar23[1] = 0x20;
                  puVar23[2] = 5;
                  pvVar8 = malloc(0x180);
                  *puVar23 = pvVar8;
                  if (pvVar8 == (void *)0x0) goto LAB_00024b5a;
                  memset(pvVar8,0,0x180);
                  piVar17 = (int *)*piVar3;
                  piVar17[10] = -0x5feee01f;
                }
                else {
                  *piVar3 = *piVar17;
                  piVar17 = (int *)*piVar17;
                  piVar3[2] = 0;
                  iVar2 = piVar17[4];
                  piVar3[1] = iVar2 - piVar17[5];
                  *(int **)(iVar2 + 8) = piVar3;
                  piVar17[4] = (int)piVar3;
                }
                iVar2 = *piVar17;
                uVar6 = uVar6 & piVar17[1] - 1U;
                piVar17[3] = piVar17[3] + 1;
                iVar11 = iVar2 + uVar6 * 0xc;
                iVar5 = *(int *)(iVar2 + uVar6 * 0xc);
                uVar10 = *(int *)(iVar11 + 4) + 1;
                *(uint *)(iVar11 + 4) = uVar10;
                piVar3[4] = iVar5;
                piVar3[3] = 0;
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0xc) = piVar3;
                }
                iVar5 = *(int *)(iVar11 + 8);
                *(int **)(iVar2 + uVar6 * 0xc) = piVar3;
                if (((uint)((iVar5 + 1) * 10) <= uVar10) && (*(int *)(*piVar3 + 0x24) != 1)) {
                  pvVar8 = calloc(*(int *)(*piVar3 + 4) * 0x18,1);
                  if (pvVar8 == (void *)0x0) {
LAB_00024b5a:
                    /* WARNING: Subroutine does not return */
                    exit(-1);
                  }
                  piVar17 = (int *)*piVar3;
                  iVar2 = piVar17[1];
                  piVar17[7] = 0;
                  uVar6 = (uint)piVar17[3] >> (piVar17[2] + 1U & 0xff);
                  uVar10 = iVar2 * 2 - 1;
                  if ((piVar17[3] & uVar10) != 0) {
                    uVar6 = uVar6 + 1;
                  }
                  piVar17[6] = uVar6;
                  if (iVar2 == 0) {
                    local_ca4 = (void *)*piVar17;
                  }
                  else {
                    local_ca4 = (void *)*piVar17;
                    local_ca8 = 0;
                    do {
                      iVar5 = *(int *)((int)local_ca4 + local_ca8);
                      while (iVar5 != 0) {
                        iVar11 = *(int *)(iVar5 + 0x10);
                        uVar22 = uVar10 & *(uint *)(iVar5 + 0x1c);
                        uVar16 = *(int *)((int)pvVar8 + uVar22 * 0xc + 4) + 1;
                        *(uint *)((int)pvVar8 + uVar22 * 0xc + 4) = uVar16;
                        if (uVar6 < uVar16) {
                          piVar17[7] = piVar17[7] + 1;
                          uVar21 = __udivsi3(uVar16,uVar6);
                          *(undefined4 *)((int)pvVar8 + uVar22 * 0xc + 8) = uVar21;
                        }
                        iVar18 = *(int *)((int)pvVar8 + uVar22 * 0xc);
                        *(undefined4 *)(iVar5 + 0xc) = 0;
                        *(int *)(iVar5 + 0x10) = iVar18;
                        if (iVar18 != 0) {
                          *(int *)(iVar18 + 0xc) = iVar5;
                        }
                        *(int *)((int)pvVar8 + uVar22 * 0xc) = iVar5;
                        iVar5 = iVar11;
                      }
                      local_ca8 = local_ca8 + 0xc;
                    } while (iVar2 * 0xc != local_ca8);
                  }
                  free(local_ca4);
                  puVar23 = (undefined4 *)*piVar3;
                  *puVar23 = pvVar8;
                  iVar2 = puVar23[2] + 1;
                  puVar23[2] = iVar2;
                  if ((uint)puVar23[7] <= (uint)puVar23[3] >> 1) {
                    iVar2 = 0;
                  }
                  puVar23[1] = puVar23[1] << 1;
                  if ((uint)puVar23[3] >> 1 < (uint)puVar23[7]) {
                    uVar10 = puVar23[8] + 1;
                    puVar23[8] = uVar10;
                    uVar6 = uVar10;
                    if (1 < uVar10) {
                      uVar6 = 1;
                    }
                    if (1 < uVar10) {
                      puVar23[9] = uVar6;
                    }
                  }
                  else {
                    puVar23[8] = iVar2;
                  }
                }
                param_1[0xb7] = param_1[0xb7] + 1;
                iVar2 = pthread_mutex_unlock((pthread_mutex_t *)sshare_lock);
                if (iVar2 != 0) {
                  piVar3 = __errno_location();
                  uVar21 = 0x1dd7;
                  iVar2 = *piVar3;
                  goto LAB_0002482e;
                }
                (*selective_yield)();
                iVar2 = pool_tclear(param_1,param_1 + 0x18);
                if (iVar2 == 0) {
LAB_00024640:
                  if (opt_debug != 0) {
                    if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000246fc;
LAB_00024662:
                    builtin_strncpy(local_828,"Successfully submitted, adding to stratu",0x28);
                    uStack_800._0_1_ = 'm';
                    uStack_800._1_1_ = '_';
                    uStack_800._2_1_ = 's';
                    uStack_800._3_1_ = 'h';
                    builtin_strncpy(acStack_7fc,"ares",4);
                    local_7f8._0_1_ = ' ';
                    local_7f8._1_1_ = 'd';
                    local_7f8._2_1_ = 'b';
                    local_7f8._3_1_ = '\0';
                    _applog(7,local_828,0);
                  }
                }
                else {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
                    snprintf(local_828,0x800,"Pool %d communication resumed, submitting work",
                             *param_1);
                    _applog(4,local_828,0);
                    goto LAB_00024640;
                  }
                  if (opt_debug != 0) {
LAB_000246fc:
                    if (6 < opt_log_level) goto LAB_00024662;
                  }
                }
                tVar4 = time((time_t *)0x0);
                bVar14 = opt_debug;
                piVar3[0xc] = tVar4;
                if (0 < tVar4 - piVar3[0xb]) {
                  bVar14 = bVar14 | 1;
                }
                if ((bVar14 != 0) &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
                  snprintf(local_828,0x800,"Pool %d stratum share submission lag time %d seconds",
                           *param_1,tVar4 - piVar3[0xb]);
                  _applog(6,local_828,0);
                }
                goto LAB_000245fc;
              }
              piVar3 = __errno_location();
              uVar21 = 0x1dd4;
              iVar2 = *piVar3;
              goto LAB_000247ea;
            }
            iVar2 = pool_tset(param_1,param_1 + 0x18);
            if ((iVar2 == 0) && (iVar2 = cnx_needed(param_1), iVar2 != 0)) {
              if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
                snprintf(local_828,0x800,"Pool %d stratum share submission failure",*param_1);
                _applog(4,local_828,0);
              }
              total_ro = total_ro + 1;
              param_1[0x21] = param_1[0x21] + 1;
            }
            if (opt_lowmem != '\0') {
              if (opt_debug == 0) goto LAB_00024a24;
              if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
              goto LAB_000249e4;
              builtin_strncpy(local_828,"Lowmem option prevents resubmitting stra",0x28);
              uStack_800._0_1_ = 't';
              uStack_800._1_1_ = 'u';
              uStack_800._2_1_ = 'm';
              uStack_800._3_1_ = ' ';
              builtin_strncpy(acStack_7fc,"shar",4);
              local_7f8._0_2_ = 0x65;
              _applog(7,local_828,0);
              break;
            }
            iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
            if (iVar2 != 0) {
              piVar3 = __errno_location();
              uVar21 = 0x1ded;
              iVar2 = *piVar3;
              goto LAB_000247ea;
            }
            __rwlock = (pthread_rwlock_t *)(param_1 + 0x3b);
            iVar2 = pthread_rwlock_rdlock(__rwlock);
            if (iVar2 != 0) {
              piVar3 = __errno_location();
              iVar2 = *piVar3;
              pcVar13 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
              uVar21 = 0x1ded;
              goto LAB_00024800;
            }
            iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
            if (iVar2 != 0) {
              piVar3 = __errno_location();
              uVar21 = 0x1ded;
              iVar2 = *piVar3;
              goto LAB_0002482e;
            }
            if (((char *)param_1[0x99] == (char *)0x0) ||
               (iVar2 = strcmp(*(char **)(local_c68 + 0x140),(char *)param_1[0x99]), iVar2 != 0)) {
              iVar2 = pthread_rwlock_unlock(__rwlock);
              if (iVar2 != 0) {
LAB_000248cc:
                piVar3 = __errno_location();
                iVar2 = *piVar3;
                pcVar13 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
                uVar21 = 0x1def;
                goto LAB_00024800;
              }
              (*selective_yield)();
              if (opt_debug == 0) goto LAB_00024a24;
              if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
              goto LAB_000249e4;
              builtin_strncpy(local_828,"No matching session id for resubmitting ",0x28);
              uStack_800._0_1_ = 's';
              uStack_800._1_1_ = 't';
              uStack_800._2_1_ = 'r';
              uStack_800._3_1_ = 'a';
              builtin_strncpy(acStack_7fc,"tum ",4);
              local_7f8._0_1_ = 's';
              local_7f8._1_1_ = 'h';
              local_7f8._2_1_ = 'a';
              local_7f8._3_1_ = 'r';
              local_7f4 = 0x65;
              _applog(7,local_828,0);
              break;
            }
            iVar2 = pthread_rwlock_unlock(__rwlock);
            if (iVar2 != 0) goto LAB_000248cc;
            (*selective_yield)();
            sleep(2);
          }
          if (opt_debug != 0) {
            if (use_syslog == '\0') {
LAB_000249e4:
              if ((opt_log_output == '\0') && (opt_log_level < 7)) goto LAB_00024a24;
            }
            builtin_strncpy(local_828,"Failed to submit stratum share, discardi",0x28);
            uStack_800._0_3_ = 0x676e;
            _applog(7,local_828,0);
          }
LAB_00024a24:
          _free_work(&local_c68,"cgminer.c","stratum_sthread",0x1dfe);
          free(piVar3);
          bVar25 = 0xfffffffe < (uint)total_stale;
          total_stale._0_4_ = (uint)total_stale + 1;
          total_stale._4_4_ = total_stale._4_4_ + (uint)bVar25;
          param_1[0x1e] = param_1[0x1e] + 1;
        }
      }
      else {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
LAB_000247d2:
          if (2 < opt_log_level) goto LAB_00024790;
        }
        else {
          snprintf(local_828,0x800,"Pool %d asking for inappropriately long nonce2 length %d",
                   *param_1,*(uint *)(local_c68 + 0x130));
          _applog(3,local_828,0);
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000247d2;
LAB_00024790:
          builtin_strncpy(local_828,"Not attempting to submit shares",0x20);
          _applog(3,local_828,0);
        }
        _free_work(&local_c68,"cgminer.c","stratum_sthread",0x1d8d);
        iVar9 = iVar11;
        iVar15 = iVar5;
        iVar20 = iVar18;
      }
LAB_000245fc:
      iVar2 = param_1[0xb6];
      cVar1 = *(char *)((int)param_1 + 0x69);
      iVar5 = iVar15;
      iVar11 = iVar9;
      iVar18 = iVar20;
    }
    pcVar13 = local_828;
    pcVar24 = "Stratum q returned empty work";
    local_c68 = 0;
  }
  uVar21 = *(undefined4 *)(pcVar24 + 4);
  uVar12 = *(undefined4 *)(pcVar24 + 8);
  uVar19 = *(undefined4 *)(pcVar24 + 0xc);
  *(undefined4 *)pcVar13 = *(undefined4 *)pcVar24;
  *(undefined4 *)(pcVar13 + 4) = uVar21;
  *(undefined4 *)(pcVar13 + 8) = uVar12;
  *(undefined4 *)(pcVar13 + 0xc) = uVar19;
  uVar21 = *(undefined4 *)(pcVar24 + 0x14);
  uVar12 = *(undefined4 *)(pcVar24 + 0x18);
  uVar19 = *(undefined4 *)(pcVar24 + 0x1c);
  *(undefined4 *)(pcVar13 + 0x10) = *(undefined4 *)(pcVar24 + 0x10);
  *(undefined4 *)(pcVar13 + 0x14) = uVar21;
  *(undefined4 *)(pcVar13 + 0x18) = uVar12;
  *(short *)(pcVar13 + 0x1c) = (short)uVar19;
  _applog(3,local_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

