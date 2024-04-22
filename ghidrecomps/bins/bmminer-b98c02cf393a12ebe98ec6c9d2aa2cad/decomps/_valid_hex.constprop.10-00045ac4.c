
undefined _valid_hex_constprop_10(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  size_t sVar1;
  byte *pbVar2;
  uint uVar3;
  char acStack_820 [2052];
  
  if (param_1 == (byte *)0x0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    snprintf(acStack_820,0x800,"Null string passed to valid_hex from"," in %s %s():%d","util.c",
             param_2,param_3);
  }
  else {
    sVar1 = strlen((char *)param_1);
    if ((int)sVar1 < 1) {
      return 1;
    }
    uVar3 = (uint)*param_1;
    if (-1 < *(int *)(&hex2bin_tbl + uVar3 * 4)) {
      pbVar2 = param_1 + 1;
      do {
        if (pbVar2 == param_1 + sVar1) {
          return 1;
        }
        uVar3 = (uint)*pbVar2;
        pbVar2 = pbVar2 + 1;
      } while (-1 < *(int *)(&hex2bin_tbl + uVar3 * 4));
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    snprintf(acStack_820,0x800,"Invalid char 0x%x passed to valid_hex from"," in %s %s():%d",uVar3,
             "util.c",param_2,param_3);
  }
  _applog(3,acStack_820,0);
  return 0;
}

