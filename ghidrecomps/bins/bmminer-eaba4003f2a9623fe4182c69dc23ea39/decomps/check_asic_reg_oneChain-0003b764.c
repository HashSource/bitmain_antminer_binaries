
_Bool check_asic_reg_oneChain(int chainIndex,uint reg)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint reg_local;
  int chainIndex_local;
  char tmp42 [2048];
  uchar displayed_rate [16];
  uchar rate_buf [10];
  char logstr [1024];
  uchar reg_buf [5];
  uint buf [2];
  uint64_t temp_hash_rate;
  int i;
  uint temp_nonce;
  uint reg_value_num;
  int nonce_number;
  int i_1;
  uchar reg_address;
  int reg_processed_counter;
  uint64_t tmp_rate;
  int read_num;
  int not_reg_data_time;
  int j;
  
  not_reg_data_time = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
rerun_all:
  clear_register_value_buf();
  reg_processed_counter = 0;
  read_num = 0;
  if (dev->chain_exist[chainIndex] != 1) {
    return true;
  }
  tmp_rate._0_4_ = 0;
  tmp_rate._4_4_ = 0;
  read_asic_register((uchar)chainIndex,'\x01','\0',(uchar)reg);
  if (reg == 0) {
    dev->chain_asic_num[chainIndex] = '\0';
  }
  do {
    if (2 < not_reg_data_time) {
LAB_0003bcba:
      if ((reg_address == '\0') &&
         (dev->max_asic_num_in_one_chain < dev->chain_asic_num[chainIndex])) {
        dev->max_asic_num_in_one_chain = dev->chain_asic_num[chainIndex];
      }
      if ((uint)dev->chain_asic_num[chainIndex] == read_num) {
        *(uint *)(rate + chainIndex) = (uint)tmp_rate;
        *(int *)((int)rate + chainIndex * 8 + 4) = tmp_rate._4_4_;
        suffix_string_soc(6,*(char **)(rate + chainIndex),
                          *(size_t *)((int)rate + chainIndex * 8 + 4),
                          (int)(::displayed_rate + chainIndex),true);
        rate_error[chainIndex] = 0;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: chain %d hashrate is %s\n","check_asic_reg_oneChain",chainIndex,
                   ::displayed_rate + chainIndex);
          _applog(7,tmp42,false);
        }
      }
      if (((read_num == 0) || (status_error != false)) &&
         ((rate_error[chainIndex] = rate_error[chainIndex] + 1, 3 < rate_error[chainIndex] ||
          (status_error != false)))) {
        *(undefined4 *)(rate + chainIndex) = 0;
        *(undefined4 *)((int)rate + chainIndex * 8 + 4) = 0;
        suffix_string_soc(6,*(char **)(rate + chainIndex),
                          *(size_t *)((int)rate + chainIndex * 8 + 4),
                          (int)(::displayed_rate + chainIndex),true);
      }
      clear_register_value_buf();
      return true;
    }
    cgsleep_ms(300);
    pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
    uVar1 = reg_value_buf.reg_value_num;
    if (((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) &&
       (not_reg_data_time < 3)) break;
    if (not_reg_data_time == 3) {
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      return true;
    }
    if (reg_value_buf.reg_value_num == 0) {
      cgsleep_ms(100);
      not_reg_data_time = not_reg_data_time + 1;
    }
    else {
      reg_processed_counter = reg_processed_counter + reg_value_buf.reg_value_num;
      if (600 < reg_processed_counter) {
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        return false;
      }
      not_reg_data_time = 0;
      for (j = 0; (uint)j < uVar1; j = j + 1) {
        if ((uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number == chainIndex) {
          reg_buf[3] = (uchar)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
          reg_buf[2] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
          reg_buf[1] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
          reg_buf[0] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x18);
          reg_address = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
          reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
          if (0x1fe < reg_value_buf.p_rd) {
            reg_value_buf.p_rd = 0;
          }
          if (reg_address == '\0') {
            dev->chain_asic_num[chainIndex] = dev->chain_asic_num[chainIndex] + '\x01';
          }
          if (((reg_address == '\b') && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            snprintf(tmp42,0x800,"%s: the asic freq is 0x%x\n","check_asic_reg_oneChain",
                     reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
            _applog(7,tmp42,false);
          }
          if (reg == 8) {
            for (i_1 = 0; i_1 < 4; i_1 = i_1 + 1) {
              sprintf((char *)(rate_buf + i_1 * 2),"%02x",(uint)reg_buf[i_1]);
            }
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: hashrate is %s\n","check_asic_reg_oneChain",rate_buf);
              _applog(7,tmp42,false);
            }
            uVar2 = strtol((char *)rate_buf,(char **)0x0,0x10);
            bVar3 = CARRY4(uVar2 * 0x1000000,(uint)tmp_rate);
            tmp_rate._0_4_ = uVar2 * 0x1000000 + (uint)tmp_rate;
            tmp_rate._4_4_ =
                 (((int)uVar2 >> 0x1f) << 0x18 | uVar2 >> 8) + tmp_rate._4_4_ + (uint)bVar3;
            read_num = read_num + 1;
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
      if ((reg_address == '\0') && (dev->chain_asic_num[chainIndex] == 'l')) {
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        goto LAB_0003bcba;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  } while( true );
  not_reg_data_time = not_reg_data_time + 1;
  pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  goto rerun_all;
}

