
/* WARNING: Unknown calling convention */

void get_work_by_nonce2(thr_info *thr,work **work,pool *pool,pool *real_pool,uint64_t nonce2,
                       uint ntime,uint version)

{
  work *pwVar1;
  int iVar2;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  pthread_rwlock_t *__rwlock;
  int thr_id;
  int iVar3;
  
  pwVar1 = make_work();
  *work = pwVar1;
  iVar3 = thr->id;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"get_work_by_nonce2",(char *)0x200f,func,line);
  }
  __rwlock = &(pool->data_lock).rwlock;
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    _wr_lock((pthread_rwlock_t *)"get_work_by_nonce2",(char *)0x200f,func_00,line_00);
  }
  pool->nonce2 = nonce2;
  version = version << 0x18 | (version >> 8 & 0xff) << 0x10 | (version >> 0x10 & 0xff) << 8 |
            version >> 0x18;
  _cg_memcpy(pool->header_bin,&version,4,"cgminer.c","get_work_by_nonce2",0x2013);
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    _rw_unlock((pthread_rwlock_t *)"get_work_by_nonce2",(char *)0x2014,func_01,line_01);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"get_work_by_nonce2",(char *)0x2014,func_02,line_02);
  }
  (*selective_yield)();
  gen_stratum_work(pool,*work);
  (*work)->pool = real_pool;
  pwVar1 = *work;
  pwVar1->work_block = work_block;
  pwVar1->thr_id = iVar3;
  pwVar1->pool->works = pwVar1->pool->works + 1;
  pwVar1->mined = true;
  pwVar1->version = version;
  return;
}

