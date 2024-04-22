
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint get_bt8d_from_baud(int param_1)

{
  uint uVar1;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined2 local_e8;
  undefined4 local_18;
  uint local_14;
  
  local_18 = 5;
  local_14 = 0;
  while( true ) {
    if (4 < local_14) {
      if (local_14 == 5) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          local_118 = s_get_bt8d_value_failed____use_def_0002c2ec._0_4_;
          uStack_114 = s_get_bt8d_value_failed____use_def_0002c2ec._4_4_;
          uStack_110 = s_get_bt8d_value_failed____use_def_0002c2ec._8_4_;
          uStack_10c = s_get_bt8d_value_failed____use_def_0002c2ec._12_4_;
          local_108 = s_get_bt8d_value_failed____use_def_0002c2ec._16_4_;
          uStack_104 = s_get_bt8d_value_failed____use_def_0002c2ec._20_4_;
          uStack_100 = s_get_bt8d_value_failed____use_def_0002c2ec._24_4_;
          uStack_fc = s_get_bt8d_value_failed____use_def_0002c2ec._28_4_;
          local_f8 = s_get_bt8d_value_failed____use_def_0002c2ec._32_4_;
          uStack_f4 = s_get_bt8d_value_failed____use_def_0002c2ec._36_4_;
          uStack_f0 = s_get_bt8d_value_failed____use_def_0002c2ec._40_4_;
          uStack_ec = s_get_bt8d_value_failed____use_def_0002c2ec._44_4_;
          local_e8 = (undefined2)ram0x0002c31c;
          _applog(3,&local_118,0);
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
    snprintf((char *)&local_118,0x100,"get bt8d %d\n",(uint)(byte)(&DAT_00030224)[local_14 * 0xc]);
    _applog(3,&local_118,0);
  }
  return (uint)(byte)(&DAT_00030224)[local_14 * 0xc];
}

