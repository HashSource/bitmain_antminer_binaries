
undefined4 bm1740_parse_reg_respond(void *param_1,int param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  char acStack_118 [256];
  void *local_18;
  byte local_11;
  
  local_11 = 0;
  local_18 = param_1;
  if ((param_2 == 9) && (8 < param_4)) {
    local_11 = CRC5((int)param_1 + 2,0x33);
    if (local_11 == (*(byte *)((int)local_18 + 8) & 0x1f)) {
      memcpy(param_3,param_1,9);
      uVar1 = 9;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_118,0x100,"%s CRC error crc = %02x\n","bm1740_parse_reg_respond",
                 (uint)local_11);
        _applog(0,acStack_118,0);
      }
      uVar1 = 0xffffffff;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_118,0x100,"%s length error\n","bm1740_parse_reg_respond");
      _applog(0,acStack_118,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

