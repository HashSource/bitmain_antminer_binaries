
uint64_t share_diff(work *work)

{
  bool bVar1;
  uint64_t uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  double dVar10;
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
  dVar10 = round(2.695953529101131e+67 / s64);
  val = __fixunsdfdi(SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20));
  uVar4 = (uint)(val >> 0x20);
  uVar3 = (uint)val;
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x1408);
  bVar8 = best_diff._4_4_ <= uVar4;
  if (uVar4 == best_diff._4_4_) {
    bVar8 = (uint)best_diff <= uVar3;
  }
  bVar7 = uVar3 != (uint)best_diff;
  bVar1 = uVar4 != best_diff._4_4_;
  if (bVar8 && (bVar1 || bVar7)) {
    best_diff = val;
    suffix_string(val,best_share,8,0);
  }
  uVar5 = (uint)work->pool->best_diff;
  uVar6 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar9 = uVar6 <= uVar4;
  if (uVar4 == uVar6) {
    bVar9 = uVar5 <= uVar3;
  }
  if (bVar9 && (uVar4 != uVar6 || uVar3 != uVar5)) {
    work->pool->best_diff = val;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x1416);
  uVar2 = best_diff;
  if ((bVar8 && (bVar1 || bVar7)) &&
     (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
    uVar2 = best_diff;
  }
  best_diff._4_4_ = (uint)(uVar2 >> 0x20);
  best_diff._0_4_ = (uint)uVar2;
  return val;
}

