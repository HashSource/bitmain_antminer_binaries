
void slowly_set_iic_power_voltage_t11(int voltage_flag)

{
  FILE *pFVar1;
  double dVar2;
  undefined4 in_stack_ffffff58;
  undefined4 in_stack_ffffff5c;
  int voltage_flag_local;
  int index [16];
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_7;
  FILE *pFile_8;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_1;
  FILE *pFile;
  double voltage;
  int max_index;
  int chain;
  int i;
  
  memset(index,0,0x40);
  chain = 0;
  do {
    if (0xf < chain) {
LAB_0003cc54:
      max_index = 0;
      for (i = 0; i < 0x10; i = i + 1) {
        if (max_index <= index[i]) {
          max_index = index[i];
        }
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: parallel set all chain to working voltage:\n","power.c",0x4c9,
                  "slowly_set_iic_power_voltage_t11");
        }
        fclose(pFVar1);
      }
      for (i = 0; i <= max_index; i = i + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fwrite("now setting ",1,0xc,pFVar1);
          }
          fclose(pFVar1);
        }
        for (chain = 0; chain < 0x10; chain = chain + 1) {
          if ((dev->chain_exist[chain] != 0) && (power_info[chain].iic_data[i] != 0xff)) {
            dVar2 = get_power_voltage_from_iic_value(power_info[chain].iic_data[i]);
            power_set_voltage(power_info + chain,power_info[chain].iic_data[i]);
            voltage._0_4_ = SUB84(dVar2,0);
            voltage._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
            *(undefined4 *)&power_info[chain].current_voltage = voltage._0_4_;
            *(undefined4 *)((int)&power_info[chain].current_voltage + 4) = voltage._4_4_;
            power_info[chain].current_iic_data = power_info[chain].iic_data[i];
            if (3 < log_level) {
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"chain[%d]-volt[%05.2f]-data[%03d] ",chain,
                        (uint)power_info[chain].current_iic_data,
                        *(undefined4 *)&power_info[chain].current_voltage,
                        *(undefined4 *)((int)&power_info[chain].current_voltage + 4),
                        (uint)power_info[chain].current_iic_data);
              }
              fclose(pFVar1);
            }
          }
        }
        usleep(500000);
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: parallel set all chain to working voltage end!\n","power.c",
                  0x4dd,"slowly_set_iic_power_voltage_t11");
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fwrite("now setting ",1,0xc,pFVar1);
        }
        fclose(pFVar1);
      }
      for (chain = 0; chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] != 0) && (3 < log_level)) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"chain[%d]-volt[%05.2f]-data[%03d] ",chain,
                    (uint)power_info[chain].current_iic_data,
                    *(undefined4 *)&power_info[chain].current_voltage,
                    *(undefined4 *)((int)&power_info[chain].current_voltage + 4),
                    (uint)power_info[chain].current_iic_data);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
      return;
    }
    if (dev->chain_exist[chain] != 0) {
      memset(power_info[chain].iic_data,0xff,0x20);
      power_info[chain].is_voltage_stable = true;
      if (chain != (uint)power_info[chain].chain_num) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: ERROR! power info is incorrect!\n","power.c",0x4ac,
                    "slowly_set_iic_power_voltage_t11");
          }
          fclose(pFVar1);
        }
        goto LAB_0003cc54;
      }
      calc_power_iic_data_by_chain
                (power_info + chain,(double)CONCAT44(in_stack_ffffff5c,in_stack_ffffff58));
      index[chain] = (uint)power_info[chain].iic_data_index;
    }
    chain = chain + 1;
  } while( true );
}

