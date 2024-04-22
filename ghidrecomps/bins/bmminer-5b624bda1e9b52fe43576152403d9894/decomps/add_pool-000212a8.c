
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  char **ppcVar1;
  void **ppvVar2;
  pool *ppVar3;
  pool *pool;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  char tmp42 [2048];
  
  ppcVar1 = DAT_000213fc;
  ppVar3 = (pool *)_cgcalloc(0x738,1,DAT_00021400,DAT_00021404->__size,0x2d7);
  ppvVar2 = DAT_00021408;
  pcVar6 = *ppcVar1;
  ppVar3->support_vil = false;
  ppVar3->prio = (int)pcVar6;
  pvVar4 = *ppvVar2;
  ppVar3->pool_no = (int)pcVar6;
  pvVar4 = _cgrealloc(pvVar4,(int)(pcVar6 + 2) * 4,DAT_00021400,DAT_00021404->__size,0x2e3);
  pcVar6 = *ppcVar1;
  *ppvVar2 = pvVar4;
  *(pool **)((int)pvVar4 + (int)pcVar6 * 4) = ppVar3;
  *ppcVar1 = pcVar6 + 1;
  iVar5 = pthread_mutex_init((pthread_mutex_t *)&ppVar3->pool_lock,(pthread_mutexattr_t *)0x0);
  if (iVar5 != 0) {
    _mutex_init((pthread_mutex_t *)DAT_00021404,(char *)0x2e6,pcVar6,(int)pvVar4);
  }
  iVar5 = pthread_cond_init((pthread_cond_t *)&ppVar3->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar5 != 0) {
    tmp42._0_4_ = *DAT_00021410;
    tmp42._4_4_ = DAT_00021410[1];
    tmp42._8_4_ = DAT_00021410[2];
    tmp42._12_4_ = DAT_00021410[3];
    tmp42._16_4_ = DAT_00021410[4];
    tmp42._20_4_ = DAT_00021410[5];
    tmp42._24_4_ = DAT_00021410[6];
    pvVar4 = (void *)DAT_00021410[7];
    pcVar6 = (char *)0x1;
    tmp42._32_4_ = DAT_00021410[8];
    tmp42._36_4_ = DAT_00021410[9];
    tmp42._28_4_ = pvVar4;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar5 = pthread_mutex_init((pthread_mutex_t *)&ppVar3->data_lock,(pthread_mutexattr_t *)0x0);
  if (iVar5 != 0) {
    _mutex_init((pthread_mutex_t *)DAT_00021404,(char *)0x2ed,pcVar6,(int)pvVar4);
  }
  iVar5 = pthread_rwlock_init((pthread_rwlock_t *)&(ppVar3->data_lock).rwlock,
                              (pthread_rwlockattr_t *)0x0);
  if (iVar5 != 0) {
    _rwlock_init(DAT_00021404,(char *)0x2ed,pcVar6,(int)pvVar4);
  }
  iVar5 = pthread_mutex_init((pthread_mutex_t *)&ppVar3->stratum_lock,(pthread_mutexattr_t *)0x0);
  if (iVar5 != 0) {
    _mutex_init((pthread_mutex_t *)DAT_00021404,(char *)0x2ee,pcVar6,(int)pvVar4);
  }
  iVar5 = pthread_mutex_init((pthread_mutex_t *)&ppVar3->gbt_lock,(pthread_mutexattr_t *)0x0);
  if (iVar5 != 0) {
    _mutex_init((pthread_mutex_t *)DAT_00021404,(char *)0x2ef,pcVar6,(int)pvVar4);
  }
  iVar5 = pthread_rwlock_init((pthread_rwlock_t *)&(ppVar3->gbt_lock).rwlock,
                              (pthread_rwlockattr_t *)0x0);
  if (iVar5 != 0) {
    _rwlock_init(DAT_00021404,(char *)0x2ef,pcVar6,(int)pvVar4);
  }
  pcVar6 = DAT_0002140c;
  (ppVar3->curlring).next = &ppVar3->curlring;
  ppVar3->rpc_req = pcVar6;
  (ppVar3->curlring).prev = &ppVar3->curlring;
  (ppVar3->tv_idle).tv_sec = -1;
  ppVar3->rpc_proxy = (char *)0x0;
  ppVar3->quota = 1;
  adjust_quota_gcd();
  ppVar3->extranonce_subscribe = false;
  return ppVar3;
}

