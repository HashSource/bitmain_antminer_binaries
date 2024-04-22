
undefined4 bm1740_makeup_set_address_cmd(undefined *param_1,uint param_2,undefined param_3)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_110 [256];
  undefined4 local_10;
  byte local_c;
  
  if (param_2 < 7) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_110,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_set_address_cmd",7);
      _applog(0,acStack_110,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_10,0,5);
    bVar1 = CRC5(&local_10,0x20);
    *param_1 = 0x55;
    param_1[1] = 0xaa;
    *(undefined4 *)(param_1 + 2) = local_10;
    param_1[6] = local_c & 0xe0 | bVar1 & 0x1f;
    uVar2 = 7;
  }
  return uVar2;
}

