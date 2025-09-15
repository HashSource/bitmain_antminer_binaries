
/* WARNING: Unknown calling convention */

uint64_t share_diff(work *work)

{
  uint64_t *puVar1;
  uint64_t uVar2;
  int iVar3;
  uint uVar4;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  uint uVar5;
  int line_01;
  int line_02;
  bool bVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  uint64_t val;
  char tmp42 [2048];
  
  dVar8 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x18),*(undefined4 *)(work->hash + 0x1c)
                              );
  dVar9 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 0x10),*(undefined4 *)(work->hash + 0x14)
                              );
  dVar10 = (double)__aeabi_ul2d(*(undefined4 *)(work->hash + 8),*(undefined4 *)(work->hash + 0xc));
  dVar11 = (double)__aeabi_ul2d(*(undefined4 *)work->hash,*(undefined4 *)(work->hash + 4));
  dVar11 = dVar8 * 6.277101735386681e+57 + dVar9 * 3.402823669209385e+38 +
           dVar10 * 1.8446744073709552e+19 + dVar11;
  if (dVar11 == 0.0) {
    dVar11 = 0.0;
  }
  dVar11 = round(2.695953529101131e+67 / dVar11);
  val = __fixunsdfdi(SUB84(dVar11,0),(int)((ulonglong)dVar11 >> 0x20));
  uVar4 = (uint)(val >> 0x20);
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)"share_diff",(char *)0x13ba,func,line);
  }
  iVar3 = pthread_rwlock_wrlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar3 != 0) {
    _wr_lock((pthread_rwlock_t *)"share_diff",(char *)0x13ba,func_00,line_00);
  }
  bVar6 = uVar4 <= best_diff._4_4_;
  if (best_diff._4_4_ == uVar4) {
    bVar6 = (uint)val <= (uint)best_diff;
  }
  if (!bVar6) {
    best_diff = val;
    suffix_string(val,best_share,8,0);
  }
  puVar1 = &work->pool->best_diff;
  uVar5 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar7 = uVar4 <= uVar5;
  if (uVar5 == uVar4) {
    bVar7 = (uint)val <= (uint)*puVar1;
  }
  if (!bVar7) {
    *puVar1 = val;
  }
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar3 != 0) {
    _rw_unlock((pthread_rwlock_t *)"share_diff",(char *)0x13c8,func_01,line_01);
  }
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"share_diff",(char *)0x13c8,func_02,line_02);
  }
  (*selective_yield)();
  uVar2 = best_diff;
  if ((!bVar6) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
    uVar2 = best_diff;
  }
  best_diff._4_4_ = (uint)(uVar2 >> 0x20);
  best_diff._0_4_ = (uint)uVar2;
  return val;
}

