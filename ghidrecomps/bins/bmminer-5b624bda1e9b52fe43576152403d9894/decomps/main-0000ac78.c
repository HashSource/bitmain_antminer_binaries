
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

int main(int argc,char **argv)

{
  undefined2 uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  pthread_mutex_t *__mutex;
  pool ***ppppVar9;
  char **ppcVar10;
  uchar *puVar11;
  _Bool _Var12;
  long lVar13;
  char **ppcVar14;
  undefined4 uVar15;
  char *pcVar16;
  char *pcVar17;
  size_t sVar18;
  block *pbVar19;
  uint uVar20;
  pool *ppVar21;
  FILE *pFVar22;
  sysinfo *psVar23;
  size_t sVar24;
  __sighandler_t p_Var25;
  __sighandler_t p_Var26;
  thr_info *ptVar27;
  thr_info **pptVar28;
  int *piVar29;
  pool *ppVar30;
  pool **pppVar31;
  uint uVar32;
  thr_info **pptVar33;
  uint uVar34;
  uint uVar35;
  UT_hash_handle *pUVar36;
  UT_hash_bucket *pUVar37;
  uchar *puVar38;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  char *func_05;
  char *func_06;
  _func_int *extraout_r3;
  code *pcVar39;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  int line_07;
  int line_08;
  int line_09;
  int line_10;
  int line_11;
  UT_hash_table *pUVar40;
  UT_hash_handle *pUVar41;
  pool_enable pVar42;
  uchar (*pauVar43) [160];
  int line_12;
  int line_13;
  cgpu_info **line_14;
  cgpu_info **extraout_r3_00;
  cgpu_info **line_15;
  cgpu_info **extraout_r3_01;
  cgpu_info **ppcVar44;
  pool **pppVar45;
  device_drv *pdVar46;
  _func__Bool_thr_info_ptr *p_Var47;
  dev_enable dVar48;
  double *pdVar49;
  cgpu_info **ppcVar50;
  int line_16;
  int line_17;
  int iVar51;
  int line_18;
  thr_info **pptVar52;
  int line_19;
  char *pcVar53;
  int iVar54;
  cgpu_info **ppcVar55;
  cgpu_info *pcVar56;
  work *pwVar57;
  int iVar58;
  block *pbVar59;
  FILE **ppFVar60;
  _Bool *p_Var61;
  int iVar62;
  pool **pppVar63;
  UT_hash_handle *pUVar64;
  bool bVar65;
  char acStack_29f8 [4104];
  char local_19f0 [4088];
  char *local_9f8;
  thr_info *local_9e8;
  uchar *local_9e4;
  _func_int **pp_Stack_9e0;
  _Bool *p_Stack_9dc;
  int *local_9d8;
  pool ***ppppStack_9d4;
  block *local_9d0;
  thr_info *local_9cc;
  block *local_9c8;
  char **local_9c4;
  pool *local_9c0;
  int local_9bc;
  work *local_9b8;
  sigaction handler;
  sysinfo sInfo;
  char tmp42 [2048];
  
  pcVar53 = g_logfile_path;
  builtin_strncpy(g_logfile_path,"bmminer.log",0xc);
  g_logfile_openflag[2] = '\0';
  g_logfile_openflag[0] = 'a';
  g_logfile_openflag[1] = '+';
  g_logfile_enable = false;
  local_9b8 = (work *)0x0;
  local_9c4 = argv;
  local_9bc = argc;
  lVar13 = sysconf(0x54);
  pcVar39 = extraout_r3;
  if (lVar13 == 1) {
    pcVar39 = sched_yield;
    pcVar53 = (char *)&selective_yield;
  }
  if (lVar13 == 1) {
    *(code **)pcVar53 = pcVar39;
  }
  ppcVar14 = (char **)_cgmalloc((local_9bc + 1) * 4,"cgminer.c","main",0x2c9f);
  ppcVar10 = local_9c4;
  initial_args = ppcVar14;
  if (0 < local_9bc) {
    iVar54 = 0;
    iVar58 = 0;
    do {
      iVar58 = iVar58 + 1;
      uVar15 = __strdup(*(undefined4 *)((int)ppcVar10 + iVar54));
      *(undefined4 *)((int)ppcVar14 + iVar54) = uVar15;
      iVar54 = iVar54 + 4;
    } while (iVar58 < local_9bc);
  }
  ppcVar14[local_9bc] = (char *)0x0;
  _mutex_init(&hash_lock,"main",(char *)0x2ca8,local_9bc);
  _mutex_init(&update_job_lock,"main",(char *)0x2ca9,line);
  _mutex_init(&console_lock,"main",(char *)0x2caa,line_00);
  _cglock_init(&control_lock,"main",(char *)0x2cab,line_01);
  _mutex_init(&stats_lock,"main",(char *)0x2cac,line_02);
  _mutex_init(&sharelog_lock,"main",(char *)0x2cad,line_03);
  _cglock_init(&ch_lock,"main",(char *)0x2cae,line_04);
  _mutex_init(&sshare_lock,"main",(char *)0x2caf,line_05);
  _rwlock_init(&blk_lock,"main",(char *)0x2cb0,line_06);
  _rwlock_init(&netacc_lock,"main",(char *)0x2cb1,line_07);
  _rwlock_init(&mining_thr_lock,"main",(char *)0x2cb2,line_08);
  _rwlock_init(&devices_lock,"main",(char *)0x2cb3,line_09);
  _mutex_init(&lp_lock,"main",(char *)0x2cb5,line_10);
  iVar54 = pthread_cond_init((pthread_cond_t *)&lp_cond,(pthread_condattr_t *)0x0);
  if (iVar54 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init lp_cond",0x24);
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  _mutex_init(&restart_lock,"main",(char *)0x2cbc,line_11);
  iVar54 = pthread_cond_init((pthread_cond_t *)&restart_cond,(pthread_condattr_t *)0x0);
  if (iVar54 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init restart_cond",0x28);
    tmp42[0x28] = '\0';
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  iVar54 = pthread_cond_init((pthread_cond_t *)&gws_cond,(pthread_condattr_t *)0x0);
  if (iVar54 != 0) {
    tmp42[8] = 'o';
    tmp42[9] = ' ';
    tmp42[10] = 'p';
    tmp42[0xb] = 't';
    tmp42[0xc] = 'h';
    tmp42[0xd] = 'r';
    tmp42[0xe] = 'e';
    tmp42[0xf] = 'a';
    tmp42[0x10] = 'd';
    tmp42[0x11] = '_';
    tmp42[0x12] = 'c';
    tmp42[0x13] = 'o';
    tmp42[0x14] = 'n';
    tmp42[0x15] = 'd';
    tmp42[0x16] = '_';
    tmp42[0x17] = 'i';
    tmp42[0x18] = 'n';
    tmp42[0x19] = 'i';
    tmp42[0x1a] = 't';
    tmp42[0x1b] = ' ';
    tmp42[0x1c] = 'g';
    tmp42[0x1d] = 'w';
    tmp42[0x1e] = 's';
    tmp42[0x1f] = '_';
    tmp42[0x20] = 'c';
    tmp42[0x21] = 'o';
    tmp42[0x22] = 'n';
    tmp42[0x23] = 'd';
    tmp42._36_4_ = tmp42._36_4_ & 0xffffff00;
LAB_0000bfd4:
    builtin_strncpy(tmp42,"Failed t",8);
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  getq = tq_new();
  if (getq == (thread_q *)0x0) {
    builtin_strncpy(tmp42 + 8,"o create getq",0xe);
    getq = (thread_q *)0x0;
    goto LAB_0000bfd4;
  }
  stgd_lock = &getq->mutex;
  local_9f8 = "2.0.0";
  snprintf(packagename,0x100,"%s %s","bmminer");
  iVar58 = 0x24;
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x20379;
  handler.sa_flags = iVar54;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  opt_kernel_path = local_19f0;
  cgminer_path = acStack_29f8;
  builtin_strncpy(local_19f0,"/usr/bin",8);
  local_19f0[8] = 0;
  pcVar16 = (char *)__strdup(*local_9c4);
  pcVar53 = cgminer_path;
  pcVar17 = dirname(pcVar16);
  strcpy(pcVar53,pcVar17);
  free(pcVar16);
  pcVar53 = cgminer_path;
  sVar18 = strlen(cgminer_path);
  (pcVar53 + sVar18)[0] = '/';
  (pcVar53 + sVar18)[1] = '\0';
  logstart = 9;
  logcursor = 10;
  devcursor = 8;
  pcVar53 = (char *)0x2ceb;
  pbVar19 = (block *)_cgcalloc(0x68,1,"cgminer.c","main",0x2ceb);
  do {
    sVar18 = strlen((char *)pbVar19);
    iVar58 = iVar58 + -1;
    (pbVar19->hash + sVar18)[0] = '0';
    (pbVar19->hash + sVar18)[1] = '\0';
  } while (iVar58 != 0);
  local_9c0 = (pool *)strlen((char *)pbVar19);
  uVar34 = 0x9e3779b9;
  uVar20 = 0xfeedbeef;
  uVar32 = uVar34;
  pbVar59 = pbVar19;
  for (ppVar21 = local_9c0; (pool *)0xb < ppVar21; ppVar21 = (pool *)&ppVar21[-1].tv_lastwork) {
    pcVar16 = pbVar59->hash;
    pcVar17 = pbVar59->hash;
    pcVar3 = pbVar59->hash;
    pcVar4 = pbVar59->hash;
    pcVar5 = pbVar59->hash;
    pcVar6 = pbVar59->hash;
    pcVar7 = pbVar59->hash;
    pcVar8 = pbVar59->hash;
    iVar54 = uVar32 + (uint)(byte)pbVar59->hash[6] * 0x10000 + (uint)(byte)pbVar59->hash[5] * 0x100
                      + (uint)(byte)pbVar59->hash[4] + (uint)(byte)pbVar59->hash[7] * 0x1000000;
    pbVar59 = (block *)(pbVar59->hash + 0xc);
    uVar20 = uVar20 + (uint)(byte)pcVar7[8] +
                      (uint)(byte)pcVar17[10] * 0x10000 + (uint)(byte)pcVar4[9] * 0x100 +
                      (uint)(byte)pcVar8[0xb] * 0x1000000;
    uVar32 = uVar34 + ((((uint)(byte)*pcVar5 +
                         (uint)(byte)pcVar16[2] * 0x10000 + (uint)(byte)pcVar3[1] * 0x100 +
                        (uint)(byte)pcVar6[3] * 0x1000000) - iVar54) - uVar20) ^ uVar20 >> 0xd;
    uVar35 = (iVar54 - uVar20) - uVar32 ^ uVar32 << 8;
    uVar34 = (uVar20 - uVar32) - uVar35 ^ uVar35 >> 0xd;
    uVar32 = (uVar32 - uVar35) - uVar34 ^ uVar34 >> 0xc;
    uVar35 = (uVar35 - uVar34) - uVar32 ^ uVar32 << 0x10;
    uVar20 = (uVar34 - uVar32) - uVar35 ^ uVar35 >> 5;
    uVar34 = (uVar32 - uVar35) - uVar20 ^ uVar20 >> 3;
    uVar32 = (uVar35 - uVar20) - uVar34 ^ uVar34 << 10;
    uVar20 = (uVar20 - uVar34) - uVar32 ^ uVar32 >> 0xf;
    local_9c8 = pbVar19;
  }
  pcVar16 = local_9c0->diff + (uVar20 - 0x30);
  switch(ppVar21) {
  case (pool *)0xb:
    pcVar16 = pcVar16 + (uint)(byte)pbVar59->hash[10] * 0x1000000;
  case (pool *)0xa:
    pcVar16 = pcVar16 + (uint)(byte)pbVar59->hash[9] * 0x10000;
  case (pool *)0x9:
    pcVar16 = pcVar16 + (uint)(byte)pbVar59->hash[8] * 0x100;
  case (pool *)0x8:
    uVar32 = uVar32 + (uint)(byte)pbVar59->hash[7] * 0x1000000;
  case (pool *)0x7:
    uVar32 = uVar32 + (uint)(byte)pbVar59->hash[6] * 0x10000;
  case (pool *)0x6:
    uVar32 = uVar32 + (uint)(byte)pbVar59->hash[5] * 0x100;
  case (pool *)0x5:
    uVar32 = uVar32 + (byte)pbVar59->hash[4];
  case (pool *)0x4:
    uVar34 = uVar34 + (uint)(byte)pbVar59->hash[3] * 0x1000000;
  case (pool *)0x3:
    uVar34 = uVar34 + (uint)(byte)pbVar59->hash[2] * 0x10000;
  case (pool *)0x2:
    uVar34 = uVar34 + (uint)(byte)pbVar59->hash[1] * 0x100;
  case (pool *)0x1:
    uVar34 = uVar34 + (byte)pbVar59->hash[0];
  }
  (pbVar19->hh).key = pbVar19;
  uVar34 = (uVar34 - uVar32) - (int)pcVar16 ^ (uint)pcVar16 >> 0xd;
  uVar32 = (uVar32 - (int)pcVar16) - uVar34 ^ uVar34 << 8;
  uVar20 = (uint)(pcVar16 + (-uVar32 - uVar34)) ^ uVar32 >> 0xd;
  uVar34 = (uVar34 - uVar32) - uVar20 ^ uVar20 >> 0xc;
  uVar32 = (uVar32 - uVar20) - uVar34 ^ uVar34 << 0x10;
  uVar20 = (uVar20 - uVar34) - uVar32 ^ uVar32 >> 5;
  uVar34 = (uVar34 - uVar32) - uVar20 ^ uVar20 >> 3;
  uVar32 = (uVar32 - uVar20) - uVar34 ^ uVar34 << 10;
  uVar34 = (uVar20 - uVar34) - uVar32 ^ uVar32 >> 0xf;
  (pbVar19->hh).hashv = uVar34;
  sVar18 = strlen((char *)pbVar19);
  (pbVar19->hh).keylen = sVar18;
  pbVar59 = blocks;
  if (blocks == (block *)0x0) {
    (pbVar19->hh).next = (void *)0x0;
    (pbVar19->hh).prev = (void *)0x0;
    blocks = pbVar19;
    pUVar40 = (UT_hash_table *)malloc(0x2c);
    (pbVar19->hh).tbl = pUVar40;
    if (pUVar40 == (UT_hash_table *)0x0) goto LAB_0000bf48;
    memset(pUVar40,0,0x2c);
    pUVar40 = (pbVar19->hh).tbl;
    pUVar40->tail = &pbVar19->hh;
    pUVar40->num_buckets = 0x20;
    pUVar40->log2_num_buckets = 5;
    pUVar40->hho = 0x44;
    pUVar37 = (UT_hash_bucket *)malloc(0x180);
    pUVar40->buckets = pUVar37;
    if (pUVar37 == (UT_hash_bucket *)0x0) goto LAB_0000bf48;
    memset(pUVar37,0,0x180);
    ((pbVar19->hh).tbl)->signature = 0xa0111fe1;
    pbVar59 = pbVar19;
  }
  else {
    pUVar40 = (blocks->hh).tbl;
    (pbVar19->hh).next = (void *)0x0;
    (pbVar19->hh).tbl = pUVar40;
    pUVar40 = (pbVar59->hh).tbl;
    pUVar36 = pUVar40->tail;
    iVar54 = pUVar40->hho;
    pUVar36->next = pbVar19;
    (pbVar19->hh).prev = (void *)((int)pUVar36 - iVar54);
    pUVar40->tail = &pbVar19->hh;
  }
  pUVar40 = (pbVar59->hh).tbl;
  pUVar37 = pUVar40->buckets;
  uVar34 = uVar34 & pUVar40->num_buckets - 1;
  pUVar40->num_items = pUVar40->num_items + 1;
  pUVar36 = pUVar37[uVar34].hh_head;
  uVar32 = pUVar37[uVar34].count + 1;
  pUVar37[uVar34].count = uVar32;
  (pbVar19->hh).hh_next = pUVar36;
  (pbVar19->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar36 != (UT_hash_handle *)0x0) {
    pUVar36->hh_prev = &pbVar19->hh;
  }
  pUVar37[uVar34].hh_head = &pbVar19->hh;
  if (((pUVar37[uVar34].expand_mult + 1) * 10 <= uVar32) &&
     (pUVar40 = (pbVar19->hh).tbl, pUVar40->noexpand != 1)) {
    sVar18 = pUVar40->num_buckets * 0x18;
    pUVar37 = (UT_hash_bucket *)malloc(sVar18);
    if (pUVar37 == (UT_hash_bucket *)0x0) {
LAB_0000bf48:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar37,0,sVar18);
    pUVar40 = (pbVar19->hh).tbl;
    uVar32 = pUVar40->num_buckets;
    pUVar40->nonideal_items = 0;
    local_9c0 = (pool *)(uVar32 * 2 - 1);
    uVar34 = pUVar40->num_items >> (pUVar40->log2_num_buckets + 1 & 0xff);
    if (((uint)local_9c0 & pUVar40->num_items) != 0) {
      uVar34 = uVar34 + 1;
    }
    pUVar40->ideal_chain_maxlen = uVar34;
    if (uVar32 == 0) {
      local_9c8 = (block *)pUVar40->buckets;
    }
    else {
      local_9c8 = (block *)pUVar40->buckets;
      local_9cc = (thr_info *)(uVar32 * 0xc);
      puVar38 = (uchar *)0x0;
      local_9d0 = pbVar19;
      do {
        pUVar36 = *(UT_hash_handle **)(puVar38 + (int)local_9c8->hash);
        ptVar27 = local_9e8;
        puVar11 = local_9e4;
        pbVar19 = local_9d0;
        while (local_9e4 = puVar38, local_9d0 = pbVar19, pUVar36 != (UT_hash_handle *)0x0) {
          pUVar64 = pUVar36->hh_next;
          uVar20 = (uint)local_9c0 & pUVar36->hashv;
          local_9e8 = (thr_info *)(pUVar37 + uVar20);
          uVar32 = local_9e8->device_thread + 1;
          local_9e8->device_thread = uVar32;
          puVar38 = local_9e4;
          if (uVar34 < uVar32) {
            pUVar40->nonideal_items = pUVar40->nonideal_items + 1;
            uVar32 = __aeabi_uidiv(uVar32,uVar34);
            *(uint *)&local_9e8->primary_thread = uVar32;
            puVar38 = local_9e4;
            ptVar27 = local_9e8;
            puVar11 = local_9e4;
          }
          local_9e4 = puVar11;
          local_9e8 = ptVar27;
          pUVar41 = pUVar37[uVar20].hh_head;
          pUVar36->hh_prev = (UT_hash_handle *)0x0;
          pUVar36->hh_next = pUVar41;
          if (pUVar41 != (UT_hash_handle *)0x0) {
            pUVar41->hh_prev = pUVar36;
          }
          pUVar37[uVar20].hh_head = pUVar36;
          pUVar36 = pUVar64;
          ptVar27 = local_9e8;
          puVar11 = local_9e4;
          pbVar19 = local_9d0;
        }
        puVar38 = local_9e4 + 0xc;
        local_9e8 = ptVar27;
        local_9e4 = puVar11;
      } while ((thr_info *)puVar38 != local_9cc);
    }
    free(local_9c8);
    pUVar40 = (pbVar19->hh).tbl;
    uVar20 = pUVar40->nonideal_items;
    pUVar40->buckets = pUVar37;
    uVar34 = pUVar40->num_items >> 1;
    uVar32 = uVar20;
    if (uVar20 <= uVar34) {
      uVar32 = 0;
    }
    pUVar40->log2_num_buckets = pUVar40->log2_num_buckets + 1;
    pUVar40->num_buckets = pUVar40->num_buckets << 1;
    if (uVar34 < uVar20) {
      uVar32 = pUVar40->ineff_expands + 1;
      pUVar40->ineff_expands = uVar32;
      uVar34 = uVar32;
      if (1 < uVar32) {
        uVar34 = 1;
      }
      if (1 < uVar32) {
        pUVar40->noexpand = uVar34;
      }
    }
    else {
      pUVar40->ineff_expands = uVar32;
    }
  }
  strcpy(current_hash,pbVar19->hash);
  scan_devices.next = &scan_devices;
  scan_devices.prev = &scan_devices;
  opt_register_table(opt_config_table,"Options for both config file and command line");
  opt_register_table(opt_cmdline_table,"Options for command line only");
  opt_parse(&local_9bc,local_9c4,(_func_void_char_ptr_varargs *)0x1e1d5);
  if (local_9bc != 1) {
    builtin_strncpy(tmp42,"Unexpected extra commandline arguments",0x27);
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  if (config_loaded == false) {
    cnfbuf = (char *)_cgmalloc(0x1000,"cgminer.c","load_default_config",0x812);
    default_save_file(cnfbuf);
    iVar54 = access(cnfbuf,4);
    if (iVar54 == 0) {
      load_config(cnfbuf,(void *)0x0);
    }
    else {
      free(cnfbuf);
      cnfbuf = (char *)0x0;
    }
  }
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
    ppVar21 = add_pool();
    pcVar17 = (char *)_cgmalloc(0xff,"cgminer.c","main",0x2d0f);
    pcVar16 = opt_benchfile;
    ppVar21->rpc_url = pcVar17;
    if (pcVar16 == (char *)0x0) {
      pcVar16 = "Benchmark";
    }
    else {
      pcVar16 = "Benchfile";
    }
    uVar15 = *(undefined4 *)(pcVar16 + 4);
    uVar1 = *(undefined2 *)(pcVar16 + 8);
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar16;
    *(undefined4 *)(pcVar17 + 4) = uVar15;
    *(undefined2 *)(pcVar17 + 8) = uVar1;
    pcVar16 = ppVar21->rpc_url;
    ppVar21->rpc_user = pcVar16;
    ppVar21->rpc_pass = pcVar16;
    ppVar21->rpc_userpass = pcVar16;
    ppVar21->sockaddr_url = pcVar16;
    strncpy(ppVar21->diff,"?",7);
    pVar42 = ppVar21->enabled;
    ppVar21->diff[7] = '\0';
    if (pVar42 != POOL_ENABLED) {
      ppVar21->enabled = POOL_ENABLED;
      enabled_pools = enabled_pools + 1;
    }
    pauVar43 = bench_hidiff_bins;
    ppVar21->idle = false;
    successful_connect = true;
    iVar54 = 0;
    do {
      iVar58 = iVar54 + 1;
      local_9e4 = *pauVar43;
      hex2bin((uchar *)((int)pauVar43 + iVar54 * 0xa0),bench_hidiffs[iVar54],0xa0);
      hex2bin(bench_lodiff_bins[iVar54],bench_lodiffs[iVar54],0xa0);
      pauVar43 = (uchar (*) [160])local_9e4;
      iVar54 = iVar58;
    } while (iVar58 != 0x10);
    set_target(bench_target,32.0);
  }
  if (opt_version_path == (char *)0x0) {
    local_9c4 = (char **)tmp42;
    local_9cc = (thr_info *)&use_syslog;
    local_9d0 = (block *)&opt_log_output;
  }
  else {
    pFVar22 = fopen(opt_version_path,"rb");
    memset(&sInfo,0,0x100);
    if (pFVar22 == (FILE *)0x0) {
      local_9cc = (thr_info *)&use_syslog;
      if (((use_syslog != false) || (local_9d0 = (block *)&opt_log_output, opt_log_output != false))
         || (2 < opt_log_level)) {
        local_9d0 = (block *)&opt_log_output;
        local_9c4 = (char **)tmp42;
        snprintf((char *)local_9c4,0x800,"Open miner version file %s error",opt_version_path);
        _applog(3,(char *)local_9c4,false);
        goto LAB_0000b544;
      }
      local_9c4 = (char **)tmp42;
LAB_0000b54a:
      if ((*(_Bool *)local_9d0 == false) && (opt_log_level < 3)) goto LAB_0000b57a;
    }
    else {
      psVar23 = (sysinfo *)fread(&sInfo,1,0x100,pFVar22);
      if ((int)psVar23 < 1) {
        local_9cc = (thr_info *)&use_syslog;
        if (((use_syslog == false) &&
            (local_9d0 = (block *)&opt_log_output, opt_log_output == false)) && (opt_log_level < 3))
        {
          local_9c4 = (char **)tmp42;
          goto LAB_0000b54a;
        }
        local_9d0 = (block *)&opt_log_output;
        local_9c4 = (char **)tmp42;
        snprintf((char *)local_9c4,0x800,"Read miner version file %s error %d",opt_version_path,
                 psVar23);
        _applog(3,(char *)local_9c4,false);
        pcVar53 = (char *)psVar23;
      }
      else {
        pcVar16 = strchr((char *)&sInfo,10);
        if (pcVar16 == (char *)0x0) {
          strcpy(g_miner_compiletime,(char *)&sInfo);
        }
        else {
          pcVar53 = "main";
          _cg_memcpy(g_miner_compiletime,&sInfo,(int)pcVar16 - (int)&sInfo,"cgminer.c","main",0x2d4a
                    );
          strcpy(g_miner_type,pcVar16 + 1);
        }
        sVar18 = strlen(g_miner_compiletime);
        if (*(char *)((int)&logcursor + sVar18 + 3) == '\n') {
          *(undefined1 *)((int)&logcursor + sVar18 + 3) = 0;
        }
        sVar18 = strlen(g_miner_compiletime);
        if (*(char *)((int)&logcursor + sVar18 + 3) == '\r') {
          *(undefined1 *)((int)&logcursor + sVar18 + 3) = 0;
        }
        sVar18 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar18 + 0xff] == '\n') {
          g_miner_compiletime[sVar18 + 0xff] = '\0';
        }
        sVar18 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar18 + 0xff] == '\r') {
          local_9c4 = (char **)tmp42;
          local_9cc = (thr_info *)&use_syslog;
          local_9d0 = (block *)&opt_log_output;
          g_miner_compiletime[sVar18 + 0xff] = '\0';
        }
        else {
          local_9c4 = (char **)tmp42;
          local_9cc = (thr_info *)&use_syslog;
          local_9d0 = (block *)&opt_log_output;
        }
      }
LAB_0000b544:
      if (*(char *)&local_9cc->id == '\0') goto LAB_0000b54a;
    }
    pcVar53 = g_miner_type;
    snprintf((char *)local_9c4,0x800,"Miner compile time: %s type: %s",g_miner_compiletime,
             g_miner_type);
    _applog(3,(char *)local_9c4,false);
  }
LAB_0000b57a:
  if (opt_logfile_path != (char *)0x0) {
    g_logfile_enable = true;
    strcpy(g_logfile_path,opt_logfile_path);
    if (opt_logfile_openflag != (char *)0x0) {
      strcpy(g_logfile_openflag,opt_logfile_openflag);
    }
    if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (2 < opt_log_level)
       ) {
      pcVar53 = g_logfile_openflag;
      snprintf((char *)local_9c4,0x800,"Log file path: %s Open flag: %s",g_logfile_path,
               g_logfile_openflag);
      _applog(3,(char *)local_9c4,false);
    }
  }
  pcVar16 = opt_logwork_path;
  if (opt_logwork_path != (char *)0x0) {
    memset(&sInfo,0,0x100);
    if (opt_logwork_asicnum == (char *)0x0) {
      if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
         (2 < opt_log_level)) {
        snprintf((char *)local_9c4,0x800,"Log work path: %s",pcVar16,pcVar53);
        _applog(3,(char *)local_9c4,false);
      }
    }
    else {
      if (*opt_logwork_asicnum == '\0') {
        *local_9c4 = (char *)0x20676f4c;
        local_9c4[1] = (char *)0x6b726f77;
        local_9c4[2] = (char *)0x69736120;
        local_9c4[3] = (char *)0x756e2063;
        local_9c4[4] = (char *)0x6d65206d;
        local_9c4[5] = (char *)0x797470;
        _applog(3,(char *)local_9c4,true);
        _quit(1);
      }
      g_logwork_asicnum = strtol(opt_logwork_asicnum,(char **)0x0,10);
      if ((g_logwork_asicnum != 0x20 && g_logwork_asicnum != 1) && (g_logwork_asicnum != 0x40)) {
        *local_9c4 = (char *)0x20676f4c;
        local_9c4[1] = (char *)0x6b726f77;
        local_9c4[2] = (char *)0x69736120;
        local_9c4[3] = (char *)0x756e2063;
        local_9c4[4] = (char *)0x756d206d;
        local_9c4[5] = (char *)0x62207473;
        local_9c4[6] = (char *)0x2c312065;
        local_9c4[7] = (char *)0x2c323320;
        local_9c4[8] = (char *)0x343620;
        _applog(3,(char *)local_9c4,true);
        _quit(1);
      }
      if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
         (2 < opt_log_level)) {
        pcVar53 = opt_logwork_asicnum;
        snprintf((char *)local_9c4,0x800,"Log work path: %s Asic num: %s",opt_logwork_path,
                 opt_logwork_asicnum);
        _applog(3,(char *)local_9c4,false);
      }
    }
    sprintf((char *)&sInfo,"%s.txt",opt_logwork_path);
    g_logwork_file = (FILE *)fopen((char *)&sInfo,"a+");
    if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (2 < opt_log_level)
       ) {
      snprintf((char *)local_9c4,0x800,"Log work open file %s",&sInfo);
      _applog(3,(char *)local_9c4,false);
    }
    ppcVar10 = local_9c4;
    ptVar27 = local_9cc;
    if (g_logwork_asicnum == 1) {
      sprintf((char *)&sInfo,"%s%02d.txt",opt_logwork_path);
      g_logwork_files[0] = (FILE *)fopen((char *)&sInfo,"a+");
      if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
         (2 < opt_log_level)) {
        pcVar53 = (char *)&sInfo;
        snprintf((char *)local_9c4,0x800,"Log work open asic %d file %s",g_logwork_asicnum,&sInfo);
        _applog(3,(char *)local_9c4,false);
      }
    }
    else if ((g_logwork_asicnum == 0x20 || g_logwork_asicnum == 0x40) && (-1 < g_logwork_asicnum)) {
      ppFVar60 = &g_logwork_file;
      psVar23 = (sysinfo *)0x0;
      do {
        pcVar53 = (char *)psVar23;
        sprintf((char *)&sInfo,"%s%02d_%02d.txt",opt_logwork_path,g_logwork_asicnum,psVar23);
        pFVar22 = fopen((char *)&sInfo,"a+");
        cVar2 = *(char *)&ptVar27->id;
        ppFVar60 = ppFVar60 + 1;
        *ppFVar60 = (FILE *)pFVar22;
        if (((cVar2 != '\0') || (*(_Bool *)local_9d0 != false)) || (2 < opt_log_level)) {
          pcVar53 = (char *)&sInfo;
          snprintf((char *)ppcVar10,0x800,"Log work open asic %d file %s",g_logwork_asicnum,&sInfo);
          _applog(3,(char *)ppcVar10,false);
        }
        psVar23 = (sysinfo *)((int)&psVar23->uptime + 1);
      } while ((int)psVar23 <= g_logwork_asicnum);
    }
    ppcVar10 = local_9c4;
    pbVar19 = local_9d0;
    if (opt_logwork_diff != false) {
      p_Var61 = &opt_logwork_diff;
      iVar54 = 0;
      do {
        sprintf((char *)&sInfo,"%s_diff_%02d.txt",opt_logwork_path,iVar54);
        pFVar22 = fopen((char *)&sInfo,"a+");
        p_Var61 = p_Var61 + 4;
        *(FILE **)p_Var61 = pFVar22;
        if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)pbVar19 != false)) ||
           (2 < opt_log_level)) {
          snprintf((char *)ppcVar10,0x800,"Log work open diff file %s",&sInfo);
          _applog(3,(char *)ppcVar10,false);
        }
        iVar54 = iVar54 + 1;
      } while (iVar54 != 0x41);
    }
  }
  if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (3 < opt_log_level))
  {
    snprintf((char *)local_9c4,0x800,"Started %s",packagename,pcVar53);
    _applog(4,(char *)local_9c4,false);
  }
  if (cnfbuf != (char *)0x0) {
    if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (4 < opt_log_level)
       ) {
      snprintf((char *)local_9c4,0x800,"Loaded configuration file %s");
      _applog(5,(char *)local_9c4,false);
    }
    if (fileconf_load == -1) {
      if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
         (3 < opt_log_level)) {
        *local_9c4 = (char *)0x6f727245;
        local_9c4[1] = (char *)0x6e692072;
        local_9c4[2] = (char *)0x6e6f6320;
        local_9c4[3] = (char *)0x75676966;
        local_9c4[4] = (char *)0x69746172;
        local_9c4[5] = (char *)0x66206e6f;
        local_9c4[6] = (char *)0x2c656c69;
        local_9c4[7] = (char *)0x72617020;
        local_9c4[8] = (char *)0x6c616974;
        local_9c4[9] = (char *)0x6c20796c;
        local_9c4[10] = (char *)0x6564616f;
        *(undefined2 *)(local_9c4 + 0xb) = 0x2e64;
        *(undefined1 *)((int)local_9c4 + 0x2e) = 0;
        _applog(4,(char *)local_9c4,false);
      }
      if ((use_curses != false) &&
         (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
          (3 < opt_log_level)))) {
        *local_9c4 = (char *)0x72617453;
        local_9c4[1] = (char *)0x67632074;
        local_9c4[2] = (char *)0x656e696d;
        local_9c4[3] = (char *)0x69772072;
        local_9c4[4] = (char *)0x2d206874;
        local_9c4[5] = (char *)0x6f742054;
        local_9c4[6] = (char *)0x65657320;
        local_9c4[7] = (char *)0x61687720;
        local_9c4[8] = (char *)0x61662074;
        local_9c4[9] = (char *)0x64656c69;
        local_9c4[10] = (char *)0x206f7420;
        local_9c4[0xb] = (char *)0x64616f6c;
        *(undefined2 *)(local_9c4 + 0xc) = 0x2e;
        _applog(4,(char *)local_9c4,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((*(char *)&local_9cc->id == '\0') && (*(_Bool *)local_9d0 == false)) &&
         (local_9d8 = &opt_log_level, opt_log_level < 4)) {
LAB_0000b932:
        local_9d8 = &opt_log_level;
        if (opt_log_level < 4) goto LAB_0000b95a;
      }
      else {
        *local_9c4 = (char *)0x61746146;
        local_9c4[1] = (char *)0x534a206c;
        local_9c4[2] = (char *)0x65204e4f;
        local_9c4[3] = (char *)0x726f7272;
        local_9c4[4] = (char *)0x206e6920;
        local_9c4[5] = (char *)0x666e6f63;
        local_9c4[6] = (char *)0x72756769;
        local_9c4[7] = (char *)0x6f697461;
        local_9c4[8] = (char *)0x6966206e;
        local_9c4[9] = (char *)0x2e656c;
        _applog(4,(char *)local_9c4,false);
        if ((*(char *)&local_9cc->id == '\0') && (*(_Bool *)local_9d0 == false)) goto LAB_0000b932;
      }
      *local_9c4 = (char *)0x666e6f43;
      local_9c4[1] = (char *)0x72756769;
      local_9c4[2] = (char *)0x6f697461;
      local_9c4[3] = (char *)0x6966206e;
      local_9c4[4] = (char *)0x6320656c;
      local_9c4[5] = (char *)0x646c756f;
      local_9c4[6] = (char *)0x746f6e20;
      local_9c4[7] = (char *)0x20656220;
      local_9c4[8] = (char *)0x64657375;
      *(undefined2 *)(local_9c4 + 9) = 0x2e;
      _applog(4,(char *)local_9c4,false);
    }
LAB_0000b95a:
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar53 = opt_kernel_path;
  sVar18 = strlen(opt_kernel_path);
  (pcVar53 + sVar18)[0] = '/';
  (pcVar53 + sVar18)[1] = '\0';
  if (want_per_device_stats == false) {
    if (*(_Bool *)local_9d0 != false) goto LAB_0000bbe4;
    setlogmask(0x3f);
  }
  else {
    *(_Bool *)local_9d0 = true;
LAB_0000bbe4:
    setlogmask(0xff);
  }
  iVar54 = 0;
  if (opt_scantime < 0) {
    opt_scantime = 0x3c;
  }
  total_control_threads = 8;
  control_thr = (thr_info *)_cgcalloc(8,0x40,"cgminer.c","main",0x2de6);
  gwsched_thr_id = 0;
  fill_device_drv(&bitforce_drv);
  fill_device_drv(&modminer_drv);
  fill_device_drv(&bitmain_drv);
  fill_device_drv(&bitmain_c5_drv);
  (*bitforce_drv.drv_detect)(false);
  (*modminer_drv.drv_detect)(false);
  (*bitmain_drv.drv_detect)(false);
  (*bitmain_c5_drv.drv_detect)(false);
  mining_threads = 0;
  if (0 < total_devices) {
    do {
      ppcVar50 = devices + iVar54;
      iVar54 = iVar54 + 1;
      enable_device(*ppcVar50);
    } while (iVar54 < total_devices);
  }
  if (total_devices == 0) {
    *local_9c4 = (char *)0x206c6c41;
    local_9c4[1] = (char *)0x69766564;
    local_9c4[2] = (char *)0x20736563;
    local_9c4[3] = (char *)0x61736964;
    local_9c4[4] = (char *)0x64656c62;
    local_9c4[5] = (char *)0x6163202c;
    local_9c4[6] = (char *)0x746f6e6e;
    local_9c4[7] = (char *)0x6e696d20;
    *(undefined2 *)(local_9c4 + 8) = 0x2174;
    *(undefined1 *)((int)local_9c4 + 0x22) = 0;
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  most_devices = total_devices;
  if (temp_cutoff_str == (char *)0x0) {
    iVar54 = pthread_rwlock_rdlock((pthread_rwlock_t *)&devices_lock);
    ppcVar50 = line_15;
    if (iVar54 != 0) {
      _rd_lock((pthread_rwlock_t *)"load_temp_cutoffs",(char *)0x51c,func_02,(int)line_15);
      ppcVar50 = extraout_r3_01;
    }
    if (0 < total_devices) {
      ppcVar55 = devices + total_devices;
      ppcVar44 = devices;
      do {
        ppcVar50 = ppcVar44 + 1;
        if ((*ppcVar44)->cutofftemp == 0) {
          (*ppcVar44)->cutofftemp = 0x5f;
        }
        ppcVar44 = ppcVar50;
      } while (ppcVar50 != ppcVar55);
    }
    _rd_unlock(&devices_lock,"load_temp_cutoffs",(char *)0x525,(int)ppcVar50);
  }
  else {
    pcVar53 = strtok(temp_cutoff_str,",");
    ppcVar10 = local_9c4;
    if (pcVar53 == (char *)0x0) {
      iVar54 = 0;
      uVar34 = 0;
    }
    else {
      pp_Stack_9e0 = &selective_yield;
      iVar54 = 0;
      do {
        if (total_devices <= iVar54) {
          *ppcVar10 = (char *)0x206f6f54;
          ppcVar10[1] = (char *)0x796e616d;
          ppcVar10[2] = (char *)0x6c617620;
          ppcVar10[3] = (char *)0x20736575;
          ppcVar10[4] = (char *)0x73736170;
          ppcVar10[5] = (char *)0x74206465;
          ppcVar10[6] = (char *)0x6573206f;
          ppcVar10[7] = (char *)0x65742074;
          ppcVar10[8] = (char *)0x6320706d;
          ppcVar10[9] = (char *)0x666f7475;
          *(undefined2 *)(ppcVar10 + 10) = 0x66;
          _applog(3,(char *)ppcVar10,true);
          _quit(1);
        }
        uVar34 = strtol(pcVar53,(char **)0x0,10);
        if (200 < uVar34) {
          *ppcVar10 = (char *)0x61766e49;
          ppcVar10[1] = (char *)0x2064696c;
          ppcVar10[2] = (char *)0x756c6176;
          ppcVar10[3] = (char *)0x61702065;
          ppcVar10[4] = (char *)0x64657373;
          ppcVar10[5] = (char *)0x206f7420;
          ppcVar10[6] = (char *)0x20746573;
          ppcVar10[7] = (char *)0x706d6574;
          ppcVar10[8] = (char *)0x74756320;
          ppcVar10[9] = (char *)0x66666f;
          _applog(3,(char *)ppcVar10,true);
          _quit(1);
        }
        iVar58 = pthread_rwlock_rdlock((pthread_rwlock_t *)&devices_lock);
        if (iVar58 != 0) {
          _rd_lock((pthread_rwlock_t *)"load_temp_cutoffs",(char *)0x515,func_00,line_13);
        }
        devices[iVar54]->cutofftemp = uVar34;
        iVar58 = pthread_rwlock_unlock((pthread_rwlock_t *)&devices_lock);
        if (iVar58 != 0) {
          _rw_unlock((pthread_rwlock_t *)"load_temp_cutoffs",(char *)0x517,func,line_12);
        }
        iVar54 = iVar54 + 1;
        (**pp_Stack_9e0)();
        pcVar53 = strtok((char *)0x0,",");
      } while (pcVar53 != (char *)0x0);
      if (iVar54 != 1) goto code_r0x0000bc7a;
      iVar54 = 1;
    }
    iVar58 = pthread_rwlock_rdlock((pthread_rwlock_t *)&devices_lock);
    ppcVar50 = line_14;
    if (iVar58 != 0) {
      _rd_lock((pthread_rwlock_t *)"load_temp_cutoffs",(char *)0x52c,func_01,(int)line_14);
      ppcVar50 = extraout_r3_00;
    }
    if (iVar54 < total_devices) {
      ppcVar50 = devices + total_devices;
      ppcVar44 = devices + iVar54;
      do {
        ppcVar55 = ppcVar44 + 1;
        (*ppcVar44)->cutofftemp = uVar34;
        ppcVar44 = ppcVar55;
      } while (ppcVar55 != ppcVar50);
    }
    _rd_unlock(&devices_lock,"load_temp_cutoffs",(char *)0x532,(int)ppcVar50);
  }
code_r0x0000bc7a:
  if (0 < total_devices) {
    ppcVar44 = devices + total_devices;
    ppcVar50 = devices;
    do {
      ppcVar55 = ppcVar50 + 1;
      ((*ppcVar50)->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
      ppcVar50 = ppcVar55;
    } while (ppcVar55 != ppcVar44);
  }
  if (opt_compact == false) {
    logstart = logstart + most_devices;
    logcursor = logstart + 1;
  }
  if (total_pools == 0) {
    if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (3 < opt_log_level)
       ) {
      *local_9c4 = (char *)0x6465654e;
      local_9c4[1] = (char *)0x206f7420;
      local_9c4[2] = (char *)0x63657073;
      local_9c4[3] = (char *)0x20796669;
      local_9c4[4] = (char *)0x6c207461;
      local_9c4[5] = (char *)0x74736165;
      local_9c4[6] = (char *)0x656e6f20;
      local_9c4[7] = (char *)0x6f6f7020;
      local_9c4[8] = (char *)0x6573206c;
      local_9c4[9] = (char *)0x72657672;
      *(undefined2 *)(local_9c4 + 10) = 0x2e;
      _applog(4,(char *)local_9c4,false);
    }
    *local_9c4 = (char *)0x6c6f6f50;
    local_9c4[1] = (char *)0x74657320;
    local_9c4[2] = (char *)0x66207075;
    local_9c4[3] = (char *)0x656c6961;
    *(undefined2 *)(local_9c4 + 4) = 100;
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  ppppStack_9d4 = &pools;
  if (0 < total_pools) {
    iVar54 = 0;
    pppVar45 = pools;
    do {
      ppVar21 = pppVar45[iVar54];
      pcVar53 = ppVar21->rpc_userpass;
      (ppVar21->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
      (ppVar21->cgminer_pool_stats).getwork_wait_min.tv_sec = 99999999;
      if (pcVar53 == (char *)0x0) {
        if (ppVar21->rpc_pass == (char *)0x0) {
          pcVar53 = (char *)calloc(1,1);
          ppVar21->rpc_pass = pcVar53;
        }
        if (ppVar21->rpc_user == (char *)0x0) {
          snprintf((char *)local_9c4,0x800,"No login credentials supplied for pool %u %s",iVar54,
                   ppVar21->rpc_url);
          goto LAB_0000cdee;
        }
        sVar18 = strlen(ppVar21->rpc_user);
        sVar24 = strlen(ppVar21->rpc_pass);
        uVar34 = sVar18 + sVar24 + 2;
        pcVar53 = (char *)_cgmalloc(uVar34,"cgminer.c","main",0x2e53);
        ppVar21->rpc_userpass = pcVar53;
        snprintf(pcVar53,uVar34,"%s:%s",ppVar21->rpc_user,ppVar21->rpc_pass);
        pppVar45 = *ppppStack_9d4;
      }
      iVar54 = iVar54 + 1;
    } while (iVar54 < total_pools);
  }
  currentpool = **ppppStack_9d4;
  if (*(char *)&local_9cc->id != '\0') {
    openlog("bmminer",1,8);
  }
  if (opt_stderr_cmd != (char *)0x0) {
    iVar54 = pipe((int *)local_9c4);
    if (iVar54 < 0) {
      perror("pipe - failed to create pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(stderr);
    iVar54 = dup2((int)local_9c4[1],2);
    if (iVar54 < 0) {
      perror("dup2 - failed to alias stderr to write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar54 = close((int)local_9c4[1]);
    if (iVar54 < 0) {
      perror("close - failed to close write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    p_Var25 = signal(0xd,(__sighandler_t)0x1);
    p_Var26 = signal(0xd,(__sighandler_t)0x1);
    if ((p_Var26 == (__sighandler_t)0xffffffff) || (p_Var25 == (__sighandler_t)0xffffffff)) {
      perror("signal - failed to edit signal mask for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    forkpid = fork();
    if (forkpid < 0) {
      perror("fork - failed to fork child process for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (forkpid == 0) {
      iVar54 = dup2((int)*local_9c4,0);
      if (-1 < iVar54) {
        close((int)*local_9c4);
        execl("/bin/bash","/bin/bash",&DAT_0004e424,opt_stderr_cmd,0);
        perror("execl - in child failed to exec user specified command for --monitor");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      perror("dup2 - in child, failed to alias read end of pipe to stdin for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar54 = close((int)*local_9c4);
    if (iVar54 < 0) {
      perror("close - failed to close read end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,"cgminer.c","main",0x2e64);
  if (0 < mining_threads) {
    iVar54 = 0;
    do {
      pptVar28 = mining_thr;
      ptVar27 = (thr_info *)_cgcalloc(1,0x40,"cgminer.c","main",0x2e68);
      iVar58 = mining_threads;
      pptVar28[iVar54] = ptVar27;
      iVar54 = iVar54 + 1;
    } while (iVar54 < iVar58);
  }
  if (0 < total_devices) {
    iVar54 = 0;
    local_9c0 = (pool *)0x0;
    do {
      iVar62 = 0;
      pcVar56 = devices[(int)local_9c0];
      pptVar28 = (thr_info **)_cgmalloc((pcVar56->threads + 1) * 4,"cgminer.c","main",0x2e71);
      iVar58 = pcVar56->threads;
      pcVar56->thr = pptVar28;
      pptVar28[iVar58] = (thr_info *)0x0;
      pcVar56->status = LIFE_INIT;
      if (0 < iVar58) {
        do {
          while( true ) {
            ptVar27 = get_thread(iVar54);
            pdVar46 = pcVar56->drv;
            ptVar27->id = iVar54;
            ptVar27->cgpu = pcVar56;
            p_Var47 = pdVar46->thread_prepare;
            ptVar27->device_thread = iVar62;
            _Var12 = (*p_Var47)(ptVar27);
            if (_Var12) break;
LAB_0000c3a0:
            iVar62 = iVar62 + 1;
            iVar54 = iVar54 + 1;
            if (pcVar56->threads <= iVar62) goto LAB_0000c452;
          }
          iVar58 = thr_info_create(ptVar27,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x1e301,
                                   ptVar27);
          if (iVar58 != 0) {
            snprintf((char *)local_9c4,0x800,"thread %d create failed",ptVar27->id);
            _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
            __quit(1,false);
          }
          dVar48 = pcVar56->deven;
          pcVar56->thr[iVar62] = ptVar27;
          if (dVar48 == DEV_DISABLED) goto LAB_0000c3a0;
          if ((opt_debug != false) &&
             (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
              (6 < opt_log_level)))) {
            snprintf((char *)local_9c4,0x800,"Pushing sem post to thread %d",ptVar27->id);
            _applog(7,(char *)local_9c4,false);
          }
          iVar62 = iVar62 + 1;
          iVar54 = iVar54 + 1;
          _cgsem_post(&ptVar27->sem,"cgminer.c","main",0x2e8d);
        } while (iVar62 < pcVar56->threads);
      }
LAB_0000c452:
      local_9c0 = (pool *)((int)&local_9c0->pool_no + 1);
    } while ((int)local_9c0 < total_devices);
  }
  iVar54 = total_pools;
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
LAB_0000c47c:
    pdVar49 = g_local_mhashes_dones;
    total_mhashes_done = 0.0;
    do {
      *pdVar49 = 0.0;
      pdVar49 = pdVar49 + 1;
    } while (pdVar49 != (double *)&g_local_mhashes_index);
    g_local_mhashes_index = 0;
    if (0 < total_devices) {
      ppcVar44 = devices + total_devices;
      ppcVar50 = devices;
      do {
        ppcVar55 = ppcVar50 + 1;
        pcVar56 = *ppcVar50;
        pcVar56->total_mhashes = 0.0;
        pcVar56->rolling = 0.0;
        ppcVar50 = ppcVar55;
      } while (ppcVar55 != ppcVar44);
    }
    iVar54 = sysinfo((sysinfo *)&sInfo);
    if (iVar54 == 0) {
      total_tv_end_sys = sInfo.uptime;
      total_tv_start_sys = sInfo.uptime;
    }
    else {
      if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
         (5 < opt_log_level)) {
        piVar29 = __errno_location();
        iVar54 = *piVar29;
        pcVar53 = strerror(iVar54);
        snprintf((char *)local_9c4,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar54,
                 pcVar53);
        _applog(6,(char *)local_9c4,false);
      }
      total_tv_end_sys = time((time_t *)0x0);
      total_tv_start_sys = time((time_t *)0x0);
    }
    cgtime(&total_tv_start);
    cgtime(&total_tv_end);
    cgtime(&tv_hashmeter);
    get_datestamp(datestamp,0x28,&total_tv_start);
    ptVar27 = control_thr;
    watchpool_thr_id = 2;
    iVar54 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,
                             (_func_void_ptr_void_ptr *)0x26089,(void *)0x0);
    if (iVar54 != 0) {
      *local_9c4 = (char *)0x63746177;
      local_9c4[1] = (char *)0x6f6f7068;
      local_9c4[2] = (char *)0x6874206c;
      local_9c4[3] = (char *)0x64616572;
      local_9c4[4] = (char *)0x65726320;
      local_9c4[5] = (char *)0x20657461;
      local_9c4[6] = (char *)0x6c696166;
      *(undefined2 *)(local_9c4 + 7) = 0x6465;
      *(undefined1 *)((int)local_9c4 + 0x1e) = 0;
      _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
      __quit(1,false);
    }
    pthread_detach(ptVar27[2].pth);
    watchdog_thr_id = 3;
    local_9e8 = control_thr;
    iVar54 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,
                             (_func_void_ptr_void_ptr *)0x284d1,(void *)0x0);
    if (iVar54 != 0) {
      *local_9c4 = (char *)0x63746177;
      local_9c4[1] = (char *)0x676f6468;
      local_9c4[2] = (char *)0x72687420;
      local_9c4[3] = (char *)0x20646165;
      local_9c4[4] = (char *)0x61657263;
      local_9c4[5] = (char *)0x66206574;
      local_9c4[6] = (char *)0x656c6961;
      *(undefined2 *)(local_9c4 + 7) = 100;
      _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
      __quit(1,false);
    }
    pthread_detach(local_9e8[3].pth);
    api_thr_id = 5;
    iVar54 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,
                             (_func_void_ptr_void_ptr *)0x1e7c5,control_thr + 5);
    if (iVar54 == 0) {
      if (total_control_threads != 8) {
        snprintf((char *)local_9c4,0x800,"incorrect total_control_threads (%d) should be 8");
        _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
        __quit(1,false);
      }
      iVar54 = nice(-10);
      if (iVar54 == 0) {
        local_9c8 = (block *)&opt_debug;
        if (opt_debug == false) {
          pp_Stack_9e0 = &selective_yield;
          local_9d8 = &opt_log_level;
          p_Stack_9dc = &opt_work_update;
        }
        else if (((*(char *)&local_9cc->id == '\0') && (*(_Bool *)local_9d0 == false)) &&
                (local_9d8 = &opt_log_level, opt_log_level < 7)) {
          pp_Stack_9e0 = &selective_yield;
          p_Stack_9dc = &opt_work_update;
        }
        else {
          local_9d8 = &opt_log_level;
          pp_Stack_9e0 = &selective_yield;
          p_Stack_9dc = &opt_work_update;
          *local_9c4 = (char *)0x62616e55;
          local_9c4[1] = (char *)0x7420656c;
          local_9c4[2] = (char *)0x6573206f;
          local_9c4[3] = (char *)0x68742074;
          local_9c4[4] = (char *)0x64616572;
          local_9c4[5] = (char *)0x206f7420;
          local_9c4[6] = (char *)0x68676968;
          local_9c4[7] = (char *)0x69727020;
          local_9c4[8] = (char *)0x7469726f;
          *(undefined2 *)(local_9c4 + 9) = 0x79;
          _applog(7,(char *)local_9c4,false);
        }
      }
      else {
        pp_Stack_9e0 = &selective_yield;
        local_9d8 = &opt_log_level;
        local_9c8 = (block *)&opt_debug;
        p_Stack_9dc = &opt_work_update;
      }
LAB_0000c830:
      do {
        cVar2 = *p_Stack_9dc;
        while( true ) {
          if (cVar2 != '\0') {
            if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) ||
               (5 < *local_9d8)) {
              *local_9c4 = (char *)0x6b726f57;
              ((int *)local_9c4)[1] = 0x64707520;
              ((int *)local_9c4)[2] = 0x20657461;
              ((int *)local_9c4)[3] = 0x7373656d;
              ((int *)local_9c4)[4] = 0x20656761;
              ((int *)local_9c4)[5] = 0x65636572;
              ((int *)local_9c4)[6] = 0x64657669;
              *(char *)((int *)local_9c4 + 7) = '\0';
              _applog(6,(char *)local_9c4,false);
            }
            cgtime(&update_tv_start);
            iVar54 = pthread_rwlock_rdlock((pthread_rwlock_t *)&mining_thr_lock);
            if (iVar54 != 0) {
              _rd_lock((pthread_rwlock_t *)"signal_work_update",(char *)0x151a,func_05,line_18);
            }
            if (0 < mining_threads) {
              pptVar33 = mining_thr + mining_threads;
              pptVar28 = mining_thr;
              do {
                pptVar52 = pptVar28 + 1;
                (*pptVar28)->work_update = true;
                pptVar28 = pptVar52;
              } while (pptVar52 != pptVar33);
            }
            iVar54 = pthread_rwlock_unlock((pthread_rwlock_t *)&mining_thr_lock);
            if (iVar54 != 0) {
              _rw_unlock((pthread_rwlock_t *)"signal_work_update",(char *)0x1521,func_06,line_19);
            }
            (**pp_Stack_9e0)();
          }
          __mutex = stgd_lock;
          *p_Stack_9dc = false;
          iVar54 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
          if (iVar54 != 0) {
            _mutex_lock((pthread_mutex_t *)"main",(char *)0x2f3c,func_03,line_16);
          }
          pwVar57 = staged_work;
          if ((staged_work != (work *)0x0) &&
             (pwVar57 = (work *)((staged_work->hh).tbl)->num_items, 1 < (int)pwVar57)) {
            work_filled = true;
            pthread_cond_wait((pthread_cond_t *)&gws_cond,(pthread_mutex_t *)stgd_lock);
            pwVar57 = staged_work;
            if (staged_work != (work *)0x0) {
              pwVar57 = (work *)((staged_work->hh).tbl)->num_items;
            }
          }
          iVar54 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
          if (iVar54 != 0) {
            _mutex_unlock_noyield((pthread_mutex_t *)"main",(char *)0x2f47,func_04,line_17);
          }
          (**pp_Stack_9e0)();
          if (1 < (int)pwVar57) break;
          if (local_9b8 != (work *)0x0) {
            _discard_work(&local_9b8,"cgminer.c","main",0x2f5b);
          }
          local_9b8 = make_work();
LAB_0000c96a:
          local_9c0 = current_pool();
          iVar54 = total_pools;
          if (pool_strategy == POOL_BALANCE) {
            ppVar21 = select_balanced(local_9c0);
          }
          else {
            ppVar21 = local_9c0;
            if (pool_strategy == POOL_LOADBALANCE) {
              if (total_pools < 1) {
LAB_0000c9d2:
                select_pool::rotating_pool = select_pool::rotating_pool + 1;
                if (iVar54 <= select_pool::rotating_pool) {
                  select_pool::rotating_pool = 0;
                }
              }
              else {
                pppVar45 = *ppppStack_9d4;
                if ((*pppVar45)->quota_gcd <= (*pppVar45)->quota_used) {
                  iVar58 = 0;
                  pppVar31 = pppVar45;
LAB_0000c9bc:
                  iVar58 = iVar58 + 1;
                  if (iVar58 != total_pools) goto LAB_0000c9b0;
                  pppVar31 = pppVar45 + total_pools;
                  do {
                    pppVar63 = pppVar45 + 1;
                    (*pppVar45)->quota_used = 0;
                    pppVar45 = pppVar63;
                  } while (pppVar63 != pppVar31);
                  goto LAB_0000c9d2;
                }
              }
LAB_0000c9e4:
              puVar38 = (uchar *)*ppppStack_9d4;
              iVar58 = 0;
              while (iVar62 = select_pool::rotating_pool, iVar58 < iVar54) {
                ppVar21 = *(pool **)(puVar38 + select_pool::rotating_pool * 4);
                iVar51 = ppVar21->quota_used;
                ppVar21->quota_used = iVar51 + 1;
                if ((iVar51 < ppVar21->quota_gcd) &&
                   (local_9e4 = puVar38, _Var12 = pool_unusable(ppVar21), puVar38 = local_9e4,
                   !_Var12)) goto LAB_0000c8b6;
                select_pool::rotating_pool = iVar62 + 1;
                iVar58 = iVar58 + 1;
                if (iVar54 <= select_pool::rotating_pool) {
                  select_pool::rotating_pool = 0;
                }
              }
              ppVar21 = local_9c0;
              if (0 < iVar54) {
                iVar54 = 0;
                do {
                  ppVar30 = priority_pool(iVar54);
                  _Var12 = pool_unusable(ppVar30);
                  ppVar21 = local_9c0;
                  if (!_Var12) {
                    if (ppVar30 != (pool *)0x0) {
                      ppVar21 = ppVar30;
                    }
                    break;
                  }
                  iVar54 = iVar54 + 1;
                } while (iVar54 < total_pools);
              }
            }
          }
LAB_0000c8b6:
          local_9c0 = ppVar21;
          if ((*(_Bool *)local_9c8 != false) &&
             (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
              (6 < *local_9d8)))) {
            snprintf((char *)local_9c4,0x800,"Selecting pool %d for work",local_9c0->pool_no);
            _applog(7,(char *)local_9c4,false);
          }
          _Var12 = pool_unusable(local_9c0);
          if (_Var12) {
            switch_pools((pool *)0x0);
            local_9c0 = current_pool();
            iVar54 = total_pools;
            if (pool_strategy == POOL_BALANCE) {
              ppVar21 = select_balanced(local_9c0);
            }
            else {
              ppVar21 = local_9c0;
              if (pool_strategy == POOL_LOADBALANCE) {
                if (total_pools < 1) {
LAB_0000caee:
                  select_pool::rotating_pool = select_pool::rotating_pool + 1;
                  if (iVar54 <= select_pool::rotating_pool) {
                    select_pool::rotating_pool = 0;
                  }
                }
                else {
                  pppVar45 = *ppppStack_9d4;
                  if ((*pppVar45)->quota_gcd <= (*pppVar45)->quota_used) {
                    iVar58 = 0;
                    pppVar31 = pppVar45;
LAB_0000cad8:
                    iVar58 = iVar58 + 1;
                    if (iVar58 != total_pools) goto LAB_0000cacc;
                    pppVar31 = pppVar45 + total_pools;
                    do {
                      pppVar63 = pppVar45 + 1;
                      (*pppVar45)->quota_used = 0;
                      pppVar45 = pppVar63;
                    } while (pppVar63 != pppVar31);
                    goto LAB_0000caee;
                  }
                }
LAB_0000cb00:
                puVar38 = (uchar *)*ppppStack_9d4;
                iVar58 = 0;
                while (iVar62 = select_pool::rotating_pool, iVar58 < iVar54) {
                  ppVar21 = *(pool **)(puVar38 + select_pool::rotating_pool * 4);
                  iVar51 = ppVar21->quota_used;
                  ppVar21->quota_used = iVar51 + 1;
                  if ((iVar51 < ppVar21->quota_gcd) &&
                     (local_9e4 = puVar38, _Var12 = pool_unusable(ppVar21), puVar38 = local_9e4,
                     !_Var12)) goto LAB_0000c922;
                  select_pool::rotating_pool = iVar62 + 1;
                  iVar58 = iVar58 + 1;
                  if (iVar54 <= select_pool::rotating_pool) {
                    select_pool::rotating_pool = 0;
                  }
                }
                ppVar21 = local_9c0;
                if (0 < iVar54) {
                  iVar54 = 0;
                  do {
                    ppVar30 = priority_pool(iVar54);
                    _Var12 = pool_unusable(ppVar30);
                    ppVar21 = local_9c0;
                    if (!_Var12) {
                      if (ppVar30 != (pool *)0x0) {
                        ppVar21 = ppVar30;
                      }
                      break;
                    }
                    iVar54 = iVar54 + 1;
                  } while (iVar54 < total_pools);
                }
              }
            }
LAB_0000c922:
            local_9c0 = ppVar21;
            if ((*(_Bool *)local_9c8 != false) &&
               (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
                (6 < *local_9d8)))) {
              snprintf((char *)local_9c4,0x800,"Selecting pool %d for work",local_9c0->pool_no);
              _applog(7,(char *)local_9c4,false);
            }
            _Var12 = pool_unusable(local_9c0);
            if (_Var12) {
              cgsleep_ms(0xb);
            }
            goto LAB_0000c96a;
          }
          if (local_9c0->has_stratum == false) {
            if (opt_benchfile == (char *)0x0) {
              if (opt_benchmark == false) goto LAB_0000c830;
              get_benchmark_work(local_9b8);
              if ((*(_Bool *)local_9c8 != false) &&
                 (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
                  (6 < *local_9d8)))) {
                pcVar53 = "Generated benchmark work";
                goto LAB_0000cbe8;
              }
            }
            else {
              get_benchfile_work(local_9b8);
              if ((*(_Bool *)local_9c8 != false) &&
                 (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
                  (6 < *local_9d8)))) {
                pcVar53 = "Generated benchfile work";
LAB_0000cbe8:
                iVar54 = *(int *)((int)pcVar53 + 4);
                iVar58 = *(int *)((int)pcVar53 + 8);
                iVar62 = *(int *)((int)pcVar53 + 0xc);
                *local_9c4 = (char *)*(int *)pcVar53;
                local_9c4[1] = (char *)iVar54;
                local_9c4[2] = (char *)iVar58;
                local_9c4[3] = (char *)iVar62;
                iVar54 = *(int *)((int)pcVar53 + 0x14);
                iVar58 = *(int *)((int)pcVar53 + 0x18);
                local_9c4[4] = (char *)*(int *)((int)pcVar53 + 0x10);
                local_9c4[5] = (char *)iVar54;
                *(char *)(local_9c4 + 6) = (char)iVar58;
                _applog(7,(char *)local_9c4,false);
              }
            }
          }
          else {
            gen_stratum_work(local_9c0,local_9b8);
            if ((*(_Bool *)local_9c8 != false) &&
               (((*(char *)&local_9cc->id != '\0' || (*(_Bool *)local_9d0 != false)) ||
                (6 < *local_9d8)))) {
              *local_9c4 = (char *)0x656e6547;
              local_9c4[1] = (char *)0x65746172;
              local_9c4[2] = (char *)0x74732064;
              local_9c4[3] = (char *)0x75746172;
              local_9c4[4] = (char *)0x6f77206d;
              *(undefined2 *)(local_9c4 + 5) = 0x6b72;
              *(undefined1 *)((int)local_9c4 + 0x16) = 0;
              _applog(7,(char *)local_9c4,false);
            }
          }
          _stage_work(local_9b8);
          local_9b8 = (work *)0x0;
          cVar2 = *p_Stack_9dc;
        }
        work_filled = true;
        local_9b8 = hash_pop(false);
        if (local_9b8 != (work *)0x0) {
          _discard_work(&local_9b8,"cgminer.c","main",0x2f53);
        }
      } while( true );
    }
    *local_9c4 = (char *)0x20495041;
    local_9c4[1] = (char *)0x65726874;
    local_9c4[2] = (char *)0x63206461;
    local_9c4[3] = (char *)0x74616572;
    local_9c4[4] = (char *)0x61662065;
    local_9c4[5] = (char *)0x64656c69;
    *(undefined1 *)(local_9c4 + 6) = 0;
LAB_0000cdee:
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  pppVar45 = *ppppStack_9d4;
  iVar58 = 0;
  while (iVar58 < iVar54) {
    ppVar21 = pppVar45[iVar58];
    iVar58 = iVar58 + 1;
    ppVar21->idle = true;
    bVar65 = ppVar21->enabled != POOL_ENABLED;
    if (bVar65) {
      enabled_pools = enabled_pools + 1;
    }
    if (bVar65) {
      ppVar21->enabled = POOL_ENABLED;
    }
  }
  if (((*(char *)&local_9cc->id != '\0') || (*(_Bool *)local_9d0 != false)) || (4 < opt_log_level))
  {
    *local_9c4 = (char *)0x626f7250;
    local_9c4[1] = (char *)0x20676e69;
    local_9c4[2] = (char *)0x20726f66;
    local_9c4[3] = (char *)0x61206e61;
    local_9c4[4] = (char *)0x6576696c;
    local_9c4[5] = (char *)0x6f6f7020;
    *(undefined2 *)(local_9c4 + 6) = 0x6c;
    _applog(5,(char *)local_9c4,false);
  }
  ppppVar9 = ppppStack_9d4;
  for (iVar54 = 0; iVar54 < total_pools; iVar54 = iVar54 + 1) {
    ppVar21 = (*ppppVar9)[iVar54];
    ppVar21->testing = true;
    pthread_create(&ppVar21->test_thread,(pthread_attr_t *)0x0,(__start_routine *)0x25f51,ppVar21);
  }
  iVar54 = 0x3c;
  do {
    sleep(1);
    ppcVar10 = local_9c4;
    pbVar19 = local_9d0;
    if (pools_active != false) break;
    iVar54 = iVar54 + -1;
  } while (iVar54 != 0);
  bVar65 = false;
  ptVar27 = local_9cc;
LAB_0000c78e:
  do {
    if (pools_active != false) goto LAB_0000c47c;
    if (bVar65) {
      puVar38 = &use_curses;
    }
    else {
      if (((*(char *)&ptVar27->id == '\0') && (*(_Bool *)pbVar19 == false)) && (opt_log_level < 3))
      {
LAB_0000cf8a:
        if (2 < opt_log_level) goto LAB_0000cf90;
LAB_0000cfb2:
        if (2 < opt_log_level) goto LAB_0000cfb8;
      }
      else {
        *ppcVar10 = (char *)0x73206f4e;
        ppcVar10[1] = (char *)0x65767265;
        ppcVar10[2] = (char *)0x77207372;
        ppcVar10[3] = (char *)0x20657265;
        ppcVar10[4] = (char *)0x6e756f66;
        ppcVar10[5] = (char *)0x68742064;
        ppcVar10[6] = (char *)0x63207461;
        ppcVar10[7] = (char *)0x646c756f;
        ppcVar10[8] = (char *)0x20656220;
        ppcVar10[9] = (char *)0x64657375;
        ppcVar10[10] = (char *)0x206f7420;
        ppcVar10[0xb] = (char *)0x20746567;
        ppcVar10[0xc] = (char *)0x6b726f77;
        ppcVar10[0xd] = (char *)0x6f726620;
        *(undefined2 *)(ppcVar10 + 0xe) = 0x2e6d;
        *(undefined1 *)((int)ppcVar10 + 0x3a) = 0;
        _applog(3,(char *)ppcVar10,false);
        if ((*(char *)&ptVar27->id == '\0') && (*(_Bool *)pbVar19 == false)) goto LAB_0000cf8a;
LAB_0000cf90:
        memcpy(ppcVar10,"Please check the details from the list below of the servers you have input"
               ,0x4b);
        _applog(3,(char *)ppcVar10,false);
        if ((*(char *)&ptVar27->id == '\0') && (*(_Bool *)pbVar19 == false)) goto LAB_0000cfb2;
LAB_0000cfb8:
        memcpy(ppcVar10,
               "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers"
               ,0x5e);
        _applog(3,(char *)ppcVar10,false);
      }
      for (iVar54 = 0; iVar54 < total_pools; iVar54 = iVar54 + 1) {
        ppVar21 = (*ppppStack_9d4)[iVar54];
        if (((*(char *)&ptVar27->id != '\0') || (*(_Bool *)pbVar19 != false)) || (3 < opt_log_level)
           ) {
          local_9e8 = ptVar27;
          snprintf((char *)ppcVar10,0x800,"Pool: %d  URL: %s  User: %s  Password: %s",iVar54,
                   ppVar21->rpc_url,ppVar21->rpc_user,ppVar21->rpc_pass);
          _applog(4,(char *)ppcVar10,false);
          ptVar27 = local_9e8;
        }
      }
      if (use_curses == false) goto LAB_0000c7ae;
      if (((*(char *)&ptVar27->id == '\0') && (*(_Bool *)pbVar19 == false)) && (opt_log_level < 3))
      {
        bVar65 = true;
        goto LAB_0000c78e;
      }
      local_9e4 = &use_curses;
      memcpy(ppcVar10,"Press any key to exit, or cgminer will wait indefinitely for an alive pool.",
             0x4c);
      _applog(3,(char *)ppcVar10,false);
      bVar65 = true;
      puVar38 = local_9e4;
    }
    if (*puVar38 == '\0') {
LAB_0000c7ae:
      *local_9c4 = (char *)0x73206f4e;
      local_9c4[1] = (char *)0x65767265;
      local_9c4[2] = (char *)0x63207372;
      local_9c4[3] = (char *)0x646c756f;
      local_9c4[4] = (char *)0x20656220;
      local_9c4[5] = (char *)0x64657375;
      local_9c4[6] = (char *)0x78452021;
      local_9c4[7] = (char *)0x6e697469;
      *(undefined2 *)(local_9c4 + 8) = 0x2e67;
      *(undefined1 *)((int)local_9c4 + 0x22) = 0;
      _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
      __quit(0,false);
    }
  } while( true );
LAB_0000c9b0:
  pppVar31 = pppVar31 + 1;
  if ((*pppVar31)->quota_used < (*pppVar31)->quota_gcd) goto LAB_0000c9e4;
  goto LAB_0000c9bc;
LAB_0000cacc:
  pppVar31 = pppVar31 + 1;
  if ((*pppVar31)->quota_used < (*pppVar31)->quota_gcd) goto LAB_0000cb00;
  goto LAB_0000cad8;
}

