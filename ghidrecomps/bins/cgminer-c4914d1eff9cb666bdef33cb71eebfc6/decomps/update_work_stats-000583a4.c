
/* WARNING: Variable defined which should be unmapped: work-local */

void update_work_stats(thr_info *thr,work *work)

{
  undefined4 uVar1;
  undefined4 uVar2;
  time_t tVar3;
  cgpu_info *pcVar4;
  pool *ppVar5;
  double dVar6;
  uint64_t uVar7;
  DItype DVar8;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  double test_diff;
  
  uVar2 = current_diff._4_4_;
  uVar1 = current_diff._0_4_;
  uVar7 = share_diff(work);
  work->share_diff = uVar7;
  dVar6 = (double)__floatundidf(*(undefined4 *)&work->share_diff,
                                *(undefined4 *)((int)&work->share_diff + 4));
  if ((double)CONCAT44(uVar2,uVar1) <= dVar6) {
    work->block = true;
    work->pool->solved = work->pool->solved + 1;
    found_blocks = found_blocks + 1;
    work->mandatory = true;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Found block for pool %d!",work->pool->pool_no);
      _applog(5,tmp42,false);
    }
  }
  _mutex_lock(&stats_lock,"cgminer.c","update_work_stats",0x225f);
  __aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  total_diff1 = __fixdfdi((DFtype)CONCAT44(thr,work));
  __aeabi_l2d(*(undefined4 *)&thr->cgpu->diff1,*(undefined4 *)((int)&thr->cgpu->diff1 + 4));
  pcVar4 = thr->cgpu;
  DVar8 = __fixdfdi((DFtype)CONCAT44(thr,work));
  pcVar4->diff1 = DVar8;
  __aeabi_l2d(*(undefined4 *)&work->pool->diff1,*(undefined4 *)((int)&work->pool->diff1 + 4));
  ppVar5 = work->pool;
  DVar8 = __fixdfdi((DFtype)CONCAT44(thr,work));
  ppVar5->diff1 = DVar8;
  pcVar4 = thr->cgpu;
  tVar3 = time((time_t *)0x0);
  pcVar4->last_device_valid_work = tVar3;
  _mutex_unlock(&stats_lock,"cgminer.c","update_work_stats",0x2264);
  return;
}

