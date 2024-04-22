
undefined4
bm1740_makeup_bist_write_wait_cmd
          (byte param_1,undefined param_2,undefined4 *param_3,undefined param_4,undefined *param_5,
          uint param_6)

{
  byte bVar1;
  undefined4 uVar2;
  char acStack_11c [256];
  byte local_1c;
  undefined uStack_1b;
  undefined uStack_1a;
  undefined4 uStack_19;
  undefined local_15;
  undefined uStack_14;
  undefined local_13;
  byte local_12;
  
  if (param_6 < 0xd) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_11c,0x100,"%s input param error: str length = %u\n",
               "bm1740_makeup_bist_write_wait_cmd",0xd);
      _applog(0,acStack_11c,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    memset(&local_1c,0,0xb);
    local_1c = (param_1 & 1) << 4 | 0x61;
    uStack_1b = 0xb;
    uStack_19 = *param_3;
    local_15 = (undefined)*(undefined2 *)(param_3 + 1);
    uStack_14 = (undefined)((ushort)*(undefined2 *)(param_3 + 1) >> 8);
    uStack_1a = param_2;
    local_13 = param_4;
    bVar1 = CRC5(&local_1c,0x50);
    *param_5 = 0x55;
    param_5[1] = 0xaa;
    *(uint *)(param_5 + 2) =
         CONCAT13((undefined)uStack_19,CONCAT12(uStack_1a,CONCAT11(uStack_1b,local_1c)));
    *(uint *)(param_5 + 6) = CONCAT13(local_15,uStack_19._1_3_);
    *(ushort *)(param_5 + 10) = CONCAT11(local_13,uStack_14);
    param_5[0xc] = local_12 & 0xe0 | bVar1 & 0x1f;
    uVar2 = 0xd;
  }
  return uVar2;
}

