
/* WARNING: Unknown calling convention */

pool * priority_pool(int choice)

{
  pool *ppVar1;
  pool **pppVar2;
  int iVar3;
  
  if (0 < total_pools) {
    ppVar1 = *pools;
    if (ppVar1->prio != choice) {
      iVar3 = 0;
      pppVar2 = pools;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == total_pools) goto LAB_0001e47a;
        pppVar2 = pppVar2 + 1;
        ppVar1 = *pppVar2;
      } while (ppVar1->prio != choice);
    }
    return ppVar1;
  }
LAB_0001e47a:
  ppVar1 = priority_pool(choice);
  return ppVar1;
}

