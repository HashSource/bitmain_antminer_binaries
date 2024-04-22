
undefined4 nonce_handle(int param_1,int param_2,int param_3,int param_4,undefined param_5)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_424 [1024];
  uint local_24;
  uint local_20;
  int local_1c;
  byte local_15;
  byte local_14;
  byte local_13;
  undefined local_12;
  byte local_11;
  
  local_11 = *(byte *)(param_3 + 2) & 0xf;
  local_12 = *(undefined *)(param_3 + 3);
  local_13 = __udivsi3(local_12,addr_interval);
  local_14 = *(byte *)(param_3 + 5);
  local_15 = 0;
  local_1c = 1;
  if (local_13 < 3) {
    memcpy((void *)(param_2 + (uint)local_13 * 0x5b0 + (uint)local_11 * 0x5b),(void *)(param_3 + 2),
           param_4 - 2);
    if (g_txok_test_enable != '\0') {
      dump_str(app_conf._0_4_,0,param_3,param_4);
    }
    if (local_11 == 0xf) {
      if (g_txok_test_enable != '\0') {
        if (txok_flag_8982 == 0) {
          local_20 = (uint)local_14 << 0x10 | 0x8000fffe;
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
            snprintf(acStack_424,0x400,"write txok %08x nonceid %02x\n",local_20,(uint)local_14);
            _applog(2,acStack_424,0);
          }
          write_register(0x24,local_20);
          txok_flag_8982 = 1;
          return 1;
        }
        local_24 = (uint)local_14 << 0x10 | 0x8000ffff;
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_424,0x400,"write txok %08x nonceid %02x\n",local_24,(uint)local_14);
          _applog(2,acStack_424,0);
        }
        write_register(0x24,local_24);
        txok_flag_8982 = 0;
      }
      local_1c = nonce_integrality(local_13,local_15,param_1,param_2);
      iVar1 = total_error_8981;
      if (local_1c < 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
          total_error_8981 = total_error_8981 + 1;
          snprintf(acStack_424,0x400,"receive a error nonce. total = %u\n",iVar1);
          _applog(1,acStack_424,0);
        }
        uVar2 = 0xffffffff;
      }
      else {
        pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
        nonce_fifo[nonce_fifo._0_4_ * 0x54d + 0x558] = param_5;
        nonce_fifo[nonce_fifo._0_4_ * 0x54d + 0x54c] =
             *(undefined *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d + 0x540);
        nonce_fifo[nonce_fifo._0_4_ * 0x54d + 0x54d] =
             *(undefined *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d + 0x541);
        nonce_fifo[nonce_fifo._0_4_ * 0x54d + 0x54e] =
             *(undefined *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d + 0x542);
        nonce_fifo[nonce_fifo._0_4_ * 0x54d + 0x54f] =
             *(undefined *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d + 0x543);
        memcpy(nonce_fifo + nonce_fifo._0_4_ * 0x54d + 0x550,
               (void *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d + 0x544),4);
        memcpy(nonce_fifo + nonce_fifo._0_4_ * 0x54d + 0x554,
               (void *)((uint)local_15 * 0x54d + 0x548 + param_1 + (uint)local_13 * 0x54d),4);
        memcpy(nonce_fifo + nonce_fifo._0_4_ * 0x54d + 0xc,
               (void *)((uint)local_15 * 0x54d + param_1 + (uint)local_13 * 0x54d),0x540);
        if ((uint)nonce_fifo._0_4_ < 0x1fe) {
          nonce_fifo._0_4_ = nonce_fifo._0_4_ + 1;
        }
        else {
          nonce_fifo._0_4_ = 0;
        }
        if ((uint)nonce_fifo._8_4_ < 0x1ff) {
          nonce_fifo._8_4_ = nonce_fifo._8_4_ + 1;
        }
        else {
          nonce_fifo._8_4_ = 0x1ff;
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
            snprintf(acStack_424,0x400,"%s: nonce fifo full!!!\n","nonce_handle");
            _applog(1,acStack_424,0);
          }
        }
        pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      snprintf(acStack_424,0x400,"%s chipid%d is not exist","nonce_handle",(uint)local_13);
      _applog(1,acStack_424,0);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

