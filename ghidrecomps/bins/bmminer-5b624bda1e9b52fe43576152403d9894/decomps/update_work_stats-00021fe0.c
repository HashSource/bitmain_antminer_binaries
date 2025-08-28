
/* WARNING: Unknown calling convention */

void update_work_stats(thr_info *thr,work *work)

{
  _Bool _Var1;
  int iVar2;
  time_t tVar3;
  char *func;
  char *func_00;
  int line;
  int line_00;
  pool *ppVar4;
  cgpu_info *pcVar5;
  double dVar6;
  double dVar7;
  uint64_t uVar8;
  int64_t iVar9;
  char tmp42 [2048];
  
  dVar7 = current_diff;
  uVar8 = share_diff(work);
  work->share_diff = uVar8;
  dVar6 = (double)__aeabi_ul2d();
  _Var1 = use_syslog;
  if (dVar7 <= dVar6) {
    ppVar4 = work->pool;
    iVar2 = ppVar4->solved;
    work->block = true;
    found_blocks = found_blocks + 1;
    ppVar4->solved = iVar2 + 1;
    work->mandatory = true;
    if (((_Var1 != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Found block for pool %d!",ppVar4->pool_no);
      _applog(5,tmp42,false);
    }
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"update_work_stats",(char *)0x2208,func,line);
  }
  dVar6 = work->device_diff;
  dVar7 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  total_diff1 = __aeabi_d2lz(SUB84(dVar7 + dVar6,0),(int)((ulonglong)(dVar7 + dVar6) >> 0x20));
  pcVar5 = thr->cgpu;
  dVar7 = (double)__aeabi_l2d((int)pcVar5->diff1,*(undefined4 *)((int)&pcVar5->diff1 + 4));
  iVar9 = __aeabi_d2lz(SUB84(dVar6 + dVar7,0),(int)((ulonglong)(dVar6 + dVar7) >> 0x20));
  ppVar4 = work->pool;
  pcVar5->diff1 = iVar9;
  dVar7 = (double)__aeabi_l2d((int)ppVar4->diff1,*(undefined4 *)((int)&ppVar4->diff1 + 4));
  iVar9 = __aeabi_d2lz(SUB84(dVar6 + dVar7,0),(int)((ulonglong)(dVar6 + dVar7) >> 0x20));
  ppVar4->diff1 = iVar9;
  tVar3 = time((time_t *)0x0);
  pcVar5->last_device_valid_work = tVar3;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"update_work_stats",(char *)0x220d,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

