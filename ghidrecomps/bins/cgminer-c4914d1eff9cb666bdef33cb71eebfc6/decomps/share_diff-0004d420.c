
uint64_t share_diff(work *work)

{
  uint uVar1;
  pool *ppVar2;
  bool bVar3;
  bool bVar4;
  UDItype UVar5;
  undefined4 in_stack_fffff7c0;
  uint in_stack_fffff7c4;
  work *work_local;
  char tmp42 [2048];
  uint64_t ret;
  double d64;
  double s64;
  _Bool new_best;
  
  le256todouble(work->hash);
  round((double)CONCAT44(in_stack_fffff7c4,in_stack_fffff7c0));
  UVar5 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7c4,in_stack_fffff7c0));
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x140b);
  ret._0_4_ = (char *)UVar5;
  ret._4_4_ = (uint)(UVar5 >> 0x20);
  bVar3 = ret._4_4_ <= best_diff._4_4_;
  if (best_diff._4_4_ == ret._4_4_) {
    bVar3 = (char *)ret <= (char *)best_diff;
  }
  if (!bVar3) {
    best_diff._0_4_ = (char *)ret;
    best_diff._4_4_ = ret._4_4_;
    suffix_string((ulonglong)in_stack_fffff7c4 << 0x20,(char *)ret,ret._4_4_,0xab1f0);
  }
  uVar1 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar4 = ret._4_4_ <= uVar1;
  if (uVar1 == ret._4_4_) {
    bVar4 = (char *)ret <= *(char **)&work->pool->best_diff;
  }
  if (!bVar4) {
    ppVar2 = work->pool;
    *(char **)&ppVar2->best_diff = (char *)ret;
    *(uint *)((int)&ppVar2->best_diff + 4) = ret._4_4_;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x1419);
  if ((!bVar3) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
  }
  return UVar5;
}

