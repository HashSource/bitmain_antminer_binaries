
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void set_target(undefined4 param_1)

{
  void *__ptr;
  double in_d0;
  UDItype UVar1;
  undefined4 in_stack_fffff7a8;
  undefined4 in_stack_fffff7ac;
  UDItype local_850;
  UDItype local_848;
  UDItype local_840;
  UDItype local_838;
  undefined4 local_830;
  undefined4 uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined2 uStack_814;
  undefined local_812;
  
  if (in_d0 == 0.0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      local_850 = 0;
      local_848 = 0;
      local_840 = 0;
      UVar1 = 0xffff0000;
    }
    else {
      UVar1 = 0xffff0000;
      local_830 = s_Diff_zero_passed_to_set_target_0005c824._0_4_;
      uStack_82c = s_Diff_zero_passed_to_set_target_0005c824._4_4_;
      uStack_828 = s_Diff_zero_passed_to_set_target_0005c824._8_4_;
      uStack_824 = s_Diff_zero_passed_to_set_target_0005c824._12_4_;
      local_820 = s_Diff_zero_passed_to_set_target_0005c824._16_4_;
      uStack_81c = s_Diff_zero_passed_to_set_target_0005c824._20_4_;
      uStack_818 = s_Diff_zero_passed_to_set_target_0005c824._24_4_;
      uStack_814 = (undefined2)ram0x0005c840;
      local_812 = (undefined)((uint)ram0x0005c840 >> 0x10);
      _applog(3,&local_830,0);
      local_850 = 0;
      local_848 = 0;
      local_840 = 0;
    }
  }
  else {
    UVar1 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
    __floatundidf();
    local_840 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
    __floatundidf();
    local_848 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
    __floatundidf();
    local_850 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
  }
  local_838 = UVar1;
  if (opt_debug != '\0') {
    __ptr = (void *)bin2hex(&local_850,0x20);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_830,0x800,"Generated target %s",__ptr);
      _applog(7,&local_830,0);
    }
    free(__ptr);
  }
  _cg_memcpy(param_1,&local_850,0x20,"cgminer.c",DAT_0001d790,0x201b);
  return;
}

