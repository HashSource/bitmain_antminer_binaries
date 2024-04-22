
void calc_diff(work *work,double known)

{
  double dVar1;
  pool *ppVar2;
  double in_d0;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 uVar8;
  undefined4 in_stack_ffffffd8;
  uint in_stack_ffffffdc;
  
  dVar3 = DAT_0001dfe0;
  ppVar2 = work->pool;
  if (in_d0 == 0.0) {
    dVar4 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 0x18),
                                 *(undefined4 *)(work->target + 0x1c));
    dVar5 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 0x10),
                                 *(undefined4 *)(work->target + 0x14));
    dVar1 = DAT_0001dff0;
    dVar5 = dVar5 * DAT_0001dfe8;
    dVar6 = (double)__aeabi_ul2d(*(undefined4 *)(work->target + 8),
                                 *(undefined4 *)(work->target + 0xc));
    dVar6 = dVar6 * DAT_0001dff8;
    dVar7 = (double)__aeabi_ul2d(*(undefined4 *)work->target,*(undefined4 *)(work->target + 4));
    dVar7 = dVar4 * dVar3 + dVar5 + dVar6 + dVar7;
    if (dVar7 == 0.0) {
      dVar7 = 1.0;
    }
    in_d0 = dVar1 / dVar7;
  }
  work->work_difficulty = in_d0;
  (ppVar2->cgminer_pool_stats).last_diff = in_d0;
  dVar3 = round((double)CONCAT44(in_stack_ffffffdc,in_stack_ffffffd8));
  uVar8 = __fixunsdfdi(SUB84(dVar3,0),(int)((ulonglong)dVar3 >> 0x20));
  suffix_string((ulonglong)in_stack_ffffffdc << 0x20,(char *)uVar8,
                (size_t)((ulonglong)uVar8 >> 0x20),(int)ppVar2->diff);
  dVar3 = (ppVar2->cgminer_pool_stats).min_diff;
  if (dVar3 == in_d0) {
    (ppVar2->cgminer_pool_stats).min_diff_count = (ppVar2->cgminer_pool_stats).min_diff_count + 1;
LAB_0001df6c:
    dVar3 = (ppVar2->cgminer_pool_stats).max_diff;
  }
  else {
    if (dVar3 == in_d0 || dVar3 < in_d0 != (NAN(dVar3) || NAN(in_d0))) {
      if (dVar3 != 0.0) goto LAB_0001df6c;
      (ppVar2->cgminer_pool_stats).min_diff = in_d0;
      (ppVar2->cgminer_pool_stats).min_diff_count = 1;
    }
    else {
      (ppVar2->cgminer_pool_stats).min_diff = in_d0;
      (ppVar2->cgminer_pool_stats).min_diff_count = 1;
    }
    dVar3 = (ppVar2->cgminer_pool_stats).max_diff;
  }
  if (dVar3 == in_d0) {
    (ppVar2->cgminer_pool_stats).max_diff_count = (ppVar2->cgminer_pool_stats).max_diff_count + 1;
  }
  else if ((int)((uint)(dVar3 < in_d0) << 0x1f) < 0) {
    (ppVar2->cgminer_pool_stats).max_diff = in_d0;
    (ppVar2->cgminer_pool_stats).max_diff_count = 1;
  }
  return;
}

