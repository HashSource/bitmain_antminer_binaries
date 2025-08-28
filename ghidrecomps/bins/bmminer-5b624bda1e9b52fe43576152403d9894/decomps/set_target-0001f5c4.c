
void set_target(uchar *dest_target,double diff)

{
  char *__ptr;
  double dVar1;
  double dVar2;
  uchar target [32];
  char tmp42 [2048];
  
  if (diff == 0.0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      builtin_strncpy(tmp42,"Diff zero passed to set_targ",0x1c);
      tmp42[0x1c] = 'e';
      tmp42[0x1d] = 't';
      tmp42[0x1e] = '\0';
      _applog(3,tmp42,false);
      diff = 1.0;
    }
    else {
      diff = 1.0;
    }
  }
  dVar1 = (2.695953529101131e+67 / diff) * 1.5930919111324523e-58;
  target._24_8_ = __fixunsdfdi(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  dVar1 = (double)__aeabi_ul2d();
  dVar2 = 2.695953529101131e+67 / diff - dVar1 * 6.277101735386681e+57;
  dVar1 = dVar2 * 2.938735877055719e-39;
  target._16_8_ = __fixunsdfdi(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  dVar1 = (double)__aeabi_ul2d();
  dVar2 = dVar2 - dVar1 * 3.402823669209385e+38;
  dVar1 = dVar2 * 5.421010862427522e-20;
  target._8_8_ = __fixunsdfdi(SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
  dVar1 = (double)__aeabi_ul2d();
  dVar2 = dVar2 - dVar1 * 1.8446744073709552e+19;
  target._0_8_ = __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  if (opt_debug != false) {
    __ptr = bin2hex(target,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated target %s",__ptr);
      _applog(7,tmp42,false);
    }
    free(__ptr);
  }
  _cg_memcpy(dest_target,target,0x20,"cgminer.c","set_target",0x1ffe);
  return;
}

