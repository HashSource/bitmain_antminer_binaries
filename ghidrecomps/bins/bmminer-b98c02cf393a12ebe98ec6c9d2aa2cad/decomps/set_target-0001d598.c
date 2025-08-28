
void set_target(undefined4 param_1)

{
  void *__ptr;
  undefined4 uVar1;
  double in_d0;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  UDItype UVar2;
  UDItype local_850;
  UDItype local_848;
  UDItype local_840;
  UDItype local_838;
  char local_830 [28];
  undefined2 uStack_814;
  undefined1 local_812;
  
  if (in_d0 == 0.0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      local_850 = 0;
      local_848 = 0;
      local_840 = 0;
      UVar2 = 0xffff0000;
    }
    else {
      UVar2 = 0xffff0000;
      builtin_strncpy(local_830,"Diff zero passed to set_targ",0x1c);
      uStack_814 = 0x7465;
      local_812 = 0;
      _applog(3,local_830,0);
      local_850 = 0;
      local_848 = 0;
      local_840 = 0;
    }
  }
  else {
    UVar2 = __fixunsdfdi(in_d0);
    uVar1 = __floatundidf();
    local_840 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar1));
    uVar1 = __floatundidf();
    local_848 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1_00,uVar1));
    uVar1 = __floatundidf();
    local_850 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1_01,uVar1));
  }
  local_838 = UVar2;
  if (opt_debug != '\0') {
    __ptr = (void *)bin2hex(&local_850,0x20);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_830,0x800,"Generated target %s",__ptr);
      _applog(7,local_830,0);
    }
    free(__ptr);
  }
  _cg_memcpy(param_1,&local_850,0x20,"cgminer.c","set_target",0x201b);
  return;
}

