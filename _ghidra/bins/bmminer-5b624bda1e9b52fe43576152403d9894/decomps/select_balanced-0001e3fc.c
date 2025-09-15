
/* WARNING: Unknown calling convention */

pool * select_balanced(pool *cp)

{
  _Bool _Var1;
  pool **pppVar2;
  pool *pool;
  pool **pppVar4;
  int iVar5;
  pool **pppVar3;
  
  iVar5 = cp->shares;
  if (0 < total_pools) {
    pppVar4 = pools + total_pools;
    pppVar2 = pools;
    do {
      pppVar3 = pppVar2 + 1;
      pool = *pppVar2;
      _Var1 = pool_unusable(pool);
      if ((!_Var1) && (pool->shares < iVar5)) {
        iVar5 = pool->shares;
        cp = pool;
      }
      pppVar2 = pppVar3;
    } while (pppVar3 != pppVar4);
    iVar5 = cp->shares;
  }
  cp->shares = iVar5 + 1;
  return cp;
}

