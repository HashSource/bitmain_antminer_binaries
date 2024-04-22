
void zero_bestshare(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar4;
  int *piVar5;
  int *piVar3;
  
  puVar1 = DAT_0001d4ec;
  best_share._0_4_ = 0;
  best_share._4_4_ = 0;
  *DAT_0001d4ec = 0;
  puVar1[1] = 0;
  suffix_string(0,0,&best_share,8,0);
  if (0 < total_pools) {
    piVar5 = pools + total_pools;
    piVar2 = pools;
    do {
      piVar3 = piVar2 + 1;
      iVar4 = *piVar2;
      *(undefined4 *)(iVar4 + 0x170) = 0;
      *(undefined4 *)(iVar4 + 0x174) = 0;
      piVar2 = piVar3;
    } while (piVar3 != piVar5);
  }
  return;
}

