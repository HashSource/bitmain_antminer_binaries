
undefined4
bm1740_makeup_bist_disable_cmd(byte param_1,undefined param_2,undefined *param_3,uint param_4)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_118 [256];
  undefined4 local_18;
  byte local_14;
  
  if (param_4 < 7) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_118,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_bist_disable_cmd",7);
      _applog(0,acStack_118,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_18,0,5);
    bVar1 = CRC5(&local_18,0x20);
    *param_3 = 0x55;
    param_3[1] = 0xaa;
    *(undefined4 *)(param_3 + 2) = local_18;
    param_3[6] = local_14 & 0xe0 | bVar1 & 0x1f;
    uVar2 = 7;
  }
  return uVar2;
}

