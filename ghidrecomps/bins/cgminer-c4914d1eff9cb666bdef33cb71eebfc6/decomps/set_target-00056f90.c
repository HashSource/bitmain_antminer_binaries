
void set_target(uchar *dest_target,double diff)

{
  char *__ptr;
  undefined4 uVar1;
  DFtype extraout_d0;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  UDItype UVar2;
  double diff_local;
  uchar *dest_target_local;
  char tmp42 [2048];
  uchar target [32];
  char *htarget;
  uint64_t *data64;
  uint64_t h64;
  double dcut64;
  double d64;
  
  if ((diff == 0.0) && (((use_syslog || (opt_log_output)) || (2 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Diff zero passed to set_targ",0x1c);
    tmp42[0x1c] = 'e';
    tmp42[0x1d] = 't';
    tmp42[0x1e] = '\0';
    _applog(3,tmp42,false);
    diff = extraout_d0;
  }
  UVar2 = __fixunsdfdi(diff);
  target._24_8_ = __uint64_identity(UVar2);
  h64._0_4_ = (undefined4)UVar2;
  h64._4_4_ = (undefined4)(UVar2 >> 0x20);
  uVar1 = __floatundidf((undefined4)h64,h64._4_4_);
  UVar2 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar1));
  target._16_8_ = __uint64_identity(UVar2);
  h64._0_4_ = (undefined4)UVar2;
  h64._4_4_ = (undefined4)(UVar2 >> 0x20);
  uVar1 = __floatundidf((undefined4)h64,h64._4_4_);
  UVar2 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1_00,uVar1));
  target._8_8_ = __uint64_identity(UVar2);
  h64._0_4_ = (undefined4)UVar2;
  h64._4_4_ = (undefined4)(UVar2 >> 0x20);
  uVar1 = __floatundidf((undefined4)h64,h64._4_4_);
  UVar2 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1_01,uVar1));
  target._0_8_ = __uint64_identity(UVar2);
  if (opt_debug != false) {
    __ptr = bin2hex(target,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated target %s",__ptr);
      _applog(7,tmp42,false);
    }
    free(__ptr);
  }
  _cg_memcpy(dest_target,target,0x20,"cgminer.c","set_target",0x2057);
  return;
}

