
void * stratum_sthread(void *userdata)

{
  work *pwVar1;
  _Bool _Var2;
  pthread_t __th;
  thread_q *ptVar3;
  stratum_share *__ptr;
  time_t tVar4;
  uint uVar5;
  size_t len;
  UT_hash_table *pUVar6;
  UT_hash_bucket *pUVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  UT_hash_handle *pUVar14;
  UT_hash_bucket *pUVar15;
  int iVar16;
  undefined4 uVar17;
  char *pcVar18;
  char *pcVar19;
  bool bVar20;
  char *pcVar21;
  char *pcVar22;
  void *userdata_local;
  char s [1024];
  char tmp42 [2048];
  work *work;
  uchar nonce2 [8];
  uint nonce;
  char nonce2hex [20];
  char noncehex [12];
  char threadname [16];
  int ssdiff;
  _Bool sessionid_match;
  UT_hash_bucket *_he_newbkt;
  uint _he_bkt;
  UT_hash_handle *_he_hh_nxt;
  UT_hash_bucket *_he_new_buckets;
  uint _ha_bkt;
  uint *hash32;
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
  uint last_nonce;
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
  uVar17 = tmp42._44_4_;
  *(thread_q **)((int)userdata + 0x2e0) = ptVar3;
  if (*(int *)((int)userdata + 0x2e0) == 0) {
    builtin_strncpy(tmp42,"Failed to create stratum_q in stratum_sthread",0x2e);
    tmp42._46_2_ = SUB42(uVar17,2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  do {
    while( true ) {
      while( true ) {
        if (*(char *)((int)userdata + 0x6d) != '\0') {
          tq_freeze(*(thread_q **)((int)userdata + 0x2e0));
          return (void *)0x0;
        }
        work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2e0),(timespec *)0x0);
        uVar17 = tmp42._28_4_;
        if (work == (work *)0x0) {
          builtin_strncpy(tmp42,"Stratum q returned empty work",0x1e);
          tmp42._30_2_ = SUB42(uVar17,2);
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
        _free_work(&work,"cgminer.c","stratum_sthread",0x1d79);
      }
      uVar9 = *(uint *)(work->data + 0x4c);
      iVar16 = (int)work->nonce2;
      iVar10 = *(int *)((int)&work->nonce2 + 4);
      nonce = uVar9;
      nonce2._0_4_ = iVar16;
      nonce2._4_4_ = iVar10;
      if ((uVar9 != last_nonce) || (iVar10 != last_nonce2._4_4_ || iVar16 != (int)last_nonce2))
      break;
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Filtering duplicate share to pool %d",*userdata);
        _applog(6,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1d85);
    }
    __bin2hex(noncehex,(uchar *)&nonce,4);
    __bin2hex(nonce2hex,nonce2,work->nonce2_len);
    __ptr = (stratum_share *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1d8e);
    pwVar1 = work;
    bVar20 = false;
    tVar4 = time((time_t *)0x0);
    __ptr->sshare_time = tVar4;
    __ptr->work = work;
    memset(s,0,0x400);
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1d97);
    __ptr->id = swork_id;
    swork_id = swork_id + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1d9a);
    if (*(char *)((int)userdata + 0x28c) == '\0') {
      pcVar18 = work->ntime;
      uVar5 = __ptr->id;
      pcVar21 = nonce2hex;
      pcVar22 = noncehex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,*(undefined4 *)((int)userdata + 0xb4),work->job_id,pcVar21,pcVar18,pcVar22,uVar5);
    }
    else {
      uVar17 = *(undefined4 *)((int)userdata + 0xb4);
      pcVar19 = work->job_id;
      pcVar18 = work->ntime;
      uVar5 = swab32(work->version);
      pcVar21 = nonce2hex;
      pcVar22 = noncehex;
      snprintf(s,0x400,
               "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
               ,uVar17,pcVar19,pcVar21,pcVar18,pcVar22,uVar5,__ptr->id);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Submitting share %08lx to pool %d",*(undefined4 *)(pwVar1->hash + 0x18),
               *userdata,pcVar21,pcVar18,pcVar22,uVar5);
      _applog(6,tmp42,false);
    }
    while( true ) {
      tVar4 = time((time_t *)0x0);
      if (__ptr->sshare_time + 0x78 <= tVar4) goto LAB_00023b52;
      len = strlen(s);
      _Var2 = stratum_send((pool *)userdata,s,len);
      if (_Var2) break;
      _Var2 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x62));
      if ((!_Var2) && (_Var2 = cnx_needed((pool *)userdata), _Var2)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d stratum share submission failure",*userdata);
          _applog(4,tmp42,false);
        }
        total_ro = total_ro + 1;
        *(int *)((int)userdata + 0x88) = *(int *)((int)userdata + 0x88) + 1;
      }
      uVar17 = tmp42._48_4_;
      if (opt_lowmem != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Lowmem option prevents resubmitting stratum share",0x32);
          tmp42._50_2_ = SUB42(uVar17,2);
          _applog(7,tmp42,false);
        }
        goto LAB_00023b52;
      }
      _cg_rlock((cglock_t *)((int)userdata + 0xdc),"cgminer.c","stratum_sthread",0x1dd7);
      if ((*(int *)((int)userdata + 0x26c) == 0) ||
         (iVar11 = strcmp(work->nonce1,*(char **)((int)userdata + 0x26c)), iVar11 != 0)) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      _cg_runlock((cglock_t *)((int)userdata + 0xdc),"cgminer.c","stratum_sthread",0x1dd9);
      if (!bVar8) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"No matching session id for resubmitting stratum shar",0x34);
          tmp42[0x34] = 'e';
          tmp42[0x35] = '\0';
          _applog(7,tmp42,false);
        }
        goto LAB_00023b52;
      }
      sleep(2);
    }
    _mutex_lock(&sshare_lock,"cgminer.c","stratum_sthread",0x1dbe);
    _hj_key = (uchar *)&__ptr->id;
    _ha_hashv = 0xfeedbeef;
    _hj_j = 0x9e3779b9;
    _hj_i = 0x9e3779b9;
    for (_hj_k = 4; 0xb < _hj_k; _hj_k = _hj_k - 0xc) {
      iVar11 = _hj_j + (uint)_hj_key[4] + (uint)_hj_key[5] * 0x100 + (uint)_hj_key[6] * 0x10000 +
                       (uint)_hj_key[7] * 0x1000000;
      uVar5 = _ha_hashv +
              (uint)_hj_key[8] + (uint)_hj_key[9] * 0x100 + (uint)_hj_key[10] * 0x10000 +
              (uint)_hj_key[0xb] * 0x1000000;
      uVar12 = uVar5 >> 0xd ^
               ((_hj_i + (uint)*_hj_key + (uint)_hj_key[1] * 0x100 + (uint)_hj_key[2] * 0x10000 +
                         (uint)_hj_key[3] * 0x1000000) - iVar11) - uVar5;
      uVar13 = uVar12 << 8 ^ (iVar11 - uVar5) - uVar12;
      uVar5 = uVar13 >> 0xd ^ (uVar5 - uVar12) - uVar13;
      uVar12 = uVar5 >> 0xc ^ (uVar12 - uVar13) - uVar5;
      uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar5) - uVar12;
      uVar5 = uVar13 >> 5 ^ (uVar5 - uVar12) - uVar13;
      _hj_i = uVar5 >> 3 ^ (uVar12 - uVar13) - uVar5;
      _hj_j = _hj_i << 10 ^ (uVar13 - uVar5) - _hj_i;
      _ha_hashv = _hj_j >> 0xf ^ (uVar5 - _hj_i) - _hj_j;
      _hj_key = _hj_key + 0xc;
    }
    uVar5 = _ha_hashv + 4;
    switch(_hj_k) {
    case 8:
      _hj_j = _hj_j + (uint)_hj_key[7] * 0x1000000 + (uint)_hj_key[6] * 0x10000 +
              (uint)_hj_key[5] * 0x100 + (uint)_hj_key[4];
    case 4:
      _hj_i = _hj_i + (uint)_hj_key[3] * 0x1000000 + (uint)_hj_key[2] * 0x10000 +
              (uint)_hj_key[1] * 0x100 + (uint)*_hj_key;
    }
    uVar12 = uVar5 >> 0xd ^ (_hj_i - _hj_j) - uVar5;
    uVar13 = uVar12 << 8 ^ (_hj_j - uVar5) - uVar12;
    uVar5 = uVar13 >> 0xd ^ (uVar5 - uVar12) - uVar13;
    uVar12 = uVar5 >> 0xc ^ (uVar12 - uVar13) - uVar5;
    uVar13 = uVar12 << 0x10 ^ (uVar13 - uVar5) - uVar12;
    uVar5 = uVar13 >> 5 ^ (uVar5 - uVar12) - uVar13;
    uVar12 = uVar5 >> 3 ^ (uVar12 - uVar13) - uVar5;
    uVar13 = uVar12 << 10 ^ (uVar13 - uVar5) - uVar12;
    uVar5 = uVar13 >> 0xf ^ (uVar5 - uVar12) - uVar13;
    (__ptr->hh).hashv = uVar5;
    (__ptr->hh).key = &__ptr->id;
    (__ptr->hh).keylen = 4;
    if (stratum_shares == (stratum_share *)0x0) {
      (__ptr->hh).next = (void *)0x0;
      (__ptr->hh).prev = (void *)0x0;
      stratum_shares = __ptr;
      pUVar6 = (UT_hash_table *)malloc(0x2c);
      (__ptr->hh).tbl = pUVar6;
      if ((stratum_shares->hh).tbl == (UT_hash_table *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset((stratum_shares->hh).tbl,0,0x2c);
      ((stratum_shares->hh).tbl)->tail = &stratum_shares->hh;
      ((stratum_shares->hh).tbl)->num_buckets = 0x20;
      ((stratum_shares->hh).tbl)->log2_num_buckets = 5;
      ((stratum_shares->hh).tbl)->hho = 0;
      pUVar6 = (stratum_shares->hh).tbl;
      pUVar7 = (UT_hash_bucket *)malloc(0x180);
      pUVar6->buckets = pUVar7;
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
    pUVar6 = (stratum_shares->hh).tbl;
    pUVar6->num_items = pUVar6->num_items + 1;
    uVar5 = uVar5 & ((stratum_shares->hh).tbl)->num_buckets - 1;
    pUVar7 = ((stratum_shares->hh).tbl)->buckets;
    pUVar7[uVar5].count = pUVar7[uVar5].count + 1;
    (__ptr->hh).hh_next = ((stratum_shares->hh).tbl)->buckets[uVar5].hh_head;
    (__ptr->hh).hh_prev = (UT_hash_handle *)0x0;
    if (((stratum_shares->hh).tbl)->buckets[uVar5].hh_head != (UT_hash_handle *)0x0) {
      (((stratum_shares->hh).tbl)->buckets[uVar5].hh_head)->hh_prev = (UT_hash_handle *)__ptr;
    }
    ((stratum_shares->hh).tbl)->buckets[uVar5].hh_head = (UT_hash_handle *)__ptr;
    if (((((stratum_shares->hh).tbl)->buckets[uVar5].expand_mult + 1) * 10 <=
         ((stratum_shares->hh).tbl)->buckets[uVar5].count) && (((__ptr->hh).tbl)->noexpand != 1)) {
      pUVar7 = (UT_hash_bucket *)malloc(((__ptr->hh).tbl)->num_buckets * 0x18);
      if (pUVar7 == (UT_hash_bucket *)0x0) {
                    /* WARNING: Subroutine does not return */
        exit(-1);
      }
      memset(pUVar7,0,((__ptr->hh).tbl)->num_buckets * 0x18);
      ((__ptr->hh).tbl)->ideal_chain_maxlen =
           (((__ptr->hh).tbl)->num_items >> (((__ptr->hh).tbl)->log2_num_buckets + 1 & 0xff)) +
           (uint)((((__ptr->hh).tbl)->num_buckets * 2 - 1 & ((__ptr->hh).tbl)->num_items) != 0);
      ((__ptr->hh).tbl)->nonideal_items = 0;
      for (_he_bkt_i = 0; _he_bkt_i < ((__ptr->hh).tbl)->num_buckets; _he_bkt_i = _he_bkt_i + 1) {
        _he_thh = ((__ptr->hh).tbl)->buckets[_he_bkt_i].hh_head;
        while (_he_thh != (UT_hash_handle *)0x0) {
          pUVar14 = _he_thh->hh_next;
          pUVar15 = pUVar7 + (((__ptr->hh).tbl)->num_buckets * 2 - 1 & _he_thh->hashv);
          pUVar15->count = pUVar15->count + 1;
          if (((__ptr->hh).tbl)->ideal_chain_maxlen < pUVar15->count) {
            pUVar6 = (__ptr->hh).tbl;
            pUVar6->nonideal_items = pUVar6->nonideal_items + 1;
            uVar5 = __aeabi_uidiv(pUVar15->count,((__ptr->hh).tbl)->ideal_chain_maxlen);
            pUVar15->expand_mult = uVar5;
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
      pUVar6 = (__ptr->hh).tbl;
      pUVar6->log2_num_buckets = pUVar6->log2_num_buckets + 1;
      ((__ptr->hh).tbl)->buckets = pUVar7;
      if (((__ptr->hh).tbl)->num_items >> 1 < ((__ptr->hh).tbl)->nonideal_items) {
        uVar5 = ((__ptr->hh).tbl)->ineff_expands + 1;
      }
      else {
        uVar5 = 0;
      }
      ((__ptr->hh).tbl)->ineff_expands = uVar5;
      if (1 < ((__ptr->hh).tbl)->ineff_expands) {
        ((__ptr->hh).tbl)->noexpand = 1;
      }
    }
    *(int *)((int)userdata + 0x2e4) = *(int *)((int)userdata + 0x2e4) + 1;
    _mutex_unlock(&sshare_lock,"cgminer.c","stratum_sthread",0x1dc1);
    _Var2 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x62));
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
LAB_00023b52:
    uVar17 = tmp42._40_4_;
    last_nonce = uVar9;
    last_nonce2._0_4_ = iVar16;
    last_nonce2._4_4_ = iVar10;
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
        tmp42[0x2b] = SUB41(uVar17,3);
        _applog(7,tmp42,false);
      }
      _free_work(&work,"cgminer.c","stratum_sthread",0x1de8);
      free(__ptr);
      *(int *)((int)userdata + 0x7c) = *(int *)((int)userdata + 0x7c) + 1;
      bVar20 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar20;
    }
  } while( true );
}

