
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  undefined4 uVar1;
  pool *ppVar2;
  int iVar3;
  char tmp42 [2048];
  pool *pool;
  
  ppVar2 = (pool *)_cgcalloc(0x740,1,"cgminer.c","add_pool",0x2de);
  uVar1 = tmp42._32_4_;
  ppVar2->support_vil = false;
  if (ppVar2 == (pool *)0x0) {
    builtin_strncpy(tmp42,"Failed to malloc pool in add_pool",0x22);
    tmp42._34_2_ = SUB42(uVar1,2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  ppVar2->prio = total_pools;
  ppVar2->pool_no = ppVar2->prio;
  pools = (pool **)_cgrealloc(pools,(total_pools + 2) * 4,"cgminer.c","add_pool",0x2ea);
  pools[total_pools] = ppVar2;
  total_pools = total_pools + 1;
  _mutex_init(&ppVar2->pool_lock,"cgminer.c","add_pool",0x2ed);
  iVar3 = pthread_cond_init((pthread_cond_t *)&ppVar2->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar3 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init in add_pool",0x28);
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cglock_init(&ppVar2->data_lock,"cgminer.c","add_pool",0x2f4);
  _mutex_init(&ppVar2->stratum_lock,"cgminer.c","add_pool",0x2f5);
  _cglock_init(&ppVar2->gbt_lock,"cgminer.c","add_pool",0x2f6);
  (ppVar2->curlring).next = &ppVar2->curlring;
  (ppVar2->curlring).prev = &ppVar2->curlring;
  (ppVar2->tv_idle).tv_sec = -1;
  ppVar2->rpc_req = getwork_req;
  ppVar2->rpc_proxy = (char *)0x0;
  ppVar2->quota = 1;
  adjust_quota_gcd();
  ppVar2->extranonce_subscribe = false;
  return ppVar2;
}

