
_Bool check_single_asic_reg(uint reg)

{
  reg_content *prVar1;
  uint uVar2;
  byte bVar3;
  FILE *__stream;
  uint reg_local;
  uchar reg_buf [7];
  FILE *pFile;
  uchar crc_value;
  uchar reg_address;
  int reg_value;
  uint reg_value_num;
  int reg_processed_counter;
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
rerun_all:
  clear_register_value_buf();
  i = 0;
  do {
    if (0xf < i) {
      return true;
    }
    reg_processed_counter = 0;
    if (dev->chain_exist[i] == 1) {
      read_asic_register((uchar)i,'\0','\0',(uchar)reg);
      while (not_reg_data_time < 3) {
        cgsleep_ms(300);
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        uVar2 = reg_value_buf.reg_value_num;
        if (((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) &&
           (not_reg_data_time < 3)) {
          not_reg_data_time = not_reg_data_time + 1;
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          goto rerun_all;
        }
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
          for (j = 0; (uint)j < uVar2; j = j + 1) {
            if (i == (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) {
              reg_buf[3] = (uchar)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_buf[2] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
              reg_buf[1] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
              reg_buf[0] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x18);
              reg_buf[4] = reg_value_buf.reg_buffer[reg_value_buf.p_rd].chip_address;
              reg_buf[5] = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
              reg_buf[6] = '\0';
              bVar3 = CRC5(reg_buf,'3');
              if (bVar3 == reg_value_buf.reg_buffer[reg_value_buf.p_rd].crc) {
                bVar3 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
                prVar1 = reg_value_buf.reg_buffer + reg_value_buf.p_rd;
                reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
                reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
                if (0x1fe < reg_value_buf.p_rd) {
                  reg_value_buf.p_rd = 0;
                }
                g_asic_data[i][bVar3] = prVar1->reg_value;
                g_asic_data_status[i][bVar3] = '\x01';
              }
              else {
                if (4 < log_level) {
                  print_crt_time_to_file(log_file,4);
                  __stream = fopen(log_file,"a+");
                  if (__stream != (FILE *)0x0) {
                    fprintf(__stream,"%s:%d:%s: crc is 0x%x, but it should be 0x%x\n",
                            "driver-btm-soc.c",0xacf,"check_single_asic_reg",(uint)bVar3,
                            (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].crc);
                  }
                  fclose(__stream);
                }
                reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
                reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
                if (reg_value_buf.p_rd == 0x1ff) {
                  reg_value_buf.p_rd = 0;
                }
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
        }
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      }
      not_reg_data_time = 0;
      clear_register_value_buf();
    }
    i = i + 1;
  } while( true );
}

