
undefined4
bm1740_makeup_bist_wait_cmd
          (byte param_1,undefined param_2,undefined4 *param_3,undefined *param_4,uint param_5)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_11c [256];
  byte local_1c;
  undefined uStack_1b;
  undefined uStack_1a;
  undefined4 uStack_19;
  undefined local_15;
  byte local_14;
  
  if (param_5 < 0xb) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_11c,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_bist_wait_cmd",0xb);
      _applog(0,acStack_11c,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_1c,0,9);
    local_1c = (param_1 & 1) << 4 | 99;
    uStack_1b = 9;
    uStack_19 = *param_3;
    local_15 = *(undefined *)(param_3 + 1);
    uStack_1a = param_2;
    bVar1 = CRC5(&local_1c,0x40);
    *param_4 = 0x55;
    param_4[1] = 0xaa;
    *(uint *)(param_4 + 2) =
         CONCAT13((undefined)uStack_19,CONCAT12(uStack_1a,CONCAT11(uStack_1b,local_1c)));
    *(uint *)(param_4 + 6) = CONCAT13(local_15,uStack_19._1_3_);
    param_4[10] = local_14 & 0xe0 | bVar1 & 0x1f;
    uVar2 = 0xb;
  }
  return uVar2;
}

