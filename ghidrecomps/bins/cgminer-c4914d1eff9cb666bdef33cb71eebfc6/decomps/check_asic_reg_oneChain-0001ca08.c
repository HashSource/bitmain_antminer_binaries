
/* WARNING: Type propagation algorithm not settling */

_Bool check_asic_reg_oneChain(int chainIndex,uint reg,_Bool core_response)

{
  uint uVar1;
  uchar uVar2;
  byte bVar3;
  FILE *pFVar4;
  uint uVar5;
  uint uVar6;
  char *buf;
  uint bufsiz;
  bool bVar7;
  double dVar8;
  _Bool core_response_local;
  uint reg_local;
  int chainIndex_local;
  char displayed_rate_asic [32];
  uint8_t rate_buf [10];
  uchar reg_buf [7];
  FILE *pFile_9;
  FILE *pFile;
  FILE *pFile_8;
  FILE *pFile_1;
  FILE *pFile_7;
  FILE *pFile_6;
  uint64_t temp_hash_rate;
  FILE *pFile_3;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  uint reg_value;
  int i;
  uint reg_value_num;
  int ii;
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
  reg_buf[5] = '\0';
  reg_buf[6] = '\0';
  reg_address = '\0';
rerun_all:
  if (!core_response) {
    clear_register_value_buf();
  }
  reg_processed_counter = 0;
  read_num = 0;
  if (dev->chain_exist[chainIndex] != 1) {
    return true;
  }
  tmp_rate._0_4_ = (char *)0x0;
  tmp_rate._4_4_ = 0;
  if (!core_response) {
    read_asic_register((uchar)chainIndex,'\x01','\0',(uchar)reg);
  }
  if (reg == 0) {
    dev->chain_asic_num[chainIndex] = '\0';
  }
  do {
    if (2 < not_reg_data_time) {
LAB_0001d43a:
      if ((reg_address == '\0') &&
         (dev->max_asic_num_in_one_chain < dev->chain_asic_num[chainIndex])) {
        dev->max_asic_num_in_one_chain = dev->chain_asic_num[chainIndex];
      }
      if (read_num == (uint)dev->chain_asic_num[chainIndex]) {
        *(char **)(rate + chainIndex) = (char *)tmp_rate;
        *(int *)((int)rate + chainIndex * 8 + 4) = tmp_rate._4_4_;
        suffix_string_soc(6,*(char **)(rate + chainIndex),
                          *(size_t *)((int)rate + chainIndex * 8 + 4),
                          (int)(displayed_rate + chainIndex),true);
        rate_error[chainIndex] = 0;
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar4 = fopen(log_file,"a+");
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: chain %d hashrate is %s\n","driver-btm-soc.c",0x780,
                    "check_asic_reg_oneChain",chainIndex,displayed_rate + chainIndex);
          }
          fclose(pFVar4);
        }
      }
      if (((read_num == 0) || (status_error != false)) &&
         ((rate_error[chainIndex] = rate_error[chainIndex] + 1, 3 < rate_error[chainIndex] ||
          (status_error != false)))) {
        *(undefined4 *)(rate + chainIndex) = 0;
        *(undefined4 *)((int)rate + chainIndex * 8 + 4) = 0;
        suffix_string_soc(6,*(char **)(rate + chainIndex),
                          *(size_t *)((int)rate + chainIndex * 8 + 4),
                          (int)(displayed_rate + chainIndex),true);
      }
      clear_register_value_buf();
      return (_Bool)1;
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
      reg_processed_counter = reg_value_buf.reg_value_num + reg_processed_counter;
      if (600 < reg_processed_counter) {
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        return false;
      }
      not_reg_data_time = 0;
      for (j = 0; (uint)j < uVar1; j = j + 1) {
        uVar6 = read_num;
        if (chainIndex == (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) {
          reg_buf[3] = (uchar)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
          reg_buf[2] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
          reg_buf[1] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
          reg_buf[0] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x18);
          reg_address = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
          uVar5 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
          uVar2 = CRC5(reg_buf,'3');
          if (uVar2 == reg_value_buf.reg_buffer[reg_value_buf.p_rd].crc) {
            reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
            reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
            if (0x1fe < reg_value_buf.p_rd) {
              reg_value_buf.p_rd = 0;
            }
            switch(reg_address) {
            case '\0':
              if (uVar5 >> 0x10 == 0x1393) {
                dev->chain_asic_num[chainIndex] = dev->chain_asic_num[chainIndex] + '\x01';
              }
              if (4 < log_level) {
                print_crt_time_to_file(log_file,4);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,"%s:%d:%s: chain[%02d] num[%d]: the asic CHIP_ADDRESS is 0x%08x\n",
                          "driver-btm-soc.c",0x725,"check_asic_reg_oneChain",chainIndex,j,uVar5);
                }
                fclose(pFVar4);
              }
              break;
            default:
              if (3 < log_level) {
                print_crt_time_to_file(log_file,3);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,
                          "%s:%d:%s: chain[%02d] num[%d]: the register  %02x value is 0x%08x\n",
                          "driver-btm-soc.c",0x757,"check_asic_reg_oneChain",chainIndex,j,
                          (uint)reg_address,uVar5);
                }
                fclose(pFVar4);
              }
              break;
            case '\x04':
              uVar6 = read_num + 1;
              if ((int)uVar6 < 0x3d) {
                for (ii = 0; ii < 4; ii = ii + 1) {
                  sprintf((char *)(rate_buf + ii * 2),"%02x",(uint)reg_buf[ii]);
                }
                uVar5 = strtol((char *)rate_buf,(char **)0x0,0x10);
                bufsiz = ((int)uVar5 >> 0x1f) << 0x18 | uVar5 >> 8;
                buf = (char *)(uVar5 * 0x1000000);
                bVar7 = CARRY4((uint)(char *)tmp_rate,(uint)buf);
                tmp_rate._0_4_ = (char *)tmp_rate + (int)buf;
                tmp_rate._4_4_ = tmp_rate._4_4_ + bufsiz + bVar7;
                suffix_string_soc(6,buf,bufsiz,(int)displayed_rate_asic,true);
                if (3 < log_level) {
                  print_crt_time_to_file(log_file,3);
                  pFVar4 = fopen(log_file,"a+");
                  if (pFVar4 != (FILE *)0x0) {
                    fprintf(pFVar4,"%s:%d:%s: Asic[%02d]=%s ","driver-btm-soc.c",0x74c,
                            "check_asic_reg_oneChain",uVar6,displayed_rate_asic);
                  }
                  fclose(pFVar4);
                }
                dVar8 = atof(displayed_rate_asic);
                chain_asic_RT[chainIndex][read_num] = dVar8;
                if ((((uVar6 & 7) == 0) || (uVar6 == 0x3c)) && (3 < log_level)) {
                  print_crt_time_to_file(log_file,3);
                  pFVar4 = fopen(log_file,"a+");
                  if (pFVar4 != (FILE *)0x0) {
                    fprintf(pFVar4,"%s:%d:%s: \n","driver-btm-soc.c",0x752,"check_asic_reg_oneChain"
                           );
                  }
                  fclose(pFVar4);
                }
              }
              break;
            case '\b':
              if (3 < log_level) {
                print_crt_time_to_file(log_file,3);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,"%s:%d:%s: chain[%d]: the asic freq is 0x%x\n","driver-btm-soc.c",
                          0x72b,"check_asic_reg_oneChain",chainIndex,uVar5);
                }
                fclose(pFVar4);
              }
              break;
            case '\x10':
              uVar6 = read_num + 1;
              if (3 < log_level) {
                print_crt_time_to_file(log_file,3);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,
                          "%s:%d:%s: chain[%02d] chip[%02d]: the asic HASH_COUNTING_NUMBER is 0x%08x\n"
                          ,"driver-btm-soc.c",0x733,"check_asic_reg_oneChain",chainIndex,uVar6,uVar5
                         );
                }
                fclose(pFVar4);
              }
              break;
            case '\x14':
              uVar6 = read_num + 1;
              if (3 < log_level) {
                print_crt_time_to_file(log_file,3);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,
                          "%s:%d:%s: chain[%02d] chip[%02d]: the asic TICKET_MASK is 0x%08x\n",
                          "driver-btm-soc.c",0x72f,"check_asic_reg_oneChain",chainIndex,uVar6,uVar5)
                  ;
                }
                fclose(pFVar4);
              }
              break;
            case '\x18':
              if (4 < log_level) {
                print_crt_time_to_file(log_file,4);
                pFVar4 = fopen(log_file,"a+");
                if (pFVar4 != (FILE *)0x0) {
                  fprintf(pFVar4,"%s:%d:%s: chain[%02d] chip[%02d]: the misc is 0x%08x\n",
                          "driver-btm-soc.c",0x728,"check_asic_reg_oneChain",chainIndex,read_num,
                          uVar5);
                }
                fclose(pFVar4);
              }
            }
          }
          else {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFVar4 = fopen(log_file,"a+");
              if (pFVar4 != (FILE *)0x0) {
                bVar3 = CRC5(reg_buf,'#');
                fprintf(pFVar4,"%s:%d:%s: crc is 0x%x, but it should be 0x%x\n","driver-btm-soc.c",
                        0x70d,"check_asic_reg_oneChain",(uint)bVar3,
                        (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].crc);
              }
              fclose(pFVar4);
            }
            reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
            reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
            if (0x1fe < reg_value_buf.p_rd) {
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
        read_num = uVar6;
      }
      if ((reg_address == '\0') && (dev->chain_asic_num[chainIndex] == '<')) {
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        goto LAB_0001d43a;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  } while( true );
  not_reg_data_time = not_reg_data_time + 1;
  pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  goto rerun_all;
}

