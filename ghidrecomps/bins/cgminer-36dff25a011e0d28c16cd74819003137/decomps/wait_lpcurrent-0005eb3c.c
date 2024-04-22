
void wait_lpcurrent(pool *pool)

{
  _Bool _Var1;
  pool *ppVar2;
  pool *pool_local;
  
  while ((_Var1 = cnx_needed(pool), !_Var1 &&
         ((pool->enabled == POOL_DISABLED ||
          (((ppVar2 = current_pool(), pool != ppVar2 && (pool_strategy != POOL_LOADBALANCE)) &&
           (pool_strategy != POOL_BALANCE))))))) {
    _mutex_lock(&lp_lock,"cgminer.c","wait_lpcurrent",0x267d);
    pthread_cond_wait((pthread_cond_t *)&lp_cond,(pthread_mutex_t *)&lp_lock);
    _mutex_unlock(&lp_lock,"cgminer.c","wait_lpcurrent",0x267f);
  }
  return;
}

