
/* WARNING: Removing unreachable block (ram,0x00060506) */
/* WARNING: Removing unreachable block (ram,0x00060520) */
/* WARNING: Removing unreachable block (ram,0x0006052e) */
/* WARNING: Removing unreachable block (ram,0x0006053c) */
/* WARNING: Removing unreachable block (ram,0x0006054a) */
/* WARNING: Removing unreachable block (ram,0x00060574) */
/* WARNING: Removing unreachable block (ram,0x0006059a) */
/* WARNING: Removing unreachable block (ram,0x000605b4) */
/* WARNING: Removing unreachable block (ram,0x000605c2) */
/* WARNING: Removing unreachable block (ram,0x000605d0) */
/* WARNING: Removing unreachable block (ram,0x000605de) */
/* WARNING: Removing unreachable block (ram,0x00060608) */

int main(int argc,char **argv)

{
  bool bVar1;
  _Bool _Var2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  char *__src;
  size_t sVar6;
  block *__s;
  UT_hash_table *pUVar7;
  UT_hash_bucket *pUVar8;
  pool *ppVar9;
  FILE *pFVar10;
  size_t sVar11;
  thr_info **pptVar12;
  thr_info *ptVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  UT_hash_handle *pUVar18;
  UT_hash_bucket *pUVar19;
  uint32_t size;
  cgpu_info *pcVar20;
  char **ppcVar21;
  undefined4 uVar22;
  char *pcVar23;
  char acStack_2a80 [4104];
  char acStack_1a78 [4088];
  char *local_a80;
  char **argv_local;
  int argc_local;
  char tmp [256];
  char tmp42 [2048];
  sysinfo sInfo;
  work *work;
  sigaction handler;
  size_t siz;
  pool *pool_1;
  cgpu_info *cgpu_1;
  cgpu_info *cgpu_2;
  pool *pool_4;
  int max_staged;
  thr_info *thr;
  pool *pool_2;
  pool *pool_3;
  cgpu_info *cgpu;
  char *start;
  int len;
  FILE *fpversion;
  pool *pool;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  block *block;
  char *s;
  int ts;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _ha_hashv;
  uint k;
  int slept;
  int j;
  int i;
  _Bool pool_msg;
  
  work = (work *)0x0;
  bVar1 = false;
  slept = 0;
  g_logfile_enable = false;
  argv_local = argv;
  argc_local = argc;
  _Var2 = is_cgminer_already_started();
  if (_Var2) {
    puts("cgminer is forbidden to start again as it is already started,will exit immediately.");
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  builtin_strncpy(g_logfile_path,"bmminer.log",0xc);
  g_logfile_openflag[0] = 'a';
  g_logfile_openflag[1] = '+';
  g_logfile_openflag[2] = '\0';
  lVar3 = sysconf(0x54);
  if (lVar3 == 1) {
    selective_yield = sched_yield;
  }
  initial_args = (char **)_cgmalloc((argc_local + 1) * 4,"cgminer.c","main",0x2d33);
  for (i = 0; i < argc_local; i = i + 1) {
    ppcVar21 = initial_args + i;
    pcVar23 = strdup(argv_local[i]);
    *ppcVar21 = pcVar23;
  }
  initial_args[argc_local] = (char *)0x0;
  _mutex_init(&hash_lock,"cgminer.c","main",0x2d3c);
  _mutex_init(&update_job_lock,"cgminer.c","main",0x2d3d);
  _mutex_init(&console_lock,"cgminer.c","main",0x2d3e);
  _cglock_init(&control_lock,"cgminer.c","main",0x2d3f);
  _mutex_init(&stats_lock,"cgminer.c","main",0x2d40);
  _mutex_init(&sharelog_lock,"cgminer.c","main",0x2d41);
  _cglock_init(&ch_lock,"cgminer.c","main",0x2d42);
  _mutex_init(&sshare_lock,"cgminer.c","main",0x2d43);
  _rwlock_init(&blk_lock,"cgminer.c","main",0x2d44);
  _rwlock_init(&netacc_lock,"cgminer.c","main",0x2d45);
  _rwlock_init(&mining_thr_lock,"cgminer.c","main",0x2d46);
  _rwlock_init(&devices_lock,"cgminer.c","main",0x2d47);
  _mutex_init(&lp_lock,"cgminer.c","main",0x2d49);
  iVar4 = pthread_cond_init((pthread_cond_t *)&lp_cond,(pthread_condattr_t *)0x0);
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init lp_cond",0x24);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  _mutex_init(&restart_lock,"cgminer.c","main",0x2d50);
  iVar4 = pthread_cond_init((pthread_cond_t *)&restart_cond,(pthread_condattr_t *)0x0);
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init restart_cond",0x28);
    tmp42._40_4_ = tmp42._40_4_ & 0xffffff00;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  iVar4 = pthread_cond_init((pthread_cond_t *)&gws_cond,(pthread_condattr_t *)0x0);
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init gws_cond",0x24);
    tmp42._36_4_ = tmp42._36_4_ & 0xffffff00;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  getq = tq_new();
  uVar22 = tmp42._20_4_;
  if (getq == (thread_q *)0x0) {
    builtin_strncpy(tmp42,"Failed to create getq",0x16);
    tmp42._22_2_ = SUB42(uVar22,2);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  stgd_lock = &getq->mutex;
  local_a80 = "2.0.0";
  snprintf(packagename,0x100,"%s %s","cgminer");
  handler.sa_flags = 0;
  handler.__sigaction_handler = (anon_union_4_2_5ad2d23e_for___sigaction_handler)(code *)0x4ccd3;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  opt_kernel_path = acStack_1a78;
  builtin_strncpy(acStack_1a78,"/usr/bin",9);
  cgminer_path = acStack_2a80;
  pcVar5 = strdup(*argv_local);
  pcVar23 = cgminer_path;
  __src = dirname(pcVar5);
  strcpy(pcVar23,__src);
  free(pcVar5);
  pcVar23 = cgminer_path;
  sVar6 = strlen(cgminer_path);
  (pcVar23 + sVar6)[0] = '/';
  (pcVar23 + sVar6)[1] = '\0';
  devcursor = 8;
  logstart = 9;
  logcursor = 10;
  pcVar23 = (char *)0x2d7f;
  __s = (block *)_cgcalloc(0x68,1,"cgminer.c","main",0x2d7f);
  for (i = 0; i < 0x24; i = i + 1) {
    sVar6 = strlen((char *)__s);
    (__s->hash + sVar6)[0] = '0';
    (__s->hash + sVar6)[1] = '\0';
  }
  _ha_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  _hj_k = strlen((char *)__s);
  _hj_key = (uchar *)__s;
  for (; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar4 = (uint)_hj_key[7] * 0x1000000 +
            (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 + _hj_j;
    uVar15 = (uint)_hj_key[0xb] * 0x1000000 +
             (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 + _ha_hashv;
    uVar16 = uVar15 >> 0xd ^
             (((uint)_hj_key[3] * 0x1000000 +
               (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 + _hj_i) -
             iVar4) - uVar15;
    uVar17 = uVar16 << 8 ^ (iVar4 - uVar15) - uVar16;
    uVar15 = uVar17 >> 0xd ^ (uVar15 - uVar16) - uVar17;
    uVar16 = uVar15 >> 0xc ^ (uVar16 - uVar17) - uVar15;
    uVar17 = uVar16 << 0x10 ^ (uVar17 - uVar15) - uVar16;
    uVar15 = uVar17 >> 5 ^ (uVar15 - uVar16) - uVar17;
    _hj_i = uVar15 >> 3 ^ (uVar16 - uVar17) - uVar15;
    _hj_j = _hj_i << 10 ^ (uVar17 - uVar15) - _hj_i;
    _ha_hashv = _hj_j >> 0xf ^ (uVar15 - _hj_i) - _hj_j;
    _hj_key = _hj_key + 0xc;
  }
  sVar6 = strlen((char *)__s);
  _ha_hashv = _ha_hashv + sVar6;
  switch(_hj_k) {
  case 0xb:
    _ha_hashv = (uint)_hj_key[10] * 0x1000000 + _ha_hashv;
  case 10:
    _ha_hashv = (uint)_hj_key[9] * 0x10000 + _ha_hashv;
  case 9:
    _ha_hashv = (uint)_hj_key[8] * 0x100 + _ha_hashv;
  case 8:
    _hj_j = (uint)_hj_key[7] * 0x1000000 + _hj_j;
  case 7:
    _hj_j = (uint)_hj_key[6] * 0x10000 + _hj_j;
  case 6:
    _hj_j = (uint)_hj_key[5] * 0x100 + _hj_j;
  case 5:
    _hj_j = _hj_j + _hj_key[4];
  case 4:
    _hj_i = (uint)_hj_key[3] * 0x1000000 + _hj_i;
  case 3:
    _hj_i = (uint)_hj_key[2] * 0x10000 + _hj_i;
  case 2:
    _hj_i = (uint)_hj_key[1] * 0x100 + _hj_i;
  case 1:
    _hj_i = _hj_i + *_hj_key;
  }
  uVar15 = _ha_hashv >> 0xd ^ (_hj_i - _hj_j) - _ha_hashv;
  uVar16 = uVar15 << 8 ^ (_hj_j - _ha_hashv) - uVar15;
  uVar17 = uVar16 >> 0xd ^ (_ha_hashv - uVar15) - uVar16;
  uVar15 = uVar17 >> 0xc ^ (uVar15 - uVar16) - uVar17;
  uVar16 = uVar15 << 0x10 ^ (uVar16 - uVar17) - uVar15;
  uVar17 = uVar16 >> 5 ^ (uVar17 - uVar15) - uVar16;
  uVar15 = uVar17 >> 3 ^ (uVar15 - uVar16) - uVar17;
  uVar16 = uVar15 << 10 ^ (uVar16 - uVar17) - uVar15;
  uVar15 = uVar16 >> 0xf ^ (uVar17 - uVar15) - uVar16;
  (__s->hh).hashv = uVar15;
  (__s->hh).key = __s;
  sVar6 = strlen((char *)__s);
  (__s->hh).keylen = sVar6;
  if (blocks == (block *)0x0) {
    (__s->hh).next = (void *)0x0;
    (__s->hh).prev = (void *)0x0;
    blocks = __s;
    pUVar7 = (UT_hash_table *)malloc(0x2c);
    (__s->hh).tbl = pUVar7;
    if ((blocks->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset((blocks->hh).tbl,0,0x2c);
    ((blocks->hh).tbl)->tail = &blocks->hh;
    ((blocks->hh).tbl)->num_buckets = 0x20;
    ((blocks->hh).tbl)->log2_num_buckets = 5;
    ((blocks->hh).tbl)->hho = 0x44;
    pUVar7 = (blocks->hh).tbl;
    pUVar8 = (UT_hash_bucket *)malloc(0x180);
    pUVar7->buckets = pUVar8;
    if (((blocks->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(((blocks->hh).tbl)->buckets,0,0x180);
    ((blocks->hh).tbl)->signature = 0xa0111fe1;
  }
  else {
    (__s->hh).tbl = (blocks->hh).tbl;
    (__s->hh).next = (void *)0x0;
    (__s->hh).prev = (void *)((int)((blocks->hh).tbl)->tail - ((blocks->hh).tbl)->hho);
    ((blocks->hh).tbl)->tail->next = __s;
    ((blocks->hh).tbl)->tail = &__s->hh;
  }
  pUVar7 = (blocks->hh).tbl;
  pUVar7->num_items = pUVar7->num_items + 1;
  uVar15 = ((blocks->hh).tbl)->num_buckets - 1 & uVar15;
  pUVar8 = ((blocks->hh).tbl)->buckets;
  pUVar8[uVar15].count = pUVar8[uVar15].count + 1;
  (__s->hh).hh_next = ((blocks->hh).tbl)->buckets[uVar15].hh_head;
  (__s->hh).hh_prev = (UT_hash_handle *)0x0;
  if (((blocks->hh).tbl)->buckets[uVar15].hh_head != (UT_hash_handle *)0x0) {
    (((blocks->hh).tbl)->buckets[uVar15].hh_head)->hh_prev = &__s->hh;
  }
  ((blocks->hh).tbl)->buckets[uVar15].hh_head = &__s->hh;
  if (((((blocks->hh).tbl)->buckets[uVar15].expand_mult + 1) * 10 <=
       ((blocks->hh).tbl)->buckets[uVar15].count) && (((__s->hh).tbl)->noexpand != 1)) {
    pUVar8 = (UT_hash_bucket *)malloc(((__s->hh).tbl)->num_buckets * 0x18);
    if (pUVar8 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar8,0,((__s->hh).tbl)->num_buckets * 0x18);
    ((__s->hh).tbl)->ideal_chain_maxlen =
         (((__s->hh).tbl)->num_items >> (((__s->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
         (uint)((((__s->hh).tbl)->num_buckets * 2 - 1 & ((__s->hh).tbl)->num_items) != 0);
    ((__s->hh).tbl)->nonideal_items = 0;
    for (_he_bkt_i = 0; _he_bkt_i < ((__s->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
      _he_thh = ((__s->hh).tbl)->buckets[_he_bkt_i].hh_head;
      while (_he_thh != (UT_hash_handle *)0x0) {
        pUVar18 = _he_thh->hh_next;
        pUVar19 = pUVar8 + (((__s->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
        pUVar19->count = pUVar19->count + 1;
        if (((__s->hh).tbl)->ideal_chain_maxlen < pUVar19->count) {
          pUVar7 = (__s->hh).tbl;
          pUVar7->nonideal_items = pUVar7->nonideal_items + 1;
          uVar15 = __udivsi3(pUVar19->count,((__s->hh).tbl)->ideal_chain_maxlen);
          pUVar19->expand_mult = uVar15;
        }
        _he_thh->hh_prev = (UT_hash_handle *)0x0;
        _he_thh->hh_next = pUVar19->hh_head;
        if (pUVar19->hh_head != (UT_hash_handle *)0x0) {
          pUVar19->hh_head->hh_prev = _he_thh;
        }
        pUVar19->hh_head = _he_thh;
        _he_thh = pUVar18;
      }
    }
    free(((__s->hh).tbl)->buckets);
    ((__s->hh).tbl)->num_buckets = ((__s->hh).tbl)->num_buckets << 1;
    pUVar7 = (__s->hh).tbl;
    pUVar7->log2_num_buckets = pUVar7->log2_num_buckets + 1;
    ((__s->hh).tbl)->buckets = pUVar8;
    if (((__s->hh).tbl)->num_items >> 1 < ((__s->hh).tbl)->nonideal_items) {
      uVar15 = ((__s->hh).tbl)->ineff_expands + 1;
    }
    else {
      uVar15 = 0;
    }
    ((__s->hh).tbl)->ineff_expands = uVar15;
    if (1 < ((__s->hh).tbl)->ineff_expands) {
      ((__s->hh).tbl)->noexpand = 1;
    }
  }
  strcpy(current_hash,(char *)__s);
  scan_devices.next = &scan_devices;
  scan_devices.prev = &scan_devices;
  opt_register_table(opt_config_table,"Options for both config file and command line");
  opt_register_table(opt_cmdline_table,"Options for command line only");
  opt_parse(&argc_local,argv_local,(_func_void_char_ptr_varargs *)0x484e9);
  uVar22 = tmp42._36_4_;
  if (argc_local != 1) {
    builtin_strncpy(tmp42,"Unexpected extra commandline arguments",0x27);
    tmp42[0x27] = SUB41(uVar22,3);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  if (config_loaded != true) {
    load_default_config();
  }
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
    ppVar9 = add_pool();
    pcVar5 = (char *)_cgmalloc(0xff,"cgminer.c","main",0x2da3);
    ppVar9->rpc_url = pcVar5;
    if (opt_benchfile == (char *)0x0) {
      builtin_strncpy(ppVar9->rpc_url,"Benchmark",10);
    }
    else {
      builtin_strncpy(ppVar9->rpc_url,"Benchfile",10);
    }
    ppVar9->rpc_user = ppVar9->rpc_url;
    ppVar9->rpc_pass = ppVar9->rpc_url;
    ppVar9->rpc_userpass = ppVar9->rpc_url;
    ppVar9->sockaddr_url = ppVar9->rpc_url;
    strncpy(ppVar9->diff,"?",7);
    ppVar9->diff[7] = '\0';
    enable_pool(ppVar9);
    ppVar9->idle = false;
    successful_connect = true;
    for (i = 0; i < 0x10; i = i + 1) {
      hex2bin(bench_hidiff_bins[i],bench_hidiffs[i],0xa0);
      hex2bin(bench_lodiff_bins[i],bench_lodiffs[i],0xa0);
    }
    set_target(bench_target,32.0);
  }
  if (opt_version_path != (char *)0x0) {
    pFVar10 = fopen(opt_version_path,"rb");
    memset(tmp,0,0x100);
    if (pFVar10 == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Open miner version file %s error",opt_version_path);
        _applog(3,tmp42,false);
      }
    }
    else {
      pcVar5 = (char *)fread(tmp,1,0x100,pFVar10);
      if ((int)pcVar5 < 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"Read miner version file %s error %d",opt_version_path,pcVar5);
          _applog(3,tmp42,false);
          pcVar23 = pcVar5;
        }
      }
      else {
        pcVar5 = strchr(tmp,10);
        if (pcVar5 == (char *)0x0) {
          strcpy(g_miner_compiletime,tmp);
        }
        else {
          pcVar23 = "main";
          _cg_memcpy(g_miner_compiletime,tmp,(int)pcVar5 - (int)tmp,"cgminer.c","main",0x2dde);
          strcpy(tmp,pcVar5 + 1);
          pcVar5 = strchr(tmp,10);
          if (pcVar5 == (char *)0x0) {
            strcpy(g_miner_type,tmp);
          }
          else {
            pcVar23 = "main";
            _cg_memcpy(g_miner_type,tmp,(int)pcVar5 - (int)tmp,"cgminer.c","main",0x2de7);
          }
        }
        sVar6 = strlen(g_miner_compiletime);
        if (g_miner_version[sVar6 + 0xff] == '\n') {
          sVar6 = strlen(g_miner_compiletime);
          g_miner_version[sVar6 + 0xff] = '\0';
        }
        sVar6 = strlen(g_miner_compiletime);
        if (g_miner_version[sVar6 + 0xff] == '\r') {
          sVar6 = strlen(g_miner_compiletime);
          g_miner_version[sVar6 + 0xff] = '\0';
        }
        sVar6 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar6 + 0xff] == '\n') {
          sVar6 = strlen(g_miner_type);
          g_miner_compiletime[sVar6 + 0xff] = '\0';
        }
        sVar6 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar6 + 0xff] == '\r') {
          sVar6 = strlen(g_miner_type);
          g_miner_compiletime[sVar6 + 0xff] = '\0';
        }
      }
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      pcVar23 = g_miner_type;
      snprintf(tmp42,0x800,"Miner compile time: %s type: %s",g_miner_compiletime,g_miner_type);
      _applog(3,tmp42,false);
    }
  }
  if (opt_logfile_path != (char *)0x0) {
    g_logfile_enable = true;
    strcpy(g_logfile_path,opt_logfile_path);
    if (opt_logfile_openflag != (char *)0x0) {
      strcpy(g_logfile_openflag,opt_logfile_openflag);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      pcVar23 = g_logfile_openflag;
      snprintf(tmp42,0x800,"Log file path: %s Open flag: %s",g_logfile_path,g_logfile_openflag);
      _applog(3,tmp42,false);
    }
  }
  if (opt_logwork_path != (char *)0x0) {
    memset(tmp,0,0x100);
    if (opt_logwork_asicnum == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Log work path: %s",opt_logwork_path,pcVar23);
        _applog(3,tmp42,false);
      }
    }
    else {
      if (*opt_logwork_asicnum == '\0') {
        builtin_strncpy(tmp42,"Log work asic num empty",0x18);
        _applog(3,tmp42,true);
        _quit(1);
      }
      g_logwork_asicnum = atoi(opt_logwork_asicnum);
      if (((g_logwork_asicnum != 1) && (g_logwork_asicnum != 0x20)) && (g_logwork_asicnum != 0x40))
      {
        builtin_strncpy(tmp42,"Log work asic num must be 1, 32, 64",0x24);
        _applog(3,tmp42,true);
        _quit(1);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar23 = opt_logwork_asicnum;
        snprintf(tmp42,0x800,"Log work path: %s Asic num: %s",opt_logwork_path,opt_logwork_asicnum);
        _applog(3,tmp42,false);
      }
    }
    sprintf(tmp,"%s.txt",opt_logwork_path);
    g_logwork_file = (FILE *)fopen(tmp,"a+");
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Log work open file %s",tmp);
      _applog(3,tmp42,false);
    }
    if (g_logwork_asicnum == 1) {
      sprintf(tmp,"%s%02d.txt",opt_logwork_path,1);
      g_logwork_files[0] = (FILE *)fopen(tmp,"a+");
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar23 = tmp;
        snprintf(tmp42,0x800,"Log work open asic %d file %s",g_logwork_asicnum,pcVar23);
        _applog(3,tmp42,false);
      }
    }
    else if ((g_logwork_asicnum == 0x20) || (g_logwork_asicnum == 0x40)) {
      for (i = 0; i <= g_logwork_asicnum; i = i + 1) {
        pcVar23 = (char *)i;
        sprintf(tmp,"%s%02d_%02d.txt",opt_logwork_path,g_logwork_asicnum,i);
        pFVar10 = fopen(tmp,"a+");
        g_logwork_files[i] = (FILE *)pFVar10;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          pcVar23 = tmp;
          snprintf(tmp42,0x800,"Log work open asic %d file %s",g_logwork_asicnum,pcVar23);
          _applog(3,tmp42,false);
        }
      }
    }
    if (opt_logwork_diff != false) {
      for (i = 0; i < 0x41; i = i + 1) {
        sprintf(tmp,"%s_diff_%02d.txt",opt_logwork_path,i);
        pFVar10 = fopen(tmp,"a+");
        g_logwork_diffs[i] = (FILE *)pFVar10;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"Log work open diff file %s",tmp);
          _applog(3,tmp42,false);
        }
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Started %s",packagename,pcVar23);
    _applog(4,tmp42,false);
  }
  if (cnfbuf != (char *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Loaded configuration file %s",cnfbuf);
      _applog(5,tmp42,false);
    }
    uVar22 = tmp42._44_4_;
    if (fileconf_load == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        builtin_strncpy(tmp42,"Error in configuration file, partially loaded.",0x2f);
        tmp42[0x2f] = SUB41(uVar22,3);
        _applog(4,tmp42,false);
      }
      uVar22 = tmp42._48_4_;
      if ((use_curses != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Start cgminer with -T to see what failed to load.",0x32);
        tmp42._50_2_ = SUB42(uVar22,2);
        _applog(4,tmp42,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        builtin_strncpy(tmp42,"Fatal JSON error in configuration file.",0x28);
        _applog(4,tmp42,false);
      }
      uVar22 = tmp42._36_4_;
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        builtin_strncpy(tmp42,"Configuration file could not be used.",0x26);
        tmp42._38_2_ = SUB42(uVar22,2);
        _applog(4,tmp42,false);
      }
    }
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar23 = opt_kernel_path;
  sVar6 = strlen(opt_kernel_path);
  (pcVar23 + sVar6)[0] = '/';
  (pcVar23 + sVar6)[1] = '\0';
  if (want_per_device_stats != false) {
    opt_log_output = true;
  }
  if (opt_log_output == false) {
    setlogmask(0x3f);
  }
  else {
    setlogmask(0xff);
  }
  if (opt_scantime < 0) {
    opt_scantime = 0x3c;
  }
  total_control_threads = 8;
  pcVar23 = (char *)0x2e83;
  control_thr = (thr_info *)_cgcalloc(8,0x40,"cgminer.c","main",0x2e83);
  gwsched_thr_id = 0;
  fill_device_drv(&bitforce_drv);
  fill_device_drv(&modminer_drv);
  fill_device_drv(&bitmain_drv);
  fill_device_drv(&bitmain_soc_drv);
  (*bitforce_drv.drv_detect)(false);
  (*modminer_drv.drv_detect)(false);
  (*bitmain_drv.drv_detect)(false);
  (*bitmain_soc_drv.drv_detect)(false);
  if (opt_display_devs != false) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"Devices detected",0x10);
      tmp42[0x10] = ':';
      tmp42[0x11] = '\0';
      _applog(3,tmp42,false);
    }
    for (i = 0; i < total_devices; i = i + 1) {
      pcVar20 = devices[i];
      if (pcVar20->name == (char *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          pcVar23 = pcVar20->drv->name;
          snprintf(tmp42,0x800," %2d. %s %d (driver: %s)",i,pcVar23,pcVar20->device_id,
                   pcVar20->drv->dname);
          _applog(3,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar23 = pcVar20->drv->name;
        snprintf(tmp42,0x800," %2d. %s %d: %s (driver: %s)",i,pcVar23,pcVar20->device_id,
                 pcVar20->name,pcVar20->drv->dname);
        _applog(3,tmp42,false);
      }
    }
    snprintf(tmp42,0x800,"%d devices listed",total_devices,pcVar23);
    _applog(3,tmp42,true);
    __quit(0,false);
  }
  mining_threads = 0;
  for (i = 0; uVar22 = tmp42._32_4_, i < total_devices; i = i + 1) {
    enable_device(devices[i]);
  }
  if (total_devices == 0) {
    builtin_strncpy(tmp42,"All devices disabled, cannot mint!",0x23);
    tmp42[0x23] = SUB41(uVar22,3);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  most_devices = total_devices;
  load_temp_cutoffs();
  uVar22 = tmp42._40_4_;
  for (i = 0; i < total_devices; i = i + 1) {
    (devices[i]->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
  }
  if (opt_compact != true) {
    logstart = logstart + most_devices;
    logcursor = logstart + 1;
  }
  if (total_pools == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      builtin_strncpy(tmp42,"Need to specify at least one pool server.",0x2a);
      tmp42._42_2_ = SUB42(uVar22,2);
      _applog(4,tmp42,false);
    }
    builtin_strncpy(tmp42,"Pool setup faile",0x10);
    tmp42[0x10] = 'd';
    tmp42[0x11] = '\0';
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar9 = pools[i];
    (ppVar9->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
    (ppVar9->cgminer_pool_stats).getwork_wait_min.tv_sec = 99999999;
    if (ppVar9->rpc_userpass == (char *)0x0) {
      if (ppVar9->rpc_pass == (char *)0x0) {
        pcVar23 = strdup("");
        ppVar9->rpc_pass = pcVar23;
      }
      if (ppVar9->rpc_user == (char *)0x0) {
        snprintf(tmp42,0x800,"No login credentials supplied for pool %u %s",i,ppVar9->rpc_url);
        _applog(3,tmp42,true);
        __quit(1,false);
      }
      sVar6 = strlen(ppVar9->rpc_user);
      sVar11 = strlen(ppVar9->rpc_pass);
      size = sVar11 + sVar6 + 2;
      pcVar23 = (char *)_cgmalloc(size,"cgminer.c","main",0x2ef0);
      ppVar9->rpc_userpass = pcVar23;
      snprintf(ppVar9->rpc_userpass,size,"%s:%s",ppVar9->rpc_user,ppVar9->rpc_pass);
    }
  }
  currentpool = *pools;
  if (use_syslog != false) {
    openlog("cgminer",1,8);
  }
  if (opt_stderr_cmd != (char *)0x0) {
    fork_monitor();
  }
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,"cgminer.c","main",0x2f01);
  for (i = 0; i < mining_threads; i = i + 1) {
    pptVar12 = mining_thr + i;
    ptVar13 = (thr_info *)_cgcalloc(1,0x40,"cgminer.c","main",0x2f05);
    *pptVar12 = ptVar13;
  }
  k = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar20 = devices[i];
    pptVar12 = (thr_info **)_cgmalloc((pcVar20->threads + 1) * 4,"cgminer.c","main",0x2f0e);
    pcVar20->thr = pptVar12;
    pcVar20->thr[pcVar20->threads] = (thr_info *)0x0;
    pcVar20->status = LIFE_INIT;
    for (j = 0; j < pcVar20->threads; j = j + 1) {
      ptVar13 = get_thread(k);
      ptVar13->id = k;
      ptVar13->cgpu = pcVar20;
      ptVar13->device_thread = j;
      _Var2 = (*pcVar20->drv->thread_prepare)(ptVar13);
      if (_Var2) {
        iVar4 = thr_info_create(ptVar13,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x5948f,
                                ptVar13);
        if (iVar4 != 0) {
          snprintf(tmp42,0x800,"thread %d create failed",ptVar13->id);
          _applog(3,tmp42,true);
          __quit(1,false);
        }
        pcVar20->thr[j] = ptVar13;
        if (pcVar20->deven != DEV_DISABLED) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Pushing sem post to thread %d",ptVar13->id);
            _applog(7,tmp42,false);
          }
          _cgsem_post(&ptVar13->sem,"cgminer.c","main",0x2f2a);
        }
      }
      k = k + 1;
    }
  }
  if ((opt_benchmark == false) && (opt_benchfile == (char *)0x0)) {
    for (i = 0; uVar22 = tmp42._24_4_, i < total_pools; i = i + 1) {
      ppVar9 = pools[i];
      enable_pool(ppVar9);
      ppVar9->idle = true;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"Probing for an alive pool",0x1a);
      tmp42._26_2_ = SUB42(uVar22,2);
      _applog(5,tmp42,false);
    }
    probe_pools();
    do {
      sleep(1);
      slept = slept + 1;
      if (pools_active == true) break;
    } while (slept < 0xb4);
    do {
      uVar22 = tmp42._56_4_;
      if (pools_active == true) goto LAB_0005fe58;
      if (!bVar1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"No servers were found that could be used to get work from.",0x3b);
          tmp42[0x3b] = SUB41(uVar22,3);
          _applog(3,tmp42,false);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          memcpy(tmp42,"Please check the details from the list below of the servers you have input",
                 0x4b);
          _applog(3,tmp42,false);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          memcpy(tmp42,
                 "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers"
                 ,0x5e);
          _applog(3,tmp42,false);
        }
        for (i = 0; i < total_pools; i = i + 1) {
          ppVar9 = pools[i];
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool: %d  URL: %s  User: %s  Password: %s",i,ppVar9->rpc_url,
                     ppVar9->rpc_user,ppVar9->rpc_pass);
            _applog(4,tmp42,false);
          }
        }
        bVar1 = true;
        if ((use_curses != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
          memcpy(tmp42,"Press any key to exit, or cgminer will wait indefinitely for an alive pool."
                 ,0x4c);
          _applog(3,tmp42,false);
        }
      }
    } while (use_curses == true);
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"no valid pool enabled, keep running to provide 4028 service.",0x3c);
      tmp42[0x3c] = '\0';
      _applog(3,tmp42,false);
    }
  }
LAB_0005fe58:
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  for (i = 0; i < 0xc; i = i + 1) {
    *(undefined4 *)(g_local_mhashes_dones + i) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + i * 8 + 4) = 0;
  }
  g_local_mhashes_index = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar20 = devices[i];
    *(undefined4 *)&pcVar20->total_mhashes = 0;
    *(undefined4 *)((int)&pcVar20->total_mhashes + 4) = 0;
    uVar22 = *(undefined4 *)((int)&pcVar20->total_mhashes + 4);
    *(undefined4 *)&pcVar20->rolling = *(undefined4 *)&pcVar20->total_mhashes;
    *(undefined4 *)((int)&pcVar20->rolling + 4) = uVar22;
  }
  iVar4 = sysinfo((sysinfo *)&sInfo);
  if (iVar4 == 0) {
    total_tv_end_sys = sInfo.uptime;
    total_tv_start_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar14 = __errno_location();
      iVar4 = *piVar14;
      piVar14 = __errno_location();
      pcVar23 = strerror(*piVar14);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar4,pcVar23);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_start);
  cgtime(&total_tv_end);
  cgtime(&tv_hashmeter);
  get_datestamp(datestamp,0x28,&total_tv_start);
  ptVar13 = control_thr;
  watchpool_thr_id = 2;
  iVar4 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x59bc1,
                          (void *)0x0);
  uVar22 = tmp42._28_4_;
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"watchpool thread create failed",0x1f);
    tmp42[0x1f] = SUB41(uVar22,3);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar13[2].pth);
  ptVar13 = control_thr;
  watchdog_thr_id = 3;
  iVar4 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x59eb1,
                          (void *)0x0);
  uVar22 = tmp42._28_4_;
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"watchdog thread create failed",0x1e);
    tmp42._30_2_ = SUB42(uVar22,2);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar13[3].pth);
  api_thr_id = 5;
  iVar4 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x51e45,
                          control_thr + 5);
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"API thread create failed",0x18);
    tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  if (total_control_threads != 8) {
    snprintf(tmp42,0x800,"incorrect total_control_threads (%d) should be 8",total_control_threads);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  set_highprio();
  do {
    iVar4 = max_queue;
    if (opt_work_update != false) {
      signal_work_update();
    }
    opt_work_update = false;
    _mutex_lock(stgd_lock,"cgminer.c","main",0x2fdf);
    ts = __total_staged();
    if (iVar4 < ts) {
      work_filled = true;
      pthread_cond_wait((pthread_cond_t *)&gws_cond,(pthread_mutex_t *)stgd_lock);
      ts = __total_staged();
    }
    _mutex_unlock(stgd_lock,"cgminer.c","main",0x2fea);
    if (iVar4 < ts) {
      work_filled = true;
      work = hash_pop(false);
      if (work != (work *)0x0) {
        _discard_work(&work,"cgminer.c","main",0x2ff6);
      }
    }
    else {
      if (work != (work *)0x0) {
        _discard_work(&work,"cgminer.c","main",0x2ffe);
      }
      work = make_work();
      while( true ) {
        ppVar9 = select_pool();
        _Var2 = pool_unusable(ppVar9);
        if (!_Var2) break;
        switch_pools((pool *)0x0);
        ppVar9 = select_pool();
        _Var2 = pool_unusable(ppVar9);
        if (_Var2) {
          cgsleep_ms(0xb);
        }
      }
      if (ppVar9->has_stratum == false) {
        if (opt_benchfile == (char *)0x0) {
          if (opt_benchmark != false) {
            get_benchmark_work(work);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              builtin_strncpy(tmp42,"Generated benchmark work",0x18);
              tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
              _applog(7,tmp42,false);
            }
            _stage_work(work);
            work = (work *)0x0;
          }
        }
        else {
          get_benchfile_work(work);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Generated benchfile work",0x18);
            tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
            _applog(7,tmp42,false);
          }
          _stage_work(work);
          work = (work *)0x0;
        }
      }
      else {
        gen_stratum_work(ppVar9,work);
        uVar22 = tmp42._20_4_;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Generated stratum work",0x17);
          tmp42[0x17] = SUB41(uVar22,3);
          _applog(7,tmp42,false);
        }
        _stage_work(work);
        work = (work *)0x0;
      }
    }
  } while( true );
}

