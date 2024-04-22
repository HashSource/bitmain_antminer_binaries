
undefined4 bm1740_parse_bist_respond(int param_1,int param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  int local_11c;
  char acStack_118 [259];
  byte local_15;
  int local_14;
  
  local_11c = param_1;
  local_14 = param_1;
  if ((param_2 == 0xb) && (10 < param_4)) {
    local_15 = CRC5(param_1 + 2,0x43);
    if (local_15 == (*(byte *)(local_14 + 10) & 0x1f)) {
      memcpy(param_3,&local_11c,0xb);
      uVar1 = 0xb;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_118,0x100,"%s CRC error. cal-crc=%x, chip-crc=%x\n",
                 "bm1740_parse_bist_respond",(uint)local_15,*(byte *)(local_14 + 10) & 0x1f);
        _applog(0,acStack_118,0);
      }
      uVar1 = 0xffffffff;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_118,0x100,"%s length error\n","bm1740_parse_bist_respond");
      _applog(0,acStack_118,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

