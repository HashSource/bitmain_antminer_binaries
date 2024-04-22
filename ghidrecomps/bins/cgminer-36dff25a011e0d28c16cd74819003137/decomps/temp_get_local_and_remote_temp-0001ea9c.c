
/* WARNING: Unknown calling convention */

void temp_get_local_and_remote_temp(void)

{
  all_parameters *paVar1;
  _Bool _Var2;
  byte bVar3;
  int16_t iVar4;
  FILE *pFVar5;
  FILE *pFile;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile_6;
  uchar write;
  uchar data;
  uint8_t remote_temp;
  uint8_t local_temp;
  int temp_asic;
  int chain;
  
  _Var2 = is_hashboard_dead();
  if (_Var2) {
    if (1 < log_level) {
      print_crt_time_to_file(temp_log,1);
      pFVar5 = fopen(temp_log,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: error: no need to read temp from dead board, reason: %d\n",
                "temperature.c",0x260,"temp_get_local_and_remote_temp",status_value);
      }
      fclose(pFVar5);
    }
  }
  else {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        for (temp_asic = 0; temp_asic < dev->chain_asic_temp_num[chain]; temp_asic = temp_asic + 1)
        {
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            pFVar5 = fopen(temp_log,"a+");
            if (pFVar5 != (FILE *)0x0) {
              fprintf(pFVar5,"%s:%d:%s: Chain[%d] Chip[%d] TempTypeID=%02x middle_offset=%d\n",
                      "temperature.c",0x26f,"temp_get_local_and_remote_temp",chain,
                      dev->TempChipAddr[chain][temp_asic] / 5,
                      (uint)dev->TempChipType[chain][temp_asic],(int)middle_Offset[chain][temp_asic]
                     );
            }
            fclose(pFVar5);
          }
          bVar3 = check_reg_temp('\0','\0','\0',dev->TempChipAddr[chain][temp_asic],chain);
          paVar1 = dev;
          if (bVar3 == 0) {
            dev->chain_asic_temp_status[chain][temp_asic] = '\0';
            if (3 < log_level) {
              print_crt_time_to_file(temp_log,3);
              pFVar5 = fopen(temp_log,"a+");
              if (pFVar5 != (FILE *)0x0) {
                fprintf(pFVar5,
                        "%s:%d:%s: read failed, old value: Chain[%d] Chip[%d] local_temp=%d\n",
                        "temperature.c",0x280,"temp_get_local_and_remote_temp",chain,
                        dev->TempChipAddr[chain][temp_asic] / 5,
                        (int)dev->chain_asic_temp[chain][temp_asic][0]);
              }
              fclose(pFVar5);
            }
          }
          else {
            iVar4 = get_local((ushort)bVar3);
            paVar1->chain_asic_temp[chain][temp_asic][0] = iVar4;
            dev->chain_asic_temp_status[chain][temp_asic] = '\x01';
            if (3 < log_level) {
              print_crt_time_to_file(temp_log,3);
              pFVar5 = fopen(temp_log,"a+");
              if (pFVar5 != (FILE *)0x0) {
                fprintf(pFVar5,"%s:%d:%s: Chain[%d] Chip[%d] local_temp=%d\n","temperature.c",0x279,
                        "temp_get_local_and_remote_temp",chain,
                        dev->TempChipAddr[chain][temp_asic] / 5,
                        (int)dev->chain_asic_temp[chain][temp_asic][0]);
              }
              fclose(pFVar5);
            }
          }
          bVar3 = check_reg_temp('\x01','\0','\0',dev->TempChipAddr[chain][temp_asic],chain);
          paVar1 = dev;
          if (bVar3 == 0) {
            dev->chain_asic_temp_status[chain][temp_asic] = '\0';
            if (3 < log_level) {
              print_crt_time_to_file(temp_log,3);
              pFVar5 = fopen(temp_log,"a+");
              if (pFVar5 != (FILE *)0x0) {
                fprintf(pFVar5,
                        "%s:%d:%s: read failed, old value: Chain[%d] Chip[%d] middle_temp=%d\n",
                        "temperature.c",0x292,"temp_get_local_and_remote_temp",chain,
                        dev->TempChipAddr[chain][temp_asic] / 5,
                        (int)dev->chain_asic_temp[chain][temp_asic][1]);
              }
              fclose(pFVar5);
            }
          }
          else {
            iVar4 = get_local((ushort)bVar3);
            paVar1->chain_asic_temp[chain][temp_asic][1] = iVar4;
            dev->chain_asic_temp_status[chain][temp_asic] = '\x01';
            if (3 < log_level) {
              print_crt_time_to_file(temp_log,3);
              pFVar5 = fopen(temp_log,"a+");
              if (pFVar5 != (FILE *)0x0) {
                fprintf(pFVar5,"%s:%d:%s: Chain[%d] Chip[%d] middle_temp=%d\n","temperature.c",0x28b
                        ,"temp_get_local_and_remote_temp",chain,
                        dev->TempChipAddr[chain][temp_asic] / 5,
                        (int)dev->chain_asic_temp[chain][temp_asic][1]);
              }
              fclose(pFVar5);
            }
          }
        }
        if (3 < log_level) {
          print_crt_time_to_file(temp_log,3);
          pFVar5 = fopen(temp_log,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: Done read temp on Chain[%d]\n","temperature.c",0x296,
                    "temp_get_local_and_remote_temp",chain);
          }
          fclose(pFVar5);
        }
      }
    }
  }
  return;
}

