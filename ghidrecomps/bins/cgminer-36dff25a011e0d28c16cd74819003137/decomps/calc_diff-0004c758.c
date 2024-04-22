
void calc_diff(work *work,double known)

{
  double dVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  pool *ppVar5;
  double *pdVar6;
  undefined4 uVar7;
  double in_d0;
  double dVar8;
  double dVar9;
  undefined8 uVar10;
  undefined4 in_stack_ffffffc8;
  uint in_stack_ffffffcc;
  double known_local;
  work *work_local;
  uint64_t uintdiff;
  double difficulty;
  cgminer_pool_stats *pool_stats;
  
  ppVar5 = work->pool;
  if (in_d0 == 0.0) {
    dVar9 = diff_from_target(work->target);
    work->work_difficulty = dVar9;
  }
  else {
    known_local._0_4_ = SUB84(in_d0,0);
    known_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
    *(undefined4 *)&work->work_difficulty = known_local._0_4_;
    *(undefined4 *)((int)&work->work_difficulty + 4) = known_local._4_4_;
  }
  pdVar6 = &work->work_difficulty;
  uVar4 = *(undefined4 *)pdVar6;
  uVar7 = *(undefined4 *)((int)&work->work_difficulty + 4);
  dVar3 = *pdVar6;
  dVar2 = *pdVar6;
  dVar1 = *pdVar6;
  dVar9 = *pdVar6;
  *(undefined4 *)&(ppVar5->cgminer_pool_stats).last_diff = uVar4;
  *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).last_diff + 4) = uVar7;
  dVar8 = round((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
  uVar10 = __fixunsdfdi(SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20));
  suffix_string((ulonglong)in_stack_ffffffcc << 0x20,(char *)uVar10,
                (size_t)((ulonglong)uVar10 >> 0x20),(int)work->pool->diff);
  if (dVar9 == (ppVar5->cgminer_pool_stats).min_diff) {
    (ppVar5->cgminer_pool_stats).min_diff_count = (ppVar5->cgminer_pool_stats).min_diff_count + 1;
  }
  else if ((dVar1 < (ppVar5->cgminer_pool_stats).min_diff) ||
          ((ppVar5->cgminer_pool_stats).min_diff == 0.0)) {
    *(undefined4 *)&(ppVar5->cgminer_pool_stats).min_diff = uVar4;
    *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).min_diff + 4) = uVar7;
    (ppVar5->cgminer_pool_stats).min_diff_count = 1;
  }
  if (dVar2 == (ppVar5->cgminer_pool_stats).max_diff) {
    (ppVar5->cgminer_pool_stats).max_diff_count = (ppVar5->cgminer_pool_stats).max_diff_count + 1;
  }
  else {
    dVar9 = (ppVar5->cgminer_pool_stats).max_diff;
    if (dVar3 != dVar9 && dVar3 < dVar9 == (NAN(dVar3) || NAN(dVar9))) {
      *(undefined4 *)&(ppVar5->cgminer_pool_stats).max_diff = uVar4;
      *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).max_diff + 4) = uVar7;
      (ppVar5->cgminer_pool_stats).max_diff_count = 1;
    }
  }
  return;
}

