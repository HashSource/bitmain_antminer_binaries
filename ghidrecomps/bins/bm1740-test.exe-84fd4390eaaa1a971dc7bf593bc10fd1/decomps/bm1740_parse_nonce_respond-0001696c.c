
undefined4 bm1740_parse_nonce_respond(void *param_1,int param_2,void *param_3,uint param_4)

{
  undefined4 uVar1;
  char acStack_110 [260];
  
  if ((param_2 == 0x5d) && (0x5c < param_4)) {
    memcpy(param_3,param_1,0x5d);
    uVar1 = 0x5d;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_110,0x100,"%s input str len error, input len=%d\n",
               "bm1740_parse_nonce_respond",param_2);
      _applog(0,acStack_110,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

