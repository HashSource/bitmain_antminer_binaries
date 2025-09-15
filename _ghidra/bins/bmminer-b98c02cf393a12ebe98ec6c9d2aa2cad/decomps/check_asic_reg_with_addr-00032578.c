
uint check_asic_reg_with_addr(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_838;
  int local_834;
  char acStack_828 [2052];
  
  clear_register_value_buf();
  read_asic_register(param_3 & 0xff,0,param_2 & 0xff,param_1 & 0xff);
  local_834 = 5;
  cgsleep_ms(0x50);
  local_838 = param_3;
  do {
    while( true ) {
      pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
      uVar1 = reg_value_buf._8_4_;
      pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: reg_value_num %d","check_asic_reg_with_addr",uVar1);
        _applog(7,acStack_828,0);
      }
      if (((uint)uVar1 < 0x1ff) && ((uint)reg_value_buf._4_4_ < 0x1ff && uVar1 != 0)) break;
      clear_register_value_buf();
      read_asic_register(local_838 & 0xff,0,param_2 & 0xff,param_1 & 0xff);
      cgsleep_ms(0x50);
      local_834 = local_834 + -1;
      if (local_834 == 0) {
        clear_register_value_buf();
        return 0;
      }
    }
    local_838 = uVar1;
    pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      uVar3 = *(uint *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: chip %x reg %x reg_buff %x","check_asic_reg_with_addr",
                 param_2,param_1,uVar3);
        _applog(7,acStack_828,0);
      }
      reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
      reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
      if (0x1fe < (uint)reg_value_buf._4_4_) {
        reg_value_buf._4_4_ = 0;
      }
      if (param_1 == 0x20) {
        if ((uVar3 & 0xc0000000) != 0) {
          pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          clear_register_value_buf();
          return 0;
        }
        pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        clear_register_value_buf();
        return uVar3;
      }
    } while (iVar2 != uVar1);
    pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
  } while( true );
}

