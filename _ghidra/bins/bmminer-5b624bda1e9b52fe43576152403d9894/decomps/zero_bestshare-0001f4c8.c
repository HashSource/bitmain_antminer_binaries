
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zero_bestshare(void)

{
  pool **pppVar1;
  pool *ppVar2;
  pool **pppVar3;
  pool **pppVar4;
  
  best_share[0] = '\0';
  best_share[1] = '\0';
  best_share[2] = '\0';
  best_share[3] = '\0';
  best_share[4] = '\0';
  best_share[5] = '\0';
  best_share[6] = '\0';
  best_share[7] = '\0';
  best_diff._0_4_ = 0;
  best_diff._4_4_ = 0;
  suffix_string(0,best_share,8,0);
  if (0 < total_pools) {
    pppVar1 = pools + total_pools;
    pppVar3 = pools;
    do {
      pppVar4 = pppVar3 + 1;
      ppVar2 = *pppVar3;
      *(undefined4 *)&ppVar2->best_diff = 0;
      *(undefined4 *)((int)&ppVar2->best_diff + 4) = 0;
      pppVar3 = pppVar4;
    } while (pppVar4 != pppVar1);
  }
  return;
}

