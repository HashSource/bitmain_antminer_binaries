
/* WARNING: Unknown calling convention */

void get_work_by_nonce2(thr_info *thr,work **work,pool *pool,pool *real_pool,uint64_t nonce2,
                       uint ntime,uint version)

{
  pthread_rwlock_t *lock;
  work *pwVar1;
  int iVar2;
  pool *func;
  char *func_00;
  pool *line;
  char *line_00;
  pthread_rwlock_t *__rwlock;
  int thr_id;
  int iVar3;
  
  func = pool;
  line = real_pool;
  pwVar1 = make_work();
  *work = pwVar1;
  iVar3 = thr->id;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_000226b8,(char *)0x200f,(char *)func,(int)line);
  }
  __rwlock = &(pool->data_lock).rwlock;
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    _wr_lock(DAT_000226b8,(char *)0x200f,(char *)func,(int)line);
  }
  lock = DAT_000226b8;
  pool->nonce2 = nonce2;
  version = version << 0x18 | (version >> 8 & 0xff) << 0x10 | (version >> 0x10 & 0xff) << 8 |
            version >> 0x18;
  func_00 = (char *)0x4;
  line_00 = DAT_000226ac;
  _cg_memcpy(pool->header_bin,&version,4,DAT_000226ac,lock->__size,0x2013);
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    _rw_unlock(lock,(char *)0x2014,func_00,(int)line_00);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_000226b8,(char *)0x2014,func_00,(int)line_00);
  }
  (**DAT_000226b0)();
  gen_stratum_work(pool,*work);
  iVar2 = DAT_000226b4;
  (*work)->pool = real_pool;
  pwVar1 = *work;
  pwVar1->work_block = *(uint *)(iVar2 + 0x4f4);
  pwVar1->thr_id = iVar3;
  pwVar1->pool->works = pwVar1->pool->works + 1;
  pwVar1->mined = true;
  pwVar1->version = version;
  return;
}

