
void enable_pool(pool *pool)

{
  pool *pool_local;
  
  if (pool->enabled != POOL_ENABLED) {
    enabled_pools = enabled_pools + 1;
    pool->enabled = POOL_ENABLED;
  }
  return;
}

