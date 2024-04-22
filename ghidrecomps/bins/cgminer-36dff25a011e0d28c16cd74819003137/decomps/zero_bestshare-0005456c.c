
/* WARNING: Unknown calling convention */

void zero_bestshare(void)

{
  pool *ppVar1;
  uint in_stack_ffffffec;
  pool *pool;
  int i;
  
  best_diff._0_4_ = (char *)0x0;
  best_diff._4_4_ = 0;
  memset(best_share,0,8);
  suffix_string((ulonglong)in_stack_ffffffec << 0x20,(char *)best_diff,best_diff._4_4_,0xc3250);
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar1 = pools[i];
    *(undefined4 *)&ppVar1->best_diff = 0;
    *(undefined4 *)((int)&ppVar1->best_diff + 4) = 0;
  }
  return;
}

