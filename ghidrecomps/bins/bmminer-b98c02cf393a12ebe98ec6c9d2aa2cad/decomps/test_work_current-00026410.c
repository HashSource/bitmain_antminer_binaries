
/* WARNING: Restarted to delay deadcode elimination for space: ram */

char test_work_current(int param_1)

{
  byte bVar1;
  size_t __n;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  void *pvVar5;
  undefined4 uVar6;
  tm *ptVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 extraout_r1;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  uint uVar19;
  char *pcVar20;
  undefined *puVar21;
  char cVar22;
  int iVar23;
  undefined4 *puVar24;
  byte *pbVar25;
  char *pcVar26;
  byte *pbVar27;
  int iVar28;
  int iVar29;
  byte *pbVar30;
  undefined8 *puVar31;
  byte *pbVar32;
  size_t sVar33;
  undefined4 extraout_s0;
  DFtype extraout_d0;
  DFtype extraout_d0_00;
  undefined4 extraout_s1;
  DFtype extraout_d0_01;
  double dVar35;
  UDItype UVar36;
  int local_8ac;
  int local_8a8;
  void *local_8a4;
  int local_898;
  undefined4 local_894;
  undefined4 local_890;
  undefined4 local_88c;
  undefined4 local_888;
  undefined4 local_884;
  undefined4 local_880;
  undefined4 local_87c;
  undefined4 local_878;
  byte abStack_874 [12];
  byte local_868 [56];
  time_t local_830;
  char acStack_82c [12];
  uint local_820;
  char acStack_81c [8];
  undefined4 local_814;
  char local_810 [20];
  undefined2 uStack_7fc;
  undefined1 local_7fa;
  DFtype DVar34;
  
  puVar15 = *(undefined4 **)(param_1 + 0x104);
  iVar23 = puVar15[0x188];
  local_898 = 0;
  bVar1 = *(byte *)(iVar23 + 0x2a);
  if (*(char *)(param_1 + 0x11a) != '\0') {
    return '\x01';
  }
  local_894 = *(undefined4 *)(param_1 + 0x20);
  local_88c = *(undefined4 *)(param_1 + 0x18);
  local_888 = *(undefined4 *)(param_1 + 0x14);
  local_890 = *(undefined4 *)(param_1 + 0x1c);
  local_884 = *(undefined4 *)(param_1 + 0x10);
  local_880 = *(undefined4 *)(param_1 + 0xc);
  local_87c = *(undefined4 *)(param_1 + 8);
  local_878 = *(undefined4 *)(param_1 + 4);
  __bin2hex(abStack_874,&local_894,0x20);
  if (bVar1 < 5) {
    _cg_memcpy(&local_898,iVar23 + 0x2b,bVar1,"cgminer.c","test_work_current",0x15c0);
    local_898 = local_898 + -1;
  }
  iVar23 = pthread_mutex_lock((pthread_mutex_t *)(puVar15 + 0x35));
  if (iVar23 == 0) {
    iVar23 = pthread_rwlock_wrlock((pthread_rwlock_t *)(puVar15 + 0x3b));
    if (iVar23 == 0) {
      if (*(char *)(puVar15 + 0xaa) != '\0') {
        *(undefined1 *)(puVar15 + 0xaa) = 0;
        *(undefined1 *)(param_1 + 0x118) = 1;
      }
      iVar23 = pthread_rwlock_unlock((pthread_rwlock_t *)(puVar15 + 0x3b));
      if (iVar23 == 0) {
        iVar23 = pthread_mutex_unlock((pthread_mutex_t *)(puVar15 + 0x35));
        if (iVar23 == 0) {
          (*selective_yield)();
          iVar23 = pthread_rwlock_wrlock((pthread_rwlock_t *)blk_lock);
          if (iVar23 != 0) {
            piVar8 = __errno_location();
            pcVar26 = "block_exists";
            iVar23 = *piVar8;
            uVar6 = 0x1576;
            goto LAB_0002718c;
          }
          __n = strlen((char *)abStack_874);
          uVar16 = 0x9e3779b9;
          uVar2 = 0xfeedbeef;
          sVar33 = __n;
          if (__n < 0xc) {
            pbVar3 = abStack_874;
            uVar12 = uVar16;
          }
          else {
            uVar12 = uVar16;
            pbVar32 = local_868;
            do {
              pbVar3 = pbVar32;
              sVar33 = sVar33 - 0xc;
              iVar23 = uVar16 + (uint)pbVar3[-6] * 0x10000 + (uint)pbVar3[-7] * 0x100 +
                                (uint)pbVar3[-8] + (uint)pbVar3[-5] * 0x1000000;
              uVar2 = (uint)pbVar3[-2] * 0x10000 + (uint)pbVar3[-3] * 0x100 + (uint)pbVar3[-4] +
                      (uint)pbVar3[-1] * 0x1000000 + uVar2;
              uVar12 = ((((uint)pbVar3[-0xc] +
                          (uint)pbVar3[-10] * 0x10000 + (uint)pbVar3[-0xb] * 0x100 +
                         (uint)pbVar3[-9] * 0x1000000) - iVar23) - uVar2) + uVar12 ^ uVar2 >> 0xd;
              uVar16 = (iVar23 - uVar2) - uVar12 ^ uVar12 << 8;
              uVar17 = (uVar2 - uVar12) - uVar16 ^ uVar16 >> 0xd;
              uVar12 = (uVar12 - uVar16) - uVar17 ^ uVar17 >> 0xc;
              uVar2 = (uVar16 - uVar17) - uVar12 ^ uVar12 << 0x10;
              uVar17 = (uVar17 - uVar12) - uVar2 ^ uVar2 >> 5;
              uVar12 = (uVar12 - uVar2) - uVar17 ^ uVar17 >> 3;
              uVar16 = (uVar2 - uVar17) - uVar12 ^ uVar12 << 10;
              uVar2 = (uVar17 - uVar12) - uVar16 ^ uVar16 >> 0xf;
              pbVar32 = pbVar3 + 0xc;
            } while (0xb < sVar33);
          }
          uVar2 = uVar2 + __n;
          switch(sVar33) {
          case 0xb:
            uVar2 = uVar2 + (uint)pbVar3[10] * 0x1000000;
          case 10:
            uVar2 = uVar2 + (uint)pbVar3[9] * 0x10000;
          case 9:
            uVar2 = uVar2 + (uint)pbVar3[8] * 0x100;
          case 8:
            uVar16 = uVar16 + (uint)pbVar3[7] * 0x1000000;
          case 7:
            uVar16 = uVar16 + (uint)pbVar3[6] * 0x10000;
          case 6:
            uVar16 = uVar16 + (uint)pbVar3[5] * 0x100;
          case 5:
            uVar16 = uVar16 + pbVar3[4];
          case 4:
            uVar12 = uVar12 + (uint)pbVar3[3] * 0x1000000;
          case 3:
            uVar12 = uVar12 + (uint)pbVar3[2] * 0x10000;
          case 2:
            uVar12 = uVar12 + (uint)pbVar3[1] * 0x100;
          case 1:
            uVar12 = uVar12 + *pbVar3;
          }
          uVar12 = (uVar12 - uVar16) - uVar2 ^ uVar2 >> 0xd;
          uVar16 = (uVar16 - uVar2) - uVar12 ^ uVar12 << 8;
          uVar2 = (uVar2 - uVar12) - uVar16 ^ uVar16 >> 0xd;
          uVar12 = (uVar12 - uVar16) - uVar2 ^ uVar2 >> 0xc;
          uVar16 = (uVar16 - uVar2) - uVar12 ^ uVar12 << 0x10;
          uVar2 = (uVar2 - uVar12) - uVar16 ^ uVar16 >> 5;
          uVar12 = (uVar12 - uVar16) - uVar2 ^ uVar2 >> 3;
          uVar16 = (uVar16 - uVar2) - uVar12 ^ uVar12 << 10;
          uVar2 = (uVar2 - uVar12) - uVar16 ^ uVar16 >> 0xf;
          if (blocks != (byte *)0x0) {
            piVar8 = *(int **)(blocks + 0x44);
            iVar23 = *(int *)(*piVar8 + (piVar8[1] - 1U & uVar2) * 0xc);
            if (iVar23 != 0) {
              iVar29 = piVar8[5];
              do {
                iVar23 = iVar23 - iVar29;
                if (iVar23 == 0) break;
                if (((uVar2 == *(uint *)(iVar23 + 0x60)) && (__n == *(size_t *)(iVar23 + 0x5c))) &&
                   (iVar10 = memcmp(*(void **)(iVar23 + 0x58),abStack_874,__n), iVar10 == 0)) {
                  iVar23 = pthread_rwlock_unlock((pthread_rwlock_t *)blk_lock);
                  if (iVar23 != 0) goto LAB_00027202;
                  (*selective_yield)();
                  iVar23 = memcmp(puVar15 + 0x88,&local_894,0x20);
                  if (iVar23 == 0) {
                    cVar22 = '\x01';
                  }
                  else {
                    iVar23 = memcmp(&local_894,current_block,0x20);
                    if (iVar23 == 0) {
                      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level))
                      {
                        snprintf((char *)&local_830,0x800,"Pool %d now up to date at height %d",
                                 *puVar15,local_898);
                        _applog(6,&local_830,0);
                      }
                      cVar22 = '\x01';
                      _cg_memcpy(puVar15 + 0x88,&local_894,0x20,"cgminer.c","test_work_current",
                                 0x1607);
                    }
                    else {
                      cVar22 = opt_debug;
                      if (opt_debug != '\0') {
                        if (((use_syslog == '\0') && (opt_log_output == '\0')) &&
                           (opt_log_level < 7)) {
                          cVar22 = '\0';
                        }
                        else {
                          cVar22 = '\0';
                          snprintf((char *)&local_830,0x800,"Stale data from pool %d at height %d",
                                   *puVar15,local_898);
                          _applog(7,&local_830,0);
                        }
                      }
                    }
                  }
                  if (*(char *)(param_1 + 0x118) != '\0') {
                    uVar2 = pool_strategy - 3;
                    work_block = work_block + 1;
                    *(int *)(param_1 + 0x150) = work_block;
                    if ((uVar2 < 2) ||
                       (iVar29 = *(int *)(param_1 + 0x104), iVar23 = current_pool(),
                       iVar29 == iVar23)) {
                      if (*(char *)(param_1 + 0x11c) == '\0') {
                        if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                           (4 < opt_log_level)) {
                          puVar21 = &DAT_000609ec;
                          if (*(char *)(param_1 + 0x144) != '\0') {
                            puVar21 = &DAT_0005dff8;
                          }
                          snprintf((char *)&local_830,0x800,
                                   "%sLONGPOLL from pool %d requested work restart",puVar21,
                                   **(undefined4 **)(param_1 + 0x104));
                          _applog(5,&local_830,0);
                        }
                      }
                      else if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                              (4 < opt_log_level)) {
                        snprintf((char *)&local_830,0x800,
                                 "Stratum from pool %d requested work restart",*puVar15);
                        _applog(5,&local_830,0);
                      }
                      restart_threads();
                    }
                  }
                  goto LAB_0002695e;
                }
                iVar23 = *(int *)(iVar23 + 0x54);
              } while (iVar23 != 0);
            }
          }
          pbVar3 = (byte *)_cgcalloc(0x68,1,"cgminer.c","block_exists",0x157a);
          if (pbVar3 == (byte *)0x0) {
            local_830._0_1_ = 'b';
            local_830._1_1_ = 'l';
            local_830._2_1_ = 'o';
            local_830._3_1_ = 'c';
            builtin_strncpy(acStack_82c,"k_exists OOM",0xc);
            local_820 = local_820 & 0xffffff00;
            _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
            __quit(1);
          }
          strcpy((char *)pbVar3,(char *)abStack_874);
          pbVar32 = blocks;
          iVar23 = new_blocks + 1;
          *(int *)(pbVar3 + 100) = new_blocks;
          new_blocks = iVar23;
          if (pbVar32 == (byte *)0x0) {
            local_8a8 = 0;
          }
          else {
            iVar23 = *(int *)(pbVar32 + 0x44);
            if (*(uint *)(iVar23 + 0xc) < 4) {
              local_8a8 = 0;
            }
            else {
              iVar29 = *(int *)(iVar23 + 0x14);
              pbVar32 = pbVar32 + 0x44;
              pbVar27 = (byte *)0x1;
              do {
                pbVar13 = (byte *)0x0;
                uVar2 = 0;
                pbVar30 = pbVar32;
                pbVar32 = (byte *)0x0;
                do {
                  uVar2 = uVar2 + 1;
                  pbVar25 = pbVar27;
                  if (pbVar27 == (byte *)0x0) {
                    pbVar4 = (byte *)0x0;
                    pbVar9 = pbVar30;
                  }
                  else {
                    pbVar9 = *(byte **)(pbVar30 + 8);
                    for (pbVar4 = (byte *)0x1;
                        ((pbVar9 != (byte *)0x0 && (pbVar9 = pbVar9 + iVar29, pbVar9 != (byte *)0x0)
                         ) && (pbVar4 != pbVar27)); pbVar4 = pbVar4 + 1) {
                      pbVar9 = *(byte **)(pbVar9 + 8);
                    }
                  }
LAB_0002677a:
                  pbVar14 = pbVar13;
                  pbVar18 = pbVar9;
                  if (pbVar4 != (byte *)0x0) goto LAB_000267aa;
LAB_0002677c:
                  if (pbVar25 != (byte *)0x0 && pbVar9 != (byte *)0x0) {
                    iVar10 = *(int *)(pbVar9 + 8);
                    pbVar11 = pbVar4;
                    pbVar14 = pbVar13;
                    pbVar18 = pbVar9;
                    pbVar13 = pbVar30;
                    if (iVar10 == 0) goto LAB_00026790;
LAB_0002678e:
                    pbVar11 = (byte *)(iVar10 + iVar29);
                    pbVar30 = pbVar13;
LAB_00026790:
                    pbVar25 = pbVar25 + -1;
                    pbVar9 = pbVar11;
                    pbVar13 = pbVar18;
                    if (pbVar14 == (byte *)0x0) goto LAB_000267d8;
LAB_00026794:
                    pbVar13 = pbVar18;
                    *(int *)(pbVar14 + 8) = (int)pbVar13 - iVar29;
                    if (pbVar13 != (byte *)0x0) {
                      iVar10 = (int)pbVar14 - iVar29;
                      do {
                        *(int *)(pbVar13 + 4) = iVar10;
                        pbVar14 = pbVar13;
                        pbVar18 = pbVar9;
                        if (pbVar4 == (byte *)0x0) goto LAB_0002677c;
LAB_000267aa:
                        pbVar13 = pbVar30;
                        pbVar30 = pbVar13;
                        if ((pbVar18 == (byte *)0x0 || pbVar25 == (byte *)0x0) ||
                           (*(int *)(pbVar13 + -iVar29 + 100) - *(int *)(pbVar18 + -iVar29 + 100) <
                            1)) {
                          if ((pbVar13 != (byte *)0x0) &&
                             (pbVar30 = (byte *)(*(int *)(pbVar13 + 8) + iVar29),
                             *(int *)(pbVar13 + 8) == 0)) {
                            pbVar30 = (byte *)0x0;
                          }
                          pbVar4 = pbVar4 + -1;
                          pbVar9 = pbVar18;
                          if (pbVar14 != (byte *)0x0) goto code_r0x00026a1e;
                        }
                        else {
                          iVar10 = *(int *)(pbVar18 + 8);
                          if (iVar10 != 0) goto LAB_0002678e;
                          pbVar25 = pbVar25 + -1;
                          pbVar9 = (byte *)0x0;
                          pbVar13 = pbVar18;
                          if (pbVar14 != (byte *)0x0) goto LAB_00026794;
                        }
LAB_000267d8:
                        iVar10 = 0;
                        pbVar32 = pbVar13;
                        if (pbVar13 == (byte *)0x0) break;
                      } while( true );
                    }
                    goto LAB_0002677a;
                  }
                  pbVar30 = pbVar9;
                } while (pbVar9 != (byte *)0x0);
                if (pbVar13 != (byte *)0x0) {
                  pbVar13[8] = 0;
                  pbVar13[9] = 0;
                  pbVar13[10] = 0;
                  pbVar13[0xb] = 0;
                }
              } while ((1 < uVar2) &&
                      (pbVar27 = (byte *)((int)pbVar27 << 1), pbVar13 = pbVar32,
                      pbVar32 != (byte *)0x0));
              pbVar27 = pbVar32 + -iVar29;
              *(byte **)(iVar23 + 0x10) = pbVar13;
              iVar23 = *(int *)(pbVar27 + 0x48);
              local_8a8 = *(int *)(pbVar27 + 100);
              blocks = pbVar27;
              if (iVar23 == 0) {
                pbVar32 = *(byte **)(pbVar27 + 0x4c);
                if (pbVar32 != (byte *)0x0) {
                  iVar29 = *(int *)(pbVar27 + 0x44);
                  pbVar30 = pbVar32;
                  blocks = pbVar32;
                  if (pbVar27 == (byte *)(*(int *)(iVar29 + 0x10) - *(int *)(iVar29 + 0x14))) {
                    *(int *)(iVar29 + 0x10) = *(int *)(iVar29 + 0x14);
                  }
                  goto LAB_00026a9e;
                }
                free((void *)**(undefined4 **)(pbVar27 + 0x44));
                free(*(void **)(pbVar27 + 0x44));
                blocks = (byte *)0x0;
              }
              else {
                iVar10 = *(int *)(pbVar27 + 0x44);
                iVar29 = *(int *)(iVar10 + 0x14) + iVar23;
                if (pbVar27 == (byte *)(*(int *)(iVar10 + 0x10) - *(int *)(iVar10 + 0x14))) {
                  *(int *)(iVar10 + 0x10) = iVar29;
                }
                *(undefined4 *)(iVar29 + 8) = *(undefined4 *)(pbVar27 + 0x4c);
                pbVar32 = *(byte **)(pbVar27 + 0x4c);
                pbVar30 = pbVar27;
LAB_00026a9e:
                piVar8 = *(int **)(pbVar30 + 0x44);
                if (pbVar32 != (byte *)0x0) {
                  *(int *)(pbVar32 + piVar8[5] + 4) = iVar23;
                }
                iVar10 = *piVar8;
                iVar29 = (*(uint *)(pbVar27 + 0x60) & piVar8[1] - 1U) * 0xc;
                pbVar32 = *(byte **)(iVar10 + iVar29);
                *(int *)(iVar10 + iVar29 + 4) = *(int *)(iVar10 + iVar29 + 4) + -1;
                iVar23 = *(int *)(pbVar27 + 0x54);
                if (pbVar32 == pbVar27 + 0x44) {
                  *(int *)(iVar10 + iVar29) = iVar23;
                }
                iVar29 = *(int *)(pbVar27 + 0x50);
                if (iVar29 != 0) {
                  *(int *)(iVar29 + 0x10) = iVar23;
                  iVar23 = *(int *)(pbVar27 + 0x54);
                }
                if (iVar23 != 0) {
                  *(int *)(iVar23 + 0xc) = iVar29;
                }
                piVar8[3] = piVar8[3] + -1;
                pbVar32 = pbVar30;
              }
              free(pbVar27);
            }
          }
          uVar2 = 0xfeedbeef;
          sVar33 = strlen((char *)pbVar3);
          uVar16 = 0x9e3779b9;
          uVar12 = uVar16;
          pbVar27 = pbVar3;
          for (uVar17 = sVar33; 0xb < uVar17; uVar17 = uVar17 - 0xc) {
            iVar23 = uVar12 + (uint)pbVar27[6] * 0x10000 + (uint)pbVar27[5] * 0x100 +
                              (uint)pbVar27[4] + (uint)pbVar27[7] * 0x1000000;
            uVar2 = (uint)pbVar27[8] + (uint)pbVar27[10] * 0x10000 + (uint)pbVar27[9] * 0x100 +
                    (uint)pbVar27[0xb] * 0x1000000 + uVar2;
            uVar12 = ((((uint)*pbVar27 + (uint)pbVar27[2] * 0x10000 + (uint)pbVar27[1] * 0x100 +
                       (uint)pbVar27[3] * 0x1000000) - iVar23) - uVar2) + uVar16 ^ uVar2 >> 0xd;
            uVar16 = (iVar23 - uVar2) - uVar12 ^ uVar12 << 8;
            uVar19 = (uVar2 - uVar12) - uVar16 ^ uVar16 >> 0xd;
            uVar12 = (uVar12 - uVar16) - uVar19 ^ uVar19 >> 0xc;
            uVar2 = (uVar16 - uVar19) - uVar12 ^ uVar12 << 0x10;
            uVar19 = (uVar19 - uVar12) - uVar2 ^ uVar2 >> 5;
            uVar16 = (uVar12 - uVar2) - uVar19 ^ uVar19 >> 3;
            uVar12 = (uVar2 - uVar19) - uVar16 ^ uVar16 << 10;
            uVar2 = (uVar19 - uVar16) - uVar12 ^ uVar12 >> 0xf;
            pbVar27 = pbVar27 + 0xc;
          }
          uVar2 = sVar33 + uVar2;
          switch(uVar17) {
          case 0xb:
            uVar2 = uVar2 + (uint)pbVar27[10] * 0x1000000;
          case 10:
            uVar2 = uVar2 + (uint)pbVar27[9] * 0x10000;
          case 9:
            uVar2 = uVar2 + (uint)pbVar27[8] * 0x100;
          case 8:
            uVar12 = uVar12 + (uint)pbVar27[7] * 0x1000000;
          case 7:
            uVar12 = uVar12 + (uint)pbVar27[6] * 0x10000;
          case 6:
            uVar12 = uVar12 + (uint)pbVar27[5] * 0x100;
          case 5:
            uVar12 = uVar12 + pbVar27[4];
          case 4:
            uVar16 = uVar16 + (uint)pbVar27[3] * 0x1000000;
          case 3:
            uVar16 = uVar16 + (uint)pbVar27[2] * 0x10000;
          case 2:
            uVar16 = uVar16 + (uint)pbVar27[1] * 0x100;
          case 1:
            uVar16 = uVar16 + *pbVar27;
          }
          uVar16 = (uVar16 - uVar12) - uVar2 ^ uVar2 >> 0xd;
          *(byte **)(pbVar3 + 0x58) = pbVar3;
          uVar12 = (uVar12 - uVar2) - uVar16 ^ uVar16 << 8;
          uVar2 = (uVar2 - uVar16) - uVar12 ^ uVar12 >> 0xd;
          uVar16 = (uVar16 - uVar12) - uVar2 ^ uVar2 >> 0xc;
          uVar12 = (uVar12 - uVar2) - uVar16 ^ uVar16 << 0x10;
          uVar2 = (uVar2 - uVar16) - uVar12 ^ uVar12 >> 5;
          uVar16 = (uVar16 - uVar12) - uVar2 ^ uVar2 >> 3;
          uVar12 = (uVar12 - uVar2) - uVar16 ^ uVar16 << 10;
          uVar2 = (uVar2 - uVar16) - uVar12 ^ uVar12 >> 0xf;
          *(uint *)(pbVar3 + 0x60) = uVar2;
          sVar33 = strlen((char *)pbVar3);
          *(size_t *)(pbVar3 + 0x5c) = sVar33;
          if (pbVar32 == (byte *)0x0) {
            pbVar3[0x4c] = 0;
            pbVar3[0x4d] = 0;
            pbVar3[0x4e] = 0;
            pbVar3[0x4f] = 0;
            pbVar3[0x48] = 0;
            pbVar3[0x49] = 0;
            pbVar3[0x4a] = 0;
            pbVar3[0x4b] = 0;
            blocks = pbVar3;
            pvVar5 = malloc(0x2c);
            *(void **)(pbVar3 + 0x44) = pvVar5;
            if (pvVar5 == (void *)0x0) goto LAB_0002758a;
            memset(pvVar5,0,0x2c);
            puVar24 = *(undefined4 **)(pbVar3 + 0x44);
            puVar24[4] = pbVar3 + 0x44;
            puVar24[1] = 0x20;
            puVar24[2] = 5;
            puVar24[5] = 0x44;
            pvVar5 = malloc(0x180);
            *puVar24 = pvVar5;
            if (pvVar5 == (void *)0x0) goto LAB_0002758a;
            memset(pvVar5,0,0x180);
            piVar8 = *(int **)(pbVar3 + 0x44);
            piVar8[10] = -0x5feee01f;
            DVar34 = extraout_d0_01;
          }
          else {
            *(undefined4 *)(pbVar3 + 0x44) = *(undefined4 *)(pbVar32 + 0x44);
            piVar8 = *(int **)(pbVar32 + 0x44);
            pbVar3[0x4c] = 0;
            pbVar3[0x4d] = 0;
            pbVar3[0x4e] = 0;
            pbVar3[0x4f] = 0;
            iVar23 = piVar8[4];
            *(int *)(pbVar3 + 0x48) = iVar23 - piVar8[5];
            *(byte **)(iVar23 + 8) = pbVar3;
            piVar8[4] = (int)(pbVar3 + 0x44);
            DVar34 = extraout_d0;
          }
          iVar29 = *piVar8;
          piVar8[3] = piVar8[3] + 1;
          iVar23 = (uVar2 & piVar8[1] - 1U) * 0xc;
          iVar10 = iVar29 + iVar23;
          iVar28 = *(int *)(iVar29 + iVar23);
          uVar2 = *(int *)(iVar10 + 4) + 1;
          *(uint *)(iVar10 + 4) = uVar2;
          *(int *)(pbVar3 + 0x54) = iVar28;
          pbVar3[0x50] = 0;
          pbVar3[0x51] = 0;
          pbVar3[0x52] = 0;
          pbVar3[0x53] = 0;
          if (iVar28 != 0) {
            *(byte **)(iVar28 + 0xc) = pbVar3 + 0x44;
          }
          iVar10 = *(int *)(iVar10 + 8);
          *(byte **)(iVar29 + iVar23) = pbVar3 + 0x44;
          if (((uint)((iVar10 + 1) * 10) <= uVar2) &&
             (*(int *)(*(int *)(pbVar3 + 0x44) + 0x24) != 1)) {
            pvVar5 = calloc(*(int *)(*(int *)(pbVar3 + 0x44) + 4) * 0x18,1);
            if (pvVar5 == (void *)0x0) {
LAB_0002758a:
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            piVar8 = *(int **)(pbVar3 + 0x44);
            iVar23 = piVar8[1];
            piVar8[7] = 0;
            uVar2 = (uint)piVar8[3] >> (piVar8[2] + 1U & 0xff);
            uVar16 = iVar23 * 2 - 1;
            if ((piVar8[3] & uVar16) != 0) {
              uVar2 = uVar2 + 1;
            }
            piVar8[6] = uVar2;
            if (iVar23 == 0) {
              local_8a4 = (void *)*piVar8;
            }
            else {
              local_8a4 = (void *)*piVar8;
              local_8ac = 0;
              do {
                iVar29 = *(int *)((int)local_8a4 + local_8ac);
                while (iVar29 != 0) {
                  iVar10 = *(int *)(iVar29 + 0x10);
                  uVar17 = uVar16 & *(uint *)(iVar29 + 0x1c);
                  uVar12 = *(int *)((int)pvVar5 + uVar17 * 0xc + 4) + 1;
                  *(uint *)((int)pvVar5 + uVar17 * 0xc + 4) = uVar12;
                  if (uVar2 < uVar12) {
                    piVar8[7] = piVar8[7] + 1;
                    uVar6 = __udivsi3(uVar12,uVar2);
                    *(undefined4 *)((int)pvVar5 + uVar17 * 0xc + 8) = uVar6;
                  }
                  iVar28 = *(int *)((int)pvVar5 + uVar17 * 0xc);
                  *(undefined4 *)(iVar29 + 0xc) = 0;
                  *(int *)(iVar29 + 0x10) = iVar28;
                  if (iVar28 != 0) {
                    *(int *)(iVar28 + 0xc) = iVar29;
                  }
                  *(int *)((int)pvVar5 + uVar17 * 0xc) = iVar29;
                  iVar29 = iVar10;
                }
                local_8ac = local_8ac + 0xc;
              } while (local_8ac != iVar23 * 0xc);
            }
            free(local_8a4);
            puVar24 = *(undefined4 **)(pbVar3 + 0x44);
            *puVar24 = pvVar5;
            iVar23 = puVar24[2] + 1;
            puVar24[2] = iVar23;
            if ((uint)puVar24[7] <= (uint)puVar24[3] >> 1) {
              iVar23 = 0;
            }
            puVar24[1] = puVar24[1] << 1;
            DVar34 = extraout_d0_00;
            if ((uint)puVar24[3] >> 1 < (uint)puVar24[7]) {
              uVar16 = puVar24[8] + 1;
              puVar24[8] = uVar16;
              uVar2 = uVar16;
              if (1 < uVar16) {
                uVar2 = 1;
              }
              if (1 < uVar16) {
                puVar24[9] = uVar2;
              }
            }
            else {
              puVar24[8] = iVar23;
            }
          }
          iVar23 = 0x1d - (uint)*(byte *)(param_1 + 0x48);
          uVar2 = iVar23 * 8;
          if ((int)uVar2 < 8) {
            dVar35 = 16776960.0;
          }
          else {
            uVar6 = __floatundidf(0xffff << (uVar2 & 0xff),
                                  0xffff << (uVar2 - 0x20 & 0xff) |
                                  0xffffU >> (iVar23 * -8 + 0x20U & 0xff));
            DVar34 = (DFtype)CONCAT44(extraout_s1,extraout_s0);
            dVar35 = (double)CONCAT44(extraout_r1,uVar6);
          }
          uVar2 = *(uint *)(param_1 + 0x48);
          dVar35 = dVar35 / (double)(longlong)
                                    (int)((uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                         | uVar2 >> 0x18);
          if (dVar35 != current_diff) {
            UVar36 = __fixunsdfdi(DVar34);
            suffix_string((int)UVar36,(int)(UVar36 >> 0x20),&block_diff,8,0);
            current_diff = dVar35;
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
              snprintf((char *)&local_830,0x800,"Network diff set to %s",&block_diff);
              _applog(5,&local_830,0);
            }
          }
          if (((local_8a8 != 0) && (opt_debug != '\0')) &&
             ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
            snprintf((char *)&local_830,0x800,"Deleted block %d from database",local_8a8);
            _applog(7,&local_830,0);
          }
          iVar23 = pthread_rwlock_unlock((pthread_rwlock_t *)blk_lock);
          if (iVar23 == 0) {
            (*selective_yield)();
            iVar23 = pthread_mutex_lock((pthread_mutex_t *)ch_lock);
            if (iVar23 == 0) {
              iVar23 = pthread_rwlock_wrlock((pthread_rwlock_t *)(ch_lock + 0x18));
              if (iVar23 == 0) {
                cgtime(&block_timeval);
                strcpy(current_hash,(char *)abStack_874);
                _cg_memcpy(current_block,&local_894,0x20,"cgminer.c","set_curblock",0x1542);
                local_830 = (time_t)block_timeval;
                iVar23 = block_timeval._4_4_ / 1000;
                ptVar7 = localtime(&local_830);
                puVar31 = (undefined8 *)ptVar7->tm_min;
                snprintf(blocktime,0x20,"[%02d:%02d:%02d.%03d]",ptVar7->tm_hour,puVar31,
                         ptVar7->tm_sec,iVar23);
                iVar23 = pthread_rwlock_unlock((pthread_rwlock_t *)(ch_lock + 0x18));
                if (iVar23 == 0) {
                  iVar23 = pthread_mutex_unlock((pthread_mutex_t *)ch_lock);
                  if (iVar23 == 0) {
                    (*selective_yield)();
                    pcVar20 = (char *)((int)&total_tv_start_sys + 3);
                    iVar23 = 0;
                    do {
                      pcVar20 = pcVar20 + 1;
                      if (*pcVar20 != '0') break;
                      iVar23 = iVar23 + 1;
                    } while (iVar23 != 0x39);
                    strncpy(prev_block,current_hash + iVar23,8);
                    prev_block[8] = 0;
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                      puVar31 = &block_diff;
                      snprintf((char *)&local_830,0x800,"New block: %s... diff %s",current_hash,
                               &block_diff);
                      _applog(6,&local_830,0);
                    }
                    if (((local_8a8 != 0) && (opt_debug != '\0')) &&
                       ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level))))))
                    {
                      snprintf((char *)&local_830,0x800,"Deleted block %d from database",local_8a8,
                               puVar31);
                      _applog(7,&local_830,0);
                    }
                    _cg_memcpy(puVar15 + 0x88,&local_894,0x20,"cgminer.c","test_work_current",0x15d5
                              );
                    if (new_blocks == 1) {
                      cVar22 = '\0';
                      goto LAB_0002695e;
                    }
                    work_block = work_block + 1;
                    *(int *)(param_1 + 0x150) = work_block;
                    if (*(char *)(param_1 + 0x118) == '\0') {
                      if (have_longpoll == '\0') {
                        if ((*(char *)(puVar15 + 0xe1) == '\0') &&
                           (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)
                            ))) {
                          local_830._0_1_ = 'N';
                          local_830._1_1_ = 'e';
                          local_830._2_1_ = 'w';
                          local_830._3_1_ = ' ';
                          builtin_strncpy(acStack_82c,"block detect",0xc);
                          local_820._0_1_ = 'e';
                          local_820._1_1_ = 'd';
                          local_820._2_1_ = ' ';
                          local_820._3_1_ = 'o';
                          builtin_strncpy(acStack_81c,"n networ",8);
                          local_814._0_2_ = 0x6b;
                          _applog(5,&local_830,0);
                        }
                      }
                      else if ((*(char *)(puVar15 + 0xe1) == '\0') &&
                              (((use_syslog != '\0' || (opt_log_output != '\0')) ||
                               (4 < opt_log_level)))) {
                        local_830._0_1_ = 'N';
                        local_830._1_1_ = 'e';
                        local_830._2_1_ = 'w';
                        local_830._3_1_ = ' ';
                        builtin_strncpy(acStack_82c,"block detect",0xc);
                        local_820._0_1_ = 'e';
                        local_820._1_1_ = 'd';
                        local_820._2_1_ = ' ';
                        local_820._3_1_ = 'o';
                        builtin_strncpy(acStack_81c,"n networ",8);
                        local_814._0_1_ = 'k';
                        local_814._1_1_ = ' ';
                        local_814._2_1_ = 'b';
                        local_814._3_1_ = 'e';
                        builtin_strncpy(local_810,"fore pool notificati",0x14);
                        uStack_7fc = 0x6e6f;
                        local_7fa = 0;
                        _applog(5,&local_830,0);
                      }
                    }
                    else if (*(char *)(param_1 + 0x11c) == '\0') {
                      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level))
                      {
                        iVar23 = **(int **)(param_1 + 0x104);
                        puVar21 = &DAT_000609ec;
                        if (*(char *)(param_1 + 0x144) != '\0') {
                          puVar21 = &DAT_0005dff8;
                        }
                        pcVar20 = "%sLONGPOLL from pool %d detected new block";
                        goto LAB_000270ec;
                      }
                    }
                    else if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                            (4 < opt_log_level)) {
                      pcVar20 = "Stratum from pool %d detected new block at height %d";
                      puVar21 = (undefined *)*puVar15;
                      iVar23 = local_898;
LAB_000270ec:
                      snprintf((char *)&local_830,0x800,pcVar20,puVar21,iVar23);
                      _applog(5,&local_830,0);
                    }
                    restart_threads();
                    cVar22 = '\x01';
LAB_0002695e:
                    *(undefined1 *)(param_1 + 0x118) = 0;
                    return cVar22;
                  }
                  piVar8 = __errno_location();
                  pcVar20 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
                  iVar23 = *piVar8;
                }
                else {
                  piVar8 = __errno_location();
                  iVar23 = *piVar8;
                  pcVar20 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
                }
                snprintf((char *)&local_830,0x800,pcVar20,iVar23,"cgminer.c","set_curblock",0x1544);
                goto LAB_00027144;
              }
              piVar8 = __errno_location();
              iVar23 = *piVar8;
              pcVar26 = "set_curblock";
              uVar6 = 0x153f;
              pcVar20 = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
            }
            else {
              piVar8 = __errno_location();
              iVar23 = *piVar8;
              pcVar26 = "set_curblock";
              uVar6 = 0x153f;
              pcVar20 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
            }
          }
          else {
LAB_00027202:
            pcVar26 = "block_exists";
            piVar8 = __errno_location();
            iVar23 = *piVar8;
            uVar6 = 0x159c;
            pcVar20 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
          }
          snprintf((char *)&local_830,0x800,pcVar20,iVar23,"cgminer.c",pcVar26,uVar6);
          goto LAB_00027144;
        }
        piVar8 = __errno_location();
        iVar23 = *piVar8;
        pcVar20 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        pcVar26 = "test_work_current";
        uVar6 = 0x15cd;
      }
      else {
        piVar8 = __errno_location();
        iVar23 = *piVar8;
        pcVar20 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        pcVar26 = "test_work_current";
        uVar6 = 0x15cd;
      }
    }
    else {
      piVar8 = __errno_location();
      pcVar26 = "test_work_current";
      iVar23 = *piVar8;
      uVar6 = 0x15c5;
LAB_0002718c:
      pcVar20 = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
    }
  }
  else {
    piVar8 = __errno_location();
    iVar23 = *piVar8;
    pcVar20 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    pcVar26 = "test_work_current";
    uVar6 = 0x15c5;
  }
  snprintf((char *)&local_830,0x800,pcVar20,iVar23,"cgminer.c",pcVar26,uVar6);
LAB_00027144:
  _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
code_r0x00026a1e:
  pbVar18 = pbVar13;
  if (pbVar13 == (byte *)0x0) {
    pbVar14[8] = 0;
    pbVar14[9] = 0;
    pbVar14[10] = 0;
    pbVar14[0xb] = 0;
    goto LAB_0002677a;
  }
  goto LAB_00026794;
}

