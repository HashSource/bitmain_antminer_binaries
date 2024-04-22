
undefined4
bm1740_parse_respond_pkg
          (int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  char acStack_114 [256];
  undefined4 local_14;
  
  local_14 = 0;
  if ((*(byte *)(param_1 + 2) & 0xf0) == 0xe0) {
    *param_3 = 0;
    uVar1 = bm1740_parse_nonce_respond(param_1,param_2,param_4,param_5);
  }
  else if (*(char *)(param_1 + 2) == -0x34) {
    *param_3 = 1;
    uVar1 = bm1740_parse_pmonitor_respond(param_1,param_2,param_4,param_5);
  }
  else if (*(char *)(param_1 + 2) == -0x45) {
    *param_3 = 3;
    uVar1 = bm1740_parse_bist_respond(param_1,param_2,param_4,param_5);
  }
  else if (*(char *)(param_1 + 2) < '\0') {
    *param_3 = 4;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_114,0x100,"%s unknow respond type %02x\n","bm1740_parse_respond_pkg",
               (uint)*(byte *)(param_1 + 2));
      _applog(0,acStack_114,0);
    }
    uVar1 = 0xffffffff;
  }
  else {
    *param_3 = 2;
    uVar1 = bm1740_parse_reg_respond(param_1,param_2,param_4,param_5);
  }
  return uVar1;
}

