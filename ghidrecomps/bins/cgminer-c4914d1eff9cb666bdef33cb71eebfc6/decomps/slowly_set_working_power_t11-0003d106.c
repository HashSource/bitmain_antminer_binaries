
void slowly_set_working_power_t11(uint8_t chain)

{
  byte bVar1;
  FILE *pFVar2;
  double dVar3;
  undefined4 in_stack_ffffffa8;
  undefined4 in_stack_ffffffac;
  uint8_t chain_local;
  FILE *pFile;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_1;
  int index;
  double voltage;
  int i;
  
  memset(power_info[chain].iic_data,0xff,0x20);
  power_info[chain].is_voltage_stable = true;
  if (chain == power_info[chain].chain_num) {
    calc_power_iic_data_by_chain
              (power_info + chain,(double)CONCAT44(in_stack_ffffffac,in_stack_ffffffa8));
    bVar1 = power_info[chain].iic_data_index;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: set chain %u to working voltage:\n","power.c",0x4fb,
                "slowly_set_working_power_t11",(uint)chain);
      }
      fclose(pFVar2);
    }
    for (i = 0; i <= (int)(uint)bVar1; i = i + 1) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fwrite("now setting ",1,0xc,pFVar2);
        }
        fclose(pFVar2);
      }
      if (power_info[chain].iic_data[i] != 0xff) {
        dVar3 = get_power_voltage_from_iic_value(power_info[chain].iic_data[i]);
        power_set_voltage(power_info + chain,power_info[chain].iic_data[i]);
        voltage._0_4_ = SUB84(dVar3,0);
        voltage._4_4_ = (undefined4)((ulonglong)dVar3 >> 0x20);
        *(undefined4 *)&power_info[chain].current_voltage = voltage._0_4_;
        *(undefined4 *)((int)&power_info[chain].current_voltage + 4) = voltage._4_4_;
        power_info[chain].current_iic_data = power_info[chain].iic_data[i];
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"chain[%d]-volt[%05.2f]-data[%03d] ",(uint)chain,
                    (uint)power_info[chain].current_iic_data,
                    *(undefined4 *)&power_info[chain].current_voltage,
                    *(undefined4 *)((int)&power_info[chain].current_voltage + 4),
                    (uint)power_info[chain].current_iic_data);
          }
          fclose(pFVar2);
        }
        usleep(500000);
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fputc(10,pFVar2);
          }
          fclose(pFVar2);
        }
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: done!\n","power.c",0x50a,"slowly_set_working_power_t11");
      }
      fclose(pFVar2);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: ERROR! power info is incorrect!\n","power.c",0x4f3,
              "slowly_set_working_power_t11");
    }
    fclose(pFVar2);
  }
  return;
}

