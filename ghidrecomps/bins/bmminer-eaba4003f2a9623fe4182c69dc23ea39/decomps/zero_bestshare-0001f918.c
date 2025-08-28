
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zero_bestshare(void)

{
  pool *ppVar1;
  pool *pool;
  int i;
  
  best_diff._0_4_ = 0;
  best_diff._4_4_ = 0;
  memset(best_share,0,8);
  suffix_string(CONCAT44(best_diff._4_4_,(undefined4)best_diff),best_share,8,0);
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar1 = pools[i];
    *(undefined4 *)&ppVar1->best_diff = 0;
    *(undefined4 *)((int)&ppVar1->best_diff + 4) = 0;
  }
  return;
}

