
/* WARNING: Unknown calling convention */

void gen_stratum_work(pool *pool,work *work)

{
  uint64_t *puVar1;
  uchar **ppuVar2;
  int iVar3;
  char *pcVar4;
  time_t tVar5;
  char *__ptr;
  uint uVar6;
  char *func;
  char *func_00;
  uint uVar7;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  pthread_rwlock_t *__rwlock;
  undefined4 local_890;
  undefined4 uStack_88c;
  uchar merkle_root [32];
  uchar merkle_sha [64];
  uchar hash1 [32];
  
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)"gen_stratum_work",(char *)0x202e,func,line);
  }
  __rwlock = &(pool->data_lock).rwlock;
  iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _wr_lock((pthread_rwlock_t *)"gen_stratum_work",(char *)0x202e,func_00,line_00);
  }
  puVar1 = &pool->nonce2;
  local_890 = (undefined4)*puVar1;
  uStack_88c = *(undefined4 *)((int)&pool->nonce2 + 4);
  _cg_memcpy(pool->coinbase + pool->nonce2_offset,&local_890,pool->n2size,"cgminer.c",
             "gen_stratum_work",0x2033);
  uVar7 = (uint)*puVar1;
  iVar3 = *(int *)((int)&pool->nonce2 + 4);
  uVar6 = pool->n2size;
  *(uint *)&work->nonce2 = uVar7;
  *(int *)((int)&work->nonce2 + 4) = iVar3;
  *(uint *)puVar1 = uVar7 + 1;
  *(uint *)((int)&pool->nonce2 + 4) = iVar3 + (uint)(0xfffffffe < uVar7);
  work->nonce2_len = uVar6;
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rw_unlock((pthread_rwlock_t *)"gen_stratum_work",(char *)0x2039,func_01,line_01);
  }
  iVar3 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rd_lock((pthread_rwlock_t *)"gen_stratum_work",(char *)0x2039,func_02,line_02);
  }
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"gen_stratum_work",(char *)0x2039,func_03,line_03);
  }
  sha256(pool->coinbase,pool->coinbase_len,hash1);
  sha256(hash1,0x20,merkle_root);
  _cg_memcpy(merkle_sha,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x203d);
  if (0 < pool->merkles) {
    iVar3 = 0;
    do {
      ppuVar2 = (pool->swork).merkle_bin + iVar3;
      iVar3 = iVar3 + 1;
      _cg_memcpy(merkle_sha + 0x20,*ppuVar2,0x20,"cgminer.c","gen_stratum_work",0x2041);
      sha256(merkle_sha,0x40,hash1);
      sha256(hash1,0x20,merkle_root);
      _cg_memcpy(merkle_sha,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x2043);
    } while (iVar3 < pool->merkles);
  }
  iVar3 = 0;
  do {
    uVar6 = *(uint *)(merkle_sha + iVar3);
    *(uint *)(merkle_root + iVar3) =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    iVar3 = iVar3 + 4;
  } while (iVar3 != 0x20);
  _cg_memcpy(work,pool->header_bin,0x70,"cgminer.c","gen_stratum_work",0x204c);
  _cg_memcpy(work->data + 0x24,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x204d);
  pcVar4 = (pool->swork).job_id;
  work->sdiff = pool->sdiff;
  pcVar4 = (char *)__strdup(pcVar4);
  work->job_id = pcVar4;
  pcVar4 = (char *)__strdup(pool->nonce1);
  work->nonce1 = pcVar4;
  pcVar4 = (char *)__strdup(pool->ntime);
  work->ntime = pcVar4;
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rw_unlock((pthread_rwlock_t *)"gen_stratum_work",(char *)0x2058,func_04,line_04);
  }
  (*selective_yield)();
  if (opt_debug == false) goto LAB_000223f0;
  pcVar4 = bin2hex(work->data,0x70);
  __ptr = bin2hex(merkle_root,0x20);
  if (opt_debug != false) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
LAB_0002252c:
      if (opt_log_level < 7) {
LAB_00022532:
        if (6 < opt_log_level) {
LAB_000224f0:
          snprintf((char *)hash1,0x800,"Work job_id %s nonce2 %llu ntime %s",work->job_id,
                   (int)work->nonce2,*(undefined4 *)((int)&work->nonce2 + 4),work->ntime);
          _applog(7,(char *)hash1,false);
        }
      }
      else {
LAB_000224c8:
        snprintf((char *)hash1,0x800,"Generated stratum header %s",pcVar4);
        _applog(7,(char *)hash1,false);
        if (opt_debug != false) {
          if ((use_syslog == false) && (opt_log_output == false)) goto LAB_00022532;
          goto LAB_000224f0;
        }
      }
    }
    else {
      snprintf((char *)hash1,0x800,"Generated stratum merkle %s",__ptr);
      _applog(7,(char *)hash1,false);
      if (opt_debug != false) {
        if ((use_syslog == false) && (opt_log_output == false)) goto LAB_0002252c;
        goto LAB_000224c8;
      }
    }
  }
  free(pcVar4);
  free(__ptr);
LAB_000223f0:
  calc_midstate(work);
  set_target(work->target,work->sdiff);
  local_work = local_work + 1;
  tVar5 = time((time_t *)0x0);
  if (5 < tVar5 - local_work_lasttime) {
    local_work_lasttime = time((time_t *)0x0);
    local_work_last = local_work;
  }
  uVar6 = work_block;
  work->pool = pool;
  work->work_block = uVar6;
  work->stratum = true;
  work->nonce = 0;
  work->longpoll = false;
  work->getwork_mode = 'S';
  work->drv_rolllimit = 0x3c;
  calc_diff(work,work->sdiff);
  cgtime(&work->tv_staged);
  return;
}

