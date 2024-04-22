
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool check_asic_reg(uint reg)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *buf_00;
  uint bufsiz;
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
rerun_all:
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
      tmp_rate._0_4_ = (char *)0x0;
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
        uVar2 = reg_value_buf.reg_value_num;
        if (((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) &&
           (not_reg_data_time < 3)) {
          not_reg_data_time = not_reg_data_time + 1;
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s___not_reg_data_time____000770b4[0];
            tmp42[1] = s___not_reg_data_time____000770b4[1];
            tmp42[2] = s___not_reg_data_time____000770b4[2];
            tmp42[3] = s___not_reg_data_time____000770b4[3];
            tmp42[4] = s___not_reg_data_time____000770b4[4];
            tmp42[5] = s___not_reg_data_time____000770b4[5];
            tmp42[6] = s___not_reg_data_time____000770b4[6];
            tmp42[7] = s___not_reg_data_time____000770b4[7];
            tmp42[8] = s___not_reg_data_time____000770b4[8];
            tmp42[9] = s___not_reg_data_time____000770b4[9];
            tmp42[10] = s___not_reg_data_time____000770b4[10];
            tmp42[11] = s___not_reg_data_time____000770b4[11];
            tmp42[12] = s___not_reg_data_time____000770b4[12];
            tmp42[13] = s___not_reg_data_time____000770b4[13];
            tmp42[14] = s___not_reg_data_time____000770b4[14];
            tmp42[15] = s___not_reg_data_time____000770b4[15];
            tmp42[16] = s___not_reg_data_time____000770b4[16];
            tmp42[17] = s___not_reg_data_time____000770b4[17];
            tmp42[18] = s___not_reg_data_time____000770b4[18];
            tmp42[19] = s___not_reg_data_time____000770b4[19];
            tmp42[20] = s___not_reg_data_time____000770b4[20];
            tmp42[21] = s___not_reg_data_time____000770b4[21];
            tmp42[22] = s___not_reg_data_time____000770b4[22];
            tmp42[23] = s___not_reg_data_time____000770b4[23];
            _applog(5,tmp42,false);
          }
          goto rerun_all;
        }
        if (not_reg_data_time == 3) {
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s___not_reg_data_time_is_3__return_000770cc[0];
            tmp42[1] = s___not_reg_data_time_is_3__return_000770cc[1];
            tmp42[2] = s___not_reg_data_time_is_3__return_000770cc[2];
            tmp42[3] = s___not_reg_data_time_is_3__return_000770cc[3];
            tmp42[4] = s___not_reg_data_time_is_3__return_000770cc[4];
            tmp42[5] = s___not_reg_data_time_is_3__return_000770cc[5];
            tmp42[6] = s___not_reg_data_time_is_3__return_000770cc[6];
            tmp42[7] = s___not_reg_data_time_is_3__return_000770cc[7];
            tmp42[8] = s___not_reg_data_time_is_3__return_000770cc[8];
            tmp42[9] = s___not_reg_data_time_is_3__return_000770cc[9];
            tmp42[10] = s___not_reg_data_time_is_3__return_000770cc[10];
            tmp42[11] = s___not_reg_data_time_is_3__return_000770cc[11];
            tmp42[12] = s___not_reg_data_time_is_3__return_000770cc[12];
            tmp42[13] = s___not_reg_data_time_is_3__return_000770cc[13];
            tmp42[14] = s___not_reg_data_time_is_3__return_000770cc[14];
            tmp42[15] = s___not_reg_data_time_is_3__return_000770cc[15];
            tmp42[16] = s___not_reg_data_time_is_3__return_000770cc[16];
            tmp42[17] = s___not_reg_data_time_is_3__return_000770cc[17];
            tmp42[18] = s___not_reg_data_time_is_3__return_000770cc[18];
            tmp42[19] = s___not_reg_data_time_is_3__return_000770cc[19];
            tmp42[20] = s___not_reg_data_time_is_3__return_000770cc[20];
            tmp42[21] = s___not_reg_data_time_is_3__return_000770cc[21];
            tmp42[22] = s___not_reg_data_time_is_3__return_000770cc[22];
            tmp42[23] = s___not_reg_data_time_is_3__return_000770cc[23];
            tmp42[24] = s___not_reg_data_time_is_3__return_000770cc[24];
            tmp42[25] = s___not_reg_data_time_is_3__return_000770cc[25];
            tmp42[26] = s___not_reg_data_time_is_3__return_000770cc[26];
            tmp42[27] = s___not_reg_data_time_is_3__return_000770cc[27];
            tmp42[28] = s___not_reg_data_time_is_3__return_000770cc[28];
            tmp42[29] = s___not_reg_data_time_is_3__return_000770cc[29];
            tmp42[30] = s___not_reg_data_time_is_3__return_000770cc[30];
            tmp42[31] = s___not_reg_data_time_is_3__return_000770cc[31];
            tmp42._32_2_ = (undefined2)ram0x000770ec;
            _applog(5,tmp42,false);
          }
          return true;
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"!!reg_value_num = %d\n",reg_value_buf.reg_value_num);
          _applog(5,tmp42,false);
        }
        if (uVar2 == 0) {
          cgsleep_ms(100);
          not_reg_data_time = not_reg_data_time + 1;
        }
        else {
          reg_processed_counter = reg_processed_counter + uVar2;
          if (600 < reg_processed_counter) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"read asic reg Error on Chain[%d]\n",i);
              _applog(5,tmp42,false);
            }
            pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
            return false;
          }
          not_reg_data_time = 0;
          for (j = 0; (uint)j < uVar2; j = j + 1) {
            if ((uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number == i) {
              uVar1._3_1_ = (char)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              uVar1._2_1_ = (char)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
              uVar1._1_1_ = (char)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
              uVar1._0_1_ = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x18);
              reg_buf[0] = (uchar)uVar1;
              reg_buf[1] = SUB41(uVar1,1);
              reg_buf[2] = SUB41(uVar1,2);
              reg_buf[3] = SUB41(uVar1,3);
              reg_address = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
              uVar4 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
              reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
              if (0x1fe < reg_value_buf.p_rd) {
                reg_value_buf.p_rd = 0;
              }
              if (reg_address == '\0') {
                if ((int)uVar4 >> 0x10 == 0x1393) {
                  dev->chain_asic_num[i] = dev->chain_asic_num[i] + '\x01';
                }
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"chain[%02d] num[%d]: the asic CHIP_ADDRESS is 0x%08x\n",i,j,
                           uVar4);
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
              uVar4 = read_num;
              if ((reg_address == '\x04') && (uVar4 = read_num + 1, (int)uVar4 < 0x6d)) {
                for (ii = 0; ii < 4; ii = ii + 1) {
                  sprintf((char *)(rate_buf + ii * 2),"%02x",(uint)reg_buf[ii]);
                }
                uVar3 = strtol((char *)rate_buf,(char **)0x0,0x10);
                bufsiz = ((int)uVar3 >> 0x1f) << 0x18 | uVar3 >> 8;
                buf_00 = (char *)(uVar3 * 0x1000000);
                bVar5 = CARRY4((uint)buf_00,(uint)(char *)tmp_rate);
                tmp_rate._0_4_ = buf_00 + (int)(char *)tmp_rate;
                tmp_rate._4_4_ = bufsiz + tmp_rate._4_4_ + (uint)bVar5;
                suffix_string_soc(6,buf_00,bufsiz,(int)displayed_rate_asic,true);
                if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Asic[%02d]=%s ",uVar4,displayed_rate_asic);
                  _applog(5,tmp42,false);
                }
                dVar6 = atof(displayed_rate_asic);
                chain_asic_RT[i][read_num] = dVar6;
                if ((((uVar4 & 7) == 0) || (uVar4 == 0x6c)) &&
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
              uVar4 = read_num;
              if (0x1fe < reg_value_buf.p_rd) {
                reg_value_buf.p_rd = 0;
              }
            }
            read_num = uVar4;
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
        *(char **)(rate + i) = (char *)tmp_rate;
        *(int *)((int)rate + i * 8 + 4) = tmp_rate._4_4_;
        suffix_string_soc(6,*(char **)(rate + i),*(size_t *)((int)rate + i * 8 + 4),
                          (int)(::displayed_rate + i),true);
        rate_error[i] = 0;
      }
      if (((read_num == 0) || (status_error != false)) &&
         ((rate_error[i] = rate_error[i] + 1, 3 < rate_error[i] || (status_error != false)))) {
        *(undefined4 *)(rate + i) = 0;
        *(undefined4 *)((int)rate + i * 8 + 4) = 0;
        suffix_string_soc(6,*(char **)(rate + i),*(size_t *)((int)rate + i * 8 + 4),
                          (int)(::displayed_rate + i),true);
      }
      clear_register_value_buf();
    }
    i = i + 1;
  } while( true );
}

