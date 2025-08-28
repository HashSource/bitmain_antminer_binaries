
void calc_diff(work *work,double known)

{
  uint64_t val;
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 uVar5;
  pool *ppVar6;
  double *pdVar7;
  undefined4 uVar8;
  double dVar9;
  double known_local;
  work *work_local;
  uint64_t uintdiff;
  double difficulty;
  cgminer_pool_stats *pool_stats;
  
  ppVar6 = work->pool;
  if (known == 0.0) {
    dVar9 = diff_from_target(work->target);
    work->work_difficulty = dVar9;
  }
  else {
    work->work_difficulty = known;
  }
  pdVar7 = &work->work_difficulty;
  uVar5 = *(undefined4 *)pdVar7;
  uVar8 = *(undefined4 *)((int)&work->work_difficulty + 4);
  dVar4 = *pdVar7;
  dVar3 = *pdVar7;
  dVar2 = *pdVar7;
  dVar1 = *pdVar7;
  dVar9 = *pdVar7;
  *(undefined4 *)&(ppVar6->cgminer_pool_stats).last_diff = uVar5;
  *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).last_diff + 4) = uVar8;
  dVar9 = round(dVar9);
  val = __fixunsdfdi(SUB84(dVar9,0),(int)((ulonglong)dVar9 >> 0x20));
  suffix_string(val,work->pool->diff,8,0);
  if (dVar1 == (ppVar6->cgminer_pool_stats).min_diff) {
    (ppVar6->cgminer_pool_stats).min_diff_count = (ppVar6->cgminer_pool_stats).min_diff_count + 1;
  }
  else if ((dVar2 < (ppVar6->cgminer_pool_stats).min_diff) ||
          ((ppVar6->cgminer_pool_stats).min_diff == 0.0)) {
    *(undefined4 *)&(ppVar6->cgminer_pool_stats).min_diff = uVar5;
    *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).min_diff + 4) = uVar8;
    (ppVar6->cgminer_pool_stats).min_diff_count = 1;
  }
  if (dVar3 == (ppVar6->cgminer_pool_stats).max_diff) {
    (ppVar6->cgminer_pool_stats).max_diff_count = (ppVar6->cgminer_pool_stats).max_diff_count + 1;
  }
  else if ((ppVar6->cgminer_pool_stats).max_diff < dVar4) {
    *(undefined4 *)&(ppVar6->cgminer_pool_stats).max_diff = uVar5;
    *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).max_diff + 4) = uVar8;
    (ppVar6->cgminer_pool_stats).max_diff_count = 1;
  }
  return;
}

