
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 stratum_sthread(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  pthread_mutex_t *ppVar3;
  int **ppiVar4;
  pthread_t __th;
  int iVar5;
  int **__ptr;
  int *piVar6;
  uint uVar7;
  time_t tVar8;
  size_t sVar9;
  void *pvVar10;
  void *pvVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  char *pcVar17;
  byte bVar18;
  int iVar19;
  int *piVar20;
  uint uVar21;
  void *pvVar22;
  int iVar23;
  undefined4 uVar24;
  int iVar25;
  undefined4 *puVar26;
  pthread_rwlock_t *__rwlock;
  void *pvVar27;
  void **ppvVar28;
  bool bVar29;
  undefined *puVar30;
  undefined *puVar31;
  int local_ca8;
  void *local_ca4;
  int local_c6c;
  int *local_c68;
  uint local_c64;
  int local_c60;
  int iStack_c5c;
  undefined auStack_c58 [12];
  char acStack_c4c [16];
  undefined auStack_c3c [20];
  char acStack_c28 [1024];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 local_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined2 local_7f4;
  
  __th = pthread_self();
  pthread_detach(__th);
  snprintf(acStack_c4c,0x10,"%d/SStratum",*param_1);
  RenameThread(acStack_c4c);
  iVar5 = tq_new();
  param_1[0xb6] = iVar5;
  if (iVar5 == 0) {
    local_828._0_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[0];
    local_828._1_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[1];
    local_828._2_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[2];
    local_828._3_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[3];
    uStack_824._0_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[4];
    uStack_824._1_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[5];
    uStack_824._2_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[6];
    uStack_824._3_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[7];
    uStack_820._0_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[8];
    uStack_820._1_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[9];
    uStack_820._2_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[10];
    uStack_820._3_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[11];
    uStack_81c._0_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[12];
    uStack_81c._1_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[13];
    uStack_81c._2_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[14];
    uStack_81c._3_1_ = s_Failed_to_create_stratum_q_in_st_0005da2c[15];
    pcVar17 = " stratum_q in stratum_sthread";
    puVar26 = &local_818;
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x69);
    iVar15 = 0;
    iVar23 = 0;
    iVar2 = 0;
    while( true ) {
      if (cVar1 != '\0') {
        tq_freeze();
        return 0;
      }
      local_c68 = (int *)tq_pop(iVar5);
      if (local_c68 == (int *)0x0) break;
      if ((uint)local_c68[0x4c] < 9) {
        iVar13 = local_c68[0x13];
        iVar19 = local_c68[0x4a];
        iVar25 = local_c68[0x4b];
        local_c6c = iVar13;
        local_c60 = iVar19;
        iStack_c5c = iVar25;
        if (iVar23 == iVar13 && (iVar2 == iVar25 && iVar15 == iVar19)) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,"Filtering duplicate share to pool %d",*param_1);
            _applog(6,&local_828,0);
          }
          _free_work(&local_c68,"cgminer.c",DAT_00024afc,0x1d99);
          iVar13 = iVar23;
          iVar19 = iVar15;
          iVar25 = iVar2;
        }
        else {
          __bin2hex(auStack_c58,&local_c6c,4);
          __bin2hex(auStack_c3c,&local_c60,local_c68[0x4c]);
          __ptr = (int **)_cgcalloc(0x34,1,"cgminer.c",DAT_00024508,0x1da2);
          piVar20 = local_c68;
          piVar6 = (int *)time((time_t *)0x0);
          __ptr[0xb] = piVar6;
          __ptr[9] = local_c68;
          memset(acStack_c28,0,0x400);
          iVar5 = pthread_mutex_lock(DAT_0002450c);
          ppVar3 = DAT_0002450c;
          if (iVar5 != 0) {
            piVar20 = __errno_location();
            iVar5 = *piVar20;
            uVar12 = 0x1dab;
LAB_000247ea:
            pcVar17 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
            uVar16 = DAT_00024820;
LAB_00024800:
            snprintf((char *)&local_828,0x800,pcVar17,iVar5,"cgminer.c",uVar16,uVar12);
            _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
            __quit(1);
          }
          __ptr[10] = swork_id;
          swork_id = (int *)((int)swork_id + 1);
          uVar7 = pthread_mutex_unlock(ppVar3);
          if (uVar7 != 0) {
            piVar20 = __errno_location();
            iVar5 = *piVar20;
            uVar12 = 0x1dae;
LAB_0002482e:
            pcVar17 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
            uVar16 = DAT_00024afc;
            goto LAB_00024800;
          }
          (*selective_yield)();
          local_c64 = uVar7;
          hex2bin(&local_c64,param_1 + 0x1bd,4);
          if (*(char *)(param_1 + 0xa1) == '\0') {
            puVar31 = auStack_c58;
            puVar30 = auStack_c3c;
            piVar6 = __ptr[10];
            iVar5 = local_c68[0x4d];
            snprintf(acStack_c28,0x400,
                     "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
                     ,param_1[0x2b],local_c68[0x48],puVar30,iVar5,puVar31,piVar6);
          }
          else {
            puVar31 = auStack_c58;
            uVar7 = local_c68[0x6f] & ~local_c64;
            piVar6 = (int *)(uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 |
                             (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18);
            puVar30 = auStack_c3c;
            iVar5 = local_c68[0x4d];
            snprintf(acStack_c28,0x400,
                     "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
                     ,param_1[0x2b],local_c68[0x48],puVar30,iVar5,puVar31,piVar6,__ptr[10]);
          }
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,"Submitting share %08lx to pool %d",piVar20[0x36],
                     *param_1,puVar30,iVar5,puVar31,piVar6);
            _applog(6,&local_828,0);
          }
          while (piVar20 = __ptr[0xb], tVar8 = time((time_t *)0x0), tVar8 <= (int)piVar20 + 0x77) {
            sVar9 = strlen(acStack_c28);
            iVar5 = stratum_send(param_1,acStack_c28,sVar9);
            if (iVar5 != 0) {
              iVar5 = pthread_mutex_lock((pthread_mutex_t *)sshare_lock);
              ppiVar4 = stratum_shares;
              if (iVar5 == 0) {
                __ptr[6] = (int *)0x4;
                uVar21 = *(byte *)(__ptr + 10) + 0x112410d +
                         (uint)*(byte *)((int)__ptr + 0x2b) * 0x1000000 +
                         (uint)*(byte *)((int)__ptr + 0x2a) * 0x10000 +
                         (uint)*(byte *)((int)__ptr + 0x29) * 0x100 ^ 0x7f76d;
                __ptr[5] = (int *)(__ptr + 10);
                uVar14 = 0x9f49bac6 - uVar21 ^ uVar21 << 8;
                uVar7 = (-0x112410d - uVar21) - uVar14 ^ uVar14 >> 0xd;
                uVar21 = (uVar21 - uVar14) - uVar7 ^ uVar7 >> 0xc;
                uVar14 = (uVar14 - uVar7) - uVar21 ^ uVar21 << 0x10;
                uVar7 = (uVar7 - uVar21) - uVar14 ^ uVar14 >> 5;
                uVar21 = (uVar21 - uVar14) - uVar7 ^ uVar7 >> 3;
                uVar14 = (uVar14 - uVar7) - uVar21 ^ uVar21 << 10;
                piVar20 = (int *)((uVar7 - uVar21) - uVar14 ^ uVar14 >> 0xf);
                __ptr[7] = piVar20;
                if (ppiVar4 == (int **)0x0) {
                  __ptr[2] = (int *)0x0;
                  __ptr[1] = (int *)0x0;
                  stratum_shares = __ptr;
                  piVar6 = (int *)malloc(0x2c);
                  *__ptr = piVar6;
                  if (piVar6 == (int *)0x0) goto LAB_00024b5a;
                  memset(piVar6,0,0x2c);
                  ppvVar28 = (void **)*__ptr;
                  ppvVar28[4] = __ptr;
                  ppvVar28[5] = (void *)0x0;
                  ppvVar28[1] = (void *)0x20;
                  ppvVar28[2] = (void *)0x5;
                  pvVar10 = malloc(0x180);
                  *ppvVar28 = pvVar10;
                  if (pvVar10 == (void *)0x0) goto LAB_00024b5a;
                  memset(pvVar10,0,0x180);
                  piVar6 = *__ptr;
                  piVar6[10] = -0x5feee01f;
                }
                else {
                  *__ptr = *ppiVar4;
                  piVar6 = *ppiVar4;
                  __ptr[2] = (int *)0x0;
                  iVar5 = piVar6[4];
                  __ptr[1] = (int *)(iVar5 - piVar6[5]);
                  *(int ***)(iVar5 + 8) = __ptr;
                  piVar6[4] = (int)__ptr;
                }
                iVar5 = *piVar6;
                uVar14 = (uint)piVar20 & piVar6[1] - 1U;
                piVar6[3] = piVar6[3] + 1;
                iVar15 = iVar5 + uVar14 * 0xc;
                piVar20 = *(int **)(iVar5 + uVar14 * 0xc);
                uVar7 = *(int *)(iVar15 + 4) + 1;
                *(uint *)(iVar15 + 4) = uVar7;
                __ptr[4] = piVar20;
                __ptr[3] = (int *)0x0;
                if (piVar20 != (int *)0x0) {
                  piVar20[3] = (int)__ptr;
                }
                iVar15 = *(int *)(iVar15 + 8);
                *(int ***)(iVar5 + uVar14 * 0xc) = __ptr;
                if (((uint)((iVar15 + 1) * 10) <= uVar7) && ((*__ptr)[9] != 1)) {
                  pvVar10 = calloc((*__ptr)[1] * 0x18,1);
                  if (pvVar10 == (void *)0x0) {
LAB_00024b5a:
                    /* WARNING: Subroutine does not return */
                    exit(-1);
                  }
                  ppvVar28 = (void **)*__ptr;
                  pvVar22 = ppvVar28[1];
                  ppvVar28[7] = (void *)0x0;
                  pvVar27 = (void *)((uint)ppvVar28[3] >> ((int)ppvVar28[2] + 1U & 0xff));
                  uVar7 = (int)pvVar22 * 2 - 1;
                  if (((uint)ppvVar28[3] & uVar7) != 0) {
                    pvVar27 = (void *)((int)pvVar27 + 1);
                  }
                  ppvVar28[6] = pvVar27;
                  if (pvVar22 == (void *)0x0) {
                    local_ca4 = *ppvVar28;
                  }
                  else {
                    local_ca4 = *ppvVar28;
                    local_ca8 = 0;
                    do {
                      iVar5 = *(int *)((int)local_ca4 + local_ca8);
                      while (iVar5 != 0) {
                        iVar15 = *(int *)(iVar5 + 0x10);
                        uVar14 = uVar7 & *(uint *)(iVar5 + 0x1c);
                        pvVar11 = (void *)(*(int *)((int)pvVar10 + uVar14 * 0xc + 4) + 1);
                        *(void **)((int)pvVar10 + uVar14 * 0xc + 4) = pvVar11;
                        if (pvVar27 < pvVar11) {
                          ppvVar28[7] = (void *)((int)ppvVar28[7] + 1);
                          uVar12 = __udivsi3(pvVar11,pvVar27);
                          *(undefined4 *)((int)pvVar10 + uVar14 * 0xc + 8) = uVar12;
                        }
                        iVar23 = *(int *)((int)pvVar10 + uVar14 * 0xc);
                        *(undefined4 *)(iVar5 + 0xc) = 0;
                        *(int *)(iVar5 + 0x10) = iVar23;
                        if (iVar23 != 0) {
                          *(int *)(iVar23 + 0xc) = iVar5;
                        }
                        *(int *)((int)pvVar10 + uVar14 * 0xc) = iVar5;
                        iVar5 = iVar15;
                      }
                      local_ca8 = local_ca8 + 0xc;
                    } while ((int)pvVar22 * 0xc != local_ca8);
                  }
                  free(local_ca4);
                  ppvVar28 = (void **)*__ptr;
                  *ppvVar28 = pvVar10;
                  pvVar10 = (void *)((int)ppvVar28[2] + 1);
                  ppvVar28[2] = pvVar10;
                  if (ppvVar28[7] <= (void *)((uint)ppvVar28[3] >> 1)) {
                    pvVar10 = (void *)0x0;
                  }
                  ppvVar28[1] = (void *)((int)ppvVar28[1] << 1);
                  if ((void *)((uint)ppvVar28[3] >> 1) < ppvVar28[7]) {
                    pvVar22 = (void *)((int)ppvVar28[8] + 1);
                    ppvVar28[8] = pvVar22;
                    pvVar10 = pvVar22;
                    if ((void *)0x1 < pvVar22) {
                      pvVar10 = (void *)0x1;
                    }
                    if ((void *)0x1 < pvVar22) {
                      ppvVar28[9] = pvVar10;
                    }
                  }
                  else {
                    ppvVar28[8] = pvVar10;
                  }
                }
                ppVar3 = DAT_0002481c;
                param_1[0xb7] = param_1[0xb7] + 1;
                iVar5 = pthread_mutex_unlock(ppVar3);
                if (iVar5 != 0) {
                  piVar20 = __errno_location();
                  uVar12 = 0x1dd7;
                  iVar5 = *piVar20;
                  goto LAB_0002482e;
                }
                (*selective_yield)();
                iVar5 = pool_tclear(param_1,param_1 + 0x18);
                if (iVar5 == 0) {
LAB_00024640:
                  if (opt_debug != 0) {
                    if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000246fc;
LAB_00024662:
                    local_828._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[0];
                    local_828._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[1];
                    local_828._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[2];
                    local_828._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[3];
                    uStack_824._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[4];
                    uStack_824._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[5];
                    uStack_824._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[6];
                    uStack_824._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[7];
                    uStack_820._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[8];
                    uStack_820._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[9];
                    uStack_820._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[10];
                    uStack_820._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[11];
                    uStack_81c._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[12];
                    uStack_81c._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[13];
                    uStack_81c._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[14];
                    uStack_81c._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[15];
                    local_818._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[16];
                    local_818._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[17];
                    local_818._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[18];
                    local_818._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[19];
                    uStack_814._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[20];
                    uStack_814._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[21];
                    uStack_814._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[22];
                    uStack_814._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[23];
                    uStack_810._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[24];
                    uStack_810._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[25];
                    uStack_810._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[26];
                    uStack_810._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[27];
                    local_80c._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[28];
                    local_80c._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[29];
                    local_80c._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[30];
                    local_80c._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[31];
                    local_808._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[32];
                    local_808._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[33];
                    local_808._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[34];
                    local_808._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[35];
                    uStack_804._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[36];
                    uStack_804._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[37];
                    uStack_804._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[38];
                    uStack_804._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[39];
                    uStack_800._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[40];
                    uStack_800._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[41];
                    uStack_800._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[42];
                    uStack_800._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[43];
                    uStack_7fc._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[44];
                    uStack_7fc._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[45];
                    uStack_7fc._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[46];
                    uStack_7fc._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[47];
                    local_7f8._0_1_ = s_Successfully_submitted__adding_t_0005dbfc[48];
                    local_7f8._1_1_ = s_Successfully_submitted__adding_t_0005dbfc[49];
                    local_7f8._2_1_ = s_Successfully_submitted__adding_t_0005dbfc[50];
                    local_7f8._3_1_ = s_Successfully_submitted__adding_t_0005dbfc[51];
                    _applog(7,&local_828,0);
                  }
                }
                else {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
                    snprintf((char *)&local_828,0x800,
                             "Pool %d communication resumed, submitting work",*param_1);
                    _applog(4,&local_828,0);
                    goto LAB_00024640;
                  }
                  if (opt_debug != 0) {
LAB_000246fc:
                    if (6 < opt_log_level) goto LAB_00024662;
                  }
                }
                piVar20 = (int *)time((time_t *)0x0);
                bVar18 = opt_debug;
                __ptr[0xc] = piVar20;
                if (0 < (int)piVar20 - (int)__ptr[0xb]) {
                  bVar18 = bVar18 | 1;
                }
                if ((bVar18 != 0) &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
                  snprintf((char *)&local_828,0x800,
                           "Pool %d stratum share submission lag time %d seconds",*param_1,
                           (int)piVar20 - (int)__ptr[0xb]);
                  _applog(6,&local_828,0);
                }
                goto LAB_000245fc;
              }
              piVar20 = __errno_location();
              uVar12 = 0x1dd4;
              iVar5 = *piVar20;
              goto LAB_000247ea;
            }
            iVar5 = pool_tset(param_1,param_1 + 0x18);
            if ((iVar5 == 0) && (iVar5 = cnx_needed(param_1), iVar5 != 0)) {
              if ((use_syslog != '\0') || ((opt_log_output != '\0' || (3 < opt_log_level)))) {
                snprintf((char *)&local_828,0x800,"Pool %d stratum share submission failure",
                         *param_1);
                _applog(4,&local_828,0);
              }
              total_ro = total_ro + 1;
              param_1[0x21] = param_1[0x21] + 1;
            }
            if (opt_lowmem != '\0') {
              if (opt_debug == 0) goto LAB_00024a24;
              if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
              goto LAB_000249e4;
              local_828._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[0];
              local_828._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[1];
              local_828._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[2];
              local_828._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[3];
              uStack_824._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[4];
              uStack_824._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[5];
              uStack_824._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[6];
              uStack_824._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[7];
              uStack_820._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[8];
              uStack_820._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[9];
              uStack_820._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[10];
              uStack_820._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[11];
              uStack_81c._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[12];
              uStack_81c._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[13];
              uStack_81c._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[14];
              uStack_81c._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[15];
              local_818._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[16];
              local_818._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[17];
              local_818._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[18];
              local_818._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[19];
              uStack_814._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[20];
              uStack_814._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[21];
              uStack_814._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[22];
              uStack_814._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[23];
              uStack_810._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[24];
              uStack_810._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[25];
              uStack_810._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[26];
              uStack_810._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[27];
              local_80c._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[28];
              local_80c._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[29];
              local_80c._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[30];
              local_80c._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[31];
              local_808._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[32];
              local_808._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[33];
              local_808._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[34];
              local_808._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[35];
              uStack_804._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[36];
              uStack_804._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[37];
              uStack_804._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[38];
              uStack_804._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[39];
              uStack_800._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[40];
              uStack_800._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[41];
              uStack_800._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[42];
              uStack_800._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[43];
              uStack_7fc._0_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[44];
              uStack_7fc._1_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[45];
              uStack_7fc._2_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[46];
              uStack_7fc._3_1_ = s_Lowmem_option_prevents_resubmitt_0005dc5c[47];
              local_7f8._0_2_ = (short)ram0x0005dc8c;
              _applog(7,&local_828,0);
              break;
            }
            iVar5 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x35));
            if (iVar5 != 0) {
              piVar20 = __errno_location();
              uVar12 = 0x1ded;
              iVar5 = *piVar20;
              goto LAB_000247ea;
            }
            __rwlock = (pthread_rwlock_t *)(param_1 + 0x3b);
            iVar5 = pthread_rwlock_rdlock(__rwlock);
            if (iVar5 != 0) {
              piVar20 = __errno_location();
              iVar5 = *piVar20;
              pcVar17 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
              uVar12 = 0x1ded;
              uVar16 = DAT_00024afc;
              goto LAB_00024800;
            }
            iVar5 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x35));
            if (iVar5 != 0) {
              piVar20 = __errno_location();
              uVar12 = 0x1ded;
              iVar5 = *piVar20;
              goto LAB_0002482e;
            }
            if (((char *)param_1[0x99] == (char *)0x0) ||
               (iVar5 = strcmp((char *)local_c68[0x50],(char *)param_1[0x99]), iVar5 != 0)) {
              iVar5 = pthread_rwlock_unlock(__rwlock);
              if (iVar5 != 0) {
LAB_000248cc:
                piVar20 = __errno_location();
                iVar5 = *piVar20;
                pcVar17 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
                uVar12 = 0x1def;
                uVar16 = DAT_00024afc;
                goto LAB_00024800;
              }
              (*selective_yield)();
              if (opt_debug == 0) goto LAB_00024a24;
              if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7))
              goto LAB_000249e4;
              local_828._0_1_ = s_No_matching_session_id_for_resub_0005dc90[0];
              local_828._1_1_ = s_No_matching_session_id_for_resub_0005dc90[1];
              local_828._2_1_ = s_No_matching_session_id_for_resub_0005dc90[2];
              local_828._3_1_ = s_No_matching_session_id_for_resub_0005dc90[3];
              uStack_824._0_1_ = s_No_matching_session_id_for_resub_0005dc90[4];
              uStack_824._1_1_ = s_No_matching_session_id_for_resub_0005dc90[5];
              uStack_824._2_1_ = s_No_matching_session_id_for_resub_0005dc90[6];
              uStack_824._3_1_ = s_No_matching_session_id_for_resub_0005dc90[7];
              uStack_820._0_1_ = s_No_matching_session_id_for_resub_0005dc90[8];
              uStack_820._1_1_ = s_No_matching_session_id_for_resub_0005dc90[9];
              uStack_820._2_1_ = s_No_matching_session_id_for_resub_0005dc90[10];
              uStack_820._3_1_ = s_No_matching_session_id_for_resub_0005dc90[11];
              uStack_81c._0_1_ = s_No_matching_session_id_for_resub_0005dc90[12];
              uStack_81c._1_1_ = s_No_matching_session_id_for_resub_0005dc90[13];
              uStack_81c._2_1_ = s_No_matching_session_id_for_resub_0005dc90[14];
              uStack_81c._3_1_ = s_No_matching_session_id_for_resub_0005dc90[15];
              local_818._0_1_ = s_No_matching_session_id_for_resub_0005dc90[16];
              local_818._1_1_ = s_No_matching_session_id_for_resub_0005dc90[17];
              local_818._2_1_ = s_No_matching_session_id_for_resub_0005dc90[18];
              local_818._3_1_ = s_No_matching_session_id_for_resub_0005dc90[19];
              uStack_814._0_1_ = s_No_matching_session_id_for_resub_0005dc90[20];
              uStack_814._1_1_ = s_No_matching_session_id_for_resub_0005dc90[21];
              uStack_814._2_1_ = s_No_matching_session_id_for_resub_0005dc90[22];
              uStack_814._3_1_ = s_No_matching_session_id_for_resub_0005dc90[23];
              uStack_810._0_1_ = s_No_matching_session_id_for_resub_0005dc90[24];
              uStack_810._1_1_ = s_No_matching_session_id_for_resub_0005dc90[25];
              uStack_810._2_1_ = s_No_matching_session_id_for_resub_0005dc90[26];
              uStack_810._3_1_ = s_No_matching_session_id_for_resub_0005dc90[27];
              local_80c._0_1_ = s_No_matching_session_id_for_resub_0005dc90[28];
              local_80c._1_1_ = s_No_matching_session_id_for_resub_0005dc90[29];
              local_80c._2_1_ = s_No_matching_session_id_for_resub_0005dc90[30];
              local_80c._3_1_ = s_No_matching_session_id_for_resub_0005dc90[31];
              local_808._0_1_ = s_No_matching_session_id_for_resub_0005dc90[32];
              local_808._1_1_ = s_No_matching_session_id_for_resub_0005dc90[33];
              local_808._2_1_ = s_No_matching_session_id_for_resub_0005dc90[34];
              local_808._3_1_ = s_No_matching_session_id_for_resub_0005dc90[35];
              uStack_804._0_1_ = s_No_matching_session_id_for_resub_0005dc90[36];
              uStack_804._1_1_ = s_No_matching_session_id_for_resub_0005dc90[37];
              uStack_804._2_1_ = s_No_matching_session_id_for_resub_0005dc90[38];
              uStack_804._3_1_ = s_No_matching_session_id_for_resub_0005dc90[39];
              uStack_800._0_1_ = s_No_matching_session_id_for_resub_0005dc90[40];
              uStack_800._1_1_ = s_No_matching_session_id_for_resub_0005dc90[41];
              uStack_800._2_1_ = s_No_matching_session_id_for_resub_0005dc90[42];
              uStack_800._3_1_ = s_No_matching_session_id_for_resub_0005dc90[43];
              uStack_7fc._0_1_ = s_No_matching_session_id_for_resub_0005dc90[44];
              uStack_7fc._1_1_ = s_No_matching_session_id_for_resub_0005dc90[45];
              uStack_7fc._2_1_ = s_No_matching_session_id_for_resub_0005dc90[46];
              uStack_7fc._3_1_ = s_No_matching_session_id_for_resub_0005dc90[47];
              local_7f8._0_1_ = s_No_matching_session_id_for_resub_0005dc90[48];
              local_7f8._1_1_ = s_No_matching_session_id_for_resub_0005dc90[49];
              local_7f8._2_1_ = s_No_matching_session_id_for_resub_0005dc90[50];
              local_7f8._3_1_ = s_No_matching_session_id_for_resub_0005dc90[51];
              local_7f4 = (undefined2)ram0x0005dcc4;
              _applog(7,&local_828,0);
              break;
            }
            iVar5 = pthread_rwlock_unlock(__rwlock);
            if (iVar5 != 0) goto LAB_000248cc;
            (*selective_yield)();
            sleep(2);
          }
          if (opt_debug != 0) {
            if (use_syslog == '\0') {
LAB_000249e4:
              if ((opt_log_output == '\0') && (opt_log_level < 7)) goto LAB_00024a24;
            }
            local_828._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[0];
            local_828._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[1];
            local_828._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[2];
            local_828._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[3];
            uStack_824._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[4];
            uStack_824._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[5];
            uStack_824._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[6];
            uStack_824._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[7];
            uStack_820._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[8];
            uStack_820._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[9];
            uStack_820._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[10];
            uStack_820._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[11];
            uStack_81c._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[12];
            uStack_81c._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[13];
            uStack_81c._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[14];
            uStack_81c._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[15];
            local_818._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[16];
            local_818._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[17];
            local_818._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[18];
            local_818._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[19];
            uStack_814._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[20];
            uStack_814._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[21];
            uStack_814._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[22];
            uStack_814._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[23];
            uStack_810._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[24];
            uStack_810._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[25];
            uStack_810._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[26];
            uStack_810._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[27];
            local_80c._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[28];
            local_80c._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[29];
            local_80c._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[30];
            local_80c._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[31];
            local_808._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[32];
            local_808._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[33];
            local_808._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[34];
            local_808._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[35];
            uStack_804._0_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[36];
            uStack_804._1_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[37];
            uStack_804._2_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[38];
            uStack_804._3_1_ = s_Failed_to_submit_stratum_share__d_0005dcc8[39];
            uStack_800._0_3_ = (undefined3)ram0x0005dcf0;
            _applog(7,&local_828,0);
          }
LAB_00024a24:
          _free_work(&local_c68,"cgminer.c",DAT_00024afc,0x1dfe);
          free(__ptr);
          bVar29 = 0xfffffffe < (uint)total_stale;
          total_stale._0_4_ = (uint)total_stale + 1;
          total_stale._4_4_ = total_stale._4_4_ + (uint)bVar29;
          param_1[0x1e] = param_1[0x1e] + 1;
        }
      }
      else {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
LAB_000247d2:
          if (2 < opt_log_level) goto LAB_00024790;
        }
        else {
          snprintf((char *)&local_828,0x800,
                   "Pool %d asking for inappropriately long nonce2 length %d",*param_1,
                   local_c68[0x4c]);
          _applog(3,&local_828,0);
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000247d2;
LAB_00024790:
          local_828._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[0];
          local_828._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[1];
          local_828._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[2];
          local_828._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[3];
          uStack_824._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[4];
          uStack_824._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[5];
          uStack_824._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[6];
          uStack_824._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[7];
          uStack_820._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[8];
          uStack_820._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[9];
          uStack_820._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[10];
          uStack_820._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[11];
          uStack_81c._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[12];
          uStack_81c._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[13];
          uStack_81c._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[14];
          uStack_81c._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[15];
          local_818._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[16];
          local_818._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[17];
          local_818._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[18];
          local_818._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[19];
          uStack_814._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[20];
          uStack_814._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[21];
          uStack_814._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[22];
          uStack_814._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[23];
          uStack_810._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[24];
          uStack_810._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[25];
          uStack_810._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[26];
          uStack_810._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[27];
          local_80c._0_1_ = s_Not_attempting_to_submit_shares_0005dab8[28];
          local_80c._1_1_ = s_Not_attempting_to_submit_shares_0005dab8[29];
          local_80c._2_1_ = s_Not_attempting_to_submit_shares_0005dab8[30];
          local_80c._3_1_ = s_Not_attempting_to_submit_shares_0005dab8[31];
          _applog(3,&local_828,0);
        }
        _free_work(&local_c68,"cgminer.c",DAT_00024820,0x1d8d);
        iVar13 = iVar23;
        iVar19 = iVar15;
        iVar25 = iVar2;
      }
LAB_000245fc:
      iVar5 = param_1[0xb6];
      cVar1 = *(char *)((int)param_1 + 0x69);
      iVar15 = iVar19;
      iVar23 = iVar13;
      iVar2 = iVar25;
    }
    puVar26 = &local_828;
    pcVar17 = "Stratum q returned empty work";
    local_c68 = (int *)0x0;
  }
  uVar12 = *(undefined4 *)((int)pcVar17 + 4);
  uVar16 = *(undefined4 *)((int)pcVar17 + 8);
  uVar24 = *(undefined4 *)((int)pcVar17 + 0xc);
  *puVar26 = *(undefined4 *)pcVar17;
  puVar26[1] = uVar12;
  puVar26[2] = uVar16;
  puVar26[3] = uVar24;
  uVar12 = *(undefined4 *)((int)pcVar17 + 0x14);
  uVar16 = *(undefined4 *)((int)pcVar17 + 0x18);
  uVar24 = *(undefined4 *)((int)pcVar17 + 0x1c);
  puVar26[4] = *(undefined4 *)((int)pcVar17 + 0x10);
  puVar26[5] = uVar12;
  puVar26[6] = uVar16;
  *(short *)(puVar26 + 7) = (short)uVar24;
  _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

