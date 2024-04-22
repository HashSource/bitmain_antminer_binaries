
void inc_work_stats(thr_info *thr,pool *pool,int diff1)

{
  uint uVar1;
  pool *ppVar2;
  time_t tVar3;
  int iVar4;
  int iVar5;
  cgpu_info *pcVar6;
  bool bVar7;
  int diff1_local;
  pool *pool_local;
  thr_info *thr_local;
  
  _mutex_lock(&stats_lock,"cgminer.c","inc_work_stats",0x2219);
  iVar5 = diff1 >> 0x1f;
  bVar7 = CARRY4((uint)total_diff1,diff1);
  total_diff1._0_4_ = (uint)total_diff1 + diff1;
  total_diff1._4_4_ = total_diff1._4_4_ + iVar5 + (uint)bVar7;
  pcVar6 = thr->cgpu;
  uVar1 = *(uint *)&thr->cgpu->diff1;
  iVar4 = *(int *)((int)&thr->cgpu->diff1 + 4);
  *(uint *)&pcVar6->diff1 = diff1 + uVar1;
  *(uint *)((int)&pcVar6->diff1 + 4) = iVar5 + iVar4 + (uint)CARRY4(diff1,uVar1);
  if (pool == (pool *)0x0) {
    ppVar2 = current_pool();
    uVar1 = *(uint *)&ppVar2->diff1;
    iVar4 = *(int *)((int)&ppVar2->diff1 + 4);
    *(uint *)&ppVar2->diff1 = diff1 + uVar1;
    *(uint *)((int)&ppVar2->diff1 + 4) = iVar5 + iVar4 + (uint)CARRY4(diff1,uVar1);
  }
  else {
    uVar1 = *(uint *)&pool->diff1;
    iVar4 = *(int *)((int)&pool->diff1 + 4);
    *(uint *)&pool->diff1 = diff1 + uVar1;
    *(uint *)((int)&pool->diff1 + 4) = iVar5 + iVar4 + (uint)CARRY4(diff1,uVar1);
  }
  pcVar6 = thr->cgpu;
  tVar3 = time((time_t *)0x0);
  pcVar6->last_device_valid_work = tVar3;
  _mutex_unlock(&stats_lock,"cgminer.c","inc_work_stats",0x2227);
  return;
}

