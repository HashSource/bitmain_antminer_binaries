
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void set_target(uchar *dest_target,double diff)

{
  char *__ptr;
  double in_d0;
  double dVar1;
  double dVar2;
  double diff_local;
  uchar *dest_target_local;
  char tmp42 [2048];
  uchar target [32];
  char *htarget;
  uint64_t *data64;
  uint64_t h64;
  double dcut64;
  double d64;
  
  diff_local = in_d0;
  if (in_d0 == 0.0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      tmp42._0_4_ = s_Diff_zero_passed_to_set_target_00073ec8._0_4_;
      tmp42._4_4_ = s_Diff_zero_passed_to_set_target_00073ec8._4_4_;
      tmp42._8_4_ = s_Diff_zero_passed_to_set_target_00073ec8._8_4_;
      tmp42._12_4_ = s_Diff_zero_passed_to_set_target_00073ec8._12_4_;
      tmp42._16_4_ = s_Diff_zero_passed_to_set_target_00073ec8._16_4_;
      tmp42._20_4_ = s_Diff_zero_passed_to_set_target_00073ec8._20_4_;
      tmp42._24_4_ = s_Diff_zero_passed_to_set_target_00073ec8._24_4_;
      tmp42._28_2_ = (undefined2)ram0x00073ee4;
      tmp42[30] = (char)((uint)ram0x00073ee4 >> 0x10);
      _applog(3,tmp42,false);
    }
    diff_local = 1.0;
  }
  d64 = (double)CONCAT44(truediffone._4_4_,truediffone._0_4_);
  dVar1 = (d64 / diff_local) / bits192;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  target._24_8_ = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  dcut64 = (double)__aeabi_ul2d((int)target._24_8_,SUB84(target._24_8_,4));
  dVar2 = d64 / diff_local - dcut64 * bits192;
  dVar1 = dVar2 / bits128;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  target._16_8_ = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  dcut64 = (double)__aeabi_ul2d((int)target._16_8_,SUB84(target._16_8_,4));
  dVar2 = dVar2 - dcut64 * bits128;
  dVar1 = dVar2 / bits64;
  dcut64._0_4_ = SUB84(dVar1,0);
  dcut64._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  target._8_8_ = __fixunsdfdi(dcut64._0_4_,dcut64._4_4_);
  dcut64 = (double)__aeabi_ul2d((int)target._8_8_,SUB84(target._8_8_,4));
  dVar2 = dVar2 - dcut64 * bits64;
  d64._0_4_ = SUB84(dVar2,0);
  d64._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
  target._0_8_ = __fixunsdfdi(d64._0_4_,d64._4_4_);
  if (opt_debug != false) {
    __ptr = bin2hex(target,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated target %s",__ptr);
      _applog(7,tmp42,false);
    }
    free(__ptr);
  }
  _cg_memcpy(dest_target,target,0x20,"cgminer.c","set_target",0x2005);
  return;
}

