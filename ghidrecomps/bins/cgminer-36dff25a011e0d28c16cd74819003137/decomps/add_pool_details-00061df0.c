
_Bool add_pool_details(pool *pool,_Bool live,char *url,char *user,char *pass)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  undefined uVar4;
  uint32_t size;
  char *user_local;
  char *url_local;
  _Bool live_local;
  pool *pool_local;
  size_t siz;
  
  pcVar1 = get_proxy(url,pool);
  pool->rpc_url = pcVar1;
  pool->rpc_user = user;
  pool->rpc_pass = pass;
  sVar2 = strlen(pool->rpc_user);
  sVar3 = strlen(pool->rpc_pass);
  size = sVar2 + sVar3 + 2;
  pcVar1 = (char *)_cgmalloc(size,"cgminer.c","add_pool_details",0x2a0c);
  pool->rpc_userpass = pcVar1;
  snprintf(pool->rpc_userpass,size,"%s:%s",pool->rpc_user,pool->rpc_pass);
  pool->testing = true;
  pool->idle = true;
  pool->blocking = !live;
  enable_pool(pool);
  pthread_create(&pool->test_thread,(pthread_attr_t *)0x0,test_pool_thread,pool);
  if (live) {
    uVar4 = 1;
  }
  else {
    pthread_join(pool->test_thread,(void **)0x0);
    uVar4 = pools_active;
  }
  return (_Bool)uVar4;
}

