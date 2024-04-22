
undefined4
bm1740_makeup_get_status_cmd
          (undefined *param_1,uint param_2,byte param_3,undefined param_4,undefined param_5)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_118 [256];
  undefined4 local_18;
  byte local_14;
  
  if (param_2 < 7) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_118,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_get_status_cmd",7);
      _applog(0,acStack_118,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_18,0,5);
    local_18 = CONCAT13(param_5,CONCAT12(param_4,CONCAT11(5,(param_3 & 1) << 4 | 0x42)));
    bVar1 = CRC5(&local_18,0x20);
    local_14 = local_14 & 0xe0 | bVar1 & 0x1f;
    if (g_crc5_err_enable != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_118,0x100,"true crc5 = %x\n",local_14 & 0x1f);
        _applog(3,acStack_118,0);
      }
      local_14 = local_14 & 0xe0 | (byte)(((uint)local_14 << 0x1b) >> 0x1b) + 1 & 0x1f;
    }
    *param_1 = 0x55;
    param_1[1] = 0xaa;
    *(undefined4 *)(param_1 + 2) = local_18;
    param_1[6] = local_14;
    uVar2 = 7;
  }
  return uVar2;
}

