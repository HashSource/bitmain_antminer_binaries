
void remove_pool(pool *pool)

{
  int iVar1;
  pool *ppVar2;
  pool *pool_local;
  pool *other;
  int last_pool;
  int i;
  
  iVar1 = total_pools + -1;
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar2 = pools[i];
    if (pool->prio < ppVar2->prio) {
      ppVar2->prio = ppVar2->prio + -1;
    }
  }
  if (pool->pool_no < iVar1) {
    pools[iVar1]->pool_no = pool->pool_no;
    pools[pool->pool_no] = pools[iVar1];
  }
  pool->pool_no = total_pools;
  pool->removed = true;
  total_pools = total_pools + -1;
  return;
}

