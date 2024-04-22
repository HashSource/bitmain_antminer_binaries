
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

char test_work_current(int param_1)

{
  byte bVar1;
  double *pdVar2;
  size_t __n;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  void *pvVar6;
  void *pvVar7;
  undefined4 uVar8;
  tm *ptVar9;
  int *piVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  undefined4 *puVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  uint uVar21;
  void *pvVar22;
  char *pcVar23;
  undefined *puVar24;
  char cVar25;
  int iVar26;
  byte *pbVar27;
  byte *pbVar28;
  int iVar29;
  int iVar30;
  byte *pbVar31;
  byte *pbVar32;
  void *pvVar33;
  void **ppvVar34;
  size_t sVar35;
  double dVar36;
  UDItype UVar37;
  undefined4 uVar38;
  undefined4 in_stack_fffff72c;
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
  undefined4 local_830;
  undefined4 uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 local_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined2 uStack_7fc;
  undefined local_7fa;
  
  puVar17 = *(undefined4 **)(param_1 + 0x104);
  iVar26 = puVar17[0x188];
  local_898 = 0;
  bVar1 = *(byte *)(iVar26 + 0x2a);
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
    in_stack_fffff72c = 0x15c0;
    _cg_memcpy(&local_898,iVar26 + 0x2b,bVar1,"cgminer.c",DAT_00026a44);
    local_898 = local_898 + -1;
  }
  iVar26 = pthread_mutex_lock((pthread_mutex_t *)(puVar17 + 0x35));
  if (iVar26 == 0) {
    iVar26 = pthread_rwlock_wrlock((pthread_rwlock_t *)(puVar17 + 0x3b));
    if (iVar26 == 0) {
      if (*(char *)(puVar17 + 0xaa) != '\0') {
        *(undefined *)(puVar17 + 0xaa) = 0;
        *(undefined *)(param_1 + 0x118) = 1;
      }
      iVar26 = pthread_rwlock_unlock((pthread_rwlock_t *)(puVar17 + 0x3b));
      uVar38 = DAT_00027488;
      if (iVar26 == 0) {
        iVar26 = pthread_mutex_unlock((pthread_mutex_t *)(puVar17 + 0x35));
        uVar38 = DAT_00027488;
        if (iVar26 == 0) {
          (*selective_yield)();
          iVar26 = pthread_rwlock_wrlock(DAT_000267f0);
          if (iVar26 != 0) {
            piVar10 = __errno_location();
            iVar26 = *piVar10;
            uVar8 = 0x1576;
            uVar38 = DAT_0002748c;
            goto LAB_0002718c;
          }
          __n = strlen((char *)abStack_874);
          uVar18 = 0x9e3779b9;
          uVar3 = 0xfeedbeef;
          sVar35 = __n;
          if (__n < 0xc) {
            pbVar4 = abStack_874;
            uVar14 = uVar18;
          }
          else {
            uVar14 = uVar18;
            pbVar32 = local_868;
            do {
              pbVar4 = pbVar32;
              sVar35 = sVar35 - 0xc;
              iVar26 = uVar18 + (uint)pbVar4[-6] * 0x10000 + (uint)pbVar4[-7] * 0x100 +
                                (uint)pbVar4[-8] + (uint)pbVar4[-5] * 0x1000000;
              uVar3 = (uint)pbVar4[-2] * 0x10000 + (uint)pbVar4[-3] * 0x100 + (uint)pbVar4[-4] +
                      (uint)pbVar4[-1] * 0x1000000 + uVar3;
              uVar14 = ((((uint)pbVar4[-0xc] +
                          (uint)pbVar4[-10] * 0x10000 + (uint)pbVar4[-0xb] * 0x100 +
                         (uint)pbVar4[-9] * 0x1000000) - iVar26) - uVar3) + uVar14 ^ uVar3 >> 0xd;
              uVar18 = (iVar26 - uVar3) - uVar14 ^ uVar14 << 8;
              uVar19 = (uVar3 - uVar14) - uVar18 ^ uVar18 >> 0xd;
              uVar14 = (uVar14 - uVar18) - uVar19 ^ uVar19 >> 0xc;
              uVar3 = (uVar18 - uVar19) - uVar14 ^ uVar14 << 0x10;
              uVar19 = (uVar19 - uVar14) - uVar3 ^ uVar3 >> 5;
              uVar14 = (uVar14 - uVar3) - uVar19 ^ uVar19 >> 3;
              uVar18 = (uVar3 - uVar19) - uVar14 ^ uVar14 << 10;
              uVar3 = (uVar19 - uVar14) - uVar18 ^ uVar18 >> 0xf;
              pbVar32 = pbVar4 + 0xc;
            } while (0xb < sVar35);
          }
          uVar3 = uVar3 + __n;
          switch(sVar35) {
          case 0xb:
            uVar3 = uVar3 + (uint)pbVar4[10] * 0x1000000;
          case 10:
            uVar3 = uVar3 + (uint)pbVar4[9] * 0x10000;
          case 9:
            uVar3 = uVar3 + (uint)pbVar4[8] * 0x100;
          case 8:
            uVar18 = uVar18 + (uint)pbVar4[7] * 0x1000000;
          case 7:
            uVar18 = uVar18 + (uint)pbVar4[6] * 0x10000;
          case 6:
            uVar18 = uVar18 + (uint)pbVar4[5] * 0x100;
          case 5:
            uVar18 = uVar18 + pbVar4[4];
          case 4:
            uVar14 = uVar14 + (uint)pbVar4[3] * 0x1000000;
          case 3:
            uVar14 = uVar14 + (uint)pbVar4[2] * 0x10000;
          case 2:
            uVar14 = uVar14 + (uint)pbVar4[1] * 0x100;
          case 1:
            uVar14 = uVar14 + *pbVar4;
          }
          uVar14 = (uVar14 - uVar18) - uVar3 ^ uVar3 >> 0xd;
          uVar18 = (uVar18 - uVar3) - uVar14 ^ uVar14 << 8;
          uVar3 = (uVar3 - uVar14) - uVar18 ^ uVar18 >> 0xd;
          uVar14 = (uVar14 - uVar18) - uVar3 ^ uVar3 >> 0xc;
          uVar18 = (uVar18 - uVar3) - uVar14 ^ uVar14 << 0x10;
          uVar3 = (uVar3 - uVar14) - uVar18 ^ uVar18 >> 5;
          uVar14 = (uVar14 - uVar18) - uVar3 ^ uVar3 >> 3;
          uVar18 = (uVar18 - uVar3) - uVar14 ^ uVar14 << 10;
          uVar3 = (uVar3 - uVar14) - uVar18 ^ uVar18 >> 0xf;
          if (blocks != (byte *)0x0) {
            piVar10 = *(int **)(blocks + 0x44);
            iVar26 = *(int *)(*piVar10 + (piVar10[1] - 1U & uVar3) * 0xc);
            if (iVar26 != 0) {
              iVar30 = piVar10[5];
              do {
                iVar26 = iVar26 - iVar30;
                if (iVar26 == 0) break;
                if (((uVar3 == *(uint *)(iVar26 + 0x60)) && (__n == *(size_t *)(iVar26 + 0x5c))) &&
                   (iVar12 = memcmp(*(void **)(iVar26 + 0x58),abStack_874,__n), iVar12 == 0)) {
                  iVar26 = pthread_rwlock_unlock(DAT_00026a3c);
                  if (iVar26 != 0) goto LAB_00027202;
                  (*selective_yield)();
                  iVar26 = memcmp(puVar17 + 0x88,&local_894,0x20);
                  if (iVar26 == 0) {
                    cVar25 = '\x01';
                  }
                  else {
                    iVar26 = memcmp(&local_894,DAT_00026a40,0x20);
                    if (iVar26 == 0) {
                      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level))
                      {
                        snprintf((char *)&local_830,0x800,"Pool %d now up to date at height %d",
                                 *puVar17,local_898);
                        _applog(6,&local_830,0);
                      }
                      cVar25 = '\x01';
                      _cg_memcpy(puVar17 + 0x88,&local_894,0x20,"cgminer.c",DAT_00026a44,0x1607);
                    }
                    else {
                      cVar25 = opt_debug;
                      if (opt_debug != '\0') {
                        if (((use_syslog == '\0') && (opt_log_output == '\0')) &&
                           (opt_log_level < 7)) {
                          cVar25 = '\0';
                        }
                        else {
                          cVar25 = '\0';
                          snprintf((char *)&local_830,0x800,"Stale data from pool %d at height %d",
                                   *puVar17,local_898);
                          _applog(7,&local_830,0);
                        }
                      }
                    }
                  }
                  if (*(char *)(param_1 + 0x118) != '\0') {
                    uVar3 = pool_strategy - 3;
                    work_block = work_block + 1;
                    *(int *)(param_1 + 0x150) = work_block;
                    if ((uVar3 < 2) ||
                       (iVar30 = *(int *)(param_1 + 0x104), iVar26 = current_pool(),
                       iVar30 == iVar26)) {
                      if (*(char *)(param_1 + 0x11c) == '\0') {
                        if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                           (4 < opt_log_level)) {
                          puVar24 = &DAT_000609ec;
                          if (*(char *)(param_1 + 0x144) != '\0') {
                            puVar24 = &UNK_0005dff8;
                          }
                          snprintf((char *)&local_830,0x800,
                                   "%sLONGPOLL from pool %d requested work restart",puVar24,
                                   **(undefined4 **)(param_1 + 0x104));
                          _applog(5,&local_830,0);
                        }
                      }
                      else if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                              (4 < opt_log_level)) {
                        snprintf((char *)&local_830,0x800,
                                 "Stratum from pool %d requested work restart",*puVar17);
                        _applog(5,&local_830,0);
                      }
                      restart_threads();
                    }
                  }
                  goto LAB_0002695e;
                }
                iVar26 = *(int *)(iVar26 + 0x54);
              } while (iVar26 != 0);
            }
          }
          uVar38 = 0x157a;
          pbVar4 = (byte *)_cgcalloc(0x68,1,"cgminer.c",DAT_000267f4);
          if (pbVar4 == (byte *)0x0) {
            local_830._0_1_ = s_block_exists_OOM_0005e000[0];
            local_830._1_1_ = s_block_exists_OOM_0005e000[1];
            local_830._2_1_ = s_block_exists_OOM_0005e000[2];
            local_830._3_1_ = s_block_exists_OOM_0005e000[3];
            uStack_82c._0_1_ = s_block_exists_OOM_0005e000[4];
            uStack_82c._1_1_ = s_block_exists_OOM_0005e000[5];
            uStack_82c._2_1_ = s_block_exists_OOM_0005e000[6];
            uStack_82c._3_1_ = s_block_exists_OOM_0005e000[7];
            uStack_828._0_1_ = s_block_exists_OOM_0005e000[8];
            uStack_828._1_1_ = s_block_exists_OOM_0005e000[9];
            uStack_828._2_1_ = s_block_exists_OOM_0005e000[10];
            uStack_828._3_1_ = s_block_exists_OOM_0005e000[11];
            uStack_824._0_1_ = s_block_exists_OOM_0005e000[12];
            uStack_824._1_1_ = s_block_exists_OOM_0005e000[13];
            uStack_824._2_1_ = s_block_exists_OOM_0005e000[14];
            uStack_824._3_1_ = s_block_exists_OOM_0005e000[15];
            local_820 = CONCAT31(local_820._1_3_,(char)ram0x0005e010);
            _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
            __quit(1);
          }
          strcpy((char *)pbVar4,(char *)abStack_874);
          pbVar32 = blocks;
          iVar26 = new_blocks + 1;
          *(int *)(pbVar4 + 100) = new_blocks;
          new_blocks = iVar26;
          if (pbVar32 == (byte *)0x0) {
            local_8a8 = 0;
          }
          else {
            iVar26 = *(int *)(pbVar32 + 0x44);
            if (*(uint *)(iVar26 + 0xc) < 4) {
              local_8a8 = 0;
            }
            else {
              iVar30 = *(int *)(iVar26 + 0x14);
              pbVar32 = pbVar32 + 0x44;
              pbVar28 = (byte *)0x1;
              do {
                pbVar15 = (byte *)0x0;
                uVar3 = 0;
                pbVar31 = pbVar32;
                pbVar32 = (byte *)0x0;
                do {
                  uVar3 = uVar3 + 1;
                  pbVar27 = pbVar28;
                  if (pbVar28 == (byte *)0x0) {
                    pbVar5 = (byte *)0x0;
                    pbVar11 = pbVar31;
                  }
                  else {
                    pbVar11 = *(byte **)(pbVar31 + 8);
                    for (pbVar5 = (byte *)0x1;
                        ((pbVar11 != (byte *)0x0 &&
                         (pbVar11 = pbVar11 + iVar30, pbVar11 != (byte *)0x0)) &&
                        (pbVar5 != pbVar28)); pbVar5 = pbVar5 + 1) {
                      pbVar11 = *(byte **)(pbVar11 + 8);
                    }
                  }
LAB_0002677a:
                  pbVar16 = pbVar15;
                  pbVar20 = pbVar11;
                  if (pbVar5 != (byte *)0x0) goto LAB_000267aa;
LAB_0002677c:
                  if (pbVar27 != (byte *)0x0 && pbVar11 != (byte *)0x0) {
                    iVar12 = *(int *)(pbVar11 + 8);
                    pbVar13 = pbVar5;
                    pbVar16 = pbVar15;
                    pbVar20 = pbVar11;
                    pbVar15 = pbVar31;
                    if (iVar12 == 0) goto LAB_00026790;
LAB_0002678e:
                    pbVar13 = (byte *)(iVar12 + iVar30);
                    pbVar31 = pbVar15;
LAB_00026790:
                    pbVar27 = pbVar27 + -1;
                    pbVar11 = pbVar13;
                    pbVar15 = pbVar20;
                    if (pbVar16 == (byte *)0x0) goto LAB_000267d8;
LAB_00026794:
                    pbVar15 = pbVar20;
                    *(int *)(pbVar16 + 8) = (int)pbVar15 - iVar30;
                    if (pbVar15 != (byte *)0x0) {
                      iVar12 = (int)pbVar16 - iVar30;
                      do {
                        *(int *)(pbVar15 + 4) = iVar12;
                        pbVar16 = pbVar15;
                        pbVar20 = pbVar11;
                        if (pbVar5 == (byte *)0x0) goto LAB_0002677c;
LAB_000267aa:
                        pbVar15 = pbVar31;
                        pbVar31 = pbVar15;
                        if ((pbVar20 == (byte *)0x0 || pbVar27 == (byte *)0x0) ||
                           (*(int *)(pbVar15 + -iVar30 + 100) - *(int *)(pbVar20 + -iVar30 + 100) <
                            1)) {
                          if ((pbVar15 != (byte *)0x0) &&
                             (pbVar31 = (byte *)(*(int *)(pbVar15 + 8) + iVar30),
                             *(int *)(pbVar15 + 8) == 0)) {
                            pbVar31 = (byte *)0x0;
                          }
                          pbVar5 = pbVar5 + -1;
                          pbVar11 = pbVar20;
                          if (pbVar16 != (byte *)0x0) goto code_r0x00026a1e;
                        }
                        else {
                          iVar12 = *(int *)(pbVar20 + 8);
                          if (iVar12 != 0) goto LAB_0002678e;
                          pbVar27 = pbVar27 + -1;
                          pbVar11 = (byte *)0x0;
                          pbVar15 = pbVar20;
                          if (pbVar16 != (byte *)0x0) goto LAB_00026794;
                        }
LAB_000267d8:
                        iVar12 = 0;
                        pbVar32 = pbVar15;
                        if (pbVar15 == (byte *)0x0) break;
                      } while( true );
                    }
                    goto LAB_0002677a;
                  }
                  pbVar31 = pbVar11;
                } while (pbVar11 != (byte *)0x0);
                if (pbVar15 != (byte *)0x0) {
                  *(undefined4 *)(pbVar15 + 8) = 0;
                }
              } while ((1 < uVar3) &&
                      (pbVar28 = (byte *)((int)pbVar28 << 1), pbVar15 = pbVar32,
                      pbVar32 != (byte *)0x0));
              pbVar28 = pbVar32 + -iVar30;
              *(byte **)(iVar26 + 0x10) = pbVar15;
              iVar26 = *(int *)(pbVar28 + 0x48);
              local_8a8 = *(int *)(pbVar28 + 100);
              blocks = pbVar28;
              if (iVar26 == 0) {
                pbVar32 = *(byte **)(pbVar28 + 0x4c);
                if (pbVar32 != (byte *)0x0) {
                  iVar30 = *(int *)(pbVar28 + 0x44);
                  pbVar31 = pbVar32;
                  blocks = pbVar32;
                  if (pbVar28 == (byte *)(*(int *)(iVar30 + 0x10) - *(int *)(iVar30 + 0x14))) {
                    *(int *)(iVar30 + 0x10) = *(int *)(iVar30 + 0x14);
                  }
                  goto LAB_00026a9e;
                }
                free(**(void ***)(pbVar28 + 0x44));
                free(*(void **)(pbVar28 + 0x44));
                blocks = (byte *)0x0;
              }
              else {
                iVar12 = *(int *)(pbVar28 + 0x44);
                iVar30 = *(int *)(iVar12 + 0x14) + iVar26;
                if (pbVar28 == (byte *)(*(int *)(iVar12 + 0x10) - *(int *)(iVar12 + 0x14))) {
                  *(int *)(iVar12 + 0x10) = iVar30;
                }
                *(undefined4 *)(iVar30 + 8) = *(undefined4 *)(pbVar28 + 0x4c);
                pbVar32 = *(byte **)(pbVar28 + 0x4c);
                pbVar31 = pbVar28;
LAB_00026a9e:
                piVar10 = *(int **)(pbVar31 + 0x44);
                if (pbVar32 != (byte *)0x0) {
                  *(int *)(pbVar32 + piVar10[5] + 4) = iVar26;
                }
                iVar12 = *piVar10;
                iVar30 = (*(uint *)(pbVar28 + 0x60) & piVar10[1] - 1U) * 0xc;
                pbVar32 = *(byte **)(iVar12 + iVar30);
                *(int *)(iVar12 + iVar30 + 4) = *(int *)(iVar12 + iVar30 + 4) + -1;
                iVar26 = *(int *)(pbVar28 + 0x54);
                if (pbVar32 == pbVar28 + 0x44) {
                  *(int *)(iVar12 + iVar30) = iVar26;
                }
                iVar30 = *(int *)(pbVar28 + 0x50);
                if (iVar30 != 0) {
                  *(int *)(iVar30 + 0x10) = iVar26;
                  iVar26 = *(int *)(pbVar28 + 0x54);
                }
                if (iVar26 != 0) {
                  *(int *)(iVar26 + 0xc) = iVar30;
                }
                piVar10[3] = piVar10[3] + -1;
                pbVar32 = pbVar31;
              }
              free(pbVar28);
            }
          }
          uVar3 = 0xfeedbeef;
          sVar35 = strlen((char *)pbVar4);
          uVar18 = 0x9e3779b9;
          uVar14 = uVar18;
          pbVar28 = pbVar4;
          for (uVar19 = sVar35; 0xb < uVar19; uVar19 = uVar19 - 0xc) {
            iVar26 = uVar14 + (uint)pbVar28[6] * 0x10000 + (uint)pbVar28[5] * 0x100 +
                              (uint)pbVar28[4] + (uint)pbVar28[7] * 0x1000000;
            uVar3 = (uint)pbVar28[8] + (uint)pbVar28[10] * 0x10000 + (uint)pbVar28[9] * 0x100 +
                    (uint)pbVar28[0xb] * 0x1000000 + uVar3;
            uVar14 = ((((uint)*pbVar28 + (uint)pbVar28[2] * 0x10000 + (uint)pbVar28[1] * 0x100 +
                       (uint)pbVar28[3] * 0x1000000) - iVar26) - uVar3) + uVar18 ^ uVar3 >> 0xd;
            uVar18 = (iVar26 - uVar3) - uVar14 ^ uVar14 << 8;
            uVar21 = (uVar3 - uVar14) - uVar18 ^ uVar18 >> 0xd;
            uVar14 = (uVar14 - uVar18) - uVar21 ^ uVar21 >> 0xc;
            uVar3 = (uVar18 - uVar21) - uVar14 ^ uVar14 << 0x10;
            uVar21 = (uVar21 - uVar14) - uVar3 ^ uVar3 >> 5;
            uVar18 = (uVar14 - uVar3) - uVar21 ^ uVar21 >> 3;
            uVar14 = (uVar3 - uVar21) - uVar18 ^ uVar18 << 10;
            uVar3 = (uVar21 - uVar18) - uVar14 ^ uVar14 >> 0xf;
            pbVar28 = pbVar28 + 0xc;
          }
          uVar3 = sVar35 + uVar3;
          switch(uVar19) {
          case 0xb:
            uVar3 = uVar3 + (uint)pbVar28[10] * 0x1000000;
          case 10:
            uVar3 = uVar3 + (uint)pbVar28[9] * 0x10000;
          case 9:
            uVar3 = uVar3 + (uint)pbVar28[8] * 0x100;
          case 8:
            uVar14 = uVar14 + (uint)pbVar28[7] * 0x1000000;
          case 7:
            uVar14 = uVar14 + (uint)pbVar28[6] * 0x10000;
          case 6:
            uVar14 = uVar14 + (uint)pbVar28[5] * 0x100;
          case 5:
            uVar14 = uVar14 + pbVar28[4];
          case 4:
            uVar18 = uVar18 + (uint)pbVar28[3] * 0x1000000;
          case 3:
            uVar18 = uVar18 + (uint)pbVar28[2] * 0x10000;
          case 2:
            uVar18 = uVar18 + (uint)pbVar28[1] * 0x100;
          case 1:
            uVar18 = uVar18 + *pbVar28;
          }
          uVar18 = (uVar18 - uVar14) - uVar3 ^ uVar3 >> 0xd;
          *(byte **)(pbVar4 + 0x58) = pbVar4;
          uVar14 = (uVar14 - uVar3) - uVar18 ^ uVar18 << 8;
          uVar3 = (uVar3 - uVar18) - uVar14 ^ uVar14 >> 0xd;
          uVar18 = (uVar18 - uVar14) - uVar3 ^ uVar3 >> 0xc;
          uVar14 = (uVar14 - uVar3) - uVar18 ^ uVar18 << 0x10;
          uVar3 = (uVar3 - uVar18) - uVar14 ^ uVar14 >> 5;
          uVar18 = (uVar18 - uVar14) - uVar3 ^ uVar3 >> 3;
          uVar14 = (uVar14 - uVar3) - uVar18 ^ uVar18 << 10;
          uVar3 = (uVar3 - uVar18) - uVar14 ^ uVar14 >> 0xf;
          *(uint *)(pbVar4 + 0x60) = uVar3;
          sVar35 = strlen((char *)pbVar4);
          *(size_t *)(pbVar4 + 0x5c) = sVar35;
          if (pbVar32 == (byte *)0x0) {
            *(undefined4 *)(pbVar4 + 0x4c) = 0;
            *(undefined4 *)(pbVar4 + 0x48) = 0;
            blocks = pbVar4;
            pvVar6 = malloc(0x2c);
            *(void **)(pbVar4 + 0x44) = pvVar6;
            if (pvVar6 == (void *)0x0) goto LAB_0002758a;
            memset(pvVar6,0,0x2c);
            ppvVar34 = *(void ***)(pbVar4 + 0x44);
            ppvVar34[4] = pbVar4 + 0x44;
            ppvVar34[1] = (void *)0x20;
            ppvVar34[2] = (void *)0x5;
            ppvVar34[5] = (void *)0x44;
            pvVar6 = malloc(0x180);
            *ppvVar34 = pvVar6;
            if (pvVar6 == (void *)0x0) goto LAB_0002758a;
            memset(pvVar6,0,0x180);
            piVar10 = *(int **)(pbVar4 + 0x44);
            piVar10[10] = -0x5feee01f;
          }
          else {
            *(undefined4 *)(pbVar4 + 0x44) = *(undefined4 *)(pbVar32 + 0x44);
            piVar10 = *(int **)(pbVar32 + 0x44);
            *(undefined4 *)(pbVar4 + 0x4c) = 0;
            iVar26 = piVar10[4];
            *(int *)(pbVar4 + 0x48) = iVar26 - piVar10[5];
            *(byte **)(iVar26 + 8) = pbVar4;
            piVar10[4] = (int)(pbVar4 + 0x44);
          }
          iVar30 = *piVar10;
          piVar10[3] = piVar10[3] + 1;
          iVar26 = (uVar3 & piVar10[1] - 1U) * 0xc;
          iVar12 = iVar30 + iVar26;
          iVar29 = *(int *)(iVar30 + iVar26);
          uVar3 = *(int *)(iVar12 + 4) + 1;
          *(uint *)(iVar12 + 4) = uVar3;
          *(int *)(pbVar4 + 0x54) = iVar29;
          *(undefined4 *)(pbVar4 + 0x50) = 0;
          if (iVar29 != 0) {
            *(byte **)(iVar29 + 0xc) = pbVar4 + 0x44;
          }
          iVar12 = *(int *)(iVar12 + 8);
          *(byte **)(iVar30 + iVar26) = pbVar4 + 0x44;
          if (((uint)((iVar12 + 1) * 10) <= uVar3) &&
             (*(int *)(*(int *)(pbVar4 + 0x44) + 0x24) != 1)) {
            pvVar6 = calloc(*(int *)(*(int *)(pbVar4 + 0x44) + 4) * 0x18,1);
            if (pvVar6 == (void *)0x0) {
LAB_0002758a:
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            ppvVar34 = *(void ***)(pbVar4 + 0x44);
            pvVar22 = ppvVar34[1];
            ppvVar34[7] = (void *)0x0;
            pvVar33 = (void *)((uint)ppvVar34[3] >> ((int)ppvVar34[2] + 1U & 0xff));
            uVar3 = (int)pvVar22 * 2 - 1;
            if (((uint)ppvVar34[3] & uVar3) != 0) {
              pvVar33 = (void *)((int)pvVar33 + 1);
            }
            ppvVar34[6] = pvVar33;
            if (pvVar22 == (void *)0x0) {
              local_8a4 = *ppvVar34;
            }
            else {
              local_8a4 = *ppvVar34;
              local_8ac = 0;
              do {
                iVar26 = *(int *)((int)local_8a4 + local_8ac);
                while (iVar26 != 0) {
                  iVar30 = *(int *)(iVar26 + 0x10);
                  uVar18 = uVar3 & *(uint *)(iVar26 + 0x1c);
                  pvVar7 = (void *)(*(int *)((int)pvVar6 + uVar18 * 0xc + 4) + 1);
                  *(void **)((int)pvVar6 + uVar18 * 0xc + 4) = pvVar7;
                  if (pvVar33 < pvVar7) {
                    ppvVar34[7] = (void *)((int)ppvVar34[7] + 1);
                    uVar8 = __udivsi3(pvVar7,pvVar33);
                    *(undefined4 *)((int)pvVar6 + uVar18 * 0xc + 8) = uVar8;
                  }
                  iVar12 = *(int *)((int)pvVar6 + uVar18 * 0xc);
                  *(undefined4 *)(iVar26 + 0xc) = 0;
                  *(int *)(iVar26 + 0x10) = iVar12;
                  if (iVar12 != 0) {
                    *(int *)(iVar12 + 0xc) = iVar26;
                  }
                  *(int *)((int)pvVar6 + uVar18 * 0xc) = iVar26;
                  iVar26 = iVar30;
                }
                local_8ac = local_8ac + 0xc;
              } while (local_8ac != (int)pvVar22 * 0xc);
            }
            free(local_8a4);
            ppvVar34 = *(void ***)(pbVar4 + 0x44);
            *ppvVar34 = pvVar6;
            pvVar6 = (void *)((int)ppvVar34[2] + 1);
            ppvVar34[2] = pvVar6;
            if (ppvVar34[7] <= (void *)((uint)ppvVar34[3] >> 1)) {
              pvVar6 = (void *)0x0;
            }
            ppvVar34[1] = (void *)((int)ppvVar34[1] << 1);
            if ((void *)((uint)ppvVar34[3] >> 1) < ppvVar34[7]) {
              pvVar22 = (void *)((int)ppvVar34[8] + 1);
              ppvVar34[8] = pvVar22;
              pvVar6 = pvVar22;
              if ((void *)0x1 < pvVar22) {
                pvVar6 = (void *)0x1;
              }
              if ((void *)0x1 < pvVar22) {
                ppvVar34[9] = pvVar6;
              }
            }
            else {
              ppvVar34[8] = pvVar6;
            }
          }
          iVar26 = 0x1d - (uint)*(byte *)(param_1 + 0x48);
          uVar3 = iVar26 * 8;
          dVar36 = DAT_00027480;
          if (7 < (int)uVar3) {
            dVar36 = (double)__floatundidf(0xffff << (uVar3 & 0xff),
                                           0xffff << (uVar3 - 0x20 & 0xff) |
                                           0xffffU >> (iVar26 * -8 + 0x20U & 0xff));
          }
          pdVar2 = DAT_00027154;
          uVar3 = *(uint *)(param_1 + 0x48);
          dVar36 = dVar36 / (double)(longlong)
                                    (int)((uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                         | uVar3 >> 0x18);
          if (dVar36 != *DAT_00027154) {
            UVar37 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff72c,uVar38));
            suffix_string((int)UVar37,(int)(UVar37 >> 0x20),DAT_00027594,8,0);
            *pdVar2 = dVar36;
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
              snprintf((char *)&local_830,0x800,"Network diff set to %s",DAT_00027594);
              _applog(5,&local_830,0);
            }
          }
          if (((local_8a8 != 0) && (opt_debug != '\0')) &&
             ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
            snprintf((char *)&local_830,0x800,"Deleted block %d from database",local_8a8);
            _applog(7,&local_830,0);
          }
          iVar26 = pthread_rwlock_unlock(DAT_00027158);
          if (iVar26 == 0) {
            (*selective_yield)();
            iVar26 = pthread_mutex_lock((pthread_mutex_t *)ch_lock);
            if (iVar26 == 0) {
              iVar26 = pthread_rwlock_wrlock(DAT_0002715c);
              uVar38 = DAT_00027174;
              if (iVar26 == 0) {
                cgtime(&block_timeval);
                strcpy(current_hash,(char *)abStack_874);
                _cg_memcpy(DAT_00027160,&local_894,0x20,"cgminer.c",uVar38,0x1542);
                local_830 = (time_t)block_timeval;
                iVar26 = block_timeval._4_4_ / 1000;
                ptVar9 = localtime(&local_830);
                iVar30 = ptVar9->tm_min;
                snprintf(DAT_00027164,0x20,"[%02d:%02d:%02d.%03d]",ptVar9->tm_hour,iVar30,
                         ptVar9->tm_sec,iVar26);
                iVar26 = pthread_rwlock_unlock(DAT_0002715c);
                if (iVar26 == 0) {
                  iVar26 = pthread_mutex_unlock((pthread_mutex_t *)ch_lock);
                  if (iVar26 == 0) {
                    (*selective_yield)();
                    pcVar23 = (char *)((int)&total_tv_start_sys + 3);
                    iVar26 = 0;
                    do {
                      pcVar23 = pcVar23 + 1;
                      if (*pcVar23 != '0') break;
                      iVar26 = iVar26 + 1;
                    } while (iVar26 != 0x39);
                    strncpy(DAT_00027168,current_hash + iVar26,8);
                    prev_block[8] = 0;
                    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
                      iVar30 = DAT_0002716c;
                      snprintf((char *)&local_830,0x800,"New block: %s... diff %s",current_hash,
                               DAT_0002716c);
                      _applog(6,&local_830,0);
                    }
                    if (((local_8a8 != 0) && (opt_debug != '\0')) &&
                       ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level))))))
                    {
                      snprintf((char *)&local_830,0x800,"Deleted block %d from database",local_8a8,
                               iVar30);
                      _applog(7,&local_830,0);
                    }
                    _cg_memcpy(puVar17 + 0x88,&local_894,0x20,"cgminer.c",DAT_00027170,0x15d5);
                    if (new_blocks == 1) {
                      cVar25 = '\0';
                      goto LAB_0002695e;
                    }
                    work_block = work_block + 1;
                    *(int *)(param_1 + 0x150) = work_block;
                    if (*(char *)(param_1 + 0x118) == '\0') {
                      if (have_longpoll == '\0') {
                        if ((*(char *)(puVar17 + 0xe1) == '\0') &&
                           (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)
                            ))) {
                          local_830._0_1_ = s_New_block_detected_on_network_0005e11c[0];
                          local_830._1_1_ = s_New_block_detected_on_network_0005e11c[1];
                          local_830._2_1_ = s_New_block_detected_on_network_0005e11c[2];
                          local_830._3_1_ = s_New_block_detected_on_network_0005e11c[3];
                          uStack_82c._0_1_ = s_New_block_detected_on_network_0005e11c[4];
                          uStack_82c._1_1_ = s_New_block_detected_on_network_0005e11c[5];
                          uStack_82c._2_1_ = s_New_block_detected_on_network_0005e11c[6];
                          uStack_82c._3_1_ = s_New_block_detected_on_network_0005e11c[7];
                          uStack_828._0_1_ = s_New_block_detected_on_network_0005e11c[8];
                          uStack_828._1_1_ = s_New_block_detected_on_network_0005e11c[9];
                          uStack_828._2_1_ = s_New_block_detected_on_network_0005e11c[10];
                          uStack_828._3_1_ = s_New_block_detected_on_network_0005e11c[11];
                          uStack_824._0_1_ = s_New_block_detected_on_network_0005e11c[12];
                          uStack_824._1_1_ = s_New_block_detected_on_network_0005e11c[13];
                          uStack_824._2_1_ = s_New_block_detected_on_network_0005e11c[14];
                          uStack_824._3_1_ = s_New_block_detected_on_network_0005e11c[15];
                          local_820._0_1_ = s_New_block_detected_on_network_0005e11c[16];
                          local_820._1_1_ = s_New_block_detected_on_network_0005e11c[17];
                          local_820._2_1_ = s_New_block_detected_on_network_0005e11c[18];
                          local_820._3_1_ = s_New_block_detected_on_network_0005e11c[19];
                          uStack_81c._0_1_ = s_New_block_detected_on_network_0005e11c[20];
                          uStack_81c._1_1_ = s_New_block_detected_on_network_0005e11c[21];
                          uStack_81c._2_1_ = s_New_block_detected_on_network_0005e11c[22];
                          uStack_81c._3_1_ = s_New_block_detected_on_network_0005e11c[23];
                          uStack_818._0_1_ = s_New_block_detected_on_network_0005e11c[24];
                          uStack_818._1_1_ = s_New_block_detected_on_network_0005e11c[25];
                          uStack_818._2_1_ = s_New_block_detected_on_network_0005e11c[26];
                          uStack_818._3_1_ = s_New_block_detected_on_network_0005e11c[27];
                          local_814._0_2_ = (short)ram0x0005e138;
                          _applog(5,&local_830,0);
                        }
                      }
                      else if ((*(char *)(puVar17 + 0xe1) == '\0') &&
                              (((use_syslog != '\0' || (opt_log_output != '\0')) ||
                               (4 < opt_log_level)))) {
                        local_830._0_1_ = s_New_block_detected_on_network_be_0005e0e4[0];
                        local_830._1_1_ = s_New_block_detected_on_network_be_0005e0e4[1];
                        local_830._2_1_ = s_New_block_detected_on_network_be_0005e0e4[2];
                        local_830._3_1_ = s_New_block_detected_on_network_be_0005e0e4[3];
                        uStack_82c._0_1_ = s_New_block_detected_on_network_be_0005e0e4[4];
                        uStack_82c._1_1_ = s_New_block_detected_on_network_be_0005e0e4[5];
                        uStack_82c._2_1_ = s_New_block_detected_on_network_be_0005e0e4[6];
                        uStack_82c._3_1_ = s_New_block_detected_on_network_be_0005e0e4[7];
                        uStack_828._0_1_ = s_New_block_detected_on_network_be_0005e0e4[8];
                        uStack_828._1_1_ = s_New_block_detected_on_network_be_0005e0e4[9];
                        uStack_828._2_1_ = s_New_block_detected_on_network_be_0005e0e4[10];
                        uStack_828._3_1_ = s_New_block_detected_on_network_be_0005e0e4[11];
                        uStack_824._0_1_ = s_New_block_detected_on_network_be_0005e0e4[12];
                        uStack_824._1_1_ = s_New_block_detected_on_network_be_0005e0e4[13];
                        uStack_824._2_1_ = s_New_block_detected_on_network_be_0005e0e4[14];
                        uStack_824._3_1_ = s_New_block_detected_on_network_be_0005e0e4[15];
                        local_820._0_1_ = s_New_block_detected_on_network_be_0005e0e4[16];
                        local_820._1_1_ = s_New_block_detected_on_network_be_0005e0e4[17];
                        local_820._2_1_ = s_New_block_detected_on_network_be_0005e0e4[18];
                        local_820._3_1_ = s_New_block_detected_on_network_be_0005e0e4[19];
                        uStack_81c._0_1_ = s_New_block_detected_on_network_be_0005e0e4[20];
                        uStack_81c._1_1_ = s_New_block_detected_on_network_be_0005e0e4[21];
                        uStack_81c._2_1_ = s_New_block_detected_on_network_be_0005e0e4[22];
                        uStack_81c._3_1_ = s_New_block_detected_on_network_be_0005e0e4[23];
                        uStack_818._0_1_ = s_New_block_detected_on_network_be_0005e0e4[24];
                        uStack_818._1_1_ = s_New_block_detected_on_network_be_0005e0e4[25];
                        uStack_818._2_1_ = s_New_block_detected_on_network_be_0005e0e4[26];
                        uStack_818._3_1_ = s_New_block_detected_on_network_be_0005e0e4[27];
                        local_814._0_1_ = s_New_block_detected_on_network_be_0005e0e4[28];
                        local_814._1_1_ = s_New_block_detected_on_network_be_0005e0e4[29];
                        local_814._2_1_ = s_New_block_detected_on_network_be_0005e0e4[30];
                        local_814._3_1_ = s_New_block_detected_on_network_be_0005e0e4[31];
                        local_810._0_1_ = s_New_block_detected_on_network_be_0005e0e4[32];
                        local_810._1_1_ = s_New_block_detected_on_network_be_0005e0e4[33];
                        local_810._2_1_ = s_New_block_detected_on_network_be_0005e0e4[34];
                        local_810._3_1_ = s_New_block_detected_on_network_be_0005e0e4[35];
                        uStack_80c._0_1_ = s_New_block_detected_on_network_be_0005e0e4[36];
                        uStack_80c._1_1_ = s_New_block_detected_on_network_be_0005e0e4[37];
                        uStack_80c._2_1_ = s_New_block_detected_on_network_be_0005e0e4[38];
                        uStack_80c._3_1_ = s_New_block_detected_on_network_be_0005e0e4[39];
                        uStack_808._0_1_ = s_New_block_detected_on_network_be_0005e0e4[40];
                        uStack_808._1_1_ = s_New_block_detected_on_network_be_0005e0e4[41];
                        uStack_808._2_1_ = s_New_block_detected_on_network_be_0005e0e4[42];
                        uStack_808._3_1_ = s_New_block_detected_on_network_be_0005e0e4[43];
                        uStack_804._0_1_ = s_New_block_detected_on_network_be_0005e0e4[44];
                        uStack_804._1_1_ = s_New_block_detected_on_network_be_0005e0e4[45];
                        uStack_804._2_1_ = s_New_block_detected_on_network_be_0005e0e4[46];
                        uStack_804._3_1_ = s_New_block_detected_on_network_be_0005e0e4[47];
                        uStack_800._0_1_ = s_New_block_detected_on_network_be_0005e0e4[48];
                        uStack_800._1_1_ = s_New_block_detected_on_network_be_0005e0e4[49];
                        uStack_800._2_1_ = s_New_block_detected_on_network_be_0005e0e4[50];
                        uStack_800._3_1_ = s_New_block_detected_on_network_be_0005e0e4[51];
                        uStack_7fc = (undefined2)ram0x0005e118;
                        local_7fa = (undefined)((uint)ram0x0005e118 >> 0x10);
                        _applog(5,&local_830,0);
                      }
                    }
                    else if (*(char *)(param_1 + 0x11c) == '\0') {
                      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level))
                      {
                        iVar26 = **(int **)(param_1 + 0x104);
                        puVar24 = &DAT_000609ec;
                        if (*(char *)(param_1 + 0x144) != '\0') {
                          puVar24 = &UNK_0005dff8;
                        }
                        pcVar23 = "%sLONGPOLL from pool %d detected new block";
                        goto LAB_000270ec;
                      }
                    }
                    else if (((use_syslog != '\0') || (opt_log_output != '\0')) ||
                            (4 < opt_log_level)) {
                      pcVar23 = "Stratum from pool %d detected new block at height %d";
                      puVar24 = (undefined *)*puVar17;
                      iVar26 = local_898;
LAB_000270ec:
                      snprintf((char *)&local_830,0x800,pcVar23,puVar24,iVar26);
                      _applog(5,&local_830,0);
                    }
                    restart_threads();
                    cVar25 = '\x01';
LAB_0002695e:
                    *(undefined *)(param_1 + 0x118) = 0;
                    return cVar25;
                  }
                  piVar10 = __errno_location();
                  pcVar23 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
                  iVar26 = *piVar10;
                }
                else {
                  piVar10 = __errno_location();
                  iVar26 = *piVar10;
                  pcVar23 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
                }
                snprintf((char *)&local_830,0x800,pcVar23,iVar26,"cgminer.c",uVar38,0x1544);
                goto LAB_00027144;
              }
              piVar10 = __errno_location();
              iVar26 = *piVar10;
              uVar8 = 0x153f;
              pcVar23 = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
              uVar38 = DAT_00027490;
            }
            else {
              piVar10 = __errno_location();
              iVar26 = *piVar10;
              uVar8 = 0x153f;
              pcVar23 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
              uVar38 = DAT_00027490;
            }
          }
          else {
LAB_00027202:
            uVar38 = DAT_0002748c;
            piVar10 = __errno_location();
            iVar26 = *piVar10;
            uVar8 = 0x159c;
            pcVar23 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
          }
          snprintf((char *)&local_830,0x800,pcVar23,iVar26,"cgminer.c",uVar38,uVar8);
          goto LAB_00027144;
        }
        piVar10 = __errno_location();
        iVar26 = *piVar10;
        pcVar23 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar8 = 0x15cd;
      }
      else {
        piVar10 = __errno_location();
        iVar26 = *piVar10;
        pcVar23 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar8 = 0x15cd;
      }
    }
    else {
      piVar10 = __errno_location();
      iVar26 = *piVar10;
      uVar8 = 0x15c5;
      uVar38 = DAT_00027488;
LAB_0002718c:
      pcVar23 = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
    }
  }
  else {
    piVar10 = __errno_location();
    iVar26 = *piVar10;
    pcVar23 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar8 = 0x15c5;
    uVar38 = DAT_00027170;
  }
  snprintf((char *)&local_830,0x800,pcVar23,iVar26,"cgminer.c",uVar38,uVar8);
LAB_00027144:
  _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
code_r0x00026a1e:
  pbVar20 = pbVar15;
  if (pbVar15 == (byte *)0x0) {
    *(undefined4 *)(pbVar16 + 8) = 0;
    goto LAB_0002677a;
  }
  goto LAB_00026794;
}

