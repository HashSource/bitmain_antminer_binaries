
/* WARNING: Unknown calling convention */

void remove_pool(pool *pool)

{
  pool *ppVar1;
  int iVar2;
  pool **pppVar3;
  pool **pppVar5;
  int last_pool;
  int iVar6;
  pool **pppVar4;
  
  iVar6 = total_pools + -1;
  if (0 < total_pools) {
    pppVar5 = pools + total_pools;
    pppVar3 = pools;
    do {
      pppVar4 = pppVar3 + 1;
      iVar2 = (*pppVar3)->prio;
      if (pool->prio < iVar2) {
        (*pppVar3)->prio = iVar2 + -1;
      }
      pppVar3 = pppVar4;
    } while (pppVar4 != pppVar5);
  }
  pppVar3 = pools;
  if (pool->pool_no < iVar6) {
    ppVar1 = pools[iVar6];
    ppVar1->pool_no = pool->pool_no;
    pppVar3[pool->pool_no] = ppVar1;
  }
  pool->pool_no = total_pools;
  pool->removed = true;
  total_pools = iVar6;
  return;
}

