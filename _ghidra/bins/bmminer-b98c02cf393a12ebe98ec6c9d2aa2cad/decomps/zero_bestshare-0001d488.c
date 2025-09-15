
void zero_bestshare(void)

{
  int *piVar1;
  int iVar3;
  int *piVar4;
  int *piVar2;
  
  best_share._0_4_ = 0;
  best_share._4_4_ = 0;
  best_diff._0_4_ = 0;
  best_diff._4_4_ = 0;
  suffix_string(0,0,&best_share,8,0);
  if (0 < total_pools) {
    piVar4 = pools + total_pools;
    piVar1 = pools;
    do {
      piVar2 = piVar1 + 1;
      iVar3 = *piVar1;
      *(undefined4 *)(iVar3 + 0x170) = 0;
      *(undefined4 *)(iVar3 + 0x174) = 0;
      piVar1 = piVar2;
    } while (piVar2 != piVar4);
  }
  return;
}

