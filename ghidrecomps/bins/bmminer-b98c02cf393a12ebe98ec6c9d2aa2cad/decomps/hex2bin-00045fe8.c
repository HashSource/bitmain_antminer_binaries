
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool hex2bin(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined2 local_7fc;
  
  if (*param_2 == 0) {
    return param_3 == 0;
  }
  if (param_3 == 0) {
    return false;
  }
  if (param_2[1] == 0) {
LAB_00046096:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      local_810._0_1_ = s_hex2bin_str_truncated_000670ec[0];
      local_810._1_1_ = s_hex2bin_str_truncated_000670ec[1];
      local_810._2_1_ = s_hex2bin_str_truncated_000670ec[2];
      local_810._3_1_ = s_hex2bin_str_truncated_000670ec[3];
      uStack_80c._0_1_ = s_hex2bin_str_truncated_000670ec[4];
      uStack_80c._1_1_ = s_hex2bin_str_truncated_000670ec[5];
      uStack_80c._2_1_ = s_hex2bin_str_truncated_000670ec[6];
      uStack_80c._3_1_ = s_hex2bin_str_truncated_000670ec[7];
      uStack_808._0_1_ = s_hex2bin_str_truncated_000670ec[8];
      uStack_808._1_1_ = s_hex2bin_str_truncated_000670ec[9];
      uStack_808._2_1_ = s_hex2bin_str_truncated_000670ec[10];
      uStack_808._3_1_ = s_hex2bin_str_truncated_000670ec[11];
      uStack_804._0_1_ = s_hex2bin_str_truncated_000670ec[12];
      uStack_804._1_1_ = s_hex2bin_str_truncated_000670ec[13];
      uStack_804._2_1_ = s_hex2bin_str_truncated_000670ec[14];
      uStack_804._3_1_ = s_hex2bin_str_truncated_000670ec[15];
      local_800._0_1_ = s_hex2bin_str_truncated_000670ec[16];
      local_800._1_1_ = s_hex2bin_str_truncated_000670ec[17];
      local_800._2_1_ = s_hex2bin_str_truncated_000670ec[18];
      local_800._3_1_ = s_hex2bin_str_truncated_000670ec[19];
      local_7fc = (undefined2)ram0x00067100;
      _applog(3,&local_810,0);
    }
  }
  else {
    uVar3 = *(uint *)(&hex2bin_tbl + (uint)*param_2 * 4);
    uVar4 = *(uint *)(&hex2bin_tbl + (uint)param_2[1] * 4);
    if (-1 < (int)(uVar3 | uVar4)) {
      param_2 = param_2 + 4;
      do {
        param_3 = param_3 + -1;
        *param_1 = (byte)uVar4 | (byte)((uVar3 & 0xff) << 4);
        pbVar1 = param_2 + -2;
        if (*pbVar1 == 0) {
          return param_3 == 0;
        }
        if (param_3 == 0) {
          return false;
        }
        pbVar2 = param_2 + -1;
        param_2 = param_2 + 2;
        if (*pbVar2 == 0) goto LAB_00046096;
        uVar3 = *(uint *)(&hex2bin_tbl + (uint)*pbVar1 * 4);
        uVar4 = *(uint *)(&hex2bin_tbl + (uint)*pbVar2 * 4);
        param_1 = param_1 + 1;
      } while (-1 < (int)(uVar3 | uVar4));
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      local_810._0_1_ = s_hex2bin_scan_failed_00067104[0];
      local_810._1_1_ = s_hex2bin_scan_failed_00067104[1];
      local_810._2_1_ = s_hex2bin_scan_failed_00067104[2];
      local_810._3_1_ = s_hex2bin_scan_failed_00067104[3];
      uStack_80c._0_1_ = s_hex2bin_scan_failed_00067104[4];
      uStack_80c._1_1_ = s_hex2bin_scan_failed_00067104[5];
      uStack_80c._2_1_ = s_hex2bin_scan_failed_00067104[6];
      uStack_80c._3_1_ = s_hex2bin_scan_failed_00067104[7];
      uStack_808._0_1_ = s_hex2bin_scan_failed_00067104[8];
      uStack_808._1_1_ = s_hex2bin_scan_failed_00067104[9];
      uStack_808._2_1_ = s_hex2bin_scan_failed_00067104[10];
      uStack_808._3_1_ = s_hex2bin_scan_failed_00067104[11];
      uStack_804._0_1_ = s_hex2bin_scan_failed_00067104[12];
      uStack_804._1_1_ = s_hex2bin_scan_failed_00067104[13];
      uStack_804._2_1_ = s_hex2bin_scan_failed_00067104[14];
      uStack_804._3_1_ = s_hex2bin_scan_failed_00067104[15];
      local_800._0_1_ = s_hex2bin_scan_failed_00067104[16];
      local_800._1_1_ = s_hex2bin_scan_failed_00067104[17];
      local_800._2_1_ = s_hex2bin_scan_failed_00067104[18];
      local_800._3_1_ = s_hex2bin_scan_failed_00067104[19];
      _applog(3,&local_810,0);
      return false;
    }
  }
  return false;
}

