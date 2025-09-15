
pool * select_balanced(pool *cp)

{
  _Bool _Var1;
  pool *pool_00;
  pool *cp_local;
  pool *pool;
  pool *ret;
  int lowest;
  int i;
  
  lowest = cp->shares;
  ret = cp;
  for (i = 0; i < total_pools; i = i + 1) {
    pool_00 = pools[i];
    _Var1 = pool_unusable(pool_00);
    if ((!_Var1) && (pool_00->shares < lowest)) {
      lowest = pool_00->shares;
      ret = pool_00;
    }
  }
  ret->shares = ret->shares + 1;
  return ret;
}

