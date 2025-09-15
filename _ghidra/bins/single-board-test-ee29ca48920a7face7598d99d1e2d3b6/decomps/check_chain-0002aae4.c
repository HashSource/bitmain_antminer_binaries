
undefined4 check_chain(void)

{
  undefined4 uVar1;
  char acStack_410 [1024];
  uint local_10;
  char local_9;
  
  local_9 = 0xff;
  local_10 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_410,0x400,"--- %s\n","check_chain");
    _applog(2,acStack_410,0);
  }
  cgpu._76_4_ = 0;
  local_10 = read_axi_fpga(2);
  if (((local_10 == 1) || (local_10 == 2)) || ((local_10 == 4 || (local_10 == 8)))) {
    for (local_9 = '\0'; local_9 == '\0'; local_9 = local_9 + '\x01') {
      chain_info._0_1_ = 0;
      chain_info._1_1_ = 0;
      if ((local_10 & 1) == 0) {
        cgpu._84_4_ = 0;
      }
      else {
        cgpu._84_4_ = 1;
        cgpu._76_4_ = cgpu._76_4_ + 1;
        gChain_exist = 1;
        gChain_fd = 0;
        gChain = local_9;
        gI2c = 0;
        chain_info._0_1_ = 0;
        chain_info._1_1_ = 0;
        g_chain._0_4_ = 0;
        g_chain[4] = 0;
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_410,0x400,"%s: gChain = %d, gI2c = %d\n","check_chain",0,0);
          _applog(2,acStack_410,0);
        }
      }
    }
    uVar1 = 0;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_410,0x400,"%s: Test zhiju only support 1 plug, but now is 0x%08x\n",
               "check_chain",local_10);
      _applog(2,acStack_410,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

