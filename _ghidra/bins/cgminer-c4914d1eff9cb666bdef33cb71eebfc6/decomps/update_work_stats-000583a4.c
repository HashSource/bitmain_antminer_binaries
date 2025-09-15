
void update_work_stats(thr_info *thr,work *work)

{
  double dVar1;
  time_t tVar2;
  cgpu_info *pcVar3;
  pool *ppVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  double dVar6;
  uint64_t uVar7;
  DItype DVar8;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  double test_diff;
  
  dVar1 = current_diff;
  uVar7 = share_diff(work);
  work->share_diff = uVar7;
  dVar6 = (double)__floatundidf((int)work->share_diff,*(undefined4 *)((int)&work->share_diff + 4));
  if (dVar1 <= dVar6) {
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
  uVar5 = __aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  total_diff1 = __fixdfdi((DFtype)CONCAT44(extraout_s1,uVar5));
  uVar5 = __aeabi_l2d((int)thr->cgpu->diff1,*(undefined4 *)((int)&thr->cgpu->diff1 + 4));
  pcVar3 = thr->cgpu;
  DVar8 = __fixdfdi((DFtype)CONCAT44(extraout_s1_00,uVar5));
  pcVar3->diff1 = DVar8;
  uVar5 = __aeabi_l2d((int)work->pool->diff1,*(undefined4 *)((int)&work->pool->diff1 + 4));
  ppVar4 = work->pool;
  DVar8 = __fixdfdi((DFtype)CONCAT44(extraout_s1_01,uVar5));
  ppVar4->diff1 = DVar8;
  pcVar3 = thr->cgpu;
  tVar2 = time((time_t *)0x0);
  pcVar3->last_device_valid_work = tVar2;
  _mutex_unlock(&stats_lock,"cgminer.c","update_work_stats",0x2264);
  return;
}

