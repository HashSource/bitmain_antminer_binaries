
/* WARNING: Unknown calling convention */

_Bool add_pool_details(pool *pool,_Bool live,char *url,char *user,char *pass)

{
  undefined uVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  int *piVar5;
  int *piVar6;
  uint size;
  size_t siz;
  
  pcVar2 = get_proxy(url,pool);
  pool->rpc_user = user;
  pool->rpc_url = pcVar2;
  pool->rpc_pass = pass;
  sVar3 = strlen(user);
  sVar4 = strlen(pass);
  size = sVar3 + sVar4 + 2;
  pcVar2 = (char *)_cgmalloc(size,DAT_000299a0,DAT_000299a4,0x29b7);
  pool->rpc_userpass = pcVar2;
  snprintf(pcVar2,size,DAT_000299a8,pool->rpc_user,pool->rpc_pass);
  piVar5 = (int *)pool->enabled;
  pool->testing = true;
  pool->idle = true;
  pool->blocking = !live;
  piVar6 = piVar5;
  if (piVar5 != (int *)0x1) {
    piVar6 = DAT_000299ac;
  }
  if (piVar5 != (int *)0x1) {
    pool->enabled = POOL_ENABLED;
    *piVar6 = *piVar6 + 1;
  }
  pthread_create(&pool->test_thread,(pthread_attr_t *)0x0,DAT_000299b0,pool);
  uVar1 = 1;
  if (!live) {
    pthread_join(pool->test_thread,(void **)0x0);
    uVar1 = *(undefined *)(DAT_000299b4 + 0x74c);
  }
  return (_Bool)uVar1;
}

