
/* WARNING: Unknown calling convention */

void remove_pool(pool *pool)

{
  int *piVar1;
  pool *other;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int last_pool;
  int iVar7;
  
  piVar1 = DAT_0001f0b8;
  iVar6 = *DAT_0001f0b8;
  iVar7 = iVar6 + -1;
  if (0 < iVar6) {
    piVar4 = *DAT_0001f0b4;
    piVar2 = piVar4;
    do {
      piVar5 = piVar2 + 1;
      iVar3 = *(int *)(*piVar2 + 4);
      if (pool->prio < iVar3) {
        *(int *)(*piVar2 + 4) = iVar3 + -1;
      }
      piVar2 = piVar5;
    } while (piVar5 != piVar4 + iVar6);
  }
  if (pool->pool_no < iVar7) {
    piVar4 = *DAT_0001f0b4;
    piVar2 = (int *)piVar4[iVar7];
    *piVar2 = pool->pool_no;
    piVar4[pool->pool_no] = (int)piVar2;
  }
  pool->pool_no = iVar6;
  pool->removed = true;
  *piVar1 = iVar7;
  return;
}

