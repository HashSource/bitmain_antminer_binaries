
_Bool check_asic_reg(uint reg)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;
  uint reg_local;
  char displayed_rate_asic [32];
  char tmp42 [2048];
  uchar displayed_rate [16];
  uchar rate_buf [10];
  char logstr [1024];
  uchar reg_buf [7];
  uint buf [2];
  uint64_t temp_hash_rate;
  uchar crc_value;
  int reg_value;
  uint temp_nonce;
  uint reg_value_num;
  int nonce_number;
  int ii;
  int reg_processed_counter;
  uint64_t tmp_rate;
  uchar reg_address;
  int read_num;
  int not_reg_data_time;
  int j;
  int i;
  
  not_reg_data_time = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
  reg_buf[5] = '\0';
  reg_buf[6] = '\0';
  reg_address = '\0';
LAB_0003aaf0:
  clear_register_value_buf();
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) &&
       (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
      snprintf(tmp42,0x800,"+Check asic reg, chain[%d] exist\n",i);
      _applog(5,tmp42,false);
    }
  }
  i = 0;
  do {
    if (0xf < i) {
      return true;
    }
    reg_processed_counter = 0;
    read_num = 0;
    if (dev->chain_exist[i] == 1) {
      tmp_rate._0_4_ = 0;
      tmp_rate._4_4_ = 0;
      read_asic_register((uchar)i,'\x01','\0',(uchar)reg);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"!!Check asic reg, read asic chain[%d], reg=0x%x\n",i,reg);
        _applog(5,tmp42,false);
      }
      if (reg == 0) {
        dev->chain_asic_num[i] = '\0';
      }
      if ((reg == 8) &&
         (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"\nget RT hashrate from Chain[%d]: (asic index start from 1-%d)\n",i,
                 0x6c);
        _applog(5,tmp42,false);
      }
      while (not_reg_data_time < 3) {
        cgsleep_ms(300);
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        uVar1 = reg_value_buf.reg_value_num;
        if (((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) &&
           (not_reg_data_time < 3)) {
          not_reg_data_time = not_reg_data_time + 1;
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"!!not_reg_data_time ++\n",0x18);
            _applog(5,tmp42,false);
          }
          goto LAB_0003aaf0;
        }
        if (not_reg_data_time == 3) {
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"!!not_reg_data_time is 3, return",0x20);
            tmp42[0x20] = '\n';
            tmp42[0x21] = '\0';
            _applog(5,tmp42,false);
          }
          return true;
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"!!reg_value_num = %d\n",reg_value_buf.reg_value_num);
          _applog(5,tmp42,false);
        }
        if (uVar1 == 0) {
          cgsleep_ms(100);
          not_reg_data_time = not_reg_data_time + 1;
        }
        else {
          reg_processed_counter = reg_processed_counter + uVar1;
          if (600 < reg_processed_counter) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"read asic reg Error on Chain[%d]\n",i);
              _applog(5,tmp42,false);
            }
            pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
            return false;
          }
          not_reg_data_time = 0;
          for (j = 0; (uint)j < uVar1; j = j + 1) {
            if ((uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number == i) {
              reg_buf[0] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x18);
              reg_buf[1] = (char)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
              reg_buf[2] = (char)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
              reg_buf[3] = (char)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_address = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
              uVar3 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
              reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
              if (0x1fe < reg_value_buf.p_rd) {
                reg_value_buf.p_rd = 0;
              }
              if (reg_address == '\0') {
                if ((int)uVar3 >> 0x10 == 0x1393) {
                  dev->chain_asic_num[i] = dev->chain_asic_num[i] + '\x01';
                }
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"chain[%02d] num[%d]: the asic CHIP_ADDRESS is 0x%08x\n",i,j,
                           uVar3);
                  _applog(7,tmp42,false);
                }
              }
              if ((reg_address == '\b') &&
                 (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
                snprintf(tmp42,0x800,"chain[%d]: the asic freq is 0x%x\n",i,
                         reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
                _applog(5,tmp42,false);
              }
              if ((reg_address == '\x14') &&
                 (((read_num = read_num + 1, use_syslog != false || (opt_log_output != false)) ||
                  (4 < opt_log_level)))) {
                snprintf(tmp42,0x800,"chain[%02d] chip[%02d]: the asic TICKET_MASK is 0x%08x\n",i,
                         read_num,reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
                _applog(5,tmp42,false);
              }
              if ((reg_address == '\x10') &&
                 (((read_num = read_num + 1, use_syslog != false || (opt_log_output != false)) ||
                  (4 < opt_log_level)))) {
                snprintf(tmp42,0x800,
                         "chain[%02d] chip[%02d]: the asic HASH_COUNTING_NUMBER is 0x%08x\n",i,
                         read_num,reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
                _applog(5,tmp42,false);
              }
              if ((reg_address == '\x10') &&
                 (((read_num = read_num + 1, use_syslog != false || (opt_log_output != false)) ||
                  (4 < opt_log_level)))) {
                snprintf(tmp42,0x800,
                         "chain[%02d] chip[%02d]: the asic START_NONCE_OFFSET is 0x%08x\n",i,
                         read_num,reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
                _applog(5,tmp42,false);
              }
              uVar3 = read_num;
              if ((reg_address == '\x04') && (uVar3 = read_num + 1, (int)uVar3 < 0x6d)) {
                for (ii = 0; ii < 4; ii = ii + 1) {
                  sprintf((char *)(rate_buf + ii * 2),"%02x",(uint)reg_buf[ii]);
                }
                uVar2 = strtol((char *)rate_buf,(char **)0x0,0x10);
                uVar4 = ((int)uVar2 >> 0x1f) << 0x18 | uVar2 >> 8;
                uVar2 = uVar2 * 0x1000000;
                bVar5 = CARRY4(uVar2,(uint)tmp_rate);
                tmp_rate._0_4_ = uVar2 + (uint)tmp_rate;
                tmp_rate._4_4_ = uVar4 + tmp_rate._4_4_ + (uint)bVar5;
                suffix_string_soc(CONCAT44(uVar4,uVar2),displayed_rate_asic,0x20,6,false);
                if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Asic[%02d]=%s ",uVar3,displayed_rate_asic);
                  _applog(5,tmp42,false);
                }
                dVar6 = atof(displayed_rate_asic);
                chain_asic_RT[i][read_num] = dVar6;
                if ((((uVar3 & 7) == 0) || (uVar3 == 0x6c)) &&
                   ((use_syslog != false || ((opt_log_output != false || (4 < opt_log_level)))))) {
                  tmp42[0] = '\n';
                  tmp42[1] = '\0';
                  _applog(5,tmp42,false);
                }
              }
            }
            else {
              reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
              reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
              uVar3 = read_num;
              if (0x1fe < reg_value_buf.p_rd) {
                reg_value_buf.p_rd = 0;
              }
            }
            read_num = uVar3;
          }
          if ((reg_address == '\0') && (dev->chain_asic_num[i] == 'l')) {
            pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
            if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
              snprintf(tmp42,0x800,"!!chain_asic_num[%d] is CHAIN_ASIC_NUM\n",i);
              _applog(5,tmp42,false);
            }
            break;
          }
        }
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      }
      not_reg_data_time = 0;
      if ((reg == 0) && (dev->max_asic_num_in_one_chain < dev->chain_asic_num[i])) {
        dev->max_asic_num_in_one_chain = dev->chain_asic_num[i];
      }
      if ((uint)dev->chain_asic_num[i] == read_num) {
        *(uint *)(rate + i) = (uint)tmp_rate;
        *(int *)((int)rate + i * 8 + 4) = tmp_rate._4_4_;
        suffix_string_soc(rate[i],::displayed_rate[i],0x20,6,false);
        rate_error[i] = 0;
      }
      if (((read_num == 0) || (status_error != false)) &&
         ((rate_error[i] = rate_error[i] + 1, 3 < rate_error[i] || (status_error != false)))) {
        *(undefined4 *)(rate + i) = 0;
        *(undefined4 *)((int)rate + i * 8 + 4) = 0;
        suffix_string_soc(rate[i],::displayed_rate[i],0x20,6,false);
      }
      clear_register_value_buf();
    }
    i = i + 1;
  } while( true );
}

