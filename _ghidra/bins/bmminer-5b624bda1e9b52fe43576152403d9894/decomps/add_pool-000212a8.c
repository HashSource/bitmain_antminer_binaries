
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  pool **ptr;
  pool *ppVar1;
  int iVar2;
  char *func;
  char *func_00;
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
  char tmp42 [2048];
  
  ppVar1 = (pool *)_cgcalloc(0x738,1,"cgminer.c","add_pool",0x2d7);
  iVar2 = total_pools;
  ppVar1->support_vil = false;
  ppVar1->prio = iVar2;
  ptr = pools;
  ppVar1->pool_no = iVar2;
  pools = (pool **)_cgrealloc(ptr,(iVar2 + 2) * 4,"cgminer.c","add_pool",0x2e3);
  pools[total_pools] = ppVar1;
  total_pools = total_pools + 1;
  iVar2 = pthread_mutex_init((pthread_mutex_t *)&ppVar1->pool_lock,(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init((pthread_mutex_t *)"add_pool",(char *)0x2e6,func,line);
  }
  iVar2 = pthread_cond_init((pthread_cond_t *)&ppVar1->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"Failed to pthread_cond_init in add_pool",0x28);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar2 = pthread_mutex_init((pthread_mutex_t *)&ppVar1->data_lock,(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init((pthread_mutex_t *)"add_pool",(char *)0x2ed,func_00,line_00);
  }
  iVar2 = pthread_rwlock_init((pthread_rwlock_t *)&(ppVar1->data_lock).rwlock,
                              (pthread_rwlockattr_t *)0x0);
  if (iVar2 != 0) {
    _rwlock_init((pthread_rwlock_t *)"add_pool",(char *)0x2ed,func_01,line_01);
  }
  iVar2 = pthread_mutex_init((pthread_mutex_t *)&ppVar1->stratum_lock,(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init((pthread_mutex_t *)"add_pool",(char *)0x2ee,func_02,line_02);
  }
  iVar2 = pthread_mutex_init((pthread_mutex_t *)&ppVar1->gbt_lock,(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init((pthread_mutex_t *)"add_pool",(char *)0x2ef,func_03,line_03);
  }
  iVar2 = pthread_rwlock_init((pthread_rwlock_t *)&(ppVar1->gbt_lock).rwlock,
                              (pthread_rwlockattr_t *)0x0);
  if (iVar2 != 0) {
    _rwlock_init((pthread_rwlock_t *)"add_pool",(char *)0x2ef,func_04,line_04);
  }
  (ppVar1->curlring).next = &ppVar1->curlring;
  ppVar1->rpc_req = "{\"method\": \"getwork\", \"params\": [], \"id\":0}\n";
  (ppVar1->curlring).prev = &ppVar1->curlring;
  (ppVar1->tv_idle).tv_sec = -1;
  ppVar1->rpc_proxy = (char *)0x0;
  ppVar1->quota = 1;
  adjust_quota_gcd();
  ppVar1->extranonce_subscribe = false;
  return ppVar1;
}

