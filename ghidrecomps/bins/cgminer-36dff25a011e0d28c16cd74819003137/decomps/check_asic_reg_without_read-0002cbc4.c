
uint check_asic_reg_without_read(uint reg,uchar mode,uchar chip_addr,uint chain,int check_num)

{
  byte bVar1;
  uint uVar2;
  FILE *pFVar3;
  uint uVar4;
  uint uVar5;
  uint chain_local;
  uchar chip_addr_local;
  uchar mode_local;
  uint reg_local;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  int core_id;
  FILE *pFile;
  uint reg_value_num;
  FILE *pFile_4;
  FILE *pFile_5;
  uchar chip_address;
  uint reg_buf;
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
  cc = 0;
rerun:
  do {
    cgsleep_ms(0x50);
    while (not_reg_data_time < 5) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar2 = reg_value_buf.reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: reg_value_num %d\n","driver-btm-soc.c",0x18b4,
                  "check_asic_reg_without_read",uVar2);
        }
        fclose(pFVar3);
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
        uVar4 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
        bVar1 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].chip_address;
        if (chain == reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) {
          if (reg == 0x40) {
            if (is_dump_asic_reg_all == false) {
              uVar5 = uVar4 >> 0x10 & 0xff00;
              core_hash_clock_delay_control[chain][bVar1 / 5][uVar5].v = (uint8_t)uVar4;
              if ((cc < 10) && (cc = cc + 1, 3 < log_level)) {
                print_crt_time_to_file(log_file,3);
                pFVar3 = fopen(log_file,"a+");
                if (pFVar3 != (FILE *)0x0) {
                  fprintf(pFVar3,"%s:%d:%s: chip %d CORE[%03d] 0x%08x %02x\n","driver-btm-soc.c",
                          0x18e3,"check_asic_reg_without_read",bVar1 / 5,uVar5,uVar4,
                          (uint)core_hash_clock_delay_control[chain][bVar1 / 5][uVar5].v);
                }
                fclose(pFVar3);
              }
              if (((uVar4 & 0xff) != 0x80) && (3 < log_level)) {
                print_crt_time_to_file(log_file,3);
                pFVar3 = fopen(log_file,"a+");
                if (pFVar3 != (FILE *)0x0) {
                  fprintf(pFVar3,
                          "%s:%d:%s: chain[%02d] chip[%02d] core[%d] clock delay control is 0x%08x\n"
                          ,"driver-btm-soc.c",0x18e9,"check_asic_reg_without_read",
                          (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number,bVar1 / 5,
                          uVar5,(uint)core_hash_clock_delay_control[chain][bVar1 / 5][uVar5].v);
                }
                fclose(pFVar3);
              }
            }
            else {
              g_asic_core_data[chain][0] = uVar4 & 0xff;
              g_asic_core_data_status[chain][0] = '\x01';
            }
          }
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"%s:%d:%s: chip %x reg %x reg_buff %x\n","driver-btm-soc.c",0x18ed,
                      "check_asic_reg_without_read",(uint)bVar1,reg,uVar4);
            }
            fclose(pFVar3);
          }
          reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
          if (0x1fe < reg_value_buf.p_rd) {
            reg_value_buf.p_rd = 0;
          }
          if (reg == 0x1c) {
            if ((uVar4 & 0xc0000000) == 0) {
              pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
              clear_register_value_buf();
              return uVar4;
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
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: no reg time %d, return\n","driver-btm-soc.c",0x1916,
                  "check_asic_reg_without_read",no_reg_time);
        }
        fclose(pFVar3);
      }
      return 0;
    }
    last_get_num = get_num;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: last_get =%d, get=%d\n","driver-btm-soc.c",0x191a,
                "check_asic_reg_without_read",get_num,get_num);
      }
      fclose(pFVar3);
    }
  } while( true );
}

