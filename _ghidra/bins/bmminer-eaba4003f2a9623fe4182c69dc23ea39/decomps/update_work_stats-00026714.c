
void update_work_stats(thr_info *thr,work *work)

{
  time_t tVar1;
  cgpu_info *pcVar2;
  pool *ppVar3;
  double dVar4;
  double dVar5;
  uint64_t uVar6;
  int64_t iVar7;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  double test_diff;
  
  dVar5 = current_diff;
  uVar6 = share_diff(work);
  work->share_diff = uVar6;
  dVar4 = (double)__aeabi_ul2d((int)work->share_diff,*(undefined4 *)((int)&work->share_diff + 4));
  if (dVar5 <= dVar4) {
    work->block = true;
    work->pool->solved = work->pool->solved + 1;
    found_blocks = found_blocks + 1;
    work->mandatory = true;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Found block for pool %d!",work->pool->pool_no);
      _applog(5,tmp42,false);
    }
  }
  _mutex_lock(&stats_lock,"cgminer.c","update_work_stats",0x220f);
  dVar5 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar5 = dVar5 + work->device_diff;
  total_diff1 = __aeabi_d2lz(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  pcVar2 = thr->cgpu;
  dVar5 = (double)__aeabi_l2d((int)thr->cgpu->diff1,*(undefined4 *)((int)&thr->cgpu->diff1 + 4));
  dVar5 = dVar5 + work->device_diff;
  iVar7 = __aeabi_d2lz(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  pcVar2->diff1 = iVar7;
  ppVar3 = work->pool;
  dVar5 = (double)__aeabi_l2d((int)work->pool->diff1,*(undefined4 *)((int)&work->pool->diff1 + 4));
  dVar5 = dVar5 + work->device_diff;
  iVar7 = __aeabi_d2lz(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  ppVar3->diff1 = iVar7;
  pcVar2 = thr->cgpu;
  tVar1 = time((time_t *)0x0);
  pcVar2->last_device_valid_work = tVar1;
  _mutex_unlock(&stats_lock,"cgminer.c","update_work_stats",0x2214);
  return;
}

