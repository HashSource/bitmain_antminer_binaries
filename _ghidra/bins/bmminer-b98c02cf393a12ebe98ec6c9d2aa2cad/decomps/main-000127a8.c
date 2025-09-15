
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void main(int param_1,int *param_2)

{
  undefined2 uVar1;
  bool bVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *__src;
  size_t sVar8;
  byte *pbVar9;
  void *pvVar10;
  FILE *pFVar11;
  int *piVar12;
  size_t sVar13;
  __sighandler_t p_Var14;
  __sighandler_t p_Var15;
  __pid_t _Var16;
  pthread_mutex_t *__mutex;
  code *pcVar17;
  code *pcVar18;
  code *extraout_r2;
  code *pcVar19;
  uint uVar20;
  code **extraout_r3;
  code **ppcVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  int iVar26;
  undefined1 *puVar27;
  int *piVar28;
  int iVar29;
  undefined4 *puVar30;
  byte *pbVar31;
  int *piVar32;
  int iVar33;
  undefined4 *puVar34;
  int *piVar35;
  undefined1 *puVar36;
  undefined1 *puVar37;
  char *pcVar38;
  bool bVar39;
  char acStack_2a00 [4104];
  char local_19f8 [4088];
  char *local_a00;
  char **local_9f0;
  code *local_9ec;
  byte *local_9e8;
  int *local_9e4;
  int *local_9e0;
  int *local_9dc;
  int *local_9d8;
  code *local_9d4;
  int *local_9d0;
  byte *local_9cc;
  undefined4 *local_9c8;
  int *local_9c4;
  char *local_9c0;
  int local_9bc;
  int local_9b8;
  _union_1051 local_9b4;
  sigset_t sStack_9b0;
  int local_930;
  char acStack_928 [256];
  int local_828;
  int local_824;
  char acStack_820 [8];
  int local_818;
  undefined4 local_814;
  char local_810 [8];
  undefined4 local_808;
  uint local_804;
  uint local_800;
  undefined4 uStack_7fc;
  undefined2 local_7f8;
  
  g_logfile_path[0] = 'b';
  g_logfile_path[1] = 'm';
  g_logfile_path[2] = 'm';
  g_logfile_path[3] = 'i';
  g_logfile_path[8] = 'l';
  g_logfile_path[9] = 'o';
  g_logfile_path[10] = 'g';
  g_logfile_path[0xb] = '\0';
  local_9e4 = (int *)&g_logfile_enable;
  g_logfile_path[4] = 'n';
  g_logfile_path[5] = 'e';
  g_logfile_path[6] = 'r';
  g_logfile_path[7] = '.';
  g_logfile_openflag._0_2_ = 0x2b61;
  g_logfile_openflag[2] = 0;
  g_logfile_enable = 0;
  local_9b8 = 0;
  local_9ec = (code *)g_logfile_openflag;
  local_9d8 = param_2;
  local_9bc = param_1;
  lVar4 = sysconf(0x54);
  pcVar19 = extraout_r2;
  ppcVar21 = extraout_r3;
  if (lVar4 == 1) {
    ppcVar21 = &selective_yield;
    pcVar19 = sched_yield;
  }
  if (lVar4 == 1) {
    *ppcVar21 = pcVar19;
  }
  local_9c8 = &opt_logfile_path;
  iVar5 = _cgmalloc((local_9bc + 1) * 4,"cgminer.c",&__func___15840,0x2cc3);
  initial_args = iVar5;
  if (0 < local_9bc) {
    puVar30 = (undefined4 *)(iVar5 + -4);
    iVar24 = 0;
    piVar28 = local_9d8 + -1;
    do {
      piVar28 = piVar28 + 1;
      iVar24 = iVar24 + 1;
      uVar6 = __strdup(*piVar28);
      puVar30 = puVar30 + 1;
      *puVar30 = uVar6;
    } while (iVar24 < local_9bc);
  }
  *(undefined4 *)(iVar5 + local_9bc * 4) = 0;
  _mutex_init_constprop_66(hash_lock,&__func___15840,0x2ccc);
  _mutex_init_constprop_66(update_job_lock,&__func___15840,0x2ccd);
  _mutex_init_constprop_66(console_lock,&__func___15840,0x2cce);
  _cglock_init_constprop_65(control_lock,&__func___15840,0x2ccf);
  _mutex_init_constprop_66(stats_lock,&__func___15840,0x2cd0);
  local_9d4 = (code *)(bench_lodiff_bins + 0x124);
  _mutex_init_constprop_66(sharelog_lock,&__func___15840,0x2cd1);
  _cglock_init_constprop_65(ch_lock,&__func___15840,0x2cd2);
  _mutex_init_constprop_66(sshare_lock,&__func___15840,0x2cd3);
  _rwlock_init_constprop_68(blk_lock,&__func___15840,0x2cd4);
  _rwlock_init_constprop_68(netacc_lock,&__func___15840,0x2cd5);
  _rwlock_init_constprop_68(mining_thr_lock,&__func___15840,0x2cd6);
  _rwlock_init_constprop_68(devices_lock,&__func___15840,0x2cd7);
  _mutex_init_constprop_66(lp_lock,&__func___15840,0x2cd9);
  iVar5 = pthread_cond_init((pthread_cond_t *)lp_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    local_828._0_1_ = 'F';
    local_828._1_1_ = 'a';
    local_828._2_1_ = 'i';
    local_828._3_1_ = 'l';
    local_824._0_1_ = 'e';
    local_824._1_1_ = 'd';
    local_824._2_1_ = ' ';
    local_824._3_1_ = 't';
    builtin_strncpy(acStack_820,"o pthrea",8);
    local_818._0_1_ = 'd';
    local_818._1_1_ = '_';
    local_818._2_1_ = 'c';
    local_818._3_1_ = 'o';
    local_814._0_1_ = 'n';
    local_814._1_1_ = 'd';
    local_814._2_1_ = '_';
    local_814._3_1_ = 'i';
    builtin_strncpy(local_810,"nit lp_c",8);
    local_808._0_1_ = 'o';
    local_808._1_1_ = 'n';
    local_808._2_1_ = 'd';
    local_808._3_1_ = '\0';
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  _mutex_init_constprop_66(restart_lock,&__func___15840,0x2ce0);
  iVar5 = pthread_cond_init((pthread_cond_t *)restart_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    local_828._0_1_ = 'F';
    local_828._1_1_ = 'a';
    local_828._2_1_ = 'i';
    local_828._3_1_ = 'l';
    local_824._0_1_ = 'e';
    local_824._1_1_ = 'd';
    local_824._2_1_ = ' ';
    local_824._3_1_ = 't';
    builtin_strncpy(acStack_820,"o pthrea",8);
    local_818._0_1_ = 'd';
    local_818._1_1_ = '_';
    local_818._2_1_ = 'c';
    local_818._3_1_ = 'o';
    local_814._0_1_ = 'n';
    local_814._1_1_ = 'd';
    local_814._2_1_ = '_';
    local_814._3_1_ = 'i';
    builtin_strncpy(local_810,"nit rest",8);
    local_808._0_1_ = 'a';
    local_808._1_1_ = 'r';
    local_808._2_1_ = 't';
    local_808._3_1_ = '_';
    local_804._0_1_ = 'c';
    local_804._1_1_ = 'o';
    local_804._2_1_ = 'n';
    local_804._3_1_ = 'd';
    local_800 = local_800 & 0xffffff00;
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  iVar5 = pthread_cond_init((pthread_cond_t *)gws_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    builtin_strncpy(acStack_820,"o pthrea",8);
    local_818._0_1_ = 'd';
    local_818._1_1_ = '_';
    local_818._2_1_ = 'c';
    local_818._3_1_ = 'o';
    local_814._0_1_ = 'n';
    local_814._1_1_ = 'd';
    local_814._2_1_ = '_';
    local_814._3_1_ = 'i';
    builtin_strncpy(local_810,"nit gws_",8);
    local_808._0_1_ = 'c';
    local_808._1_1_ = 'o';
    local_808._2_1_ = 'n';
    local_808._3_1_ = 'd';
    local_804 = local_804 & 0xffffff00;
LAB_000138f6:
    local_824._0_1_ = 'e';
    local_824._1_1_ = 'd';
    local_824._2_1_ = ' ';
    local_824._3_1_ = 't';
    local_828._0_1_ = 'F';
    local_828._1_1_ = 'a';
    local_828._2_1_ = 'i';
    local_828._3_1_ = 'l';
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  getq = tq_new();
  if (getq == 0) {
    acStack_820[0] = 'o';
    acStack_820[1] = ' ';
    acStack_820[2] = 'c';
    acStack_820[3] = 'r';
    acStack_820[4] = 'e';
    acStack_820[5] = 'a';
    acStack_820[6] = 't';
    acStack_820[7] = 'e';
    local_818._0_1_ = ' ';
    local_818._1_1_ = 'g';
    local_818._2_1_ = 'e';
    local_818._3_1_ = 't';
    local_814._0_2_ = 0x71;
    getq = 0;
    goto LAB_000138f6;
  }
  local_a00 = "2.0.0";
  local_9c8[0x117] = getq + 0xc;
  snprintf(packagename,0x100,"%s %s","bmminer");
  local_9b4 = (_union_1051)0x1de6d;
  local_930 = iVar5;
  sigemptyset(&sStack_9b0);
  sigaction(0xf,(sigaction *)&local_9b4,(sigaction *)termhandler);
  sigaction(2,(sigaction *)&local_9b4,(sigaction *)inthandler);
  sigaction(6,(sigaction *)&local_9b4,(sigaction *)abrthandler);
  opt_kernel_path = local_19f8;
  builtin_strncpy(local_19f8,"/usr/bin",8);
  cgminer_path = acStack_2a00;
  local_19f8[8] = 0;
  local_9e8 = (byte *)0x5c810;
  local_9f0 = &opt_kernel_path;
  pcVar7 = (char *)__strdup(*local_9d8);
  pcVar38 = cgminer_path;
  __src = dirname(pcVar7);
  strcpy(pcVar38,__src);
  free(pcVar7);
  pcVar38 = cgminer_path;
  iVar5 = 0x24;
  sVar8 = strlen(cgminer_path);
  *(undefined2 *)(pcVar38 + sVar8) = *(undefined2 *)local_9e8;
  *(undefined4 *)(local_9d4 + 0xa78) = 9;
  pbVar9 = (byte *)_cgcalloc(0x68,1,"cgminer.c",&__func___15840,0x2d0f);
  local_9cc = pbVar9;
  do {
    sVar8 = strlen((char *)pbVar9);
    pbVar31 = local_9cc;
    iVar5 = iVar5 + -1;
    (pbVar9 + sVar8)[0] = '0';
    (pbVar9 + sVar8)[1] = '\0';
  } while (iVar5 != 0);
  uVar22 = 0x9e3779b9;
  uVar25 = 0xfeedbeef;
  local_9c0 = (char *)(sVar8 + 1);
  uVar20 = uVar22;
  pbVar9 = local_9cc;
  for (pcVar38 = local_9c0; (char *)0xb < pcVar38; pcVar38 = pcVar38 + -0xc) {
    iVar5 = uVar20 + (uint)pbVar9[6] * 0x10000 + (uint)pbVar9[5] * 0x100 + (uint)pbVar9[4] +
                     (uint)pbVar9[7] * 0x1000000;
    uVar25 = (uint)pbVar9[10] * 0x10000 + (uint)pbVar9[9] * 0x100 + (uint)pbVar9[8] +
             (uint)pbVar9[0xb] * 0x1000000 + uVar25;
    uVar20 = ((((uint)*pbVar9 + (uint)pbVar9[2] * 0x10000 + (uint)pbVar9[1] * 0x100 +
               (uint)pbVar9[3] * 0x1000000) - iVar5) - uVar25) + uVar22 ^ uVar25 >> 0xd;
    uVar22 = (iVar5 - uVar25) - uVar20 ^ uVar20 << 8;
    uVar23 = (uVar25 - uVar20) - uVar22 ^ uVar22 >> 0xd;
    uVar25 = (uVar20 - uVar22) - uVar23 ^ uVar23 >> 0xc;
    uVar20 = (uVar22 - uVar23) - uVar25 ^ uVar25 << 0x10;
    uVar23 = (uVar23 - uVar25) - uVar20 ^ uVar20 >> 5;
    uVar22 = (uVar25 - uVar20) - uVar23 ^ uVar23 >> 3;
    uVar20 = (uVar20 - uVar23) - uVar22 ^ uVar22 << 10;
    uVar25 = (uVar23 - uVar22) - uVar20 ^ uVar20 >> 0xf;
    pbVar9 = pbVar9 + 0xc;
  }
  pcVar7 = local_9c0 + uVar25;
  switch(pcVar38) {
  case (char *)0xb:
    pcVar7 = pcVar7 + (uint)pbVar9[10] * 0x1000000;
  case (char *)0xa:
    pcVar7 = pcVar7 + (uint)pbVar9[9] * 0x10000;
  case (char *)0x9:
    pcVar7 = pcVar7 + (uint)pbVar9[8] * 0x100;
  case (char *)0x8:
    uVar20 = uVar20 + (uint)pbVar9[7] * 0x1000000;
  case (char *)0x7:
    uVar20 = uVar20 + (uint)pbVar9[6] * 0x10000;
  case (char *)0x6:
    uVar20 = uVar20 + (uint)pbVar9[5] * 0x100;
  case (char *)0x5:
    uVar20 = uVar20 + pbVar9[4];
  case (char *)0x4:
    uVar22 = uVar22 + (uint)pbVar9[3] * 0x1000000;
  case (char *)0x3:
    uVar22 = uVar22 + (uint)pbVar9[2] * 0x10000;
  case (char *)0x2:
    uVar22 = uVar22 + (uint)pbVar9[1] * 0x100;
  case (char *)0x1:
    uVar22 = uVar22 + *pbVar9;
  }
  *(byte **)(local_9cc + 0x58) = local_9cc;
  uVar25 = (uVar22 - uVar20) - (int)pcVar7 ^ (uint)pcVar7 >> 0xd;
  uVar23 = (uVar20 - (int)pcVar7) - uVar25 ^ uVar25 << 8;
  uVar22 = (uint)(pcVar7 + (-uVar23 - uVar25)) ^ uVar23 >> 0xd;
  uVar20 = (uVar25 - uVar23) - uVar22 ^ uVar22 >> 0xc;
  uVar25 = (uVar23 - uVar22) - uVar20 ^ uVar20 << 0x10;
  uVar22 = (uVar22 - uVar20) - uVar25 ^ uVar25 >> 5;
  uVar20 = (uVar20 - uVar25) - uVar22 ^ uVar22 >> 3;
  uVar25 = (uVar25 - uVar22) - uVar20 ^ uVar20 << 10;
  uVar22 = (uVar22 - uVar20) - uVar25 ^ uVar25 >> 0xf;
  *(uint *)(local_9cc + 0x60) = uVar22;
  sVar8 = strlen((char *)local_9cc);
  *(size_t *)(pbVar31 + 0x5c) = sVar8;
  iVar5 = *(int *)(local_9d4 + 0xa08);
  if (iVar5 == 0) {
    pbVar31[0x4c] = 0;
    pbVar31[0x4d] = 0;
    pbVar31[0x4e] = 0;
    pbVar31[0x4f] = 0;
    pbVar31[0x48] = 0;
    pbVar31[0x49] = 0;
    pbVar31[0x4a] = 0;
    pbVar31[0x4b] = 0;
    *(byte **)(local_9d4 + 0xa08) = pbVar31;
    pvVar10 = malloc(0x2c);
    pbVar9 = local_9cc;
    *(void **)(pbVar31 + 0x44) = pvVar10;
    if (pvVar10 == (void *)0x0) goto LAB_00013946;
    memset(pvVar10,0,0x2c);
    pbVar31 = pbVar9 + 0x44;
    puVar30 = *(undefined4 **)pbVar31;
    puVar30[4] = pbVar31;
    puVar30[1] = 0x20;
    puVar30[2] = 5;
    puVar30[5] = 0x44;
    pvVar10 = malloc(0x180);
    *puVar30 = pvVar10;
    if (pvVar10 == (void *)0x0) goto LAB_00013946;
    memset(pvVar10,0,0x180);
    *(undefined4 *)(*(int *)(pbVar9 + 0x44) + 0x28) = 0xa0111fe1;
  }
  else {
    *(undefined4 *)(local_9cc + 0x44) = *(undefined4 *)(iVar5 + 0x44);
    pbVar31 = local_9cc + 0x44;
    iVar24 = *(int *)(iVar5 + 0x44);
    local_9cc[0x4c] = 0;
    local_9cc[0x4d] = 0;
    local_9cc[0x4e] = 0;
    local_9cc[0x4f] = 0;
    iVar5 = *(int *)(iVar24 + 0x10);
    *(int *)(local_9cc + 0x48) = iVar5 - *(int *)(iVar24 + 0x14);
    *(byte **)(iVar5 + 8) = local_9cc;
    *(byte **)(iVar24 + 0x10) = pbVar31;
  }
  pbVar9 = local_9cc;
  piVar28 = *(int **)(*(int *)(local_9d4 + 0xa08) + 0x44);
  iVar24 = *piVar28;
  piVar28[3] = piVar28[3] + 1;
  iVar5 = (uVar22 & piVar28[1] - 1U) * 0xc;
  iVar26 = iVar24 + iVar5;
  iVar29 = *(int *)(iVar24 + iVar5);
  uVar22 = *(int *)(iVar26 + 4) + 1;
  *(uint *)(iVar26 + 4) = uVar22;
  *(int *)(local_9cc + 0x54) = iVar29;
  local_9cc[0x50] = 0;
  local_9cc[0x51] = 0;
  local_9cc[0x52] = 0;
  local_9cc[0x53] = 0;
  if (iVar29 != 0) {
    *(byte **)(iVar29 + 0xc) = pbVar31;
  }
  iVar26 = *(int *)(iVar26 + 8);
  *(byte **)(iVar24 + iVar5) = pbVar31;
  if (((uint)((iVar26 + 1) * 10) <= uVar22) && (*(int *)(*(int *)(local_9cc + 0x44) + 0x24) != 1)) {
    pvVar10 = calloc(*(int *)(*(int *)(local_9cc + 0x44) + 4) * 0x18,1);
    if (pvVar10 == (void *)0x0) {
LAB_00013946:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    puVar30 = *(undefined4 **)(pbVar9 + 0x44);
    iVar5 = puVar30[1];
    puVar30[7] = 0;
    local_9c0 = (char *)(iVar5 * 2 + -1);
    uVar22 = (uint)puVar30[3] >> (puVar30[2] + 1 & 0xff);
    if ((puVar30[3] & (uint)local_9c0) != 0) {
      uVar22 = uVar22 + 1;
    }
    puVar30[6] = uVar22;
    if (iVar5 != 0) {
      local_9e0 = (int *)*puVar30;
      local_9dc = (int *)(iVar5 * 0xc);
      piVar28 = (int *)0x0;
      local_9d0 = (int *)0x0;
      do {
        iVar5 = *(int *)((int)local_9e0 + (int)local_9d0);
        while (iVar5 != 0) {
          iVar24 = *(int *)(iVar5 + 0x10);
          uVar25 = *(uint *)(iVar5 + 0x1c) & (uint)local_9c0;
          uVar20 = *(int *)((int)pvVar10 + uVar25 * 0xc + 4) + 1;
          *(uint *)((int)pvVar10 + uVar25 * 0xc + 4) = uVar20;
          if (uVar22 < uVar20) {
            puVar30[7] = puVar30[7] + 1;
            local_9c4 = piVar28;
            uVar6 = __udivsi3(uVar20,uVar22);
            *(undefined4 *)((int)pvVar10 + uVar25 * 0xc + 8) = uVar6;
            piVar28 = local_9c4;
          }
          iVar26 = *(int *)((int)pvVar10 + uVar25 * 0xc);
          *(int **)(iVar5 + 0xc) = piVar28;
          *(int *)(iVar5 + 0x10) = iVar26;
          if (iVar26 != 0) {
            *(int *)(iVar26 + 0xc) = iVar5;
          }
          *(int *)((int)pvVar10 + uVar25 * 0xc) = iVar5;
          iVar5 = iVar24;
        }
        local_9d0 = local_9d0 + 3;
      } while (local_9dc != local_9d0);
    }
    free((void *)*puVar30);
    puVar30 = *(undefined4 **)(local_9cc + 0x44);
    *puVar30 = pvVar10;
    puVar30[2] = puVar30[2] + 1;
    puVar30[1] = puVar30[1] << 1;
    if ((uint)puVar30[3] >> 1 < (uint)puVar30[7]) {
      uVar20 = puVar30[8] + 1;
      puVar30[8] = uVar20;
      uVar22 = uVar20;
      if (1 < uVar20) {
        uVar22 = 1;
      }
      if (1 < uVar20) {
        puVar30[9] = uVar22;
      }
    }
    else {
      puVar30[8] = 0;
    }
  }
  strcpy(current_hash,(char *)local_9cc);
  scan_devices._0_4_ = &scan_devices;
  scan_devices._4_4_ = &scan_devices;
  opt_register_table(&opt_config_table,"Options for both config file and command line");
  opt_register_table(opt_cmdline_table,"Options for command line only");
  opt_parse(&local_9bc,local_9d8,0x1bda5);
  if (local_9bc != 1) {
    local_828._0_1_ = 'U';
    local_828._1_1_ = 'n';
    local_828._2_1_ = 'e';
    local_828._3_1_ = 'x';
    local_824._0_1_ = 'p';
    local_824._1_1_ = 'e';
    local_824._2_1_ = 'c';
    local_824._3_1_ = 't';
    builtin_strncpy(acStack_820,"ed extra",8);
    local_818._0_1_ = ' ';
    local_818._1_1_ = 'c';
    local_818._2_1_ = 'o';
    local_818._3_1_ = 'm';
    local_814._0_1_ = 'm';
    local_814._1_1_ = 'a';
    local_814._2_1_ = 'n';
    local_814._3_1_ = 'd';
    builtin_strncpy(local_810,"line arg",8);
    local_808._0_1_ = 'u';
    local_808._1_1_ = 'm';
    local_808._2_1_ = 'e';
    local_808._3_1_ = 'n';
    local_804 = CONCAT13(local_804._3_1_,0x7374);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  if (*(char *)(local_9c8 + 0xd3) == '\0') {
    uVar6 = _cgmalloc(0x1000,"cgminer.c","load_default_config",0x829);
    puVar30 = local_9c8;
    local_9c8[0xd1] = uVar6;
    default_save_file();
    iVar5 = access((char *)puVar30[0xd1],4);
    puVar30 = local_9c8;
    if (iVar5 == 0) {
      load_config(local_9c8[0xd1],0);
    }
    else {
      free((void *)local_9c8[0xd1]);
      puVar30[0xd1] = 0;
    }
  }
  if ((*(char *)(local_9c8 + 0x160) != '\0') || (local_9c8[0x113] != 0)) {
    iVar5 = add_pool();
    puVar30 = (undefined4 *)_cgmalloc(0xff,"cgminer.c",&__func___15840,0x2d33);
    *(undefined4 **)(iVar5 + 0xa4) = puVar30;
    if (local_9c8[0x113] == 0) {
      pcVar38 = "Benchmark";
    }
    else {
      pcVar38 = "Benchfile";
    }
    uVar6 = *(undefined4 *)(pcVar38 + 4);
    uVar1 = *(undefined2 *)(pcVar38 + 8);
    *puVar30 = *(undefined4 *)pcVar38;
    puVar30[1] = uVar6;
    *(undefined2 *)(puVar30 + 2) = uVar1;
    uVar6 = *(undefined4 *)(iVar5 + 0xa4);
    *(undefined4 *)(iVar5 + 0xac) = uVar6;
    *(undefined4 *)(iVar5 + 0xb0) = uVar6;
    *(undefined4 *)(iVar5 + 0xa8) = uVar6;
    *(undefined4 *)(iVar5 + 600) = uVar6;
    strncpy((char *)(iVar5 + 0x30),"?",7);
    *(undefined1 *)(iVar5 + 0x37) = 0;
    if (*(int *)(iVar5 + 100) != 1) {
      *(undefined4 *)(iVar5 + 100) = 1;
      enabled_pools = enabled_pools + 1;
    }
    puVar27 = bench_lodiff_bins;
    *(undefined1 *)(iVar5 + 0x61) = 0;
    iVar5 = 0;
    successful_connect = 1;
    puVar36 = bench_hidiff_bins;
    do {
      puVar37 = puVar36 + 0xa0;
      hex2bin(puVar36,"000000029c6bf469abe4ad37605c097a860cff3cf5c1ef4377618f74000000000000000082b1514e7b6565941e5824f084292164ec5f97e7ea20c494bd96e524d478977b536dd2261900896c8b10020000000080000000000000000000000000000000000000000000000000000000000000000000000000000000008002000064e4e3becc01064d808269b330f40f4de82dc92e894d635025daa3e2e2c410b4"
                      + iVar5);
      pcVar38 = "00000002c01f502cb3e9fdb053230ec12a4954c1021a6b35862b5e29000000000000000084d1b83ae44057025e8c5b5756b44f04df5fffe4a7a30e5c12d12a97a7a4c2ea536dce431900896cb6d60e00000000800000000000000000000000000000000000000000000000000000000000000000000000000000000080020000d08f7e14c50dad77dc238b4db2901a0578e657b1954779ab9cd82a73829edf7f"
                + iVar5;
      iVar5 = iVar5 + 0x144;
      hex2bin(puVar27,pcVar38,0xa0);
      puVar27 = puVar27 + 0xa0;
      puVar36 = puVar37;
    } while (puVar37 != bench_lodiff_bins);
    set_target(0,bench_target);
  }
  if ((char *)local_9c8[4] != (char *)0x0) {
    pFVar11 = fopen((char *)local_9c8[4],"rb");
    memset(acStack_928,0,0x100);
    if (pFVar11 == (FILE *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Open miner version file %s error",local_9c8[4]);
        _applog(3,&local_828,0);
        goto LAB_000130d0;
      }
LAB_0001391a:
      if (opt_log_level < 3) goto LAB_0001310e;
    }
    else {
      sVar8 = fread(acStack_928,1,0x100,pFVar11);
      if ((int)sVar8 < 1) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
        goto LAB_0001391a;
        snprintf((char *)&local_828,0x800,"Read miner version file %s error %d",local_9c8[4],sVar8);
        _applog(3,&local_828,0);
      }
      else {
        pcVar38 = strchr(acStack_928,10);
        if (pcVar38 == (char *)0x0) {
          strcpy(g_miner_compiletime,acStack_928);
        }
        else {
          _cg_memcpy(g_miner_compiletime,acStack_928,(int)pcVar38 - (int)acStack_928,"cgminer.c",
                     &__func___15840,0x2d6e);
          pcVar38 = stpcpy(acStack_928,pcVar38 + 1);
          pcVar7 = strchr(acStack_928,10);
          if (pcVar7 == (char *)0x0) {
            memcpy(g_miner_type,acStack_928,(size_t)(pcVar38 + (1 - (int)acStack_928)));
          }
          else {
            _cg_memcpy(g_miner_type,acStack_928,(int)pcVar7 - (int)acStack_928,"cgminer.c",
                       &__func___15840,0x2d77);
          }
        }
        sVar8 = strlen(g_miner_compiletime);
        if (local_9d4[sVar8 + 0xa7b] == (code)0xa) {
          local_9d4[sVar8 + 0xa7b] = (code)0x0;
        }
        sVar8 = strlen(g_miner_compiletime);
        if (local_9d4[sVar8 + 0xa7b] == (code)0xd) {
          local_9d4[sVar8 + 0xa7b] = (code)0x0;
        }
        sVar8 = strlen(g_miner_type);
        if (local_9d4[sVar8 + 0xb7b] == (code)0xa) {
          local_9d4[sVar8 + 0xb7b] = (code)0x0;
        }
        sVar8 = strlen(g_miner_type);
        if (local_9d4[sVar8 + 0xb7b] == (code)0xd) {
          local_9d4[sVar8 + 0xb7b] = (code)0x0;
        }
      }
LAB_000130d0:
      if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_0001391a;
    }
    snprintf((char *)&local_828,0x800,"Miner compile time: %s type: %s",g_miner_compiletime,
             g_miner_type);
    _applog(3,&local_828,0);
  }
LAB_0001310e:
  puVar30 = local_9c8;
  pcVar38 = (char *)*local_9c8;
  if (pcVar38 == (char *)0x0) {
LAB_00013190:
    iVar5 = local_9c8[2];
    if (iVar5 == 0) {
      local_9c0 = &opt_log_output;
    }
    else {
LAB_0001319a:
      memset(acStack_928,0,0x100);
      pcVar38 = (char *)local_9c8[1];
      if (pcVar38 == (char *)0x0) {
        if (((use_syslog != '\0') || (local_9c0 = &opt_log_output, opt_log_output != '\0')) ||
           (2 < opt_log_level)) {
          local_9c0 = &opt_log_output;
          snprintf((char *)&local_828,0x800,"Log work path: %s",iVar5);
          _applog(3,&local_828,0);
        }
      }
      else {
        if (*pcVar38 == '\0') {
          piVar28 = &local_828;
          pcVar38 = "Log work asic num empty";
LAB_00013288:
          iVar5 = *(int *)((int)pcVar38 + 4);
          iVar24 = *(int *)((int)pcVar38 + 8);
          iVar26 = *(int *)((int)pcVar38 + 0xc);
          *piVar28 = *(int *)pcVar38;
          piVar28[1] = iVar5;
          piVar28[2] = iVar24;
          piVar28[3] = iVar26;
          iVar5 = *(int *)((int)pcVar38 + 0x14);
          piVar28[4] = *(int *)((int)pcVar38 + 0x10);
          piVar28[5] = iVar5;
          piVar32 = &local_828;
LAB_0001329a:
          _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
          __quit(1);
        }
        lVar4 = strtol(pcVar38,(char **)0x0,10);
        *(long *)(local_9d4 + 0xc7c) = lVar4;
        if (((lVar4 - 0x20U & 0xffffffdf) != 0) && (lVar4 != 1)) {
          local_828._0_1_ = 'L';
          local_828._1_1_ = 'o';
          local_828._2_1_ = 'g';
          local_828._3_1_ = ' ';
          local_824._0_1_ = 'w';
          local_824._1_1_ = 'o';
          local_824._2_1_ = 'r';
          local_824._3_1_ = 'k';
          builtin_strncpy(acStack_820," asic nu",8);
          local_818._0_1_ = 'm';
          local_818._1_1_ = ' ';
          local_818._2_1_ = 'm';
          local_818._3_1_ = 'u';
          local_814._0_1_ = 's';
          local_814._1_1_ = 't';
          local_814._2_1_ = ' ';
          local_814._3_1_ = 'b';
          builtin_strncpy(local_810,"e 1, 32,",8);
          local_808._0_1_ = ' ';
          local_808._1_1_ = '6';
          local_808._2_1_ = '4';
          local_808._3_1_ = '\0';
          _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
          __quit(1);
        }
        if (((use_syslog != '\0') || (local_9c0 = &opt_log_output, opt_log_output != '\0')) ||
           (2 < opt_log_level)) {
          local_9c0 = &opt_log_output;
          snprintf((char *)&local_828,0x800,"Log work path: %s Asic num: %s",local_9c8[2],
                   local_9c8[1]);
          _applog(3,&local_828,0);
        }
      }
      sprintf(acStack_928,"%s.txt",local_9c8[2]);
      pFVar11 = fopen(acStack_928,"a+");
      cVar3 = use_syslog;
      *(FILE **)(local_9d4 + 0xc80) = pFVar11;
      if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Log work open file %s",acStack_928);
        _applog(3,&local_828,0);
      }
      puVar30 = local_9c8;
      pcVar19 = local_9d4;
      iVar5 = *(int *)(local_9d4 + 0xc7c);
      if (iVar5 == 1) {
        sprintf(acStack_928,"%s%02d.txt",local_9c8[2]);
        pFVar11 = fopen(acStack_928,"a+");
        cVar3 = use_syslog;
        *(FILE **)(local_9d4 + 0xc84) = pFVar11;
        if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
          snprintf((char *)&local_828,0x800,"Log work open asic %d file %s",
                   *(undefined4 *)(local_9d4 + 0xc7c),acStack_928);
          _applog(3,&local_828,0);
        }
      }
      else if (((iVar5 - 0x20U & 0xffffffdf) == 0) && (-1 < iVar5)) {
        local_9c4 = (int *)0x5e9e4;
        local_9cc = (byte *)&DAT_0005e760;
        puVar34 = &g_logwork_file;
        local_9d0 = (int *)0x5e9c4;
        iVar24 = 0;
        do {
          sprintf(acStack_928,(char *)local_9c4,puVar30[2],iVar5,iVar24);
          pFVar11 = fopen(acStack_928,(char *)local_9cc);
          cVar3 = use_syslog;
          puVar34 = puVar34 + 1;
          *puVar34 = pFVar11;
          if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,(char *)local_9d0,*(undefined4 *)(pcVar19 + 0xc7c),
                     acStack_928);
            _applog(3,&local_828,0);
          }
          iVar5 = *(int *)(pcVar19 + 0xc7c);
          iVar24 = iVar24 + 1;
        } while (iVar24 <= iVar5);
      }
      if (local_9d4[0xd88] != (code)0x0) {
        puVar30 = (undefined4 *)&opt_logwork_diff;
        iVar5 = 0;
        local_9c4 = (int *)0x5ea08;
        do {
          sprintf(acStack_928,"%s_diff_%02d.txt",local_9c8[2],iVar5);
          pFVar11 = fopen(acStack_928,"a+");
          cVar3 = use_syslog;
          puVar30 = puVar30 + 1;
          *puVar30 = pFVar11;
          if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,(char *)local_9c4,acStack_928);
            _applog(3,&local_828,0);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 0x41);
      }
    }
    if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_00013478;
LAB_00013480:
    snprintf((char *)&local_828,0x800,"Started %s",packagename);
    _applog(4,&local_828,0);
    if (local_9c8[0xd1] != 0) {
      if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_0001396c;
LAB_000134bc:
      snprintf((char *)&local_828,0x800,"Loaded configuration file %s");
      _applog(5,&local_828,0);
      iVar5 = local_9c8[0x106];
      if (iVar5 == -1) {
        if (use_syslog == '\0') {
LAB_000136f2:
          if ((*local_9c0 != '\0') || (3 < opt_log_level)) goto LAB_000137c8;
          if (use_curses == '\0') goto LAB_0001353a;
LAB_00013718:
          if (3 < opt_log_level) {
LAB_00013724:
            local_828._0_1_ = 'S';
            local_828._1_1_ = 't';
            local_828._2_1_ = 'a';
            local_828._3_1_ = 'r';
            local_824._0_1_ = 't';
            local_824._1_1_ = ' ';
            local_824._2_1_ = 'c';
            local_824._3_1_ = 'g';
            builtin_strncpy(acStack_820,"miner wi",8);
            local_818._0_1_ = 't';
            local_818._1_1_ = 'h';
            local_818._2_1_ = ' ';
            local_818._3_1_ = '-';
            local_814._0_1_ = 'T';
            local_814._1_1_ = ' ';
            local_814._2_1_ = 't';
            local_814._3_1_ = 'o';
            builtin_strncpy(local_810," see wha",8);
            local_808._0_1_ = 't';
            local_808._1_1_ = ' ';
            local_808._2_1_ = 'f';
            local_808._3_1_ = 'a';
            local_804._0_1_ = 'i';
            local_804._1_1_ = 'l';
            local_804._2_1_ = 'e';
            local_804._3_1_ = 'd';
            local_800._0_1_ = ' ';
            local_800._1_1_ = 't';
            local_800._2_1_ = 'o';
            local_800._3_1_ = ' ';
            uStack_7fc._0_1_ = 'l';
            uStack_7fc._1_1_ = 'o';
            uStack_7fc._2_1_ = 'a';
            uStack_7fc._3_1_ = 'd';
            local_7f8 = 0x2e;
            _applog(4,&local_828,0);
          }
        }
        else {
LAB_000137c8:
          local_828._0_1_ = 'E';
          local_828._1_1_ = 'r';
          local_828._2_1_ = 'r';
          local_828._3_1_ = 'o';
          local_824._0_1_ = 'r';
          local_824._1_1_ = ' ';
          local_824._2_1_ = 'i';
          local_824._3_1_ = 'n';
          builtin_strncpy(acStack_820," configu",8);
          local_818._0_1_ = 'r';
          local_818._1_1_ = 'a';
          local_818._2_1_ = 't';
          local_818._3_1_ = 'i';
          local_814._0_1_ = 'o';
          local_814._1_1_ = 'n';
          local_814._2_1_ = ' ';
          local_814._3_1_ = 'f';
          builtin_strncpy(local_810,"ile, par",8);
          local_808._0_1_ = 't';
          local_808._1_1_ = 'i';
          local_808._2_1_ = 'a';
          local_808._3_1_ = 'l';
          local_804._0_1_ = 'l';
          local_804._1_1_ = 'y';
          local_804._2_1_ = ' ';
          local_804._3_1_ = 'l';
          local_800._0_1_ = 'o';
          local_800._1_1_ = 'a';
          local_800._2_1_ = 'd';
          local_800._3_1_ = 'e';
          uStack_7fc._0_3_ = 0x2e64;
          _applog(4,&local_828,0);
          if (use_curses != '\0') {
            if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_00013718;
            goto LAB_00013724;
          }
        }
      }
      else {
LAB_000134e4:
        if (iVar5 == 0) {
          if (((use_syslog == '\0') && (*local_9c0 == '\0')) && (opt_log_level < 4)) {
LAB_0001350a:
            if (opt_log_level < 4) goto LAB_0001353a;
          }
          else {
            local_828._0_1_ = 'F';
            local_828._1_1_ = 'a';
            local_828._2_1_ = 't';
            local_828._3_1_ = 'a';
            local_824._0_1_ = 'l';
            local_824._1_1_ = ' ';
            local_824._2_1_ = 'J';
            local_824._3_1_ = 'S';
            builtin_strncpy(acStack_820,"ON error",8);
            local_818._0_1_ = ' ';
            local_818._1_1_ = 'i';
            local_818._2_1_ = 'n';
            local_818._3_1_ = ' ';
            local_814._0_1_ = 'c';
            local_814._1_1_ = 'o';
            local_814._2_1_ = 'n';
            local_814._3_1_ = 'f';
            builtin_strncpy(local_810,"iguratio",8);
            local_808._0_1_ = 'n';
            local_808._1_1_ = ' ';
            local_808._2_1_ = 'f';
            local_808._3_1_ = 'i';
            local_804._0_1_ = 'l';
            local_804._1_1_ = 'e';
            local_804._2_1_ = '.';
            local_804._3_1_ = '\0';
            _applog(4,&local_828,0);
            if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_0001350a;
          }
          local_828._0_1_ = 'C';
          local_828._1_1_ = 'o';
          local_828._2_1_ = 'n';
          local_828._3_1_ = 'f';
          local_824._0_1_ = 'i';
          local_824._1_1_ = 'g';
          local_824._2_1_ = 'u';
          local_824._3_1_ = 'r';
          builtin_strncpy(acStack_820,"ation fi",8);
          local_818._0_1_ = 'l';
          local_818._1_1_ = 'e';
          local_818._2_1_ = ' ';
          local_818._3_1_ = 'c';
          local_814._0_1_ = 'o';
          local_814._1_1_ = 'u';
          local_814._2_1_ = 'l';
          local_814._3_1_ = 'd';
          builtin_strncpy(local_810," not be ",8);
          local_808._0_1_ = 'u';
          local_808._1_1_ = 's';
          local_808._2_1_ = 'e';
          local_808._3_1_ = 'd';
          local_804 = CONCAT22(local_804._2_2_,0x2e);
          _applog(4,&local_828,0);
        }
      }
LAB_0001353a:
      puVar30 = local_9c8;
      free((void *)local_9c8[0xd1]);
      puVar30[0xd1] = 0;
    }
  }
  else {
    *(char *)local_9e4 = '\x01';
    strcpy(g_logfile_path,pcVar38);
    if ((char *)puVar30[3] != (char *)0x0) {
      strcpy(g_logfile_openflag,(char *)puVar30[3]);
    }
    if (((use_syslog != '\0') || (local_9c0 = &opt_log_output, opt_log_output != '\0')) ||
       (2 < opt_log_level)) {
      snprintf((char *)&local_828,0x800,"Log file path: %s Open flag: %s",g_logfile_path,local_9ec);
      _applog(3,&local_828,0);
      goto LAB_00013190;
    }
    iVar5 = local_9c8[2];
    if (iVar5 != 0) goto LAB_0001319a;
LAB_00013478:
    if (3 < opt_log_level) goto LAB_00013480;
    if (local_9c8[0xd1] != 0) {
LAB_0001396c:
      if (4 < opt_log_level) goto LAB_000134bc;
      iVar5 = local_9c8[0x106];
      if (iVar5 == -1) goto LAB_000136f2;
      goto LAB_000134e4;
    }
  }
  pcVar38 = *local_9f0;
  sVar8 = strlen(pcVar38);
  *(undefined2 *)(pcVar38 + sVar8) = *(undefined2 *)local_9e8;
  if (want_per_device_stats == '\0') {
    if (*local_9c0 != '\0') goto LAB_00013570;
    setlogmask(0x3f);
  }
  else {
    *local_9c0 = '\x01';
LAB_00013570:
    setlogmask(0xff);
  }
  local_9cc = (byte *)&control_thr;
  if (opt_scantime < 0) {
    opt_scantime = 0x3c;
  }
  *(undefined4 *)(local_9d4 + 0xe90) = 8;
  control_thr = _cgcalloc(8,0x40,"cgminer.c",&__func___15840,0x2e13);
  fill_device_drv(bitforce_drv);
  fill_device_drv(modminer_drv);
  fill_device_drv(bitmain_drv);
  fill_device_drv(&bitmain_c5_drv);
  (*(code *)bitforce_drv._12_4_)(0);
  (*(code *)modminer_drv._12_4_)(0);
  (*(code *)bitmain_drv._12_4_)(0);
  piVar28 = &total_devices;
  iVar5 = 0;
  (*DAT_0007e3ec)(0);
  local_9c4 = &mining_threads;
  mining_threads = 0;
  if (0 < total_devices) {
    do {
      iVar24 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      enable_device(*(undefined4 *)(devices + iVar24));
    } while (iVar5 < total_devices);
  }
  iVar5 = total_devices;
  if (total_devices == 0) {
    local_828._0_1_ = 'A';
    local_828._1_1_ = 'l';
    local_828._2_1_ = 'l';
    local_828._3_1_ = ' ';
    local_824._0_1_ = 'd';
    local_824._1_1_ = 'e';
    local_824._2_1_ = 'v';
    local_824._3_1_ = 'i';
    builtin_strncpy(acStack_820,"ces disa",8);
    local_818._0_1_ = 'b';
    local_818._1_1_ = 'l';
    local_818._2_1_ = 'e';
    local_818._3_1_ = 'd';
    local_814._0_1_ = ',';
    local_814._1_1_ = ' ';
    local_814._2_1_ = 'c';
    local_814._3_1_ = 'a';
    builtin_strncpy(local_810,"nnot min",8);
    local_808 = CONCAT13(local_808._3_1_,0x2174);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pcVar38 = (char *)local_9c8[0x108];
  *(int *)(local_9d4 + 0xa74) = total_devices;
  if (pcVar38 == (char *)0x0) {
    iVar29 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
    iVar26 = total_devices;
    iVar24 = devices;
    piVar32 = (int *)modminer_drv;
    if (iVar29 != 0) {
LAB_00014714:
      pcVar38 = (char *)_rd_lock_part_39_constprop_80("load_temp_cutoffs",0x52a);
LAB_0001471e:
      snprintf((char *)&local_828,0x800,"No login credentials supplied for pool %u %s",piVar32,
               *(undefined4 *)(iVar5 + 0xa4));
      _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
      __quit(1,pcVar38);
    }
    for (iVar5 = 0; iVar5 < iVar26; iVar5 = iVar5 + 1) {
      iVar29 = *(int *)(iVar24 + iVar5 * 4);
      if (*(int *)(iVar29 + 0xb8) == 0) {
        *(undefined4 *)(iVar29 + 0xb8) = 0x5f;
      }
    }
    _wr_unlock_constprop_78(devices_lock,"load_temp_cutoffs",0x533);
  }
  else {
    iVar5 = 0;
    piVar32 = &devices;
    piVar35 = (int *)0x0;
    pcVar38 = strtok(pcVar38,",");
    while (pcVar38 != (char *)0x0) {
      if (total_devices <= iVar5) {
        local_828._0_1_ = 'T';
        local_828._1_1_ = 'o';
        local_828._2_1_ = 'o';
        local_828._3_1_ = ' ';
        local_824._0_1_ = 'm';
        local_824._1_1_ = 'a';
        local_824._2_1_ = 'n';
        local_824._3_1_ = 'y';
        builtin_strncpy(acStack_820," values ",8);
        local_818._0_1_ = 'p';
        local_818._1_1_ = 'a';
        local_818._2_1_ = 's';
        local_818._3_1_ = 's';
        local_814._0_1_ = 'e';
        local_814._1_1_ = 'd';
        local_814._2_1_ = ' ';
        local_814._3_1_ = 't';
        builtin_strncpy(local_810,"o set te",8);
        local_808._0_1_ = 'm';
        local_808._1_1_ = 'p';
        local_808._2_1_ = ' ';
        local_808._3_1_ = 'c';
        local_804._0_1_ = 'u';
        local_804._1_1_ = 't';
        local_804._2_1_ = 'o';
        local_804._3_1_ = 'f';
        local_800 = CONCAT22(local_800._2_2_,0x66);
        _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      piVar35 = (int *)strtol(pcVar38,(char **)0x0,10);
      if ((int *)0xc8 < piVar35) {
        local_828._0_1_ = 'I';
        local_828._1_1_ = 'n';
        local_828._2_1_ = 'v';
        local_828._3_1_ = 'a';
        local_824._0_1_ = 'l';
        local_824._1_1_ = 'i';
        local_824._2_1_ = 'd';
        local_824._3_1_ = ' ';
        acStack_820[0] = 'v';
        acStack_820[1] = 'a';
        acStack_820[2] = 'l';
        acStack_820[3] = 'u';
        acStack_820[4] = 'e';
        acStack_820[5] = ' ';
        acStack_820[6] = 'p';
        acStack_820[7] = 'a';
        pcVar38 = "ssed to set temp cutoff";
        piVar28 = &local_818;
        goto LAB_00013288;
      }
      iVar24 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
      if (iVar24 != 0) {
        _rd_lock_part_39_constprop_80("load_temp_cutoffs",0x523);
        goto LAB_00013ef2;
      }
      *(int **)(*(int *)(devices + iVar5 * 4) + 0xb8) = piVar35;
      piVar12 = (int *)pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
      if (piVar12 != (int *)0x0) {
        piVar28 = __errno_location();
        snprintf((char *)&local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                 *piVar28,"cgminer.c","load_temp_cutoffs",0x525);
        piVar32 = &local_828;
        goto LAB_0001329a;
      }
      iVar5 = iVar5 + 1;
      local_9d0 = piVar12;
      (*selective_yield)();
      pcVar38 = strtok((char *)local_9d0,",");
    }
    if (iVar5 < 2) {
      local_9d0 = piVar35;
      iVar29 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
      iVar26 = total_devices;
      iVar24 = devices;
      if (iVar29 != 0) {
        _rd_lock_part_39_constprop_80("load_temp_cutoffs",0x53a);
        goto LAB_00014714;
      }
      for (; iVar5 < iVar26; iVar5 = iVar5 + 1) {
        *(int **)(*(int *)(iVar24 + iVar5 * 4) + 0xb8) = local_9d0;
      }
      _wr_unlock_constprop_78(devices_lock,"load_temp_cutoffs",0x540);
    }
  }
  iVar24 = total_devices;
  iVar5 = devices;
  for (iVar26 = 0; iVar26 < iVar24; iVar26 = iVar26 + 1) {
    *(undefined4 *)(*(int *)(iVar5 + iVar26 * 4) + 0x138) = 99999999;
  }
  if (opt_compact == '\0') {
    *(int *)(local_9d4 + 0xa78) = *(int *)(local_9d4 + 0xa74) + *(int *)(local_9d4 + 0xa78);
  }
  local_9d8 = &total_pools;
  if (total_pools == 0) {
    if (((use_syslog != '\0') || (*local_9c0 != '\0')) || (3 < opt_log_level)) {
      local_828._0_1_ = 'N';
      local_828._1_1_ = 'e';
      local_828._2_1_ = 'e';
      local_828._3_1_ = 'd';
      local_824._0_1_ = ' ';
      local_824._1_1_ = 't';
      local_824._2_1_ = 'o';
      local_824._3_1_ = ' ';
      builtin_strncpy(acStack_820,"specify ",8);
      local_818._0_1_ = 'a';
      local_818._1_1_ = 't';
      local_818._2_1_ = ' ';
      local_818._3_1_ = 'l';
      local_814._0_1_ = 'e';
      local_814._1_1_ = 'a';
      local_814._2_1_ = 's';
      local_814._3_1_ = 't';
      builtin_strncpy(local_810," one poo",8);
      local_808._0_1_ = 'l';
      local_808._1_1_ = ' ';
      local_808._2_1_ = 's';
      local_808._3_1_ = 'e';
      local_804._0_1_ = 'r';
      local_804._1_1_ = 'v';
      local_804._2_1_ = 'e';
      local_804._3_1_ = 'r';
      local_800 = CONCAT22(local_800._2_2_,0x2e);
      _applog(4,&local_828,0);
    }
    local_828._0_1_ = 'P';
    local_828._1_1_ = 'o';
    local_828._2_1_ = 'o';
    local_828._3_1_ = 'l';
    local_824._0_1_ = ' ';
    local_824._1_1_ = 's';
    local_824._2_1_ = 'e';
    local_824._3_1_ = 't';
    builtin_strncpy(acStack_820,"up faile",8);
    local_818 = CONCAT22(local_818._2_2_,100);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  local_9e0 = &devices;
  local_9e4 = &total_devices;
  local_9d0 = &pools;
  local_9dc = (int *)0x5c334;
  for (piVar32 = (int *)0x0; piVar35 = local_9e0, piVar28 = local_9e4, cVar3 = use_syslog,
      (int)piVar32 < total_pools; piVar32 = (int *)((int)piVar32 + 1)) {
    iVar5 = *(int *)(pools + (int)piVar32 * 4);
    *(undefined4 *)(iVar5 + 0x194) = 99999999;
    *(undefined4 *)(iVar5 + 0x1b8) = 99999999;
    if (*(int *)(iVar5 + 0xa8) == 0) {
      if (*(int *)(iVar5 + 0xb0) == 0) {
        pvVar10 = calloc(1,1);
        *(void **)(iVar5 + 0xb0) = pvVar10;
      }
      pcVar38 = *(char **)(iVar5 + 0xac);
      if (pcVar38 == (char *)0x0) goto LAB_0001471e;
      sVar8 = strlen(pcVar38);
      sVar13 = strlen(*(char **)(iVar5 + 0xb0));
      sVar8 = sVar13 + sVar8 + 2;
      pcVar38 = (char *)_cgmalloc(sVar8,local_9dc,&__func___15840,0x2e80);
      *(char **)(iVar5 + 0xa8) = pcVar38;
      snprintf(pcVar38,sVar8,"%s:%s",*(undefined4 *)(iVar5 + 0xac),*(undefined4 *)(iVar5 + 0xb0));
    }
  }
  local_9c8[299] = *(undefined4 *)*local_9d0;
  if (cVar3 != '\0') {
    openlog("bmminer",1,8);
  }
  piVar32 = &local_828;
  if (*(int *)(local_9d4 + 0xe94) != 0) {
    iVar5 = pipe(piVar32);
    if (iVar5 < 0) {
      perror("pipe - failed to create pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(stderr);
    iVar5 = dup2(local_824,2);
    if (iVar5 < 0) {
      perror("dup2 - failed to alias stderr to write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar5 = close(local_824);
    if (iVar5 < 0) {
      perror("close - failed to close write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    p_Var14 = signal(0xd,(__sighandler_t)0x1);
    p_Var15 = signal(0xd,(__sighandler_t)0x1);
    if ((p_Var14 == (__sighandler_t)0xffffffff) || (p_Var15 == (__sighandler_t)0xffffffff)) {
      perror("signal - failed to edit signal mask for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    _Var16 = fork();
    local_9c8[0x111] = _Var16;
    if (_Var16 < 0) {
      perror("fork - failed to fork child process for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (_Var16 == 0) {
      iVar5 = dup2(local_828,0);
      if (-1 < iVar5) {
        close(local_828);
        execl("/bin/bash","/bin/bash",&DAT_0005ed20,*(undefined4 *)(local_9d4 + 0xe94),0);
        perror("execl - in child failed to exec user specified command for --monitor");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      perror("dup2 - in child, failed to alias read end of pipe to stdin for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar5 = close(local_828);
    if (iVar5 < 0) {
      perror("close - failed to close read end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
LAB_00013ef2:
  local_9e0 = &mining_thr;
  mining_thr = _cgcalloc(*local_9c4,4,"cgminer.c",&__func___15840,0x2e91);
  for (iVar5 = 0; iVar5 < *local_9c4; iVar5 = iVar5 + 1) {
    iVar24 = *local_9e0;
    uVar6 = _cgcalloc(1,0x40,"cgminer.c",&__func___15840,0x2e95);
    *(undefined4 *)(iVar24 + iVar5 * 4) = uVar6;
  }
  local_9e8 = (byte *)&use_syslog;
  local_9f0 = (char **)&opt_debug;
  iVar5 = 0;
  local_9e4 = piVar32;
  for (local_9dc = (int *)0x0; piVar32 = local_9e4, pbVar9 = local_9e8, (int)local_9dc < *piVar28;
      local_9dc = (int *)((int)local_9dc + 1)) {
    iVar29 = *(int *)(*piVar35 + (int)local_9dc * 4);
    local_9ec = (code *)0x1bca1;
    iVar24 = _cgmalloc((*(int *)(iVar29 + 0x94) + 1) * 4,"cgminer.c",&__func___15840,0x2e9e);
    iVar26 = *(int *)(iVar29 + 0x94);
    *(int *)(iVar29 + 0x98) = iVar24;
    *(undefined4 *)(iVar24 + iVar26 * 4) = 0;
    *(undefined4 *)(iVar29 + 0x60) = 4;
    for (iVar24 = 0; iVar33 = iVar5 + iVar24, iVar24 < iVar26; iVar24 = iVar24 + 1) {
      piVar32 = (int *)get_thread(iVar33);
      iVar26 = *(int *)(iVar29 + 4);
      *piVar32 = iVar33;
      piVar32[9] = iVar29;
      pcVar19 = *(code **)(iVar26 + 0x2c);
      piVar32[1] = iVar24;
      iVar26 = (*pcVar19)();
      if (iVar26 != 0) {
        iVar26 = thr_info_create(piVar32,0,local_9ec,piVar32);
        piVar12 = local_9e4;
        if (iVar26 != 0) {
          snprintf((char *)local_9e4,0x800,"thread %d create failed",*piVar32);
          _applog(3,piVar12,1);
                    /* WARNING: Subroutine does not return */
          __quit(1,0);
        }
        iVar26 = *(int *)(iVar29 + 0x20);
        *(int **)(*(int *)(iVar29 + 0x98) + iVar24 * 4) = piVar32;
        if (iVar26 != 1) {
          if ((*(char *)local_9f0 != '\0') &&
             (((*local_9e8 != 0 || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
            snprintf((char *)local_9e4,0x800,"Pushing sem post to thread %d",*piVar32);
            _applog(7,piVar12,0);
          }
          _cgsem_post(piVar32 + 4,"cgminer.c",&__func___15840,0x2eba);
        }
      }
      iVar26 = *(int *)(iVar29 + 0x94);
    }
    iVar5 = iVar33;
  }
  if ((*(char *)(local_9c8 + 0x160) == '\0') && (local_9c8[0x113] == 0)) {
    iVar29 = *local_9d8;
    iVar26 = *local_9d0;
    iVar24 = 0;
    bVar2 = false;
    iVar5 = enabled_pools;
    while (iVar24 < iVar29) {
      iVar33 = *(int *)(iVar26 + iVar24 * 4);
      iVar24 = iVar24 + 1;
      *(undefined1 *)(iVar33 + 0x61) = 1;
      bVar39 = *(int *)(iVar33 + 100) != 1;
      if (bVar39) {
        iVar5 = iVar5 + 1;
        bVar2 = true;
      }
      if (bVar39) {
        *(undefined4 *)(iVar33 + 100) = 1;
      }
    }
    if (bVar2) {
      enabled_pools = iVar5;
    }
    if (((*local_9e8 != 0) || (*local_9c0 != '\0')) || (4 < opt_log_level)) {
      *local_9e4 = 0x626f7250;
      local_9e4[1] = 0x20676e69;
      local_9e4[2] = 0x20726f66;
      local_9e4[3] = 0x61206e61;
      local_9e4[4] = 0x6576696c;
      local_9e4[5] = 0x6f6f7020;
      *(undefined2 *)(local_9e4 + 6) = 0x6c;
      _applog(5,local_9e4,0);
    }
    for (iVar5 = 0; iVar5 < *local_9d8; iVar5 = iVar5 + 1) {
      pvVar10 = *(void **)(*local_9d0 + iVar5 * 4);
      *(undefined1 *)((int)pvVar10 + 0x11c) = 1;
      pthread_create((pthread_t *)((int)pvVar10 + 0x118),(pthread_attr_t *)0x0,
                     (__start_routine *)0x23015,pvVar10);
    }
    iVar5 = 0;
    do {
      sleep(1);
      pcVar38 = local_9c0;
      uVar22 = iVar5 - 0xb3;
      if (uVar22 != 0) {
        uVar22 = 1;
      }
      iVar5 = iVar5 + 1;
    } while (*(byte *)(local_9c8 + 0x171) < uVar22);
    piVar12 = &opt_log_level;
    bVar2 = false;
    local_9e4 = piVar35;
    while (piVar35 = local_9e4, *(char *)(local_9c8 + 0x171) == '\0') {
      if (bVar2) {
LAB_00014aae:
        if (use_curses == '\0') {
LAB_00014abe:
          *piVar32 = 0x73206f4e;
          piVar32[1] = 0x65767265;
          piVar32[2] = 0x63207372;
          piVar32[3] = 0x646c756f;
          piVar32[4] = 0x20656220;
          piVar32[5] = 0x64657375;
          piVar32[6] = 0x78452021;
          piVar32[7] = 0x6e697469;
          *(undefined2 *)(piVar32 + 8) = 0x2e67;
          *(undefined1 *)((int)piVar32 + 0x22) = 0;
          _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
          __quit(0);
        }
      }
      else {
        if (((*pbVar9 == 0) && (*pcVar38 == '\0')) && (*piVar12 < 3)) {
LAB_00014c1c:
          if (2 < *piVar12) goto LAB_00014b42;
LAB_00014c22:
          if (2 < *piVar12) goto LAB_00014b6a;
        }
        else {
          *piVar32 = 0x73206f4e;
          piVar32[1] = 0x65767265;
          piVar32[2] = 0x77207372;
          piVar32[3] = 0x20657265;
          piVar32[4] = 0x6e756f66;
          piVar32[5] = 0x68742064;
          piVar32[6] = 0x63207461;
          piVar32[7] = 0x646c756f;
          piVar32[8] = 0x20656220;
          piVar32[9] = 0x64657375;
          piVar32[10] = 0x206f7420;
          piVar32[0xb] = 0x20746567;
          piVar32[0xc] = 0x6b726f77;
          piVar32[0xd] = 0x6f726620;
          *(undefined2 *)(piVar32 + 0xe) = 0x2e6d;
          *(undefined1 *)((int)piVar32 + 0x3a) = 0;
          _applog(3,piVar32,0);
          if ((*pbVar9 == 0) && (*pcVar38 == '\0')) goto LAB_00014c1c;
LAB_00014b42:
          memcpy(piVar32,
                 "Please check the details from the list below of the servers you have input",0x4b);
          _applog(3,piVar32,0);
          if ((*pbVar9 == 0) && (*pcVar38 == '\0')) goto LAB_00014c22;
LAB_00014b6a:
          memcpy(piVar32,
                 "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers"
                 ,0x5e);
          _applog(3,piVar32,0);
        }
        local_9dc = piVar12;
        for (iVar5 = 0; piVar12 = local_9dc, iVar5 < *local_9d8; iVar5 = iVar5 + 1) {
          iVar24 = *(int *)(*local_9d0 + iVar5 * 4);
          if (((*pbVar9 != 0) || (*pcVar38 != '\0')) || (3 < *local_9dc)) {
            snprintf((char *)piVar32,0x800,"Pool: %d  URL: %s  User: %s  Password: %s",iVar5,
                     *(undefined4 *)(iVar24 + 0xa4),*(undefined4 *)(iVar24 + 0xac),
                     *(undefined4 *)(iVar24 + 0xb0));
            _applog(4,piVar32,0);
          }
        }
        if (use_curses == '\0') goto LAB_00014abe;
        if (((*pbVar9 != 0) || (*pcVar38 != '\0')) || (2 < *local_9dc)) {
          memcpy(piVar32,
                 "Press any key to exit, or cgminer will wait indefinitely for an alive pool.",0x4c)
          ;
          _applog(3,piVar32,0);
          goto LAB_00014aae;
        }
      }
      bVar2 = true;
    }
  }
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  puVar30 = (undefined4 *)g_local_mhashes_dones;
  do {
    puVar34 = puVar30 + 2;
    *puVar30 = 0;
    puVar30[1] = 0;
    puVar30 = puVar34;
  } while (puVar34 != &g_local_mhashes_index);
  iVar26 = *piVar28;
  iVar24 = *piVar35;
  local_9c8[0x14c] = 0;
  for (iVar5 = 0; iVar5 < iVar26; iVar5 = iVar5 + 1) {
    iVar29 = *(int *)(iVar24 + iVar5 * 4);
    *(undefined4 *)(iVar29 + 0x50) = 0;
    *(undefined4 *)(iVar29 + 0x54) = 0;
    *(undefined4 *)(iVar29 + 0x30) = 0;
    *(undefined4 *)(iVar29 + 0x34) = 0;
  }
  cgtime(&total_tv_start);
  cgtime(&total_tv_end);
  cgtime(&tv_hashmeter);
  get_datestamp(datestamp,0x28);
  iVar24 = *(int *)local_9cc;
  local_9c8[0x129] = 2;
  iVar5 = thr_info_create(iVar24 + 0x80,0,0x22289);
  if (iVar5 != 0) {
    *piVar32 = 0x63746177;
    piVar32[1] = 0x6f6f7068;
    piVar32[2] = 0x6874206c;
    piVar32[3] = 0x64616572;
    piVar32[4] = 0x65726320;
    piVar32[5] = 0x20657461;
    piVar32[6] = 0x6c696166;
    *(undefined2 *)(piVar32 + 7) = 0x6465;
    *(undefined1 *)((int)piVar32 + 0x1e) = 0;
    _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pthread_detach(*(pthread_t *)(iVar24 + 0x8c));
  iVar24 = *(int *)local_9cc;
  local_9c8[0x12a] = 3;
  iVar5 = thr_info_create(iVar24 + 0xc0,0,0x25e51,0);
  if (iVar5 != 0) {
    *piVar32 = 0x63746177;
    piVar32[1] = 0x676f6468;
    piVar32[2] = 0x72687420;
    piVar32[3] = 0x20646165;
    piVar32[4] = 0x61657263;
    piVar32[5] = 0x66206574;
    piVar32[6] = 0x656c6961;
    *(undefined2 *)(piVar32 + 7) = 100;
    _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pthread_detach(*(pthread_t *)(iVar24 + 0xcc));
  iVar5 = *(int *)local_9cc;
  local_9c8[0xd0] = 5;
  iVar5 = thr_info_create(iVar5 + 0x140,0,0x1c1c9);
  if (iVar5 != 0) {
    *piVar32 = 0x20495041;
    piVar32[1] = 0x65726874;
    piVar32[2] = 0x63206461;
    piVar32[3] = 0x74616572;
    piVar32[4] = 0x61662065;
    piVar32[5] = 0x64656c69;
    *(undefined1 *)(piVar32 + 6) = 0;
    _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  if (*(int *)(local_9d4 + 0xe90) != 8) {
    snprintf((char *)piVar32,0x800,"incorrect total_control_threads (%d) should be 8");
    _applog(3,piVar32,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  iVar5 = nice(-10);
  if (((iVar5 == 0) && (opt_debug != '\0')) &&
     ((*pbVar9 != 0 || ((*local_9c0 != '\0' || (6 < opt_log_level)))))) {
    *piVar32 = 0x62616e55;
    piVar32[1] = 0x7420656c;
    piVar32[2] = 0x6573206f;
    piVar32[3] = 0x68742074;
    piVar32[4] = 0x64616572;
    piVar32[5] = 0x206f7420;
    piVar32[6] = 0x68676968;
    piVar32[7] = 0x69727020;
    piVar32[8] = 0x7469726f;
    *(undefined2 *)(piVar32 + 9) = 0x79;
    _applog(7,piVar32,0);
  }
  pcVar19 = local_9d4;
  local_9cc = pbVar9;
  local_9e4 = (int *)&opt_work_update;
LAB_000142e8:
  if ((char)*local_9e4 != '\0') {
    if (((*local_9cc != 0) || (*local_9c0 != '\0')) || (5 < opt_log_level)) {
      *piVar32 = 0x6b726f57;
      piVar32[1] = 0x64707520;
      piVar32[2] = 0x20657461;
      piVar32[3] = 0x7373656d;
      piVar32[4] = 0x20656761;
      piVar32[5] = 0x65636572;
      piVar32[6] = 0x64657669;
      *(undefined1 *)(piVar32 + 7) = 0;
      _applog(6,piVar32,0);
    }
    cgtime(&update_tv_start);
    iVar5 = pthread_rwlock_rdlock((pthread_rwlock_t *)mining_thr_lock);
    if (iVar5 != 0) {
      piVar28 = __errno_location();
      uVar6 = 0x1531;
      pcVar38 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
      pcVar7 = "signal_work_update";
      goto LAB_0001481e;
    }
    iVar24 = *local_9c4;
    iVar26 = *local_9e0;
    for (iVar5 = 0; iVar5 < iVar24; iVar5 = iVar5 + 1) {
      *(undefined1 *)(*(int *)(iVar26 + iVar5 * 4) + 0x3f) = 1;
    }
    iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)mining_thr_lock);
    if (iVar5 != 0) {
      piVar28 = __errno_location();
      uVar6 = 0x1538;
      pcVar38 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
      pcVar7 = "signal_work_update";
      goto LAB_0001481e;
    }
    (*selective_yield)();
  }
  __mutex = (pthread_mutex_t *)local_9c8[0x117];
  *(char *)local_9e4 = '\0';
  iVar5 = pthread_mutex_lock(__mutex);
  puVar30 = local_9c8;
  if (iVar5 != 0) {
    piVar28 = __errno_location();
    uVar6 = 0x2f60;
    pcVar38 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    goto LAB_00014816;
  }
  if ((local_9c8[0x14d] == 0) || (*(int *)(*(int *)(local_9c8[0x14d] + 0x158) + 0xc) < 2)) {
LAB_0001431c:
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)local_9c8[0x117]);
    if (iVar5 != 0) goto LAB_000148b2;
    (*selective_yield)();
  }
  else {
    pthread_cond_wait((pthread_cond_t *)gws_cond,(pthread_mutex_t *)local_9c8[0x117]);
    iVar5 = puVar30[0x14d];
    if (iVar5 == 0) goto LAB_0001431c;
    iVar24 = *(int *)(*(int *)(iVar5 + 0x158) + 0xc);
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)puVar30[0x117]);
    if (iVar5 != 0) goto LAB_000148b2;
    (*selective_yield)();
    if (1 < iVar24) {
      local_9b8 = hash_pop(0);
      if (local_9b8 != 0) {
        _discard_work(&local_9b8,"cgminer.c",&__func___15840,0x2f77);
      }
      goto LAB_000142e8;
    }
  }
  if (local_9b8 != 0) {
    _discard_work(&local_9b8,"cgminer.c",&__func___15840,0x2f7f);
  }
  local_9b8 = make_work();
  local_9dc = (int *)&opt_debug;
LAB_0001442e:
  pcVar17 = (code *)current_pool();
  if (local_9c8[0x107] == 4) {
    pcVar18 = (code *)select_balanced();
  }
  else {
    pcVar18 = pcVar17;
    if (local_9c8[0x107] == 3) {
      iVar26 = *local_9d8;
      iVar5 = *local_9d0;
      for (iVar24 = 0; iVar24 < iVar26; iVar24 = iVar24 + 1) {
        iVar29 = *(int *)(iVar5 + iVar24 * 4);
        if (*(int *)(iVar29 + 0x40) < *(int *)(iVar29 + 0x3c)) goto LAB_0001454a;
      }
      for (iVar24 = 0; iVar24 < iVar26; iVar24 = iVar24 + 1) {
        *(undefined4 *)(*(int *)(iVar5 + iVar24 * 4) + 0x40) = 0;
      }
      iVar5 = *(int *)(pcVar19 + 0xe98) + 1;
      if (iVar26 <= iVar5) {
        iVar5 = 0;
      }
      *(int *)(pcVar19 + 0xe98) = iVar5;
LAB_0001454a:
      local_9e8 = (byte *)*local_9d0;
      local_9d4 = (code *)0x0;
      while (piVar28 = local_9d8, (int)local_9d4 < iVar26) {
        iVar24 = *(int *)(pcVar19 + 0xe98);
        pcVar18 = *(code **)(local_9e8 + iVar24 * 4);
        iVar5 = *(int *)(pcVar18 + 0x40);
        *(int *)(pcVar18 + 0x40) = iVar5 + 1;
        if (((iVar5 < *(int *)(pcVar18 + 0x3c)) && (pcVar18[0x61] == (code)0x0)) &&
           ((*(int *)(pcVar18 + 100) == 1 &&
            (local_9ec = pcVar18, iVar5 = pool_unusable_part_4(pcVar18), pcVar18 = local_9ec,
            iVar5 == 0)))) goto LAB_00014372;
        iVar24 = iVar24 + 1;
        local_9d4 = local_9d4 + 1;
        if (iVar26 <= iVar24) {
          iVar24 = 0;
        }
        *(int *)(pcVar19 + 0xe98) = iVar24;
      }
      iVar5 = 0;
      while ((pcVar18 = pcVar17, iVar5 < *piVar28 &&
             (((local_9d4 = (code *)priority_pool(iVar5), local_9d4[0x61] != (code)0x0 ||
               (*(int *)(local_9d4 + 100) != 1)) ||
              (iVar24 = pool_unusable_part_4(), pcVar18 = local_9d4, iVar24 != 0))))) {
        iVar5 = iVar5 + 1;
      }
    }
  }
LAB_00014372:
  if (((char)*local_9dc != '\0') &&
     (((*local_9cc != 0 || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
    snprintf((char *)piVar32,0x800,"Selecting pool %d for work",*(undefined4 *)pcVar18);
    _applog(7,piVar32,0);
  }
  if (((pcVar18[0x61] != (code)0x0) || (*(int *)(pcVar18 + 100) != 1)) ||
     (iVar5 = pool_unusable_part_4(pcVar18), piVar28 = local_9dc, iVar5 != 0)) {
    switch_pools(0);
    pcVar17 = (code *)current_pool();
    if (local_9c8[0x107] == 4) {
      pcVar18 = (code *)select_balanced();
    }
    else {
      pcVar18 = pcVar17;
      if (local_9c8[0x107] == 3) {
        iVar26 = *local_9d8;
        iVar5 = *local_9d0;
        for (iVar24 = 0; iVar24 < iVar26; iVar24 = iVar24 + 1) {
          iVar29 = *(int *)(iVar5 + iVar24 * 4);
          if (*(int *)(iVar29 + 0x40) < *(int *)(iVar29 + 0x3c)) goto LAB_00014488;
        }
        for (iVar24 = 0; iVar24 < iVar26; iVar24 = iVar24 + 1) {
          *(undefined4 *)(*(int *)(iVar5 + iVar24 * 4) + 0x40) = 0;
        }
        iVar5 = *(int *)(pcVar19 + 0xe98) + 1;
        if (iVar26 <= iVar5) {
          iVar5 = 0;
        }
        *(int *)(pcVar19 + 0xe98) = iVar5;
LAB_00014488:
        local_9e8 = (byte *)*local_9d0;
        local_9d4 = (code *)0x0;
        while (piVar28 = local_9d8, (int)local_9d4 < iVar26) {
          iVar24 = *(int *)(pcVar19 + 0xe98);
          pcVar18 = *(code **)(local_9e8 + iVar24 * 4);
          iVar5 = *(int *)(pcVar18 + 0x40);
          *(int *)(pcVar18 + 0x40) = iVar5 + 1;
          if ((((iVar5 < *(int *)(pcVar18 + 0x3c)) && (pcVar18[0x61] == (code)0x0)) &&
              (*(int *)(pcVar18 + 100) == 1)) &&
             (local_9ec = pcVar18, iVar5 = pool_unusable_part_4(pcVar18), pcVar18 = local_9ec,
             iVar5 == 0)) goto LAB_000143d4;
          iVar24 = iVar24 + 1;
          if (iVar26 <= iVar24) {
            iVar24 = 0;
          }
          local_9d4 = local_9d4 + 1;
          *(int *)(pcVar19 + 0xe98) = iVar24;
        }
        iVar5 = 0;
        while ((pcVar18 = pcVar17, iVar5 < *piVar28 &&
               (((local_9d4 = (code *)priority_pool(iVar5), local_9d4[0x61] != (code)0x0 ||
                 (*(int *)(local_9d4 + 100) != 1)) ||
                (iVar24 = pool_unusable_part_4(), pcVar18 = local_9d4, iVar24 != 0))))) {
          iVar5 = iVar5 + 1;
        }
      }
    }
LAB_000143d4:
    if (((char)*local_9dc != '\0') &&
       (((*local_9cc != 0 || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)piVar32,0x800,"Selecting pool %d for work",*(undefined4 *)pcVar18);
      _applog(7,piVar32,0);
    }
    if (((pcVar18[0x61] != (code)0x0) || (*(int *)(pcVar18 + 100) != 1)) ||
       (iVar5 = pool_unusable_part_4(pcVar18), iVar5 != 0)) {
      cgsleep_ms(0xb);
    }
    goto LAB_0001442e;
  }
  if (pcVar18[0x280] == (code)0x0) {
    if (local_9c8[0x113] == 0) goto LAB_0001467a;
    get_benchfile_work(local_9b8);
    if (((char)*piVar28 == '\0') ||
       (((*local_9cc == 0 && (*local_9c0 == '\0')) && (opt_log_level < 7)))) goto LAB_00014650;
    pcVar38 = "Generated benchfile work";
    goto LAB_0001463a;
  }
  gen_stratum_work(pcVar18,local_9b8);
  if (((char)*piVar28 != '\0') &&
     (((*local_9cc != 0 || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
    *piVar32 = 0x656e6547;
    piVar32[1] = 0x65746172;
    piVar32[2] = 0x74732064;
    piVar32[3] = 0x75746172;
    piVar32[4] = 0x6f77206d;
    *(undefined2 *)(piVar32 + 5) = 0x6b72;
    *(undefined1 *)((int)piVar32 + 0x16) = 0;
    _applog(7,piVar32,0);
  }
  goto LAB_00014650;
LAB_000148b2:
  piVar28 = __errno_location();
  uVar6 = 0x2f6b;
  pcVar38 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
LAB_00014816:
  pcVar7 = "main";
LAB_0001481e:
  snprintf((char *)piVar32,0x800,pcVar38,*piVar28,"cgminer.c",pcVar7,uVar6);
  goto LAB_0001329a;
LAB_0001467a:
  if (*(char *)(local_9c8 + 0x160) != '\0') {
    get_benchmark_work(local_9b8);
    if (((char)*piVar28 != '\0') &&
       (((*local_9cc != 0 || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
      pcVar38 = "Generated benchmark work";
LAB_0001463a:
      iVar5 = *(int *)((int)pcVar38 + 4);
      iVar24 = *(int *)((int)pcVar38 + 8);
      iVar26 = *(int *)((int)pcVar38 + 0xc);
      *piVar32 = *(int *)pcVar38;
      piVar32[1] = iVar5;
      piVar32[2] = iVar24;
      piVar32[3] = iVar26;
      iVar5 = *(int *)((int)pcVar38 + 0x14);
      iVar24 = *(int *)((int)pcVar38 + 0x18);
      piVar32[4] = *(int *)((int)pcVar38 + 0x10);
      piVar32[5] = iVar5;
      *(char *)(piVar32 + 6) = (char)iVar24;
      _applog(7,piVar32,0);
    }
LAB_00014650:
    _stage_work(local_9b8);
    local_9b8 = 0;
  }
  goto LAB_000142e8;
}

