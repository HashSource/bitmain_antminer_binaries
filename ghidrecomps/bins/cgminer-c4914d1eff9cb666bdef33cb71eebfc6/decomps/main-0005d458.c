
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
  char **ppcVar23;
  undefined4 uVar24;
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
  argv_local = argv;
  argc_local = argc;
  _Var3 = is_cgminer_already_started();
  if (_Var3) {
    puts("cgminer is forbidden to start again as it is already started,will exit immediately.");
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  g_logfile_path[0] = s_bmminer_log_0008e6c4[0];
  g_logfile_path[1] = s_bmminer_log_0008e6c4[1];
  g_logfile_path[2] = s_bmminer_log_0008e6c4[2];
  g_logfile_path[3] = s_bmminer_log_0008e6c4[3];
  g_logfile_path[4] = s_bmminer_log_0008e6c4[4];
  g_logfile_path[5] = s_bmminer_log_0008e6c4[5];
  g_logfile_path[6] = s_bmminer_log_0008e6c4[6];
  g_logfile_path[7] = s_bmminer_log_0008e6c4[7];
  g_logfile_path[8] = s_bmminer_log_0008e6c4[8];
  g_logfile_path[9] = s_bmminer_log_0008e6c4[9];
  g_logfile_path[10] = s_bmminer_log_0008e6c4[10];
  g_logfile_path[11] = s_bmminer_log_0008e6c4[11];
  g_logfile_openflag[0] = (char)DAT_0008e568;
  g_logfile_openflag[1] = DAT_0008e568._1_1_;
  g_logfile_openflag[2] = DAT_0008e56a;
  lVar4 = sysconf(0x54);
  if (lVar4 == 1) {
    selective_yield = sched_yield;
  }
  initial_args = (char **)_cgmalloc((argc_local + 1) * 4,"cgminer.c","main",0x2d33);
  for (i = 0; i < argc_local; i = i + 1) {
    ppcVar23 = initial_args + i;
    pcVar25 = strdup(argv_local[i]);
    *ppcVar23 = pcVar25;
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
  iVar5 = pthread_cond_init((pthread_cond_t *)&lp_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_lp_c_0008e6d0[35];
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  _mutex_init(&restart_lock,"cgminer.c","main",0x2d50);
  iVar5 = pthread_cond_init((pthread_cond_t *)&restart_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_rest_0008e6f4[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_rest_0008e6f4[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_rest_0008e6f4[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_rest_0008e6f4[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_rest_0008e6f4[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_rest_0008e6f4[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_rest_0008e6f4[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_rest_0008e6f4[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_rest_0008e6f4[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_rest_0008e6f4[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_rest_0008e6f4[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_rest_0008e6f4[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_rest_0008e6f4[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_rest_0008e6f4[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_rest_0008e6f4[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_rest_0008e6f4[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_rest_0008e6f4[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_rest_0008e6f4[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_rest_0008e6f4[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_rest_0008e6f4[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_rest_0008e6f4[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_rest_0008e6f4[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_rest_0008e6f4[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_rest_0008e6f4[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_rest_0008e6f4[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_rest_0008e6f4[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_rest_0008e6f4[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_rest_0008e6f4[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_rest_0008e6f4[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_rest_0008e6f4[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_rest_0008e6f4[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_rest_0008e6f4[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_rest_0008e6f4[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_rest_0008e6f4[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_rest_0008e6f4[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_rest_0008e6f4[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_rest_0008e6f4[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_rest_0008e6f4[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_rest_0008e6f4[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_rest_0008e6f4[39];
    tmp42[40] = (char)ram0x0008e71c;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  iVar5 = pthread_cond_init((pthread_cond_t *)&gws_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_gws__0008e720[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_gws__0008e720[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_gws__0008e720[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_gws__0008e720[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_gws__0008e720[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_gws__0008e720[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_gws__0008e720[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_gws__0008e720[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_gws__0008e720[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_gws__0008e720[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_gws__0008e720[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_gws__0008e720[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_gws__0008e720[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_gws__0008e720[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_gws__0008e720[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_gws__0008e720[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_gws__0008e720[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_gws__0008e720[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_gws__0008e720[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_gws__0008e720[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_gws__0008e720[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_gws__0008e720[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_gws__0008e720[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_gws__0008e720[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_gws__0008e720[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_gws__0008e720[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_gws__0008e720[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_gws__0008e720[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_gws__0008e720[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_gws__0008e720[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_gws__0008e720[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_gws__0008e720[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_gws__0008e720[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_gws__0008e720[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_gws__0008e720[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_gws__0008e720[35];
    tmp42[36] = (char)ram0x0008e744;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  getq = tq_new();
  if (getq == (thread_q *)0x0) {
    tmp42[0] = s_Failed_to_create_getq_0008e748[0];
    tmp42[1] = s_Failed_to_create_getq_0008e748[1];
    tmp42[2] = s_Failed_to_create_getq_0008e748[2];
    tmp42[3] = s_Failed_to_create_getq_0008e748[3];
    tmp42[4] = s_Failed_to_create_getq_0008e748[4];
    tmp42[5] = s_Failed_to_create_getq_0008e748[5];
    tmp42[6] = s_Failed_to_create_getq_0008e748[6];
    tmp42[7] = s_Failed_to_create_getq_0008e748[7];
    tmp42[8] = s_Failed_to_create_getq_0008e748[8];
    tmp42[9] = s_Failed_to_create_getq_0008e748[9];
    tmp42[10] = s_Failed_to_create_getq_0008e748[10];
    tmp42[11] = s_Failed_to_create_getq_0008e748[11];
    tmp42[12] = s_Failed_to_create_getq_0008e748[12];
    tmp42[13] = s_Failed_to_create_getq_0008e748[13];
    tmp42[14] = s_Failed_to_create_getq_0008e748[14];
    tmp42[15] = s_Failed_to_create_getq_0008e748[15];
    tmp42[16] = s_Failed_to_create_getq_0008e748[16];
    tmp42[17] = s_Failed_to_create_getq_0008e748[17];
    tmp42[18] = s_Failed_to_create_getq_0008e748[18];
    tmp42[19] = s_Failed_to_create_getq_0008e748[19];
    tmp42[20] = (char)(short)ram0x0008e75c;
    tmp42[21] = (char)((ushort)(short)ram0x0008e75c >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  stgd_lock = &getq->mutex;
  local_a80 = "2.0.0";
  snprintf(packagename,0x100,"%s %s","cgminer");
  handler.__sigaction_handler.sa_handler = sighandler + 1;
  handler.sa_flags = 0;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  opt_kernel_path = (char *)&uStack_1a78;
  uStack_1a78._0_1_ = s__usr_bin_0008e770[0];
  uStack_1a78._1_1_ = s__usr_bin_0008e770[1];
  uStack_1a78._2_1_ = s__usr_bin_0008e770[2];
  uStack_1a78._3_1_ = s__usr_bin_0008e770[3];
  uStack_1a74._0_1_ = s__usr_bin_0008e770[4];
  uStack_1a74._1_1_ = s__usr_bin_0008e770[5];
  uStack_1a74._2_1_ = s__usr_bin_0008e770[6];
  uStack_1a74._3_1_ = s__usr_bin_0008e770[7];
  cStack_1a70 = s__usr_bin_0008e770[8];
  cgminer_path = acStack_2a80;
  pcVar6 = strdup(*argv_local);
  pcVar25 = cgminer_path;
  __src = dirname(pcVar6);
  strcpy(pcVar25,__src);
  free(pcVar6);
  pcVar25 = cgminer_path;
  sVar7 = strlen(cgminer_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_0008cd34;
  devcursor = 8;
  logstart = 9;
  logcursor = 10;
  pcVar25 = (char *)0x2d7f;
  __s = (block *)_cgcalloc(0x68,1,"cgminer.c","main",0x2d7f);
  for (i = 0; i < 0x24; i = i + 1) {
    sVar7 = strlen((char *)__s);
    *(undefined2 *)(__s->hash + sVar7) = DAT_0008c974;
  }
  _ha_hashv = 0xfeedbeef;
  _hj_j = 0x9e3779b9;
  _hj_i = 0x9e3779b9;
  _hj_k = strlen((char *)__s);
  _hj_key = (uchar *)__s;
  for (; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
    iVar5 = (uint)_hj_key[7] * 0x1000000 +
            (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 + _hj_j;
    uVar17 = (uint)_hj_key[0xb] * 0x1000000 +
             (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 + _ha_hashv;
    uVar18 = uVar17 >> 0xd ^
             (((uint)_hj_key[3] * 0x1000000 +
               (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 + _hj_i) -
             iVar5) - uVar17;
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
         (((__s->hh).tbl)->num_items >> (((__s->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
         (uint)((((__s->hh).tbl)->num_buckets * 2 - 1 & ((__s->hh).tbl)->num_items) != 0);
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
  opt_parse(&argc_local,argv_local,applog_and_exit + 1);
  if (argc_local != 1) {
    tmp42[0] = s_Unexpected_extra_commandline_arg_0008e7cc[0];
    tmp42[1] = s_Unexpected_extra_commandline_arg_0008e7cc[1];
    tmp42[2] = s_Unexpected_extra_commandline_arg_0008e7cc[2];
    tmp42[3] = s_Unexpected_extra_commandline_arg_0008e7cc[3];
    tmp42[4] = s_Unexpected_extra_commandline_arg_0008e7cc[4];
    tmp42[5] = s_Unexpected_extra_commandline_arg_0008e7cc[5];
    tmp42[6] = s_Unexpected_extra_commandline_arg_0008e7cc[6];
    tmp42[7] = s_Unexpected_extra_commandline_arg_0008e7cc[7];
    tmp42[8] = s_Unexpected_extra_commandline_arg_0008e7cc[8];
    tmp42[9] = s_Unexpected_extra_commandline_arg_0008e7cc[9];
    tmp42[10] = s_Unexpected_extra_commandline_arg_0008e7cc[10];
    tmp42[11] = s_Unexpected_extra_commandline_arg_0008e7cc[11];
    tmp42[12] = s_Unexpected_extra_commandline_arg_0008e7cc[12];
    tmp42[13] = s_Unexpected_extra_commandline_arg_0008e7cc[13];
    tmp42[14] = s_Unexpected_extra_commandline_arg_0008e7cc[14];
    tmp42[15] = s_Unexpected_extra_commandline_arg_0008e7cc[15];
    tmp42[16] = s_Unexpected_extra_commandline_arg_0008e7cc[16];
    tmp42[17] = s_Unexpected_extra_commandline_arg_0008e7cc[17];
    tmp42[18] = s_Unexpected_extra_commandline_arg_0008e7cc[18];
    tmp42[19] = s_Unexpected_extra_commandline_arg_0008e7cc[19];
    tmp42[20] = s_Unexpected_extra_commandline_arg_0008e7cc[20];
    tmp42[21] = s_Unexpected_extra_commandline_arg_0008e7cc[21];
    tmp42[22] = s_Unexpected_extra_commandline_arg_0008e7cc[22];
    tmp42[23] = s_Unexpected_extra_commandline_arg_0008e7cc[23];
    tmp42[24] = s_Unexpected_extra_commandline_arg_0008e7cc[24];
    tmp42[25] = s_Unexpected_extra_commandline_arg_0008e7cc[25];
    tmp42[26] = s_Unexpected_extra_commandline_arg_0008e7cc[26];
    tmp42[27] = s_Unexpected_extra_commandline_arg_0008e7cc[27];
    tmp42[28] = s_Unexpected_extra_commandline_arg_0008e7cc[28];
    tmp42[29] = s_Unexpected_extra_commandline_arg_0008e7cc[29];
    tmp42[30] = s_Unexpected_extra_commandline_arg_0008e7cc[30];
    tmp42[31] = s_Unexpected_extra_commandline_arg_0008e7cc[31];
    tmp42[32] = s_Unexpected_extra_commandline_arg_0008e7cc[32];
    tmp42[33] = s_Unexpected_extra_commandline_arg_0008e7cc[33];
    tmp42[34] = s_Unexpected_extra_commandline_arg_0008e7cc[34];
    tmp42[35] = s_Unexpected_extra_commandline_arg_0008e7cc[35];
    tmp42._36_3_ = (undefined3)ram0x0008e7f0;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  if (config_loaded != true) {
    load_default_config();
  }
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
    ppVar10 = add_pool();
    pcVar6 = (char *)_cgmalloc(0xff,"cgminer.c","main",0x2da3);
    ppVar10->rpc_url = pcVar6;
    uVar2 = s_Benchmark_0008e800._4_4_;
    uVar24 = s_Benchfile_0008e7f4._4_4_;
    if (opt_benchfile == (char *)0x0) {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchmark_0008e800._0_4_;
      puVar16[1] = uVar2;
      *(undefined2 *)(puVar16 + 2) = s_Benchmark_0008e800._8_2_;
    }
    else {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchfile_0008e7f4._0_4_;
      puVar16[1] = uVar24;
      *(undefined2 *)(puVar16 + 2) = s_Benchfile_0008e7f4._8_2_;
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
          _cg_memcpy(g_miner_compiletime,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2dde);
          strcpy(tmp,pcVar6 + 1);
          pcVar6 = strchr(tmp,10);
          if (pcVar6 == (char *)0x0) {
            strcpy(g_miner_type,tmp);
          }
          else {
            pcVar25 = "main";
            _cg_memcpy(g_miner_type,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2de7);
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
        tmp42[0] = s_Log_work_asic_num_empty_0008e89c[0];
        tmp42[1] = s_Log_work_asic_num_empty_0008e89c[1];
        tmp42[2] = s_Log_work_asic_num_empty_0008e89c[2];
        tmp42[3] = s_Log_work_asic_num_empty_0008e89c[3];
        tmp42[4] = s_Log_work_asic_num_empty_0008e89c[4];
        tmp42[5] = s_Log_work_asic_num_empty_0008e89c[5];
        tmp42[6] = s_Log_work_asic_num_empty_0008e89c[6];
        tmp42[7] = s_Log_work_asic_num_empty_0008e89c[7];
        tmp42[8] = s_Log_work_asic_num_empty_0008e89c[8];
        tmp42[9] = s_Log_work_asic_num_empty_0008e89c[9];
        tmp42[10] = s_Log_work_asic_num_empty_0008e89c[10];
        tmp42[11] = s_Log_work_asic_num_empty_0008e89c[11];
        tmp42[12] = s_Log_work_asic_num_empty_0008e89c[12];
        tmp42[13] = s_Log_work_asic_num_empty_0008e89c[13];
        tmp42[14] = s_Log_work_asic_num_empty_0008e89c[14];
        tmp42[15] = s_Log_work_asic_num_empty_0008e89c[15];
        tmp42[16] = s_Log_work_asic_num_empty_0008e89c[16];
        tmp42[17] = s_Log_work_asic_num_empty_0008e89c[17];
        tmp42[18] = s_Log_work_asic_num_empty_0008e89c[18];
        tmp42[19] = s_Log_work_asic_num_empty_0008e89c[19];
        tmp42[20] = s_Log_work_asic_num_empty_0008e89c[20];
        tmp42[21] = s_Log_work_asic_num_empty_0008e89c[21];
        tmp42[22] = s_Log_work_asic_num_empty_0008e89c[22];
        tmp42[23] = s_Log_work_asic_num_empty_0008e89c[23];
        _applog(3,tmp42,true);
        _quit(1);
      }
      g_logwork_asicnum = atoi(opt_logwork_asicnum);
      if (((g_logwork_asicnum != 1) && (g_logwork_asicnum != 0x20)) && (g_logwork_asicnum != 0x40))
      {
        tmp42[0] = s_Log_work_asic_num_must_be_1__32__0008e8b4[0];
        tmp42[1] = s_Log_work_asic_num_must_be_1__32__0008e8b4[1];
        tmp42[2] = s_Log_work_asic_num_must_be_1__32__0008e8b4[2];
        tmp42[3] = s_Log_work_asic_num_must_be_1__32__0008e8b4[3];
        tmp42[4] = s_Log_work_asic_num_must_be_1__32__0008e8b4[4];
        tmp42[5] = s_Log_work_asic_num_must_be_1__32__0008e8b4[5];
        tmp42[6] = s_Log_work_asic_num_must_be_1__32__0008e8b4[6];
        tmp42[7] = s_Log_work_asic_num_must_be_1__32__0008e8b4[7];
        tmp42[8] = s_Log_work_asic_num_must_be_1__32__0008e8b4[8];
        tmp42[9] = s_Log_work_asic_num_must_be_1__32__0008e8b4[9];
        tmp42[10] = s_Log_work_asic_num_must_be_1__32__0008e8b4[10];
        tmp42[11] = s_Log_work_asic_num_must_be_1__32__0008e8b4[11];
        tmp42[12] = s_Log_work_asic_num_must_be_1__32__0008e8b4[12];
        tmp42[13] = s_Log_work_asic_num_must_be_1__32__0008e8b4[13];
        tmp42[14] = s_Log_work_asic_num_must_be_1__32__0008e8b4[14];
        tmp42[15] = s_Log_work_asic_num_must_be_1__32__0008e8b4[15];
        tmp42[16] = s_Log_work_asic_num_must_be_1__32__0008e8b4[16];
        tmp42[17] = s_Log_work_asic_num_must_be_1__32__0008e8b4[17];
        tmp42[18] = s_Log_work_asic_num_must_be_1__32__0008e8b4[18];
        tmp42[19] = s_Log_work_asic_num_must_be_1__32__0008e8b4[19];
        tmp42[20] = s_Log_work_asic_num_must_be_1__32__0008e8b4[20];
        tmp42[21] = s_Log_work_asic_num_must_be_1__32__0008e8b4[21];
        tmp42[22] = s_Log_work_asic_num_must_be_1__32__0008e8b4[22];
        tmp42[23] = s_Log_work_asic_num_must_be_1__32__0008e8b4[23];
        tmp42[24] = s_Log_work_asic_num_must_be_1__32__0008e8b4[24];
        tmp42[25] = s_Log_work_asic_num_must_be_1__32__0008e8b4[25];
        tmp42[26] = s_Log_work_asic_num_must_be_1__32__0008e8b4[26];
        tmp42[27] = s_Log_work_asic_num_must_be_1__32__0008e8b4[27];
        tmp42[28] = s_Log_work_asic_num_must_be_1__32__0008e8b4[28];
        tmp42[29] = s_Log_work_asic_num_must_be_1__32__0008e8b4[29];
        tmp42[30] = s_Log_work_asic_num_must_be_1__32__0008e8b4[30];
        tmp42[31] = s_Log_work_asic_num_must_be_1__32__0008e8b4[31];
        tmp42[32] = s_Log_work_asic_num_must_be_1__32__0008e8b4[32];
        tmp42[33] = s_Log_work_asic_num_must_be_1__32__0008e8b4[33];
        tmp42[34] = s_Log_work_asic_num_must_be_1__32__0008e8b4[34];
        tmp42[35] = s_Log_work_asic_num_must_be_1__32__0008e8b4[35];
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
    g_logwork_file = (FILE *)fopen(tmp,(char *)&DAT_0008e568);
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Log work open file %s",tmp);
      _applog(3,tmp42,false);
    }
    if (g_logwork_asicnum == 1) {
      sprintf(tmp,"%s%02d.txt",opt_logwork_path,1);
      g_logwork_files[0] = (FILE *)fopen(tmp,(char *)&DAT_0008e568);
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
        pFVar11 = fopen(tmp,(char *)&DAT_0008e568);
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
        pFVar11 = fopen(tmp,(char *)&DAT_0008e568);
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
        tmp42[0] = s_Error_in_configuration_file__par_0008ea14[0];
        tmp42[1] = s_Error_in_configuration_file__par_0008ea14[1];
        tmp42[2] = s_Error_in_configuration_file__par_0008ea14[2];
        tmp42[3] = s_Error_in_configuration_file__par_0008ea14[3];
        tmp42[4] = s_Error_in_configuration_file__par_0008ea14[4];
        tmp42[5] = s_Error_in_configuration_file__par_0008ea14[5];
        tmp42[6] = s_Error_in_configuration_file__par_0008ea14[6];
        tmp42[7] = s_Error_in_configuration_file__par_0008ea14[7];
        tmp42[8] = s_Error_in_configuration_file__par_0008ea14[8];
        tmp42[9] = s_Error_in_configuration_file__par_0008ea14[9];
        tmp42[10] = s_Error_in_configuration_file__par_0008ea14[10];
        tmp42[11] = s_Error_in_configuration_file__par_0008ea14[11];
        tmp42[12] = s_Error_in_configuration_file__par_0008ea14[12];
        tmp42[13] = s_Error_in_configuration_file__par_0008ea14[13];
        tmp42[14] = s_Error_in_configuration_file__par_0008ea14[14];
        tmp42[15] = s_Error_in_configuration_file__par_0008ea14[15];
        tmp42[16] = s_Error_in_configuration_file__par_0008ea14[16];
        tmp42[17] = s_Error_in_configuration_file__par_0008ea14[17];
        tmp42[18] = s_Error_in_configuration_file__par_0008ea14[18];
        tmp42[19] = s_Error_in_configuration_file__par_0008ea14[19];
        tmp42[20] = s_Error_in_configuration_file__par_0008ea14[20];
        tmp42[21] = s_Error_in_configuration_file__par_0008ea14[21];
        tmp42[22] = s_Error_in_configuration_file__par_0008ea14[22];
        tmp42[23] = s_Error_in_configuration_file__par_0008ea14[23];
        tmp42[24] = s_Error_in_configuration_file__par_0008ea14[24];
        tmp42[25] = s_Error_in_configuration_file__par_0008ea14[25];
        tmp42[26] = s_Error_in_configuration_file__par_0008ea14[26];
        tmp42[27] = s_Error_in_configuration_file__par_0008ea14[27];
        tmp42[28] = s_Error_in_configuration_file__par_0008ea14[28];
        tmp42[29] = s_Error_in_configuration_file__par_0008ea14[29];
        tmp42[30] = s_Error_in_configuration_file__par_0008ea14[30];
        tmp42[31] = s_Error_in_configuration_file__par_0008ea14[31];
        tmp42[32] = s_Error_in_configuration_file__par_0008ea14[32];
        tmp42[33] = s_Error_in_configuration_file__par_0008ea14[33];
        tmp42[34] = s_Error_in_configuration_file__par_0008ea14[34];
        tmp42[35] = s_Error_in_configuration_file__par_0008ea14[35];
        tmp42[36] = s_Error_in_configuration_file__par_0008ea14[36];
        tmp42[37] = s_Error_in_configuration_file__par_0008ea14[37];
        tmp42[38] = s_Error_in_configuration_file__par_0008ea14[38];
        tmp42[39] = s_Error_in_configuration_file__par_0008ea14[39];
        tmp42[40] = s_Error_in_configuration_file__par_0008ea14[40];
        tmp42[41] = s_Error_in_configuration_file__par_0008ea14[41];
        tmp42[42] = s_Error_in_configuration_file__par_0008ea14[42];
        tmp42[43] = s_Error_in_configuration_file__par_0008ea14[43];
        tmp42._44_3_ = (undefined3)ram0x0008ea40;
        _applog(4,tmp42,false);
      }
      if ((use_curses != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        tmp42[0] = s_Start_cgminer_with__T_to_see_wha_0008ea44[0];
        tmp42[1] = s_Start_cgminer_with__T_to_see_wha_0008ea44[1];
        tmp42[2] = s_Start_cgminer_with__T_to_see_wha_0008ea44[2];
        tmp42[3] = s_Start_cgminer_with__T_to_see_wha_0008ea44[3];
        tmp42[4] = s_Start_cgminer_with__T_to_see_wha_0008ea44[4];
        tmp42[5] = s_Start_cgminer_with__T_to_see_wha_0008ea44[5];
        tmp42[6] = s_Start_cgminer_with__T_to_see_wha_0008ea44[6];
        tmp42[7] = s_Start_cgminer_with__T_to_see_wha_0008ea44[7];
        tmp42[8] = s_Start_cgminer_with__T_to_see_wha_0008ea44[8];
        tmp42[9] = s_Start_cgminer_with__T_to_see_wha_0008ea44[9];
        tmp42[10] = s_Start_cgminer_with__T_to_see_wha_0008ea44[10];
        tmp42[11] = s_Start_cgminer_with__T_to_see_wha_0008ea44[11];
        tmp42[12] = s_Start_cgminer_with__T_to_see_wha_0008ea44[12];
        tmp42[13] = s_Start_cgminer_with__T_to_see_wha_0008ea44[13];
        tmp42[14] = s_Start_cgminer_with__T_to_see_wha_0008ea44[14];
        tmp42[15] = s_Start_cgminer_with__T_to_see_wha_0008ea44[15];
        tmp42[16] = s_Start_cgminer_with__T_to_see_wha_0008ea44[16];
        tmp42[17] = s_Start_cgminer_with__T_to_see_wha_0008ea44[17];
        tmp42[18] = s_Start_cgminer_with__T_to_see_wha_0008ea44[18];
        tmp42[19] = s_Start_cgminer_with__T_to_see_wha_0008ea44[19];
        tmp42[20] = s_Start_cgminer_with__T_to_see_wha_0008ea44[20];
        tmp42[21] = s_Start_cgminer_with__T_to_see_wha_0008ea44[21];
        tmp42[22] = s_Start_cgminer_with__T_to_see_wha_0008ea44[22];
        tmp42[23] = s_Start_cgminer_with__T_to_see_wha_0008ea44[23];
        tmp42[24] = s_Start_cgminer_with__T_to_see_wha_0008ea44[24];
        tmp42[25] = s_Start_cgminer_with__T_to_see_wha_0008ea44[25];
        tmp42[26] = s_Start_cgminer_with__T_to_see_wha_0008ea44[26];
        tmp42[27] = s_Start_cgminer_with__T_to_see_wha_0008ea44[27];
        tmp42[28] = s_Start_cgminer_with__T_to_see_wha_0008ea44[28];
        tmp42[29] = s_Start_cgminer_with__T_to_see_wha_0008ea44[29];
        tmp42[30] = s_Start_cgminer_with__T_to_see_wha_0008ea44[30];
        tmp42[31] = s_Start_cgminer_with__T_to_see_wha_0008ea44[31];
        tmp42[32] = s_Start_cgminer_with__T_to_see_wha_0008ea44[32];
        tmp42[33] = s_Start_cgminer_with__T_to_see_wha_0008ea44[33];
        tmp42[34] = s_Start_cgminer_with__T_to_see_wha_0008ea44[34];
        tmp42[35] = s_Start_cgminer_with__T_to_see_wha_0008ea44[35];
        tmp42[36] = s_Start_cgminer_with__T_to_see_wha_0008ea44[36];
        tmp42[37] = s_Start_cgminer_with__T_to_see_wha_0008ea44[37];
        tmp42[38] = s_Start_cgminer_with__T_to_see_wha_0008ea44[38];
        tmp42[39] = s_Start_cgminer_with__T_to_see_wha_0008ea44[39];
        tmp42[40] = s_Start_cgminer_with__T_to_see_wha_0008ea44[40];
        tmp42[41] = s_Start_cgminer_with__T_to_see_wha_0008ea44[41];
        tmp42[42] = s_Start_cgminer_with__T_to_see_wha_0008ea44[42];
        tmp42[43] = s_Start_cgminer_with__T_to_see_wha_0008ea44[43];
        tmp42[44] = s_Start_cgminer_with__T_to_see_wha_0008ea44[44];
        tmp42[45] = s_Start_cgminer_with__T_to_see_wha_0008ea44[45];
        tmp42[46] = s_Start_cgminer_with__T_to_see_wha_0008ea44[46];
        tmp42[47] = s_Start_cgminer_with__T_to_see_wha_0008ea44[47];
        tmp42[48] = (char)(short)ram0x0008ea74;
        tmp42[49] = (char)((ushort)(short)ram0x0008ea74 >> 8);
        _applog(4,tmp42,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Fatal_JSON_error_in_configuratio_0008e9c4[0];
        tmp42[1] = s_Fatal_JSON_error_in_configuratio_0008e9c4[1];
        tmp42[2] = s_Fatal_JSON_error_in_configuratio_0008e9c4[2];
        tmp42[3] = s_Fatal_JSON_error_in_configuratio_0008e9c4[3];
        tmp42[4] = s_Fatal_JSON_error_in_configuratio_0008e9c4[4];
        tmp42[5] = s_Fatal_JSON_error_in_configuratio_0008e9c4[5];
        tmp42[6] = s_Fatal_JSON_error_in_configuratio_0008e9c4[6];
        tmp42[7] = s_Fatal_JSON_error_in_configuratio_0008e9c4[7];
        tmp42[8] = s_Fatal_JSON_error_in_configuratio_0008e9c4[8];
        tmp42[9] = s_Fatal_JSON_error_in_configuratio_0008e9c4[9];
        tmp42[10] = s_Fatal_JSON_error_in_configuratio_0008e9c4[10];
        tmp42[11] = s_Fatal_JSON_error_in_configuratio_0008e9c4[11];
        tmp42[12] = s_Fatal_JSON_error_in_configuratio_0008e9c4[12];
        tmp42[13] = s_Fatal_JSON_error_in_configuratio_0008e9c4[13];
        tmp42[14] = s_Fatal_JSON_error_in_configuratio_0008e9c4[14];
        tmp42[15] = s_Fatal_JSON_error_in_configuratio_0008e9c4[15];
        tmp42[16] = s_Fatal_JSON_error_in_configuratio_0008e9c4[16];
        tmp42[17] = s_Fatal_JSON_error_in_configuratio_0008e9c4[17];
        tmp42[18] = s_Fatal_JSON_error_in_configuratio_0008e9c4[18];
        tmp42[19] = s_Fatal_JSON_error_in_configuratio_0008e9c4[19];
        tmp42[20] = s_Fatal_JSON_error_in_configuratio_0008e9c4[20];
        tmp42[21] = s_Fatal_JSON_error_in_configuratio_0008e9c4[21];
        tmp42[22] = s_Fatal_JSON_error_in_configuratio_0008e9c4[22];
        tmp42[23] = s_Fatal_JSON_error_in_configuratio_0008e9c4[23];
        tmp42[24] = s_Fatal_JSON_error_in_configuratio_0008e9c4[24];
        tmp42[25] = s_Fatal_JSON_error_in_configuratio_0008e9c4[25];
        tmp42[26] = s_Fatal_JSON_error_in_configuratio_0008e9c4[26];
        tmp42[27] = s_Fatal_JSON_error_in_configuratio_0008e9c4[27];
        tmp42[28] = s_Fatal_JSON_error_in_configuratio_0008e9c4[28];
        tmp42[29] = s_Fatal_JSON_error_in_configuratio_0008e9c4[29];
        tmp42[30] = s_Fatal_JSON_error_in_configuratio_0008e9c4[30];
        tmp42[31] = s_Fatal_JSON_error_in_configuratio_0008e9c4[31];
        tmp42[32] = s_Fatal_JSON_error_in_configuratio_0008e9c4[32];
        tmp42[33] = s_Fatal_JSON_error_in_configuratio_0008e9c4[33];
        tmp42[34] = s_Fatal_JSON_error_in_configuratio_0008e9c4[34];
        tmp42[35] = s_Fatal_JSON_error_in_configuratio_0008e9c4[35];
        tmp42[36] = s_Fatal_JSON_error_in_configuratio_0008e9c4[36];
        tmp42[37] = s_Fatal_JSON_error_in_configuratio_0008e9c4[37];
        tmp42[38] = s_Fatal_JSON_error_in_configuratio_0008e9c4[38];
        tmp42[39] = s_Fatal_JSON_error_in_configuratio_0008e9c4[39];
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Configuration_file_could_not_be_u_0008e9ec[0];
        tmp42[1] = s_Configuration_file_could_not_be_u_0008e9ec[1];
        tmp42[2] = s_Configuration_file_could_not_be_u_0008e9ec[2];
        tmp42[3] = s_Configuration_file_could_not_be_u_0008e9ec[3];
        tmp42[4] = s_Configuration_file_could_not_be_u_0008e9ec[4];
        tmp42[5] = s_Configuration_file_could_not_be_u_0008e9ec[5];
        tmp42[6] = s_Configuration_file_could_not_be_u_0008e9ec[6];
        tmp42[7] = s_Configuration_file_could_not_be_u_0008e9ec[7];
        tmp42[8] = s_Configuration_file_could_not_be_u_0008e9ec[8];
        tmp42[9] = s_Configuration_file_could_not_be_u_0008e9ec[9];
        tmp42[10] = s_Configuration_file_could_not_be_u_0008e9ec[10];
        tmp42[11] = s_Configuration_file_could_not_be_u_0008e9ec[11];
        tmp42[12] = s_Configuration_file_could_not_be_u_0008e9ec[12];
        tmp42[13] = s_Configuration_file_could_not_be_u_0008e9ec[13];
        tmp42[14] = s_Configuration_file_could_not_be_u_0008e9ec[14];
        tmp42[15] = s_Configuration_file_could_not_be_u_0008e9ec[15];
        tmp42[16] = s_Configuration_file_could_not_be_u_0008e9ec[16];
        tmp42[17] = s_Configuration_file_could_not_be_u_0008e9ec[17];
        tmp42[18] = s_Configuration_file_could_not_be_u_0008e9ec[18];
        tmp42[19] = s_Configuration_file_could_not_be_u_0008e9ec[19];
        tmp42[20] = s_Configuration_file_could_not_be_u_0008e9ec[20];
        tmp42[21] = s_Configuration_file_could_not_be_u_0008e9ec[21];
        tmp42[22] = s_Configuration_file_could_not_be_u_0008e9ec[22];
        tmp42[23] = s_Configuration_file_could_not_be_u_0008e9ec[23];
        tmp42[24] = s_Configuration_file_could_not_be_u_0008e9ec[24];
        tmp42[25] = s_Configuration_file_could_not_be_u_0008e9ec[25];
        tmp42[26] = s_Configuration_file_could_not_be_u_0008e9ec[26];
        tmp42[27] = s_Configuration_file_could_not_be_u_0008e9ec[27];
        tmp42[28] = s_Configuration_file_could_not_be_u_0008e9ec[28];
        tmp42[29] = s_Configuration_file_could_not_be_u_0008e9ec[29];
        tmp42[30] = s_Configuration_file_could_not_be_u_0008e9ec[30];
        tmp42[31] = s_Configuration_file_could_not_be_u_0008e9ec[31];
        tmp42[32] = s_Configuration_file_could_not_be_u_0008e9ec[32];
        tmp42[33] = s_Configuration_file_could_not_be_u_0008e9ec[33];
        tmp42[34] = s_Configuration_file_could_not_be_u_0008e9ec[34];
        tmp42[35] = s_Configuration_file_could_not_be_u_0008e9ec[35];
        tmp42[36] = (char)(short)ram0x0008ea10;
        tmp42[37] = (char)((ushort)(short)ram0x0008ea10 >> 8);
        _applog(4,tmp42,false);
      }
    }
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar25 = opt_kernel_path;
  sVar7 = strlen(opt_kernel_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_0008cd34;
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
  pcVar25 = (char *)0x2e83;
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
      tmp42[0] = s_Devices_detected__0008ea78[0];
      tmp42[1] = s_Devices_detected__0008ea78[1];
      tmp42[2] = s_Devices_detected__0008ea78[2];
      tmp42[3] = s_Devices_detected__0008ea78[3];
      tmp42[4] = s_Devices_detected__0008ea78[4];
      tmp42[5] = s_Devices_detected__0008ea78[5];
      tmp42[6] = s_Devices_detected__0008ea78[6];
      tmp42[7] = s_Devices_detected__0008ea78[7];
      tmp42[8] = s_Devices_detected__0008ea78[8];
      tmp42[9] = s_Devices_detected__0008ea78[9];
      tmp42[10] = s_Devices_detected__0008ea78[10];
      tmp42[11] = s_Devices_detected__0008ea78[11];
      tmp42[12] = s_Devices_detected__0008ea78[12];
      tmp42[13] = s_Devices_detected__0008ea78[13];
      tmp42[14] = s_Devices_detected__0008ea78[14];
      tmp42[15] = s_Devices_detected__0008ea78[15];
      tmp42[16] = (char)(short)ram0x0008ea88;
      tmp42[17] = (char)((ushort)(short)ram0x0008ea88 >> 8);
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
    tmp42[0] = s_All_devices_disabled__cannot_min_0008eadc[0];
    tmp42[1] = s_All_devices_disabled__cannot_min_0008eadc[1];
    tmp42[2] = s_All_devices_disabled__cannot_min_0008eadc[2];
    tmp42[3] = s_All_devices_disabled__cannot_min_0008eadc[3];
    tmp42[4] = s_All_devices_disabled__cannot_min_0008eadc[4];
    tmp42[5] = s_All_devices_disabled__cannot_min_0008eadc[5];
    tmp42[6] = s_All_devices_disabled__cannot_min_0008eadc[6];
    tmp42[7] = s_All_devices_disabled__cannot_min_0008eadc[7];
    tmp42[8] = s_All_devices_disabled__cannot_min_0008eadc[8];
    tmp42[9] = s_All_devices_disabled__cannot_min_0008eadc[9];
    tmp42[10] = s_All_devices_disabled__cannot_min_0008eadc[10];
    tmp42[11] = s_All_devices_disabled__cannot_min_0008eadc[11];
    tmp42[12] = s_All_devices_disabled__cannot_min_0008eadc[12];
    tmp42[13] = s_All_devices_disabled__cannot_min_0008eadc[13];
    tmp42[14] = s_All_devices_disabled__cannot_min_0008eadc[14];
    tmp42[15] = s_All_devices_disabled__cannot_min_0008eadc[15];
    tmp42[16] = s_All_devices_disabled__cannot_min_0008eadc[16];
    tmp42[17] = s_All_devices_disabled__cannot_min_0008eadc[17];
    tmp42[18] = s_All_devices_disabled__cannot_min_0008eadc[18];
    tmp42[19] = s_All_devices_disabled__cannot_min_0008eadc[19];
    tmp42[20] = s_All_devices_disabled__cannot_min_0008eadc[20];
    tmp42[21] = s_All_devices_disabled__cannot_min_0008eadc[21];
    tmp42[22] = s_All_devices_disabled__cannot_min_0008eadc[22];
    tmp42[23] = s_All_devices_disabled__cannot_min_0008eadc[23];
    tmp42[24] = s_All_devices_disabled__cannot_min_0008eadc[24];
    tmp42[25] = s_All_devices_disabled__cannot_min_0008eadc[25];
    tmp42[26] = s_All_devices_disabled__cannot_min_0008eadc[26];
    tmp42[27] = s_All_devices_disabled__cannot_min_0008eadc[27];
    tmp42[28] = s_All_devices_disabled__cannot_min_0008eadc[28];
    tmp42[29] = s_All_devices_disabled__cannot_min_0008eadc[29];
    tmp42[30] = s_All_devices_disabled__cannot_min_0008eadc[30];
    tmp42[31] = s_All_devices_disabled__cannot_min_0008eadc[31];
    tmp42._32_3_ = (undefined3)ram0x0008eafc;
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
      tmp42[0] = s_Need_to_specify_at_least_one_poo_0008eb00[0];
      tmp42[1] = s_Need_to_specify_at_least_one_poo_0008eb00[1];
      tmp42[2] = s_Need_to_specify_at_least_one_poo_0008eb00[2];
      tmp42[3] = s_Need_to_specify_at_least_one_poo_0008eb00[3];
      tmp42[4] = s_Need_to_specify_at_least_one_poo_0008eb00[4];
      tmp42[5] = s_Need_to_specify_at_least_one_poo_0008eb00[5];
      tmp42[6] = s_Need_to_specify_at_least_one_poo_0008eb00[6];
      tmp42[7] = s_Need_to_specify_at_least_one_poo_0008eb00[7];
      tmp42[8] = s_Need_to_specify_at_least_one_poo_0008eb00[8];
      tmp42[9] = s_Need_to_specify_at_least_one_poo_0008eb00[9];
      tmp42[10] = s_Need_to_specify_at_least_one_poo_0008eb00[10];
      tmp42[11] = s_Need_to_specify_at_least_one_poo_0008eb00[11];
      tmp42[12] = s_Need_to_specify_at_least_one_poo_0008eb00[12];
      tmp42[13] = s_Need_to_specify_at_least_one_poo_0008eb00[13];
      tmp42[14] = s_Need_to_specify_at_least_one_poo_0008eb00[14];
      tmp42[15] = s_Need_to_specify_at_least_one_poo_0008eb00[15];
      tmp42[16] = s_Need_to_specify_at_least_one_poo_0008eb00[16];
      tmp42[17] = s_Need_to_specify_at_least_one_poo_0008eb00[17];
      tmp42[18] = s_Need_to_specify_at_least_one_poo_0008eb00[18];
      tmp42[19] = s_Need_to_specify_at_least_one_poo_0008eb00[19];
      tmp42[20] = s_Need_to_specify_at_least_one_poo_0008eb00[20];
      tmp42[21] = s_Need_to_specify_at_least_one_poo_0008eb00[21];
      tmp42[22] = s_Need_to_specify_at_least_one_poo_0008eb00[22];
      tmp42[23] = s_Need_to_specify_at_least_one_poo_0008eb00[23];
      tmp42[24] = s_Need_to_specify_at_least_one_poo_0008eb00[24];
      tmp42[25] = s_Need_to_specify_at_least_one_poo_0008eb00[25];
      tmp42[26] = s_Need_to_specify_at_least_one_poo_0008eb00[26];
      tmp42[27] = s_Need_to_specify_at_least_one_poo_0008eb00[27];
      tmp42[28] = s_Need_to_specify_at_least_one_poo_0008eb00[28];
      tmp42[29] = s_Need_to_specify_at_least_one_poo_0008eb00[29];
      tmp42[30] = s_Need_to_specify_at_least_one_poo_0008eb00[30];
      tmp42[31] = s_Need_to_specify_at_least_one_poo_0008eb00[31];
      tmp42[32] = s_Need_to_specify_at_least_one_poo_0008eb00[32];
      tmp42[33] = s_Need_to_specify_at_least_one_poo_0008eb00[33];
      tmp42[34] = s_Need_to_specify_at_least_one_poo_0008eb00[34];
      tmp42[35] = s_Need_to_specify_at_least_one_poo_0008eb00[35];
      tmp42[36] = s_Need_to_specify_at_least_one_poo_0008eb00[36];
      tmp42[37] = s_Need_to_specify_at_least_one_poo_0008eb00[37];
      tmp42[38] = s_Need_to_specify_at_least_one_poo_0008eb00[38];
      tmp42[39] = s_Need_to_specify_at_least_one_poo_0008eb00[39];
      tmp42[40] = (char)(short)ram0x0008eb28;
      tmp42[41] = (char)((ushort)(short)ram0x0008eb28 >> 8);
      _applog(4,tmp42,false);
    }
    tmp42[0] = s_Pool_setup_failed_0008eb2c[0];
    tmp42[1] = s_Pool_setup_failed_0008eb2c[1];
    tmp42[2] = s_Pool_setup_failed_0008eb2c[2];
    tmp42[3] = s_Pool_setup_failed_0008eb2c[3];
    tmp42[4] = s_Pool_setup_failed_0008eb2c[4];
    tmp42[5] = s_Pool_setup_failed_0008eb2c[5];
    tmp42[6] = s_Pool_setup_failed_0008eb2c[6];
    tmp42[7] = s_Pool_setup_failed_0008eb2c[7];
    tmp42[8] = s_Pool_setup_failed_0008eb2c[8];
    tmp42[9] = s_Pool_setup_failed_0008eb2c[9];
    tmp42[10] = s_Pool_setup_failed_0008eb2c[10];
    tmp42[11] = s_Pool_setup_failed_0008eb2c[11];
    tmp42[12] = s_Pool_setup_failed_0008eb2c[12];
    tmp42[13] = s_Pool_setup_failed_0008eb2c[13];
    tmp42[14] = s_Pool_setup_failed_0008eb2c[14];
    tmp42[15] = s_Pool_setup_failed_0008eb2c[15];
    tmp42[16] = (char)(short)ram0x0008eb3c;
    tmp42[17] = (char)((ushort)(short)ram0x0008eb3c >> 8);
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
      size = sVar12 + sVar7 + 2;
      pcVar25 = (char *)_cgmalloc(size,"cgminer.c","main",0x2ef0);
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
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,"cgminer.c","main",0x2f01);
  for (i = 0; i < mining_threads; i = i + 1) {
    pptVar13 = mining_thr + i;
    ptVar14 = (thr_info *)_cgcalloc(1,0x40,"cgminer.c","main",0x2f05);
    *pptVar13 = ptVar14;
  }
  k = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar22 = devices[i];
    pptVar13 = (thr_info **)_cgmalloc((pcVar22->threads + 1) * 4,"cgminer.c","main",0x2f0e);
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
        iVar5 = thr_info_create(ptVar14,(pthread_attr_t *)0x0,miner_thread + 1,ptVar14);
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
          _cgsem_post(&ptVar14->sem,"cgminer.c","main",0x2f2a);
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
      tmp42[0] = s_Probing_for_an_alive_pool_0008eb88[0];
      tmp42[1] = s_Probing_for_an_alive_pool_0008eb88[1];
      tmp42[2] = s_Probing_for_an_alive_pool_0008eb88[2];
      tmp42[3] = s_Probing_for_an_alive_pool_0008eb88[3];
      tmp42[4] = s_Probing_for_an_alive_pool_0008eb88[4];
      tmp42[5] = s_Probing_for_an_alive_pool_0008eb88[5];
      tmp42[6] = s_Probing_for_an_alive_pool_0008eb88[6];
      tmp42[7] = s_Probing_for_an_alive_pool_0008eb88[7];
      tmp42[8] = s_Probing_for_an_alive_pool_0008eb88[8];
      tmp42[9] = s_Probing_for_an_alive_pool_0008eb88[9];
      tmp42[10] = s_Probing_for_an_alive_pool_0008eb88[10];
      tmp42[11] = s_Probing_for_an_alive_pool_0008eb88[11];
      tmp42[12] = s_Probing_for_an_alive_pool_0008eb88[12];
      tmp42[13] = s_Probing_for_an_alive_pool_0008eb88[13];
      tmp42[14] = s_Probing_for_an_alive_pool_0008eb88[14];
      tmp42[15] = s_Probing_for_an_alive_pool_0008eb88[15];
      tmp42[16] = s_Probing_for_an_alive_pool_0008eb88[16];
      tmp42[17] = s_Probing_for_an_alive_pool_0008eb88[17];
      tmp42[18] = s_Probing_for_an_alive_pool_0008eb88[18];
      tmp42[19] = s_Probing_for_an_alive_pool_0008eb88[19];
      tmp42[20] = s_Probing_for_an_alive_pool_0008eb88[20];
      tmp42[21] = s_Probing_for_an_alive_pool_0008eb88[21];
      tmp42[22] = s_Probing_for_an_alive_pool_0008eb88[22];
      tmp42[23] = s_Probing_for_an_alive_pool_0008eb88[23];
      tmp42[24] = (char)(short)ram0x0008eba0;
      tmp42[25] = (char)((ushort)(short)ram0x0008eba0 >> 8);
      _applog(5,tmp42,false);
    }
    probe_pools();
    do {
      sleep(1);
      slept = slept + 1;
      if (pools_active == true) break;
    } while (slept < 0xb4);
    do {
      if (pools_active == true) goto begin_bench;
      if (!bVar1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_No_servers_were_found_that_could_0008eba4[0];
          tmp42[1] = s_No_servers_were_found_that_could_0008eba4[1];
          tmp42[2] = s_No_servers_were_found_that_could_0008eba4[2];
          tmp42[3] = s_No_servers_were_found_that_could_0008eba4[3];
          tmp42[4] = s_No_servers_were_found_that_could_0008eba4[4];
          tmp42[5] = s_No_servers_were_found_that_could_0008eba4[5];
          tmp42[6] = s_No_servers_were_found_that_could_0008eba4[6];
          tmp42[7] = s_No_servers_were_found_that_could_0008eba4[7];
          tmp42[8] = s_No_servers_were_found_that_could_0008eba4[8];
          tmp42[9] = s_No_servers_were_found_that_could_0008eba4[9];
          tmp42[10] = s_No_servers_were_found_that_could_0008eba4[10];
          tmp42[11] = s_No_servers_were_found_that_could_0008eba4[11];
          tmp42[12] = s_No_servers_were_found_that_could_0008eba4[12];
          tmp42[13] = s_No_servers_were_found_that_could_0008eba4[13];
          tmp42[14] = s_No_servers_were_found_that_could_0008eba4[14];
          tmp42[15] = s_No_servers_were_found_that_could_0008eba4[15];
          tmp42[16] = s_No_servers_were_found_that_could_0008eba4[16];
          tmp42[17] = s_No_servers_were_found_that_could_0008eba4[17];
          tmp42[18] = s_No_servers_were_found_that_could_0008eba4[18];
          tmp42[19] = s_No_servers_were_found_that_could_0008eba4[19];
          tmp42[20] = s_No_servers_were_found_that_could_0008eba4[20];
          tmp42[21] = s_No_servers_were_found_that_could_0008eba4[21];
          tmp42[22] = s_No_servers_were_found_that_could_0008eba4[22];
          tmp42[23] = s_No_servers_were_found_that_could_0008eba4[23];
          tmp42[24] = s_No_servers_were_found_that_could_0008eba4[24];
          tmp42[25] = s_No_servers_were_found_that_could_0008eba4[25];
          tmp42[26] = s_No_servers_were_found_that_could_0008eba4[26];
          tmp42[27] = s_No_servers_were_found_that_could_0008eba4[27];
          tmp42[28] = s_No_servers_were_found_that_could_0008eba4[28];
          tmp42[29] = s_No_servers_were_found_that_could_0008eba4[29];
          tmp42[30] = s_No_servers_were_found_that_could_0008eba4[30];
          tmp42[31] = s_No_servers_were_found_that_could_0008eba4[31];
          tmp42[32] = s_No_servers_were_found_that_could_0008eba4[32];
          tmp42[33] = s_No_servers_were_found_that_could_0008eba4[33];
          tmp42[34] = s_No_servers_were_found_that_could_0008eba4[34];
          tmp42[35] = s_No_servers_were_found_that_could_0008eba4[35];
          tmp42[36] = s_No_servers_were_found_that_could_0008eba4[36];
          tmp42[37] = s_No_servers_were_found_that_could_0008eba4[37];
          tmp42[38] = s_No_servers_were_found_that_could_0008eba4[38];
          tmp42[39] = s_No_servers_were_found_that_could_0008eba4[39];
          tmp42[40] = s_No_servers_were_found_that_could_0008eba4[40];
          tmp42[41] = s_No_servers_were_found_that_could_0008eba4[41];
          tmp42[42] = s_No_servers_were_found_that_could_0008eba4[42];
          tmp42[43] = s_No_servers_were_found_that_could_0008eba4[43];
          tmp42[44] = s_No_servers_were_found_that_could_0008eba4[44];
          tmp42[45] = s_No_servers_were_found_that_could_0008eba4[45];
          tmp42[46] = s_No_servers_were_found_that_could_0008eba4[46];
          tmp42[47] = s_No_servers_were_found_that_could_0008eba4[47];
          tmp42[48] = s_No_servers_were_found_that_could_0008eba4[48];
          tmp42[49] = s_No_servers_were_found_that_could_0008eba4[49];
          tmp42[50] = s_No_servers_were_found_that_could_0008eba4[50];
          tmp42[51] = s_No_servers_were_found_that_could_0008eba4[51];
          tmp42[52] = s_No_servers_were_found_that_could_0008eba4[52];
          tmp42[53] = s_No_servers_were_found_that_could_0008eba4[53];
          tmp42[54] = s_No_servers_were_found_that_could_0008eba4[54];
          tmp42[55] = s_No_servers_were_found_that_could_0008eba4[55];
          tmp42._56_3_ = (undefined3)ram0x0008ebdc;
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
    } while (use_curses == true);
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      tmp42[0] = s_no_valid_pool_enabled__keep_runn_0008ed04[0];
      tmp42[1] = s_no_valid_pool_enabled__keep_runn_0008ed04[1];
      tmp42[2] = s_no_valid_pool_enabled__keep_runn_0008ed04[2];
      tmp42[3] = s_no_valid_pool_enabled__keep_runn_0008ed04[3];
      tmp42[4] = s_no_valid_pool_enabled__keep_runn_0008ed04[4];
      tmp42[5] = s_no_valid_pool_enabled__keep_runn_0008ed04[5];
      tmp42[6] = s_no_valid_pool_enabled__keep_runn_0008ed04[6];
      tmp42[7] = s_no_valid_pool_enabled__keep_runn_0008ed04[7];
      tmp42[8] = s_no_valid_pool_enabled__keep_runn_0008ed04[8];
      tmp42[9] = s_no_valid_pool_enabled__keep_runn_0008ed04[9];
      tmp42[10] = s_no_valid_pool_enabled__keep_runn_0008ed04[10];
      tmp42[11] = s_no_valid_pool_enabled__keep_runn_0008ed04[11];
      tmp42[12] = s_no_valid_pool_enabled__keep_runn_0008ed04[12];
      tmp42[13] = s_no_valid_pool_enabled__keep_runn_0008ed04[13];
      tmp42[14] = s_no_valid_pool_enabled__keep_runn_0008ed04[14];
      tmp42[15] = s_no_valid_pool_enabled__keep_runn_0008ed04[15];
      tmp42[16] = s_no_valid_pool_enabled__keep_runn_0008ed04[16];
      tmp42[17] = s_no_valid_pool_enabled__keep_runn_0008ed04[17];
      tmp42[18] = s_no_valid_pool_enabled__keep_runn_0008ed04[18];
      tmp42[19] = s_no_valid_pool_enabled__keep_runn_0008ed04[19];
      tmp42[20] = s_no_valid_pool_enabled__keep_runn_0008ed04[20];
      tmp42[21] = s_no_valid_pool_enabled__keep_runn_0008ed04[21];
      tmp42[22] = s_no_valid_pool_enabled__keep_runn_0008ed04[22];
      tmp42[23] = s_no_valid_pool_enabled__keep_runn_0008ed04[23];
      tmp42[24] = s_no_valid_pool_enabled__keep_runn_0008ed04[24];
      tmp42[25] = s_no_valid_pool_enabled__keep_runn_0008ed04[25];
      tmp42[26] = s_no_valid_pool_enabled__keep_runn_0008ed04[26];
      tmp42[27] = s_no_valid_pool_enabled__keep_runn_0008ed04[27];
      tmp42[28] = s_no_valid_pool_enabled__keep_runn_0008ed04[28];
      tmp42[29] = s_no_valid_pool_enabled__keep_runn_0008ed04[29];
      tmp42[30] = s_no_valid_pool_enabled__keep_runn_0008ed04[30];
      tmp42[31] = s_no_valid_pool_enabled__keep_runn_0008ed04[31];
      tmp42[32] = s_no_valid_pool_enabled__keep_runn_0008ed04[32];
      tmp42[33] = s_no_valid_pool_enabled__keep_runn_0008ed04[33];
      tmp42[34] = s_no_valid_pool_enabled__keep_runn_0008ed04[34];
      tmp42[35] = s_no_valid_pool_enabled__keep_runn_0008ed04[35];
      tmp42[36] = s_no_valid_pool_enabled__keep_runn_0008ed04[36];
      tmp42[37] = s_no_valid_pool_enabled__keep_runn_0008ed04[37];
      tmp42[38] = s_no_valid_pool_enabled__keep_runn_0008ed04[38];
      tmp42[39] = s_no_valid_pool_enabled__keep_runn_0008ed04[39];
      tmp42[40] = s_no_valid_pool_enabled__keep_runn_0008ed04[40];
      tmp42[41] = s_no_valid_pool_enabled__keep_runn_0008ed04[41];
      tmp42[42] = s_no_valid_pool_enabled__keep_runn_0008ed04[42];
      tmp42[43] = s_no_valid_pool_enabled__keep_runn_0008ed04[43];
      tmp42[44] = s_no_valid_pool_enabled__keep_runn_0008ed04[44];
      tmp42[45] = s_no_valid_pool_enabled__keep_runn_0008ed04[45];
      tmp42[46] = s_no_valid_pool_enabled__keep_runn_0008ed04[46];
      tmp42[47] = s_no_valid_pool_enabled__keep_runn_0008ed04[47];
      tmp42[48] = s_no_valid_pool_enabled__keep_runn_0008ed04[48];
      tmp42[49] = s_no_valid_pool_enabled__keep_runn_0008ed04[49];
      tmp42[50] = s_no_valid_pool_enabled__keep_runn_0008ed04[50];
      tmp42[51] = s_no_valid_pool_enabled__keep_runn_0008ed04[51];
      tmp42[52] = s_no_valid_pool_enabled__keep_runn_0008ed04[52];
      tmp42[53] = s_no_valid_pool_enabled__keep_runn_0008ed04[53];
      tmp42[54] = s_no_valid_pool_enabled__keep_runn_0008ed04[54];
      tmp42[55] = s_no_valid_pool_enabled__keep_runn_0008ed04[55];
      tmp42[56] = s_no_valid_pool_enabled__keep_runn_0008ed04[56];
      tmp42[57] = s_no_valid_pool_enabled__keep_runn_0008ed04[57];
      tmp42[58] = s_no_valid_pool_enabled__keep_runn_0008ed04[58];
      tmp42[59] = s_no_valid_pool_enabled__keep_runn_0008ed04[59];
      tmp42[60] = (char)ram0x0008ed40;
      _applog(3,tmp42,false);
    }
  }
begin_bench:
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
    uVar24 = *(undefined4 *)((int)&pcVar22->total_mhashes + 4);
    *(undefined4 *)&pcVar22->rolling = *(undefined4 *)&pcVar22->total_mhashes;
    *(undefined4 *)((int)&pcVar22->rolling + 4) = uVar24;
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
  iVar5 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,watchpool_thread + 1,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchpool_thread_create_failed_0008ed44[0];
    tmp42[1] = s_watchpool_thread_create_failed_0008ed44[1];
    tmp42[2] = s_watchpool_thread_create_failed_0008ed44[2];
    tmp42[3] = s_watchpool_thread_create_failed_0008ed44[3];
    tmp42[4] = s_watchpool_thread_create_failed_0008ed44[4];
    tmp42[5] = s_watchpool_thread_create_failed_0008ed44[5];
    tmp42[6] = s_watchpool_thread_create_failed_0008ed44[6];
    tmp42[7] = s_watchpool_thread_create_failed_0008ed44[7];
    tmp42[8] = s_watchpool_thread_create_failed_0008ed44[8];
    tmp42[9] = s_watchpool_thread_create_failed_0008ed44[9];
    tmp42[10] = s_watchpool_thread_create_failed_0008ed44[10];
    tmp42[11] = s_watchpool_thread_create_failed_0008ed44[11];
    tmp42[12] = s_watchpool_thread_create_failed_0008ed44[12];
    tmp42[13] = s_watchpool_thread_create_failed_0008ed44[13];
    tmp42[14] = s_watchpool_thread_create_failed_0008ed44[14];
    tmp42[15] = s_watchpool_thread_create_failed_0008ed44[15];
    tmp42[16] = s_watchpool_thread_create_failed_0008ed44[16];
    tmp42[17] = s_watchpool_thread_create_failed_0008ed44[17];
    tmp42[18] = s_watchpool_thread_create_failed_0008ed44[18];
    tmp42[19] = s_watchpool_thread_create_failed_0008ed44[19];
    tmp42[20] = s_watchpool_thread_create_failed_0008ed44[20];
    tmp42[21] = s_watchpool_thread_create_failed_0008ed44[21];
    tmp42[22] = s_watchpool_thread_create_failed_0008ed44[22];
    tmp42[23] = s_watchpool_thread_create_failed_0008ed44[23];
    tmp42[24] = s_watchpool_thread_create_failed_0008ed44[24];
    tmp42[25] = s_watchpool_thread_create_failed_0008ed44[25];
    tmp42[26] = s_watchpool_thread_create_failed_0008ed44[26];
    tmp42[27] = s_watchpool_thread_create_failed_0008ed44[27];
    tmp42._28_3_ = (undefined3)ram0x0008ed60;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[2].pth);
  ptVar14 = control_thr;
  watchdog_thr_id = 3;
  iVar5 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,watchdog_thread + 1,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchdog_thread_create_failed_0008ed64[0];
    tmp42[1] = s_watchdog_thread_create_failed_0008ed64[1];
    tmp42[2] = s_watchdog_thread_create_failed_0008ed64[2];
    tmp42[3] = s_watchdog_thread_create_failed_0008ed64[3];
    tmp42[4] = s_watchdog_thread_create_failed_0008ed64[4];
    tmp42[5] = s_watchdog_thread_create_failed_0008ed64[5];
    tmp42[6] = s_watchdog_thread_create_failed_0008ed64[6];
    tmp42[7] = s_watchdog_thread_create_failed_0008ed64[7];
    tmp42[8] = s_watchdog_thread_create_failed_0008ed64[8];
    tmp42[9] = s_watchdog_thread_create_failed_0008ed64[9];
    tmp42[10] = s_watchdog_thread_create_failed_0008ed64[10];
    tmp42[11] = s_watchdog_thread_create_failed_0008ed64[11];
    tmp42[12] = s_watchdog_thread_create_failed_0008ed64[12];
    tmp42[13] = s_watchdog_thread_create_failed_0008ed64[13];
    tmp42[14] = s_watchdog_thread_create_failed_0008ed64[14];
    tmp42[15] = s_watchdog_thread_create_failed_0008ed64[15];
    tmp42[16] = s_watchdog_thread_create_failed_0008ed64[16];
    tmp42[17] = s_watchdog_thread_create_failed_0008ed64[17];
    tmp42[18] = s_watchdog_thread_create_failed_0008ed64[18];
    tmp42[19] = s_watchdog_thread_create_failed_0008ed64[19];
    tmp42[20] = s_watchdog_thread_create_failed_0008ed64[20];
    tmp42[21] = s_watchdog_thread_create_failed_0008ed64[21];
    tmp42[22] = s_watchdog_thread_create_failed_0008ed64[22];
    tmp42[23] = s_watchdog_thread_create_failed_0008ed64[23];
    tmp42[24] = s_watchdog_thread_create_failed_0008ed64[24];
    tmp42[25] = s_watchdog_thread_create_failed_0008ed64[25];
    tmp42[26] = s_watchdog_thread_create_failed_0008ed64[26];
    tmp42[27] = s_watchdog_thread_create_failed_0008ed64[27];
    tmp42[28] = (char)(short)ram0x0008ed80;
    tmp42[29] = (char)((ushort)(short)ram0x0008ed80 >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[3].pth);
  api_thr_id = 5;
  iVar5 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,api_thread + 1,control_thr + 5);
  if (iVar5 != 0) {
    tmp42[0] = s_API_thread_create_failed_0008ed84[0];
    tmp42[1] = s_API_thread_create_failed_0008ed84[1];
    tmp42[2] = s_API_thread_create_failed_0008ed84[2];
    tmp42[3] = s_API_thread_create_failed_0008ed84[3];
    tmp42[4] = s_API_thread_create_failed_0008ed84[4];
    tmp42[5] = s_API_thread_create_failed_0008ed84[5];
    tmp42[6] = s_API_thread_create_failed_0008ed84[6];
    tmp42[7] = s_API_thread_create_failed_0008ed84[7];
    tmp42[8] = s_API_thread_create_failed_0008ed84[8];
    tmp42[9] = s_API_thread_create_failed_0008ed84[9];
    tmp42[10] = s_API_thread_create_failed_0008ed84[10];
    tmp42[11] = s_API_thread_create_failed_0008ed84[11];
    tmp42[12] = s_API_thread_create_failed_0008ed84[12];
    tmp42[13] = s_API_thread_create_failed_0008ed84[13];
    tmp42[14] = s_API_thread_create_failed_0008ed84[14];
    tmp42[15] = s_API_thread_create_failed_0008ed84[15];
    tmp42[16] = s_API_thread_create_failed_0008ed84[16];
    tmp42[17] = s_API_thread_create_failed_0008ed84[17];
    tmp42[18] = s_API_thread_create_failed_0008ed84[18];
    tmp42[19] = s_API_thread_create_failed_0008ed84[19];
    tmp42[20] = s_API_thread_create_failed_0008ed84[20];
    tmp42[21] = s_API_thread_create_failed_0008ed84[21];
    tmp42[22] = s_API_thread_create_failed_0008ed84[22];
    tmp42[23] = s_API_thread_create_failed_0008ed84[23];
    tmp42[24] = (char)ram0x0008ed9c;
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
    iVar5 = max_queue;
    if (opt_work_update != false) {
      signal_work_update();
    }
    opt_work_update = false;
    _mutex_lock(stgd_lock,"cgminer.c","main",0x2fdf);
    ts = __total_staged();
    if (iVar5 < ts) {
      work_filled = true;
      pthread_cond_wait((pthread_cond_t *)&gws_cond,(pthread_mutex_t *)stgd_lock);
      ts = __total_staged();
    }
    _mutex_unlock(stgd_lock,"cgminer.c","main",0x2fea);
    if (iVar5 < ts) {
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
      if (ppVar10->has_stratum == false) {
        if (opt_benchfile == (char *)0x0) {
          if (opt_benchmark != false) {
            get_benchmark_work(work);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42[0] = s_Generated_benchmark_work_0008ee08[0];
              tmp42[1] = s_Generated_benchmark_work_0008ee08[1];
              tmp42[2] = s_Generated_benchmark_work_0008ee08[2];
              tmp42[3] = s_Generated_benchmark_work_0008ee08[3];
              tmp42[4] = s_Generated_benchmark_work_0008ee08[4];
              tmp42[5] = s_Generated_benchmark_work_0008ee08[5];
              tmp42[6] = s_Generated_benchmark_work_0008ee08[6];
              tmp42[7] = s_Generated_benchmark_work_0008ee08[7];
              tmp42[8] = s_Generated_benchmark_work_0008ee08[8];
              tmp42[9] = s_Generated_benchmark_work_0008ee08[9];
              tmp42[10] = s_Generated_benchmark_work_0008ee08[10];
              tmp42[11] = s_Generated_benchmark_work_0008ee08[11];
              tmp42[12] = s_Generated_benchmark_work_0008ee08[12];
              tmp42[13] = s_Generated_benchmark_work_0008ee08[13];
              tmp42[14] = s_Generated_benchmark_work_0008ee08[14];
              tmp42[15] = s_Generated_benchmark_work_0008ee08[15];
              tmp42[16] = s_Generated_benchmark_work_0008ee08[16];
              tmp42[17] = s_Generated_benchmark_work_0008ee08[17];
              tmp42[18] = s_Generated_benchmark_work_0008ee08[18];
              tmp42[19] = s_Generated_benchmark_work_0008ee08[19];
              tmp42[20] = s_Generated_benchmark_work_0008ee08[20];
              tmp42[21] = s_Generated_benchmark_work_0008ee08[21];
              tmp42[22] = s_Generated_benchmark_work_0008ee08[22];
              tmp42[23] = s_Generated_benchmark_work_0008ee08[23];
              tmp42[24] = (char)ram0x0008ee20;
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
            tmp42[0] = s_Generated_benchfile_work_0008edec[0];
            tmp42[1] = s_Generated_benchfile_work_0008edec[1];
            tmp42[2] = s_Generated_benchfile_work_0008edec[2];
            tmp42[3] = s_Generated_benchfile_work_0008edec[3];
            tmp42[4] = s_Generated_benchfile_work_0008edec[4];
            tmp42[5] = s_Generated_benchfile_work_0008edec[5];
            tmp42[6] = s_Generated_benchfile_work_0008edec[6];
            tmp42[7] = s_Generated_benchfile_work_0008edec[7];
            tmp42[8] = s_Generated_benchfile_work_0008edec[8];
            tmp42[9] = s_Generated_benchfile_work_0008edec[9];
            tmp42[10] = s_Generated_benchfile_work_0008edec[10];
            tmp42[11] = s_Generated_benchfile_work_0008edec[11];
            tmp42[12] = s_Generated_benchfile_work_0008edec[12];
            tmp42[13] = s_Generated_benchfile_work_0008edec[13];
            tmp42[14] = s_Generated_benchfile_work_0008edec[14];
            tmp42[15] = s_Generated_benchfile_work_0008edec[15];
            tmp42[16] = s_Generated_benchfile_work_0008edec[16];
            tmp42[17] = s_Generated_benchfile_work_0008edec[17];
            tmp42[18] = s_Generated_benchfile_work_0008edec[18];
            tmp42[19] = s_Generated_benchfile_work_0008edec[19];
            tmp42[20] = s_Generated_benchfile_work_0008edec[20];
            tmp42[21] = s_Generated_benchfile_work_0008edec[21];
            tmp42[22] = s_Generated_benchfile_work_0008edec[22];
            tmp42[23] = s_Generated_benchfile_work_0008edec[23];
            tmp42[24] = (char)ram0x0008ee04;
            _applog(7,tmp42,false);
          }
          _stage_work(work);
          work = (work *)0x0;
        }
      }
      else {
        gen_stratum_work(ppVar10,work);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Generated_stratum_work_0008edd4[0];
          tmp42[1] = s_Generated_stratum_work_0008edd4[1];
          tmp42[2] = s_Generated_stratum_work_0008edd4[2];
          tmp42[3] = s_Generated_stratum_work_0008edd4[3];
          tmp42[4] = s_Generated_stratum_work_0008edd4[4];
          tmp42[5] = s_Generated_stratum_work_0008edd4[5];
          tmp42[6] = s_Generated_stratum_work_0008edd4[6];
          tmp42[7] = s_Generated_stratum_work_0008edd4[7];
          tmp42[8] = s_Generated_stratum_work_0008edd4[8];
          tmp42[9] = s_Generated_stratum_work_0008edd4[9];
          tmp42[10] = s_Generated_stratum_work_0008edd4[10];
          tmp42[11] = s_Generated_stratum_work_0008edd4[11];
          tmp42[12] = s_Generated_stratum_work_0008edd4[12];
          tmp42[13] = s_Generated_stratum_work_0008edd4[13];
          tmp42[14] = s_Generated_stratum_work_0008edd4[14];
          tmp42[15] = s_Generated_stratum_work_0008edd4[15];
          tmp42[16] = s_Generated_stratum_work_0008edd4[16];
          tmp42[17] = s_Generated_stratum_work_0008edd4[17];
          tmp42[18] = s_Generated_stratum_work_0008edd4[18];
          tmp42[19] = s_Generated_stratum_work_0008edd4[19];
          tmp42._20_3_ = (undefined3)ram0x0008ede8;
          _applog(7,tmp42,false);
        }
        _stage_work(work);
        work = (work *)0x0;
      }
    }
  } while( true );
}

