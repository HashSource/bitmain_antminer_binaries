
uint64_t share_diff(work *work)

{
  uint uVar1;
  pool *ppVar2;
  bool bVar3;
  bool bVar4;
  double a;
  UDItype val;
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
  a = round(2.695953529101131e+67 / s64);
  val = __fixunsdfdi(a);
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x140b);
  ret._0_4_ = (uint)val;
  ret._4_4_ = (uint)(val >> 0x20);
  bVar3 = ret._4_4_ <= best_diff._4_4_;
  if (best_diff._4_4_ == ret._4_4_) {
    bVar3 = (uint)ret <= (uint)best_diff;
  }
  if (!bVar3) {
    best_diff._0_4_ = (uint)ret;
    best_diff._4_4_ = ret._4_4_;
    suffix_string(val,best_share,8,0);
  }
  uVar1 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar4 = ret._4_4_ <= uVar1;
  if (uVar1 == ret._4_4_) {
    bVar4 = (uint)ret <= (uint)work->pool->best_diff;
  }
  if (!bVar4) {
    ppVar2 = work->pool;
    *(uint *)&ppVar2->best_diff = (uint)ret;
    *(uint *)((int)&ppVar2->best_diff + 4) = ret._4_4_;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x1419);
  if ((!bVar3) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
  }
  return val;
}

