
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void main(int param_1,int *param_2)

{
  undefined2 uVar1;
  bool bVar2;
  char cVar3;
  char **ppcVar4;
  long lVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *__src;
  size_t sVar9;
  int *piVar10;
  void *pvVar11;
  FILE *pFVar12;
  int **ppiVar13;
  size_t sVar14;
  __sighandler_t p_Var15;
  __sighandler_t p_Var16;
  pthread_mutex_t *__mutex;
  undefined4 *puVar17;
  undefined4 *puVar18;
  code *pcVar19;
  uint uVar20;
  code **ppcVar21;
  uint uVar22;
  uint uVar23;
  int *piVar24;
  void *pvVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  void **ppvVar29;
  int iVar30;
  undefined4 uVar31;
  int *piVar32;
  int iVar33;
  undefined4 *puVar34;
  FILE **ppFVar35;
  int iVar36;
  int iVar37;
  int **ppiVar38;
  char *pcVar39;
  bool bVar40;
  char acStack_2a00 [4104];
  undefined4 local_19f8;
  undefined4 uStack_19f4;
  undefined local_19f0;
  char *local_a00;
  undefined4 **local_9f0;
  undefined1 *local_9ec;
  char *local_9e8;
  int *local_9e4;
  int *local_9e0;
  char *local_9dc;
  int *local_9d8;
  undefined4 *local_9d4;
  int *local_9d0;
  int *local_9cc;
  char **local_9c8;
  char *local_9c4;
  char *local_9c0;
  int local_9bc;
  int local_9b8;
  sigaction local_9b4;
  char acStack_928 [256];
  int *local_828;
  undefined4 local_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 local_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 local_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined2 local_7f8;
  
  g_logfile_path._0_4_ = s_bmminer_log_0005e754._0_4_;
  g_logfile_path._8_4_ = s_bmminer_log_0005e754._8_4_;
  local_9e4 = (int *)&g_logfile_enable;
  g_logfile_path._4_4_ = s_bmminer_log_0005e754._4_4_;
  ppcVar21 = (code **)&g_logfile_enable;
  g_logfile_openflag._0_2_ = DAT_0005e760;
  g_logfile_openflag[2] = DAT_0005e762;
  g_logfile_enable = 0;
  local_9b8 = 0;
  local_9ec = g_logfile_openflag;
  pcVar19 = (code *)s_bmminer_log_0005e754._8_4_;
  local_9d8 = param_2;
  local_9bc = param_1;
  lVar5 = sysconf(0x54);
  if (lVar5 == 1) {
    ppcVar21 = &selective_yield;
    pcVar19 = sched_yield;
  }
  if (lVar5 == 1) {
    *ppcVar21 = pcVar19;
  }
  local_9c8 = (char **)&opt_logfile_path;
  iVar6 = _cgmalloc((local_9bc + 1) * 4,"cgminer.c",DAT_00012b04,0x2cc3);
  initial_args = iVar6;
  if (0 < local_9bc) {
    puVar34 = (undefined4 *)(iVar6 + -4);
    iVar26 = 0;
    piVar10 = local_9d8 + -1;
    do {
      piVar10 = piVar10 + 1;
      iVar26 = iVar26 + 1;
      uVar7 = __strdup(*piVar10);
      puVar34 = puVar34 + 1;
      *puVar34 = uVar7;
    } while (iVar26 < local_9bc);
  }
  *(undefined4 *)(iVar6 + local_9bc * 4) = 0;
  _mutex_init_constprop_66(hash_lock,DAT_00012b04,0x2ccc);
  _mutex_init_constprop_66(update_job_lock,DAT_00012b04,0x2ccd);
  _mutex_init_constprop_66(console_lock,DAT_00012b04,0x2cce);
  _cglock_init_constprop_65(control_lock,DAT_00012b04,0x2ccf);
  _mutex_init_constprop_66(stats_lock,DAT_00012b04,0x2cd0);
  local_9d4 = (undefined4 *)(bench_lodiff_bins + 0x124);
  _mutex_init_constprop_66(DAT_00012b08,DAT_00012b04,0x2cd1);
  _cglock_init_constprop_65(ch_lock,DAT_00012b04,0x2cd2);
  _mutex_init_constprop_66(DAT_00012b0c,DAT_00012b04,0x2cd3);
  _rwlock_init_constprop_68(blk_lock,DAT_00012b04,0x2cd4);
  _rwlock_init_constprop_68(netacc_lock,DAT_00012b04,0x2cd5);
  _rwlock_init_constprop_68(mining_thr_lock,DAT_00012b04,0x2cd6);
  _rwlock_init_constprop_68(devices_lock,DAT_00012b04,0x2cd7);
  _mutex_init_constprop_66(DAT_00012b10,DAT_00012b04,0x2cd9);
  iVar6 = pthread_cond_init(DAT_00012b14,(pthread_condattr_t *)0x0);
  if (iVar6 != 0) {
    local_828 = (int *)s_Failed_to_pthread_cond_init_lp_c_0005e764._0_4_;
    local_824._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[4];
    local_824._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[5];
    local_824._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[6];
    local_824._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[7];
    uStack_820._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[8];
    uStack_820._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[9];
    uStack_820._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[10];
    uStack_820._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[11];
    uStack_81c._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[12];
    uStack_81c._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[13];
    uStack_81c._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[14];
    uStack_81c._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[15];
    local_818 = (int *)s_Failed_to_pthread_cond_init_lp_c_0005e764._16_4_;
    local_814._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[20];
    local_814._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[21];
    local_814._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[22];
    local_814._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[23];
    uStack_810._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[24];
    uStack_810._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[25];
    uStack_810._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[26];
    uStack_810._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[27];
    uStack_80c._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[28];
    uStack_80c._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[29];
    uStack_80c._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[30];
    uStack_80c._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[31];
    local_808._0_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[32];
    local_808._1_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[33];
    local_808._2_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[34];
    local_808._3_1_ = s_Failed_to_pthread_cond_init_lp_c_0005e764[35];
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  _mutex_init_constprop_66(restart_lock,DAT_00012b04,0x2ce0);
  iVar6 = pthread_cond_init((pthread_cond_t *)restart_cond,(pthread_condattr_t *)0x0);
  if (iVar6 != 0) {
    local_828 = (int *)s_Failed_to_pthread_cond_init_rest_0005e788._0_4_;
    local_824._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[4];
    local_824._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[5];
    local_824._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[6];
    local_824._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[7];
    uStack_820._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[8];
    uStack_820._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[9];
    uStack_820._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[10];
    uStack_820._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[11];
    uStack_81c._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[12];
    uStack_81c._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[13];
    uStack_81c._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[14];
    uStack_81c._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[15];
    local_818 = (int *)s_Failed_to_pthread_cond_init_rest_0005e788._16_4_;
    local_814._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[20];
    local_814._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[21];
    local_814._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[22];
    local_814._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[23];
    uStack_810._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[24];
    uStack_810._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[25];
    uStack_810._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[26];
    uStack_810._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[27];
    uStack_80c._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[28];
    uStack_80c._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[29];
    uStack_80c._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[30];
    uStack_80c._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[31];
    local_808._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[32];
    local_808._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[33];
    local_808._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[34];
    local_808._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[35];
    local_804._0_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[36];
    local_804._1_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[37];
    local_804._2_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[38];
    local_804._3_1_ = s_Failed_to_pthread_cond_init_rest_0005e788[39];
    local_800 = CONCAT31(local_800._1_3_,(char)ram0x0005e7b0);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  iVar6 = pthread_cond_init((pthread_cond_t *)gws_cond,(pthread_condattr_t *)0x0);
  if (iVar6 != 0) {
    local_828 = (int *)s_Failed_to_pthread_cond_init_gws__0005e7b4._0_4_;
    local_824._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[4];
    local_824._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[5];
    local_824._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[6];
    local_824._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[7];
    uStack_820._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[8];
    uStack_820._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[9];
    uStack_820._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[10];
    uStack_820._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[11];
    uStack_81c._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[12];
    uStack_81c._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[13];
    uStack_81c._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[14];
    uStack_81c._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[15];
    local_818 = (int *)s_Failed_to_pthread_cond_init_gws__0005e7b4._16_4_;
    local_814._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[20];
    local_814._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[21];
    local_814._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[22];
    local_814._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[23];
    uStack_810._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[24];
    uStack_810._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[25];
    uStack_810._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[26];
    uStack_810._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[27];
    uStack_80c._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[28];
    uStack_80c._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[29];
    uStack_80c._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[30];
    uStack_80c._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[31];
    local_808._0_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[32];
    local_808._1_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[33];
    local_808._2_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[34];
    local_808._3_1_ = s_Failed_to_pthread_cond_init_gws__0005e7b4[35];
    local_804._0_1_ = (char)ram0x0005e7d8;
LAB_000138f6:
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  getq = tq_new();
  if (getq == 0) {
    local_828 = (int *)s_Failed_to_create_getq_0005e7dc._0_4_;
    local_824._0_1_ = s_Failed_to_create_getq_0005e7dc[4];
    local_824._1_1_ = s_Failed_to_create_getq_0005e7dc[5];
    local_824._2_1_ = s_Failed_to_create_getq_0005e7dc[6];
    local_824._3_1_ = s_Failed_to_create_getq_0005e7dc[7];
    uStack_820._0_1_ = s_Failed_to_create_getq_0005e7dc[8];
    uStack_820._1_1_ = s_Failed_to_create_getq_0005e7dc[9];
    uStack_820._2_1_ = s_Failed_to_create_getq_0005e7dc[10];
    uStack_820._3_1_ = s_Failed_to_create_getq_0005e7dc[11];
    uStack_81c._0_1_ = s_Failed_to_create_getq_0005e7dc[12];
    uStack_81c._1_1_ = s_Failed_to_create_getq_0005e7dc[13];
    uStack_81c._2_1_ = s_Failed_to_create_getq_0005e7dc[14];
    uStack_81c._3_1_ = s_Failed_to_create_getq_0005e7dc[15];
    local_818 = (int *)s_Failed_to_create_getq_0005e7dc._16_4_;
    local_814._0_2_ = (short)ram0x0005e7f0;
    getq = 0;
    goto LAB_000138f6;
  }
  local_a00 = "2.0.0";
  local_9c8[0x117] = (char *)(getq + 0xc);
  snprintf(DAT_00012b18,0x100,"%s %s","bmminer");
  local_9b4.__sigaction_handler.sa_handler = sighandler + 1;
  local_9b4.sa_flags = iVar6;
  sigemptyset(&local_9b4.sa_mask);
  sigaction(0xf,&local_9b4,(sigaction *)termhandler);
  sigaction(2,&local_9b4,(sigaction *)inthandler);
  sigaction(6,&local_9b4,(sigaction *)abrthandler);
  opt_kernel_path = &local_19f8;
  local_19f8._0_1_ = s__usr_bin_0005e7fc[0];
  local_19f8._1_1_ = s__usr_bin_0005e7fc[1];
  local_19f8._2_1_ = s__usr_bin_0005e7fc[2];
  local_19f8._3_1_ = s__usr_bin_0005e7fc[3];
  uStack_19f4._0_1_ = s__usr_bin_0005e7fc[4];
  uStack_19f4._1_1_ = s__usr_bin_0005e7fc[5];
  uStack_19f4._2_1_ = s__usr_bin_0005e7fc[6];
  uStack_19f4._3_1_ = s__usr_bin_0005e7fc[7];
  cgminer_path = acStack_2a00;
  local_19f0 = (undefined)ram0x0005e804;
  local_9e8 = "/";
  local_9f0 = &opt_kernel_path;
  pcVar8 = (char *)__strdup(*local_9d8);
  pcVar39 = cgminer_path;
  __src = dirname(pcVar8);
  strcpy(pcVar39,__src);
  free(pcVar8);
  pcVar39 = cgminer_path;
  iVar6 = 0x24;
  sVar9 = strlen(cgminer_path);
  uVar7 = DAT_00012b04;
  *(undefined2 *)(pcVar39 + sVar9) = *(undefined2 *)local_9e8;
  local_9d4[0x29e] = 9;
  piVar10 = (int *)_cgcalloc(0x68,1,"cgminer.c",uVar7,0x2d0f);
  local_9cc = piVar10;
  do {
    sVar9 = strlen((char *)piVar10);
    piVar24 = local_9cc;
    iVar6 = iVar6 + -1;
    *(undefined2 *)((int)piVar10 + sVar9) = s_bmminer_1_0_0_000603b8._12_2_;
  } while (iVar6 != 0);
  uVar22 = 0x9e3779b9;
  uVar27 = 0xfeedbeef;
  local_9c0 = (char *)(sVar9 + 1);
  uVar20 = uVar22;
  piVar10 = local_9cc;
  for (pcVar39 = local_9c0; (char *)0xb < pcVar39; pcVar39 = pcVar39 + -0xc) {
    iVar6 = uVar20 + (uint)*(byte *)((int)piVar10 + 6) * 0x10000 +
                     (uint)*(byte *)((int)piVar10 + 5) * 0x100 + (uint)*(byte *)(piVar10 + 1) +
                     (uint)*(byte *)((int)piVar10 + 7) * 0x1000000;
    uVar27 = (uint)*(byte *)((int)piVar10 + 10) * 0x10000 +
             (uint)*(byte *)((int)piVar10 + 9) * 0x100 + (uint)*(byte *)(piVar10 + 2) +
             (uint)*(byte *)((int)piVar10 + 0xb) * 0x1000000 + uVar27;
    uVar20 = ((((uint)*(byte *)piVar10 +
                (uint)*(byte *)((int)piVar10 + 2) * 0x10000 +
                (uint)*(byte *)((int)piVar10 + 1) * 0x100 +
               (uint)*(byte *)((int)piVar10 + 3) * 0x1000000) - iVar6) - uVar27) + uVar22 ^
             uVar27 >> 0xd;
    uVar22 = (iVar6 - uVar27) - uVar20 ^ uVar20 << 8;
    uVar23 = (uVar27 - uVar20) - uVar22 ^ uVar22 >> 0xd;
    uVar27 = (uVar20 - uVar22) - uVar23 ^ uVar23 >> 0xc;
    uVar20 = (uVar22 - uVar23) - uVar27 ^ uVar27 << 0x10;
    uVar23 = (uVar23 - uVar27) - uVar20 ^ uVar20 >> 5;
    uVar22 = (uVar27 - uVar20) - uVar23 ^ uVar23 >> 3;
    uVar20 = (uVar20 - uVar23) - uVar22 ^ uVar22 << 10;
    uVar27 = (uVar23 - uVar22) - uVar20 ^ uVar20 >> 0xf;
    piVar10 = piVar10 + 3;
  }
  pcVar8 = local_9c0 + uVar27;
  switch(pcVar39) {
  case (char *)0xb:
    pcVar8 = pcVar8 + (uint)*(byte *)((int)piVar10 + 10) * 0x1000000;
  case (char *)0xa:
    pcVar8 = pcVar8 + (uint)*(byte *)((int)piVar10 + 9) * 0x10000;
  case (char *)0x9:
    pcVar8 = pcVar8 + (uint)*(byte *)(piVar10 + 2) * 0x100;
  case (char *)0x8:
    uVar20 = uVar20 + (uint)*(byte *)((int)piVar10 + 7) * 0x1000000;
  case (char *)0x7:
    uVar20 = uVar20 + (uint)*(byte *)((int)piVar10 + 6) * 0x10000;
  case (char *)0x6:
    uVar20 = uVar20 + (uint)*(byte *)((int)piVar10 + 5) * 0x100;
  case (char *)0x5:
    uVar20 = uVar20 + *(byte *)(piVar10 + 1);
  case (char *)0x4:
    uVar22 = uVar22 + (uint)*(byte *)((int)piVar10 + 3) * 0x1000000;
  case (char *)0x3:
    uVar22 = uVar22 + (uint)*(byte *)((int)piVar10 + 2) * 0x10000;
  case (char *)0x2:
    uVar22 = uVar22 + (uint)*(byte *)((int)piVar10 + 1) * 0x100;
  case (char *)0x1:
    uVar22 = uVar22 + *(byte *)piVar10;
  }
  local_9cc[0x16] = (int)local_9cc;
  uVar27 = (uVar22 - uVar20) - (int)pcVar8 ^ (uint)pcVar8 >> 0xd;
  uVar23 = (uVar20 - (int)pcVar8) - uVar27 ^ uVar27 << 8;
  uVar22 = (uint)(pcVar8 + (-uVar23 - uVar27)) ^ uVar23 >> 0xd;
  uVar20 = (uVar27 - uVar23) - uVar22 ^ uVar22 >> 0xc;
  uVar27 = (uVar23 - uVar22) - uVar20 ^ uVar20 << 0x10;
  uVar22 = (uVar22 - uVar20) - uVar27 ^ uVar27 >> 5;
  uVar20 = (uVar20 - uVar27) - uVar22 ^ uVar22 >> 3;
  uVar27 = (uVar27 - uVar22) - uVar20 ^ uVar20 << 10;
  uVar22 = (uVar22 - uVar20) - uVar27 ^ uVar27 >> 0xf;
  local_9cc[0x18] = uVar22;
  sVar9 = strlen((char *)local_9cc);
  piVar24[0x17] = sVar9;
  iVar6 = local_9d4[0x282];
  if (iVar6 == 0) {
    piVar24[0x13] = 0;
    piVar24[0x12] = 0;
    local_9d4[0x282] = piVar24;
    pvVar11 = malloc(0x2c);
    piVar10 = local_9cc;
    piVar24[0x11] = (int)pvVar11;
    if (pvVar11 == (void *)0x0) goto LAB_00013946;
    memset(pvVar11,0,0x2c);
    piVar24 = piVar10 + 0x11;
    ppvVar29 = (void **)*piVar24;
    ppvVar29[4] = piVar24;
    ppvVar29[1] = (void *)0x20;
    ppvVar29[2] = (void *)0x5;
    ppvVar29[5] = (void *)0x44;
    pvVar11 = malloc(0x180);
    *ppvVar29 = pvVar11;
    if (pvVar11 == (void *)0x0) goto LAB_00013946;
    memset(pvVar11,0,0x180);
    *(undefined4 *)(piVar10[0x11] + 0x28) = 0xa0111fe1;
  }
  else {
    local_9cc[0x11] = *(int *)(iVar6 + 0x44);
    piVar24 = local_9cc + 0x11;
    iVar26 = *(int *)(iVar6 + 0x44);
    local_9cc[0x13] = 0;
    iVar6 = *(int *)(iVar26 + 0x10);
    local_9cc[0x12] = iVar6 - *(int *)(iVar26 + 0x14);
    *(int **)(iVar6 + 8) = local_9cc;
    *(int **)(iVar26 + 0x10) = piVar24;
  }
  piVar10 = local_9cc;
  piVar32 = *(int **)(local_9d4[0x282] + 0x44);
  iVar26 = *piVar32;
  piVar32[3] = piVar32[3] + 1;
  iVar6 = (uVar22 & piVar32[1] - 1U) * 0xc;
  iVar28 = iVar26 + iVar6;
  iVar33 = *(int *)(iVar26 + iVar6);
  uVar22 = *(int *)(iVar28 + 4) + 1;
  *(uint *)(iVar28 + 4) = uVar22;
  local_9cc[0x15] = iVar33;
  local_9cc[0x14] = 0;
  if (iVar33 != 0) {
    *(int **)(iVar33 + 0xc) = piVar24;
  }
  iVar28 = *(int *)(iVar28 + 8);
  *(int **)(iVar26 + iVar6) = piVar24;
  if (((uint)((iVar28 + 1) * 10) <= uVar22) && (*(int *)(local_9cc[0x11] + 0x24) != 1)) {
    pvVar11 = calloc(*(int *)(local_9cc[0x11] + 4) * 0x18,1);
    if (pvVar11 == (void *)0x0) {
LAB_00013946:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    ppiVar38 = (int **)piVar10[0x11];
    piVar10 = ppiVar38[1];
    ppiVar38[7] = (int *)0x0;
    local_9c0 = (char *)((int)piVar10 * 2 + -1);
    piVar24 = (int *)((uint)ppiVar38[3] >> ((int)ppiVar38[2] + 1U & 0xff));
    if (((uint)ppiVar38[3] & (uint)local_9c0) != 0) {
      piVar24 = (int *)((int)piVar24 + 1);
    }
    ppiVar38[6] = piVar24;
    if (piVar10 != (int *)0x0) {
      local_9e0 = *ppiVar38;
      local_9dc = (char *)((int)piVar10 * 0xc);
      piVar10 = (int *)0x0;
      local_9d0 = (int *)0x0;
      do {
        iVar6 = *(int *)((int)local_9e0 + (int)local_9d0);
        while (iVar6 != 0) {
          iVar26 = *(int *)(iVar6 + 0x10);
          uVar22 = *(uint *)(iVar6 + 0x1c) & (uint)local_9c0;
          piVar32 = (int *)(*(int *)((int)pvVar11 + uVar22 * 0xc + 4) + 1);
          *(int **)((int)pvVar11 + uVar22 * 0xc + 4) = piVar32;
          if (piVar24 < piVar32) {
            ppiVar38[7] = (int *)((int)ppiVar38[7] + 1);
            local_9c4 = (char *)piVar10;
            uVar7 = __udivsi3(piVar32,piVar24);
            *(undefined4 *)((int)pvVar11 + uVar22 * 0xc + 8) = uVar7;
            piVar10 = (int *)local_9c4;
          }
          iVar28 = *(int *)((int)pvVar11 + uVar22 * 0xc);
          *(int **)(iVar6 + 0xc) = piVar10;
          *(int *)(iVar6 + 0x10) = iVar28;
          if (iVar28 != 0) {
            *(int *)(iVar28 + 0xc) = iVar6;
          }
          *(int *)((int)pvVar11 + uVar22 * 0xc) = iVar6;
          iVar6 = iVar26;
        }
        local_9d0 = (int *)((int **)local_9d0 + 3);
      } while ((int *)local_9dc != local_9d0);
    }
    free(*ppiVar38);
    ppvVar29 = (void **)local_9cc[0x11];
    *ppvVar29 = pvVar11;
    ppvVar29[2] = (void *)((int)ppvVar29[2] + 1);
    ppvVar29[1] = (void *)((int)ppvVar29[1] << 1);
    if ((void *)((uint)ppvVar29[3] >> 1) < ppvVar29[7]) {
      pvVar25 = (void *)((int)ppvVar29[8] + 1);
      ppvVar29[8] = pvVar25;
      pvVar11 = pvVar25;
      if ((void *)0x1 < pvVar25) {
        pvVar11 = (void *)0x1;
      }
      if ((void *)0x1 < pvVar25) {
        ppvVar29[9] = pvVar11;
      }
    }
    else {
      ppvVar29[8] = (void *)0x0;
    }
  }
  strcpy(current_hash,(char *)local_9cc);
  scan_devices._0_4_ = &scan_devices;
  scan_devices._4_4_ = &scan_devices;
  opt_register_table(&opt_config_table,"Options for both config file and command line");
  opt_register_table(DAT_00012ec0,"Options for command line only");
  opt_parse(&local_9bc,local_9d8,0x1bda5);
  if (local_9bc != 1) {
    local_828 = (int *)s_Unexpected_extra_commandline_arg_0005e858._0_4_;
    local_824._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[4];
    local_824._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[5];
    local_824._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[6];
    local_824._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[7];
    uStack_820._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[8];
    uStack_820._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[9];
    uStack_820._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[10];
    uStack_820._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[11];
    uStack_81c._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[12];
    uStack_81c._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[13];
    uStack_81c._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[14];
    uStack_81c._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[15];
    local_818 = (int *)s_Unexpected_extra_commandline_arg_0005e858._16_4_;
    local_814._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[20];
    local_814._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[21];
    local_814._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[22];
    local_814._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[23];
    uStack_810._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[24];
    uStack_810._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[25];
    uStack_810._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[26];
    uStack_810._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[27];
    uStack_80c._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[28];
    uStack_80c._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[29];
    uStack_80c._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[30];
    uStack_80c._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[31];
    local_808._0_1_ = s_Unexpected_extra_commandline_arg_0005e858[32];
    local_808._1_1_ = s_Unexpected_extra_commandline_arg_0005e858[33];
    local_808._2_1_ = s_Unexpected_extra_commandline_arg_0005e858[34];
    local_808._3_1_ = s_Unexpected_extra_commandline_arg_0005e858[35];
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  if (*(char *)(local_9c8 + 0xd3) == '\0') {
    pcVar39 = (char *)_cgmalloc(0x1000,"cgminer.c",DAT_00013be0,0x829);
    ppcVar4 = local_9c8;
    local_9c8[0xd1] = pcVar39;
    default_save_file();
    iVar6 = access(ppcVar4[0xd1],4);
    ppcVar4 = local_9c8;
    if (iVar6 == 0) {
      load_config(local_9c8[0xd1],0);
    }
    else {
      free(local_9c8[0xd1]);
      ppcVar4[0xd1] = (char *)0x0;
    }
  }
  if ((*(char *)(local_9c8 + 0x160) != '\0') || (local_9c8[0x113] != (char *)0x0)) {
    iVar6 = add_pool();
    puVar34 = (undefined4 *)_cgmalloc(0xff,"cgminer.c",DAT_00013210,0x2d33);
    *(undefined4 **)(iVar6 + 0xa4) = puVar34;
    if (local_9c8[0x113] == (char *)0x0) {
      pcVar39 = "Benchmark";
    }
    else {
      pcVar39 = "Benchfile";
    }
    uVar7 = *(undefined4 *)((int)pcVar39 + 4);
    uVar1 = *(undefined2 *)((int)pcVar39 + 8);
    *puVar34 = *(undefined4 *)pcVar39;
    puVar34[1] = uVar7;
    *(undefined2 *)(puVar34 + 2) = uVar1;
    uVar7 = *(undefined4 *)(iVar6 + 0xa4);
    *(undefined4 *)(iVar6 + 0xac) = uVar7;
    *(undefined4 *)(iVar6 + 0xb0) = uVar7;
    *(undefined4 *)(iVar6 + 0xa8) = uVar7;
    *(undefined4 *)(iVar6 + 600) = uVar7;
    strncpy((char *)(iVar6 + 0x30),"?",7);
    *(undefined *)(iVar6 + 0x37) = 0;
    if (*(int *)(iVar6 + 100) != 1) {
      *(undefined4 *)(iVar6 + 100) = 1;
      enabled_pools = enabled_pools + 1;
    }
    iVar33 = DAT_00013228;
    iVar28 = DAT_00013224;
    iVar26 = DAT_00013214;
    iVar30 = DAT_00013224 + 0xa00;
    *(undefined *)(iVar6 + 0x61) = 0;
    iVar36 = 0;
    successful_connect = 1;
    iVar6 = iVar30;
    do {
      iVar37 = iVar28 + 0xa0;
      hex2bin(iVar28,iVar33 + iVar36);
      iVar28 = iVar26 + iVar36;
      iVar36 = iVar36 + 0x144;
      hex2bin(iVar6,iVar28,0xa0);
      iVar6 = iVar6 + 0xa0;
      iVar28 = iVar37;
    } while (iVar37 != iVar30);
    set_target((int)DAT_00013208,DAT_00013218);
  }
  if (local_9c8[4] != (char *)0x0) {
    pFVar12 = fopen(local_9c8[4],"rb");
    memset(acStack_928,0,0x100);
    if (pFVar12 == (FILE *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Open miner version file %s error",local_9c8[4]);
        _applog(3,&local_828,0);
        goto LAB_000130d0;
      }
LAB_0001391a:
      if (opt_log_level < 3) goto LAB_0001310e;
    }
    else {
      sVar9 = fread(acStack_928,1,0x100,pFVar12);
      if ((int)sVar9 < 1) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
        goto LAB_0001391a;
        snprintf((char *)&local_828,0x800,"Read miner version file %s error %d",local_9c8[4],sVar9);
        _applog(3,&local_828,0);
      }
      else {
        pcVar39 = strchr(acStack_928,10);
        if (pcVar39 == (char *)0x0) {
          strcpy(DAT_00013be4,acStack_928);
        }
        else {
          _cg_memcpy(DAT_0001321c,acStack_928,(int)pcVar39 - (int)acStack_928,"cgminer.c",
                     DAT_00013210,0x2d6e);
          pcVar39 = stpcpy(acStack_928,pcVar39 + 1);
          pcVar8 = strchr(acStack_928,10);
          if (pcVar8 == (char *)0x0) {
            memcpy(DAT_00013f24,acStack_928,(size_t)(pcVar39 + (1 - (int)acStack_928)));
          }
          else {
            _cg_memcpy(DAT_00013220,acStack_928,(int)pcVar8 - (int)acStack_928,"cgminer.c",
                       DAT_00013210,0x2d77);
          }
        }
        sVar9 = strlen(DAT_0001321c);
        pcVar39 = DAT_0001321c;
        if (*(code *)((int)local_9d4 + sVar9 + 0xa7b) == (code)0xa) {
          *(code *)((int)local_9d4 + sVar9 + 0xa7b) = (code)0x0;
        }
        sVar9 = strlen(pcVar39);
        pcVar39 = DAT_00013220;
        if (*(code *)((int)local_9d4 + sVar9 + 0xa7b) == (code)0xd) {
          *(code *)((int)local_9d4 + sVar9 + 0xa7b) = (code)0x0;
        }
        sVar9 = strlen(pcVar39);
        pcVar39 = DAT_00013220;
        if (*(code *)((int)local_9d4 + sVar9 + 0xb7b) == (code)0xa) {
          *(code *)((int)local_9d4 + sVar9 + 0xb7b) = (code)0x0;
        }
        sVar9 = strlen(pcVar39);
        if (*(code *)((int)local_9d4 + sVar9 + 0xb7b) == (code)0xd) {
          *(code *)((int)local_9d4 + sVar9 + 0xb7b) = (code)0x0;
        }
      }
LAB_000130d0:
      if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_0001391a;
    }
    snprintf((char *)&local_828,0x800,"Miner compile time: %s type: %s",DAT_00013220 + -0x100,
             DAT_00013220);
    _applog(3,&local_828,0);
  }
LAB_0001310e:
  ppcVar4 = local_9c8;
  pcVar39 = *local_9c8;
  if (pcVar39 == (char *)0x0) {
LAB_00013190:
    pcVar39 = local_9c8[2];
    if (pcVar39 == (char *)0x0) {
      local_9c0 = &opt_log_output;
    }
    else {
LAB_0001319a:
      memset(acStack_928,0,0x100);
      pcVar8 = local_9c8[1];
      if (pcVar8 == (char *)0x0) {
        if (((use_syslog != '\0') || (local_9c0 = &opt_log_output, opt_log_output != '\0')) ||
           (2 < opt_log_level)) {
          local_9c0 = &opt_log_output;
          snprintf((char *)&local_828,0x800,"Log work path: %s",pcVar39);
          _applog(3,&local_828,0);
        }
      }
      else {
        if (*pcVar8 == '\0') {
          ppiVar38 = &local_828;
          pcVar39 = "Log work asic num empty";
LAB_00013288:
          piVar10 = *(int **)((int)pcVar39 + 4);
          piVar24 = *(int **)((int)pcVar39 + 8);
          piVar32 = *(int **)((int)pcVar39 + 0xc);
          *ppiVar38 = *(int **)pcVar39;
          ppiVar38[1] = piVar10;
          ppiVar38[2] = piVar24;
          ppiVar38[3] = piVar32;
          piVar10 = *(int **)((int)pcVar39 + 0x14);
          ppiVar38[4] = *(int **)((int)pcVar39 + 0x10);
          ppiVar38[5] = piVar10;
          ppiVar13 = &local_828;
          goto LAB_0001329a;
        }
        lVar5 = strtol(pcVar8,(char **)0x0,10);
        local_9d4[799] = lVar5;
        if (((lVar5 - 0x20U & 0xffffffdf) != 0) && (lVar5 != 1)) {
          local_828 = (int *)s_Log_work_asic_num_must_be_1__32__0005e940._0_4_;
          local_824._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[4];
          local_824._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[5];
          local_824._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[6];
          local_824._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[7];
          uStack_820._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[8];
          uStack_820._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[9];
          uStack_820._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[10];
          uStack_820._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[11];
          uStack_81c._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[12];
          uStack_81c._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[13];
          uStack_81c._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[14];
          uStack_81c._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[15];
          local_818 = (int *)s_Log_work_asic_num_must_be_1__32__0005e940._16_4_;
          local_814._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[20];
          local_814._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[21];
          local_814._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[22];
          local_814._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[23];
          uStack_810._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[24];
          uStack_810._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[25];
          uStack_810._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[26];
          uStack_810._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[27];
          uStack_80c._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[28];
          uStack_80c._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[29];
          uStack_80c._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[30];
          uStack_80c._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[31];
          local_808._0_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[32];
          local_808._1_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[33];
          local_808._2_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[34];
          local_808._3_1_ = s_Log_work_asic_num_must_be_1__32__0005e940[35];
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
      pFVar12 = fopen(acStack_928,(char *)&DAT_0005e760);
      cVar3 = use_syslog;
      local_9d4[800] = pFVar12;
      if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Log work open file %s",acStack_928);
        _applog(3,&local_828,0);
      }
      ppcVar4 = local_9c8;
      puVar34 = local_9d4;
      iVar6 = local_9d4[799];
      if (iVar6 == 1) {
        sprintf(acStack_928,"%s%02d.txt",local_9c8[2]);
        pFVar12 = fopen(acStack_928,(char *)&DAT_0005e760);
        cVar3 = use_syslog;
        local_9d4[0x321] = pFVar12;
        if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
          snprintf((char *)&local_828,0x800,"Log work open asic %d file %s",local_9d4[799],
                   acStack_928);
          _applog(3,&local_828,0);
        }
      }
      else if (((iVar6 - 0x20U & 0xffffffdf) == 0) && (-1 < iVar6)) {
        local_9c4 = "%s%02d_%02d.txt";
        local_9cc = (int *)&DAT_0005e760;
        local_9d0 = (int *)0x5e9c4;
        iVar26 = 0;
        ppFVar35 = DAT_000137bc;
        do {
          sprintf(acStack_928,local_9c4,ppcVar4[2],iVar6,iVar26);
          pFVar12 = fopen(acStack_928,(char *)local_9cc);
          cVar3 = use_syslog;
          ppFVar35 = ppFVar35 + 1;
          *ppFVar35 = pFVar12;
          if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,(char *)local_9d0,puVar34[799],acStack_928);
            _applog(3,&local_828,0);
          }
          iVar6 = puVar34[799];
          iVar26 = iVar26 + 1;
        } while (iVar26 <= iVar6);
      }
      if (*(code *)(local_9d4 + 0x362) != (code)0x0) {
        iVar6 = 0;
        local_9c4 = "Log work open diff file %s";
        ppFVar35 = DAT_000137c0;
        do {
          sprintf(acStack_928,"%s_diff_%02d.txt",local_9c8[2],iVar6);
          pFVar12 = fopen(acStack_928,(char *)&DAT_0005e760);
          cVar3 = use_syslog;
          ppFVar35 = ppFVar35 + 1;
          *ppFVar35 = pFVar12;
          if (((cVar3 != '\0') || (*local_9c0 != '\0')) || (2 < opt_log_level)) {
            snprintf((char *)&local_828,0x800,local_9c4,acStack_928);
            _applog(3,&local_828,0);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x41);
      }
    }
    if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_00013478;
LAB_00013480:
    snprintf((char *)&local_828,0x800,"Started %s",DAT_000137b4);
    _applog(4,&local_828,0);
    if (local_9c8[0xd1] != (char *)0x0) {
      if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_0001396c;
LAB_000134bc:
      snprintf((char *)&local_828,0x800,"Loaded configuration file %s");
      _applog(5,&local_828,0);
      pcVar39 = local_9c8[0x106];
      if (pcVar39 == (char *)0xffffffff) {
        if (use_syslog == '\0') {
LAB_000136f2:
          if ((*local_9c0 != '\0') || (3 < opt_log_level)) goto LAB_000137c8;
          if (use_curses == '\0') goto LAB_0001353a;
LAB_00013718:
          if (3 < opt_log_level) {
LAB_00013724:
            local_828 = (int *)s_Start_cgminer_with__T_to_see_wha_0005ead0._0_4_;
            local_824._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[4];
            local_824._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[5];
            local_824._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[6];
            local_824._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[7];
            uStack_820._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[8];
            uStack_820._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[9];
            uStack_820._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[10];
            uStack_820._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[11];
            uStack_81c._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[12];
            uStack_81c._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[13];
            uStack_81c._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[14];
            uStack_81c._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[15];
            local_818 = (int *)s_Start_cgminer_with__T_to_see_wha_0005ead0._16_4_;
            local_814._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[20];
            local_814._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[21];
            local_814._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[22];
            local_814._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[23];
            uStack_810._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[24];
            uStack_810._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[25];
            uStack_810._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[26];
            uStack_810._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[27];
            uStack_80c._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[28];
            uStack_80c._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[29];
            uStack_80c._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[30];
            uStack_80c._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[31];
            local_808._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[32];
            local_808._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[33];
            local_808._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[34];
            local_808._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[35];
            local_804._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[36];
            local_804._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[37];
            local_804._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[38];
            local_804._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[39];
            local_800._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[40];
            local_800._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[41];
            local_800._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[42];
            local_800._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[43];
            uStack_7fc._0_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[44];
            uStack_7fc._1_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[45];
            uStack_7fc._2_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[46];
            uStack_7fc._3_1_ = s_Start_cgminer_with__T_to_see_wha_0005ead0[47];
            local_7f8 = (undefined2)ram0x0005eb00;
            _applog(4,&local_828,0);
          }
        }
        else {
LAB_000137c8:
          local_828 = (int *)s_Error_in_configuration_file__par_0005eaa0._0_4_;
          local_824._0_1_ = s_Error_in_configuration_file__par_0005eaa0[4];
          local_824._1_1_ = s_Error_in_configuration_file__par_0005eaa0[5];
          local_824._2_1_ = s_Error_in_configuration_file__par_0005eaa0[6];
          local_824._3_1_ = s_Error_in_configuration_file__par_0005eaa0[7];
          uStack_820._0_1_ = s_Error_in_configuration_file__par_0005eaa0[8];
          uStack_820._1_1_ = s_Error_in_configuration_file__par_0005eaa0[9];
          uStack_820._2_1_ = s_Error_in_configuration_file__par_0005eaa0[10];
          uStack_820._3_1_ = s_Error_in_configuration_file__par_0005eaa0[11];
          uStack_81c._0_1_ = s_Error_in_configuration_file__par_0005eaa0[12];
          uStack_81c._1_1_ = s_Error_in_configuration_file__par_0005eaa0[13];
          uStack_81c._2_1_ = s_Error_in_configuration_file__par_0005eaa0[14];
          uStack_81c._3_1_ = s_Error_in_configuration_file__par_0005eaa0[15];
          local_818 = (int *)s_Error_in_configuration_file__par_0005eaa0._16_4_;
          local_814._0_1_ = s_Error_in_configuration_file__par_0005eaa0[20];
          local_814._1_1_ = s_Error_in_configuration_file__par_0005eaa0[21];
          local_814._2_1_ = s_Error_in_configuration_file__par_0005eaa0[22];
          local_814._3_1_ = s_Error_in_configuration_file__par_0005eaa0[23];
          uStack_810._0_1_ = s_Error_in_configuration_file__par_0005eaa0[24];
          uStack_810._1_1_ = s_Error_in_configuration_file__par_0005eaa0[25];
          uStack_810._2_1_ = s_Error_in_configuration_file__par_0005eaa0[26];
          uStack_810._3_1_ = s_Error_in_configuration_file__par_0005eaa0[27];
          uStack_80c._0_1_ = s_Error_in_configuration_file__par_0005eaa0[28];
          uStack_80c._1_1_ = s_Error_in_configuration_file__par_0005eaa0[29];
          uStack_80c._2_1_ = s_Error_in_configuration_file__par_0005eaa0[30];
          uStack_80c._3_1_ = s_Error_in_configuration_file__par_0005eaa0[31];
          local_808._0_1_ = s_Error_in_configuration_file__par_0005eaa0[32];
          local_808._1_1_ = s_Error_in_configuration_file__par_0005eaa0[33];
          local_808._2_1_ = s_Error_in_configuration_file__par_0005eaa0[34];
          local_808._3_1_ = s_Error_in_configuration_file__par_0005eaa0[35];
          local_804._0_1_ = s_Error_in_configuration_file__par_0005eaa0[36];
          local_804._1_1_ = s_Error_in_configuration_file__par_0005eaa0[37];
          local_804._2_1_ = s_Error_in_configuration_file__par_0005eaa0[38];
          local_804._3_1_ = s_Error_in_configuration_file__par_0005eaa0[39];
          local_800._0_1_ = s_Error_in_configuration_file__par_0005eaa0[40];
          local_800._1_1_ = s_Error_in_configuration_file__par_0005eaa0[41];
          local_800._2_1_ = s_Error_in_configuration_file__par_0005eaa0[42];
          local_800._3_1_ = s_Error_in_configuration_file__par_0005eaa0[43];
          uStack_7fc._0_3_ = (undefined3)ram0x0005eacc;
          _applog(4,&local_828,0);
          if (use_curses != '\0') {
            if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_00013718;
            goto LAB_00013724;
          }
        }
      }
      else {
LAB_000134e4:
        if (pcVar39 == (char *)0x0) {
          if (((use_syslog == '\0') && (*local_9c0 == '\0')) && (opt_log_level < 4)) {
LAB_0001350a:
            if (opt_log_level < 4) goto LAB_0001353a;
          }
          else {
            local_828 = (int *)s_Fatal_JSON_error_in_configuratio_0005ea50._0_4_;
            local_824._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[4];
            local_824._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[5];
            local_824._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[6];
            local_824._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[7];
            uStack_820._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[8];
            uStack_820._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[9];
            uStack_820._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[10];
            uStack_820._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[11];
            uStack_81c._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[12];
            uStack_81c._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[13];
            uStack_81c._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[14];
            uStack_81c._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[15];
            local_818 = (int *)s_Fatal_JSON_error_in_configuratio_0005ea50._16_4_;
            local_814._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[20];
            local_814._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[21];
            local_814._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[22];
            local_814._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[23];
            uStack_810._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[24];
            uStack_810._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[25];
            uStack_810._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[26];
            uStack_810._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[27];
            uStack_80c._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[28];
            uStack_80c._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[29];
            uStack_80c._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[30];
            uStack_80c._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[31];
            local_808._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[32];
            local_808._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[33];
            local_808._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[34];
            local_808._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[35];
            local_804._0_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[36];
            local_804._1_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[37];
            local_804._2_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[38];
            local_804._3_1_ = s_Fatal_JSON_error_in_configuratio_0005ea50[39];
            _applog(4,&local_828,0);
            if ((use_syslog == '\0') && (*local_9c0 == '\0')) goto LAB_0001350a;
          }
          local_828 = (int *)s_Configuration_file_could_not_be_u_0005ea78._0_4_;
          local_824._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[4];
          local_824._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[5];
          local_824._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[6];
          local_824._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[7];
          uStack_820._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[8];
          uStack_820._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[9];
          uStack_820._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[10];
          uStack_820._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[11];
          uStack_81c._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[12];
          uStack_81c._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[13];
          uStack_81c._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[14];
          uStack_81c._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[15];
          local_818 = (int *)s_Configuration_file_could_not_be_u_0005ea78._16_4_;
          local_814._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[20];
          local_814._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[21];
          local_814._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[22];
          local_814._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[23];
          uStack_810._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[24];
          uStack_810._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[25];
          uStack_810._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[26];
          uStack_810._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[27];
          uStack_80c._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[28];
          uStack_80c._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[29];
          uStack_80c._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[30];
          uStack_80c._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[31];
          local_808._0_1_ = s_Configuration_file_could_not_be_u_0005ea78[32];
          local_808._1_1_ = s_Configuration_file_could_not_be_u_0005ea78[33];
          local_808._2_1_ = s_Configuration_file_could_not_be_u_0005ea78[34];
          local_808._3_1_ = s_Configuration_file_could_not_be_u_0005ea78[35];
          local_804._0_2_ = (short)ram0x0005ea9c;
          _applog(4,&local_828,0);
        }
      }
LAB_0001353a:
      ppcVar4 = local_9c8;
      free(local_9c8[0xd1]);
      ppcVar4[0xd1] = (char *)0x0;
    }
  }
  else {
    *(char *)local_9e4 = '\x01';
    strcpy(g_logfile_path,pcVar39);
    if (ppcVar4[3] != (char *)0x0) {
      strcpy(g_logfile_openflag,ppcVar4[3]);
    }
    if (((use_syslog != '\0') || (local_9c0 = &opt_log_output, opt_log_output != '\0')) ||
       (2 < opt_log_level)) {
      snprintf((char *)&local_828,0x800,"Log file path: %s Open flag: %s",g_logfile_path,local_9ec);
      _applog(3,&local_828,0);
      goto LAB_00013190;
    }
    pcVar39 = local_9c8[2];
    if (pcVar39 != (char *)0x0) goto LAB_0001319a;
LAB_00013478:
    if (3 < opt_log_level) goto LAB_00013480;
    if (local_9c8[0xd1] != (char *)0x0) {
LAB_0001396c:
      if (4 < opt_log_level) goto LAB_000134bc;
      pcVar39 = local_9c8[0x106];
      if (pcVar39 == (char *)0xffffffff) goto LAB_000136f2;
      goto LAB_000134e4;
    }
  }
  puVar34 = *local_9f0;
  sVar9 = strlen((char *)puVar34);
  *(undefined2 *)((int)puVar34 + sVar9) = *(undefined2 *)local_9e8;
  if (want_per_device_stats == '\0') {
    if (*local_9c0 != '\0') goto LAB_00013570;
    setlogmask(0x3f);
  }
  else {
    *local_9c0 = '\x01';
LAB_00013570:
    setlogmask(0xff);
  }
  uVar7 = DAT_000137b8;
  local_9cc = &control_thr;
  if (opt_scantime < 0) {
    opt_scantime = 0x3c;
  }
  local_9d4[0x3a4] = 8;
  control_thr = _cgcalloc(8,0x40,"cgminer.c",uVar7,0x2e13);
  fill_device_drv(bitforce_drv);
  fill_device_drv(modminer_drv);
  fill_device_drv(bitmain_drv);
  fill_device_drv(&bitmain_c5_drv);
  (*(code *)bitforce_drv._12_4_)(0);
  (*(code *)modminer_drv._12_4_)(0);
  (*(code *)bitmain_drv._12_4_)(0);
  piVar10 = &total_devices;
  iVar6 = 0;
  (*DAT_0007e3ec)(0);
  local_9c4 = (char *)&mining_threads;
  mining_threads = 0;
  if (0 < total_devices) {
    do {
      iVar26 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      enable_device(*(undefined4 *)(devices + iVar26));
    } while (iVar6 < total_devices);
  }
  iVar6 = total_devices;
  if (total_devices == 0) {
    local_828 = (int *)s_All_devices_disabled__cannot_min_0005eb04._0_4_;
    local_824._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[4];
    local_824._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[5];
    local_824._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[6];
    local_824._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[7];
    uStack_820._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[8];
    uStack_820._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[9];
    uStack_820._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[10];
    uStack_820._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[11];
    uStack_81c._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[12];
    uStack_81c._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[13];
    uStack_81c._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[14];
    uStack_81c._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[15];
    local_818 = (int *)s_All_devices_disabled__cannot_min_0005eb04._16_4_;
    local_814._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[20];
    local_814._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[21];
    local_814._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[22];
    local_814._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[23];
    uStack_810._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[24];
    uStack_810._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[25];
    uStack_810._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[26];
    uStack_810._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[27];
    uStack_80c._0_1_ = s_All_devices_disabled__cannot_min_0005eb04[28];
    uStack_80c._1_1_ = s_All_devices_disabled__cannot_min_0005eb04[29];
    uStack_80c._2_1_ = s_All_devices_disabled__cannot_min_0005eb04[30];
    uStack_80c._3_1_ = s_All_devices_disabled__cannot_min_0005eb04[31];
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pcVar39 = local_9c8[0x108];
  local_9d4[0x29d] = total_devices;
  if (pcVar39 == (char *)0x0) {
    iVar33 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
    iVar28 = total_devices;
    iVar26 = devices;
    piVar24 = (int *)modminer_drv;
    if (iVar33 != 0) {
LAB_00014714:
      pcVar39 = (char *)_rd_lock_part_39_constprop_80(DAT_000149e4,0x52a);
LAB_0001471e:
      snprintf((char *)&local_828,0x800,"No login credentials supplied for pool %u %s",piVar24,
               *(undefined4 *)(iVar6 + 0xa4));
      _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
      __quit(1,pcVar39);
    }
    for (iVar6 = 0; iVar6 < iVar28; iVar6 = iVar6 + 1) {
      iVar33 = *(int *)(iVar26 + iVar6 * 4);
      if (*(int *)(iVar33 + 0xb8) == 0) {
        *(undefined4 *)(iVar33 + 0xb8) = 0x5f;
      }
    }
    _wr_unlock_constprop_78(devices_lock,DAT_00013f2c,0x533);
  }
  else {
    iVar6 = 0;
    piVar24 = &devices;
    ppiVar38 = (int **)0x0;
    pcVar39 = strtok(pcVar39,",");
    while (pcVar39 != (char *)0x0) {
      if (total_devices <= iVar6) {
        local_828 = (int *)s_Too_many_values_passed_to_set_te_0005eb28._0_4_;
        local_824._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[4];
        local_824._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[5];
        local_824._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[6];
        local_824._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[7];
        uStack_820._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[8];
        uStack_820._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[9];
        uStack_820._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[10];
        uStack_820._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[11];
        uStack_81c._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[12];
        uStack_81c._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[13];
        uStack_81c._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[14];
        uStack_81c._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[15];
        local_818 = (int *)s_Too_many_values_passed_to_set_te_0005eb28._16_4_;
        local_814._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[20];
        local_814._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[21];
        local_814._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[22];
        local_814._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[23];
        uStack_810._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[24];
        uStack_810._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[25];
        uStack_810._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[26];
        uStack_810._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[27];
        uStack_80c._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[28];
        uStack_80c._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[29];
        uStack_80c._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[30];
        uStack_80c._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[31];
        local_808._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[32];
        local_808._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[33];
        local_808._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[34];
        local_808._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[35];
        local_804._0_1_ = s_Too_many_values_passed_to_set_te_0005eb28[36];
        local_804._1_1_ = s_Too_many_values_passed_to_set_te_0005eb28[37];
        local_804._2_1_ = s_Too_many_values_passed_to_set_te_0005eb28[38];
        local_804._3_1_ = s_Too_many_values_passed_to_set_te_0005eb28[39];
        local_800 = CONCAT22(local_800._2_2_,(short)ram0x0005eb50);
        _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      ppiVar38 = (int **)strtol(pcVar39,(char **)0x0,10);
      if ((int **)0xc8 < ppiVar38) {
        local_828 = (int *)s_Invalid_value_passed_to_set_temp_0005c638._0_4_;
        local_824._0_1_ = s_Invalid_value_passed_to_set_temp_0005c638[4];
        local_824._1_1_ = s_Invalid_value_passed_to_set_temp_0005c638[5];
        local_824._2_1_ = s_Invalid_value_passed_to_set_temp_0005c638[6];
        local_824._3_1_ = s_Invalid_value_passed_to_set_temp_0005c638[7];
        uStack_820._0_1_ = s_Invalid_value_passed_to_set_temp_0005c638[8];
        uStack_820._1_1_ = s_Invalid_value_passed_to_set_temp_0005c638[9];
        uStack_820._2_1_ = s_Invalid_value_passed_to_set_temp_0005c638[10];
        uStack_820._3_1_ = s_Invalid_value_passed_to_set_temp_0005c638[11];
        uStack_81c._0_1_ = s_Invalid_value_passed_to_set_temp_0005c638[12];
        uStack_81c._1_1_ = s_Invalid_value_passed_to_set_temp_0005c638[13];
        uStack_81c._2_1_ = s_Invalid_value_passed_to_set_temp_0005c638[14];
        uStack_81c._3_1_ = s_Invalid_value_passed_to_set_temp_0005c638[15];
        pcVar39 = "ssed to set temp cutoff";
        ppiVar38 = (int **)&local_818;
        goto LAB_00013288;
      }
      iVar26 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
      if (iVar26 != 0) {
        _rd_lock_part_39_constprop_80(DAT_00013f2c,0x523);
        goto LAB_00013ef2;
      }
      *(int ***)(*(int *)(devices + iVar6 * 4) + 0xb8) = ppiVar38;
      ppiVar13 = (int **)pthread_rwlock_unlock((pthread_rwlock_t *)devices_lock);
      if (ppiVar13 != (int **)0x0) {
        piVar10 = __errno_location();
        snprintf((char *)&local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                 *piVar10,"cgminer.c",DAT_00013f2c,0x525);
        ppiVar13 = &local_828;
        goto LAB_0001329a;
      }
      iVar6 = iVar6 + 1;
      local_9d0 = (int *)ppiVar13;
      (*selective_yield)();
      pcVar39 = strtok((char *)local_9d0,",");
    }
    if (iVar6 < 2) {
      local_9d0 = (int *)ppiVar38;
      iVar33 = pthread_rwlock_rdlock((pthread_rwlock_t *)devices_lock);
      iVar28 = total_devices;
      iVar26 = devices;
      if (iVar33 != 0) {
        _rd_lock_part_39_constprop_80(DAT_000149e4,0x53a);
        goto LAB_00014714;
      }
      for (; iVar6 < iVar28; iVar6 = iVar6 + 1) {
        *(int **)(*(int *)(iVar26 + iVar6 * 4) + 0xb8) = local_9d0;
      }
      _wr_unlock_constprop_78(devices_lock,DAT_00014278,0x540);
    }
  }
  iVar26 = total_devices;
  iVar6 = devices;
  for (iVar28 = 0; iVar28 < iVar26; iVar28 = iVar28 + 1) {
    *(undefined4 *)(*(int *)(iVar6 + iVar28 * 4) + 0x138) = 99999999;
  }
  if (opt_compact == '\0') {
    local_9d4[0x29e] = local_9d4[0x29d] + local_9d4[0x29e];
  }
  local_9d8 = &total_pools;
  if (total_pools == 0) {
    if (((use_syslog != '\0') || (*local_9c0 != '\0')) || (3 < opt_log_level)) {
      local_828 = (int *)s_Need_to_specify_at_least_one_poo_0005eb54._0_4_;
      local_824._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[4];
      local_824._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[5];
      local_824._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[6];
      local_824._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[7];
      uStack_820._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[8];
      uStack_820._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[9];
      uStack_820._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[10];
      uStack_820._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[11];
      uStack_81c._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[12];
      uStack_81c._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[13];
      uStack_81c._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[14];
      uStack_81c._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[15];
      local_818 = (int *)s_Need_to_specify_at_least_one_poo_0005eb54._16_4_;
      local_814._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[20];
      local_814._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[21];
      local_814._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[22];
      local_814._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[23];
      uStack_810._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[24];
      uStack_810._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[25];
      uStack_810._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[26];
      uStack_810._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[27];
      uStack_80c._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[28];
      uStack_80c._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[29];
      uStack_80c._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[30];
      uStack_80c._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[31];
      local_808._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[32];
      local_808._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[33];
      local_808._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[34];
      local_808._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[35];
      local_804._0_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[36];
      local_804._1_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[37];
      local_804._2_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[38];
      local_804._3_1_ = s_Need_to_specify_at_least_one_poo_0005eb54[39];
      local_800._0_2_ = (short)ram0x0005eb7c;
      _applog(4,&local_828,0);
    }
    local_828 = (int *)s_Pool_setup_failed_0005eb80._0_4_;
    local_824._0_1_ = s_Pool_setup_failed_0005eb80[4];
    local_824._1_1_ = s_Pool_setup_failed_0005eb80[5];
    local_824._2_1_ = s_Pool_setup_failed_0005eb80[6];
    local_824._3_1_ = s_Pool_setup_failed_0005eb80[7];
    uStack_820._0_1_ = s_Pool_setup_failed_0005eb80[8];
    uStack_820._1_1_ = s_Pool_setup_failed_0005eb80[9];
    uStack_820._2_1_ = s_Pool_setup_failed_0005eb80[10];
    uStack_820._3_1_ = s_Pool_setup_failed_0005eb80[11];
    uStack_81c._0_1_ = s_Pool_setup_failed_0005eb80[12];
    uStack_81c._1_1_ = s_Pool_setup_failed_0005eb80[13];
    uStack_81c._2_1_ = s_Pool_setup_failed_0005eb80[14];
    uStack_81c._3_1_ = s_Pool_setup_failed_0005eb80[15];
    local_818 = (int *)CONCAT22(local_818._2_2_,(short)ram0x0005eb90);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  local_9e0 = &devices;
  local_9e4 = &total_devices;
  local_9d0 = &pools;
  local_9dc = "cgminer.c";
  for (piVar24 = (int *)0x0; ppiVar38 = (int **)local_9e0, piVar10 = local_9e4, cVar3 = use_syslog,
      (int)piVar24 < total_pools; piVar24 = (int *)((int)piVar24 + 1)) {
    iVar6 = *(int *)(pools + (int)piVar24 * 4);
    *(undefined4 *)(iVar6 + 0x194) = 99999999;
    *(undefined4 *)(iVar6 + 0x1b8) = 99999999;
    if (*(int *)(iVar6 + 0xa8) == 0) {
      if (*(int *)(iVar6 + 0xb0) == 0) {
        pvVar11 = calloc(1,1);
        *(void **)(iVar6 + 0xb0) = pvVar11;
      }
      pcVar39 = *(char **)(iVar6 + 0xac);
      if (pcVar39 == (char *)0x0) goto LAB_0001471e;
      sVar9 = strlen(pcVar39);
      sVar14 = strlen(*(char **)(iVar6 + 0xb0));
      sVar9 = sVar14 + sVar9 + 2;
      pcVar39 = (char *)_cgmalloc(sVar9,local_9dc,DAT_00013f28,0x2e80);
      *(char **)(iVar6 + 0xa8) = pcVar39;
      snprintf(pcVar39,sVar9,"%s:%s",*(undefined4 *)(iVar6 + 0xac),*(undefined4 *)(iVar6 + 0xb0));
    }
  }
  local_9c8[299] = *(char **)*local_9d0;
  if (cVar3 != '\0') {
    openlog("bmminer",1,8);
  }
  piVar24 = (int *)&local_828;
  if (local_9d4[0x3a5] != 0) {
    iVar6 = pipe(piVar24);
    if (iVar6 < 0) {
      perror("pipe - failed to create pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(stderr);
    iVar6 = dup2(local_824,2);
    if (iVar6 < 0) {
      perror("dup2 - failed to alias stderr to write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar6 = close(local_824);
    if (iVar6 < 0) {
      perror("close - failed to close write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    p_Var15 = signal(0xd,(__sighandler_t)0x1);
    p_Var16 = signal(0xd,(__sighandler_t)0x1);
    if ((p_Var15 == (__sighandler_t)0xffffffff) || (p_Var16 == (__sighandler_t)0xffffffff)) {
      perror("signal - failed to edit signal mask for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    pcVar39 = (char *)fork();
    local_9c8[0x111] = pcVar39;
    if ((int)pcVar39 < 0) {
      perror("fork - failed to fork child process for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (pcVar39 == (char *)0x0) {
      iVar6 = dup2((int)local_828,0);
      if (iVar6 < 0) {
        perror("dup2 - in child, failed to alias read end of pipe to stdin for --monitor");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close((int)local_828);
      execl("/bin/bash","/bin/bash",&DAT_0005ed20,local_9d4[0x3a5],0);
      perror("execl - in child failed to exec user specified command for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar6 = close((int)local_828);
    if (iVar6 < 0) {
      perror("close - failed to close read end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
LAB_00013ef2:
  local_9e0 = &mining_thr;
  mining_thr = _cgcalloc(*(int *)local_9c4,4,"cgminer.c",DAT_00013f28,0x2e91);
  for (iVar6 = 0; iVar6 < *(int *)local_9c4; iVar6 = iVar6 + 1) {
    piVar32 = (int *)*local_9e0;
    iVar26 = _cgcalloc(1,0x40,"cgminer.c",DAT_00014264,0x2e95);
    piVar32[iVar6] = iVar26;
  }
  local_9e8 = &use_syslog;
  local_9f0 = (undefined4 **)&opt_debug;
  iVar6 = 0;
  local_9e4 = piVar24;
  for (local_9dc = (char *)0x0; ppiVar13 = (int **)local_9e4, piVar24 = (int *)local_9e8,
      (int)local_9dc < *piVar10; local_9dc = (char *)((int)local_9dc + 1)) {
    iVar33 = (*ppiVar38)[(int)local_9dc];
    local_9ec = miner_thread + 1;
    iVar26 = _cgmalloc((*(int *)(iVar33 + 0x94) + 1) * 4,"cgminer.c",DAT_00014264,0x2e9e);
    iVar28 = *(int *)(iVar33 + 0x94);
    *(int *)(iVar33 + 0x98) = iVar26;
    *(undefined4 *)(iVar26 + iVar28 * 4) = 0;
    *(undefined4 *)(iVar33 + 0x60) = 4;
    for (iVar26 = 0; iVar30 = iVar6 + iVar26, iVar26 < iVar28; iVar26 = iVar26 + 1) {
      piVar24 = (int *)get_thread(iVar30);
      iVar28 = *(int *)(iVar33 + 4);
      *piVar24 = iVar30;
      piVar24[9] = iVar33;
      pcVar19 = *(code **)(iVar28 + 0x2c);
      piVar24[1] = iVar26;
      iVar28 = (*pcVar19)();
      if (iVar28 != 0) {
        iVar28 = thr_info_create(piVar24,0,local_9ec,piVar24);
        ppiVar13 = (int **)local_9e4;
        if (iVar28 != 0) {
          snprintf((char *)local_9e4,0x800,"thread %d create failed",*piVar24);
          _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
          __quit(1,0);
        }
        iVar28 = *(int *)(iVar33 + 0x20);
        *(int **)(*(int *)(iVar33 + 0x98) + iVar26 * 4) = piVar24;
        if (iVar28 != 1) {
          if ((*(char *)local_9f0 != '\0') &&
             (((*local_9e8 != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
            snprintf((char *)local_9e4,0x800,"Pushing sem post to thread %d",*piVar24);
            _applog(7,ppiVar13,0);
          }
          _cgsem_post(piVar24 + 4,"cgminer.c",DAT_00014264,0x2eba);
        }
      }
      iVar28 = *(int *)(iVar33 + 0x94);
    }
    iVar6 = iVar30;
  }
  if ((*(char *)(local_9c8 + 0x160) == '\0') && (local_9c8[0x113] == (char *)0x0)) {
    iVar28 = *local_9d8;
    piVar32 = (int *)*local_9d0;
    iVar26 = 0;
    bVar2 = false;
    iVar6 = enabled_pools;
    while (iVar26 < iVar28) {
      iVar33 = piVar32[iVar26];
      iVar26 = iVar26 + 1;
      *(undefined *)(iVar33 + 0x61) = 1;
      bVar40 = *(int *)(iVar33 + 100) != 1;
      if (bVar40) {
        iVar6 = iVar6 + 1;
        bVar2 = true;
      }
      if (bVar40) {
        *(undefined4 *)(iVar33 + 100) = 1;
      }
    }
    if (bVar2) {
      enabled_pools = iVar6;
    }
    if (((*local_9e8 != '\0') || (*local_9c0 != '\0')) || (4 < opt_log_level)) {
      *local_9e4 = s_Probing_for_an_alive_pool_0005edc8._0_4_;
      local_9e4[1] = s_Probing_for_an_alive_pool_0005edc8._4_4_;
      local_9e4[2] = s_Probing_for_an_alive_pool_0005edc8._8_4_;
      local_9e4[3] = s_Probing_for_an_alive_pool_0005edc8._12_4_;
      local_9e4[4] = s_Probing_for_an_alive_pool_0005edc8._16_4_;
      local_9e4[5] = s_Probing_for_an_alive_pool_0005edc8._20_4_;
      *(short *)(local_9e4 + 6) = (short)ram0x0005ede0;
      _applog(5,local_9e4,0);
    }
    for (iVar6 = 0; iVar6 < *local_9d8; iVar6 = iVar6 + 1) {
      pvVar11 = (void *)((int *)*local_9d0)[iVar6];
      *(undefined *)((int)pvVar11 + 0x11c) = 1;
      pthread_create((pthread_t *)((int)pvVar11 + 0x118),(pthread_attr_t *)0x0,test_pool_thread + 1,
                     pvVar11);
    }
    iVar6 = 0;
    do {
      sleep(1);
      pcVar39 = local_9c0;
      uVar22 = iVar6 - 0xb3;
      if (uVar22 != 0) {
        uVar22 = 1;
      }
      iVar6 = iVar6 + 1;
    } while (*(byte *)(local_9c8 + 0x171) < uVar22);
    piVar32 = &opt_log_level;
    bVar2 = false;
    local_9e4 = (int *)ppiVar38;
    while (ppiVar38 = (int **)local_9e4, *(char *)(local_9c8 + 0x171) == '\0') {
      if (bVar2) {
LAB_00014aae:
        if (use_curses == '\0') {
LAB_00014abe:
          *ppiVar13 = (int *)s_No_servers_could_be_used__Exitin_0005eef8._0_4_;
          ppiVar13[1] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._4_4_;
          ppiVar13[2] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._8_4_;
          ppiVar13[3] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._12_4_;
          ppiVar13[4] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._16_4_;
          ppiVar13[5] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._20_4_;
          ppiVar13[6] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._24_4_;
          ppiVar13[7] = (int *)s_No_servers_could_be_used__Exitin_0005eef8._28_4_;
          *(short *)(ppiVar13 + 8) = (short)ram0x0005ef18;
          *(char *)((int)ppiVar13 + 0x22) = (char)((uint)ram0x0005ef18 >> 0x10);
          _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
          __quit(0);
        }
      }
      else {
        if (((*(char *)piVar24 == '\0') && (*pcVar39 == '\0')) && ((int)*piVar32 < 3)) {
LAB_00014c1c:
          if (2 < (int)*piVar32) goto LAB_00014b42;
LAB_00014c22:
          if (2 < (int)*piVar32) goto LAB_00014b6a;
        }
        else {
          *ppiVar13 = (int *)s_No_servers_were_found_that_could_0005ede4._0_4_;
          ppiVar13[1] = (int *)s_No_servers_were_found_that_could_0005ede4._4_4_;
          ppiVar13[2] = (int *)s_No_servers_were_found_that_could_0005ede4._8_4_;
          ppiVar13[3] = (int *)s_No_servers_were_found_that_could_0005ede4._12_4_;
          ppiVar13[4] = (int *)s_No_servers_were_found_that_could_0005ede4._16_4_;
          ppiVar13[5] = (int *)s_No_servers_were_found_that_could_0005ede4._20_4_;
          ppiVar13[6] = (int *)s_No_servers_were_found_that_could_0005ede4._24_4_;
          ppiVar13[7] = (int *)s_No_servers_were_found_that_could_0005ede4._28_4_;
          ppiVar13[8] = (int *)s_No_servers_were_found_that_could_0005ede4._32_4_;
          ppiVar13[9] = (int *)s_No_servers_were_found_that_could_0005ede4._36_4_;
          ppiVar13[10] = (int *)s_No_servers_were_found_that_could_0005ede4._40_4_;
          ppiVar13[0xb] = (int *)s_No_servers_were_found_that_could_0005ede4._44_4_;
          ppiVar13[0xc] = (int *)s_No_servers_were_found_that_could_0005ede4._48_4_;
          ppiVar13[0xd] = (int *)s_No_servers_were_found_that_could_0005ede4._52_4_;
          *(short *)(ppiVar13 + 0xe) = (short)ram0x0005ee1c;
          *(char *)((int)ppiVar13 + 0x3a) = (char)((uint)ram0x0005ee1c >> 0x10);
          _applog(3,ppiVar13,0);
          if ((*(char *)piVar24 == '\0') && (*pcVar39 == '\0')) goto LAB_00014c1c;
LAB_00014b42:
          memcpy(ppiVar13,
                 "Please check the details from the list below of the servers you have input",0x4b);
          _applog(3,ppiVar13,0);
          if ((*(char *)piVar24 == '\0') && (*pcVar39 == '\0')) goto LAB_00014c22;
LAB_00014b6a:
          memcpy(ppiVar13,
                 "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers"
                 ,0x5e);
          _applog(3,ppiVar13,0);
        }
        local_9dc = (char *)piVar32;
        for (iVar6 = 0; piVar32 = (int *)local_9dc, iVar6 < *local_9d8; iVar6 = iVar6 + 1) {
          iVar26 = ((int *)*local_9d0)[iVar6];
          if (((*(char *)piVar24 != '\0') || (*pcVar39 != '\0')) || (3 < (int)*(int **)local_9dc)) {
            snprintf((char *)ppiVar13,0x800,"Pool: %d  URL: %s  User: %s  Password: %s",iVar6,
                     *(undefined4 *)(iVar26 + 0xa4),*(undefined4 *)(iVar26 + 0xac),
                     *(undefined4 *)(iVar26 + 0xb0));
            _applog(4,ppiVar13,0);
          }
        }
        if (use_curses == '\0') goto LAB_00014abe;
        if (((*(char *)piVar24 != '\0') || (*pcVar39 != '\0')) || (2 < (int)*(int **)local_9dc)) {
          memcpy(ppiVar13,
                 "Press any key to exit, or cgminer will wait indefinitely for an alive pool.",0x4c)
          ;
          _applog(3,ppiVar13,0);
          goto LAB_00014aae;
        }
      }
      bVar2 = true;
    }
  }
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  puVar17 = DAT_00014268 + 0x18;
  puVar34 = DAT_00014268;
  do {
    puVar18 = puVar34 + 2;
    *puVar34 = 0;
    puVar34[1] = 0;
    puVar34 = puVar18;
  } while (puVar18 != puVar17);
  iVar26 = *piVar10;
  piVar10 = *ppiVar38;
  local_9c8[0x14c] = (char *)0x0;
  for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
    iVar28 = piVar10[iVar6];
    *(undefined4 *)(iVar28 + 0x50) = 0;
    *(undefined4 *)(iVar28 + 0x54) = 0;
    *(undefined4 *)(iVar28 + 0x30) = 0;
    *(undefined4 *)(iVar28 + 0x34) = 0;
  }
  cgtime(DAT_0001426c);
  cgtime(DAT_00014270);
  cgtime(DAT_00014274);
  get_datestamp(DAT_0001426c + 8,0x28);
  iVar26 = *local_9cc;
  local_9c8[0x129] = (char *)0x2;
  iVar6 = thr_info_create(iVar26 + 0x80,0,0x22289);
  if (iVar6 != 0) {
    *ppiVar13 = (int *)s_watchpool_thread_create_failed_0005ef68._0_4_;
    ppiVar13[1] = (int *)s_watchpool_thread_create_failed_0005ef68._4_4_;
    ppiVar13[2] = (int *)s_watchpool_thread_create_failed_0005ef68._8_4_;
    ppiVar13[3] = (int *)s_watchpool_thread_create_failed_0005ef68._12_4_;
    ppiVar13[4] = (int *)s_watchpool_thread_create_failed_0005ef68._16_4_;
    ppiVar13[5] = (int *)s_watchpool_thread_create_failed_0005ef68._20_4_;
    ppiVar13[6] = (int *)s_watchpool_thread_create_failed_0005ef68._24_4_;
    *(short *)(ppiVar13 + 7) = (short)ram0x0005ef84;
    *(char *)((int)ppiVar13 + 0x1e) = (char)((uint)ram0x0005ef84 >> 0x10);
    _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pthread_detach(*(pthread_t *)(iVar26 + 0x8c));
  iVar26 = *local_9cc;
  local_9c8[0x12a] = (char *)0x3;
  iVar6 = thr_info_create(iVar26 + 0xc0,0,0x25e51,0);
  if (iVar6 != 0) {
    *ppiVar13 = (int *)s_watchdog_thread_create_failed_0005ef88._0_4_;
    ppiVar13[1] = (int *)s_watchdog_thread_create_failed_0005ef88._4_4_;
    ppiVar13[2] = (int *)s_watchdog_thread_create_failed_0005ef88._8_4_;
    ppiVar13[3] = (int *)s_watchdog_thread_create_failed_0005ef88._12_4_;
    ppiVar13[4] = (int *)s_watchdog_thread_create_failed_0005ef88._16_4_;
    ppiVar13[5] = (int *)s_watchdog_thread_create_failed_0005ef88._20_4_;
    ppiVar13[6] = (int *)s_watchdog_thread_create_failed_0005ef88._24_4_;
    *(short *)(ppiVar13 + 7) = (short)ram0x0005efa4;
    _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  pthread_detach(*(pthread_t *)(iVar26 + 0xcc));
  iVar6 = *local_9cc;
  local_9c8[0xd0] = (char *)0x5;
  iVar6 = thr_info_create(iVar6 + 0x140,0,0x1c1c9);
  if (iVar6 != 0) {
    *ppiVar13 = (int *)s_API_thread_create_failed_0005efa8._0_4_;
    ppiVar13[1] = (int *)s_API_thread_create_failed_0005efa8._4_4_;
    ppiVar13[2] = (int *)s_API_thread_create_failed_0005efa8._8_4_;
    ppiVar13[3] = (int *)s_API_thread_create_failed_0005efa8._12_4_;
    ppiVar13[4] = (int *)s_API_thread_create_failed_0005efa8._16_4_;
    ppiVar13[5] = (int *)s_API_thread_create_failed_0005efa8._20_4_;
    *(char *)(ppiVar13 + 6) = (char)ram0x0005efc0;
    _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  if (local_9d4[0x3a4] != 8) {
    snprintf((char *)ppiVar13,0x800,"incorrect total_control_threads (%d) should be 8");
    _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
    __quit(1,0);
  }
  iVar6 = nice(-10);
  if (((iVar6 == 0) && (opt_debug != '\0')) &&
     ((*(char *)piVar24 != '\0' || ((*local_9c0 != '\0' || (6 < opt_log_level)))))) {
    *ppiVar13 = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._0_4_;
    ppiVar13[1] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._4_4_;
    ppiVar13[2] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._8_4_;
    ppiVar13[3] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._12_4_;
    ppiVar13[4] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._16_4_;
    ppiVar13[5] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._20_4_;
    ppiVar13[6] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._24_4_;
    ppiVar13[7] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._28_4_;
    ppiVar13[8] = (int *)s_Unable_to_set_thread_to_high_pri_0005eff8._32_4_;
    *(short *)(ppiVar13 + 9) = (short)ram0x0005f01c;
    _applog(7,ppiVar13,0);
  }
  puVar34 = local_9d4;
  local_9cc = piVar24;
  local_9e4 = (int *)&opt_work_update;
LAB_000142e8:
  while( true ) {
    if (*(char *)local_9e4 != '\0') {
      if (((*(char *)local_9cc != '\0') || (*local_9c0 != '\0')) || (5 < opt_log_level)) {
        *ppiVar13 = (int *)s_Work_update_message_received_0005f020._0_4_;
        ppiVar13[1] = (int *)s_Work_update_message_received_0005f020._4_4_;
        ppiVar13[2] = (int *)s_Work_update_message_received_0005f020._8_4_;
        ppiVar13[3] = (int *)s_Work_update_message_received_0005f020._12_4_;
        ppiVar13[4] = (int *)s_Work_update_message_received_0005f020._16_4_;
        ppiVar13[5] = (int *)s_Work_update_message_received_0005f020._20_4_;
        ppiVar13[6] = (int *)s_Work_update_message_received_0005f020._24_4_;
        *(char *)(ppiVar13 + 7) = (char)ram0x0005f03c;
        _applog(6,ppiVar13,0);
      }
      cgtime(DAT_000149ec);
      iVar6 = pthread_rwlock_rdlock((pthread_rwlock_t *)mining_thr_lock);
      uVar7 = DAT_000149f0;
      if (iVar6 != 0) {
        piVar10 = __errno_location();
        uVar31 = 0x1531;
        pcVar39 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
        goto LAB_0001481e;
      }
      iVar26 = *(int *)local_9c4;
      piVar10 = (int *)*local_9e0;
      for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
        *(undefined *)(piVar10[iVar6] + 0x3f) = 1;
      }
      iVar6 = pthread_rwlock_unlock((pthread_rwlock_t *)mining_thr_lock);
      uVar7 = DAT_000149f0;
      if (iVar6 != 0) {
        piVar10 = __errno_location();
        uVar31 = 0x1538;
        pcVar39 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
        goto LAB_0001481e;
      }
      (*selective_yield)();
    }
    __mutex = (pthread_mutex_t *)local_9c8[0x117];
    *(char *)local_9e4 = '\0';
    iVar6 = pthread_mutex_lock(__mutex);
    ppcVar4 = local_9c8;
    if (iVar6 != 0) {
      piVar10 = __errno_location();
      uVar31 = 0x2f60;
      pcVar39 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      uVar7 = DAT_000149e8;
      goto LAB_0001481e;
    }
    if ((local_9c8[0x14d] == (char *)0x0) ||
       (*(int *)(*(int *)(local_9c8[0x14d] + 0x158) + 0xc) < 2)) break;
    pthread_cond_wait((pthread_cond_t *)gws_cond,(pthread_mutex_t *)local_9c8[0x117]);
    pcVar39 = ppcVar4[0x14d];
    if (pcVar39 == (char *)0x0) break;
    iVar26 = *(int *)(*(int *)(pcVar39 + 0x158) + 0xc);
    iVar6 = pthread_mutex_unlock((pthread_mutex_t *)ppcVar4[0x117]);
    if (iVar6 != 0) goto LAB_000148b2;
    (*selective_yield)();
    if (iVar26 < 2) goto LAB_00014338;
    local_9b8 = hash_pop(0);
    if (local_9b8 != 0) {
      _discard_work(&local_9b8,"cgminer.c",DAT_000149e8,0x2f77);
    }
  }
  iVar6 = pthread_mutex_unlock((pthread_mutex_t *)local_9c8[0x117]);
  if (iVar6 == 0) {
    (*selective_yield)();
LAB_00014338:
    if (local_9b8 != 0) {
      _discard_work(&local_9b8,"cgminer.c",DAT_000145e8,0x2f7f);
    }
    local_9b8 = make_work();
    local_9dc = &opt_debug;
LAB_0001442e:
    puVar17 = (undefined4 *)current_pool();
    if (local_9c8[0x107] == (char *)0x4) {
      puVar18 = (undefined4 *)select_balanced();
    }
    else {
      puVar18 = puVar17;
      if (local_9c8[0x107] == (char *)0x3) {
        iVar26 = *local_9d8;
        piVar10 = (int *)*local_9d0;
        for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
          iVar28 = piVar10[iVar6];
          if (*(int *)(iVar28 + 0x40) < *(int *)(iVar28 + 0x3c)) goto LAB_0001454a;
        }
        for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
          *(undefined4 *)(piVar10[iVar6] + 0x40) = 0;
        }
        iVar6 = puVar34[0x3a6] + 1;
        if (iVar26 <= iVar6) {
          iVar6 = 0;
        }
        puVar34[0x3a6] = iVar6;
LAB_0001454a:
        local_9e8 = (char *)*local_9d0;
        local_9d4 = (undefined4 *)0x0;
        while (piVar10 = local_9d8, (int)local_9d4 < iVar26) {
          iVar28 = puVar34[0x3a6];
          puVar18 = *(undefined4 **)((int)local_9e8 + iVar28 * 4);
          iVar6 = puVar18[0x10];
          puVar18[0x10] = iVar6 + 1;
          if (((iVar6 < (int)puVar18[0xf]) && (*(code *)((int)puVar18 + 0x61) == (code)0x0)) &&
             ((puVar18[0x19] == 1 &&
              (local_9ec = (undefined1 *)puVar18, iVar6 = pool_unusable_part_4(puVar18),
              puVar18 = (undefined4 *)local_9ec, iVar6 == 0)))) goto LAB_00014372;
          iVar28 = iVar28 + 1;
          local_9d4 = (undefined4 *)((int)local_9d4 + 1);
          if (iVar26 <= iVar28) {
            iVar28 = 0;
          }
          puVar34[0x3a6] = iVar28;
        }
        iVar6 = 0;
        while ((puVar18 = puVar17, iVar6 < *piVar10 &&
               (((local_9d4 = (undefined4 *)priority_pool(iVar6),
                 *(code *)((int)local_9d4 + 0x61) != (code)0x0 || (local_9d4[0x19] != 1)) ||
                (iVar26 = pool_unusable_part_4(), puVar18 = local_9d4, iVar26 != 0))))) {
          iVar6 = iVar6 + 1;
        }
      }
    }
LAB_00014372:
    if ((*local_9dc != '\0') &&
       (((*(char *)local_9cc != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)ppiVar13,0x800,"Selecting pool %d for work",*puVar18);
      _applog(7,ppiVar13,0);
    }
    if (((*(code *)((int)puVar18 + 0x61) != (code)0x0) || (puVar18[0x19] != 1)) ||
       (iVar6 = pool_unusable_part_4(puVar18), ppiVar38 = (int **)local_9dc, iVar6 != 0)) {
      switch_pools(0);
      puVar17 = (undefined4 *)current_pool();
      if (local_9c8[0x107] == (char *)0x4) {
        puVar18 = (undefined4 *)select_balanced();
      }
      else {
        puVar18 = puVar17;
        if (local_9c8[0x107] == (char *)0x3) {
          iVar26 = *local_9d8;
          piVar10 = (int *)*local_9d0;
          for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
            iVar28 = piVar10[iVar6];
            if (*(int *)(iVar28 + 0x40) < *(int *)(iVar28 + 0x3c)) goto LAB_00014488;
          }
          for (iVar6 = 0; iVar6 < iVar26; iVar6 = iVar6 + 1) {
            *(undefined4 *)(piVar10[iVar6] + 0x40) = 0;
          }
          iVar6 = puVar34[0x3a6] + 1;
          if (iVar26 <= iVar6) {
            iVar6 = 0;
          }
          puVar34[0x3a6] = iVar6;
LAB_00014488:
          local_9e8 = (char *)*local_9d0;
          local_9d4 = (undefined4 *)0x0;
          while (piVar10 = local_9d8, (int)local_9d4 < iVar26) {
            iVar28 = puVar34[0x3a6];
            puVar18 = *(undefined4 **)((int)local_9e8 + iVar28 * 4);
            iVar6 = puVar18[0x10];
            puVar18[0x10] = iVar6 + 1;
            if ((((iVar6 < (int)puVar18[0xf]) && (*(code *)((int)puVar18 + 0x61) == (code)0x0)) &&
                (puVar18[0x19] == 1)) &&
               (local_9ec = (undefined1 *)puVar18, iVar6 = pool_unusable_part_4(puVar18),
               puVar18 = (undefined4 *)local_9ec, iVar6 == 0)) goto LAB_000143d4;
            iVar28 = iVar28 + 1;
            if (iVar26 <= iVar28) {
              iVar28 = 0;
            }
            local_9d4 = (undefined4 *)((int)local_9d4 + 1);
            puVar34[0x3a6] = iVar28;
          }
          iVar6 = 0;
          while ((puVar18 = puVar17, iVar6 < *piVar10 &&
                 (((local_9d4 = (undefined4 *)priority_pool(iVar6),
                   *(code *)((int)local_9d4 + 0x61) != (code)0x0 || (local_9d4[0x19] != 1)) ||
                  (iVar26 = pool_unusable_part_4(), puVar18 = local_9d4, iVar26 != 0))))) {
            iVar6 = iVar6 + 1;
          }
        }
      }
LAB_000143d4:
      if ((*local_9dc != '\0') &&
         (((*(char *)local_9cc != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
        snprintf((char *)ppiVar13,0x800,"Selecting pool %d for work",*puVar18);
        _applog(7,ppiVar13,0);
      }
      if (((*(code *)((int)puVar18 + 0x61) != (code)0x0) || (puVar18[0x19] != 1)) ||
         (iVar6 = pool_unusable_part_4(puVar18), iVar6 != 0)) {
        cgsleep_ms(0xb);
      }
      goto LAB_0001442e;
    }
    if (*(code *)(puVar18 + 0xa0) == (code)0x0) {
      if (local_9c8[0x113] == (char *)0x0) {
        if (*(char *)(local_9c8 + 0x160) == '\0') goto LAB_000142e8;
        get_benchmark_work(local_9b8);
        if ((*(char *)ppiVar38 != '\0') &&
           (((*(char *)local_9cc != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
          pcVar39 = "Generated benchmark work";
          goto LAB_0001463a;
        }
      }
      else {
        get_benchfile_work(local_9b8);
        if ((*(char *)ppiVar38 != '\0') &&
           (((*(char *)local_9cc != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
          pcVar39 = "Generated benchfile work";
LAB_0001463a:
          piVar10 = *(int **)((int)pcVar39 + 4);
          piVar24 = *(int **)((int)pcVar39 + 8);
          piVar32 = *(int **)((int)pcVar39 + 0xc);
          *ppiVar13 = *(int **)pcVar39;
          ppiVar13[1] = piVar10;
          ppiVar13[2] = piVar24;
          ppiVar13[3] = piVar32;
          piVar10 = *(int **)((int)pcVar39 + 0x14);
          piVar24 = *(int **)((int)pcVar39 + 0x18);
          ppiVar13[4] = *(int **)((int)pcVar39 + 0x10);
          ppiVar13[5] = piVar10;
          *(char *)(ppiVar13 + 6) = (char)piVar24;
          _applog(7,ppiVar13,0);
        }
      }
    }
    else {
      gen_stratum_work(puVar18,local_9b8);
      if ((*(char *)ppiVar38 != '\0') &&
         (((*(char *)local_9cc != '\0' || (*local_9c0 != '\0')) || (6 < opt_log_level)))) {
        *ppiVar13 = (int *)s_Generated_stratum_work_0005f05c._0_4_;
        ppiVar13[1] = (int *)s_Generated_stratum_work_0005f05c._4_4_;
        ppiVar13[2] = (int *)s_Generated_stratum_work_0005f05c._8_4_;
        ppiVar13[3] = (int *)s_Generated_stratum_work_0005f05c._12_4_;
        ppiVar13[4] = (int *)s_Generated_stratum_work_0005f05c._16_4_;
        *(short *)(ppiVar13 + 5) = (short)ram0x0005f070;
        *(char *)((int)ppiVar13 + 0x16) = (char)((uint)ram0x0005f070 >> 0x10);
        _applog(7,ppiVar13,0);
      }
    }
    _stage_work(local_9b8);
    local_9b8 = 0;
    goto LAB_000142e8;
  }
LAB_000148b2:
  piVar10 = __errno_location();
  uVar31 = 0x2f6b;
  pcVar39 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  uVar7 = DAT_000149e8;
LAB_0001481e:
  snprintf((char *)ppiVar13,0x800,pcVar39,*piVar10,"cgminer.c",uVar7,uVar31);
LAB_0001329a:
  _applog(3,ppiVar13,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

