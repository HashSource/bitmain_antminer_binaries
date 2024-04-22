
uint64_t share_diff(work *work)

{
  uint64_t uVar1;
  char *buf;
  uint bufsiz;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  double dVar5;
  uint64_t uVar6;
  undefined4 in_stack_fffff7c8;
  uint in_stack_fffff7cc;
  work *work_local;
  char tmp42 [2048];
  uint64_t ret;
  double d64;
  double s64;
  _Bool new_best;
  
  le256todouble(work->hash);
  dVar5 = round((double)CONCAT44(in_stack_fffff7cc,in_stack_fffff7c8));
  uVar6 = __fixunsdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  bufsiz = (uint)(uVar6 >> 0x20);
  buf = (char *)uVar6;
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x13c1);
  bVar3 = bufsiz <= best_diff._4_4_;
  if (best_diff._4_4_ == bufsiz) {
    bVar3 = buf <= (char *)best_diff;
  }
  if (!bVar3) {
    best_diff = uVar6;
    suffix_string((ulonglong)in_stack_fffff7cc << 0x20,buf,bufsiz,0x8691c);
  }
  uVar2 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar4 = bufsiz <= uVar2;
  if (uVar2 == bufsiz) {
    bVar4 = buf <= *(char **)&work->pool->best_diff;
  }
  if (!bVar4) {
    work->pool->best_diff = uVar6;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x13cf);
  uVar1 = best_diff;
  if ((!bVar3) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
    uVar1 = best_diff;
  }
  best_diff._4_4_ = (uint)(uVar1 >> 0x20);
  best_diff._0_4_ = (char *)uVar1;
  return uVar6;
}

