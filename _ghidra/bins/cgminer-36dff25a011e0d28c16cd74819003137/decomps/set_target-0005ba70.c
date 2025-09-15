
void set_target(uchar *dest_target,double diff)

{
  char *__ptr;
  double dVar1;
  double dVar2;
  __uint64_t _Var3;
  double diff_local;
  uchar *dest_target_local;
  char tmp42 [2048];
  uchar target [32];
  char *htarget;
  uint64_t *data64;
  uint64_t h64;
  double dcut64;
  double d64;
  
  diff_local = diff;
  if (diff == 0.0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"Diff zero passed to set_targ",0x1c);
      tmp42[0x1c] = 'e';
      tmp42[0x1d] = 't';
      tmp42[0x1e] = '\0';
      _applog(3,tmp42,false);
    }
    diff_local = 1.0;
  }
  dVar1 = (2.695953529101131e+67 / diff_local) / 6.277101735386681e+57;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  _Var3 = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  target._24_8_ = __uint64_identity(_Var3);
  dcut64 = (double)__floatundidf((int)_Var3,(int)(_Var3 >> 0x20));
  dVar2 = 2.695953529101131e+67 / diff_local - dcut64 * 6.277101735386681e+57;
  dVar1 = dVar2 / 3.402823669209385e+38;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  _Var3 = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  target._16_8_ = __uint64_identity(_Var3);
  dcut64 = (double)__floatundidf((int)_Var3,(int)(_Var3 >> 0x20));
  dVar2 = dVar2 - dcut64 * 3.402823669209385e+38;
  dVar1 = dVar2 / 1.8446744073709552e+19;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  _Var3 = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  target._8_8_ = __uint64_identity(_Var3);
  dcut64 = (double)__floatundidf((int)_Var3,(int)(_Var3 >> 0x20));
  dVar2 = dVar2 - dcut64 * 1.8446744073709552e+19;
  d64._0_4_ = SUB84(dVar2,0);
  d64._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
  _Var3 = __fixunsdfdi(d64._0_4_,d64._4_4_);
  target._0_8_ = __uint64_identity(_Var3);
  if (opt_debug != false) {
    __ptr = bin2hex(target,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated target %s",__ptr);
      _applog(7,tmp42,false);
    }
    free(__ptr);
  }
  _cg_memcpy(dest_target,target,0x20,"cgminer.c","set_target",0x2054);
  return;
}

