
void calc_diff(work *work,double known)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  pool *ppVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  double dVar9;
  UDItype val;
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
  pdVar1 = &work->work_difficulty;
  uVar7 = *(undefined4 *)pdVar1;
  uVar8 = *(undefined4 *)((int)&work->work_difficulty + 4);
  dVar5 = *pdVar1;
  dVar4 = *pdVar1;
  dVar3 = *pdVar1;
  dVar2 = *pdVar1;
  dVar9 = *pdVar1;
  *(undefined4 *)&(ppVar6->cgminer_pool_stats).last_diff = uVar7;
  *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).last_diff + 4) = uVar8;
  dVar9 = round(dVar9);
  val = __fixunsdfdi(dVar9);
  suffix_string(val,work->pool->diff,8,0);
  if (dVar2 == (ppVar6->cgminer_pool_stats).min_diff) {
    (ppVar6->cgminer_pool_stats).min_diff_count = (ppVar6->cgminer_pool_stats).min_diff_count + 1;
  }
  else if (((int)((uint)(dVar3 < (ppVar6->cgminer_pool_stats).min_diff) << 0x1f) < 0) ||
          ((ppVar6->cgminer_pool_stats).min_diff == 0.0)) {
    *(undefined4 *)&(ppVar6->cgminer_pool_stats).min_diff = uVar7;
    *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).min_diff + 4) = uVar8;
    (ppVar6->cgminer_pool_stats).min_diff_count = 1;
  }
  if (dVar4 == (ppVar6->cgminer_pool_stats).max_diff) {
    (ppVar6->cgminer_pool_stats).max_diff_count = (ppVar6->cgminer_pool_stats).max_diff_count + 1;
  }
  else if ((ppVar6->cgminer_pool_stats).max_diff < dVar5) {
    *(undefined4 *)&(ppVar6->cgminer_pool_stats).max_diff = uVar7;
    *(undefined4 *)((int)&(ppVar6->cgminer_pool_stats).max_diff + 4) = uVar8;
    (ppVar6->cgminer_pool_stats).max_diff_count = 1;
  }
  return;
}

