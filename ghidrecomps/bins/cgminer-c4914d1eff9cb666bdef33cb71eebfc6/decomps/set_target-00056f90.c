
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void set_target(uchar *dest_target,double diff)

{
  char *__ptr;
  double in_d0;
  UDItype UVar1;
  undefined4 in_stack_fffff798;
  undefined4 in_stack_fffff79c;
  double diff_local;
  uchar *dest_target_local;
  char tmp42 [2048];
  uchar target [32];
  char *htarget;
  uint64_t *data64;
  uint64_t h64;
  double dcut64;
  double d64;
  
  if ((in_d0 == 0.0) && (((use_syslog || (opt_log_output)) || (2 < opt_log_level)))) {
    tmp42._0_4_ = s_Diff_zero_passed_to_set_target_0008d74c._0_4_;
    tmp42._4_4_ = s_Diff_zero_passed_to_set_target_0008d74c._4_4_;
    tmp42._8_4_ = s_Diff_zero_passed_to_set_target_0008d74c._8_4_;
    tmp42._12_4_ = s_Diff_zero_passed_to_set_target_0008d74c._12_4_;
    tmp42._16_4_ = s_Diff_zero_passed_to_set_target_0008d74c._16_4_;
    tmp42._20_4_ = s_Diff_zero_passed_to_set_target_0008d74c._20_4_;
    tmp42._24_4_ = s_Diff_zero_passed_to_set_target_0008d74c._24_4_;
    tmp42._28_2_ = (undefined2)ram0x0008d768;
    tmp42[30] = (char)((uint)ram0x0008d768 >> 0x10);
    _applog(3,tmp42,false);
  }
  UVar1 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  target._24_8_ = __uint64_identity(CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  h64._0_4_ = (undefined4)UVar1;
  h64._4_4_ = (undefined4)(UVar1 >> 0x20);
  __floatundidf((undefined4)h64,h64._4_4_);
  UVar1 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  target._16_8_ = __uint64_identity(CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  h64._0_4_ = (undefined4)UVar1;
  h64._4_4_ = (undefined4)(UVar1 >> 0x20);
  __floatundidf((undefined4)h64,h64._4_4_);
  UVar1 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  target._8_8_ = __uint64_identity(CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  h64._0_4_ = (undefined4)UVar1;
  h64._4_4_ = (undefined4)(UVar1 >> 0x20);
  __floatundidf((undefined4)h64,h64._4_4_);
  __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff79c,in_stack_fffff798));
  target._0_8_ = __uint64_identity(CONCAT44(in_stack_fffff79c,in_stack_fffff798));
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

