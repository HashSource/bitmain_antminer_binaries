
uint check_asic_reg_with_addr(uint reg,uchar chip_addr,uint chain,int check_num)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  int check_num_local;
  uint chain_local;
  uchar chip_addr_local;
  uint reg_local;
  FILE *pFile_1;
  FILE *pFile;
  uint reg_buf;
  uint reg_value_num;
  int not_reg_data_time;
  int i;
  
  not_reg_data_time = 0;
  i = chain;
  do {
    clear_register_value_buf();
    read_asic_register((uchar)i,'\0',chip_addr,(uchar)reg);
    cgsleep_ms(0x14);
    while( true ) {
      if (4 < not_reg_data_time) {
        clear_register_value_buf();
        return 0;
      }
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar1 = reg_value_buf.reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: reg_value_num %d\n","temperature.c",0x7f,
                  "check_asic_reg_with_addr",uVar1);
        }
        fclose(pFVar2);
      }
      if ((((0x1fe < uVar1) || (0x1fe < reg_value_buf.p_rd)) || (uVar1 == 0)) &&
         (not_reg_data_time < 5)) break;
      if (4 < not_reg_data_time) {
        return 0;
      }
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      for (i = 0; (uint)i < uVar1; i = i + 1) {
        uVar3 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
        if (chain == reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: chip %x reg %x reg_buff %x\n","temperature.c",0x9b,
                      "check_asic_reg_with_addr",(uint)chip_addr,reg,uVar3);
            }
            fclose(pFVar2);
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
    not_reg_data_time = not_reg_data_time + 1;
  } while( true );
}

