
/* WARNING: Removing unreachable block (ram,0x00068578) */
/* WARNING: Removing unreachable block (ram,0x00068598) */
/* WARNING: Removing unreachable block (ram,0x000685ac) */
/* WARNING: Removing unreachable block (ram,0x000685c0) */
/* WARNING: Removing unreachable block (ram,0x000685d4) */
/* WARNING: Removing unreachable block (ram,0x00068620) */
/* WARNING: Removing unreachable block (ram,0x0006864c) */
/* WARNING: Removing unreachable block (ram,0x0006866c) */
/* WARNING: Removing unreachable block (ram,0x00068680) */
/* WARNING: Removing unreachable block (ram,0x00068694) */
/* WARNING: Removing unreachable block (ram,0x000686a8) */
/* WARNING: Removing unreachable block (ram,0x000686f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int main(int argc,char **argv)

{
  bool bVar1;
  undefined4 uVar2;
  _Bool _Var3;
  long lVar4;
  int iVar5;
  char *pcVar6;
  char *__src;
  size_t sVar7;
  block *__s;
  UT_hash_table *pUVar8;
  UT_hash_bucket *pUVar9;
  pool *ppVar10;
  FILE *pFVar11;
  size_t sVar12;
  thr_info **pptVar13;
  thr_info *ptVar14;
  int *piVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  UT_hash_handle *pUVar20;
  UT_hash_bucket *pUVar21;
  uint32_t size;
  cgpu_info *pcVar22;
  undefined4 uVar23;
  char **ppcVar24;
  char *pcVar25;
  undefined4 in_stack_ffffd574;
  char acStack_2a80 [4104];
  undefined4 uStack_1a78;
  undefined4 uStack_1a74;
  char cStack_1a70;
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
  g_logfile_path._0_4_ = s_bmminer_log_000a5918._0_4_;
  g_logfile_path._4_4_ = s_bmminer_log_000a5918._4_4_;
  g_logfile_path._8_4_ = s_bmminer_log_000a5918._8_4_;
  g_logfile_openflag._0_2_ = DAT_000a5924;
  g_logfile_openflag[2] = DAT_000a5926;
  argv_local = argv;
  argc_local = argc;
  lVar4 = sysconf(0x54);
  if (lVar4 == 1) {
    selective_yield = sched_yield;
  }
  initial_args = (char **)_cgmalloc((argc_local + 1) * 4,"cgminer.c","main",0x2cf4);
  for (i = 0; i < argc_local; i = i + 1) {
    ppcVar24 = initial_args + i;
    pcVar25 = strdup(argv_local[i]);
    *ppcVar24 = pcVar25;
  }
  initial_args[argc_local] = (char *)0x0;
  _mutex_init(&hash_lock,"cgminer.c","main",0x2cfd);
  _mutex_init(&update_job_lock,"cgminer.c","main",0x2cfe);
  _mutex_init(&console_lock,"cgminer.c","main",0x2cff);
  _cglock_init(&control_lock,"cgminer.c","main",0x2d00);
  _mutex_init(&stats_lock,"cgminer.c","main",0x2d01);
  _mutex_init(&sharelog_lock,"cgminer.c","main",0x2d02);
  _cglock_init(&ch_lock,"cgminer.c","main",0x2d03);
  _mutex_init(&sshare_lock,"cgminer.c","main",0x2d04);
  _rwlock_init(&blk_lock,"cgminer.c","main",0x2d05);
  _rwlock_init(&netacc_lock,"cgminer.c","main",0x2d06);
  _rwlock_init(&mining_thr_lock,"cgminer.c","main",0x2d07);
  _rwlock_init(&devices_lock,"cgminer.c","main",0x2d08);
  _mutex_init(&lp_lock,"cgminer.c","main",0x2d0a);
  iVar5 = pthread_cond_init((pthread_cond_t *)&lp_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_lp_c_000a5928[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_lp_c_000a5928[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_lp_c_000a5928[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_lp_c_000a5928[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_lp_c_000a5928[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_lp_c_000a5928[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_lp_c_000a5928[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_lp_c_000a5928[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_lp_c_000a5928[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_lp_c_000a5928[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_lp_c_000a5928[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_lp_c_000a5928[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_lp_c_000a5928[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_lp_c_000a5928[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_lp_c_000a5928[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_lp_c_000a5928[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_lp_c_000a5928[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_lp_c_000a5928[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_lp_c_000a5928[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_lp_c_000a5928[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_lp_c_000a5928[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_lp_c_000a5928[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_lp_c_000a5928[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_lp_c_000a5928[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_lp_c_000a5928[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_lp_c_000a5928[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_lp_c_000a5928[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_lp_c_000a5928[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_lp_c_000a5928[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_lp_c_000a5928[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_lp_c_000a5928[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_lp_c_000a5928[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_lp_c_000a5928[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_lp_c_000a5928[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_lp_c_000a5928[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_lp_c_000a5928[35];
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  _mutex_init(&restart_lock,"cgminer.c","main",0x2d11);
  iVar5 = pthread_cond_init((pthread_cond_t *)&restart_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_rest_000a594c[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_rest_000a594c[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_rest_000a594c[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_rest_000a594c[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_rest_000a594c[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_rest_000a594c[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_rest_000a594c[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_rest_000a594c[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_rest_000a594c[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_rest_000a594c[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_rest_000a594c[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_rest_000a594c[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_rest_000a594c[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_rest_000a594c[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_rest_000a594c[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_rest_000a594c[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_rest_000a594c[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_rest_000a594c[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_rest_000a594c[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_rest_000a594c[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_rest_000a594c[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_rest_000a594c[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_rest_000a594c[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_rest_000a594c[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_rest_000a594c[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_rest_000a594c[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_rest_000a594c[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_rest_000a594c[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_rest_000a594c[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_rest_000a594c[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_rest_000a594c[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_rest_000a594c[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_rest_000a594c[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_rest_000a594c[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_rest_000a594c[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_rest_000a594c[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_rest_000a594c[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_rest_000a594c[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_rest_000a594c[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_rest_000a594c[39];
    tmp42[40] = (char)ram0x000a5974;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  iVar5 = pthread_cond_init((pthread_cond_t *)&gws_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_gws__000a5978[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_gws__000a5978[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_gws__000a5978[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_gws__000a5978[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_gws__000a5978[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_gws__000a5978[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_gws__000a5978[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_gws__000a5978[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_gws__000a5978[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_gws__000a5978[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_gws__000a5978[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_gws__000a5978[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_gws__000a5978[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_gws__000a5978[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_gws__000a5978[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_gws__000a5978[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_gws__000a5978[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_gws__000a5978[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_gws__000a5978[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_gws__000a5978[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_gws__000a5978[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_gws__000a5978[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_gws__000a5978[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_gws__000a5978[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_gws__000a5978[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_gws__000a5978[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_gws__000a5978[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_gws__000a5978[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_gws__000a5978[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_gws__000a5978[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_gws__000a5978[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_gws__000a5978[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_gws__000a5978[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_gws__000a5978[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_gws__000a5978[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_gws__000a5978[35];
    tmp42[36] = (char)ram0x000a599c;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  getq = tq_new();
  if (getq == (thread_q *)0x0) {
    tmp42[0] = s_Failed_to_create_getq_000a59a0[0];
    tmp42[1] = s_Failed_to_create_getq_000a59a0[1];
    tmp42[2] = s_Failed_to_create_getq_000a59a0[2];
    tmp42[3] = s_Failed_to_create_getq_000a59a0[3];
    tmp42[4] = s_Failed_to_create_getq_000a59a0[4];
    tmp42[5] = s_Failed_to_create_getq_000a59a0[5];
    tmp42[6] = s_Failed_to_create_getq_000a59a0[6];
    tmp42[7] = s_Failed_to_create_getq_000a59a0[7];
    tmp42[8] = s_Failed_to_create_getq_000a59a0[8];
    tmp42[9] = s_Failed_to_create_getq_000a59a0[9];
    tmp42[10] = s_Failed_to_create_getq_000a59a0[10];
    tmp42[11] = s_Failed_to_create_getq_000a59a0[11];
    tmp42[12] = s_Failed_to_create_getq_000a59a0[12];
    tmp42[13] = s_Failed_to_create_getq_000a59a0[13];
    tmp42[14] = s_Failed_to_create_getq_000a59a0[14];
    tmp42[15] = s_Failed_to_create_getq_000a59a0[15];
    tmp42[16] = s_Failed_to_create_getq_000a59a0[16];
    tmp42[17] = s_Failed_to_create_getq_000a59a0[17];
    tmp42[18] = s_Failed_to_create_getq_000a59a0[18];
    tmp42[19] = s_Failed_to_create_getq_000a59a0[19];
    tmp42[20] = (char)(short)ram0x000a59b4;
    tmp42[21] = (char)((ushort)(short)ram0x000a59b4 >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  stgd_lock = &getq->mutex;
  local_a80 = "2.0.0";
  snprintf(packagename,0x100,"%s %s","cgminer");
  handler.__sigaction_handler.sa_handler = sighandler;
  handler.sa_flags = 0;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  opt_kernel_path = (char *)&uStack_1a78;
  uStack_1a78._0_1_ = s__usr_bin_000a59d0[0];
  uStack_1a78._1_1_ = s__usr_bin_000a59d0[1];
  uStack_1a78._2_1_ = s__usr_bin_000a59d0[2];
  uStack_1a78._3_1_ = s__usr_bin_000a59d0[3];
  uStack_1a74._0_1_ = s__usr_bin_000a59d0[4];
  uStack_1a74._1_1_ = s__usr_bin_000a59d0[5];
  uStack_1a74._2_1_ = s__usr_bin_000a59d0[6];
  uStack_1a74._3_1_ = s__usr_bin_000a59d0[7];
  cStack_1a70 = s__usr_bin_000a59d0[8];
  cgminer_path = acStack_2a80;
  pcVar6 = strdup(*argv_local);
  pcVar25 = cgminer_path;
  __src = dirname(pcVar6);
  strcpy(pcVar25,__src);
  free(pcVar6);
  pcVar25 = cgminer_path;
  sVar7 = strlen(cgminer_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_000a40f0;
  devcursor = 8;
  logstart = 9;
  logcursor = 10;
  pcVar25 = (char *)0x2d40;
  __s = (block *)_cgcalloc(0x68,1,"cgminer.c","main",0x2d40);
  for (i = 0; i < 0x24; i = i + 1) {
    sVar7 = strlen((char *)__s);
    *(undefined2 *)(__s->hash + sVar7) = DAT_000a3d30;
  }
  _ha_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  _hj_k = strlen((char *)__s);
  _hj_key = (uchar *)__s;
  for (; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar5 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                    (uint)_hj_key[7] * 0x1000000;
    uVar17 = _ha_hashv +
             (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
             (uint)_hj_key[0xb] * 0x1000000;
    uVar18 = uVar17 >> 0xd ^
             ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                       (uint)_hj_key[3] * 0x1000000) - iVar5) - uVar17;
    uVar19 = uVar18 << 8 ^ (iVar5 - uVar17) - uVar18;
    uVar17 = uVar19 >> 0xd ^ (uVar17 - uVar18) - uVar19;
    uVar18 = uVar17 >> 0xc ^ (uVar18 - uVar19) - uVar17;
    uVar19 = uVar18 << 0x10 ^ (uVar19 - uVar17) - uVar18;
    uVar17 = uVar19 >> 5 ^ (uVar17 - uVar18) - uVar19;
    _hj_i = uVar17 >> 3 ^ (uVar18 - uVar19) - uVar17;
    _hj_j = _hj_i << 10 ^ (uVar19 - uVar17) - _hj_i;
    _ha_hashv = _hj_j >> 0xf ^ (uVar17 - _hj_i) - _hj_j;
    _hj_key = _hj_key + 0xc;
  }
  sVar7 = strlen((char *)__s);
  _ha_hashv = _ha_hashv + sVar7;
  switch(_hj_k) {
  case 0xb:
    _ha_hashv = _ha_hashv + (uint)_hj_key[10] * 0x1000000;
  case 10:
    _ha_hashv = _ha_hashv + (uint)_hj_key[9] * 0x10000;
  case 9:
    _ha_hashv = _ha_hashv + (uint)_hj_key[8] * 0x100;
  case 8:
    _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000;
  case 7:
    _hj_j = _hj_j + (uint)_hj_key[6] * 0x10000;
  case 6:
    _hj_j = _hj_j + (uint)_hj_key[5] * 0x100;
  case 5:
    _hj_j = _hj_j + _hj_key[4];
  case 4:
    _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000;
  case 3:
    _hj_i = _hj_i + (uint)_hj_key[2] * 0x10000;
  case 2:
    _hj_i = _hj_i + (uint)_hj_key[1] * 0x100;
  case 1:
    _hj_i = _hj_i + *_hj_key;
  }
  uVar17 = _ha_hashv >> 0xd ^ (_hj_i - _hj_j) - _ha_hashv;
  uVar18 = uVar17 << 8 ^ (_hj_j - _ha_hashv) - uVar17;
  uVar19 = uVar18 >> 0xd ^ (_ha_hashv - uVar17) - uVar18;
  uVar17 = uVar19 >> 0xc ^ (uVar17 - uVar18) - uVar19;
  uVar18 = uVar17 << 0x10 ^ (uVar18 - uVar19) - uVar17;
  uVar19 = uVar18 >> 5 ^ (uVar19 - uVar17) - uVar18;
  uVar17 = uVar19 >> 3 ^ (uVar17 - uVar18) - uVar19;
  uVar18 = uVar17 << 10 ^ (uVar18 - uVar19) - uVar17;
  uVar17 = uVar18 >> 0xf ^ (uVar19 - uVar17) - uVar18;
  (__s->hh).hashv = uVar17;
  (__s->hh).key = __s;
  sVar7 = strlen((char *)__s);
  (__s->hh).keylen = sVar7;
  if (blocks == (block *)0x0) {
    (__s->hh).next = (void *)0x0;
    (__s->hh).prev = (void *)0x0;
    blocks = __s;
    pUVar8 = (UT_hash_table *)malloc(0x2c);
    (__s->hh).tbl = pUVar8;
    if ((blocks->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset((blocks->hh).tbl,0,0x2c);
    ((blocks->hh).tbl)->tail = &blocks->hh;
    ((blocks->hh).tbl)->num_buckets = 0x20;
    ((blocks->hh).tbl)->log2_num_buckets = 5;
    ((blocks->hh).tbl)->hho = 0x44;
    pUVar8 = (blocks->hh).tbl;
    pUVar9 = (UT_hash_bucket *)malloc(0x180);
    pUVar8->buckets = pUVar9;
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
  pUVar8 = (blocks->hh).tbl;
  pUVar8->num_items = pUVar8->num_items + 1;
  uVar17 = ((blocks->hh).tbl)->num_buckets - 1 & uVar17;
  pUVar9 = ((blocks->hh).tbl)->buckets;
  pUVar9[uVar17].count = pUVar9[uVar17].count + 1;
  (__s->hh).hh_next = ((blocks->hh).tbl)->buckets[uVar17].hh_head;
  (__s->hh).hh_prev = (UT_hash_handle *)0x0;
  if (((blocks->hh).tbl)->buckets[uVar17].hh_head != (UT_hash_handle *)0x0) {
    (((blocks->hh).tbl)->buckets[uVar17].hh_head)->hh_prev = &__s->hh;
  }
  ((blocks->hh).tbl)->buckets[uVar17].hh_head = &__s->hh;
  if (((((blocks->hh).tbl)->buckets[uVar17].expand_mult + 1) * 10 <=
       ((blocks->hh).tbl)->buckets[uVar17].count) && (((__s->hh).tbl)->noexpand != 1)) {
    pUVar9 = (UT_hash_bucket *)malloc(((__s->hh).tbl)->num_buckets * 0x18);
    if (pUVar9 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar9,0,((__s->hh).tbl)->num_buckets * 0x18);
    ((__s->hh).tbl)->ideal_chain_maxlen =
         (uint)((((__s->hh).tbl)->num_buckets * 2 - 1 & ((__s->hh).tbl)->num_items) != 0) +
         (((__s->hh).tbl)->num_items >> (((__s->hh).tbl)->log2_num_buckets + 1 & 0xff));
    ((__s->hh).tbl)->nonideal_items = 0;
    for (_he_bkt_i = 0; _he_bkt_i < ((__s->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
      _he_thh = ((__s->hh).tbl)->buckets[_he_bkt_i].hh_head;
      while (_he_thh != (UT_hash_handle *)0x0) {
        pUVar20 = _he_thh->hh_next;
        pUVar21 = pUVar9 + (((__s->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
        pUVar21->count = pUVar21->count + 1;
        if (((__s->hh).tbl)->ideal_chain_maxlen < pUVar21->count) {
          pUVar8 = (__s->hh).tbl;
          pUVar8->nonideal_items = pUVar8->nonideal_items + 1;
          uVar17 = __udivsi3(pUVar21->count,((__s->hh).tbl)->ideal_chain_maxlen);
          pUVar21->expand_mult = uVar17;
        }
        _he_thh->hh_prev = (UT_hash_handle *)0x0;
        _he_thh->hh_next = pUVar21->hh_head;
        if (pUVar21->hh_head != (UT_hash_handle *)0x0) {
          pUVar21->hh_head->hh_prev = _he_thh;
        }
        pUVar21->hh_head = _he_thh;
        _he_thh = pUVar20;
      }
    }
    free(((__s->hh).tbl)->buckets);
    ((__s->hh).tbl)->num_buckets = ((__s->hh).tbl)->num_buckets << 1;
    pUVar8 = (__s->hh).tbl;
    pUVar8->log2_num_buckets = pUVar8->log2_num_buckets + 1;
    ((__s->hh).tbl)->buckets = pUVar9;
    if (((__s->hh).tbl)->num_items >> 1 < ((__s->hh).tbl)->nonideal_items) {
      uVar17 = ((__s->hh).tbl)->ineff_expands + 1;
    }
    else {
      uVar17 = 0;
    }
    ((__s->hh).tbl)->ineff_expands = uVar17;
    if (1 < ((__s->hh).tbl)->ineff_expands) {
      ((__s->hh).tbl)->noexpand = 1;
    }
  }
  strcpy(current_hash,(char *)__s);
  scan_devices.next = &scan_devices;
  scan_devices.prev = &scan_devices;
  opt_register_table(opt_config_table,"Options for both config file and command line");
  opt_register_table(opt_cmdline_table,"Options for command line only");
  opt_parse(&argc_local,argv_local,applog_and_exit);
  if (argc_local != 1) {
    tmp42[0] = s_Unexpected_extra_commandline_arg_000a5a2c[0];
    tmp42[1] = s_Unexpected_extra_commandline_arg_000a5a2c[1];
    tmp42[2] = s_Unexpected_extra_commandline_arg_000a5a2c[2];
    tmp42[3] = s_Unexpected_extra_commandline_arg_000a5a2c[3];
    tmp42[4] = s_Unexpected_extra_commandline_arg_000a5a2c[4];
    tmp42[5] = s_Unexpected_extra_commandline_arg_000a5a2c[5];
    tmp42[6] = s_Unexpected_extra_commandline_arg_000a5a2c[6];
    tmp42[7] = s_Unexpected_extra_commandline_arg_000a5a2c[7];
    tmp42[8] = s_Unexpected_extra_commandline_arg_000a5a2c[8];
    tmp42[9] = s_Unexpected_extra_commandline_arg_000a5a2c[9];
    tmp42[10] = s_Unexpected_extra_commandline_arg_000a5a2c[10];
    tmp42[11] = s_Unexpected_extra_commandline_arg_000a5a2c[11];
    tmp42[12] = s_Unexpected_extra_commandline_arg_000a5a2c[12];
    tmp42[13] = s_Unexpected_extra_commandline_arg_000a5a2c[13];
    tmp42[14] = s_Unexpected_extra_commandline_arg_000a5a2c[14];
    tmp42[15] = s_Unexpected_extra_commandline_arg_000a5a2c[15];
    tmp42[16] = s_Unexpected_extra_commandline_arg_000a5a2c[16];
    tmp42[17] = s_Unexpected_extra_commandline_arg_000a5a2c[17];
    tmp42[18] = s_Unexpected_extra_commandline_arg_000a5a2c[18];
    tmp42[19] = s_Unexpected_extra_commandline_arg_000a5a2c[19];
    tmp42[20] = s_Unexpected_extra_commandline_arg_000a5a2c[20];
    tmp42[21] = s_Unexpected_extra_commandline_arg_000a5a2c[21];
    tmp42[22] = s_Unexpected_extra_commandline_arg_000a5a2c[22];
    tmp42[23] = s_Unexpected_extra_commandline_arg_000a5a2c[23];
    tmp42[24] = s_Unexpected_extra_commandline_arg_000a5a2c[24];
    tmp42[25] = s_Unexpected_extra_commandline_arg_000a5a2c[25];
    tmp42[26] = s_Unexpected_extra_commandline_arg_000a5a2c[26];
    tmp42[27] = s_Unexpected_extra_commandline_arg_000a5a2c[27];
    tmp42[28] = s_Unexpected_extra_commandline_arg_000a5a2c[28];
    tmp42[29] = s_Unexpected_extra_commandline_arg_000a5a2c[29];
    tmp42[30] = s_Unexpected_extra_commandline_arg_000a5a2c[30];
    tmp42[31] = s_Unexpected_extra_commandline_arg_000a5a2c[31];
    tmp42[32] = s_Unexpected_extra_commandline_arg_000a5a2c[32];
    tmp42[33] = s_Unexpected_extra_commandline_arg_000a5a2c[33];
    tmp42[34] = s_Unexpected_extra_commandline_arg_000a5a2c[34];
    tmp42[35] = s_Unexpected_extra_commandline_arg_000a5a2c[35];
    tmp42._36_3_ = (undefined3)ram0x000a5a50;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  if (config_loaded != true) {
    load_default_config();
  }
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
    ppVar10 = add_pool();
    pcVar6 = (char *)_cgmalloc(0xff,"cgminer.c","main",0x2d64);
    ppVar10->rpc_url = pcVar6;
    uVar2 = s_Benchmark_000a5a60._4_4_;
    uVar23 = s_Benchfile_000a5a54._4_4_;
    if (opt_benchfile == (char *)0x0) {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchmark_000a5a60._0_4_;
      puVar16[1] = uVar2;
      *(undefined2 *)(puVar16 + 2) = s_Benchmark_000a5a60._8_2_;
    }
    else {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchfile_000a5a54._0_4_;
      puVar16[1] = uVar23;
      *(undefined2 *)(puVar16 + 2) = s_Benchfile_000a5a54._8_2_;
    }
    ppVar10->rpc_user = ppVar10->rpc_url;
    ppVar10->rpc_pass = ppVar10->rpc_url;
    ppVar10->rpc_userpass = ppVar10->rpc_url;
    ppVar10->sockaddr_url = ppVar10->rpc_url;
    strncpy(ppVar10->diff,"?",7);
    ppVar10->diff[7] = '\0';
    enable_pool(ppVar10);
    ppVar10->idle = false;
    successful_connect = true;
    for (i = 0; i < 0x10; i = i + 1) {
      hex2bin(bench_hidiff_bins[i],bench_hidiffs[i],0xa0);
      hex2bin(bench_lodiff_bins[i],bench_lodiffs[i],0xa0);
    }
    set_target(bench_target,(double)CONCAT44(in_stack_ffffd574,pcVar25));
  }
  if (opt_version_path != (char *)0x0) {
    pFVar11 = fopen(opt_version_path,"rb");
    memset(tmp,0,0x100);
    if (pFVar11 == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Open miner version file %s error",opt_version_path);
        _applog(3,tmp42,false);
      }
    }
    else {
      pcVar6 = (char *)fread(tmp,1,0x100,pFVar11);
      if ((int)pcVar6 < 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"Read miner version file %s error %d",opt_version_path,pcVar6);
          _applog(3,tmp42,false);
          pcVar25 = pcVar6;
        }
      }
      else {
        pcVar6 = strchr(tmp,10);
        if (pcVar6 == (char *)0x0) {
          strcpy(g_miner_compiletime,tmp);
        }
        else {
          pcVar25 = "main";
          _cg_memcpy(g_miner_compiletime,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2d9f);
          strcpy(tmp,pcVar6 + 1);
          pcVar6 = strchr(tmp,10);
          if (pcVar6 == (char *)0x0) {
            strcpy(g_miner_type,tmp);
          }
          else {
            pcVar25 = "main";
            _cg_memcpy(g_miner_type,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2da8);
          }
        }
        sVar7 = strlen(g_miner_compiletime);
        if (g_miner_version[sVar7 + 0xff] == '\n') {
          sVar7 = strlen(g_miner_compiletime);
          g_miner_version[sVar7 + 0xff] = '\0';
        }
        sVar7 = strlen(g_miner_compiletime);
        if (g_miner_version[sVar7 + 0xff] == '\r') {
          sVar7 = strlen(g_miner_compiletime);
          g_miner_version[sVar7 + 0xff] = '\0';
        }
        sVar7 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar7 + 0xff] == '\n') {
          sVar7 = strlen(g_miner_type);
          g_miner_compiletime[sVar7 + 0xff] = '\0';
        }
        sVar7 = strlen(g_miner_type);
        if (g_miner_compiletime[sVar7 + 0xff] == '\r') {
          sVar7 = strlen(g_miner_type);
          g_miner_compiletime[sVar7 + 0xff] = '\0';
        }
      }
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      pcVar25 = g_miner_type;
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
      pcVar25 = g_logfile_openflag;
      snprintf(tmp42,0x800,"Log file path: %s Open flag: %s",g_logfile_path,g_logfile_openflag);
      _applog(3,tmp42,false);
    }
  }
  if (opt_logwork_path != (char *)0x0) {
    memset(tmp,0,0x100);
    if (opt_logwork_asicnum == (char *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,"Log work path: %s",opt_logwork_path,pcVar25);
        _applog(3,tmp42,false);
      }
    }
    else {
      if (*opt_logwork_asicnum == '\0') {
        tmp42[0] = s_Log_work_asic_num_empty_000a5afc[0];
        tmp42[1] = s_Log_work_asic_num_empty_000a5afc[1];
        tmp42[2] = s_Log_work_asic_num_empty_000a5afc[2];
        tmp42[3] = s_Log_work_asic_num_empty_000a5afc[3];
        tmp42[4] = s_Log_work_asic_num_empty_000a5afc[4];
        tmp42[5] = s_Log_work_asic_num_empty_000a5afc[5];
        tmp42[6] = s_Log_work_asic_num_empty_000a5afc[6];
        tmp42[7] = s_Log_work_asic_num_empty_000a5afc[7];
        tmp42[8] = s_Log_work_asic_num_empty_000a5afc[8];
        tmp42[9] = s_Log_work_asic_num_empty_000a5afc[9];
        tmp42[10] = s_Log_work_asic_num_empty_000a5afc[10];
        tmp42[11] = s_Log_work_asic_num_empty_000a5afc[11];
        tmp42[12] = s_Log_work_asic_num_empty_000a5afc[12];
        tmp42[13] = s_Log_work_asic_num_empty_000a5afc[13];
        tmp42[14] = s_Log_work_asic_num_empty_000a5afc[14];
        tmp42[15] = s_Log_work_asic_num_empty_000a5afc[15];
        tmp42[16] = s_Log_work_asic_num_empty_000a5afc[16];
        tmp42[17] = s_Log_work_asic_num_empty_000a5afc[17];
        tmp42[18] = s_Log_work_asic_num_empty_000a5afc[18];
        tmp42[19] = s_Log_work_asic_num_empty_000a5afc[19];
        tmp42[20] = s_Log_work_asic_num_empty_000a5afc[20];
        tmp42[21] = s_Log_work_asic_num_empty_000a5afc[21];
        tmp42[22] = s_Log_work_asic_num_empty_000a5afc[22];
        tmp42[23] = s_Log_work_asic_num_empty_000a5afc[23];
        _applog(3,tmp42,true);
        _quit(1);
      }
      g_logwork_asicnum = atoi(opt_logwork_asicnum);
      if (((g_logwork_asicnum != 1) && (g_logwork_asicnum != 0x20)) && (g_logwork_asicnum != 0x40))
      {
        tmp42[0] = s_Log_work_asic_num_must_be_1__32__000a5b14[0];
        tmp42[1] = s_Log_work_asic_num_must_be_1__32__000a5b14[1];
        tmp42[2] = s_Log_work_asic_num_must_be_1__32__000a5b14[2];
        tmp42[3] = s_Log_work_asic_num_must_be_1__32__000a5b14[3];
        tmp42[4] = s_Log_work_asic_num_must_be_1__32__000a5b14[4];
        tmp42[5] = s_Log_work_asic_num_must_be_1__32__000a5b14[5];
        tmp42[6] = s_Log_work_asic_num_must_be_1__32__000a5b14[6];
        tmp42[7] = s_Log_work_asic_num_must_be_1__32__000a5b14[7];
        tmp42[8] = s_Log_work_asic_num_must_be_1__32__000a5b14[8];
        tmp42[9] = s_Log_work_asic_num_must_be_1__32__000a5b14[9];
        tmp42[10] = s_Log_work_asic_num_must_be_1__32__000a5b14[10];
        tmp42[11] = s_Log_work_asic_num_must_be_1__32__000a5b14[11];
        tmp42[12] = s_Log_work_asic_num_must_be_1__32__000a5b14[12];
        tmp42[13] = s_Log_work_asic_num_must_be_1__32__000a5b14[13];
        tmp42[14] = s_Log_work_asic_num_must_be_1__32__000a5b14[14];
        tmp42[15] = s_Log_work_asic_num_must_be_1__32__000a5b14[15];
        tmp42[16] = s_Log_work_asic_num_must_be_1__32__000a5b14[16];
        tmp42[17] = s_Log_work_asic_num_must_be_1__32__000a5b14[17];
        tmp42[18] = s_Log_work_asic_num_must_be_1__32__000a5b14[18];
        tmp42[19] = s_Log_work_asic_num_must_be_1__32__000a5b14[19];
        tmp42[20] = s_Log_work_asic_num_must_be_1__32__000a5b14[20];
        tmp42[21] = s_Log_work_asic_num_must_be_1__32__000a5b14[21];
        tmp42[22] = s_Log_work_asic_num_must_be_1__32__000a5b14[22];
        tmp42[23] = s_Log_work_asic_num_must_be_1__32__000a5b14[23];
        tmp42[24] = s_Log_work_asic_num_must_be_1__32__000a5b14[24];
        tmp42[25] = s_Log_work_asic_num_must_be_1__32__000a5b14[25];
        tmp42[26] = s_Log_work_asic_num_must_be_1__32__000a5b14[26];
        tmp42[27] = s_Log_work_asic_num_must_be_1__32__000a5b14[27];
        tmp42[28] = s_Log_work_asic_num_must_be_1__32__000a5b14[28];
        tmp42[29] = s_Log_work_asic_num_must_be_1__32__000a5b14[29];
        tmp42[30] = s_Log_work_asic_num_must_be_1__32__000a5b14[30];
        tmp42[31] = s_Log_work_asic_num_must_be_1__32__000a5b14[31];
        tmp42[32] = s_Log_work_asic_num_must_be_1__32__000a5b14[32];
        tmp42[33] = s_Log_work_asic_num_must_be_1__32__000a5b14[33];
        tmp42[34] = s_Log_work_asic_num_must_be_1__32__000a5b14[34];
        tmp42[35] = s_Log_work_asic_num_must_be_1__32__000a5b14[35];
        _applog(3,tmp42,true);
        _quit(1);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar25 = opt_logwork_asicnum;
        snprintf(tmp42,0x800,"Log work path: %s Asic num: %s",opt_logwork_path,opt_logwork_asicnum);
        _applog(3,tmp42,false);
      }
    }
    sprintf(tmp,"%s.txt",opt_logwork_path);
    g_logwork_file = (FILE *)fopen(tmp,(char *)&DAT_000a5924);
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Log work open file %s",tmp);
      _applog(3,tmp42,false);
    }
    if (g_logwork_asicnum == 1) {
      sprintf(tmp,"%s%02d.txt",opt_logwork_path,1);
      g_logwork_files[0] = (FILE *)fopen(tmp,(char *)&DAT_000a5924);
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar25 = tmp;
        snprintf(tmp42,0x800,"Log work open asic %d file %s",g_logwork_asicnum,pcVar25);
        _applog(3,tmp42,false);
      }
    }
    else if ((g_logwork_asicnum == 0x20) || (g_logwork_asicnum == 0x40)) {
      for (i = 0; i <= g_logwork_asicnum; i = i + 1) {
        pcVar25 = (char *)i;
        sprintf(tmp,"%s%02d_%02d.txt",opt_logwork_path,g_logwork_asicnum,i);
        pFVar11 = fopen(tmp,(char *)&DAT_000a5924);
        g_logwork_files[i] = (FILE *)pFVar11;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          pcVar25 = tmp;
          snprintf(tmp42,0x800,"Log work open asic %d file %s",g_logwork_asicnum,pcVar25);
          _applog(3,tmp42,false);
        }
      }
    }
    if (opt_logwork_diff != false) {
      for (i = 0; i < 0x41; i = i + 1) {
        sprintf(tmp,"%s_diff_%02d.txt",opt_logwork_path,i);
        pFVar11 = fopen(tmp,(char *)&DAT_000a5924);
        g_logwork_diffs[i] = (FILE *)pFVar11;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"Log work open diff file %s",tmp);
          _applog(3,tmp42,false);
        }
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Started %s",packagename,pcVar25);
    _applog(4,tmp42,false);
  }
  if (cnfbuf != (char *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Loaded configuration file %s",cnfbuf);
      _applog(5,tmp42,false);
    }
    if (fileconf_load == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Error_in_configuration_file__par_000a5c74[0];
        tmp42[1] = s_Error_in_configuration_file__par_000a5c74[1];
        tmp42[2] = s_Error_in_configuration_file__par_000a5c74[2];
        tmp42[3] = s_Error_in_configuration_file__par_000a5c74[3];
        tmp42[4] = s_Error_in_configuration_file__par_000a5c74[4];
        tmp42[5] = s_Error_in_configuration_file__par_000a5c74[5];
        tmp42[6] = s_Error_in_configuration_file__par_000a5c74[6];
        tmp42[7] = s_Error_in_configuration_file__par_000a5c74[7];
        tmp42[8] = s_Error_in_configuration_file__par_000a5c74[8];
        tmp42[9] = s_Error_in_configuration_file__par_000a5c74[9];
        tmp42[10] = s_Error_in_configuration_file__par_000a5c74[10];
        tmp42[11] = s_Error_in_configuration_file__par_000a5c74[11];
        tmp42[12] = s_Error_in_configuration_file__par_000a5c74[12];
        tmp42[13] = s_Error_in_configuration_file__par_000a5c74[13];
        tmp42[14] = s_Error_in_configuration_file__par_000a5c74[14];
        tmp42[15] = s_Error_in_configuration_file__par_000a5c74[15];
        tmp42[16] = s_Error_in_configuration_file__par_000a5c74[16];
        tmp42[17] = s_Error_in_configuration_file__par_000a5c74[17];
        tmp42[18] = s_Error_in_configuration_file__par_000a5c74[18];
        tmp42[19] = s_Error_in_configuration_file__par_000a5c74[19];
        tmp42[20] = s_Error_in_configuration_file__par_000a5c74[20];
        tmp42[21] = s_Error_in_configuration_file__par_000a5c74[21];
        tmp42[22] = s_Error_in_configuration_file__par_000a5c74[22];
        tmp42[23] = s_Error_in_configuration_file__par_000a5c74[23];
        tmp42[24] = s_Error_in_configuration_file__par_000a5c74[24];
        tmp42[25] = s_Error_in_configuration_file__par_000a5c74[25];
        tmp42[26] = s_Error_in_configuration_file__par_000a5c74[26];
        tmp42[27] = s_Error_in_configuration_file__par_000a5c74[27];
        tmp42[28] = s_Error_in_configuration_file__par_000a5c74[28];
        tmp42[29] = s_Error_in_configuration_file__par_000a5c74[29];
        tmp42[30] = s_Error_in_configuration_file__par_000a5c74[30];
        tmp42[31] = s_Error_in_configuration_file__par_000a5c74[31];
        tmp42[32] = s_Error_in_configuration_file__par_000a5c74[32];
        tmp42[33] = s_Error_in_configuration_file__par_000a5c74[33];
        tmp42[34] = s_Error_in_configuration_file__par_000a5c74[34];
        tmp42[35] = s_Error_in_configuration_file__par_000a5c74[35];
        tmp42[36] = s_Error_in_configuration_file__par_000a5c74[36];
        tmp42[37] = s_Error_in_configuration_file__par_000a5c74[37];
        tmp42[38] = s_Error_in_configuration_file__par_000a5c74[38];
        tmp42[39] = s_Error_in_configuration_file__par_000a5c74[39];
        tmp42[40] = s_Error_in_configuration_file__par_000a5c74[40];
        tmp42[41] = s_Error_in_configuration_file__par_000a5c74[41];
        tmp42[42] = s_Error_in_configuration_file__par_000a5c74[42];
        tmp42[43] = s_Error_in_configuration_file__par_000a5c74[43];
        tmp42._44_3_ = (undefined3)ram0x000a5ca0;
        _applog(4,tmp42,false);
      }
      if ((use_curses != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        tmp42[0] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[0];
        tmp42[1] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[1];
        tmp42[2] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[2];
        tmp42[3] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[3];
        tmp42[4] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[4];
        tmp42[5] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[5];
        tmp42[6] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[6];
        tmp42[7] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[7];
        tmp42[8] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[8];
        tmp42[9] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[9];
        tmp42[10] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[10];
        tmp42[11] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[11];
        tmp42[12] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[12];
        tmp42[13] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[13];
        tmp42[14] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[14];
        tmp42[15] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[15];
        tmp42[16] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[16];
        tmp42[17] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[17];
        tmp42[18] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[18];
        tmp42[19] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[19];
        tmp42[20] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[20];
        tmp42[21] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[21];
        tmp42[22] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[22];
        tmp42[23] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[23];
        tmp42[24] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[24];
        tmp42[25] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[25];
        tmp42[26] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[26];
        tmp42[27] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[27];
        tmp42[28] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[28];
        tmp42[29] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[29];
        tmp42[30] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[30];
        tmp42[31] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[31];
        tmp42[32] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[32];
        tmp42[33] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[33];
        tmp42[34] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[34];
        tmp42[35] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[35];
        tmp42[36] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[36];
        tmp42[37] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[37];
        tmp42[38] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[38];
        tmp42[39] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[39];
        tmp42[40] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[40];
        tmp42[41] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[41];
        tmp42[42] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[42];
        tmp42[43] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[43];
        tmp42[44] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[44];
        tmp42[45] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[45];
        tmp42[46] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[46];
        tmp42[47] = s_Start_cgminer_with__T_to_see_wha_000a5ca4[47];
        tmp42[48] = (char)(short)ram0x000a5cd4;
        tmp42[49] = (char)((ushort)(short)ram0x000a5cd4 >> 8);
        _applog(4,tmp42,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Fatal_JSON_error_in_configuratio_000a5c24[0];
        tmp42[1] = s_Fatal_JSON_error_in_configuratio_000a5c24[1];
        tmp42[2] = s_Fatal_JSON_error_in_configuratio_000a5c24[2];
        tmp42[3] = s_Fatal_JSON_error_in_configuratio_000a5c24[3];
        tmp42[4] = s_Fatal_JSON_error_in_configuratio_000a5c24[4];
        tmp42[5] = s_Fatal_JSON_error_in_configuratio_000a5c24[5];
        tmp42[6] = s_Fatal_JSON_error_in_configuratio_000a5c24[6];
        tmp42[7] = s_Fatal_JSON_error_in_configuratio_000a5c24[7];
        tmp42[8] = s_Fatal_JSON_error_in_configuratio_000a5c24[8];
        tmp42[9] = s_Fatal_JSON_error_in_configuratio_000a5c24[9];
        tmp42[10] = s_Fatal_JSON_error_in_configuratio_000a5c24[10];
        tmp42[11] = s_Fatal_JSON_error_in_configuratio_000a5c24[11];
        tmp42[12] = s_Fatal_JSON_error_in_configuratio_000a5c24[12];
        tmp42[13] = s_Fatal_JSON_error_in_configuratio_000a5c24[13];
        tmp42[14] = s_Fatal_JSON_error_in_configuratio_000a5c24[14];
        tmp42[15] = s_Fatal_JSON_error_in_configuratio_000a5c24[15];
        tmp42[16] = s_Fatal_JSON_error_in_configuratio_000a5c24[16];
        tmp42[17] = s_Fatal_JSON_error_in_configuratio_000a5c24[17];
        tmp42[18] = s_Fatal_JSON_error_in_configuratio_000a5c24[18];
        tmp42[19] = s_Fatal_JSON_error_in_configuratio_000a5c24[19];
        tmp42[20] = s_Fatal_JSON_error_in_configuratio_000a5c24[20];
        tmp42[21] = s_Fatal_JSON_error_in_configuratio_000a5c24[21];
        tmp42[22] = s_Fatal_JSON_error_in_configuratio_000a5c24[22];
        tmp42[23] = s_Fatal_JSON_error_in_configuratio_000a5c24[23];
        tmp42[24] = s_Fatal_JSON_error_in_configuratio_000a5c24[24];
        tmp42[25] = s_Fatal_JSON_error_in_configuratio_000a5c24[25];
        tmp42[26] = s_Fatal_JSON_error_in_configuratio_000a5c24[26];
        tmp42[27] = s_Fatal_JSON_error_in_configuratio_000a5c24[27];
        tmp42[28] = s_Fatal_JSON_error_in_configuratio_000a5c24[28];
        tmp42[29] = s_Fatal_JSON_error_in_configuratio_000a5c24[29];
        tmp42[30] = s_Fatal_JSON_error_in_configuratio_000a5c24[30];
        tmp42[31] = s_Fatal_JSON_error_in_configuratio_000a5c24[31];
        tmp42[32] = s_Fatal_JSON_error_in_configuratio_000a5c24[32];
        tmp42[33] = s_Fatal_JSON_error_in_configuratio_000a5c24[33];
        tmp42[34] = s_Fatal_JSON_error_in_configuratio_000a5c24[34];
        tmp42[35] = s_Fatal_JSON_error_in_configuratio_000a5c24[35];
        tmp42[36] = s_Fatal_JSON_error_in_configuratio_000a5c24[36];
        tmp42[37] = s_Fatal_JSON_error_in_configuratio_000a5c24[37];
        tmp42[38] = s_Fatal_JSON_error_in_configuratio_000a5c24[38];
        tmp42[39] = s_Fatal_JSON_error_in_configuratio_000a5c24[39];
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Configuration_file_could_not_be_u_000a5c4c[0];
        tmp42[1] = s_Configuration_file_could_not_be_u_000a5c4c[1];
        tmp42[2] = s_Configuration_file_could_not_be_u_000a5c4c[2];
        tmp42[3] = s_Configuration_file_could_not_be_u_000a5c4c[3];
        tmp42[4] = s_Configuration_file_could_not_be_u_000a5c4c[4];
        tmp42[5] = s_Configuration_file_could_not_be_u_000a5c4c[5];
        tmp42[6] = s_Configuration_file_could_not_be_u_000a5c4c[6];
        tmp42[7] = s_Configuration_file_could_not_be_u_000a5c4c[7];
        tmp42[8] = s_Configuration_file_could_not_be_u_000a5c4c[8];
        tmp42[9] = s_Configuration_file_could_not_be_u_000a5c4c[9];
        tmp42[10] = s_Configuration_file_could_not_be_u_000a5c4c[10];
        tmp42[11] = s_Configuration_file_could_not_be_u_000a5c4c[11];
        tmp42[12] = s_Configuration_file_could_not_be_u_000a5c4c[12];
        tmp42[13] = s_Configuration_file_could_not_be_u_000a5c4c[13];
        tmp42[14] = s_Configuration_file_could_not_be_u_000a5c4c[14];
        tmp42[15] = s_Configuration_file_could_not_be_u_000a5c4c[15];
        tmp42[16] = s_Configuration_file_could_not_be_u_000a5c4c[16];
        tmp42[17] = s_Configuration_file_could_not_be_u_000a5c4c[17];
        tmp42[18] = s_Configuration_file_could_not_be_u_000a5c4c[18];
        tmp42[19] = s_Configuration_file_could_not_be_u_000a5c4c[19];
        tmp42[20] = s_Configuration_file_could_not_be_u_000a5c4c[20];
        tmp42[21] = s_Configuration_file_could_not_be_u_000a5c4c[21];
        tmp42[22] = s_Configuration_file_could_not_be_u_000a5c4c[22];
        tmp42[23] = s_Configuration_file_could_not_be_u_000a5c4c[23];
        tmp42[24] = s_Configuration_file_could_not_be_u_000a5c4c[24];
        tmp42[25] = s_Configuration_file_could_not_be_u_000a5c4c[25];
        tmp42[26] = s_Configuration_file_could_not_be_u_000a5c4c[26];
        tmp42[27] = s_Configuration_file_could_not_be_u_000a5c4c[27];
        tmp42[28] = s_Configuration_file_could_not_be_u_000a5c4c[28];
        tmp42[29] = s_Configuration_file_could_not_be_u_000a5c4c[29];
        tmp42[30] = s_Configuration_file_could_not_be_u_000a5c4c[30];
        tmp42[31] = s_Configuration_file_could_not_be_u_000a5c4c[31];
        tmp42[32] = s_Configuration_file_could_not_be_u_000a5c4c[32];
        tmp42[33] = s_Configuration_file_could_not_be_u_000a5c4c[33];
        tmp42[34] = s_Configuration_file_could_not_be_u_000a5c4c[34];
        tmp42[35] = s_Configuration_file_could_not_be_u_000a5c4c[35];
        tmp42[36] = (char)(short)ram0x000a5c70;
        tmp42[37] = (char)((ushort)(short)ram0x000a5c70 >> 8);
        _applog(4,tmp42,false);
      }
    }
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar25 = opt_kernel_path;
  sVar7 = strlen(opt_kernel_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_000a40f0;
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
  pcVar25 = (char *)0x2e44;
  control_thr = (thr_info *)_cgcalloc(8,0x40,"cgminer.c","main",0x2e44);
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
      tmp42[0] = s_Devices_detected__000a5cd8[0];
      tmp42[1] = s_Devices_detected__000a5cd8[1];
      tmp42[2] = s_Devices_detected__000a5cd8[2];
      tmp42[3] = s_Devices_detected__000a5cd8[3];
      tmp42[4] = s_Devices_detected__000a5cd8[4];
      tmp42[5] = s_Devices_detected__000a5cd8[5];
      tmp42[6] = s_Devices_detected__000a5cd8[6];
      tmp42[7] = s_Devices_detected__000a5cd8[7];
      tmp42[8] = s_Devices_detected__000a5cd8[8];
      tmp42[9] = s_Devices_detected__000a5cd8[9];
      tmp42[10] = s_Devices_detected__000a5cd8[10];
      tmp42[11] = s_Devices_detected__000a5cd8[11];
      tmp42[12] = s_Devices_detected__000a5cd8[12];
      tmp42[13] = s_Devices_detected__000a5cd8[13];
      tmp42[14] = s_Devices_detected__000a5cd8[14];
      tmp42[15] = s_Devices_detected__000a5cd8[15];
      tmp42[16] = (char)(short)ram0x000a5ce8;
      tmp42[17] = (char)((ushort)(short)ram0x000a5ce8 >> 8);
      _applog(3,tmp42,false);
    }
    for (i = 0; i < total_devices; i = i + 1) {
      pcVar22 = devices[i];
      if (pcVar22->name == (char *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          pcVar25 = pcVar22->drv->name;
          snprintf(tmp42,0x800," %2d. %s %d (driver: %s)",i,pcVar25,pcVar22->device_id,
                   pcVar22->drv->dname);
          _applog(3,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        pcVar25 = pcVar22->drv->name;
        snprintf(tmp42,0x800," %2d. %s %d: %s (driver: %s)",i,pcVar25,pcVar22->device_id,
                 pcVar22->name,pcVar22->drv->dname);
        _applog(3,tmp42,false);
      }
    }
    snprintf(tmp42,0x800,"%d devices listed",total_devices,pcVar25);
    _applog(3,tmp42,true);
    __quit(0,false);
  }
  mining_threads = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    enable_device(devices[i]);
  }
  if (total_devices == 0) {
    tmp42[0] = s_All_devices_disabled__cannot_min_000a5d3c[0];
    tmp42[1] = s_All_devices_disabled__cannot_min_000a5d3c[1];
    tmp42[2] = s_All_devices_disabled__cannot_min_000a5d3c[2];
    tmp42[3] = s_All_devices_disabled__cannot_min_000a5d3c[3];
    tmp42[4] = s_All_devices_disabled__cannot_min_000a5d3c[4];
    tmp42[5] = s_All_devices_disabled__cannot_min_000a5d3c[5];
    tmp42[6] = s_All_devices_disabled__cannot_min_000a5d3c[6];
    tmp42[7] = s_All_devices_disabled__cannot_min_000a5d3c[7];
    tmp42[8] = s_All_devices_disabled__cannot_min_000a5d3c[8];
    tmp42[9] = s_All_devices_disabled__cannot_min_000a5d3c[9];
    tmp42[10] = s_All_devices_disabled__cannot_min_000a5d3c[10];
    tmp42[11] = s_All_devices_disabled__cannot_min_000a5d3c[11];
    tmp42[12] = s_All_devices_disabled__cannot_min_000a5d3c[12];
    tmp42[13] = s_All_devices_disabled__cannot_min_000a5d3c[13];
    tmp42[14] = s_All_devices_disabled__cannot_min_000a5d3c[14];
    tmp42[15] = s_All_devices_disabled__cannot_min_000a5d3c[15];
    tmp42[16] = s_All_devices_disabled__cannot_min_000a5d3c[16];
    tmp42[17] = s_All_devices_disabled__cannot_min_000a5d3c[17];
    tmp42[18] = s_All_devices_disabled__cannot_min_000a5d3c[18];
    tmp42[19] = s_All_devices_disabled__cannot_min_000a5d3c[19];
    tmp42[20] = s_All_devices_disabled__cannot_min_000a5d3c[20];
    tmp42[21] = s_All_devices_disabled__cannot_min_000a5d3c[21];
    tmp42[22] = s_All_devices_disabled__cannot_min_000a5d3c[22];
    tmp42[23] = s_All_devices_disabled__cannot_min_000a5d3c[23];
    tmp42[24] = s_All_devices_disabled__cannot_min_000a5d3c[24];
    tmp42[25] = s_All_devices_disabled__cannot_min_000a5d3c[25];
    tmp42[26] = s_All_devices_disabled__cannot_min_000a5d3c[26];
    tmp42[27] = s_All_devices_disabled__cannot_min_000a5d3c[27];
    tmp42[28] = s_All_devices_disabled__cannot_min_000a5d3c[28];
    tmp42[29] = s_All_devices_disabled__cannot_min_000a5d3c[29];
    tmp42[30] = s_All_devices_disabled__cannot_min_000a5d3c[30];
    tmp42[31] = s_All_devices_disabled__cannot_min_000a5d3c[31];
    tmp42._32_3_ = (undefined3)ram0x000a5d5c;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  most_devices = total_devices;
  load_temp_cutoffs();
  for (i = 0; i < total_devices; i = i + 1) {
    (devices[i]->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
  }
  if (opt_compact != true) {
    logstart = logstart + most_devices;
    logcursor = logstart + 1;
  }
  if (total_pools == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      tmp42[0] = s_Need_to_specify_at_least_one_poo_000a5d60[0];
      tmp42[1] = s_Need_to_specify_at_least_one_poo_000a5d60[1];
      tmp42[2] = s_Need_to_specify_at_least_one_poo_000a5d60[2];
      tmp42[3] = s_Need_to_specify_at_least_one_poo_000a5d60[3];
      tmp42[4] = s_Need_to_specify_at_least_one_poo_000a5d60[4];
      tmp42[5] = s_Need_to_specify_at_least_one_poo_000a5d60[5];
      tmp42[6] = s_Need_to_specify_at_least_one_poo_000a5d60[6];
      tmp42[7] = s_Need_to_specify_at_least_one_poo_000a5d60[7];
      tmp42[8] = s_Need_to_specify_at_least_one_poo_000a5d60[8];
      tmp42[9] = s_Need_to_specify_at_least_one_poo_000a5d60[9];
      tmp42[10] = s_Need_to_specify_at_least_one_poo_000a5d60[10];
      tmp42[11] = s_Need_to_specify_at_least_one_poo_000a5d60[11];
      tmp42[12] = s_Need_to_specify_at_least_one_poo_000a5d60[12];
      tmp42[13] = s_Need_to_specify_at_least_one_poo_000a5d60[13];
      tmp42[14] = s_Need_to_specify_at_least_one_poo_000a5d60[14];
      tmp42[15] = s_Need_to_specify_at_least_one_poo_000a5d60[15];
      tmp42[16] = s_Need_to_specify_at_least_one_poo_000a5d60[16];
      tmp42[17] = s_Need_to_specify_at_least_one_poo_000a5d60[17];
      tmp42[18] = s_Need_to_specify_at_least_one_poo_000a5d60[18];
      tmp42[19] = s_Need_to_specify_at_least_one_poo_000a5d60[19];
      tmp42[20] = s_Need_to_specify_at_least_one_poo_000a5d60[20];
      tmp42[21] = s_Need_to_specify_at_least_one_poo_000a5d60[21];
      tmp42[22] = s_Need_to_specify_at_least_one_poo_000a5d60[22];
      tmp42[23] = s_Need_to_specify_at_least_one_poo_000a5d60[23];
      tmp42[24] = s_Need_to_specify_at_least_one_poo_000a5d60[24];
      tmp42[25] = s_Need_to_specify_at_least_one_poo_000a5d60[25];
      tmp42[26] = s_Need_to_specify_at_least_one_poo_000a5d60[26];
      tmp42[27] = s_Need_to_specify_at_least_one_poo_000a5d60[27];
      tmp42[28] = s_Need_to_specify_at_least_one_poo_000a5d60[28];
      tmp42[29] = s_Need_to_specify_at_least_one_poo_000a5d60[29];
      tmp42[30] = s_Need_to_specify_at_least_one_poo_000a5d60[30];
      tmp42[31] = s_Need_to_specify_at_least_one_poo_000a5d60[31];
      tmp42[32] = s_Need_to_specify_at_least_one_poo_000a5d60[32];
      tmp42[33] = s_Need_to_specify_at_least_one_poo_000a5d60[33];
      tmp42[34] = s_Need_to_specify_at_least_one_poo_000a5d60[34];
      tmp42[35] = s_Need_to_specify_at_least_one_poo_000a5d60[35];
      tmp42[36] = s_Need_to_specify_at_least_one_poo_000a5d60[36];
      tmp42[37] = s_Need_to_specify_at_least_one_poo_000a5d60[37];
      tmp42[38] = s_Need_to_specify_at_least_one_poo_000a5d60[38];
      tmp42[39] = s_Need_to_specify_at_least_one_poo_000a5d60[39];
      tmp42[40] = (char)(short)ram0x000a5d88;
      tmp42[41] = (char)((ushort)(short)ram0x000a5d88 >> 8);
      _applog(4,tmp42,false);
    }
    tmp42[0] = s_Pool_setup_failed_000a5d8c[0];
    tmp42[1] = s_Pool_setup_failed_000a5d8c[1];
    tmp42[2] = s_Pool_setup_failed_000a5d8c[2];
    tmp42[3] = s_Pool_setup_failed_000a5d8c[3];
    tmp42[4] = s_Pool_setup_failed_000a5d8c[4];
    tmp42[5] = s_Pool_setup_failed_000a5d8c[5];
    tmp42[6] = s_Pool_setup_failed_000a5d8c[6];
    tmp42[7] = s_Pool_setup_failed_000a5d8c[7];
    tmp42[8] = s_Pool_setup_failed_000a5d8c[8];
    tmp42[9] = s_Pool_setup_failed_000a5d8c[9];
    tmp42[10] = s_Pool_setup_failed_000a5d8c[10];
    tmp42[11] = s_Pool_setup_failed_000a5d8c[11];
    tmp42[12] = s_Pool_setup_failed_000a5d8c[12];
    tmp42[13] = s_Pool_setup_failed_000a5d8c[13];
    tmp42[14] = s_Pool_setup_failed_000a5d8c[14];
    tmp42[15] = s_Pool_setup_failed_000a5d8c[15];
    tmp42[16] = (char)(short)ram0x000a5d9c;
    tmp42[17] = (char)((ushort)(short)ram0x000a5d9c >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar10 = pools[i];
    (ppVar10->cgminer_stats).getwork_wait_min.tv_sec = 99999999;
    (ppVar10->cgminer_pool_stats).getwork_wait_min.tv_sec = 99999999;
    if (ppVar10->rpc_userpass == (char *)0x0) {
      if (ppVar10->rpc_pass == (char *)0x0) {
        pcVar25 = strdup("");
        ppVar10->rpc_pass = pcVar25;
      }
      if (ppVar10->rpc_user == (char *)0x0) {
        snprintf(tmp42,0x800,"No login credentials supplied for pool %u %s",i,ppVar10->rpc_url);
        _applog(3,tmp42,true);
        __quit(1,false);
      }
      sVar7 = strlen(ppVar10->rpc_user);
      sVar12 = strlen(ppVar10->rpc_pass);
      size = sVar7 + sVar12 + 2;
      pcVar25 = (char *)_cgmalloc(size,"cgminer.c","main",0x2eb1);
      ppVar10->rpc_userpass = pcVar25;
      snprintf(ppVar10->rpc_userpass,size,"%s:%s",ppVar10->rpc_user,ppVar10->rpc_pass);
    }
  }
  currentpool = *pools;
  if (use_syslog != false) {
    openlog("cgminer",1,8);
  }
  if (opt_stderr_cmd != (char *)0x0) {
    fork_monitor();
  }
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,"cgminer.c","main",0x2ec2);
  for (i = 0; i < mining_threads; i = i + 1) {
    pptVar13 = mining_thr + i;
    ptVar14 = (thr_info *)_cgcalloc(1,0x40,"cgminer.c","main",0x2ec6);
    *pptVar13 = ptVar14;
  }
  k = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar22 = devices[i];
    pptVar13 = (thr_info **)_cgmalloc((pcVar22->threads + 1) * 4,"cgminer.c","main",0x2ecf);
    pcVar22->thr = pptVar13;
    pcVar22->thr[pcVar22->threads] = (thr_info *)0x0;
    pcVar22->status = LIFE_INIT;
    for (j = 0; j < pcVar22->threads; j = j + 1) {
      ptVar14 = get_thread(k);
      ptVar14->id = k;
      ptVar14->cgpu = pcVar22;
      ptVar14->device_thread = j;
      _Var3 = (*pcVar22->drv->thread_prepare)(ptVar14);
      if (_Var3) {
        iVar5 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,miner_thread,ptVar14);
        if (iVar5 != 0) {
          snprintf(tmp42,0x800,"thread %d create failed",ptVar14->id);
          _applog(3,tmp42,true);
          __quit(1,false);
        }
        pcVar22->thr[j] = ptVar14;
        if (pcVar22->deven != DEV_DISABLED) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Pushing sem post to thread %d",ptVar14->id);
            _applog(7,tmp42,false);
          }
          _cgsem_post(&ptVar14->sem,"cgminer.c","main",0x2eeb);
        }
      }
      k = k + 1;
    }
  }
  if ((opt_benchmark == false) && (opt_benchfile == (char *)0x0)) {
    for (i = 0; i < total_pools; i = i + 1) {
      ppVar10 = pools[i];
      enable_pool(ppVar10);
      ppVar10->idle = true;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_Probing_for_an_alive_pool_000a5de8[0];
      tmp42[1] = s_Probing_for_an_alive_pool_000a5de8[1];
      tmp42[2] = s_Probing_for_an_alive_pool_000a5de8[2];
      tmp42[3] = s_Probing_for_an_alive_pool_000a5de8[3];
      tmp42[4] = s_Probing_for_an_alive_pool_000a5de8[4];
      tmp42[5] = s_Probing_for_an_alive_pool_000a5de8[5];
      tmp42[6] = s_Probing_for_an_alive_pool_000a5de8[6];
      tmp42[7] = s_Probing_for_an_alive_pool_000a5de8[7];
      tmp42[8] = s_Probing_for_an_alive_pool_000a5de8[8];
      tmp42[9] = s_Probing_for_an_alive_pool_000a5de8[9];
      tmp42[10] = s_Probing_for_an_alive_pool_000a5de8[10];
      tmp42[11] = s_Probing_for_an_alive_pool_000a5de8[11];
      tmp42[12] = s_Probing_for_an_alive_pool_000a5de8[12];
      tmp42[13] = s_Probing_for_an_alive_pool_000a5de8[13];
      tmp42[14] = s_Probing_for_an_alive_pool_000a5de8[14];
      tmp42[15] = s_Probing_for_an_alive_pool_000a5de8[15];
      tmp42[16] = s_Probing_for_an_alive_pool_000a5de8[16];
      tmp42[17] = s_Probing_for_an_alive_pool_000a5de8[17];
      tmp42[18] = s_Probing_for_an_alive_pool_000a5de8[18];
      tmp42[19] = s_Probing_for_an_alive_pool_000a5de8[19];
      tmp42[20] = s_Probing_for_an_alive_pool_000a5de8[20];
      tmp42[21] = s_Probing_for_an_alive_pool_000a5de8[21];
      tmp42[22] = s_Probing_for_an_alive_pool_000a5de8[22];
      tmp42[23] = s_Probing_for_an_alive_pool_000a5de8[23];
      tmp42[24] = (char)(short)ram0x000a5e00;
      tmp42[25] = (char)((ushort)(short)ram0x000a5e00 >> 8);
      _applog(5,tmp42,false);
    }
    probe_pools();
    do {
      sleep(1);
      slept = slept + 1;
      if (pools_active == true) break;
    } while (slept < 0xb4);
    while (pools_active != true) {
      if (!bVar1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_No_servers_were_found_that_could_000a5e04[0];
          tmp42[1] = s_No_servers_were_found_that_could_000a5e04[1];
          tmp42[2] = s_No_servers_were_found_that_could_000a5e04[2];
          tmp42[3] = s_No_servers_were_found_that_could_000a5e04[3];
          tmp42[4] = s_No_servers_were_found_that_could_000a5e04[4];
          tmp42[5] = s_No_servers_were_found_that_could_000a5e04[5];
          tmp42[6] = s_No_servers_were_found_that_could_000a5e04[6];
          tmp42[7] = s_No_servers_were_found_that_could_000a5e04[7];
          tmp42[8] = s_No_servers_were_found_that_could_000a5e04[8];
          tmp42[9] = s_No_servers_were_found_that_could_000a5e04[9];
          tmp42[10] = s_No_servers_were_found_that_could_000a5e04[10];
          tmp42[11] = s_No_servers_were_found_that_could_000a5e04[11];
          tmp42[12] = s_No_servers_were_found_that_could_000a5e04[12];
          tmp42[13] = s_No_servers_were_found_that_could_000a5e04[13];
          tmp42[14] = s_No_servers_were_found_that_could_000a5e04[14];
          tmp42[15] = s_No_servers_were_found_that_could_000a5e04[15];
          tmp42[16] = s_No_servers_were_found_that_could_000a5e04[16];
          tmp42[17] = s_No_servers_were_found_that_could_000a5e04[17];
          tmp42[18] = s_No_servers_were_found_that_could_000a5e04[18];
          tmp42[19] = s_No_servers_were_found_that_could_000a5e04[19];
          tmp42[20] = s_No_servers_were_found_that_could_000a5e04[20];
          tmp42[21] = s_No_servers_were_found_that_could_000a5e04[21];
          tmp42[22] = s_No_servers_were_found_that_could_000a5e04[22];
          tmp42[23] = s_No_servers_were_found_that_could_000a5e04[23];
          tmp42[24] = s_No_servers_were_found_that_could_000a5e04[24];
          tmp42[25] = s_No_servers_were_found_that_could_000a5e04[25];
          tmp42[26] = s_No_servers_were_found_that_could_000a5e04[26];
          tmp42[27] = s_No_servers_were_found_that_could_000a5e04[27];
          tmp42[28] = s_No_servers_were_found_that_could_000a5e04[28];
          tmp42[29] = s_No_servers_were_found_that_could_000a5e04[29];
          tmp42[30] = s_No_servers_were_found_that_could_000a5e04[30];
          tmp42[31] = s_No_servers_were_found_that_could_000a5e04[31];
          tmp42[32] = s_No_servers_were_found_that_could_000a5e04[32];
          tmp42[33] = s_No_servers_were_found_that_could_000a5e04[33];
          tmp42[34] = s_No_servers_were_found_that_could_000a5e04[34];
          tmp42[35] = s_No_servers_were_found_that_could_000a5e04[35];
          tmp42[36] = s_No_servers_were_found_that_could_000a5e04[36];
          tmp42[37] = s_No_servers_were_found_that_could_000a5e04[37];
          tmp42[38] = s_No_servers_were_found_that_could_000a5e04[38];
          tmp42[39] = s_No_servers_were_found_that_could_000a5e04[39];
          tmp42[40] = s_No_servers_were_found_that_could_000a5e04[40];
          tmp42[41] = s_No_servers_were_found_that_could_000a5e04[41];
          tmp42[42] = s_No_servers_were_found_that_could_000a5e04[42];
          tmp42[43] = s_No_servers_were_found_that_could_000a5e04[43];
          tmp42[44] = s_No_servers_were_found_that_could_000a5e04[44];
          tmp42[45] = s_No_servers_were_found_that_could_000a5e04[45];
          tmp42[46] = s_No_servers_were_found_that_could_000a5e04[46];
          tmp42[47] = s_No_servers_were_found_that_could_000a5e04[47];
          tmp42[48] = s_No_servers_were_found_that_could_000a5e04[48];
          tmp42[49] = s_No_servers_were_found_that_could_000a5e04[49];
          tmp42[50] = s_No_servers_were_found_that_could_000a5e04[50];
          tmp42[51] = s_No_servers_were_found_that_could_000a5e04[51];
          tmp42[52] = s_No_servers_were_found_that_could_000a5e04[52];
          tmp42[53] = s_No_servers_were_found_that_could_000a5e04[53];
          tmp42[54] = s_No_servers_were_found_that_could_000a5e04[54];
          tmp42[55] = s_No_servers_were_found_that_could_000a5e04[55];
          tmp42._56_2_ = (undefined2)ram0x000a5e3c;
          tmp42[58] = (char)((uint)ram0x000a5e3c >> 0x10);
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
          ppVar10 = pools[i];
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool: %d  URL: %s  User: %s  Password: %s",i,ppVar10->rpc_url,
                     ppVar10->rpc_user,ppVar10->rpc_pass);
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
      if (use_curses != true) {
        tmp42[0] = s_No_servers_could_be_used__Exitin_000a5f64[0];
        tmp42[1] = s_No_servers_could_be_used__Exitin_000a5f64[1];
        tmp42[2] = s_No_servers_could_be_used__Exitin_000a5f64[2];
        tmp42[3] = s_No_servers_could_be_used__Exitin_000a5f64[3];
        tmp42[4] = s_No_servers_could_be_used__Exitin_000a5f64[4];
        tmp42[5] = s_No_servers_could_be_used__Exitin_000a5f64[5];
        tmp42[6] = s_No_servers_could_be_used__Exitin_000a5f64[6];
        tmp42[7] = s_No_servers_could_be_used__Exitin_000a5f64[7];
        tmp42[8] = s_No_servers_could_be_used__Exitin_000a5f64[8];
        tmp42[9] = s_No_servers_could_be_used__Exitin_000a5f64[9];
        tmp42[10] = s_No_servers_could_be_used__Exitin_000a5f64[10];
        tmp42[11] = s_No_servers_could_be_used__Exitin_000a5f64[11];
        tmp42[12] = s_No_servers_could_be_used__Exitin_000a5f64[12];
        tmp42[13] = s_No_servers_could_be_used__Exitin_000a5f64[13];
        tmp42[14] = s_No_servers_could_be_used__Exitin_000a5f64[14];
        tmp42[15] = s_No_servers_could_be_used__Exitin_000a5f64[15];
        tmp42[16] = s_No_servers_could_be_used__Exitin_000a5f64[16];
        tmp42[17] = s_No_servers_could_be_used__Exitin_000a5f64[17];
        tmp42[18] = s_No_servers_could_be_used__Exitin_000a5f64[18];
        tmp42[19] = s_No_servers_could_be_used__Exitin_000a5f64[19];
        tmp42[20] = s_No_servers_could_be_used__Exitin_000a5f64[20];
        tmp42[21] = s_No_servers_could_be_used__Exitin_000a5f64[21];
        tmp42[22] = s_No_servers_could_be_used__Exitin_000a5f64[22];
        tmp42[23] = s_No_servers_could_be_used__Exitin_000a5f64[23];
        tmp42[24] = s_No_servers_could_be_used__Exitin_000a5f64[24];
        tmp42[25] = s_No_servers_could_be_used__Exitin_000a5f64[25];
        tmp42[26] = s_No_servers_could_be_used__Exitin_000a5f64[26];
        tmp42[27] = s_No_servers_could_be_used__Exitin_000a5f64[27];
        tmp42[28] = s_No_servers_could_be_used__Exitin_000a5f64[28];
        tmp42[29] = s_No_servers_could_be_used__Exitin_000a5f64[29];
        tmp42[30] = s_No_servers_could_be_used__Exitin_000a5f64[30];
        tmp42[31] = s_No_servers_could_be_used__Exitin_000a5f64[31];
        tmp42._32_3_ = (undefined3)ram0x000a5f84;
        _applog(3,tmp42,true);
        __quit(0,false);
      }
    }
  }
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  for (i = 0; i < 0xc; i = i + 1) {
    *(undefined4 *)(g_local_mhashes_dones + i) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + i * 8 + 4) = 0;
  }
  g_local_mhashes_index = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar22 = devices[i];
    *(undefined4 *)&pcVar22->total_mhashes = 0;
    *(undefined4 *)((int)&pcVar22->total_mhashes + 4) = 0;
    uVar23 = *(undefined4 *)((int)&pcVar22->total_mhashes + 4);
    *(undefined4 *)&pcVar22->rolling = *(undefined4 *)&pcVar22->total_mhashes;
    *(undefined4 *)((int)&pcVar22->rolling + 4) = uVar23;
  }
  iVar5 = sysinfo((sysinfo *)&sInfo);
  if (iVar5 == 0) {
    total_tv_end_sys = sInfo.uptime;
    total_tv_start_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar15 = __errno_location();
      iVar5 = *piVar15;
      piVar15 = __errno_location();
      pcVar25 = strerror(*piVar15);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar5,pcVar25);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_start);
  cgtime(&total_tv_end);
  cgtime(&tv_hashmeter);
  get_datestamp(datestamp,0x28,&total_tv_start);
  ptVar14 = control_thr;
  watchpool_thr_id = 2;
  iVar5 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,watchpool_thread,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchpool_thread_create_failed_000a5f88[0];
    tmp42[1] = s_watchpool_thread_create_failed_000a5f88[1];
    tmp42[2] = s_watchpool_thread_create_failed_000a5f88[2];
    tmp42[3] = s_watchpool_thread_create_failed_000a5f88[3];
    tmp42[4] = s_watchpool_thread_create_failed_000a5f88[4];
    tmp42[5] = s_watchpool_thread_create_failed_000a5f88[5];
    tmp42[6] = s_watchpool_thread_create_failed_000a5f88[6];
    tmp42[7] = s_watchpool_thread_create_failed_000a5f88[7];
    tmp42[8] = s_watchpool_thread_create_failed_000a5f88[8];
    tmp42[9] = s_watchpool_thread_create_failed_000a5f88[9];
    tmp42[10] = s_watchpool_thread_create_failed_000a5f88[10];
    tmp42[11] = s_watchpool_thread_create_failed_000a5f88[11];
    tmp42[12] = s_watchpool_thread_create_failed_000a5f88[12];
    tmp42[13] = s_watchpool_thread_create_failed_000a5f88[13];
    tmp42[14] = s_watchpool_thread_create_failed_000a5f88[14];
    tmp42[15] = s_watchpool_thread_create_failed_000a5f88[15];
    tmp42[16] = s_watchpool_thread_create_failed_000a5f88[16];
    tmp42[17] = s_watchpool_thread_create_failed_000a5f88[17];
    tmp42[18] = s_watchpool_thread_create_failed_000a5f88[18];
    tmp42[19] = s_watchpool_thread_create_failed_000a5f88[19];
    tmp42[20] = s_watchpool_thread_create_failed_000a5f88[20];
    tmp42[21] = s_watchpool_thread_create_failed_000a5f88[21];
    tmp42[22] = s_watchpool_thread_create_failed_000a5f88[22];
    tmp42[23] = s_watchpool_thread_create_failed_000a5f88[23];
    tmp42[24] = s_watchpool_thread_create_failed_000a5f88[24];
    tmp42[25] = s_watchpool_thread_create_failed_000a5f88[25];
    tmp42[26] = s_watchpool_thread_create_failed_000a5f88[26];
    tmp42[27] = s_watchpool_thread_create_failed_000a5f88[27];
    tmp42._28_3_ = (undefined3)ram0x000a5fa4;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[2].pth);
  ptVar14 = control_thr;
  watchdog_thr_id = 3;
  iVar5 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,watchdog_thread,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchdog_thread_create_failed_000a5fa8[0];
    tmp42[1] = s_watchdog_thread_create_failed_000a5fa8[1];
    tmp42[2] = s_watchdog_thread_create_failed_000a5fa8[2];
    tmp42[3] = s_watchdog_thread_create_failed_000a5fa8[3];
    tmp42[4] = s_watchdog_thread_create_failed_000a5fa8[4];
    tmp42[5] = s_watchdog_thread_create_failed_000a5fa8[5];
    tmp42[6] = s_watchdog_thread_create_failed_000a5fa8[6];
    tmp42[7] = s_watchdog_thread_create_failed_000a5fa8[7];
    tmp42[8] = s_watchdog_thread_create_failed_000a5fa8[8];
    tmp42[9] = s_watchdog_thread_create_failed_000a5fa8[9];
    tmp42[10] = s_watchdog_thread_create_failed_000a5fa8[10];
    tmp42[11] = s_watchdog_thread_create_failed_000a5fa8[11];
    tmp42[12] = s_watchdog_thread_create_failed_000a5fa8[12];
    tmp42[13] = s_watchdog_thread_create_failed_000a5fa8[13];
    tmp42[14] = s_watchdog_thread_create_failed_000a5fa8[14];
    tmp42[15] = s_watchdog_thread_create_failed_000a5fa8[15];
    tmp42[16] = s_watchdog_thread_create_failed_000a5fa8[16];
    tmp42[17] = s_watchdog_thread_create_failed_000a5fa8[17];
    tmp42[18] = s_watchdog_thread_create_failed_000a5fa8[18];
    tmp42[19] = s_watchdog_thread_create_failed_000a5fa8[19];
    tmp42[20] = s_watchdog_thread_create_failed_000a5fa8[20];
    tmp42[21] = s_watchdog_thread_create_failed_000a5fa8[21];
    tmp42[22] = s_watchdog_thread_create_failed_000a5fa8[22];
    tmp42[23] = s_watchdog_thread_create_failed_000a5fa8[23];
    tmp42[24] = s_watchdog_thread_create_failed_000a5fa8[24];
    tmp42[25] = s_watchdog_thread_create_failed_000a5fa8[25];
    tmp42[26] = s_watchdog_thread_create_failed_000a5fa8[26];
    tmp42[27] = s_watchdog_thread_create_failed_000a5fa8[27];
    tmp42[28] = (char)(short)ram0x000a5fc4;
    tmp42[29] = (char)((ushort)(short)ram0x000a5fc4 >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[3].pth);
  api_thr_id = 5;
  iVar5 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,api_thread,control_thr + 5);
  if (iVar5 != 0) {
    tmp42[0] = s_API_thread_create_failed_000a5fc8[0];
    tmp42[1] = s_API_thread_create_failed_000a5fc8[1];
    tmp42[2] = s_API_thread_create_failed_000a5fc8[2];
    tmp42[3] = s_API_thread_create_failed_000a5fc8[3];
    tmp42[4] = s_API_thread_create_failed_000a5fc8[4];
    tmp42[5] = s_API_thread_create_failed_000a5fc8[5];
    tmp42[6] = s_API_thread_create_failed_000a5fc8[6];
    tmp42[7] = s_API_thread_create_failed_000a5fc8[7];
    tmp42[8] = s_API_thread_create_failed_000a5fc8[8];
    tmp42[9] = s_API_thread_create_failed_000a5fc8[9];
    tmp42[10] = s_API_thread_create_failed_000a5fc8[10];
    tmp42[11] = s_API_thread_create_failed_000a5fc8[11];
    tmp42[12] = s_API_thread_create_failed_000a5fc8[12];
    tmp42[13] = s_API_thread_create_failed_000a5fc8[13];
    tmp42[14] = s_API_thread_create_failed_000a5fc8[14];
    tmp42[15] = s_API_thread_create_failed_000a5fc8[15];
    tmp42[16] = s_API_thread_create_failed_000a5fc8[16];
    tmp42[17] = s_API_thread_create_failed_000a5fc8[17];
    tmp42[18] = s_API_thread_create_failed_000a5fc8[18];
    tmp42[19] = s_API_thread_create_failed_000a5fc8[19];
    tmp42[20] = s_API_thread_create_failed_000a5fc8[20];
    tmp42[21] = s_API_thread_create_failed_000a5fc8[21];
    tmp42[22] = s_API_thread_create_failed_000a5fc8[22];
    tmp42[23] = s_API_thread_create_failed_000a5fc8[23];
    tmp42[24] = (char)ram0x000a5fe0;
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
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            iVar5 = max_queue;
            if (opt_work_update != false) {
              signal_work_update();
            }
            opt_work_update = false;
            _mutex_lock(stgd_lock,"cgminer.c","main",0x2f9e);
            ts = __total_staged();
            if (iVar5 < ts) {
              work_filled = true;
              pthread_cond_wait((pthread_cond_t *)&gws_cond,(pthread_mutex_t *)stgd_lock);
              ts = __total_staged();
            }
            _mutex_unlock(stgd_lock,"cgminer.c","main",0x2fa9);
            if (ts <= iVar5) break;
            work_filled = true;
            work = hash_pop(false);
            if (work != (work *)0x0) {
              _discard_work(&work,"cgminer.c","main",0x2fb5);
            }
          }
          if (work != (work *)0x0) {
            _discard_work(&work,"cgminer.c","main",0x2fbd);
          }
          work = make_work();
          while( true ) {
            ppVar10 = select_pool();
            _Var3 = pool_unusable(ppVar10);
            if (!_Var3) break;
            switch_pools((pool *)0x0);
            ppVar10 = select_pool();
            _Var3 = pool_unusable(ppVar10);
            if (_Var3) {
              cgsleep_ms(0xb);
            }
          }
          if (ppVar10->has_stratum == false) break;
          gen_stratum_work(ppVar10,work);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Generated_stratum_work_000a6018[0];
            tmp42[1] = s_Generated_stratum_work_000a6018[1];
            tmp42[2] = s_Generated_stratum_work_000a6018[2];
            tmp42[3] = s_Generated_stratum_work_000a6018[3];
            tmp42[4] = s_Generated_stratum_work_000a6018[4];
            tmp42[5] = s_Generated_stratum_work_000a6018[5];
            tmp42[6] = s_Generated_stratum_work_000a6018[6];
            tmp42[7] = s_Generated_stratum_work_000a6018[7];
            tmp42[8] = s_Generated_stratum_work_000a6018[8];
            tmp42[9] = s_Generated_stratum_work_000a6018[9];
            tmp42[10] = s_Generated_stratum_work_000a6018[10];
            tmp42[11] = s_Generated_stratum_work_000a6018[11];
            tmp42[12] = s_Generated_stratum_work_000a6018[12];
            tmp42[13] = s_Generated_stratum_work_000a6018[13];
            tmp42[14] = s_Generated_stratum_work_000a6018[14];
            tmp42[15] = s_Generated_stratum_work_000a6018[15];
            tmp42[16] = s_Generated_stratum_work_000a6018[16];
            tmp42[17] = s_Generated_stratum_work_000a6018[17];
            tmp42[18] = s_Generated_stratum_work_000a6018[18];
            tmp42[19] = s_Generated_stratum_work_000a6018[19];
            tmp42._20_3_ = (undefined3)ram0x000a602c;
            _applog(7,tmp42,false);
          }
          _stage_work(work);
          work = (work *)0x0;
        }
        if (opt_benchfile == (char *)0x0) break;
        get_benchfile_work(work);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Generated_benchfile_work_000a6030[0];
          tmp42[1] = s_Generated_benchfile_work_000a6030[1];
          tmp42[2] = s_Generated_benchfile_work_000a6030[2];
          tmp42[3] = s_Generated_benchfile_work_000a6030[3];
          tmp42[4] = s_Generated_benchfile_work_000a6030[4];
          tmp42[5] = s_Generated_benchfile_work_000a6030[5];
          tmp42[6] = s_Generated_benchfile_work_000a6030[6];
          tmp42[7] = s_Generated_benchfile_work_000a6030[7];
          tmp42[8] = s_Generated_benchfile_work_000a6030[8];
          tmp42[9] = s_Generated_benchfile_work_000a6030[9];
          tmp42[10] = s_Generated_benchfile_work_000a6030[10];
          tmp42[11] = s_Generated_benchfile_work_000a6030[11];
          tmp42[12] = s_Generated_benchfile_work_000a6030[12];
          tmp42[13] = s_Generated_benchfile_work_000a6030[13];
          tmp42[14] = s_Generated_benchfile_work_000a6030[14];
          tmp42[15] = s_Generated_benchfile_work_000a6030[15];
          tmp42[16] = s_Generated_benchfile_work_000a6030[16];
          tmp42[17] = s_Generated_benchfile_work_000a6030[17];
          tmp42[18] = s_Generated_benchfile_work_000a6030[18];
          tmp42[19] = s_Generated_benchfile_work_000a6030[19];
          tmp42[20] = s_Generated_benchfile_work_000a6030[20];
          tmp42[21] = s_Generated_benchfile_work_000a6030[21];
          tmp42[22] = s_Generated_benchfile_work_000a6030[22];
          tmp42[23] = s_Generated_benchfile_work_000a6030[23];
          tmp42[24] = (char)ram0x000a6048;
          _applog(7,tmp42,false);
        }
        _stage_work(work);
        work = (work *)0x0;
      }
    } while (opt_benchmark == false);
    get_benchmark_work(work);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Generated_benchmark_work_000a604c[0];
      tmp42[1] = s_Generated_benchmark_work_000a604c[1];
      tmp42[2] = s_Generated_benchmark_work_000a604c[2];
      tmp42[3] = s_Generated_benchmark_work_000a604c[3];
      tmp42[4] = s_Generated_benchmark_work_000a604c[4];
      tmp42[5] = s_Generated_benchmark_work_000a604c[5];
      tmp42[6] = s_Generated_benchmark_work_000a604c[6];
      tmp42[7] = s_Generated_benchmark_work_000a604c[7];
      tmp42[8] = s_Generated_benchmark_work_000a604c[8];
      tmp42[9] = s_Generated_benchmark_work_000a604c[9];
      tmp42[10] = s_Generated_benchmark_work_000a604c[10];
      tmp42[11] = s_Generated_benchmark_work_000a604c[11];
      tmp42[12] = s_Generated_benchmark_work_000a604c[12];
      tmp42[13] = s_Generated_benchmark_work_000a604c[13];
      tmp42[14] = s_Generated_benchmark_work_000a604c[14];
      tmp42[15] = s_Generated_benchmark_work_000a604c[15];
      tmp42[16] = s_Generated_benchmark_work_000a604c[16];
      tmp42[17] = s_Generated_benchmark_work_000a604c[17];
      tmp42[18] = s_Generated_benchmark_work_000a604c[18];
      tmp42[19] = s_Generated_benchmark_work_000a604c[19];
      tmp42[20] = s_Generated_benchmark_work_000a604c[20];
      tmp42[21] = s_Generated_benchmark_work_000a604c[21];
      tmp42[22] = s_Generated_benchmark_work_000a604c[22];
      tmp42[23] = s_Generated_benchmark_work_000a604c[23];
      tmp42[24] = (char)ram0x000a6064;
      _applog(7,tmp42,false);
    }
    _stage_work(work);
    work = (work *)0x0;
  } while( true );
}

