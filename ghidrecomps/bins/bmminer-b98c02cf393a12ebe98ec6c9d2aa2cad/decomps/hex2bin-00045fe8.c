
bool hex2bin(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  char local_810 [20];
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
      builtin_strncpy(local_810,"hex2bin str truncate",0x14);
      local_7fc = 100;
      _applog(3,local_810,0);
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
      builtin_strncpy(local_810,"hex2bin scan failed",0x14);
      _applog(3,local_810,0);
      return false;
    }
  }
  return false;
}

