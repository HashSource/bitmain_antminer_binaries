
void __suspend_stratum(pool *pool)

{
  pool *pool_local;
  
  clear_sockbuf(pool);
  pool->stratum_notify = false;
  pool->stratum_active = pool->stratum_notify;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  return;
}

