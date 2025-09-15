
/* WARNING: Unknown calling convention */

_Bool add_pool_details(pool *pool,_Bool live,char *url,char *user,char *pass)

{
  undefined1 uVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  int *piVar5;
  uint size;
  bool bVar6;
  
  pcVar2 = get_proxy(url,pool);
  pool->rpc_user = user;
  pool->rpc_url = pcVar2;
  pool->rpc_pass = pass;
  sVar3 = strlen(user);
  sVar4 = strlen(pass);
  size = sVar3 + sVar4 + 2;
  pcVar2 = (char *)_cgmalloc(size,"cgminer.c","add_pool_details",0x29b7);
  pool->rpc_userpass = pcVar2;
  snprintf(pcVar2,size,"%s:%s",pool->rpc_user,pool->rpc_pass);
  piVar5 = (int *)pool->enabled;
  pool->testing = true;
  pool->idle = true;
  bVar6 = piVar5 != (int *)0x1;
  pool->blocking = !live;
  if (bVar6) {
    piVar5 = &enabled_pools;
  }
  if (bVar6) {
    pool->enabled = POOL_ENABLED;
    *piVar5 = *piVar5 + 1;
  }
  pthread_create(&pool->test_thread,(pthread_attr_t *)0x0,(__start_routine *)0x25f51,pool);
  uVar1 = 1;
  if (!live) {
    pthread_join(pool->test_thread,(void **)0x0);
    uVar1 = pools_active;
  }
  return (_Bool)uVar1;
}

