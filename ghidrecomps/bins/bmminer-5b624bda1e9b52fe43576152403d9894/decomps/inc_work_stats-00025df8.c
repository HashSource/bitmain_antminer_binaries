
/* WARNING: Unknown calling convention */

void inc_work_stats(thr_info *thr,pool *pool,int diff1)

{
  int iVar1;
  time_t tVar2;
  pool *ppVar3;
  char *func;
  uint uVar4;
  char *func_00;
  int line;
  int line_00;
  int iVar5;
  cgpu_info *pcVar6;
  bool bVar7;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"inc_work_stats",(char *)0x2212,func,line);
  }
  pcVar6 = thr->cgpu;
  iVar5 = diff1 >> 0x1f;
  uVar4 = (uint)pcVar6->diff1;
  iVar1 = *(int *)((int)&pcVar6->diff1 + 4);
  bVar7 = CARRY4((uint)total_diff1,diff1);
  total_diff1._0_4_ = (uint)total_diff1 + diff1;
  total_diff1._4_4_ = total_diff1._4_4_ + iVar5 + (uint)bVar7;
  *(uint *)&pcVar6->diff1 = uVar4 + diff1;
  *(uint *)((int)&pcVar6->diff1 + 4) = iVar1 + iVar5 + (uint)CARRY4(uVar4,diff1);
  if (pool == (pool *)0x0) {
    ppVar3 = current_pool();
    uVar4 = (uint)ppVar3->diff1;
    iVar1 = *(int *)((int)&ppVar3->diff1 + 4);
    pcVar6 = thr->cgpu;
    *(uint *)&ppVar3->diff1 = diff1 + uVar4;
    *(uint *)((int)&ppVar3->diff1 + 4) = iVar5 + iVar1 + (uint)CARRY4(diff1,uVar4);
  }
  else {
    uVar4 = (uint)pool->diff1;
    iVar1 = *(int *)((int)&pool->diff1 + 4);
    *(uint *)&pool->diff1 = diff1 + uVar4;
    *(uint *)((int)&pool->diff1 + 4) = iVar5 + iVar1 + (uint)CARRY4(diff1,uVar4);
  }
  tVar2 = time((time_t *)0x0);
  pcVar6->last_device_valid_work = tVar2;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"inc_work_stats",(char *)0x2220,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

