
void calc_diff(work *work,double known)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  pool *ppVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double in_d0;
  double dVar8;
  UDItype UVar9;
  undefined4 in_stack_ffffffc0;
  uint in_stack_ffffffc4;
  double known_local;
  work *work_local;
  uint64_t uintdiff;
  double difficulty;
  cgminer_pool_stats *pool_stats;
  
  ppVar5 = work->pool;
  if (in_d0 == 0.0) {
    dVar8 = diff_from_target(work->target);
    work->work_difficulty = dVar8;
  }
  else {
    known_local._0_4_ = SUB84(in_d0,0);
    known_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
    *(undefined4 *)&work->work_difficulty = known_local._0_4_;
    *(undefined4 *)((int)&work->work_difficulty + 4) = known_local._4_4_;
  }
  pdVar1 = &work->work_difficulty;
  uVar6 = *(undefined4 *)pdVar1;
  uVar7 = *(undefined4 *)((int)&work->work_difficulty + 4);
  dVar4 = *pdVar1;
  dVar3 = *pdVar1;
  dVar2 = *pdVar1;
  dVar8 = *pdVar1;
  *(undefined4 *)&(ppVar5->cgminer_pool_stats).last_diff = uVar6;
  *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).last_diff + 4) = uVar7;
  round((double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  uintdiff._0_4_ = (char *)UVar9;
  uintdiff._4_4_ = (size_t)(UVar9 >> 0x20);
  suffix_string((ulonglong)in_stack_ffffffc4 << 0x20,(char *)uintdiff,uintdiff._4_4_,
                (int)work->pool->diff);
  if (dVar8 == (ppVar5->cgminer_pool_stats).min_diff) {
    (ppVar5->cgminer_pool_stats).min_diff_count = (ppVar5->cgminer_pool_stats).min_diff_count + 1;
  }
  else if (((int)((uint)(dVar2 < (ppVar5->cgminer_pool_stats).min_diff) << 0x1f) < 0) ||
          ((ppVar5->cgminer_pool_stats).min_diff == 0.0)) {
    *(undefined4 *)&(ppVar5->cgminer_pool_stats).min_diff = uVar6;
    *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).min_diff + 4) = uVar7;
    (ppVar5->cgminer_pool_stats).min_diff_count = 1;
  }
  if (dVar3 == (ppVar5->cgminer_pool_stats).max_diff) {
    (ppVar5->cgminer_pool_stats).max_diff_count = (ppVar5->cgminer_pool_stats).max_diff_count + 1;
  }
  else {
    dVar8 = (ppVar5->cgminer_pool_stats).max_diff;
    if (dVar4 != dVar8 && dVar4 < dVar8 == (NAN(dVar4) || NAN(dVar8))) {
      *(undefined4 *)&(ppVar5->cgminer_pool_stats).max_diff = uVar6;
      *(undefined4 *)((int)&(ppVar5->cgminer_pool_stats).max_diff + 4) = uVar7;
      (ppVar5->cgminer_pool_stats).max_diff_count = 1;
    }
  }
  return;
}

