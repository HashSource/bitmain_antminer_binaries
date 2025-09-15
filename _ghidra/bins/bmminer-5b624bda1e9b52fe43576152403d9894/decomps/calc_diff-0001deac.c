
void calc_diff(work *work,double known)

{
  pool *ppVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  uint64_t val;
  
  ppVar1 = work->pool;
  if (known == 0.0) {
    dVar2 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 0x18),
                                 *(undefined4 *)(work->target + 0x1c));
    dVar3 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 0x10),
                                 *(undefined4 *)(work->target + 0x14));
    dVar4 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 8),
                                 *(undefined4 *)(work->target + 0xc));
    dVar5 = (double)__aeabi_ul2d(*(undefined4 *)work->target,*(undefined4 *)(work->target + 4));
    dVar5 = dVar2 * 6.277101735386681e+57 + dVar3 * 3.402823669209385e+38 +
            dVar4 * 1.8446744073709552e+19 + dVar5;
    if (dVar5 == 0.0) {
      dVar5 = 1.0;
    }
    known = 2.695953529101131e+67 / dVar5;
  }
  work->work_difficulty = known;
  (ppVar1->cgminer_pool_stats).last_diff = known;
  dVar2 = round(known);
  val = __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  suffix_string(val,ppVar1->diff,8,0);
  dVar2 = (ppVar1->cgminer_pool_stats).min_diff;
  if (dVar2 == known) {
    (ppVar1->cgminer_pool_stats).min_diff_count = (ppVar1->cgminer_pool_stats).min_diff_count + 1;
LAB_0001df6c:
    dVar2 = (ppVar1->cgminer_pool_stats).max_diff;
  }
  else {
    if (dVar2 <= known) {
      if (dVar2 != 0.0) goto LAB_0001df6c;
      (ppVar1->cgminer_pool_stats).min_diff = known;
      (ppVar1->cgminer_pool_stats).min_diff_count = 1;
    }
    else {
      (ppVar1->cgminer_pool_stats).min_diff = known;
      (ppVar1->cgminer_pool_stats).min_diff_count = 1;
    }
    dVar2 = (ppVar1->cgminer_pool_stats).max_diff;
  }
  if (dVar2 == known) {
    (ppVar1->cgminer_pool_stats).max_diff_count = (ppVar1->cgminer_pool_stats).max_diff_count + 1;
  }
  else if ((int)((uint)(dVar2 < known) << 0x1f) < 0) {
    (ppVar1->cgminer_pool_stats).max_diff = known;
    (ppVar1->cgminer_pool_stats).max_diff_count = 1;
  }
  return;
}

