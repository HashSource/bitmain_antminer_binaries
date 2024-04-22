
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint get_bt8d_from_baud(int param_1)

{
  uint uVar1;
  undefined4 local_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 local_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined4 uStack_3fc;
  undefined4 local_3f8;
  undefined4 uStack_3f4;
  undefined4 uStack_3f0;
  undefined4 uStack_3ec;
  undefined2 local_3e8;
  undefined4 local_18;
  uint local_14;
  
  local_18 = 5;
  local_14 = 0;
  while( true ) {
    if (4 < local_14) {
      if (local_14 == 5) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          local_418 = s_get_bt8d_value_failed____use_def_00033998._0_4_;
          uStack_414 = s_get_bt8d_value_failed____use_def_00033998._4_4_;
          uStack_410 = s_get_bt8d_value_failed____use_def_00033998._8_4_;
          uStack_40c = s_get_bt8d_value_failed____use_def_00033998._12_4_;
          local_408 = s_get_bt8d_value_failed____use_def_00033998._16_4_;
          uStack_404 = s_get_bt8d_value_failed____use_def_00033998._20_4_;
          uStack_400 = s_get_bt8d_value_failed____use_def_00033998._24_4_;
          uStack_3fc = s_get_bt8d_value_failed____use_def_00033998._28_4_;
          local_3f8 = s_get_bt8d_value_failed____use_def_00033998._32_4_;
          uStack_3f4 = s_get_bt8d_value_failed____use_def_00033998._36_4_;
          uStack_3f0 = s_get_bt8d_value_failed____use_def_00033998._40_4_;
          uStack_3ec = s_get_bt8d_value_failed____use_def_00033998._44_4_;
          local_3e8 = (undefined2)ram0x000339c8;
          _applog(3,&local_418,0);
        }
        uVar1 = get_bt8d_from_baud(0x1c200);
      }
      else {
        uVar1 = 0xff;
      }
      return uVar1;
    }
    if (*(int *)(&baud_BT8D_values + local_14 * 0xc) == param_1) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf((char *)&local_418,0x400,"get bt8d %d\n",(uint)(byte)(&DAT_00046f0c)[local_14 * 0xc]);
    _applog(3,&local_418,0);
  }
  return (uint)(byte)(&DAT_00046f0c)[local_14 * 0xc];
}

