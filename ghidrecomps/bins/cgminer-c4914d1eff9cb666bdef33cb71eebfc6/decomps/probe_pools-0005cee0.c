
/* WARNING: Unknown calling convention */

void probe_pools(void)

{
  pool *__arg;
  pool *pool;
  int i;
  
  for (i = 0; i < total_pools; i = i + 1) {
    __arg = pools[i];
    __arg->testing = true;
    pthread_create(&__arg->test_thread,(pthread_attr_t *)0x0,test_pool_thread + 1,__arg);
  }
  return;
}

