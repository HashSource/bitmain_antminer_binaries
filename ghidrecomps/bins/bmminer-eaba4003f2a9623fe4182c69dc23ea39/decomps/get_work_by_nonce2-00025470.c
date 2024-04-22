
void get_work_by_nonce2(thr_info *thr,work **work,pool *pool,pool *real_pool,uint64_t nonce2,
                       uint ntime,uint version)

{
  work *pwVar1;
  int iVar2;
  pool *real_pool_local;
  pool *pool_local;
  work **work_local;
  thr_info *thr_local;
  device_drv *drv;
  cgpu_info *cgpu;
  int thr_id;
  
  pwVar1 = make_work();
  *work = pwVar1;
  iVar2 = thr->id;
  _cg_wlock(&pool->data_lock,"cgminer.c","get_work_by_nonce2",0x2016);
  pool->nonce2 = nonce2;
  version = version << 0x18 | version >> 0x18 | (version & 0xff0000) >> 8 | (version & 0xff00) << 8;
  _cg_memcpy(pool->header_bin,&version,4,"cgminer.c","get_work_by_nonce2",0x201a);
  _cg_wunlock(&pool->data_lock,"cgminer.c","get_work_by_nonce2",0x201b);
  gen_stratum_work(pool,*work);
  (*work)->pool = real_pool;
  (*work)->thr_id = iVar2;
  (*work)->work_block = work_block;
  (*work)->pool->works = (*work)->pool->works + 1;
  (*work)->mined = true;
  (*work)->version = version;
  return;
}

