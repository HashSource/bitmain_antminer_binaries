
void get_work_by_nonce2(thr_info *thr,work **work,pool *pool,pool *real_pool,uint64_t nonce2,
                       uint32_t version)

{
  work *pwVar1;
  int iVar2;
  pool *real_pool_local;
  pool *pool_local;
  work **work_local;
  thr_info *thr_local;
  int thr_id;
  
  pwVar1 = make_work();
  *work = pwVar1;
  iVar2 = thr->id;
  _cg_wlock(&pool->data_lock,"cgminer.c","get_work_by_nonce2",0x2063);
  pool->nonce2 = nonce2;
  version = version >> 0x18 | version >> 8 & 0xff00 | (version & 0xff00) << 8 | version << 0x18;
  _cg_memcpy(pool->header_bin,&version,4,"cgminer.c","get_work_by_nonce2",0x2066);
  _cg_wunlock(&pool->data_lock,"cgminer.c","get_work_by_nonce2",0x2067);
  gen_stratum_work(pool,*work);
  (*work)->pool = real_pool;
  (*work)->thr_id = iVar2;
  (*work)->work_block = work_block;
  (*work)->pool->works = (*work)->pool->works + 1;
  (*work)->mined = true;
  (*work)->version = version;
  return;
}

