
uint64_t share_diff(work *work)

{
  bool bVar1;
  bool bVar2;
  uint64_t uVar3;
  char *buf;
  uint bufsiz;
  char *pcVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  double dVar8;
  uint64_t uVar9;
  undefined4 in_stack_fffff7c8;
  uint in_stack_fffff7cc;
  work *work_local;
  char tmp42 [2048];
  uint64_t ret;
  double d64;
  double s64;
  _Bool new_best;
  
  le256todouble(work->hash);
  dVar8 = round((double)CONCAT44(in_stack_fffff7cc,in_stack_fffff7c8));
  uVar9 = __fixunsdfdi(SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20));
  bufsiz = (uint)(uVar9 >> 0x20);
  buf = (char *)uVar9;
  _cg_wlock(&control_lock,"cgminer.c","share_diff",0x1408);
  bVar6 = best_diff._4_4_ <= bufsiz;
  if (bufsiz == best_diff._4_4_) {
    bVar6 = (char *)best_diff <= buf;
  }
  bVar1 = buf != (char *)best_diff;
  bVar2 = bufsiz != best_diff._4_4_;
  if (bVar6 && (bVar2 || bVar1)) {
    best_diff = uVar9;
    suffix_string((ulonglong)in_stack_fffff7cc << 0x20,buf,bufsiz,0xc3250);
  }
  pcVar4 = *(char **)&work->pool->best_diff;
  uVar5 = *(uint *)((int)&work->pool->best_diff + 4);
  bVar7 = uVar5 <= bufsiz;
  if (bufsiz == uVar5) {
    bVar7 = pcVar4 <= buf;
  }
  if (bVar7 && (bufsiz != uVar5 || buf != pcVar4)) {
    work->pool->best_diff = uVar9;
  }
  _cg_wunlock(&control_lock,"cgminer.c","share_diff",0x1416);
  uVar3 = best_diff;
  if ((bVar6 && (bVar2 || bVar1)) &&
     (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"New best share: %s",best_share);
    _applog(6,tmp42,false);
    uVar3 = best_diff;
  }
  best_diff._4_4_ = (uint)(uVar3 >> 0x20);
  best_diff._0_4_ = (char *)uVar3;
  return uVar9;
}

