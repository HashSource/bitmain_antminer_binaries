
uint check_asic_reg_with_addr(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
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
      pthread_mutex_lock(DAT_00032744);
      uVar2 = reg_value_buf._8_4_;
      pthread_mutex_unlock(DAT_00032744);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: reg_value_num %d",DAT_00032748,uVar2);
        _applog(7,acStack_828,0);
      }
      uVar1 = DAT_00032748;
      if (((uint)uVar2 < 0x1ff) && ((uint)reg_value_buf._4_4_ < 0x1ff && uVar2 != 0)) break;
      clear_register_value_buf();
      read_asic_register(local_838 & 0xff,0,param_2 & 0xff,param_1 & 0xff);
      cgsleep_ms(0x50);
      local_834 = local_834 + -1;
      if (local_834 == 0) {
        clear_register_value_buf();
        return 0;
      }
    }
    local_838 = uVar2;
    pthread_mutex_lock(DAT_00032744);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      uVar4 = *(uint *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: chip %x reg %x reg_buff %x",uVar1,param_2,param_1,uVar4);
        _applog(7,acStack_828,0);
      }
      reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
      reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
      if (0x1fe < (uint)reg_value_buf._4_4_) {
        reg_value_buf._4_4_ = 0;
      }
      if (param_1 == 0x20) {
        if ((uVar4 & 0xc0000000) != 0) {
          pthread_mutex_unlock(DAT_00032744);
          clear_register_value_buf();
          return 0;
        }
        pthread_mutex_unlock(DAT_00032744);
        clear_register_value_buf();
        return uVar4;
      }
    } while (iVar3 != uVar2);
    pthread_mutex_unlock(DAT_00032744);
  } while( true );
}

