
/* WARNING: Unknown calling convention */

void gen_stratum_work(pool *pool,work *work)

{
  uint64_t *puVar1;
  uchar **ppuVar2;
  int iVar3;
  char *pcVar4;
  time_t tVar5;
  char *__ptr;
  char *header;
  char *__ptr_00;
  char *merkle_hash;
  uint uVar6;
  char *in_r2;
  char *pcVar7;
  int in_r3;
  int iVar8;
  double *line;
  int *piVar9;
  pthread_rwlock_t *__rwlock;
  pthread_rwlock_t *lock;
  undefined4 uVar10;
  uint64_t nonce2le;
  uchar merkle_root [32];
  uchar merkle_sha [64];
  uchar hash1 [32];
  
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_000225bc,(char *)0x202e,in_r2,in_r3);
  }
  __rwlock = &(pool->data_lock).rwlock;
  iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _wr_lock(DAT_000225bc,(char *)0x202e,in_r2,in_r3);
  }
  lock = DAT_0002253c;
  puVar1 = &pool->nonce2;
  nonce2le._0_4_ = *(undefined4 *)puVar1;
  nonce2le._4_4_ = *(undefined4 *)((int)&pool->nonce2 + 4);
  _cg_memcpy(pool->coinbase + pool->nonce2_offset,&nonce2le,pool->n2size,DAT_00022540,
             DAT_0002253c->__size,0x2033);
  pcVar7 = *(char **)puVar1;
  iVar8 = *(int *)((int)&pool->nonce2 + 4);
  uVar6 = pool->n2size;
  *(char **)&work->nonce2 = pcVar7;
  *(int *)((int)&work->nonce2 + 4) = iVar8;
  *(char **)puVar1 = pcVar7 + 1;
  *(uint *)((int)&pool->nonce2 + 4) = iVar8 + (uint)((char *)0xfffffffe < pcVar7);
  work->nonce2_len = uVar6;
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rw_unlock(lock,(char *)0x2039,pcVar7,iVar8);
  }
  iVar3 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rd_lock(DAT_000225bc,(char *)0x2039,pcVar7,iVar8);
  }
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_000225bc,(char *)0x2039,pcVar7,iVar8);
  }
  sha256(pool->coinbase,pool->coinbase_len,hash1);
  sha256(hash1,0x20,merkle_root);
  _cg_memcpy(merkle_sha,merkle_root,0x20,DAT_00022540,lock->__size,0x203d);
  if (0 < pool->merkles) {
    iVar3 = 0;
    do {
      ppuVar2 = (pool->swork).merkle_bin + iVar3;
      iVar3 = iVar3 + 1;
      _cg_memcpy(merkle_sha + 0x20,*ppuVar2,0x20,DAT_00022540,lock->__size,0x2041);
      sha256(merkle_sha,0x40,hash1);
      sha256(hash1,0x20,merkle_root);
      _cg_memcpy(merkle_sha,merkle_root,0x20,DAT_00022540,lock->__size,0x2043);
    } while (iVar3 < pool->merkles);
  }
  pcVar7 = (char *)0x0;
  do {
    uVar6 = *(uint *)(merkle_sha + (int)pcVar7);
    *(uint *)(merkle_root + (int)pcVar7) =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    pcVar7 = pcVar7 + 4;
  } while (pcVar7 != (char *)0x20);
  _cg_memcpy(work,pool->header_bin,0x70,DAT_00022540,lock->__size,0x204c);
  uVar10 = 0x204d;
  _cg_memcpy(work->data + 0x24,merkle_root,0x20,DAT_00022540,lock->__size,0x204d);
  line = &pool->sdiff;
  pcVar4 = (pool->swork).job_id;
  work->sdiff = *line;
  pcVar4 = (char *)__strdup(pcVar4);
  work->job_id = pcVar4;
  pcVar4 = (char *)__strdup(pool->nonce1);
  work->nonce1 = pcVar4;
  pcVar4 = (char *)__strdup(pool->ntime);
  work->ntime = pcVar4;
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar3 != 0) {
    _rw_unlock(DAT_000225bc,(char *)0x2058,pcVar7,(int)line);
  }
  pcVar7 = DAT_00022548;
  (**DAT_00022544)();
  if (*pcVar7 == '\0') goto LAB_000223f0;
  __ptr = bin2hex(work->data,0x70);
  __ptr_00 = bin2hex(merkle_root,0x20);
  pcVar4 = DAT_00022554;
  if (*pcVar7 != '\0') {
    if (((*DAT_00022554 == '\0') && (*DAT_00022558 == '\0')) && (*DAT_0002255c < 7)) {
LAB_0002252c:
      piVar9 = DAT_0002255c;
      if (*DAT_0002255c < 7) {
LAB_00022532:
        if (6 < *piVar9) {
LAB_000224f0:
          lock = *(pthread_rwlock_t **)&work->nonce2;
          uVar10 = *(undefined4 *)((int)&work->nonce2 + 4);
          snprintf((char *)hash1,0x800,DAT_00022568,work->job_id,lock,uVar10,work->ntime);
          _applog(7,(char *)hash1,false);
        }
      }
      else {
LAB_000224c8:
        snprintf((char *)hash1,0x800,DAT_00022564,__ptr);
        _applog(7,(char *)hash1,false);
        if (*pcVar7 != '\0') {
          if ((*pcVar4 == '\0') && (piVar9 = DAT_000225b8, *DAT_00022558 == '\0'))
          goto LAB_00022532;
          goto LAB_000224f0;
        }
      }
    }
    else {
      snprintf((char *)hash1,0x800,DAT_00022560,__ptr_00);
      _applog(7,(char *)hash1,false);
      if (*pcVar7 != '\0') {
        if ((*pcVar4 == '\0') && (*DAT_00022558 == '\0')) goto LAB_0002252c;
        goto LAB_000224c8;
      }
    }
  }
  free(__ptr);
  free(__ptr_00);
LAB_000223f0:
  piVar9 = DAT_0002254c;
  calc_midstate(work);
  set_target(work->target,(double)CONCAT44(uVar10,lock));
  iVar3 = DAT_00022550;
  *piVar9 = *piVar9 + 1;
  tVar5 = time((time_t *)0x0);
  if (5 < tVar5 - *(int *)(iVar3 + 0x4ec)) {
    tVar5 = time((time_t *)0x0);
    iVar8 = *piVar9;
    *(time_t *)(iVar3 + 0x4ec) = tVar5;
    *(int *)(iVar3 + 0x4f0) = iVar8;
  }
  uVar6 = *(uint *)(iVar3 + 0x4f4);
  work->pool = pool;
  work->work_block = uVar6;
  work->stratum = true;
  work->nonce = 0;
  work->longpoll = false;
  work->getwork_mode = 'S';
  work->drv_rolllimit = 0x3c;
  calc_diff(work,(double)CONCAT44(uVar10,lock));
  cgtime(&work->tv_staged);
  return;
}

