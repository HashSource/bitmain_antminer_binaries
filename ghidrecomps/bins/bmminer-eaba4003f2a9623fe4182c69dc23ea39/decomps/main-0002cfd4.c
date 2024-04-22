
/* WARNING: Removing unreachable block (ram,0x00030024) */
/* WARNING: Removing unreachable block (ram,0x0003003e) */
/* WARNING: Removing unreachable block (ram,0x0003004c) */
/* WARNING: Removing unreachable block (ram,0x0003005a) */
/* WARNING: Removing unreachable block (ram,0x00030068) */
/* WARNING: Removing unreachable block (ram,0x00030092) */
/* WARNING: Removing unreachable block (ram,0x000300b8) */
/* WARNING: Removing unreachable block (ram,0x000300d2) */
/* WARNING: Removing unreachable block (ram,0x000300e0) */
/* WARNING: Removing unreachable block (ram,0x000300ee) */
/* WARNING: Removing unreachable block (ram,0x000300fc) */
/* WARNING: Removing unreachable block (ram,0x00030126) */
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
  pool *pool_4;
  int max_staged;
  cgpu_info *cgpu_2;
  pool *pool_3;
  pool *pool_2;
  thr_info *thr;
  cgpu_info *cgpu_1;
  size_t siz;
  pool *pool_1;
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
  g_logfile_path._0_4_ = s_bmminer_log_00074cd4._0_4_;
  g_logfile_path._4_4_ = s_bmminer_log_00074cd4._4_4_;
  g_logfile_path._8_4_ = s_bmminer_log_00074cd4._8_4_;
  g_logfile_openflag._0_2_ = DAT_00074ce0;
  g_logfile_openflag[2] = DAT_00074ce2;
  argv_local = argv;
  argc_local = argc;
  lVar4 = sysconf(0x54);
  if (lVar4 == 1) {
    selective_yield = sched_yield;
  }
  initial_args = (char **)_cgmalloc((argc_local + 1) * 4,"cgminer.c","main",0x2ca6);
  for (i = 0; i < argc_local; i = i + 1) {
    ppcVar24 = initial_args + i;
    pcVar25 = strdup(argv_local[i]);
    *ppcVar24 = pcVar25;
  }
  initial_args[argc_local] = (char *)0x0;
  _mutex_init(&hash_lock,"cgminer.c","main",0x2caf);
  _mutex_init(&update_job_lock,"cgminer.c","main",0x2cb0);
  _mutex_init(&console_lock,"cgminer.c","main",0x2cb1);
  _cglock_init(&control_lock,"cgminer.c","main",0x2cb2);
  _mutex_init(&stats_lock,"cgminer.c","main",0x2cb3);
  _mutex_init(&sharelog_lock,"cgminer.c","main",0x2cb4);
  _cglock_init(&ch_lock,"cgminer.c","main",0x2cb5);
  _mutex_init(&sshare_lock,"cgminer.c","main",0x2cb6);
  _rwlock_init(&blk_lock,"cgminer.c","main",0x2cb7);
  _rwlock_init(&netacc_lock,"cgminer.c","main",0x2cb8);
  _rwlock_init(&mining_thr_lock,"cgminer.c","main",0x2cb9);
  _rwlock_init(&devices_lock,"cgminer.c","main",0x2cba);
  _mutex_init(&lp_lock,"cgminer.c","main",0x2cbc);
  iVar5 = pthread_cond_init((pthread_cond_t *)&lp_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_lp_c_00074ce4[35];
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  _mutex_init(&restart_lock,"cgminer.c","main",0x2cc3);
  iVar5 = pthread_cond_init((pthread_cond_t *)&restart_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_rest_00074d08[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_rest_00074d08[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_rest_00074d08[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_rest_00074d08[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_rest_00074d08[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_rest_00074d08[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_rest_00074d08[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_rest_00074d08[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_rest_00074d08[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_rest_00074d08[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_rest_00074d08[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_rest_00074d08[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_rest_00074d08[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_rest_00074d08[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_rest_00074d08[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_rest_00074d08[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_rest_00074d08[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_rest_00074d08[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_rest_00074d08[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_rest_00074d08[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_rest_00074d08[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_rest_00074d08[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_rest_00074d08[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_rest_00074d08[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_rest_00074d08[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_rest_00074d08[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_rest_00074d08[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_rest_00074d08[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_rest_00074d08[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_rest_00074d08[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_rest_00074d08[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_rest_00074d08[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_rest_00074d08[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_rest_00074d08[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_rest_00074d08[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_rest_00074d08[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_rest_00074d08[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_rest_00074d08[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_rest_00074d08[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_rest_00074d08[39];
    tmp42[40] = (char)ram0x00074d30;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  iVar5 = pthread_cond_init((pthread_cond_t *)&gws_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_gws__00074d34[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_gws__00074d34[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_gws__00074d34[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_gws__00074d34[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_gws__00074d34[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_gws__00074d34[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_gws__00074d34[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_gws__00074d34[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_gws__00074d34[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_gws__00074d34[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_gws__00074d34[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_gws__00074d34[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_gws__00074d34[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_gws__00074d34[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_gws__00074d34[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_gws__00074d34[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_gws__00074d34[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_gws__00074d34[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_gws__00074d34[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_gws__00074d34[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_gws__00074d34[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_gws__00074d34[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_gws__00074d34[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_gws__00074d34[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_gws__00074d34[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_gws__00074d34[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_gws__00074d34[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_gws__00074d34[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_gws__00074d34[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_gws__00074d34[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_gws__00074d34[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_gws__00074d34[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_gws__00074d34[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_gws__00074d34[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_gws__00074d34[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_gws__00074d34[35];
    tmp42[36] = (char)ram0x00074d58;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  getq = tq_new();
  if (getq == (thread_q *)0x0) {
    tmp42[0] = s_Failed_to_create_getq_00074d5c[0];
    tmp42[1] = s_Failed_to_create_getq_00074d5c[1];
    tmp42[2] = s_Failed_to_create_getq_00074d5c[2];
    tmp42[3] = s_Failed_to_create_getq_00074d5c[3];
    tmp42[4] = s_Failed_to_create_getq_00074d5c[4];
    tmp42[5] = s_Failed_to_create_getq_00074d5c[5];
    tmp42[6] = s_Failed_to_create_getq_00074d5c[6];
    tmp42[7] = s_Failed_to_create_getq_00074d5c[7];
    tmp42[8] = s_Failed_to_create_getq_00074d5c[8];
    tmp42[9] = s_Failed_to_create_getq_00074d5c[9];
    tmp42[10] = s_Failed_to_create_getq_00074d5c[10];
    tmp42[11] = s_Failed_to_create_getq_00074d5c[11];
    tmp42[12] = s_Failed_to_create_getq_00074d5c[12];
    tmp42[13] = s_Failed_to_create_getq_00074d5c[13];
    tmp42[14] = s_Failed_to_create_getq_00074d5c[14];
    tmp42[15] = s_Failed_to_create_getq_00074d5c[15];
    tmp42[16] = s_Failed_to_create_getq_00074d5c[16];
    tmp42[17] = s_Failed_to_create_getq_00074d5c[17];
    tmp42[18] = s_Failed_to_create_getq_00074d5c[18];
    tmp42[19] = s_Failed_to_create_getq_00074d5c[19];
    tmp42[20] = (char)(short)ram0x00074d70;
    tmp42[21] = (char)((ushort)(short)ram0x00074d70 >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  stgd_lock = &getq->mutex;
  local_a80 = "2.0.0";
  snprintf(packagename,0x100,"%s %s","bmminer");
  handler.__sigaction_handler.sa_handler = sighandler + 1;
  handler.sa_flags = 0;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,(sigaction *)&termhandler);
  sigaction(2,(sigaction *)&handler,(sigaction *)&inthandler);
  sigaction(6,(sigaction *)&handler,(sigaction *)&abrthandler);
  opt_kernel_path = (char *)&uStack_1a78;
  uStack_1a78._0_1_ = s__usr_bin_00074d8c[0];
  uStack_1a78._1_1_ = s__usr_bin_00074d8c[1];
  uStack_1a78._2_1_ = s__usr_bin_00074d8c[2];
  uStack_1a78._3_1_ = s__usr_bin_00074d8c[3];
  uStack_1a74._0_1_ = s__usr_bin_00074d8c[4];
  uStack_1a74._1_1_ = s__usr_bin_00074d8c[5];
  uStack_1a74._2_1_ = s__usr_bin_00074d8c[6];
  uStack_1a74._3_1_ = s__usr_bin_00074d8c[7];
  cStack_1a70 = s__usr_bin_00074d8c[8];
  cgminer_path = acStack_2a80;
  pcVar6 = strdup(*argv_local);
  pcVar25 = cgminer_path;
  __src = dirname(pcVar6);
  strcpy(pcVar25,__src);
  free(pcVar6);
  pcVar25 = cgminer_path;
  sVar7 = strlen(cgminer_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_000734fc;
  devcursor = 8;
  logstart = 9;
  logcursor = 10;
  pcVar25 = (char *)0x2cf2;
  __s = (block *)_cgcalloc(0x68,1,"cgminer.c","main",0x2cf2);
  for (i = 0; i < 0x24; i = i + 1) {
    sVar7 = strlen((char *)__s);
    *(undefined2 *)(__s->hash + sVar7) = DAT_0007313c;
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
  uVar17 = uVar17 & ((blocks->hh).tbl)->num_buckets - 1;
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
          uVar17 = __aeabi_uidiv(pUVar21->count,((__s->hh).tbl)->ideal_chain_maxlen);
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
    tmp42[0] = s_Unexpected_extra_commandline_arg_00074de8[0];
    tmp42[1] = s_Unexpected_extra_commandline_arg_00074de8[1];
    tmp42[2] = s_Unexpected_extra_commandline_arg_00074de8[2];
    tmp42[3] = s_Unexpected_extra_commandline_arg_00074de8[3];
    tmp42[4] = s_Unexpected_extra_commandline_arg_00074de8[4];
    tmp42[5] = s_Unexpected_extra_commandline_arg_00074de8[5];
    tmp42[6] = s_Unexpected_extra_commandline_arg_00074de8[6];
    tmp42[7] = s_Unexpected_extra_commandline_arg_00074de8[7];
    tmp42[8] = s_Unexpected_extra_commandline_arg_00074de8[8];
    tmp42[9] = s_Unexpected_extra_commandline_arg_00074de8[9];
    tmp42[10] = s_Unexpected_extra_commandline_arg_00074de8[10];
    tmp42[11] = s_Unexpected_extra_commandline_arg_00074de8[11];
    tmp42[12] = s_Unexpected_extra_commandline_arg_00074de8[12];
    tmp42[13] = s_Unexpected_extra_commandline_arg_00074de8[13];
    tmp42[14] = s_Unexpected_extra_commandline_arg_00074de8[14];
    tmp42[15] = s_Unexpected_extra_commandline_arg_00074de8[15];
    tmp42[16] = s_Unexpected_extra_commandline_arg_00074de8[16];
    tmp42[17] = s_Unexpected_extra_commandline_arg_00074de8[17];
    tmp42[18] = s_Unexpected_extra_commandline_arg_00074de8[18];
    tmp42[19] = s_Unexpected_extra_commandline_arg_00074de8[19];
    tmp42[20] = s_Unexpected_extra_commandline_arg_00074de8[20];
    tmp42[21] = s_Unexpected_extra_commandline_arg_00074de8[21];
    tmp42[22] = s_Unexpected_extra_commandline_arg_00074de8[22];
    tmp42[23] = s_Unexpected_extra_commandline_arg_00074de8[23];
    tmp42[24] = s_Unexpected_extra_commandline_arg_00074de8[24];
    tmp42[25] = s_Unexpected_extra_commandline_arg_00074de8[25];
    tmp42[26] = s_Unexpected_extra_commandline_arg_00074de8[26];
    tmp42[27] = s_Unexpected_extra_commandline_arg_00074de8[27];
    tmp42[28] = s_Unexpected_extra_commandline_arg_00074de8[28];
    tmp42[29] = s_Unexpected_extra_commandline_arg_00074de8[29];
    tmp42[30] = s_Unexpected_extra_commandline_arg_00074de8[30];
    tmp42[31] = s_Unexpected_extra_commandline_arg_00074de8[31];
    tmp42[32] = s_Unexpected_extra_commandline_arg_00074de8[32];
    tmp42[33] = s_Unexpected_extra_commandline_arg_00074de8[33];
    tmp42[34] = s_Unexpected_extra_commandline_arg_00074de8[34];
    tmp42[35] = s_Unexpected_extra_commandline_arg_00074de8[35];
    tmp42._36_3_ = (undefined3)ram0x00074e0c;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  if (config_loaded != true) {
    load_default_config();
  }
  if ((opt_benchmark != false) || (opt_benchfile != (char *)0x0)) {
    ppVar10 = add_pool();
    pcVar6 = (char *)_cgmalloc(0xff,"cgminer.c","main",0x2d16);
    ppVar10->rpc_url = pcVar6;
    uVar2 = s_Benchmark_00074e1c._4_4_;
    uVar23 = s_Benchfile_00074e10._4_4_;
    if (opt_benchfile == (char *)0x0) {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchmark_00074e1c._0_4_;
      puVar16[1] = uVar2;
      *(undefined2 *)(puVar16 + 2) = s_Benchmark_00074e1c._8_2_;
    }
    else {
      puVar16 = (undefined4 *)ppVar10->rpc_url;
      *puVar16 = s_Benchfile_00074e10._0_4_;
      puVar16[1] = uVar23;
      *(undefined2 *)(puVar16 + 2) = s_Benchfile_00074e10._8_2_;
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
          _cg_memcpy(g_miner_compiletime,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2d51);
          strcpy(tmp,pcVar6 + 1);
          pcVar6 = strchr(tmp,10);
          if (pcVar6 == (char *)0x0) {
            strcpy(g_miner_type,tmp);
          }
          else {
            pcVar25 = "main";
            _cg_memcpy(g_miner_type,tmp,(int)pcVar6 - (int)tmp,"cgminer.c","main",0x2d5a);
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
  g_logfile_enable = true;
  g_logfile_path[0] = s__tmp_pattern_test_log_00074e98[0];
  g_logfile_path[1] = s__tmp_pattern_test_log_00074e98[1];
  g_logfile_path[2] = s__tmp_pattern_test_log_00074e98[2];
  g_logfile_path[3] = s__tmp_pattern_test_log_00074e98[3];
  g_logfile_path[4] = s__tmp_pattern_test_log_00074e98[4];
  g_logfile_path[5] = s__tmp_pattern_test_log_00074e98[5];
  g_logfile_path[6] = s__tmp_pattern_test_log_00074e98[6];
  g_logfile_path[7] = s__tmp_pattern_test_log_00074e98[7];
  g_logfile_path[8] = s__tmp_pattern_test_log_00074e98[8];
  g_logfile_path[9] = s__tmp_pattern_test_log_00074e98[9];
  g_logfile_path[10] = s__tmp_pattern_test_log_00074e98[10];
  g_logfile_path[11] = s__tmp_pattern_test_log_00074e98[11];
  g_logfile_path[12] = s__tmp_pattern_test_log_00074e98[12];
  g_logfile_path[13] = s__tmp_pattern_test_log_00074e98[13];
  g_logfile_path[14] = s__tmp_pattern_test_log_00074e98[14];
  g_logfile_path[15] = s__tmp_pattern_test_log_00074e98[15];
  g_logfile_path[16] = s__tmp_pattern_test_log_00074e98[16];
  g_logfile_path[17] = s__tmp_pattern_test_log_00074e98[17];
  g_logfile_path[18] = s__tmp_pattern_test_log_00074e98[18];
  g_logfile_path[19] = s__tmp_pattern_test_log_00074e98[19];
  g_logfile_path[20] = s__tmp_pattern_test_log_00074e98[20];
  g_logfile_path[21] = s__tmp_pattern_test_log_00074e98[21];
  g_logfile_openflag[0] = (char)DAT_00074eb0;
  g_logfile_openflag[1] = DAT_00074eb0._1_1_;
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
        tmp42[0] = s_Log_work_asic_num_empty_00074eb4[0];
        tmp42[1] = s_Log_work_asic_num_empty_00074eb4[1];
        tmp42[2] = s_Log_work_asic_num_empty_00074eb4[2];
        tmp42[3] = s_Log_work_asic_num_empty_00074eb4[3];
        tmp42[4] = s_Log_work_asic_num_empty_00074eb4[4];
        tmp42[5] = s_Log_work_asic_num_empty_00074eb4[5];
        tmp42[6] = s_Log_work_asic_num_empty_00074eb4[6];
        tmp42[7] = s_Log_work_asic_num_empty_00074eb4[7];
        tmp42[8] = s_Log_work_asic_num_empty_00074eb4[8];
        tmp42[9] = s_Log_work_asic_num_empty_00074eb4[9];
        tmp42[10] = s_Log_work_asic_num_empty_00074eb4[10];
        tmp42[11] = s_Log_work_asic_num_empty_00074eb4[11];
        tmp42[12] = s_Log_work_asic_num_empty_00074eb4[12];
        tmp42[13] = s_Log_work_asic_num_empty_00074eb4[13];
        tmp42[14] = s_Log_work_asic_num_empty_00074eb4[14];
        tmp42[15] = s_Log_work_asic_num_empty_00074eb4[15];
        tmp42[16] = s_Log_work_asic_num_empty_00074eb4[16];
        tmp42[17] = s_Log_work_asic_num_empty_00074eb4[17];
        tmp42[18] = s_Log_work_asic_num_empty_00074eb4[18];
        tmp42[19] = s_Log_work_asic_num_empty_00074eb4[19];
        tmp42[20] = s_Log_work_asic_num_empty_00074eb4[20];
        tmp42[21] = s_Log_work_asic_num_empty_00074eb4[21];
        tmp42[22] = s_Log_work_asic_num_empty_00074eb4[22];
        tmp42[23] = s_Log_work_asic_num_empty_00074eb4[23];
        _applog(3,tmp42,true);
        _quit(1);
      }
      g_logwork_asicnum = atoi(opt_logwork_asicnum);
      if (((g_logwork_asicnum != 1) && (g_logwork_asicnum != 0x20)) && (g_logwork_asicnum != 0x40))
      {
        tmp42[0] = s_Log_work_asic_num_must_be_1__32__00074ecc[0];
        tmp42[1] = s_Log_work_asic_num_must_be_1__32__00074ecc[1];
        tmp42[2] = s_Log_work_asic_num_must_be_1__32__00074ecc[2];
        tmp42[3] = s_Log_work_asic_num_must_be_1__32__00074ecc[3];
        tmp42[4] = s_Log_work_asic_num_must_be_1__32__00074ecc[4];
        tmp42[5] = s_Log_work_asic_num_must_be_1__32__00074ecc[5];
        tmp42[6] = s_Log_work_asic_num_must_be_1__32__00074ecc[6];
        tmp42[7] = s_Log_work_asic_num_must_be_1__32__00074ecc[7];
        tmp42[8] = s_Log_work_asic_num_must_be_1__32__00074ecc[8];
        tmp42[9] = s_Log_work_asic_num_must_be_1__32__00074ecc[9];
        tmp42[10] = s_Log_work_asic_num_must_be_1__32__00074ecc[10];
        tmp42[11] = s_Log_work_asic_num_must_be_1__32__00074ecc[11];
        tmp42[12] = s_Log_work_asic_num_must_be_1__32__00074ecc[12];
        tmp42[13] = s_Log_work_asic_num_must_be_1__32__00074ecc[13];
        tmp42[14] = s_Log_work_asic_num_must_be_1__32__00074ecc[14];
        tmp42[15] = s_Log_work_asic_num_must_be_1__32__00074ecc[15];
        tmp42[16] = s_Log_work_asic_num_must_be_1__32__00074ecc[16];
        tmp42[17] = s_Log_work_asic_num_must_be_1__32__00074ecc[17];
        tmp42[18] = s_Log_work_asic_num_must_be_1__32__00074ecc[18];
        tmp42[19] = s_Log_work_asic_num_must_be_1__32__00074ecc[19];
        tmp42[20] = s_Log_work_asic_num_must_be_1__32__00074ecc[20];
        tmp42[21] = s_Log_work_asic_num_must_be_1__32__00074ecc[21];
        tmp42[22] = s_Log_work_asic_num_must_be_1__32__00074ecc[22];
        tmp42[23] = s_Log_work_asic_num_must_be_1__32__00074ecc[23];
        tmp42[24] = s_Log_work_asic_num_must_be_1__32__00074ecc[24];
        tmp42[25] = s_Log_work_asic_num_must_be_1__32__00074ecc[25];
        tmp42[26] = s_Log_work_asic_num_must_be_1__32__00074ecc[26];
        tmp42[27] = s_Log_work_asic_num_must_be_1__32__00074ecc[27];
        tmp42[28] = s_Log_work_asic_num_must_be_1__32__00074ecc[28];
        tmp42[29] = s_Log_work_asic_num_must_be_1__32__00074ecc[29];
        tmp42[30] = s_Log_work_asic_num_must_be_1__32__00074ecc[30];
        tmp42[31] = s_Log_work_asic_num_must_be_1__32__00074ecc[31];
        tmp42[32] = s_Log_work_asic_num_must_be_1__32__00074ecc[32];
        tmp42[33] = s_Log_work_asic_num_must_be_1__32__00074ecc[33];
        tmp42[34] = s_Log_work_asic_num_must_be_1__32__00074ecc[34];
        tmp42[35] = s_Log_work_asic_num_must_be_1__32__00074ecc[35];
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
    g_logwork_file = (FILE *)fopen(tmp,(char *)&DAT_00074ce0);
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Log work open file %s",tmp);
      _applog(3,tmp42,false);
    }
    if (g_logwork_asicnum == 1) {
      sprintf(tmp,"%s%02d.txt",opt_logwork_path,1);
      g_logwork_files[0] = (FILE *)fopen(tmp,(char *)&DAT_00074ce0);
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
        pFVar11 = fopen(tmp,(char *)&DAT_00074ce0);
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
        pFVar11 = fopen(tmp,(char *)&DAT_00074ce0);
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
        tmp42[0] = s_Error_in_configuration_file__par_0007502c[0];
        tmp42[1] = s_Error_in_configuration_file__par_0007502c[1];
        tmp42[2] = s_Error_in_configuration_file__par_0007502c[2];
        tmp42[3] = s_Error_in_configuration_file__par_0007502c[3];
        tmp42[4] = s_Error_in_configuration_file__par_0007502c[4];
        tmp42[5] = s_Error_in_configuration_file__par_0007502c[5];
        tmp42[6] = s_Error_in_configuration_file__par_0007502c[6];
        tmp42[7] = s_Error_in_configuration_file__par_0007502c[7];
        tmp42[8] = s_Error_in_configuration_file__par_0007502c[8];
        tmp42[9] = s_Error_in_configuration_file__par_0007502c[9];
        tmp42[10] = s_Error_in_configuration_file__par_0007502c[10];
        tmp42[11] = s_Error_in_configuration_file__par_0007502c[11];
        tmp42[12] = s_Error_in_configuration_file__par_0007502c[12];
        tmp42[13] = s_Error_in_configuration_file__par_0007502c[13];
        tmp42[14] = s_Error_in_configuration_file__par_0007502c[14];
        tmp42[15] = s_Error_in_configuration_file__par_0007502c[15];
        tmp42[16] = s_Error_in_configuration_file__par_0007502c[16];
        tmp42[17] = s_Error_in_configuration_file__par_0007502c[17];
        tmp42[18] = s_Error_in_configuration_file__par_0007502c[18];
        tmp42[19] = s_Error_in_configuration_file__par_0007502c[19];
        tmp42[20] = s_Error_in_configuration_file__par_0007502c[20];
        tmp42[21] = s_Error_in_configuration_file__par_0007502c[21];
        tmp42[22] = s_Error_in_configuration_file__par_0007502c[22];
        tmp42[23] = s_Error_in_configuration_file__par_0007502c[23];
        tmp42[24] = s_Error_in_configuration_file__par_0007502c[24];
        tmp42[25] = s_Error_in_configuration_file__par_0007502c[25];
        tmp42[26] = s_Error_in_configuration_file__par_0007502c[26];
        tmp42[27] = s_Error_in_configuration_file__par_0007502c[27];
        tmp42[28] = s_Error_in_configuration_file__par_0007502c[28];
        tmp42[29] = s_Error_in_configuration_file__par_0007502c[29];
        tmp42[30] = s_Error_in_configuration_file__par_0007502c[30];
        tmp42[31] = s_Error_in_configuration_file__par_0007502c[31];
        tmp42[32] = s_Error_in_configuration_file__par_0007502c[32];
        tmp42[33] = s_Error_in_configuration_file__par_0007502c[33];
        tmp42[34] = s_Error_in_configuration_file__par_0007502c[34];
        tmp42[35] = s_Error_in_configuration_file__par_0007502c[35];
        tmp42[36] = s_Error_in_configuration_file__par_0007502c[36];
        tmp42[37] = s_Error_in_configuration_file__par_0007502c[37];
        tmp42[38] = s_Error_in_configuration_file__par_0007502c[38];
        tmp42[39] = s_Error_in_configuration_file__par_0007502c[39];
        tmp42[40] = s_Error_in_configuration_file__par_0007502c[40];
        tmp42[41] = s_Error_in_configuration_file__par_0007502c[41];
        tmp42[42] = s_Error_in_configuration_file__par_0007502c[42];
        tmp42[43] = s_Error_in_configuration_file__par_0007502c[43];
        tmp42._44_3_ = (undefined3)ram0x00075058;
        _applog(4,tmp42,false);
      }
      if ((use_curses != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        tmp42[0] = s_Start_cgminer_with__T_to_see_wha_0007505c[0];
        tmp42[1] = s_Start_cgminer_with__T_to_see_wha_0007505c[1];
        tmp42[2] = s_Start_cgminer_with__T_to_see_wha_0007505c[2];
        tmp42[3] = s_Start_cgminer_with__T_to_see_wha_0007505c[3];
        tmp42[4] = s_Start_cgminer_with__T_to_see_wha_0007505c[4];
        tmp42[5] = s_Start_cgminer_with__T_to_see_wha_0007505c[5];
        tmp42[6] = s_Start_cgminer_with__T_to_see_wha_0007505c[6];
        tmp42[7] = s_Start_cgminer_with__T_to_see_wha_0007505c[7];
        tmp42[8] = s_Start_cgminer_with__T_to_see_wha_0007505c[8];
        tmp42[9] = s_Start_cgminer_with__T_to_see_wha_0007505c[9];
        tmp42[10] = s_Start_cgminer_with__T_to_see_wha_0007505c[10];
        tmp42[11] = s_Start_cgminer_with__T_to_see_wha_0007505c[11];
        tmp42[12] = s_Start_cgminer_with__T_to_see_wha_0007505c[12];
        tmp42[13] = s_Start_cgminer_with__T_to_see_wha_0007505c[13];
        tmp42[14] = s_Start_cgminer_with__T_to_see_wha_0007505c[14];
        tmp42[15] = s_Start_cgminer_with__T_to_see_wha_0007505c[15];
        tmp42[16] = s_Start_cgminer_with__T_to_see_wha_0007505c[16];
        tmp42[17] = s_Start_cgminer_with__T_to_see_wha_0007505c[17];
        tmp42[18] = s_Start_cgminer_with__T_to_see_wha_0007505c[18];
        tmp42[19] = s_Start_cgminer_with__T_to_see_wha_0007505c[19];
        tmp42[20] = s_Start_cgminer_with__T_to_see_wha_0007505c[20];
        tmp42[21] = s_Start_cgminer_with__T_to_see_wha_0007505c[21];
        tmp42[22] = s_Start_cgminer_with__T_to_see_wha_0007505c[22];
        tmp42[23] = s_Start_cgminer_with__T_to_see_wha_0007505c[23];
        tmp42[24] = s_Start_cgminer_with__T_to_see_wha_0007505c[24];
        tmp42[25] = s_Start_cgminer_with__T_to_see_wha_0007505c[25];
        tmp42[26] = s_Start_cgminer_with__T_to_see_wha_0007505c[26];
        tmp42[27] = s_Start_cgminer_with__T_to_see_wha_0007505c[27];
        tmp42[28] = s_Start_cgminer_with__T_to_see_wha_0007505c[28];
        tmp42[29] = s_Start_cgminer_with__T_to_see_wha_0007505c[29];
        tmp42[30] = s_Start_cgminer_with__T_to_see_wha_0007505c[30];
        tmp42[31] = s_Start_cgminer_with__T_to_see_wha_0007505c[31];
        tmp42[32] = s_Start_cgminer_with__T_to_see_wha_0007505c[32];
        tmp42[33] = s_Start_cgminer_with__T_to_see_wha_0007505c[33];
        tmp42[34] = s_Start_cgminer_with__T_to_see_wha_0007505c[34];
        tmp42[35] = s_Start_cgminer_with__T_to_see_wha_0007505c[35];
        tmp42[36] = s_Start_cgminer_with__T_to_see_wha_0007505c[36];
        tmp42[37] = s_Start_cgminer_with__T_to_see_wha_0007505c[37];
        tmp42[38] = s_Start_cgminer_with__T_to_see_wha_0007505c[38];
        tmp42[39] = s_Start_cgminer_with__T_to_see_wha_0007505c[39];
        tmp42[40] = s_Start_cgminer_with__T_to_see_wha_0007505c[40];
        tmp42[41] = s_Start_cgminer_with__T_to_see_wha_0007505c[41];
        tmp42[42] = s_Start_cgminer_with__T_to_see_wha_0007505c[42];
        tmp42[43] = s_Start_cgminer_with__T_to_see_wha_0007505c[43];
        tmp42[44] = s_Start_cgminer_with__T_to_see_wha_0007505c[44];
        tmp42[45] = s_Start_cgminer_with__T_to_see_wha_0007505c[45];
        tmp42[46] = s_Start_cgminer_with__T_to_see_wha_0007505c[46];
        tmp42[47] = s_Start_cgminer_with__T_to_see_wha_0007505c[47];
        tmp42[48] = (char)(short)ram0x0007508c;
        tmp42[49] = (char)((ushort)(short)ram0x0007508c >> 8);
        _applog(4,tmp42,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Fatal_JSON_error_in_configuratio_00074fdc[0];
        tmp42[1] = s_Fatal_JSON_error_in_configuratio_00074fdc[1];
        tmp42[2] = s_Fatal_JSON_error_in_configuratio_00074fdc[2];
        tmp42[3] = s_Fatal_JSON_error_in_configuratio_00074fdc[3];
        tmp42[4] = s_Fatal_JSON_error_in_configuratio_00074fdc[4];
        tmp42[5] = s_Fatal_JSON_error_in_configuratio_00074fdc[5];
        tmp42[6] = s_Fatal_JSON_error_in_configuratio_00074fdc[6];
        tmp42[7] = s_Fatal_JSON_error_in_configuratio_00074fdc[7];
        tmp42[8] = s_Fatal_JSON_error_in_configuratio_00074fdc[8];
        tmp42[9] = s_Fatal_JSON_error_in_configuratio_00074fdc[9];
        tmp42[10] = s_Fatal_JSON_error_in_configuratio_00074fdc[10];
        tmp42[11] = s_Fatal_JSON_error_in_configuratio_00074fdc[11];
        tmp42[12] = s_Fatal_JSON_error_in_configuratio_00074fdc[12];
        tmp42[13] = s_Fatal_JSON_error_in_configuratio_00074fdc[13];
        tmp42[14] = s_Fatal_JSON_error_in_configuratio_00074fdc[14];
        tmp42[15] = s_Fatal_JSON_error_in_configuratio_00074fdc[15];
        tmp42[16] = s_Fatal_JSON_error_in_configuratio_00074fdc[16];
        tmp42[17] = s_Fatal_JSON_error_in_configuratio_00074fdc[17];
        tmp42[18] = s_Fatal_JSON_error_in_configuratio_00074fdc[18];
        tmp42[19] = s_Fatal_JSON_error_in_configuratio_00074fdc[19];
        tmp42[20] = s_Fatal_JSON_error_in_configuratio_00074fdc[20];
        tmp42[21] = s_Fatal_JSON_error_in_configuratio_00074fdc[21];
        tmp42[22] = s_Fatal_JSON_error_in_configuratio_00074fdc[22];
        tmp42[23] = s_Fatal_JSON_error_in_configuratio_00074fdc[23];
        tmp42[24] = s_Fatal_JSON_error_in_configuratio_00074fdc[24];
        tmp42[25] = s_Fatal_JSON_error_in_configuratio_00074fdc[25];
        tmp42[26] = s_Fatal_JSON_error_in_configuratio_00074fdc[26];
        tmp42[27] = s_Fatal_JSON_error_in_configuratio_00074fdc[27];
        tmp42[28] = s_Fatal_JSON_error_in_configuratio_00074fdc[28];
        tmp42[29] = s_Fatal_JSON_error_in_configuratio_00074fdc[29];
        tmp42[30] = s_Fatal_JSON_error_in_configuratio_00074fdc[30];
        tmp42[31] = s_Fatal_JSON_error_in_configuratio_00074fdc[31];
        tmp42[32] = s_Fatal_JSON_error_in_configuratio_00074fdc[32];
        tmp42[33] = s_Fatal_JSON_error_in_configuratio_00074fdc[33];
        tmp42[34] = s_Fatal_JSON_error_in_configuratio_00074fdc[34];
        tmp42[35] = s_Fatal_JSON_error_in_configuratio_00074fdc[35];
        tmp42[36] = s_Fatal_JSON_error_in_configuratio_00074fdc[36];
        tmp42[37] = s_Fatal_JSON_error_in_configuratio_00074fdc[37];
        tmp42[38] = s_Fatal_JSON_error_in_configuratio_00074fdc[38];
        tmp42[39] = s_Fatal_JSON_error_in_configuratio_00074fdc[39];
        _applog(4,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        tmp42[0] = s_Configuration_file_could_not_be_u_00075004[0];
        tmp42[1] = s_Configuration_file_could_not_be_u_00075004[1];
        tmp42[2] = s_Configuration_file_could_not_be_u_00075004[2];
        tmp42[3] = s_Configuration_file_could_not_be_u_00075004[3];
        tmp42[4] = s_Configuration_file_could_not_be_u_00075004[4];
        tmp42[5] = s_Configuration_file_could_not_be_u_00075004[5];
        tmp42[6] = s_Configuration_file_could_not_be_u_00075004[6];
        tmp42[7] = s_Configuration_file_could_not_be_u_00075004[7];
        tmp42[8] = s_Configuration_file_could_not_be_u_00075004[8];
        tmp42[9] = s_Configuration_file_could_not_be_u_00075004[9];
        tmp42[10] = s_Configuration_file_could_not_be_u_00075004[10];
        tmp42[11] = s_Configuration_file_could_not_be_u_00075004[11];
        tmp42[12] = s_Configuration_file_could_not_be_u_00075004[12];
        tmp42[13] = s_Configuration_file_could_not_be_u_00075004[13];
        tmp42[14] = s_Configuration_file_could_not_be_u_00075004[14];
        tmp42[15] = s_Configuration_file_could_not_be_u_00075004[15];
        tmp42[16] = s_Configuration_file_could_not_be_u_00075004[16];
        tmp42[17] = s_Configuration_file_could_not_be_u_00075004[17];
        tmp42[18] = s_Configuration_file_could_not_be_u_00075004[18];
        tmp42[19] = s_Configuration_file_could_not_be_u_00075004[19];
        tmp42[20] = s_Configuration_file_could_not_be_u_00075004[20];
        tmp42[21] = s_Configuration_file_could_not_be_u_00075004[21];
        tmp42[22] = s_Configuration_file_could_not_be_u_00075004[22];
        tmp42[23] = s_Configuration_file_could_not_be_u_00075004[23];
        tmp42[24] = s_Configuration_file_could_not_be_u_00075004[24];
        tmp42[25] = s_Configuration_file_could_not_be_u_00075004[25];
        tmp42[26] = s_Configuration_file_could_not_be_u_00075004[26];
        tmp42[27] = s_Configuration_file_could_not_be_u_00075004[27];
        tmp42[28] = s_Configuration_file_could_not_be_u_00075004[28];
        tmp42[29] = s_Configuration_file_could_not_be_u_00075004[29];
        tmp42[30] = s_Configuration_file_could_not_be_u_00075004[30];
        tmp42[31] = s_Configuration_file_could_not_be_u_00075004[31];
        tmp42[32] = s_Configuration_file_could_not_be_u_00075004[32];
        tmp42[33] = s_Configuration_file_could_not_be_u_00075004[33];
        tmp42[34] = s_Configuration_file_could_not_be_u_00075004[34];
        tmp42[35] = s_Configuration_file_could_not_be_u_00075004[35];
        tmp42[36] = (char)(short)ram0x00075028;
        tmp42[37] = (char)((ushort)(short)ram0x00075028 >> 8);
        _applog(4,tmp42,false);
      }
    }
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar25 = opt_kernel_path;
  sVar7 = strlen(opt_kernel_path);
  *(undefined2 *)(pcVar25 + sVar7) = DAT_000734fc;
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
  pcVar25 = (char *)0x2dfb;
  control_thr = (thr_info *)_cgcalloc(8,0x40,"cgminer.c","main",0x2dfb);
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
      tmp42[0] = s_Devices_detected__00075090[0];
      tmp42[1] = s_Devices_detected__00075090[1];
      tmp42[2] = s_Devices_detected__00075090[2];
      tmp42[3] = s_Devices_detected__00075090[3];
      tmp42[4] = s_Devices_detected__00075090[4];
      tmp42[5] = s_Devices_detected__00075090[5];
      tmp42[6] = s_Devices_detected__00075090[6];
      tmp42[7] = s_Devices_detected__00075090[7];
      tmp42[8] = s_Devices_detected__00075090[8];
      tmp42[9] = s_Devices_detected__00075090[9];
      tmp42[10] = s_Devices_detected__00075090[10];
      tmp42[11] = s_Devices_detected__00075090[11];
      tmp42[12] = s_Devices_detected__00075090[12];
      tmp42[13] = s_Devices_detected__00075090[13];
      tmp42[14] = s_Devices_detected__00075090[14];
      tmp42[15] = s_Devices_detected__00075090[15];
      tmp42[16] = (char)(short)ram0x000750a0;
      tmp42[17] = (char)((ushort)(short)ram0x000750a0 >> 8);
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
    tmp42[0] = s_All_devices_disabled__cannot_min_000750f4[0];
    tmp42[1] = s_All_devices_disabled__cannot_min_000750f4[1];
    tmp42[2] = s_All_devices_disabled__cannot_min_000750f4[2];
    tmp42[3] = s_All_devices_disabled__cannot_min_000750f4[3];
    tmp42[4] = s_All_devices_disabled__cannot_min_000750f4[4];
    tmp42[5] = s_All_devices_disabled__cannot_min_000750f4[5];
    tmp42[6] = s_All_devices_disabled__cannot_min_000750f4[6];
    tmp42[7] = s_All_devices_disabled__cannot_min_000750f4[7];
    tmp42[8] = s_All_devices_disabled__cannot_min_000750f4[8];
    tmp42[9] = s_All_devices_disabled__cannot_min_000750f4[9];
    tmp42[10] = s_All_devices_disabled__cannot_min_000750f4[10];
    tmp42[11] = s_All_devices_disabled__cannot_min_000750f4[11];
    tmp42[12] = s_All_devices_disabled__cannot_min_000750f4[12];
    tmp42[13] = s_All_devices_disabled__cannot_min_000750f4[13];
    tmp42[14] = s_All_devices_disabled__cannot_min_000750f4[14];
    tmp42[15] = s_All_devices_disabled__cannot_min_000750f4[15];
    tmp42[16] = s_All_devices_disabled__cannot_min_000750f4[16];
    tmp42[17] = s_All_devices_disabled__cannot_min_000750f4[17];
    tmp42[18] = s_All_devices_disabled__cannot_min_000750f4[18];
    tmp42[19] = s_All_devices_disabled__cannot_min_000750f4[19];
    tmp42[20] = s_All_devices_disabled__cannot_min_000750f4[20];
    tmp42[21] = s_All_devices_disabled__cannot_min_000750f4[21];
    tmp42[22] = s_All_devices_disabled__cannot_min_000750f4[22];
    tmp42[23] = s_All_devices_disabled__cannot_min_000750f4[23];
    tmp42[24] = s_All_devices_disabled__cannot_min_000750f4[24];
    tmp42[25] = s_All_devices_disabled__cannot_min_000750f4[25];
    tmp42[26] = s_All_devices_disabled__cannot_min_000750f4[26];
    tmp42[27] = s_All_devices_disabled__cannot_min_000750f4[27];
    tmp42[28] = s_All_devices_disabled__cannot_min_000750f4[28];
    tmp42[29] = s_All_devices_disabled__cannot_min_000750f4[29];
    tmp42[30] = s_All_devices_disabled__cannot_min_000750f4[30];
    tmp42[31] = s_All_devices_disabled__cannot_min_000750f4[31];
    tmp42._32_3_ = (undefined3)ram0x00075114;
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
      tmp42[0] = s_Need_to_specify_at_least_one_poo_00075118[0];
      tmp42[1] = s_Need_to_specify_at_least_one_poo_00075118[1];
      tmp42[2] = s_Need_to_specify_at_least_one_poo_00075118[2];
      tmp42[3] = s_Need_to_specify_at_least_one_poo_00075118[3];
      tmp42[4] = s_Need_to_specify_at_least_one_poo_00075118[4];
      tmp42[5] = s_Need_to_specify_at_least_one_poo_00075118[5];
      tmp42[6] = s_Need_to_specify_at_least_one_poo_00075118[6];
      tmp42[7] = s_Need_to_specify_at_least_one_poo_00075118[7];
      tmp42[8] = s_Need_to_specify_at_least_one_poo_00075118[8];
      tmp42[9] = s_Need_to_specify_at_least_one_poo_00075118[9];
      tmp42[10] = s_Need_to_specify_at_least_one_poo_00075118[10];
      tmp42[11] = s_Need_to_specify_at_least_one_poo_00075118[11];
      tmp42[12] = s_Need_to_specify_at_least_one_poo_00075118[12];
      tmp42[13] = s_Need_to_specify_at_least_one_poo_00075118[13];
      tmp42[14] = s_Need_to_specify_at_least_one_poo_00075118[14];
      tmp42[15] = s_Need_to_specify_at_least_one_poo_00075118[15];
      tmp42[16] = s_Need_to_specify_at_least_one_poo_00075118[16];
      tmp42[17] = s_Need_to_specify_at_least_one_poo_00075118[17];
      tmp42[18] = s_Need_to_specify_at_least_one_poo_00075118[18];
      tmp42[19] = s_Need_to_specify_at_least_one_poo_00075118[19];
      tmp42[20] = s_Need_to_specify_at_least_one_poo_00075118[20];
      tmp42[21] = s_Need_to_specify_at_least_one_poo_00075118[21];
      tmp42[22] = s_Need_to_specify_at_least_one_poo_00075118[22];
      tmp42[23] = s_Need_to_specify_at_least_one_poo_00075118[23];
      tmp42[24] = s_Need_to_specify_at_least_one_poo_00075118[24];
      tmp42[25] = s_Need_to_specify_at_least_one_poo_00075118[25];
      tmp42[26] = s_Need_to_specify_at_least_one_poo_00075118[26];
      tmp42[27] = s_Need_to_specify_at_least_one_poo_00075118[27];
      tmp42[28] = s_Need_to_specify_at_least_one_poo_00075118[28];
      tmp42[29] = s_Need_to_specify_at_least_one_poo_00075118[29];
      tmp42[30] = s_Need_to_specify_at_least_one_poo_00075118[30];
      tmp42[31] = s_Need_to_specify_at_least_one_poo_00075118[31];
      tmp42[32] = s_Need_to_specify_at_least_one_poo_00075118[32];
      tmp42[33] = s_Need_to_specify_at_least_one_poo_00075118[33];
      tmp42[34] = s_Need_to_specify_at_least_one_poo_00075118[34];
      tmp42[35] = s_Need_to_specify_at_least_one_poo_00075118[35];
      tmp42[36] = s_Need_to_specify_at_least_one_poo_00075118[36];
      tmp42[37] = s_Need_to_specify_at_least_one_poo_00075118[37];
      tmp42[38] = s_Need_to_specify_at_least_one_poo_00075118[38];
      tmp42[39] = s_Need_to_specify_at_least_one_poo_00075118[39];
      tmp42[40] = (char)(short)ram0x00075140;
      tmp42[41] = (char)((ushort)(short)ram0x00075140 >> 8);
      _applog(4,tmp42,false);
    }
    tmp42[0] = s_Pool_setup_failed_00075144[0];
    tmp42[1] = s_Pool_setup_failed_00075144[1];
    tmp42[2] = s_Pool_setup_failed_00075144[2];
    tmp42[3] = s_Pool_setup_failed_00075144[3];
    tmp42[4] = s_Pool_setup_failed_00075144[4];
    tmp42[5] = s_Pool_setup_failed_00075144[5];
    tmp42[6] = s_Pool_setup_failed_00075144[6];
    tmp42[7] = s_Pool_setup_failed_00075144[7];
    tmp42[8] = s_Pool_setup_failed_00075144[8];
    tmp42[9] = s_Pool_setup_failed_00075144[9];
    tmp42[10] = s_Pool_setup_failed_00075144[10];
    tmp42[11] = s_Pool_setup_failed_00075144[11];
    tmp42[12] = s_Pool_setup_failed_00075144[12];
    tmp42[13] = s_Pool_setup_failed_00075144[13];
    tmp42[14] = s_Pool_setup_failed_00075144[14];
    tmp42[15] = s_Pool_setup_failed_00075144[15];
    tmp42[16] = (char)(short)ram0x00075154;
    tmp42[17] = (char)((ushort)(short)ram0x00075154 >> 8);
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
      uVar17 = sVar7 + sVar12 + 2;
      pcVar25 = (char *)_cgmalloc(uVar17,"cgminer.c","main",0x2e68);
      ppVar10->rpc_userpass = pcVar25;
      snprintf(ppVar10->rpc_userpass,uVar17,"%s:%s",ppVar10->rpc_user,ppVar10->rpc_pass);
    }
  }
  currentpool = *pools;
  if (use_syslog != false) {
    openlog("bmminer",1,8);
  }
  if (opt_stderr_cmd != (char *)0x0) {
    fork_monitor();
  }
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,"cgminer.c","main",0x2e79);
  for (i = 0; i < mining_threads; i = i + 1) {
    pptVar13 = mining_thr + i;
    ptVar14 = (thr_info *)_cgcalloc(1,0x40,"cgminer.c","main",0x2e7d);
    *pptVar13 = ptVar14;
  }
  k = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar22 = devices[i];
    pptVar13 = (thr_info **)_cgmalloc((pcVar22->threads + 1) * 4,"cgminer.c","main",0x2e86);
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
          _cgsem_post(&ptVar14->sem,"cgminer.c","main",0x2ea2);
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
      tmp42[0] = s_Probing_for_an_alive_pool_000751a0[0];
      tmp42[1] = s_Probing_for_an_alive_pool_000751a0[1];
      tmp42[2] = s_Probing_for_an_alive_pool_000751a0[2];
      tmp42[3] = s_Probing_for_an_alive_pool_000751a0[3];
      tmp42[4] = s_Probing_for_an_alive_pool_000751a0[4];
      tmp42[5] = s_Probing_for_an_alive_pool_000751a0[5];
      tmp42[6] = s_Probing_for_an_alive_pool_000751a0[6];
      tmp42[7] = s_Probing_for_an_alive_pool_000751a0[7];
      tmp42[8] = s_Probing_for_an_alive_pool_000751a0[8];
      tmp42[9] = s_Probing_for_an_alive_pool_000751a0[9];
      tmp42[10] = s_Probing_for_an_alive_pool_000751a0[10];
      tmp42[11] = s_Probing_for_an_alive_pool_000751a0[11];
      tmp42[12] = s_Probing_for_an_alive_pool_000751a0[12];
      tmp42[13] = s_Probing_for_an_alive_pool_000751a0[13];
      tmp42[14] = s_Probing_for_an_alive_pool_000751a0[14];
      tmp42[15] = s_Probing_for_an_alive_pool_000751a0[15];
      tmp42[16] = s_Probing_for_an_alive_pool_000751a0[16];
      tmp42[17] = s_Probing_for_an_alive_pool_000751a0[17];
      tmp42[18] = s_Probing_for_an_alive_pool_000751a0[18];
      tmp42[19] = s_Probing_for_an_alive_pool_000751a0[19];
      tmp42[20] = s_Probing_for_an_alive_pool_000751a0[20];
      tmp42[21] = s_Probing_for_an_alive_pool_000751a0[21];
      tmp42[22] = s_Probing_for_an_alive_pool_000751a0[22];
      tmp42[23] = s_Probing_for_an_alive_pool_000751a0[23];
      tmp42[24] = (char)(short)ram0x000751b8;
      tmp42[25] = (char)((ushort)(short)ram0x000751b8 >> 8);
      _applog(5,tmp42,false);
    }
    probe_pools();
    do {
      sleep(1);
      slept = slept + 1;
      if (pools_active == true) break;
    } while (slept < 0x3c);
    while (pools_active != true) {
      if (!bVar1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_No_servers_were_found_that_could_000751bc[0];
          tmp42[1] = s_No_servers_were_found_that_could_000751bc[1];
          tmp42[2] = s_No_servers_were_found_that_could_000751bc[2];
          tmp42[3] = s_No_servers_were_found_that_could_000751bc[3];
          tmp42[4] = s_No_servers_were_found_that_could_000751bc[4];
          tmp42[5] = s_No_servers_were_found_that_could_000751bc[5];
          tmp42[6] = s_No_servers_were_found_that_could_000751bc[6];
          tmp42[7] = s_No_servers_were_found_that_could_000751bc[7];
          tmp42[8] = s_No_servers_were_found_that_could_000751bc[8];
          tmp42[9] = s_No_servers_were_found_that_could_000751bc[9];
          tmp42[10] = s_No_servers_were_found_that_could_000751bc[10];
          tmp42[11] = s_No_servers_were_found_that_could_000751bc[11];
          tmp42[12] = s_No_servers_were_found_that_could_000751bc[12];
          tmp42[13] = s_No_servers_were_found_that_could_000751bc[13];
          tmp42[14] = s_No_servers_were_found_that_could_000751bc[14];
          tmp42[15] = s_No_servers_were_found_that_could_000751bc[15];
          tmp42[16] = s_No_servers_were_found_that_could_000751bc[16];
          tmp42[17] = s_No_servers_were_found_that_could_000751bc[17];
          tmp42[18] = s_No_servers_were_found_that_could_000751bc[18];
          tmp42[19] = s_No_servers_were_found_that_could_000751bc[19];
          tmp42[20] = s_No_servers_were_found_that_could_000751bc[20];
          tmp42[21] = s_No_servers_were_found_that_could_000751bc[21];
          tmp42[22] = s_No_servers_were_found_that_could_000751bc[22];
          tmp42[23] = s_No_servers_were_found_that_could_000751bc[23];
          tmp42[24] = s_No_servers_were_found_that_could_000751bc[24];
          tmp42[25] = s_No_servers_were_found_that_could_000751bc[25];
          tmp42[26] = s_No_servers_were_found_that_could_000751bc[26];
          tmp42[27] = s_No_servers_were_found_that_could_000751bc[27];
          tmp42[28] = s_No_servers_were_found_that_could_000751bc[28];
          tmp42[29] = s_No_servers_were_found_that_could_000751bc[29];
          tmp42[30] = s_No_servers_were_found_that_could_000751bc[30];
          tmp42[31] = s_No_servers_were_found_that_could_000751bc[31];
          tmp42[32] = s_No_servers_were_found_that_could_000751bc[32];
          tmp42[33] = s_No_servers_were_found_that_could_000751bc[33];
          tmp42[34] = s_No_servers_were_found_that_could_000751bc[34];
          tmp42[35] = s_No_servers_were_found_that_could_000751bc[35];
          tmp42[36] = s_No_servers_were_found_that_could_000751bc[36];
          tmp42[37] = s_No_servers_were_found_that_could_000751bc[37];
          tmp42[38] = s_No_servers_were_found_that_could_000751bc[38];
          tmp42[39] = s_No_servers_were_found_that_could_000751bc[39];
          tmp42[40] = s_No_servers_were_found_that_could_000751bc[40];
          tmp42[41] = s_No_servers_were_found_that_could_000751bc[41];
          tmp42[42] = s_No_servers_were_found_that_could_000751bc[42];
          tmp42[43] = s_No_servers_were_found_that_could_000751bc[43];
          tmp42[44] = s_No_servers_were_found_that_could_000751bc[44];
          tmp42[45] = s_No_servers_were_found_that_could_000751bc[45];
          tmp42[46] = s_No_servers_were_found_that_could_000751bc[46];
          tmp42[47] = s_No_servers_were_found_that_could_000751bc[47];
          tmp42[48] = s_No_servers_were_found_that_could_000751bc[48];
          tmp42[49] = s_No_servers_were_found_that_could_000751bc[49];
          tmp42[50] = s_No_servers_were_found_that_could_000751bc[50];
          tmp42[51] = s_No_servers_were_found_that_could_000751bc[51];
          tmp42[52] = s_No_servers_were_found_that_could_000751bc[52];
          tmp42[53] = s_No_servers_were_found_that_could_000751bc[53];
          tmp42[54] = s_No_servers_were_found_that_could_000751bc[54];
          tmp42[55] = s_No_servers_were_found_that_could_000751bc[55];
          tmp42._56_2_ = (undefined2)ram0x000751f4;
          tmp42[58] = (char)((uint)ram0x000751f4 >> 0x10);
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
        tmp42[0] = s_No_servers_could_be_used__Exitin_0007531c[0];
        tmp42[1] = s_No_servers_could_be_used__Exitin_0007531c[1];
        tmp42[2] = s_No_servers_could_be_used__Exitin_0007531c[2];
        tmp42[3] = s_No_servers_could_be_used__Exitin_0007531c[3];
        tmp42[4] = s_No_servers_could_be_used__Exitin_0007531c[4];
        tmp42[5] = s_No_servers_could_be_used__Exitin_0007531c[5];
        tmp42[6] = s_No_servers_could_be_used__Exitin_0007531c[6];
        tmp42[7] = s_No_servers_could_be_used__Exitin_0007531c[7];
        tmp42[8] = s_No_servers_could_be_used__Exitin_0007531c[8];
        tmp42[9] = s_No_servers_could_be_used__Exitin_0007531c[9];
        tmp42[10] = s_No_servers_could_be_used__Exitin_0007531c[10];
        tmp42[11] = s_No_servers_could_be_used__Exitin_0007531c[11];
        tmp42[12] = s_No_servers_could_be_used__Exitin_0007531c[12];
        tmp42[13] = s_No_servers_could_be_used__Exitin_0007531c[13];
        tmp42[14] = s_No_servers_could_be_used__Exitin_0007531c[14];
        tmp42[15] = s_No_servers_could_be_used__Exitin_0007531c[15];
        tmp42[16] = s_No_servers_could_be_used__Exitin_0007531c[16];
        tmp42[17] = s_No_servers_could_be_used__Exitin_0007531c[17];
        tmp42[18] = s_No_servers_could_be_used__Exitin_0007531c[18];
        tmp42[19] = s_No_servers_could_be_used__Exitin_0007531c[19];
        tmp42[20] = s_No_servers_could_be_used__Exitin_0007531c[20];
        tmp42[21] = s_No_servers_could_be_used__Exitin_0007531c[21];
        tmp42[22] = s_No_servers_could_be_used__Exitin_0007531c[22];
        tmp42[23] = s_No_servers_could_be_used__Exitin_0007531c[23];
        tmp42[24] = s_No_servers_could_be_used__Exitin_0007531c[24];
        tmp42[25] = s_No_servers_could_be_used__Exitin_0007531c[25];
        tmp42[26] = s_No_servers_could_be_used__Exitin_0007531c[26];
        tmp42[27] = s_No_servers_could_be_used__Exitin_0007531c[27];
        tmp42[28] = s_No_servers_could_be_used__Exitin_0007531c[28];
        tmp42[29] = s_No_servers_could_be_used__Exitin_0007531c[29];
        tmp42[30] = s_No_servers_could_be_used__Exitin_0007531c[30];
        tmp42[31] = s_No_servers_could_be_used__Exitin_0007531c[31];
        tmp42._32_3_ = (undefined3)ram0x0007533c;
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
  iVar5 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,watchpool_thread + 1,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchpool_thread_create_failed_00075340[0];
    tmp42[1] = s_watchpool_thread_create_failed_00075340[1];
    tmp42[2] = s_watchpool_thread_create_failed_00075340[2];
    tmp42[3] = s_watchpool_thread_create_failed_00075340[3];
    tmp42[4] = s_watchpool_thread_create_failed_00075340[4];
    tmp42[5] = s_watchpool_thread_create_failed_00075340[5];
    tmp42[6] = s_watchpool_thread_create_failed_00075340[6];
    tmp42[7] = s_watchpool_thread_create_failed_00075340[7];
    tmp42[8] = s_watchpool_thread_create_failed_00075340[8];
    tmp42[9] = s_watchpool_thread_create_failed_00075340[9];
    tmp42[10] = s_watchpool_thread_create_failed_00075340[10];
    tmp42[11] = s_watchpool_thread_create_failed_00075340[11];
    tmp42[12] = s_watchpool_thread_create_failed_00075340[12];
    tmp42[13] = s_watchpool_thread_create_failed_00075340[13];
    tmp42[14] = s_watchpool_thread_create_failed_00075340[14];
    tmp42[15] = s_watchpool_thread_create_failed_00075340[15];
    tmp42[16] = s_watchpool_thread_create_failed_00075340[16];
    tmp42[17] = s_watchpool_thread_create_failed_00075340[17];
    tmp42[18] = s_watchpool_thread_create_failed_00075340[18];
    tmp42[19] = s_watchpool_thread_create_failed_00075340[19];
    tmp42[20] = s_watchpool_thread_create_failed_00075340[20];
    tmp42[21] = s_watchpool_thread_create_failed_00075340[21];
    tmp42[22] = s_watchpool_thread_create_failed_00075340[22];
    tmp42[23] = s_watchpool_thread_create_failed_00075340[23];
    tmp42[24] = s_watchpool_thread_create_failed_00075340[24];
    tmp42[25] = s_watchpool_thread_create_failed_00075340[25];
    tmp42[26] = s_watchpool_thread_create_failed_00075340[26];
    tmp42[27] = s_watchpool_thread_create_failed_00075340[27];
    tmp42._28_3_ = (undefined3)ram0x0007535c;
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[2].pth);
  ptVar14 = control_thr;
  watchdog_thr_id = 3;
  iVar5 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,watchdog_thread + 1,(void *)0x0);
  if (iVar5 != 0) {
    tmp42[0] = s_watchdog_thread_create_failed_00075360[0];
    tmp42[1] = s_watchdog_thread_create_failed_00075360[1];
    tmp42[2] = s_watchdog_thread_create_failed_00075360[2];
    tmp42[3] = s_watchdog_thread_create_failed_00075360[3];
    tmp42[4] = s_watchdog_thread_create_failed_00075360[4];
    tmp42[5] = s_watchdog_thread_create_failed_00075360[5];
    tmp42[6] = s_watchdog_thread_create_failed_00075360[6];
    tmp42[7] = s_watchdog_thread_create_failed_00075360[7];
    tmp42[8] = s_watchdog_thread_create_failed_00075360[8];
    tmp42[9] = s_watchdog_thread_create_failed_00075360[9];
    tmp42[10] = s_watchdog_thread_create_failed_00075360[10];
    tmp42[11] = s_watchdog_thread_create_failed_00075360[11];
    tmp42[12] = s_watchdog_thread_create_failed_00075360[12];
    tmp42[13] = s_watchdog_thread_create_failed_00075360[13];
    tmp42[14] = s_watchdog_thread_create_failed_00075360[14];
    tmp42[15] = s_watchdog_thread_create_failed_00075360[15];
    tmp42[16] = s_watchdog_thread_create_failed_00075360[16];
    tmp42[17] = s_watchdog_thread_create_failed_00075360[17];
    tmp42[18] = s_watchdog_thread_create_failed_00075360[18];
    tmp42[19] = s_watchdog_thread_create_failed_00075360[19];
    tmp42[20] = s_watchdog_thread_create_failed_00075360[20];
    tmp42[21] = s_watchdog_thread_create_failed_00075360[21];
    tmp42[22] = s_watchdog_thread_create_failed_00075360[22];
    tmp42[23] = s_watchdog_thread_create_failed_00075360[23];
    tmp42[24] = s_watchdog_thread_create_failed_00075360[24];
    tmp42[25] = s_watchdog_thread_create_failed_00075360[25];
    tmp42[26] = s_watchdog_thread_create_failed_00075360[26];
    tmp42[27] = s_watchdog_thread_create_failed_00075360[27];
    tmp42[28] = (char)(short)ram0x0007537c;
    tmp42[29] = (char)((ushort)(short)ram0x0007537c >> 8);
    _applog(3,tmp42,true);
    __quit(1,false);
  }
  pthread_detach(ptVar14[3].pth);
  api_thr_id = 5;
  iVar5 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,api_thread + 1,control_thr + 5);
  if (iVar5 != 0) {
    tmp42[0] = s_API_thread_create_failed_00075380[0];
    tmp42[1] = s_API_thread_create_failed_00075380[1];
    tmp42[2] = s_API_thread_create_failed_00075380[2];
    tmp42[3] = s_API_thread_create_failed_00075380[3];
    tmp42[4] = s_API_thread_create_failed_00075380[4];
    tmp42[5] = s_API_thread_create_failed_00075380[5];
    tmp42[6] = s_API_thread_create_failed_00075380[6];
    tmp42[7] = s_API_thread_create_failed_00075380[7];
    tmp42[8] = s_API_thread_create_failed_00075380[8];
    tmp42[9] = s_API_thread_create_failed_00075380[9];
    tmp42[10] = s_API_thread_create_failed_00075380[10];
    tmp42[11] = s_API_thread_create_failed_00075380[11];
    tmp42[12] = s_API_thread_create_failed_00075380[12];
    tmp42[13] = s_API_thread_create_failed_00075380[13];
    tmp42[14] = s_API_thread_create_failed_00075380[14];
    tmp42[15] = s_API_thread_create_failed_00075380[15];
    tmp42[16] = s_API_thread_create_failed_00075380[16];
    tmp42[17] = s_API_thread_create_failed_00075380[17];
    tmp42[18] = s_API_thread_create_failed_00075380[18];
    tmp42[19] = s_API_thread_create_failed_00075380[19];
    tmp42[20] = s_API_thread_create_failed_00075380[20];
    tmp42[21] = s_API_thread_create_failed_00075380[21];
    tmp42[22] = s_API_thread_create_failed_00075380[22];
    tmp42[23] = s_API_thread_create_failed_00075380[23];
    tmp42[24] = (char)ram0x00075398;
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
    while( true ) {
      iVar5 = max_queue;
      if (opt_work_update != false) {
        signal_work_update();
      }
      opt_work_update = false;
      _mutex_lock(stgd_lock,"cgminer.c","main",0x2f51);
      ts = __total_staged();
      if (iVar5 < ts) {
        work_filled = true;
        pthread_cond_wait((pthread_cond_t *)&gws_cond,(pthread_mutex_t *)stgd_lock);
        ts = __total_staged();
      }
      _mutex_unlock(stgd_lock,"cgminer.c","main",0x2f5c);
      if (iVar5 < ts) break;
      if (work != (work *)0x0) {
        _discard_work(&work,"cgminer.c","main",0x2f70);
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
              tmp42[0] = s_Generated_benchmark_work_00075404[0];
              tmp42[1] = s_Generated_benchmark_work_00075404[1];
              tmp42[2] = s_Generated_benchmark_work_00075404[2];
              tmp42[3] = s_Generated_benchmark_work_00075404[3];
              tmp42[4] = s_Generated_benchmark_work_00075404[4];
              tmp42[5] = s_Generated_benchmark_work_00075404[5];
              tmp42[6] = s_Generated_benchmark_work_00075404[6];
              tmp42[7] = s_Generated_benchmark_work_00075404[7];
              tmp42[8] = s_Generated_benchmark_work_00075404[8];
              tmp42[9] = s_Generated_benchmark_work_00075404[9];
              tmp42[10] = s_Generated_benchmark_work_00075404[10];
              tmp42[11] = s_Generated_benchmark_work_00075404[11];
              tmp42[12] = s_Generated_benchmark_work_00075404[12];
              tmp42[13] = s_Generated_benchmark_work_00075404[13];
              tmp42[14] = s_Generated_benchmark_work_00075404[14];
              tmp42[15] = s_Generated_benchmark_work_00075404[15];
              tmp42[16] = s_Generated_benchmark_work_00075404[16];
              tmp42[17] = s_Generated_benchmark_work_00075404[17];
              tmp42[18] = s_Generated_benchmark_work_00075404[18];
              tmp42[19] = s_Generated_benchmark_work_00075404[19];
              tmp42[20] = s_Generated_benchmark_work_00075404[20];
              tmp42[21] = s_Generated_benchmark_work_00075404[21];
              tmp42[22] = s_Generated_benchmark_work_00075404[22];
              tmp42[23] = s_Generated_benchmark_work_00075404[23];
              tmp42[24] = (char)ram0x0007541c;
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
            tmp42[0] = s_Generated_benchfile_work_000753e8[0];
            tmp42[1] = s_Generated_benchfile_work_000753e8[1];
            tmp42[2] = s_Generated_benchfile_work_000753e8[2];
            tmp42[3] = s_Generated_benchfile_work_000753e8[3];
            tmp42[4] = s_Generated_benchfile_work_000753e8[4];
            tmp42[5] = s_Generated_benchfile_work_000753e8[5];
            tmp42[6] = s_Generated_benchfile_work_000753e8[6];
            tmp42[7] = s_Generated_benchfile_work_000753e8[7];
            tmp42[8] = s_Generated_benchfile_work_000753e8[8];
            tmp42[9] = s_Generated_benchfile_work_000753e8[9];
            tmp42[10] = s_Generated_benchfile_work_000753e8[10];
            tmp42[11] = s_Generated_benchfile_work_000753e8[11];
            tmp42[12] = s_Generated_benchfile_work_000753e8[12];
            tmp42[13] = s_Generated_benchfile_work_000753e8[13];
            tmp42[14] = s_Generated_benchfile_work_000753e8[14];
            tmp42[15] = s_Generated_benchfile_work_000753e8[15];
            tmp42[16] = s_Generated_benchfile_work_000753e8[16];
            tmp42[17] = s_Generated_benchfile_work_000753e8[17];
            tmp42[18] = s_Generated_benchfile_work_000753e8[18];
            tmp42[19] = s_Generated_benchfile_work_000753e8[19];
            tmp42[20] = s_Generated_benchfile_work_000753e8[20];
            tmp42[21] = s_Generated_benchfile_work_000753e8[21];
            tmp42[22] = s_Generated_benchfile_work_000753e8[22];
            tmp42[23] = s_Generated_benchfile_work_000753e8[23];
            tmp42[24] = (char)ram0x00075400;
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
          tmp42[0] = s_Generated_stratum_work_000753d0[0];
          tmp42[1] = s_Generated_stratum_work_000753d0[1];
          tmp42[2] = s_Generated_stratum_work_000753d0[2];
          tmp42[3] = s_Generated_stratum_work_000753d0[3];
          tmp42[4] = s_Generated_stratum_work_000753d0[4];
          tmp42[5] = s_Generated_stratum_work_000753d0[5];
          tmp42[6] = s_Generated_stratum_work_000753d0[6];
          tmp42[7] = s_Generated_stratum_work_000753d0[7];
          tmp42[8] = s_Generated_stratum_work_000753d0[8];
          tmp42[9] = s_Generated_stratum_work_000753d0[9];
          tmp42[10] = s_Generated_stratum_work_000753d0[10];
          tmp42[11] = s_Generated_stratum_work_000753d0[11];
          tmp42[12] = s_Generated_stratum_work_000753d0[12];
          tmp42[13] = s_Generated_stratum_work_000753d0[13];
          tmp42[14] = s_Generated_stratum_work_000753d0[14];
          tmp42[15] = s_Generated_stratum_work_000753d0[15];
          tmp42[16] = s_Generated_stratum_work_000753d0[16];
          tmp42[17] = s_Generated_stratum_work_000753d0[17];
          tmp42[18] = s_Generated_stratum_work_000753d0[18];
          tmp42[19] = s_Generated_stratum_work_000753d0[19];
          tmp42._20_3_ = (undefined3)ram0x000753e4;
          _applog(7,tmp42,false);
        }
        _stage_work(work);
        work = (work *)0x0;
      }
    }
    work_filled = true;
    work = hash_pop(false);
    if (work != (work *)0x0) {
      _discard_work(&work,"cgminer.c","main",0x2f68);
    }
  } while( true );
}

