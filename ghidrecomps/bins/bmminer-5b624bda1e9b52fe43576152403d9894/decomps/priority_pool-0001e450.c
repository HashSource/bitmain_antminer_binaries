
/* WARNING: Unknown calling convention */

pool * priority_pool(int choice)

{
  pool *ppVar1;
  pool *pool;
  pool **pppVar2;
  int iVar3;
  
  if (0 < *DAT_0001e488) {
    pppVar2 = (pool **)*DAT_0001e48c;
    ppVar1 = *pppVar2;
    if (ppVar1->prio != choice) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == *DAT_0001e488) goto LAB_0001e47a;
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

