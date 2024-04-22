
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int main(int argc,char **argv)

{
  undefined2 uVar1;
  cgpu_info **ppcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char **ppcVar10;
  opt_table *entry;
  device_drv *drv;
  device_drv *drv_00;
  device_drv *drv_01;
  undefined *__rwlock;
  undefined *puVar11;
  __start_routine *__start_routine;
  long *plVar12;
  pthread_cond_t *__cond;
  pthread_mutex_t *ppVar13;
  thr_info *ptVar14;
  _Bool _Var15;
  uint uVar16;
  long lVar17;
  char **ppcVar18;
  undefined4 uVar19;
  int iVar20;
  thread_q *ptVar21;
  char *pcVar22;
  char *s;
  size_t sVar23;
  block *__s;
  block *block;
  uint _hj_k;
  UT_hash_bucket *_he_new_buckets;
  pool *ppVar24;
  pool *pool;
  undefined4 *puVar25;
  FILE *pFVar26;
  FILE *fpversion;
  sysinfo *psVar27;
  char *nextptr;
  void *pvVar28;
  size_t sVar29;
  int r;
  __sighandler_t p_Var30;
  sighandler_t sr0;
  __sighandler_t p_Var31;
  sighandler_t sr1;
  thr_info **pptVar32;
  int *piVar33;
  time_t tVar34;
  int ret;
  pool *cp_1;
  pool *ppVar35;
  cgpu_info *cgpu_1;
  pool *pool_2;
  thr_info **pptVar36;
  uint uVar37;
  uint uVar38;
  UT_hash_handle *pUVar39;
  UT_hash_bucket *pUVar40;
  thr_info *ptVar41;
  undefined4 *puVar42;
  undefined8 *puVar43;
  uint uVar44;
  UT_hash_table *pUVar45;
  UT_hash_handle *pUVar46;
  char *pcVar47;
  pool_enable pVar48;
  int *piVar49;
  int *piVar50;
  int *piVar51;
  device_drv *pdVar52;
  _func__Bool_thr_info_ptr *p_Var53;
  dev_enable dVar54;
  undefined8 *puVar55;
  pool *pool_3;
  pool *tp;
  pool *tp_1;
  thr_info **pptVar56;
  uint *puVar57;
  int iVar58;
  UT_hash_handle *_he_thh;
  int iVar59;
  int i;
  pool *pool_1;
  cgpu_info *pcVar60;
  cgpu_info *cgpu;
  int i_1;
  int ts;
  int iVar61;
  block *pbVar62;
  int iVar63;
  FILE **ppFVar64;
  size_t siz;
  char *pcVar65;
  int iVar66;
  thr_info *thr;
  UT_hash_handle *pUVar67;
  UT_hash_handle *_he_hh_nxt;
  uchar *_hj_key;
  thr_info *ptVar68;
  UT_hash_bucket *_he_newbkt;
  pool *pool_4;
  bool bVar69;
  undefined4 in_stack_ffffd5fc;
  char acStack_29f8 [4104];
  undefined4 local_19f0;
  undefined4 uStack_19ec;
  undefined local_19e8;
  undefined4 local_9f8;
  thr_info *local_9e8;
  thr_info *local_9e4;
  int **ppiStack_9e0;
  char *pcStack_9dc;
  int *local_9d8;
  thr_info **pptStack_9d4;
  block *local_9d0;
  thr_info *local_9cc;
  block *local_9c8;
  char **local_9c4;
  pool *pool_6;
  int local_9bc;
  work *work;
  sigaction handler;
  sysinfo sInfo;
  char tmp42 [2048];
  
  puVar57 = DAT_0000af34;
  uVar16 = *DAT_0000af2c;
  uVar37 = DAT_0000af2c[2];
  g_logfile_openflag[2] = *(char *)(DAT_0000af30 + 1);
  uVar44 = (uint)(byte)g_logfile_openflag[2];
  g_logfile_openflag._0_2_ = *DAT_0000af30;
  DAT_0000af34[1] = DAT_0000af2c[1];
  puVar57[2] = uVar37;
  *puVar57 = uVar16;
  g_logfile_enable = false;
  work = (work *)0x0;
  local_9c4 = argv;
  local_9bc = argc;
  lVar17 = sysconf(0x54);
  pcVar65 = DAT_0000af44;
  pcVar22 = DAT_0000af40;
  if (lVar17 == 1) {
    puVar57 = DAT_0000af3c;
    uVar44 = DAT_0000af38;
  }
  if (lVar17 == 1) {
    *puVar57 = uVar44;
  }
  ppcVar18 = (char **)_cgmalloc((local_9bc + 1) * 4,pcVar22,pcVar65,0x2c9f);
  ppcVar10 = local_9c4;
  initial_args = ppcVar18;
  if (0 < local_9bc) {
    iVar58 = 0;
    iVar61 = 0;
    do {
      iVar61 = iVar61 + 1;
      uVar19 = __strdup(*(undefined4 *)((int)ppcVar10 + iVar58));
      *(undefined4 *)((int)ppcVar18 + iVar58) = uVar19;
      iVar58 = iVar58 + 4;
    } while (iVar61 < local_9bc);
  }
  ppcVar18[local_9bc] = (char *)0x0;
  iVar61 = local_9bc;
  _mutex_init(DAT_0000af48,DAT_0000af44,(char *)0x2ca8,local_9bc);
  iVar58 = DAT_0000af50;
  _mutex_init(DAT_0000af4c,DAT_0000af44,(char *)0x2ca9,iVar61);
  _mutex_init(DAT_0000af54,DAT_0000af44,(char *)0x2caa,iVar61);
  _cglock_init(DAT_0000af58,DAT_0000af44,(char *)0x2cab,iVar61);
  _mutex_init(DAT_0000af5c,DAT_0000af44,(char *)0x2cac,iVar61);
  _mutex_init((pthread_mutex_t *)(iVar58 + 0x500),DAT_0000af44,(char *)0x2cad,iVar61);
  _cglock_init(DAT_0000af60,DAT_0000af44,(char *)0x2cae,iVar61);
  _mutex_init((pthread_mutex_t *)(iVar58 + 0x468),DAT_0000af44,(char *)0x2caf,iVar61);
  _rwlock_init((pthread_rwlock_t *)(iVar58 + 0x6d4),DAT_0000af44,(char *)0x2cb0,iVar61);
  _rwlock_init(DAT_0000af64,DAT_0000af44,(char *)0x2cb1,iVar61);
  _rwlock_init(DAT_0000af68,DAT_0000af44,(char *)0x2cb2,iVar61);
  _rwlock_init(DAT_0000af6c,DAT_0000af44,(char *)0x2cb3,iVar61);
  _mutex_init((pthread_mutex_t *)(iVar58 + 0x49c),DAT_0000af44,(char *)0x2cb5,iVar61);
  iVar20 = pthread_cond_init((pthread_cond_t *)(iVar58 + 0x4b8),(pthread_condattr_t *)0x0);
  if (iVar20 != 0) {
    tmp42._0_4_ = *DAT_0000bd00;
    tmp42._4_4_ = DAT_0000bd00[1];
    tmp42._8_4_ = DAT_0000bd00[2];
    tmp42._12_4_ = DAT_0000bd00[3];
    tmp42._16_4_ = DAT_0000bd00[4];
    tmp42._20_4_ = DAT_0000bd00[5];
    tmp42._24_4_ = DAT_0000bd00[6];
    tmp42._28_4_ = DAT_0000bd00[7];
    tmp42._32_4_ = DAT_0000bd00[8];
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  _mutex_init(DAT_0000af70,DAT_0000af44,(char *)0x2cbc,iVar61);
  iVar61 = pthread_cond_init(DAT_0000af74,(pthread_condattr_t *)0x0);
  if (iVar61 != 0) {
    tmp42._0_4_ = *DAT_0000c074;
    tmp42._4_4_ = DAT_0000c074[1];
    tmp42._8_4_ = DAT_0000c074[2];
    tmp42._12_4_ = DAT_0000c074[3];
    tmp42._16_4_ = DAT_0000c074[4];
    tmp42._20_4_ = DAT_0000c074[5];
    tmp42._24_4_ = DAT_0000c074[6];
    tmp42._28_4_ = DAT_0000c074[7];
    tmp42._32_4_ = DAT_0000c074[8];
    tmp42._36_4_ = DAT_0000c074[9];
    tmp42[40] = (char)DAT_0000c074[10];
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  iVar61 = pthread_cond_init(DAT_0000af78,(pthread_condattr_t *)0x0);
  if (iVar61 != 0) {
    tmp42._0_4_ = *DAT_0000c070;
    tmp42._4_4_ = DAT_0000c070[1];
    tmp42._8_4_ = DAT_0000c070[2];
    tmp42._12_4_ = DAT_0000c070[3];
    tmp42._16_4_ = DAT_0000c070[4];
    tmp42._20_4_ = DAT_0000c070[5];
    tmp42._24_4_ = DAT_0000c070[6];
    tmp42._28_4_ = DAT_0000c070[7];
    tmp42._32_4_ = DAT_0000c070[8];
    tmp42[36] = (char)DAT_0000c070[9];
LAB_0000bfd4:
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  ptVar21 = tq_new();
  *DAT_0000af7c = ptVar21;
  local_9f8 = DAT_0000af80;
  if (ptVar21 == (thread_q *)0x0) {
    tmp42._0_4_ = *DAT_0000c06c;
    tmp42._4_4_ = DAT_0000c06c[1];
    tmp42._8_4_ = DAT_0000c06c[2];
    tmp42._12_4_ = DAT_0000c06c[3];
    tmp42._16_4_ = DAT_0000c06c[4];
    tmp42[20] = (char)(short)DAT_0000c06c[5];
    tmp42[21] = (char)((ushort)(short)DAT_0000c06c[5] >> 8);
    goto LAB_0000bfd4;
  }
  *(pthread_mutex_t **)(iVar58 + 0x454) = &ptVar21->mutex;
  snprintf((char *)(iVar58 + 0x1c),0x100,DAT_0000af84,DAT_0000af88);
  ppcVar10 = DAT_0000af90;
  iVar20 = 0x24;
  handler.__sigaction_handler = DAT_0000af8c;
  handler.sa_flags = iVar61;
  sigemptyset((sigset_t *)&handler.sa_mask);
  sigaction(0xf,(sigaction *)&handler,DAT_0000af94);
  sigaction(2,(sigaction *)&handler,DAT_0000af98);
  sigaction(6,(sigaction *)&handler,DAT_0000af9c);
  opt_kernel_path = (char *)&local_19f0;
  local_19f0 = *DAT_0000afa0;
  uStack_19ec = DAT_0000afa0[1];
  local_19e8 = (undefined)DAT_0000afa0[2];
  *ppcVar10 = acStack_29f8;
  pcVar22 = (char *)__strdup(*local_9c4);
  pcVar65 = *ppcVar10;
  s = dirname(pcVar22);
  strcpy(pcVar65,s);
  free(pcVar22);
  iVar58 = DAT_0000afa4;
  pcVar22 = *ppcVar10;
  sVar23 = strlen(pcVar22);
  *(undefined2 *)(pcVar22 + sVar23) = s__bmminer__0004bfec._8_2_;
  *(undefined4 *)(iVar58 + 0xa7c) = 9;
  *(undefined4 *)(iVar58 + 0xa80) = 10;
  *(undefined4 *)(iVar58 + 0xa78) = 8;
  pcVar22 = (char *)0x2ceb;
  __s = (block *)_cgcalloc(0x68,1,DAT_0000af40,DAT_0000af44,0x2ceb);
  uVar1 = *DAT_0000afa8;
  do {
    sVar23 = strlen((char *)__s);
    iVar20 = iVar20 + -1;
    *(undefined2 *)(__s->hash + sVar23) = uVar1;
  } while (iVar20 != 0);
  pool_6 = (pool *)strlen((char *)__s);
  uVar44 = 0x9e3779b9;
  uVar37 = 0xfeedbeef;
  uVar16 = uVar44;
  pbVar62 = __s;
  for (ppVar24 = pool_6; (pool *)0xb < ppVar24; ppVar24 = (pool *)&ppVar24[-1].tv_lastwork) {
    pcVar65 = pbVar62->hash;
    pcVar47 = pbVar62->hash;
    pcVar4 = pbVar62->hash;
    pcVar5 = pbVar62->hash;
    pcVar6 = pbVar62->hash;
    pcVar7 = pbVar62->hash;
    pcVar8 = pbVar62->hash;
    pcVar9 = pbVar62->hash;
    iVar61 = uVar16 + (uint)(byte)pbVar62->hash[6] * 0x10000 + (uint)(byte)pbVar62->hash[5] * 0x100
                      + (uint)(byte)pbVar62->hash[4] + (uint)(byte)pbVar62->hash[7] * 0x1000000;
    pbVar62 = (block *)(pbVar62->hash + 0xc);
    uVar37 = uVar37 + (uint)(byte)pcVar8[8] +
                      (uint)(byte)pcVar47[10] * 0x10000 + (uint)(byte)pcVar5[9] * 0x100 +
                      (uint)(byte)pcVar9[0xb] * 0x1000000;
    uVar16 = uVar44 + ((((uint)(byte)*pcVar6 +
                         (uint)(byte)pcVar65[2] * 0x10000 + (uint)(byte)pcVar4[1] * 0x100 +
                        (uint)(byte)pcVar7[3] * 0x1000000) - iVar61) - uVar37) ^ uVar37 >> 0xd;
    uVar38 = (iVar61 - uVar37) - uVar16 ^ uVar16 << 8;
    uVar44 = (uVar37 - uVar16) - uVar38 ^ uVar38 >> 0xd;
    uVar16 = (uVar16 - uVar38) - uVar44 ^ uVar44 >> 0xc;
    uVar38 = (uVar38 - uVar44) - uVar16 ^ uVar16 << 0x10;
    uVar37 = (uVar44 - uVar16) - uVar38 ^ uVar38 >> 5;
    uVar44 = (uVar16 - uVar38) - uVar37 ^ uVar37 >> 3;
    uVar16 = (uVar38 - uVar37) - uVar44 ^ uVar44 << 10;
    uVar37 = (uVar37 - uVar44) - uVar16 ^ uVar16 >> 0xf;
    local_9c8 = __s;
  }
  pcVar65 = pool_6->diff + (uVar37 - 0x30);
  switch(ppVar24) {
  case (pool *)0xb:
    pcVar65 = pcVar65 + (uint)(byte)pbVar62->hash[10] * 0x1000000;
  case (pool *)0xa:
    pcVar65 = pcVar65 + (uint)(byte)pbVar62->hash[9] * 0x10000;
  case (pool *)0x9:
    pcVar65 = pcVar65 + (uint)(byte)pbVar62->hash[8] * 0x100;
  case (pool *)0x8:
    uVar16 = uVar16 + (uint)(byte)pbVar62->hash[7] * 0x1000000;
  case (pool *)0x7:
    uVar16 = uVar16 + (uint)(byte)pbVar62->hash[6] * 0x10000;
  case (pool *)0x6:
    uVar16 = uVar16 + (uint)(byte)pbVar62->hash[5] * 0x100;
  case (pool *)0x5:
    uVar16 = uVar16 + (byte)pbVar62->hash[4];
  case (pool *)0x4:
    uVar44 = uVar44 + (uint)(byte)pbVar62->hash[3] * 0x1000000;
  case (pool *)0x3:
    uVar44 = uVar44 + (uint)(byte)pbVar62->hash[2] * 0x10000;
  case (pool *)0x2:
    uVar44 = uVar44 + (uint)(byte)pbVar62->hash[1] * 0x100;
  case (pool *)0x1:
    uVar44 = uVar44 + (byte)pbVar62->hash[0];
  }
  (__s->hh).key = __s;
  uVar44 = (uVar44 - uVar16) - (int)pcVar65 ^ (uint)pcVar65 >> 0xd;
  uVar16 = (uVar16 - (int)pcVar65) - uVar44 ^ uVar44 << 8;
  uVar37 = (uint)(pcVar65 + (-uVar16 - uVar44)) ^ uVar16 >> 0xd;
  uVar44 = (uVar44 - uVar16) - uVar37 ^ uVar37 >> 0xc;
  uVar16 = (uVar16 - uVar37) - uVar44 ^ uVar44 << 0x10;
  uVar37 = (uVar37 - uVar44) - uVar16 ^ uVar16 >> 5;
  uVar44 = (uVar44 - uVar16) - uVar37 ^ uVar37 >> 3;
  uVar16 = (uVar16 - uVar37) - uVar44 ^ uVar44 << 10;
  uVar44 = (uVar37 - uVar44) - uVar16 ^ uVar16 >> 0xf;
  (__s->hh).hashv = uVar44;
  sVar23 = strlen((char *)__s);
  (__s->hh).keylen = sVar23;
  pbVar62 = blocks;
  iVar61 = DAT_0000b348;
  if (blocks == (block *)0x0) {
    (__s->hh).next = (void *)0x0;
    (__s->hh).prev = (void *)0x0;
    *(block **)(iVar61 + 0x6f4) = __s;
    pUVar45 = (UT_hash_table *)malloc(0x2c);
    (__s->hh).tbl = pUVar45;
    if (pUVar45 == (UT_hash_table *)0x0) goto LAB_0000bf48;
    memset(pUVar45,0,0x2c);
    pUVar45 = (__s->hh).tbl;
    pUVar45->tail = &__s->hh;
    pUVar45->num_buckets = 0x20;
    pUVar45->log2_num_buckets = 5;
    pUVar45->hho = 0x44;
    pUVar40 = (UT_hash_bucket *)malloc(0x180);
    pUVar45->buckets = pUVar40;
    if (pUVar40 == (UT_hash_bucket *)0x0) goto LAB_0000bf48;
    memset(pUVar40,0,0x180);
    ((__s->hh).tbl)->signature = 0xa0111fe1;
    pbVar62 = __s;
  }
  else {
    pUVar45 = (blocks->hh).tbl;
    (__s->hh).next = (void *)0x0;
    (__s->hh).tbl = pUVar45;
    pUVar45 = (pbVar62->hh).tbl;
    pUVar39 = pUVar45->tail;
    iVar61 = pUVar45->hho;
    pUVar39->next = __s;
    (__s->hh).prev = (void *)((int)pUVar39 - iVar61);
    pUVar45->tail = &__s->hh;
  }
  pUVar45 = (pbVar62->hh).tbl;
  pUVar40 = pUVar45->buckets;
  uVar44 = uVar44 & pUVar45->num_buckets - 1;
  pUVar45->num_items = pUVar45->num_items + 1;
  pUVar39 = pUVar40[uVar44].hh_head;
  uVar16 = pUVar40[uVar44].count + 1;
  pUVar40[uVar44].count = uVar16;
  (__s->hh).hh_next = pUVar39;
  (__s->hh).hh_prev = (UT_hash_handle *)0x0;
  if (pUVar39 != (UT_hash_handle *)0x0) {
    pUVar39->hh_prev = &__s->hh;
  }
  pUVar40[uVar44].hh_head = &__s->hh;
  if (((pUVar40[uVar44].expand_mult + 1) * 10 <= uVar16) &&
     (pUVar45 = (__s->hh).tbl, pUVar45->noexpand != 1)) {
    sVar23 = pUVar45->num_buckets * 0x18;
    pUVar40 = (UT_hash_bucket *)malloc(sVar23);
    if (pUVar40 == (UT_hash_bucket *)0x0) {
LAB_0000bf48:
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    memset(pUVar40,0,sVar23);
    pUVar45 = (__s->hh).tbl;
    uVar16 = pUVar45->num_buckets;
    pUVar45->nonideal_items = 0;
    pool_6 = (pool *)(uVar16 * 2 - 1);
    uVar44 = pUVar45->num_items >> (pUVar45->log2_num_buckets + 1 & 0xff);
    if (((uint)pool_6 & pUVar45->num_items) != 0) {
      uVar44 = uVar44 + 1;
    }
    pUVar45->ideal_chain_maxlen = uVar44;
    if (uVar16 == 0) {
      local_9c8 = (block *)pUVar45->buckets;
    }
    else {
      local_9c8 = (block *)pUVar45->buckets;
      local_9cc = (thr_info *)(uVar16 * 0xc);
      ptVar41 = (thr_info *)0x0;
      local_9d0 = __s;
      do {
        pUVar39 = *(UT_hash_handle **)((int)&ptVar41->id + (int)local_9c8->hash);
        ptVar68 = local_9e8;
        ptVar14 = local_9e4;
        __s = local_9d0;
        while (local_9e4 = ptVar41, local_9d0 = __s, pUVar39 != (UT_hash_handle *)0x0) {
          pUVar67 = pUVar39->hh_next;
          uVar37 = (uint)pool_6 & pUVar39->hashv;
          local_9e8 = (thr_info *)(pUVar40 + uVar37);
          uVar16 = local_9e8->device_thread + 1;
          local_9e8->device_thread = uVar16;
          ptVar41 = local_9e4;
          if (uVar44 < uVar16) {
            pUVar45->nonideal_items = pUVar45->nonideal_items + 1;
            uVar19 = __aeabi_uidiv(uVar16,uVar44);
            *(undefined4 *)&local_9e8->primary_thread = uVar19;
            ptVar41 = local_9e4;
            ptVar68 = local_9e8;
            ptVar14 = local_9e4;
          }
          local_9e4 = ptVar14;
          local_9e8 = ptVar68;
          pUVar46 = pUVar40[uVar37].hh_head;
          pUVar39->hh_prev = (UT_hash_handle *)0x0;
          pUVar39->hh_next = pUVar46;
          if (pUVar46 != (UT_hash_handle *)0x0) {
            pUVar46->hh_prev = pUVar39;
          }
          pUVar40[uVar37].hh_head = pUVar39;
          pUVar39 = pUVar67;
          ptVar68 = local_9e8;
          ptVar14 = local_9e4;
          __s = local_9d0;
        }
        ptVar41 = (thr_info *)&local_9e4->pth;
        local_9e8 = ptVar68;
        local_9e4 = ptVar14;
      } while (ptVar41 != local_9cc);
    }
    free(local_9c8);
    pUVar45 = (__s->hh).tbl;
    uVar37 = pUVar45->nonideal_items;
    pUVar45->buckets = pUVar40;
    uVar44 = pUVar45->num_items >> 1;
    uVar16 = uVar37;
    if (uVar37 <= uVar44) {
      uVar16 = 0;
    }
    pUVar45->log2_num_buckets = pUVar45->log2_num_buckets + 1;
    pUVar45->num_buckets = pUVar45->num_buckets << 1;
    if (uVar44 < uVar37) {
      uVar16 = pUVar45->ineff_expands + 1;
      pUVar45->ineff_expands = uVar16;
      uVar44 = uVar16;
      if (1 < uVar16) {
        uVar44 = 1;
      }
      if (1 < uVar16) {
        pUVar45->noexpand = uVar44;
      }
    }
    else {
      pUVar45->ineff_expands = uVar16;
    }
  }
  strcpy(DAT_0000b34c,__s->hash);
  pcVar65 = DAT_0000b358;
  entry = DAT_0000b354;
  iVar61 = DAT_0000b350;
  *(int *)DAT_0000b350 = DAT_0000b350;
  *(int *)(iVar61 + 4) = iVar61;
  opt_register_table(entry,pcVar65);
  opt_register_table(DAT_0000b35c,DAT_0000b360);
  opt_parse(&local_9bc,local_9c4,DAT_0000b364);
  iVar61 = DAT_0000b680;
  if (local_9bc != 1) {
    tmp42._0_4_ = *DAT_0000b368;
    tmp42._4_4_ = DAT_0000b368[1];
    tmp42._8_4_ = DAT_0000b368[2];
    tmp42._12_4_ = DAT_0000b368[3];
    tmp42._16_4_ = DAT_0000b368[4];
    tmp42._20_4_ = DAT_0000b368[5];
    tmp42._24_4_ = DAT_0000b368[6];
    tmp42._28_4_ = DAT_0000b368[7];
    tmp42._32_4_ = DAT_0000b368[8];
    tmp42._36_3_ = (undefined3)DAT_0000b368[9];
    _applog(3,tmp42,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  if (config_loaded == false) {
    pcVar65 = (char *)_cgmalloc(0x1000,DAT_0000c36c,DAT_0000c370,0x812);
    *(char **)(iVar61 + 0x340) = pcVar65;
    default_save_file(pcVar65);
    iVar20 = access(*(char **)(iVar61 + 0x340),4);
    if (iVar20 == 0) {
      load_config(*(char **)(iVar61 + 0x340),(void *)0x0);
    }
    else {
      free(*(char **)(iVar61 + 0x340));
      *(undefined4 *)(iVar61 + 0x340) = 0;
    }
  }
  if ((opt_benchmark != false) || (*(int *)(DAT_0000b680 + 0x448) != 0)) {
    ppVar24 = add_pool();
    puVar25 = (undefined4 *)_cgmalloc(0xff,DAT_0000b688,(char *)DAT_0000b684,0x2d0f);
    pcVar65 = opt_benchfile;
    ppVar24->rpc_url = (char *)puVar25;
    puVar42 = DAT_0000c368;
    if (pcVar65 != (char *)0x0) {
      puVar42 = DAT_0000b68c;
    }
    uVar19 = puVar42[1];
    uVar1 = *(undefined2 *)(puVar42 + 2);
    *puVar25 = *puVar42;
    puVar25[1] = uVar19;
    *(undefined2 *)(puVar25 + 2) = uVar1;
    pcVar65 = DAT_0000b690;
    pcVar47 = ppVar24->rpc_url;
    ppVar24->rpc_user = pcVar47;
    ppVar24->rpc_pass = pcVar47;
    ppVar24->rpc_userpass = pcVar47;
    ppVar24->sockaddr_url = pcVar47;
    strncpy(ppVar24->diff,pcVar65,7);
    pVar48 = ppVar24->enabled;
    ppVar24->diff[7] = '\0';
    piVar33 = DAT_0000b694;
    if (pVar48 != POOL_ENABLED) {
      ppVar24->enabled = POOL_ENABLED;
      *piVar33 = *piVar33 + 1;
    }
    iVar20 = DAT_0000b6d0;
    iVar61 = DAT_0000b6cc;
    local_9e4 = DAT_0000b698;
    iVar63 = 0;
    ppVar24->idle = false;
    *DAT_0000b69c = 1;
    do {
      iVar59 = iVar63 * 0x144;
      iVar66 = iVar63 * 0xa0;
      iVar63 = iVar63 + 1;
      hex2bin((uchar *)((int)local_9e4 + iVar66),(char *)(iVar61 + iVar59),0xa0);
      hex2bin((uchar *)(iVar20 + iVar66),(char *)(DAT_0000b6d4 + iVar59),0xa0);
    } while (iVar63 != 0x10);
    set_target(DAT_0000b6a0,(double)CONCAT44(in_stack_ffffd5fc,pcVar22));
  }
  if (opt_version_path == (char *)0x0) {
    local_9c4 = (char **)tmp42;
    local_9cc = DAT_0000c358;
    local_9d0 = (block *)DAT_0000c35c;
  }
  else {
    pFVar26 = fopen(opt_version_path,DAT_0000b6a4);
    memset(&sInfo,0,0x100);
    if (pFVar26 == (FILE *)0x0) {
      local_9cc = DAT_0000c358;
      if (((*(char *)&DAT_0000c358->id != '\0') ||
          (local_9d0 = (block *)DAT_0000c35c, *DAT_0000c35c != '\0')) || (2 < *DAT_0000c360)) {
        local_9d0 = (block *)DAT_0000c35c;
        local_9c4 = (char **)tmp42;
        snprintf((char *)local_9c4,0x800,DAT_0000c364,opt_version_path);
        _applog(3,(char *)local_9c4,false);
        goto LAB_0000b544;
      }
      local_9c4 = (char **)tmp42;
LAB_0000b54a:
      if ((local_9d0->hash[0] == '\0') && (*DAT_0000b6b8 < 3)) goto LAB_0000b57a;
    }
    else {
      psVar27 = (sysinfo *)fread(&sInfo,1,0x100,pFVar26);
      if ((int)psVar27 < 1) {
        local_9cc = DAT_0000c358;
        if (*(char *)&DAT_0000c358->id == '\0') {
          local_9d0 = (block *)DAT_0000c35c;
          if ((*DAT_0000c35c == '\0') && (*DAT_0000c360 < 3)) {
            local_9c4 = (char **)tmp42;
            goto LAB_0000b54a;
          }
        }
        else {
          local_9d0 = (block *)DAT_0000cef0;
        }
        local_9c4 = (char **)tmp42;
        snprintf((char *)local_9c4,0x800,DAT_0000cef4,opt_version_path,psVar27);
        _applog(3,(char *)local_9c4,false);
        pcVar22 = (char *)psVar27;
      }
      else {
        pcVar65 = strchr((char *)&sInfo,10);
        if (pcVar65 == (char *)0x0) {
          strcpy(DAT_0000c068,(char *)&sInfo);
        }
        else {
          pcVar22 = (char *)DAT_0000b684;
          _cg_memcpy(DAT_0000b6a8,&sInfo,(int)pcVar65 - (int)&sInfo,DAT_0000b688,
                     (char *)DAT_0000b684,0x2d4a);
          strcpy((char *)DAT_0000b6ac,pcVar65 + 1);
        }
        sVar23 = strlen(DAT_0000b6a8);
        pcVar65 = DAT_0000b6a8;
        iVar61 = iVar58 + (sVar23 - 1);
        if (*(char *)(iVar61 + 0xa84) == '\n') {
          *(undefined *)(iVar61 + 0xa84) = 0;
        }
        sVar23 = strlen(pcVar65);
        psVar27 = DAT_0000b6ac;
        iVar61 = iVar58 + (sVar23 - 1);
        if (*(char *)(iVar61 + 0xa84) == '\r') {
          *(undefined *)(iVar61 + 0xa84) = 0;
        }
        sVar23 = strlen((char *)psVar27);
        psVar27 = DAT_0000b6ac;
        iVar61 = iVar58 + (sVar23 - 1);
        if (*(char *)(iVar61 + 0xb84) == '\n') {
          *(undefined *)(iVar61 + 0xb84) = 0;
        }
        sVar23 = strlen((char *)psVar27);
        iVar61 = iVar58 + (sVar23 - 1);
        if (*(char *)(iVar61 + 0xb84) == '\r') {
          local_9cc = DAT_0000c060;
          local_9c4 = (char **)tmp42;
          local_9d0 = (block *)DAT_0000c064;
          *(undefined *)(iVar61 + 0xb84) = 0;
        }
        else {
          local_9c4 = (char **)tmp42;
          local_9cc = DAT_0000b6b0;
          local_9d0 = (block *)DAT_0000b6b4;
        }
      }
LAB_0000b544:
      if (*(char *)&local_9cc->id == '\0') goto LAB_0000b54a;
    }
    pcVar22 = (char *)DAT_0000b6ac;
    snprintf((char *)local_9c4,0x800,DAT_0000b6bc,DAT_0000b6ac + -4,DAT_0000b6ac);
    _applog(3,(char *)local_9c4,false);
  }
LAB_0000b57a:
  iVar61 = DAT_0000b680;
  if (opt_logfile_path != (char *)0x0) {
    g_logfile_enable = true;
    strcpy(DAT_0000b6c0,opt_logfile_path);
    if (*(char **)(iVar61 + 0x14) != (char *)0x0) {
      strcpy(DAT_0000b6c4,*(char **)(iVar61 + 0x14));
    }
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *DAT_0000b6b8))
    {
      pcVar22 = g_logfile_openflag;
      snprintf((char *)local_9c4,0x800,DAT_0000b6c8,DAT_0000b6c0,g_logfile_openflag);
      _applog(3,(char *)local_9c4,false);
    }
  }
  pcVar65 = opt_logwork_path;
  iVar61 = DAT_0000b680;
  if (opt_logwork_path != (char *)0x0) {
    memset(&sInfo,0,0x100);
    pcVar47 = *(char **)(iVar61 + 0xc);
    if (pcVar47 == (char *)0x0) {
      if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *DAT_0000c040)
         ) {
        snprintf((char *)local_9c4,0x800,DAT_0000c044,pcVar65,pcVar22);
        _applog(3,(char *)local_9c4,false);
      }
    }
    else {
      if (*pcVar47 == '\0') {
        iVar20 = DAT_0000c078[1];
        iVar63 = DAT_0000c078[2];
        iVar59 = DAT_0000c078[3];
        *local_9c4 = (char *)*DAT_0000c078;
        local_9c4[1] = (char *)iVar20;
        local_9c4[2] = (char *)iVar63;
        local_9c4[3] = (char *)iVar59;
        iVar20 = DAT_0000c078[5];
        local_9c4[4] = (char *)DAT_0000c078[4];
        local_9c4[5] = (char *)iVar20;
        _applog(3,(char *)local_9c4,true);
        _quit(1);
        pcVar47 = *(char **)(iVar61 + 0xc);
      }
      lVar17 = strtol(pcVar47,(char **)0x0,10);
      *(long *)(iVar58 + 0xc84) = lVar17;
      if ((lVar17 != 0x20 && lVar17 != 1) && (lVar17 != 0x40)) {
        iVar61 = DAT_0000b6d8[1];
        iVar20 = DAT_0000b6d8[2];
        iVar63 = DAT_0000b6d8[3];
        *local_9c4 = (char *)*DAT_0000b6d8;
        local_9c4[1] = (char *)iVar61;
        local_9c4[2] = (char *)iVar20;
        local_9c4[3] = (char *)iVar63;
        iVar61 = DAT_0000b6d8[5];
        iVar20 = DAT_0000b6d8[6];
        iVar63 = DAT_0000b6d8[7];
        iVar59 = DAT_0000b6d8[8];
        local_9c4[4] = (char *)DAT_0000b6d8[4];
        local_9c4[5] = (char *)iVar61;
        local_9c4[6] = (char *)iVar20;
        local_9c4[7] = (char *)iVar63;
        local_9c4[8] = (char *)iVar59;
        _applog(3,(char *)local_9c4,true);
        _quit(1);
      }
      if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *DAT_0000b6b8)
         ) {
        pcVar22 = opt_logwork_asicnum;
        snprintf((char *)local_9c4,0x800,DAT_0000b9d0,opt_logwork_path,opt_logwork_asicnum);
        _applog(3,(char *)local_9c4,false);
      }
    }
    sprintf((char *)&sInfo,DAT_0000b9d4,opt_logwork_path);
    pFVar26 = fopen((char *)&sInfo,DAT_0000b9d8);
    *(FILE **)(iVar58 + 0xc88) = pFVar26;
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *DAT_0000b9dc))
    {
      snprintf((char *)local_9c4,0x800,DAT_0000b9e0,&sInfo);
      _applog(3,(char *)local_9c4,false);
    }
    piVar49 = (int *)local_9c4;
    ptVar41 = local_9cc;
    iVar61 = DAT_0000b9e4;
    piVar33 = DAT_0000b9dc;
    iVar20 = *(int *)(iVar58 + 0xc84);
    if (iVar20 == 1) {
      sprintf((char *)&sInfo,DAT_0000c054,opt_logwork_path);
      pFVar26 = fopen((char *)&sInfo,DAT_0000c058);
      *(FILE **)(iVar61 + 0xc8c) = pFVar26;
      if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *DAT_0000c040)
         ) {
        pcVar22 = (char *)&sInfo;
        snprintf((char *)local_9c4,0x800,DAT_0000c05c,*(undefined4 *)(iVar58 + 0xc84),&sInfo);
        _applog(3,(char *)local_9c4,false);
      }
    }
    else if ((iVar20 == 0x20 || iVar20 == 0x40) && (-1 < iVar20)) {
      psVar27 = (sysinfo *)0x0;
      ppFVar64 = DAT_0000b9e8;
      do {
        pcVar22 = (char *)psVar27;
        sprintf((char *)&sInfo,DAT_0000b9ec,opt_logwork_path,iVar20,psVar27);
        pFVar26 = fopen((char *)&sInfo,DAT_0000b9d8);
        cVar3 = *(char *)&ptVar41->id;
        ppFVar64 = ppFVar64 + 1;
        *ppFVar64 = pFVar26;
        if (((cVar3 != '\0') || (local_9d0->hash[0] != '\0')) || (2 < *piVar33)) {
          pcVar22 = (char *)&sInfo;
          snprintf((char *)piVar49,0x800,DAT_0000b9f0,*(undefined4 *)(iVar58 + 0xc84),&sInfo);
          _applog(3,(char *)piVar49,false);
        }
        iVar20 = *(int *)(iVar58 + 0xc84);
        psVar27 = (sysinfo *)((int)&psVar27->uptime + 1);
      } while ((int)psVar27 <= iVar20);
    }
    piVar49 = (int *)local_9c4;
    pcVar65 = local_9d0->hash;
    piVar33 = DAT_0000b9dc;
    if (*(char *)(iVar58 + 0xd90) != '\0') {
      iVar61 = 0;
      ppFVar64 = DAT_0000b9f4;
      do {
        sprintf((char *)&sInfo,DAT_0000b9f8,opt_logwork_path,iVar61);
        pFVar26 = fopen((char *)&sInfo,DAT_0000b9d8);
        ppFVar64 = ppFVar64 + 1;
        *ppFVar64 = pFVar26;
        if (((*(char *)&local_9cc->id != '\0') || (*pcVar65 != '\0')) || (2 < *piVar33)) {
          snprintf((char *)piVar49,0x800,DAT_0000b9fc,&sInfo);
          _applog(3,(char *)piVar49,false);
        }
        iVar61 = iVar61 + 1;
      } while (iVar61 != 0x41);
    }
  }
  if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (3 < *DAT_0000b9dc)) {
    snprintf((char *)local_9c4,0x800,DAT_0000ba00,DAT_0000ba04,pcVar22);
    _applog(4,(char *)local_9c4,false);
  }
  if (cnfbuf != (char *)0x0) {
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (4 < *DAT_0000b9dc))
    {
      snprintf((char *)local_9c4,0x800,DAT_0000ba08);
      _applog(5,(char *)local_9c4,false);
    }
    if (fileconf_load == -1) {
      if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (3 < *DAT_0000c040)
         ) {
        iVar61 = DAT_0000c048[1];
        iVar20 = DAT_0000c048[2];
        iVar63 = DAT_0000c048[3];
        *local_9c4 = (char *)*DAT_0000c048;
        local_9c4[1] = (char *)iVar61;
        local_9c4[2] = (char *)iVar20;
        local_9c4[3] = (char *)iVar63;
        iVar61 = DAT_0000c048[5];
        iVar20 = DAT_0000c048[6];
        iVar63 = DAT_0000c048[7];
        local_9c4[4] = (char *)DAT_0000c048[4];
        local_9c4[5] = (char *)iVar61;
        local_9c4[6] = (char *)iVar20;
        local_9c4[7] = (char *)iVar63;
        iVar61 = DAT_0000c048[9];
        iVar20 = DAT_0000c048[10];
        iVar63 = DAT_0000c048[0xb];
        local_9c4[8] = (char *)DAT_0000c048[8];
        local_9c4[9] = (char *)iVar61;
        local_9c4[10] = (char *)iVar20;
        *(short *)(local_9c4 + 0xb) = (short)iVar63;
        *(char *)((int)local_9c4 + 0x2e) = (char)((uint)iVar63 >> 0x10);
        _applog(4,(char *)local_9c4,false);
      }
      if ((*DAT_0000c04c != '\0') &&
         (((*(char *)&local_9cc->id != '\0' || (local_9d0->hash[0] != '\0')) || (3 < *DAT_0000c040))
         )) {
        iVar61 = DAT_0000c050[1];
        iVar20 = DAT_0000c050[2];
        iVar63 = DAT_0000c050[3];
        *local_9c4 = (char *)*DAT_0000c050;
        local_9c4[1] = (char *)iVar61;
        local_9c4[2] = (char *)iVar20;
        local_9c4[3] = (char *)iVar63;
        iVar61 = DAT_0000c050[5];
        iVar20 = DAT_0000c050[6];
        iVar63 = DAT_0000c050[7];
        local_9c4[4] = (char *)DAT_0000c050[4];
        local_9c4[5] = (char *)iVar61;
        local_9c4[6] = (char *)iVar20;
        local_9c4[7] = (char *)iVar63;
        iVar61 = DAT_0000c050[9];
        iVar20 = DAT_0000c050[10];
        iVar63 = DAT_0000c050[0xb];
        iVar59 = DAT_0000c050[0xc];
        local_9c4[8] = (char *)DAT_0000c050[8];
        local_9c4[9] = (char *)iVar61;
        local_9c4[10] = (char *)iVar20;
        local_9c4[0xb] = (char *)iVar63;
        *(short *)(local_9c4 + 0xc) = (short)iVar59;
        _applog(4,(char *)local_9c4,false);
      }
    }
    else if (fileconf_load == 0) {
      if (((*(char *)&local_9cc->id == '\0') && (local_9d0->hash[0] == '\0')) &&
         (local_9d8 = DAT_0000b9dc, *DAT_0000b9dc < 4)) {
LAB_0000b932:
        local_9d8 = DAT_0000b9dc;
        if (*DAT_0000b9dc < 4) goto LAB_0000b95a;
      }
      else {
        iVar61 = DAT_0000ba0c[1];
        iVar20 = DAT_0000ba0c[2];
        iVar63 = DAT_0000ba0c[3];
        *local_9c4 = (char *)*DAT_0000ba0c;
        local_9c4[1] = (char *)iVar61;
        local_9c4[2] = (char *)iVar20;
        local_9c4[3] = (char *)iVar63;
        iVar61 = DAT_0000ba0c[5];
        iVar20 = DAT_0000ba0c[6];
        iVar63 = DAT_0000ba0c[7];
        local_9c4[4] = (char *)DAT_0000ba0c[4];
        local_9c4[5] = (char *)iVar61;
        local_9c4[6] = (char *)iVar20;
        local_9c4[7] = (char *)iVar63;
        iVar61 = DAT_0000ba0c[9];
        local_9c4[8] = (char *)DAT_0000ba0c[8];
        local_9c4[9] = (char *)iVar61;
        _applog(4,(char *)local_9c4,false);
        if ((*(char *)&local_9cc->id == '\0') && (local_9d0->hash[0] == '\0')) goto LAB_0000b932;
      }
      iVar61 = DAT_0000ba10[1];
      iVar20 = DAT_0000ba10[2];
      iVar63 = DAT_0000ba10[3];
      *local_9c4 = (char *)*DAT_0000ba10;
      local_9c4[1] = (char *)iVar61;
      local_9c4[2] = (char *)iVar20;
      local_9c4[3] = (char *)iVar63;
      iVar61 = DAT_0000ba10[5];
      iVar20 = DAT_0000ba10[6];
      iVar63 = DAT_0000ba10[7];
      local_9c4[4] = (char *)DAT_0000ba10[4];
      local_9c4[5] = (char *)iVar61;
      local_9c4[6] = (char *)iVar20;
      local_9c4[7] = (char *)iVar63;
      iVar61 = DAT_0000ba10[9];
      local_9c4[8] = (char *)DAT_0000ba10[8];
      *(short *)(local_9c4 + 9) = (short)iVar61;
      _applog(4,(char *)local_9c4,false);
    }
LAB_0000b95a:
    free(cnfbuf);
    cnfbuf = (char *)0x0;
  }
  pcVar22 = opt_kernel_path;
  sVar23 = strlen(opt_kernel_path);
  *(undefined2 *)(pcVar22 + sVar23) = s__bmminer__0004bfec._8_2_;
  if (*DAT_0000ba14 == '\0') {
    if (local_9d0->hash[0] != '\0') goto LAB_0000bbe4;
    setlogmask(0x3f);
  }
  else {
    local_9d0->hash[0] = '\x01';
LAB_0000bbe4:
    setlogmask(0xff);
  }
  piVar33 = DAT_0000ba2c;
  drv_01 = DAT_0000ba28;
  drv_00 = DAT_0000ba24;
  drv = DAT_0000ba20;
  pdVar52 = DAT_0000ba1c;
  iVar20 = 0;
  iVar61 = *(int *)(DAT_0000ba18 + 0x81c);
  bVar69 = iVar61 < 0;
  if (bVar69) {
    iVar61 = 0x3c;
  }
  if (bVar69) {
    *(int *)(DAT_0000ba18 + 0x81c) = iVar61;
  }
  *(undefined4 *)(iVar58 + 0xe98) = 8;
  pcVar22 = DAT_0000bcec;
  control_thr = (thr_info *)_cgcalloc(8,0x40,DAT_0000bcec,DAT_0000bce8,0x2de6);
  *(undefined4 *)(iVar58 + 0xe9c) = 0;
  fill_device_drv(drv);
  fill_device_drv(drv_00);
  fill_device_drv(drv_01);
  fill_device_drv(pdVar52);
  (*drv->drv_detect)(false);
  (*drv_00->drv_detect)(false);
  (*drv_01->drv_detect)(false);
  piVar49 = (int *)pdVar52->drv_detect;
  (*(code *)piVar49)(0);
  puVar11 = PTR_devices_0000bd0c;
  iVar61 = *piVar33;
  mining_threads = 0;
  if (0 < iVar61) {
    do {
      piVar49 = *(int **)puVar11;
      ppcVar2 = (cgpu_info **)(piVar49 + iVar20);
      iVar20 = iVar20 + 1;
      enable_device(*ppcVar2);
      iVar61 = *piVar33;
    } while (iVar20 < iVar61);
  }
  if (iVar61 == 0) {
    iVar58 = _UNK_0000c038[1];
    iVar61 = _UNK_0000c038[2];
    iVar20 = _UNK_0000c038[3];
    *local_9c4 = (char *)*_UNK_0000c038;
    local_9c4[1] = (char *)iVar58;
    local_9c4[2] = (char *)iVar61;
    local_9c4[3] = (char *)iVar20;
    iVar58 = _UNK_0000c038[5];
    iVar61 = _UNK_0000c038[6];
    iVar20 = _UNK_0000c038[7];
    iVar63 = _UNK_0000c038[8];
    local_9c4[4] = (char *)_UNK_0000c038[4];
    local_9c4[5] = (char *)iVar58;
    local_9c4[6] = (char *)iVar61;
    local_9c4[7] = (char *)iVar20;
    *(short *)(local_9c4 + 8) = (short)iVar63;
    *(char *)((int)local_9c4 + 0x22) = (char)((uint)iVar63 >> 0x10);
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  *(int *)(iVar58 + 0xa74) = iVar61;
  if (temp_cutoff_str == (char *)0x0) {
    iVar61 = pthread_rwlock_rdlock((pthread_rwlock_t *)PTR_devices_lock_0000bcf8);
    if (iVar61 != 0) {
      _rd_lock((pthread_rwlock_t *)PTR___func___1_0000bcfc,(char *)0x51c,pcVar22,(int)piVar49);
    }
    iVar61 = *piVar33;
    if (0 < iVar61) {
      piVar50 = *(int **)PTR_devices_0000bd0c;
      piVar51 = piVar50;
      do {
        piVar49 = piVar51 + 1;
        if (*(int *)(*piVar51 + 0xb8) == 0) {
          *(undefined4 *)(*piVar51 + 0xb8) = 0x5f;
        }
        piVar51 = piVar49;
      } while (piVar49 != piVar50 + iVar61);
    }
    _rd_unlock((pthread_rwlock_t *)PTR_devices_lock_0000bcf8,PTR___func___1_0000bcfc,(char *)0x525,
               (int)piVar49);
  }
  else {
    pcVar65 = strtok(temp_cutoff_str,PTR_DAT_0000bcf0);
    piVar51 = (int *)local_9c4;
    puVar11 = PTR_devices_0000bd0c;
    if (pcVar65 == (char *)0x0) {
      iVar61 = 0;
      uVar44 = 0;
    }
    else {
      ppiStack_9e0 = (int **)PTR_selective_yield_0000bcf4;
      iVar61 = 0;
      do {
        iVar20 = *piVar33;
        if (iVar20 <= iVar61) {
          iVar20 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 4);
          iVar63 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 8);
          iVar59 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0xc);
          *piVar51 = *(int *)PTR_s_Too_many_values_passed_to_set_te_0000bd10;
          piVar51[1] = iVar20;
          piVar51[2] = iVar63;
          piVar51[3] = iVar59;
          iVar63 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x14);
          iVar59 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x18);
          iVar20 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x1c);
          piVar51[4] = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x10);
          piVar51[5] = iVar63;
          piVar51[6] = iVar59;
          piVar51[7] = iVar20;
          iVar63 = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x24);
          uVar19 = *(undefined4 *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x28);
          piVar51[8] = *(int *)(PTR_s_Too_many_values_passed_to_set_te_0000bd10 + 0x20);
          piVar51[9] = iVar63;
          *(short *)(piVar51 + 10) = (short)uVar19;
          _applog(3,(char *)piVar51,true);
          _quit(1);
        }
        pcVar22 = (char *)0xa;
        uVar44 = strtol(pcVar65,(char **)0x0,10);
        if (200 < uVar44) {
          iVar20 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 4);
          iVar63 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 8);
          iVar59 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0xc);
          *piVar51 = *(int *)PTR_s_Invalid_value_passed_to_set_temp_0000bd14;
          piVar51[1] = iVar20;
          piVar51[2] = iVar63;
          piVar51[3] = iVar59;
          iVar63 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x14);
          iVar59 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x18);
          iVar20 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x1c);
          piVar51[4] = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x10);
          piVar51[5] = iVar63;
          piVar51[6] = iVar59;
          piVar51[7] = iVar20;
          pcVar22 = (char *)0x1;
          iVar63 = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x24);
          piVar51[8] = *(int *)(PTR_s_Invalid_value_passed_to_set_temp_0000bd14 + 0x20);
          piVar51[9] = iVar63;
          _applog(3,(char *)piVar51,true);
          _quit(1);
        }
        iVar63 = pthread_rwlock_rdlock((pthread_rwlock_t *)PTR_devices_lock_0000bcf8);
        if (iVar63 != 0) {
          _rd_lock((pthread_rwlock_t *)PTR___func___1_0000bcfc,(char *)0x515,pcVar22,iVar20);
        }
        __rwlock = PTR_devices_lock_0000bcf8;
        iVar63 = *(int *)(*(int *)puVar11 + iVar61 * 4);
        *(uint *)(iVar63 + 0xb8) = uVar44;
        iVar20 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
        if (iVar20 != 0) {
          _rw_unlock(_UNK_0000c03c,(char *)0x517,pcVar22,iVar63);
        }
        iVar61 = iVar61 + 1;
        piVar49 = *ppiStack_9e0;
        (*(code *)piVar49)();
        pcVar65 = strtok((char *)0x0,PTR_DAT_0000bcf0);
      } while (pcVar65 != (char *)0x0);
      if (iVar61 != 1) goto code_r0x0000bc7a;
      iVar61 = 1;
    }
    iVar20 = pthread_rwlock_rdlock((pthread_rwlock_t *)PTR_devices_lock_0000bcf8);
    if (iVar20 != 0) {
      _rd_lock((pthread_rwlock_t *)PTR___func___1_0000bcfc,(char *)0x52c,pcVar22,(int)piVar49);
    }
    if (iVar61 < *piVar33) {
      piVar49 = (int *)(*(int *)PTR_devices_0000bd0c + *piVar33 * 4);
      piVar51 = (int *)(*(int *)PTR_devices_0000bd0c + iVar61 * 4);
      do {
        piVar50 = piVar51 + 1;
        *(uint *)(*piVar51 + 0xb8) = uVar44;
        piVar51 = piVar50;
      } while (piVar50 != piVar49);
    }
    _rd_unlock((pthread_rwlock_t *)PTR_devices_lock_0000bcf8,PTR___func___1_0000bcfc,(char *)0x532,
               (int)piVar49);
  }
code_r0x0000bc7a:
  iVar61 = *piVar33;
  if (0 < iVar61) {
    piVar51 = *(int **)PTR_devices_0000bd0c;
    piVar49 = piVar51;
    do {
      piVar50 = piVar49 + 1;
      *(undefined4 *)(*piVar49 + 0x138) = 99999999;
      piVar49 = piVar50;
    } while (piVar50 != piVar51 + iVar61);
  }
  if (*PTR_opt_compact_0000bd04 == '\0') {
    iVar61 = *(int *)(iVar58 + 0xa7c) + *(int *)(iVar58 + 0xa74);
    *(int *)(iVar58 + 0xa7c) = iVar61;
    *(int *)(iVar58 + 0xa80) = iVar61 + 1;
  }
  if (total_pools == 0) {
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (3 < *DAT_0000c360))
    {
      iVar58 = _UNK_0000c38c[1];
      iVar61 = _UNK_0000c38c[2];
      iVar20 = _UNK_0000c38c[3];
      *local_9c4 = (char *)*_UNK_0000c38c;
      local_9c4[1] = (char *)iVar58;
      local_9c4[2] = (char *)iVar61;
      local_9c4[3] = (char *)iVar20;
      iVar58 = _UNK_0000c38c[5];
      iVar61 = _UNK_0000c38c[6];
      iVar20 = _UNK_0000c38c[7];
      local_9c4[4] = (char *)_UNK_0000c38c[4];
      local_9c4[5] = (char *)iVar58;
      local_9c4[6] = (char *)iVar61;
      local_9c4[7] = (char *)iVar20;
      iVar58 = _UNK_0000c38c[9];
      iVar61 = _UNK_0000c38c[10];
      local_9c4[8] = (char *)_UNK_0000c38c[8];
      local_9c4[9] = (char *)iVar58;
      *(short *)(local_9c4 + 10) = (short)iVar61;
      _applog(4,(char *)local_9c4,false);
    }
    iVar58 = _UNK_0000c390[1];
    iVar61 = _UNK_0000c390[2];
    iVar20 = _UNK_0000c390[3];
    iVar63 = _UNK_0000c390[4];
    *local_9c4 = (char *)*_UNK_0000c390;
    local_9c4[1] = (char *)iVar58;
    local_9c4[2] = (char *)iVar61;
    local_9c4[3] = (char *)iVar20;
    *(short *)(local_9c4 + 4) = (short)iVar63;
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  pptStack_9d4 = (thr_info **)PTR_pools_0000bd08;
  if (0 < total_pools) {
    iVar61 = 0;
    ptVar41 = *(thr_info **)PTR_pools_0000bd08;
    do {
      iVar20 = (&ptVar41->id)[iVar61];
      *(undefined4 *)(iVar20 + 0x194) = 99999999;
      *(undefined4 *)(iVar20 + 0x1b8) = 99999999;
      if (*(int *)(iVar20 + 0xa8) == 0) {
        if (*(int *)(iVar20 + 0xb0) == 0) {
          pvVar28 = calloc(1,1);
          *(void **)(iVar20 + 0xb0) = pvVar28;
        }
        if (*(char **)(iVar20 + 0xac) == (char *)0x0) {
          snprintf((char *)local_9c4,0x800,DAT_0000ceec,iVar61,*(undefined4 *)(iVar20 + 0xa4));
          goto LAB_0000cdee;
        }
        sVar23 = strlen(*(char **)(iVar20 + 0xac));
        sVar29 = strlen(*(char **)(iVar20 + 0xb0));
        uVar44 = sVar23 + sVar29 + 2;
        pcVar22 = (char *)_cgmalloc(uVar44,DAT_0000c02c,DAT_0000c030,0x2e53);
        *(char **)(iVar20 + 0xa8) = pcVar22;
        snprintf(pcVar22,uVar44,DAT_0000c034,*(undefined4 *)(iVar20 + 0xac),
                 *(undefined4 *)(iVar20 + 0xb0));
        ptVar41 = *pptStack_9d4;
      }
      iVar61 = iVar61 + 1;
    } while (iVar61 < total_pools);
  }
  currentpool = (pool *)(*pptStack_9d4)->id;
  if (*(char *)&local_9cc->id != '\0') {
    openlog(DAT_0000c374,1,8);
  }
  iVar61 = DAT_0000c378;
  if (*(int *)(iVar58 + 0xea0) != 0) {
    iVar20 = pipe((int *)local_9c4);
    if (iVar20 < 0) {
      perror(DAT_0000cee4);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    fflush(*DAT_0000c37c);
    iVar20 = dup2((int)local_9c4[1],2);
    if (iVar20 < 0) {
      perror(DAT_0000cee8);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar20 = close((int)local_9c4[1]);
    if (iVar20 < 0) {
      perror(DAT_0000cee0);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    p_Var30 = signal(0xd,(__sighandler_t)0x1);
    p_Var31 = signal(0xd,(__sighandler_t)0x1);
    if ((p_Var31 == (__sighandler_t)0xffffffff) || (p_Var30 == (__sighandler_t)0xffffffff)) {
      perror(DAT_0000c9fc);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    forkpid = fork();
    if (forkpid < 0) {
      perror(DAT_0000c9f0);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (forkpid == 0) {
      iVar58 = dup2((int)*local_9c4,0);
      if (iVar58 < 0) {
        perror(DAT_0000c394);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      close((int)*local_9c4);
      execl(DAT_0000c380,DAT_0000c380,DAT_0000c384,*(undefined4 *)(iVar61 + 0xea0),0);
      perror(DAT_0000c388);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    iVar61 = close((int)*local_9c4);
    if (iVar61 < 0) {
      perror(DAT_0000c728);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  mining_thr = (thr_info **)_cgcalloc(mining_threads,4,DAT_0000c36c,DAT_0000c398,0x2e64);
  if (0 < mining_threads) {
    iVar61 = 0;
    do {
      pptVar32 = mining_thr;
      ptVar41 = (thr_info *)_cgcalloc(1,0x40,DAT_0000c36c,DAT_0000c398,0x2e68);
      iVar20 = mining_threads;
      pptVar32[iVar61] = ptVar41;
      iVar61 = iVar61 + 1;
    } while (iVar61 < iVar20);
  }
  piVar49 = DAT_0000c39c;
  if (0 < *piVar33) {
    iVar61 = 0;
    pool_6 = (pool *)0x0;
    do {
      iVar63 = 0;
      pcVar60 = *(cgpu_info **)(*piVar49 + (int)pool_6 * 4);
      pptVar32 = (thr_info **)_cgmalloc((pcVar60->threads + 1) * 4,DAT_0000c36c,DAT_0000c398,0x2e71)
      ;
      iVar20 = pcVar60->threads;
      pcVar60->thr = pptVar32;
      pptVar32[iVar20] = (thr_info *)0x0;
      pcVar60->status = LIFE_INIT;
      if (0 < iVar20) {
        do {
          while( true ) {
            ptVar41 = get_thread(iVar61);
            pdVar52 = pcVar60->drv;
            ptVar41->id = iVar61;
            ptVar41->cgpu = pcVar60;
            p_Var53 = pdVar52->thread_prepare;
            ptVar41->device_thread = iVar63;
            _Var15 = (*p_Var53)(ptVar41);
            if (_Var15) break;
LAB_0000c3a0:
            iVar63 = iVar63 + 1;
            iVar61 = iVar61 + 1;
            if (pcVar60->threads <= iVar63) goto LAB_0000c452;
          }
          iVar20 = thr_info_create(ptVar41,(pthread_attr_t *)0x0,DAT_0000c6e4,ptVar41);
          if (iVar20 != 0) {
            snprintf((char *)local_9c4,0x800,DAT_0000c72c,ptVar41->id);
            _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
            __quit(1,false);
          }
          dVar54 = pcVar60->deven;
          pcVar60->thr[iVar63] = ptVar41;
          if (dVar54 == DEV_DISABLED) goto LAB_0000c3a0;
          if ((opt_debug != false) &&
             (((*(char *)&local_9cc->id != '\0' || (local_9d0->hash[0] != '\0')) ||
              (6 < opt_log_level)))) {
            snprintf((char *)local_9c4,0x800,DAT_0000c6e8,ptVar41->id);
            _applog(7,(char *)local_9c4,false);
          }
          iVar63 = iVar63 + 1;
          iVar61 = iVar61 + 1;
          _cgsem_post(&ptVar41->sem,DAT_0000c6ec,DAT_0000c6f0,0x2e8d);
        } while (iVar63 < pcVar60->threads);
      }
LAB_0000c452:
      pool_6 = (pool *)((int)&pool_6->pool_no + 1);
    } while ((int)pool_6 < *piVar33);
  }
  iVar61 = total_pools;
  piVar49 = DAT_0000c730;
  if ((opt_benchmark == false) && (*(int *)(DAT_0000c6f4 + 0x448) == 0)) {
    ptVar41 = *pptStack_9d4;
    iVar63 = *DAT_0000c730;
    iVar20 = 0;
    while (iVar20 < iVar61) {
      iVar59 = (&ptVar41->id)[iVar20];
      iVar20 = iVar20 + 1;
      *(undefined *)(iVar59 + 0x61) = 1;
      bVar69 = *(int *)(iVar59 + 100) != 1;
      if (bVar69) {
        iVar63 = iVar63 + 1;
      }
      if (bVar69) {
        *(undefined4 *)(iVar59 + 100) = 1;
      }
    }
    *piVar49 = iVar63;
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (4 < *DAT_0000c704))
    {
      iVar61 = DAT_0000c734[1];
      iVar20 = DAT_0000c734[2];
      iVar63 = DAT_0000c734[3];
      *local_9c4 = (char *)*DAT_0000c734;
      local_9c4[1] = (char *)iVar61;
      local_9c4[2] = (char *)iVar20;
      local_9c4[3] = (char *)iVar63;
      iVar61 = DAT_0000c734[5];
      iVar20 = DAT_0000c734[6];
      local_9c4[4] = (char *)DAT_0000c734[4];
      local_9c4[5] = (char *)iVar61;
      *(short *)(local_9c4 + 6) = (short)iVar20;
      _applog(5,(char *)local_9c4,false);
    }
    pptVar32 = pptStack_9d4;
    for (i_1 = 0; __start_routine = DAT_0000c738, i_1 < total_pools; i_1 = i_1 + 1) {
      pvVar28 = (void *)(&(*pptVar32)->id)[i_1];
      *(undefined *)((int)pvVar28 + 0x11c) = 1;
      pthread_create((pthread_t *)((int)pvVar28 + 0x118),(pthread_attr_t *)0x0,__start_routine,
                     pvVar28);
    }
    iVar61 = 0x3c;
    do {
      sleep(1);
      piVar51 = (int *)local_9c4;
      pcVar22 = local_9d0->hash;
      piVar49 = DAT_0000ca00;
      if (pools_active != false) break;
      iVar61 = iVar61 + -1;
    } while (iVar61 != 0);
    bVar69 = false;
    ptVar41 = local_9cc;
LAB_0000c78e:
    do {
      if (pools_active != false) break;
      ptVar68 = DAT_0000ca04;
      if (!bVar69) {
        if (((*(char *)&ptVar41->id == '\0') && (*pcVar22 == '\0')) && (*piVar49 < 3)) {
LAB_0000cf8a:
          if (2 < *DAT_0000d090) goto LAB_0000cf90;
LAB_0000cfb2:
          if (2 < *DAT_0000d090) goto LAB_0000cfb8;
        }
        else {
          iVar61 = DAT_0000d0b0[1];
          iVar20 = DAT_0000d0b0[2];
          iVar63 = DAT_0000d0b0[3];
          *piVar51 = *DAT_0000d0b0;
          piVar51[1] = iVar61;
          piVar51[2] = iVar20;
          piVar51[3] = iVar63;
          iVar61 = DAT_0000d0b0[5];
          iVar20 = DAT_0000d0b0[6];
          iVar63 = DAT_0000d0b0[7];
          piVar51[4] = DAT_0000d0b0[4];
          piVar51[5] = iVar61;
          piVar51[6] = iVar20;
          piVar51[7] = iVar63;
          iVar61 = DAT_0000d0b0[9];
          iVar20 = DAT_0000d0b0[10];
          iVar63 = DAT_0000d0b0[0xb];
          piVar51[8] = DAT_0000d0b0[8];
          piVar51[9] = iVar61;
          piVar51[10] = iVar20;
          piVar51[0xb] = iVar63;
          iVar61 = DAT_0000d0b0[0xd];
          iVar20 = DAT_0000d0b0[0xe];
          piVar51[0xc] = DAT_0000d0b0[0xc];
          piVar51[0xd] = iVar61;
          *(short *)(piVar51 + 0xe) = (short)iVar20;
          *(char *)((int)piVar51 + 0x3a) = (char)((uint)iVar20 >> 0x10);
          _applog(3,(char *)piVar51,false);
          if ((*(char *)&ptVar41->id == '\0') && (*pcVar22 == '\0')) goto LAB_0000cf8a;
LAB_0000cf90:
          memcpy(piVar51,DAT_0000d09c,0x4b);
          _applog(3,(char *)piVar51,false);
          if ((*(char *)&ptVar41->id == '\0') && (*pcVar22 == '\0')) goto LAB_0000cfb2;
LAB_0000cfb8:
          memcpy(piVar51,DAT_0000d0a0,0x5e);
          _applog(3,(char *)piVar51,false);
        }
        for (iVar61 = 0; iVar61 < total_pools; iVar61 = iVar61 + 1) {
          iVar20 = (&(*pptStack_9d4)->id)[iVar61];
          if (((*(char *)&ptVar41->id != '\0') || (*pcVar22 != '\0')) || (3 < *piVar49)) {
            local_9e8 = ptVar41;
            snprintf((char *)piVar51,0x800,DAT_0000d0a4,iVar61,*(undefined4 *)(iVar20 + 0xa4),
                     *(undefined4 *)(iVar20 + 0xac),*(undefined4 *)(iVar20 + 0xb0));
            _applog(4,(char *)piVar51,false);
            ptVar41 = local_9e8;
          }
        }
        if (use_curses == false) goto LAB_0000c7ae;
        if (((*(char *)&ptVar41->id == '\0') && (*pcVar22 == '\0')) && (*piVar49 < 3)) {
          bVar69 = true;
          goto LAB_0000c78e;
        }
        local_9e4 = DAT_0000d0a8;
        memcpy(piVar51,DAT_0000d0ac,0x4c);
        _applog(3,(char *)piVar51,false);
        bVar69 = true;
        ptVar68 = local_9e4;
      }
      if (*(char *)&ptVar68->id == '\0') {
LAB_0000c7ae:
        iVar58 = DAT_0000ca08[1];
        iVar61 = DAT_0000ca08[2];
        iVar20 = DAT_0000ca08[3];
        *local_9c4 = (char *)*DAT_0000ca08;
        local_9c4[1] = (char *)iVar58;
        local_9c4[2] = (char *)iVar61;
        local_9c4[3] = (char *)iVar20;
        iVar58 = DAT_0000ca08[5];
        iVar61 = DAT_0000ca08[6];
        iVar20 = DAT_0000ca08[7];
        iVar63 = DAT_0000ca08[8];
        local_9c4[4] = (char *)DAT_0000ca08[4];
        local_9c4[5] = (char *)iVar58;
        local_9c4[6] = (char *)iVar61;
        local_9c4[7] = (char *)iVar20;
        *(short *)(local_9c4 + 8) = (short)iVar63;
        *(char *)((int)local_9c4 + 0x22) = (char)((uint)iVar63 >> 0x10);
        _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
        __quit(0,false);
      }
    } while( true );
  }
  puVar55 = DAT_0000c6fc;
  *DAT_0000c6f8 = 0;
  puVar43 = puVar55 + 0xc;
  do {
    *puVar55 = 0;
    puVar55 = puVar55 + 1;
  } while (puVar55 != puVar43);
  iVar61 = *piVar33;
  g_local_mhashes_index = 0;
  if (0 < iVar61) {
    piVar49 = *DAT_0000c700;
    piVar33 = piVar49;
    do {
      piVar51 = piVar33 + 1;
      iVar20 = *piVar33;
      *(undefined8 *)(iVar20 + 0x50) = 0;
      *(undefined8 *)(iVar20 + 0x30) = 0;
      piVar33 = piVar51;
    } while (piVar51 != piVar49 + iVar61);
  }
  iVar61 = sysinfo((sysinfo *)&sInfo);
  plVar12 = DAT_0000c9f8;
  if (iVar61 == 0) {
    *DAT_0000c9f4 = sInfo.uptime;
    *plVar12 = sInfo.uptime;
  }
  else {
    if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) || (5 < *DAT_0000c704))
    {
      piVar33 = __errno_location();
      iVar61 = *piVar33;
      pcVar22 = strerror(iVar61);
      snprintf((char *)local_9c4,0x800,DAT_0000c708,iVar61,pcVar22);
      _applog(6,(char *)local_9c4,false);
    }
    tVar34 = time((time_t *)0x0);
    *DAT_0000c70c = tVar34;
    tVar34 = time((time_t *)0x0);
    *DAT_0000c710 = tVar34;
  }
  iVar61 = DAT_0000c6f4;
  cgtime((timeval *)(DAT_0000c6f4 + 0x518));
  cgtime(DAT_0000c714);
  cgtime((timeval *)(iVar61 + 0x520));
  get_datestamp((char *)(iVar61 + 0x6a0),0x28,(timeval *)(iVar61 + 0x518));
  ptVar41 = control_thr;
  watchpool_thr_id = 2;
  iVar61 = thr_info_create(control_thr + 2,(pthread_attr_t *)0x0,DAT_0000c718,(void *)0x0);
  if (iVar61 != 0) {
    iVar58 = DAT_0000cefc[1];
    iVar61 = DAT_0000cefc[2];
    iVar20 = DAT_0000cefc[3];
    *local_9c4 = (char *)*DAT_0000cefc;
    local_9c4[1] = (char *)iVar58;
    local_9c4[2] = (char *)iVar61;
    local_9c4[3] = (char *)iVar20;
    iVar58 = DAT_0000cefc[5];
    iVar61 = DAT_0000cefc[6];
    iVar20 = DAT_0000cefc[7];
    local_9c4[4] = (char *)DAT_0000cefc[4];
    local_9c4[5] = (char *)iVar58;
    local_9c4[6] = (char *)iVar61;
    *(short *)(local_9c4 + 7) = (short)iVar20;
    *(char *)((int)local_9c4 + 0x1e) = (char)((uint)iVar20 >> 0x10);
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  pthread_detach(ptVar41[2].pth);
  watchdog_thr_id = 3;
  local_9e8 = control_thr;
  iVar61 = thr_info_create(control_thr + 3,(pthread_attr_t *)0x0,DAT_0000c71c,(void *)0x0);
  if (iVar61 != 0) {
    iVar58 = DAT_0000cef8[1];
    iVar61 = DAT_0000cef8[2];
    iVar20 = DAT_0000cef8[3];
    *local_9c4 = (char *)*DAT_0000cef8;
    local_9c4[1] = (char *)iVar58;
    local_9c4[2] = (char *)iVar61;
    local_9c4[3] = (char *)iVar20;
    iVar58 = DAT_0000cef8[5];
    iVar61 = DAT_0000cef8[6];
    iVar20 = DAT_0000cef8[7];
    local_9c4[4] = (char *)DAT_0000cef8[4];
    local_9c4[5] = (char *)iVar58;
    local_9c4[6] = (char *)iVar61;
    *(short *)(local_9c4 + 7) = (short)iVar20;
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  pthread_detach(local_9e8[3].pth);
  api_thr_id = 5;
  ptVar41 = DAT_0000c720;
  iVar61 = thr_info_create(control_thr + 5,(pthread_attr_t *)0x0,
                           (_func_void_ptr_void_ptr *)DAT_0000c720,control_thr + 5);
  if (iVar61 != 0) {
    iVar58 = DAT_0000cf00[1];
    iVar61 = DAT_0000cf00[2];
    iVar20 = DAT_0000cf00[3];
    *local_9c4 = (char *)*DAT_0000cf00;
    local_9c4[1] = (char *)iVar58;
    local_9c4[2] = (char *)iVar61;
    local_9c4[3] = (char *)iVar20;
    iVar58 = DAT_0000cf00[5];
    iVar61 = DAT_0000cf00[6];
    local_9c4[4] = (char *)DAT_0000cf00[4];
    local_9c4[5] = (char *)iVar58;
    *(char *)(local_9c4 + 6) = (char)iVar61;
LAB_0000cdee:
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  if (*(int *)(iVar58 + 0xe98) != 8) {
    snprintf((char *)local_9c4,0x800,DAT_0000c724);
    _applog(3,(char *)local_9c4,true);
                    /* WARNING: Subroutine does not return */
    __quit(1,false);
  }
  iVar20 = nice(-10);
  iVar61 = DAT_0000ca28;
  if (iVar20 == 0) {
    local_9c8 = (block *)DAT_0000ca0c;
    if (*DAT_0000ca0c == '\0') {
      ppiStack_9e0 = (int **)DAT_0000d08c;
      local_9d8 = DAT_0000d090;
      pcStack_9dc = DAT_0000d094;
    }
    else {
      if ((*(char *)&local_9cc->id == '\0') && (local_9d0->hash[0] == '\0')) {
        local_9d8 = DAT_0000cf08;
        if (*DAT_0000cf08 < 7) {
          ppiStack_9e0 = (int **)DAT_0000cf04;
          pcStack_9dc = DAT_0000cf10;
          goto LAB_0000c830;
        }
      }
      else {
        local_9d8 = DAT_0000ca00;
      }
      ppiStack_9e0 = (int **)DAT_0000ca14;
      pcStack_9dc = DAT_0000ca18;
      iVar61 = DAT_0000ca10[1];
      iVar20 = DAT_0000ca10[2];
      iVar63 = DAT_0000ca10[3];
      *local_9c4 = (char *)*DAT_0000ca10;
      local_9c4[1] = (char *)iVar61;
      local_9c4[2] = (char *)iVar20;
      local_9c4[3] = (char *)iVar63;
      iVar61 = DAT_0000ca10[5];
      iVar20 = DAT_0000ca10[6];
      iVar63 = DAT_0000ca10[7];
      local_9c4[4] = (char *)DAT_0000ca10[4];
      local_9c4[5] = (char *)iVar61;
      local_9c4[6] = (char *)iVar20;
      local_9c4[7] = (char *)iVar63;
      ptVar41 = (thr_info *)0x0;
      iVar61 = DAT_0000ca10[9];
      local_9c4[8] = (char *)DAT_0000ca10[8];
      *(short *)(local_9c4 + 9) = (short)iVar61;
      _applog(7,(char *)local_9c4,false);
      iVar61 = DAT_0000ca28;
    }
  }
  else {
    ppiStack_9e0 = (int **)DAT_0000cf04;
    local_9d8 = DAT_0000cf08;
    local_9c8 = (block *)DAT_0000cf0c;
    pcStack_9dc = DAT_0000cf10;
  }
LAB_0000c830:
  do {
    cVar3 = *pcStack_9dc;
    while( true ) {
      if (cVar3 != '\0') {
        if (((*(char *)&local_9cc->id != '\0') || (local_9d0->hash[0] != '\0')) ||
           (pptVar32 = (thr_info **)*local_9d8, 5 < (int)pptVar32)) {
          iVar20 = DAT_0000cebc[1];
          iVar63 = DAT_0000cebc[2];
          iVar59 = DAT_0000cebc[3];
          *local_9c4 = (char *)*DAT_0000cebc;
          ((int *)local_9c4)[1] = iVar20;
          ((int *)local_9c4)[2] = iVar63;
          ((int *)local_9c4)[3] = iVar59;
          iVar20 = DAT_0000cebc[5];
          iVar63 = DAT_0000cebc[6];
          pptVar32 = (thr_info **)DAT_0000cebc[7];
          ((int *)local_9c4)[4] = DAT_0000cebc[4];
          ((int *)local_9c4)[5] = iVar20;
          ((int *)local_9c4)[6] = iVar63;
          ptVar41 = (thr_info *)0x0;
          *(char *)((int *)local_9c4 + 7) = (char)pptVar32;
          _applog(6,(char *)local_9c4,false);
        }
        cgtime(DAT_0000cec0);
        iVar20 = pthread_rwlock_rdlock(DAT_0000cec4);
        if (iVar20 != 0) {
          _rd_lock(DAT_0000cedc,(char *)0x151a,(char *)ptVar41,(int)pptVar32);
        }
        if (0 < mining_threads) {
          pptVar36 = mining_thr + mining_threads;
          pptVar56 = mining_thr;
          do {
            pptVar32 = pptVar56 + 1;
            ptVar41 = *pptVar56;
            ptVar41->work_update = true;
            pptVar56 = pptVar32;
          } while (pptVar32 != pptVar36);
        }
        iVar20 = pthread_rwlock_unlock(DAT_0000cec4);
        if (iVar20 != 0) {
          _rw_unlock(DAT_0000d098,(char *)0x1521,(char *)ptVar41,(int)pptVar32);
        }
        (*(code *)*ppiStack_9e0)();
      }
      ppVar13 = stgd_lock;
      pUVar45 = (UT_hash_table *)0x0;
      *pcStack_9dc = '\0';
      iVar20 = pthread_mutex_lock((pthread_mutex_t *)ppVar13);
      if (iVar20 != 0) {
        _mutex_lock((pthread_mutex_t *)DAT_0000cecc,(char *)0x2f3c,(char *)ptVar41,(int)pUVar45);
      }
      ppVar13 = stgd_lock;
      __cond = DAT_0000ced0;
      ts = (int)staged_work;
      if (staged_work != (work *)0x0) {
        pUVar45 = (staged_work->hh).tbl;
        ts = pUVar45->num_items;
        if (1 < ts) {
          pUVar45 = (UT_hash_table *)0x1;
          *(undefined *)(iVar58 + 0xea4) = 1;
          pthread_cond_wait(__cond,(pthread_mutex_t *)ppVar13);
          ts = (int)staged_work;
          if (staged_work != (work *)0x0) {
            pUVar45 = (staged_work->hh).tbl;
            ts = pUVar45->num_items;
          }
        }
      }
      iVar20 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
      if (iVar20 != 0) {
        _mutex_unlock_noyield
                  ((pthread_mutex_t *)DAT_0000cecc,(char *)0x2f47,(char *)ptVar41,(int)pUVar45);
      }
      (*(code *)*ppiStack_9e0)();
      if (1 < ts) break;
      if (work != (work *)0x0) {
        ptVar41 = DAT_0000ca20;
        _discard_work(&work,DAT_0000ca1c,(char *)DAT_0000ca20,0x2f5b);
      }
      work = make_work();
LAB_0000c96a:
      pool_6 = current_pool();
      iVar20 = total_pools;
      if (pool_strategy == POOL_BALANCE) {
        ppVar24 = select_balanced(pool_6);
      }
      else {
        ppVar24 = pool_6;
        if (pool_strategy == POOL_LOADBALANCE) {
          if (total_pools < 1) {
LAB_0000c9d2:
            iVar63 = *(int *)(iVar58 + 0xea8) + 1;
            *(int *)(iVar58 + 0xea8) = iVar63;
            if (iVar20 <= iVar63) {
              *(undefined4 *)(iVar61 + 0xea8) = 0;
            }
          }
          else {
            ptVar41 = *pptStack_9d4;
            if (*(int *)(ptVar41->id + 0x3c) <= *(int *)(ptVar41->id + 0x40)) {
              iVar63 = 0;
              ptVar68 = ptVar41;
LAB_0000c9bc:
              iVar63 = iVar63 + 1;
              if (iVar63 != total_pools) goto LAB_0000c9b0;
              piVar33 = &ptVar41->id + total_pools;
              ptVar68 = ptVar41;
              do {
                piVar49 = &ptVar68->device_thread;
                *(undefined4 *)(ptVar68->id + 0x40) = 0;
                ptVar68 = (thr_info *)piVar49;
              } while (piVar49 != piVar33);
              goto LAB_0000c9d2;
            }
          }
LAB_0000c9e4:
          ptVar68 = *pptStack_9d4;
          iVar63 = 0;
          while (iVar63 < iVar20) {
            iVar66 = *(int *)(iVar58 + 0xea8);
            ppVar24 = (pool *)(&ptVar68->id)[iVar66];
            iVar59 = ppVar24->quota_used;
            ptVar41 = (thr_info *)ppVar24->quota_gcd;
            ppVar24->quota_used = iVar59 + 1;
            if ((iVar59 < (int)ptVar41) &&
               (local_9e4 = ptVar68, _Var15 = pool_unusable(ppVar24), ptVar68 = local_9e4, !_Var15))
            goto out;
            iVar66 = iVar66 + 1;
            iVar63 = iVar63 + 1;
            *(int *)(iVar58 + 0xea8) = iVar66;
            if (iVar20 <= iVar66) {
              *(undefined4 *)(iVar61 + 0xea8) = 0;
            }
          }
          ppVar24 = pool_6;
          if (0 < iVar20) {
            iVar20 = 0;
            do {
              ppVar35 = priority_pool(iVar20);
              _Var15 = pool_unusable(ppVar35);
              ppVar24 = pool_6;
              if (!_Var15) {
                if (ppVar35 != (pool *)0x0) {
                  ppVar24 = ppVar35;
                }
                break;
              }
              iVar20 = iVar20 + 1;
            } while (iVar20 < total_pools);
          }
        }
      }
out:
      pool_6 = ppVar24;
      if ((local_9c8->hash[0] != '\0') &&
         (((*(char *)&local_9cc->id != '\0' || (local_9d0->hash[0] != '\0')) || (6 < *local_9d8))))
      {
        snprintf((char *)local_9c4,0x800,DAT_0000ca24,pool_6->pool_no);
        ptVar41 = (thr_info *)0x0;
        _applog(7,(char *)local_9c4,false);
      }
      _Var15 = pool_unusable(pool_6);
      if (_Var15) {
        switch_pools((pool *)0x0);
        pool_6 = current_pool();
        iVar20 = total_pools;
        if (pool_strategy == POOL_BALANCE) {
          ppVar24 = select_balanced(pool_6);
        }
        else {
          ppVar24 = pool_6;
          if (pool_strategy == POOL_LOADBALANCE) {
            if (total_pools < 1) {
LAB_0000caee:
              iVar63 = *(int *)(iVar58 + 0xea8) + 1;
              *(int *)(iVar58 + 0xea8) = iVar63;
              if (iVar20 <= iVar63) {
                *(undefined4 *)(iVar61 + 0xea8) = 0;
              }
            }
            else {
              ptVar41 = *pptStack_9d4;
              if (*(int *)(ptVar41->id + 0x3c) <= *(int *)(ptVar41->id + 0x40)) {
                iVar63 = 0;
                ptVar68 = ptVar41;
LAB_0000cad8:
                iVar63 = iVar63 + 1;
                if (iVar63 != total_pools) goto LAB_0000cacc;
                piVar33 = &ptVar41->id + total_pools;
                ptVar68 = ptVar41;
                do {
                  piVar49 = &ptVar68->device_thread;
                  *(undefined4 *)(ptVar68->id + 0x40) = 0;
                  ptVar68 = (thr_info *)piVar49;
                } while (piVar49 != piVar33);
                goto LAB_0000caee;
              }
            }
LAB_0000cb00:
            ptVar68 = *pptStack_9d4;
            iVar63 = 0;
            while (iVar63 < iVar20) {
              iVar66 = *(int *)(iVar58 + 0xea8);
              ppVar24 = (pool *)(&ptVar68->id)[iVar66];
              iVar59 = ppVar24->quota_used;
              ptVar41 = (thr_info *)ppVar24->quota_gcd;
              ppVar24->quota_used = iVar59 + 1;
              if ((iVar59 < (int)ptVar41) &&
                 (local_9e4 = ptVar68, _Var15 = pool_unusable(ppVar24), ptVar68 = local_9e4, !_Var15
                 )) goto out;
              iVar66 = iVar66 + 1;
              iVar63 = iVar63 + 1;
              *(int *)(iVar58 + 0xea8) = iVar66;
              if (iVar20 <= iVar66) {
                *(undefined4 *)(iVar61 + 0xea8) = 0;
              }
            }
            ppVar24 = pool_6;
            if (0 < iVar20) {
              iVar20 = 0;
              do {
                ppVar35 = priority_pool(iVar20);
                _Var15 = pool_unusable(ppVar35);
                ppVar24 = pool_6;
                if (!_Var15) {
                  if (ppVar35 != (pool *)0x0) {
                    ppVar24 = ppVar35;
                  }
                  break;
                }
                iVar20 = iVar20 + 1;
              } while (iVar20 < total_pools);
            }
          }
        }
out:
        pool_6 = ppVar24;
        if ((local_9c8->hash[0] != '\0') &&
           (((*(char *)&local_9cc->id != '\0' || (local_9d0->hash[0] != '\0')) || (6 < *local_9d8)))
           ) {
          snprintf((char *)local_9c4,0x800,DAT_0000ca24,pool_6->pool_no);
          ptVar41 = (thr_info *)0x0;
          _applog(7,(char *)local_9c4,false);
        }
        _Var15 = pool_unusable(pool_6);
        if (_Var15) {
          cgsleep_ms(0xb);
        }
        goto LAB_0000c96a;
      }
      if (pool_6->has_stratum == false) {
        if (opt_benchfile == (char *)0x0) {
          if (opt_benchmark == false) goto LAB_0000c830;
          get_benchmark_work(work);
          if (local_9c8->hash[0] != '\0') {
            piVar33 = DAT_0000ced8;
            if ((*(char *)&local_9cc->id == '\0') && (local_9d0->hash[0] == '\0')) {
              iVar20 = *local_9d8;
              goto joined_r0x0000cd7c;
            }
            goto LAB_0000cbe8;
          }
        }
        else {
          get_benchfile_work(work);
          if (local_9c8->hash[0] != '\0') {
            piVar33 = DAT_0000ceb8;
            if ((*(char *)&local_9cc->id == '\0') && (local_9d0->hash[0] == '\0')) {
              iVar20 = *local_9d8;
joined_r0x0000cd7c:
              if (iVar20 < 7) goto LAB_0000cc00;
            }
LAB_0000cbe8:
            iVar20 = piVar33[1];
            iVar63 = piVar33[2];
            iVar59 = piVar33[3];
            *local_9c4 = (char *)*piVar33;
            local_9c4[1] = (char *)iVar20;
            local_9c4[2] = (char *)iVar63;
            local_9c4[3] = (char *)iVar59;
            iVar20 = piVar33[5];
            iVar63 = piVar33[6];
            local_9c4[4] = (char *)piVar33[4];
            local_9c4[5] = (char *)iVar20;
            *(char *)(local_9c4 + 6) = (char)iVar63;
            ptVar41 = (thr_info *)0x0;
            _applog(7,(char *)local_9c4,false);
          }
        }
      }
      else {
        gen_stratum_work(pool_6,work);
        if ((local_9c8->hash[0] != '\0') &&
           (((*(char *)&local_9cc->id != '\0' || (local_9d0->hash[0] != '\0')) || (6 < *local_9d8)))
           ) {
          iVar20 = DAT_0000ced4[1];
          iVar63 = DAT_0000ced4[2];
          iVar59 = DAT_0000ced4[3];
          *local_9c4 = (char *)*DAT_0000ced4;
          local_9c4[1] = (char *)iVar20;
          local_9c4[2] = (char *)iVar63;
          local_9c4[3] = (char *)iVar59;
          ptVar41 = (thr_info *)0x0;
          iVar20 = DAT_0000ced4[5];
          local_9c4[4] = (char *)DAT_0000ced4[4];
          *(short *)(local_9c4 + 5) = (short)iVar20;
          *(char *)((int)local_9c4 + 0x16) = (char)((uint)iVar20 >> 0x10);
          _applog(7,(char *)local_9c4,false);
        }
      }
LAB_0000cc00:
      _stage_work(work);
      work = (work *)0x0;
      cVar3 = *pcStack_9dc;
    }
    *(undefined *)(iVar58 + 0xea4) = 1;
    work = hash_pop(false);
    if (work != (work *)0x0) {
      ptVar41 = DAT_0000cecc;
      _discard_work(&work,DAT_0000cec8,(char *)DAT_0000cecc,0x2f53);
    }
  } while( true );
LAB_0000c9b0:
  ptVar68 = (thr_info *)&ptVar68->device_thread;
  if (*(int *)(*(int *)ptVar68 + 0x40) < *(int *)(*(int *)ptVar68 + 0x3c)) goto LAB_0000c9e4;
  goto LAB_0000c9bc;
LAB_0000cacc:
  ptVar68 = (thr_info *)&ptVar68->device_thread;
  if (*(int *)(*(int *)ptVar68 + 0x40) < *(int *)(*(int *)ptVar68 + 0x3c)) goto LAB_0000cb00;
  goto LAB_0000cad8;
}

