
uint check_asic_reg_with_addr_test(uint reg,uchar chip_addr,uint chain,int check_num)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int check_num_local;
  uint chain_local;
  uchar chip_addr_local;
  uint reg_local;
  char tmp42 [2048];
  int core_id_2;
  int core_id_1;
  int core_id;
  uchar chip_address;
  uint ret_count;
  uint check_count;
  uint reg_buf;
  uint reg_value_num;
  int nonce_number;
  int cc;
  uint no_reg_time;
  int last_get_num;
  int get_num;
  int not_reg_data_time;
  int i;
  
  not_reg_data_time = 0;
  get_num = 0;
  last_get_num = 0;
  no_reg_time = 0;
  cc = 0x14;
rerun:
  do {
    cgsleep_ms(0x50);
    while (not_reg_data_time < 5) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar2 = reg_value_buf.reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: reg_value_num %d","check_asic_reg_with_addr_test",uVar2);
        _applog(7,tmp42,false);
      }
      if ((((0x1fe < uVar2) || (0x1fe < reg_value_buf.p_rd)) || (uVar2 == 0)) &&
         (not_reg_data_time < 5)) {
        not_reg_data_time = not_reg_data_time + 1;
        goto rerun;
      }
      if (4 < not_reg_data_time) {
        return 0;
      }
      get_num = get_num + uVar2;
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      for (i = 0; (uint)i < uVar2; i = i + 1) {
        uVar3 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
        bVar1 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].chip_address;
        if ((reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number == chain) && (bVar1 < 0xd9))
        {
          if (reg == 0x40) {
            if (check_core_register == 0) {
              uVar4 = uVar3 >> 0x18;
              core_hash_clock_delay_control[chain][bVar1 >> 1][uVar4] = (uchar)uVar3;
              if ((cc < 10) &&
                 (((cc = cc + 1, use_syslog != false || (opt_log_output != false)) ||
                  (4 < opt_log_level)))) {
                snprintf(tmp42,0x800,"chip %d CORE[%03d] 0x%08x %02x \n",(uint)(bVar1 >> 1),uVar4,
                         uVar3,(uint)core_hash_clock_delay_control[chain][chip_addr >> 1][uVar4]);
                _applog(5,tmp42,false);
              }
            }
            else if (check_core_register == 6) {
              core_hash_clock_counter[chain][bVar1 >> 1][uVar3 >> 0x18] = uVar3;
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,
                         "chain[%02d] chip[%02d] core[%02d] hash clock counter is 0x%08x",
                         (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number,
                         (uint)(bVar1 >> 1),uVar3 >> 0x18,uVar3 & 0xff);
                _applog(5,tmp42,false);
              }
            }
            else if (check_core_register == 5) {
              core_hash_clock_control[chain][0][uVar3 >> 0x18] = uVar3;
            }
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: chip %x reg %x reg_buff %x","check_asic_reg_with_addr_test",
                     (uint)bVar1,reg,uVar3);
            _applog(7,tmp42,false);
          }
          reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
          if (0x1fe < reg_value_buf.p_rd) {
            reg_value_buf.p_rd = 0;
          }
          if (reg == 0x1c) {
            if ((uVar3 & 0xc0000000) == 0) {
              pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
              clear_register_value_buf();
              return uVar3;
            }
            pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
            clear_register_value_buf();
            return 0;
          }
        }
        else {
          reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
          if (0x1fe < reg_value_buf.p_rd) {
            reg_value_buf.p_rd = 0;
          }
        }
      }
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    }
    if (check_num <= get_num) {
      clear_register_value_buf();
      return 0;
    }
    if (get_num == last_get_num) {
      no_reg_time = no_reg_time + 1;
    }
    if (5 < no_reg_time) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: no reg time %d, return\n","check_asic_reg_with_addr_test",
                 no_reg_time);
        _applog(7,tmp42,false);
      }
      return 0;
    }
    last_get_num = get_num;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: last_get =%d, get=%d\n","check_asic_reg_with_addr_test",get_num,
               get_num);
      _applog(7,tmp42,false);
    }
  } while( true );
}

