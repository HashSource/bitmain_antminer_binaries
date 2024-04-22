
undefined4
bm1740_makeup_set_config_cmd
          (undefined *param_1,uint param_2,byte param_3,undefined param_4,undefined param_5,
          uint param_6)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_120 [256];
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  byte local_14;
  
  if (param_2 < 0xb) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_120,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_set_config_cmd",0xb);
      _applog(0,acStack_120,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_1c,0,9);
    local_1c = CONCAT13(param_5,CONCAT12(param_4,CONCAT11(9,(param_3 & 1) << 4 | 0x41)));
    local_20 = param_6 << 0x18 | (param_6 >> 8 & 0xff) << 0x10 | (param_6 >> 0x10 & 0xff) << 8 |
               param_6 >> 0x18;
    local_18 = local_20;
    bVar1 = CRC5(&local_1c,0x40);
    *param_1 = 0x55;
    param_1[1] = 0xaa;
    *(undefined4 *)(param_1 + 2) = local_1c;
    *(uint *)(param_1 + 6) = local_18;
    param_1[10] = local_14 & 0xe0 | bVar1 & 0x1f;
    uVar2 = 0xb;
  }
  return uVar2;
}

