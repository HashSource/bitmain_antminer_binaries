
uint64_t share_diff(work *work)

{
  uint64_t uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  uint64_t val;
  work *work_local;
  char tmp42 [2048];
  uint64_t ret;
  double d64;
  double s64;
  _Bool new_best;
  
  s64 = le256todouble(work->hash);
  if (s64 == 0.0) {
    s64 = 0.0;
  }
  dVar6 = round(2.695953529101131e+67 / s64);
  val = __fixunsdfdi(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20));
  uVar2 = (uint)(val >> 0x20);
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x13c1);
  bVar4 = uVar2 <= best_diff._4_4_;
  if (best_diff._4_4_ == uVar2) {
    bVar4 = (uint)val <= (uint)best_diff;
  }
  if (!bVar4) {
    best_diff = val;
    suffix_string(val,best_share,8,0);
  }
  uVar3 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar5 = uVar2 <= uVar3;
  if (uVar3 == uVar2) {
    bVar5 = (uint)val <= (uint)work->pool->best_diff;
  }
  if (!bVar5) {
    work->pool->best_diff = val;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x13cf);
  uVar1 = best_diff;
  if ((!bVar4) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
    uVar1 = best_diff;
  }
  best_diff._4_4_ = (uint)(uVar1 >> 0x20);
  best_diff._0_4_ = (uint)uVar1;
  return val;
}

