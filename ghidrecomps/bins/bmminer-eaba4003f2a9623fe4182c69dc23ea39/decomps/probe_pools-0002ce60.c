
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void probe_pools(void)

{
  pool *__arg;
  pool *pool;
  int i;
  
  for (i = 0; i < total_pools; i = i + 1) {
    __arg = pools[i];
    __arg->testing = true;
    pthread_create(&__arg->test_thread,(pthread_attr_t *)0x0,(__start_routine *)0x2b655,__arg);
  }
  return;
}

