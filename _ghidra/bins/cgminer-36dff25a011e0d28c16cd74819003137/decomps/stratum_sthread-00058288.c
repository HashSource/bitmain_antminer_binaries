
void * stratum_sthread(void *userdata)

{
  work *pwVar1;
  _Bool _Var2;
  pthread_t __th;
  thread_q *ptVar3;
  stratum_share *__ptr;
  time_t tVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  __uint32_t _Var7;
  size_t len;
  UT_hash_table *pUVar8;
  UT_hash_bucket *pUVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  UT_hash_handle *pUVar14;
  UT_hash_bucket *pUVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  undefined4 uVar19;
  bool bVar20;
  uchar auVar21 [8];
  char *pcVar22;
  char *pcVar23;
  void *userdata_local;
  char s [1024];
  char tmp42 [2048];
  uint32_t pool_version;
  work *work;
  uchar nonce2 [8];
  uint32_t nonce;
  char nonce2hex [20];
  char noncehex [12];
  char threadname [16];
  int ssdiff;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  _Bool sessionid_match;
  uint32_t *hash32;
  stratum_share *sshare;
  uint64_t *nonce2_64;
  pool *pool;
  UT_hash_handle *_he_thh;
  uint _he_bkt_i;
  uchar *_hj_key;
  uint _hj_k;
  uint _hj_j;
  uint _hj_i;
  uint _ha_hashv;
  _Bool submitted;
  uint32_t last_nonce;
  uint64_t last_nonce2;
  
  last_nonce2._0_4_ = 0;
  last_nonce2._4_4_ = 0;
  last_nonce = 0;
  __th = pthread_self();
  pthread_detach(__th);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,"%d/SStratum",*userdata);
  RenameThread(threadname);
  ptVar3 = tq_new();
  uVar19 = tmp42._44_4_;
  *(thread_q **)((int)userdata + 0x2d8) = ptVar3;
  if (*(int *)((int)userdata + 0x2d8) == 0) {
    builtin_strncpy(tmp42,"Failed to create stratum_q in stratum_sthread",0x2e);
    tmp42._46_2_ = SUB42(uVar19,2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"in %s ","stratum_sthread");
    _applog(5,tmp42,false);
  }
  do {
    while( true ) {
      while( true ) {
        if (*(char *)((int)userdata + 0x69) != '\0') {
          tq_freeze(*(thread_q **)((int)userdata + 0x2d8));
          return (void *)0x0;
        }
        work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2d8),(timespec *)0x0);
        uVar19 = tmp42._28_4_;
        if (work == (work *)0x0) {
          builtin_strncpy(tmp42,"Stratum q returned empty work",0x1e);
          tmp42._30_2_ = SUB42(uVar19,2);
          _applog(3,tmp42,true);
          _quit(1);
        }
        if (work->nonce2_len < 9) break;
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d asking for inappropriately long nonce2 length %d",*userdata,
                   work->nonce2_len);
          _applog(3,tmp42,false);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"Not attempting to submit shares",0x20);
          _applog(3,tmp42,false);
        }
        _free_work(&work,"cgminer.c","stratum_sthread",0x1dc5);
      }
      nonce = *(uint32_t *)(work->data + 0x4c);
      auVar21 = (uchar  [8])__uint64_identity(work->nonce2);
      nonce2._0_4_ = auVar21._0_4_;
      nonce2._4_4_ = auVar21._4_4_;
      nonce2 = auVar21;
      if ((last_nonce != nonce) ||
         (last_nonce2._4_4_ != nonce2._4_4_ || (int)last_nonce2 != nonce2._0_4_)) break;
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Filtering duplicate share to pool %d",*userdata);
        _applog(6,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1dd1);
    }
    last_nonce = nonce;
    last_nonce2._0_1_ = nonce2[0];
    last_nonce2._1_1_ = nonce2[1];
    last_nonce2._2_1_ = nonce2[2];
    last_nonce2._3_1_ = nonce2[3];
    last_nonce2._4_1_ = nonce2[4];
    last_nonce2._5_1_ = nonce2[5];
    last_nonce2._6_1_ = nonce2[6];
    last_nonce2._7_1_ = nonce2[7];
    __bin2hex(noncehex,(uchar *)&nonce,4);
    __bin2hex(nonce2hex,nonce2,work->nonce2_len);
    __ptr = (stratum_share *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1dda);
    pwVar1 = work;
    bVar20 = false;
    tVar4 = time((time_t *)0x0);
    __ptr->sshare_time = tVar4;
    __ptr->work = work;
    memset(s,0,0x400);
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1de3);
    iVar16 = swork_id + 1;
    __ptr->id = swork_id;
    swork_id = iVar16;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1de6);
    pool_version = 0;
    hex2bin((uchar *)&pool_version,(char *)((int)userdata + 0x6f4),4);
    if (*(char *)((int)userdata + 0x284) == '\0') {
      pcVar18 = work->ntime;
      uVar11 = __ptr->id;
      pcVar23 = noncehex;
      pcVar22 = nonce2hex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,*(undefined4 *)((int)userdata + 0xac),work->job_id,pcVar22,pcVar18,pcVar23,uVar11);
    }
    else {
      uVar19 = *(undefined4 *)((int)userdata + 0xac);
      pcVar17 = work->job_id;
      pcVar18 = work->ntime;
      uVar5 = swab32(work->version);
      uVar6 = swab32(pool_version);
      uVar11 = ~uVar6 & uVar5;
      pcVar23 = noncehex;
      pcVar22 = nonce2hex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,uVar19,pcVar17,pcVar22,pcVar18,pcVar23,uVar11,__ptr->id);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      _Var7 = __uint32_identity(*(__uint32_t *)(pwVar1->hash + 0x18));
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Submitting share %08lx to pool %d",_Var7,*userdata,pcVar22,pcVar18,
               pcVar23,uVar11);
      _applog(6,tmp42,false);
    }
    while( true ) {
      tVar4 = time((time_t *)0x0);
      if (__ptr->sshare_time + 0x78 <= tVar4) goto LAB_00059ca4;
      len = strlen(s);
      _Var2 = stratum_send((pool *)userdata,s,len);
      if (_Var2) break;
      _Var2 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x60));
      if ((!_Var2) && (_Var2 = cnx_needed((pool *)userdata), _Var2)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d stratum share submission failure",*userdata);
          _applog(4,tmp42,false);
        }
        total_ro = total_ro + 1;
        *(int *)((int)userdata + 0x84) = *(int *)((int)userdata + 0x84) + 1;
      }
      uVar19 = tmp42._48_4_;
      if (opt_lowmem != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Lowmem option prevents resubmitting stratum share",0x32);
          tmp42._50_2_ = SUB42(uVar19,2);
          _applog(7,tmp42,false);
        }
        goto LAB_00059ca4;
      }
      _cg_rlock((cglock_t *)((int)userdata + 0xd4),"cgminer.c","stratum_sthread",0x1e26);
      if ((*(int *)((int)userdata + 0x264) == 0) ||
         (iVar16 = strcmp(work->nonce1,*(char **)((int)userdata + 0x264)), iVar16 != 0)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      _cg_runlock((cglock_t *)((int)userdata + 0xd4),"cgminer.c","stratum_sthread",0x1e28);
      if (!bVar10) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"No matching session id for resubmitting stratum shar",0x34);
          tmp42[0x34] = 'e';
          tmp42[0x35] = '\0';
          _applog(7,tmp42,false);
        }
        goto LAB_00059ca4;
      }
      sleep(2);
    }
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1e0d);
    _hj_key = (uchar *)&__ptr->id;
    _ha_hashv = 0xfeedbeef;
    _hj_j = 0x9e3779b9;
    _hj_i = 0x9e3779b9;
    for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
      iVar16 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                       (uint)_hj_key[7] * 0x1000000;
      uVar11 = _ha_hashv +
               (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
               (uint)_hj_key[0xb] * 0x1000000;
      uVar12 = uVar11 >> 0xd ^
               ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                         (uint)_hj_key[3] * 0x1000000) - iVar16) - uVar11;
      uVar13 = uVar12 << 8 ^ (iVar16 - uVar11) - uVar12;
      uVar11 = uVar13 >> 0xd ^ (uVar11 - uVar12) - uVar13;
      uVar12 = uVar11 >> 0xc ^ (uVar12 - uVar13) - uVar11;
      uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar11) - uVar12;
      uVar11 = uVar13 >> 5 ^ (uVar11 - uVar12) - uVar13;
      _hj_i = uVar11 >> 3 ^ (uVar12 - uVar13) - uVar11;
      _hj_j = _hj_i << 10 ^ (uVar13 - uVar11) - _hj_i;
      _ha_hashv = _hj_j >> 0xf ^ (uVar11 - _hj_i) - _hj_j;
      _hj_key = _hj_key + 0xc;
    }
    uVar11 = _ha_hashv + 4;
    switch(_hj_k) {
    case 8:
      _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000 + (uint)_hj_key[6] * 0x10000 +
              (uint)_hj_key[5] * 0x100 + (uint)_hj_key[4];
    case 4:
      _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000 + (uint)_hj_key[2] * 0x10000 +
              (uint)_hj_key[1] * 0x100 + (uint)*_hj_key;
    }
    uVar12 = uVar11 >> 0xd ^ (_hj_i - _hj_j) - uVar11;
    uVar13 = uVar12 << 8 ^ (_hj_j - uVar11) - uVar12;
    uVar11 = uVar13 >> 0xd ^ (uVar11 - uVar12) - uVar13;
    uVar12 = uVar11 >> 0xc ^ (uVar12 - uVar13) - uVar11;
    uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar11) - uVar12;
    uVar11 = uVar13 >> 5 ^ (uVar11 - uVar12) - uVar13;
    uVar12 = uVar11 >> 3 ^ (uVar12 - uVar13) - uVar11;
    uVar13 = uVar12 << 10 ^ (uVar13 - uVar11) - uVar12;
    uVar11 = uVar13 >> 0xf ^ (uVar11 - uVar12) - uVar13;
    (__ptr->hh).hashv = uVar11;
    (__ptr->hh).key = &__ptr->id;
    (__ptr->hh).keylen = 4;
    if (stratum_shares == (stratum_share *)0x0) {
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev = (void *)0x0;
      stratum_shares = __ptr;
      pUVar8 = (UT_hash_table *)malloc(0x2c);
      (__ptr->hh).tbl = pUVar8;
      if ((stratum_shares->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((stratum_shares->hh).tbl,0,0x2c);
      ((stratum_shares->hh).tbl)->tail = &stratum_shares->hh;
      ((stratum_shares->hh).tbl)->num_buckets = 0x20;
      ((stratum_shares->hh).tbl)->log2_num_buckets = 5;
      ((stratum_shares->hh).tbl)->hho = 0;
      pUVar8 = (stratum_shares->hh).tbl;
      pUVar9 = (UT_hash_bucket *)malloc(0x180);
      pUVar8->buckets = pUVar9;
      if (((stratum_shares->hh).tbl)->buckets == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(((stratum_shares->hh).tbl)->buckets,0,0x180);
      ((stratum_shares->hh).tbl)->signature = 0xa0111fe1;
    }
    else {
      (__ptr->hh).tbl = (stratum_shares->hh).tbl;
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev =
           (void *)((int)((stratum_shares->hh).tbl)->tail - ((stratum_shares->hh).tbl)->hho);
      ((stratum_shares->hh).tbl)->tail->next = __ptr;
      ((stratum_shares->hh).tbl)->tail = (UT_hash_handle *)__ptr;
    }
    pUVar8 = (stratum_shares->hh).tbl;
    pUVar8->num_items = pUVar8->num_items + 1;
    uVar11 = ((stratum_shares->hh).tbl)->num_buckets - 1 & uVar11;
    pUVar9 = ((stratum_shares->hh).tbl)->buckets;
    pUVar9[uVar11].count = pUVar9[uVar11].count + 1;
    (__ptr->hh).hh_next = ((stratum_shares->hh).tbl)->buckets[uVar11].hh_head;
    (__ptr->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((stratum_shares->hh).tbl)->buckets[uVar11].hh_head != (UT_hash_handle *)0x0) {
      (((stratum_shares->hh).tbl)->buckets[uVar11].hh_head)->hh_prev = (UT_hash_handle *)__ptr;
    }
    ((stratum_shares->hh).tbl)->buckets[uVar11].hh_head = (UT_hash_handle *)__ptr;
    if (((((stratum_shares->hh).tbl)->buckets[uVar11].expand_mult + 1) * 10 <=
         ((stratum_shares->hh).tbl)->buckets[uVar11].count) && (((__ptr->hh).tbl)->noexpand != 1)) {
      pUVar9 = (UT_hash_bucket *)malloc(((__ptr->hh).tbl)->num_buckets * 0x18);
      if (pUVar9 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar9,0,((__ptr->hh).tbl)->num_buckets * 0x18);
      ((__ptr->hh).tbl)->ideal_chain_maxlen =
           (uint)((((__ptr->hh).tbl)->num_buckets * 2 - 1 & ((__ptr->hh).tbl)->num_items) != 0) +
           (((__ptr->hh).tbl)->num_items >> (((__ptr->hh).tbl)->log2_num_buckets + 1 & 0xff));
      ((__ptr->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__ptr->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__ptr->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar14 = _he_thh->hh_next;
          pUVar15 = pUVar9 + (((__ptr->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar15->count = pUVar15->count + 1;
          if (((__ptr->hh).tbl)->ideal_chain_maxlen < pUVar15->count) {
            pUVar8 = (__ptr->hh).tbl;
            pUVar8->nonideal_items = pUVar8->nonideal_items + 1;
            uVar11 = __udivsi3(pUVar15->count,((__ptr->hh).tbl)->ideal_chain_maxlen);
            pUVar15->expand_mult = uVar11;
          }
          _he_thh->hh_prev = (UT_hash_handle *)0x0;
          _he_thh->hh_next = pUVar15->hh_head;
          if (pUVar15->hh_head != (UT_hash_handle *)0x0) {
            pUVar15->hh_head->hh_prev = _he_thh;
          }
          pUVar15->hh_head = _he_thh;
          _he_thh = pUVar14;
        }
      }
      free(((__ptr->hh).tbl)->buckets);
      ((__ptr->hh).tbl)->num_buckets = ((__ptr->hh).tbl)->num_buckets << 1;
      pUVar8 = (__ptr->hh).tbl;
      pUVar8->log2_num_buckets = pUVar8->log2_num_buckets + 1;
      ((__ptr->hh).tbl)->buckets = pUVar9;
      if (((__ptr->hh).tbl)->num_items >> 1 < ((__ptr->hh).tbl)->nonideal_items) {
        uVar11 = ((__ptr->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar11 = 0;
      }
      ((__ptr->hh).tbl)->ineff_expands = uVar11;
      if (1 < ((__ptr->hh).tbl)->ineff_expands) {
        ((__ptr->hh).tbl)->noexpand = 1;
      }
    }
    *(int *)((int)userdata + 0x2dc) = *(int *)((int)userdata + 0x2dc) + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1e10);
    _Var2 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x60));
    if ((_Var2) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Pool %d communication resumed, submitting work",*userdata);
      _applog(4,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Successfully submitted, adding to stratum_shares db",0x34);
      _applog(7,tmp42,false);
    }
    bVar20 = true;
LAB_00059ca4:
    uVar19 = tmp42._40_4_;
    if (bVar20) {
      tVar4 = time((time_t *)0x0);
      __ptr->sshare_sent = tVar4;
      iVar16 = __ptr->sshare_sent - __ptr->sshare_time;
      if (((opt_debug != false) || (0 < iVar16)) &&
         ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Pool %d stratum share submission lag time %d seconds",*userdata,iVar16
                );
        _applog(6,tmp42,false);
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Failed to submit stratum share, discarding",0x2b);
        tmp42[0x2b] = SUB41(uVar19,3);
        _applog(7,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1e37);
      free(__ptr);
      *(int *)((int)userdata + 0x78) = *(int *)((int)userdata + 0x78) + 1;
      bVar20 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar20;
    }
  } while( true );
}

