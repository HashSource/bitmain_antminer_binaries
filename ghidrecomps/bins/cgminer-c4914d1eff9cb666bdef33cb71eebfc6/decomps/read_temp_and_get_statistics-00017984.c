
/* WARNING: Unknown calling convention */

void read_temp_and_get_statistics(void)

{
  all_parameters *paVar1;
  int16_t iVar2;
  uint uVar3;
  FILE *pFVar4;
  int iVar5;
  int mintemp [4];
  int maxtemp [4];
  int16_t temp_low [4];
  int16_t temp_top [4];
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile_2;
  int ret;
  FILE *pFile;
  FILE *pFile_5;
  int temp_cnt;
  int temp_sum;
  int j;
  int i;
  
  temp_sum = 0;
  temp_cnt = 0;
  read_temp_error = false;
  dev->temp_num = '\0';
  memset(temp_top,0,8);
  memset(temp_low,0,8);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      maxtemp[0] = 0;
      maxtemp[1] = 0;
      maxtemp[2] = 0;
      mintemp[0] = 1000;
      mintemp[1] = 1000;
      mintemp[2] = 1000;
      for (j = 0; j < dev->chain_asic_temp_num[i]; j = j + 1) {
        if (3 < log_level) {
          print_crt_time_to_file(temp_log,3);
          pFVar4 = fopen(temp_log,"a+");
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: Chain[%d] Chip[%d] TempTypeID=%02x middle offset=%d\n",
                    "temperature.c",0x3ae,"read_temp_and_get_statistics",i,
                    (dev->TempChipAddr[i][j] >> 2) + 1,(uint)dev->TempChipType[i][j],
                    (int)middle_Offset[i][j]);
          }
          fclose(pFVar4);
        }
        uVar3 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
        paVar1 = dev;
        if (uVar3 == 0) {
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            pFVar4 = fopen(temp_log,"a+");
            if (pFVar4 != (FILE *)0x0) {
              fprintf(pFVar4,"%s:%d:%s: read failed, old value: Chain[%d] Chip[%d] local Temp=%d\n",
                      "temperature.c",0x3c0,"read_temp_and_get_statistics",i,
                      (dev->TempChipAddr[i][j] >> 2) + 1,(int)dev->chain_asic_temp[i][j][0]);
            }
            fclose(pFVar4);
          }
          read_temp_error = true;
        }
        else {
          iVar2 = get_local((ushort)uVar3 & 0xff);
          paVar1->chain_asic_temp[i][j][0] = iVar2;
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            pFVar4 = fopen(temp_log,"a+");
            if (pFVar4 != (FILE *)0x0) {
              fprintf(pFVar4,"%s:%d:%s: Chain[%d] Chip[%d] local Temp=%d\n","temperature.c",0x3b5,
                      "read_temp_and_get_statistics",i,(dev->TempChipAddr[i][j] >> 2) + 1,
                      (int)dev->chain_asic_temp[i][j][0]);
            }
            fclose(pFVar4);
          }
          if ((byte)(dev->TempChipAddr[i][j] + 0x88) < 4) {
            temp_sum = temp_sum + dev->chain_asic_temp[i][j][0];
            temp_cnt = temp_cnt + 1;
          }
          dev->temp_num = dev->temp_num + '\x01';
        }
        uVar3 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
        paVar1 = dev;
        if (uVar3 == 0) {
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            pFVar4 = fopen(temp_log,"a+");
            if (pFVar4 != (FILE *)0x0) {
              fprintf(pFVar4,
                      "%s:%d:%s: read failed on Chain[%d] Chip[%d] middle Temp old value:%d\n",
                      "temperature.c",0x3f0,"read_temp_and_get_statistics",i,
                      (dev->TempChipAddr[i][j] >> 2) + 1,(int)dev->chain_asic_temp[i][j][1]);
            }
            fclose(pFVar4);
          }
        }
        else {
          iVar2 = get_remote((ushort)uVar3 & 0xff);
          paVar1->chain_asic_temp[i][j][1] = iVar2;
          if (3 < log_level) {
            print_crt_time_to_file(temp_log,3);
            pFVar4 = fopen(temp_log,"a+");
            if (pFVar4 != (FILE *)0x0) {
              fprintf(pFVar4,"%s:%d:%s: Chain[%d] Chip[%d] middle Temp=%d\n","temperature.c",0x3d9,
                      "read_temp_and_get_statistics",i,(dev->TempChipAddr[i][j] >> 2) + 1,
                      (int)dev->chain_asic_temp[i][j][1]);
            }
            fclose(pFVar4);
          }
        }
        if (maxtemp[0] < dev->chain_asic_temp[i][j][0]) {
          maxtemp[0] = (int)dev->chain_asic_temp[i][j][0];
        }
        if (maxtemp[1] < dev->chain_asic_temp[i][j][1]) {
          maxtemp[1] = (int)dev->chain_asic_temp[i][j][1];
        }
        if (maxtemp[2] < dev->chain_asic_temp[i][j][2]) {
          maxtemp[2] = (int)dev->chain_asic_temp[i][j][2];
        }
        if (dev->chain_asic_temp[i][j][0] < mintemp[0]) {
          mintemp[0] = (int)dev->chain_asic_temp[i][j][0];
        }
        if (dev->chain_asic_temp[i][j][1] < mintemp[1]) {
          mintemp[1] = (int)dev->chain_asic_temp[i][j][1];
        }
        if (dev->chain_asic_temp[i][j][2] < mintemp[2]) {
          mintemp[2] = (int)dev->chain_asic_temp[i][j][2];
        }
      }
      dev->chain_asic_maxtemp[i][0] = (int16_t)maxtemp[0];
      dev->chain_asic_maxtemp[i][1] = (int16_t)maxtemp[1];
      dev->chain_asic_maxtemp[i][2] = (int16_t)maxtemp[2];
      dev->chain_asic_mintemp[i][0] = (int16_t)mintemp[0];
      dev->chain_asic_mintemp[i][1] = (int16_t)mintemp[1];
      dev->chain_asic_mintemp[i][2] = (int16_t)mintemp[2];
      if (temp_top[0] < dev->chain_asic_maxtemp[i][0]) {
        temp_top[0] = dev->chain_asic_maxtemp[i][0];
      }
      if (temp_top[1] < dev->chain_asic_maxtemp[i][1]) {
        temp_top[1] = dev->chain_asic_maxtemp[i][1];
      }
      if (temp_top[2] < dev->chain_asic_maxtemp[i][2]) {
        temp_top[2] = dev->chain_asic_maxtemp[i][2];
      }
      if ((((dev->chain_asic_mintemp[i][0] < temp_low[0]) && (0 < dev->chain_asic_mintemp[i][0])) &&
          (chain_temp_toolow[i] == 0)) || (temp_low[0] == 0)) {
        temp_low[0] = dev->chain_asic_mintemp[i][0];
      }
      if ((((dev->chain_asic_mintemp[i][1] < temp_low[1]) && (0 < dev->chain_asic_mintemp[i][1])) &&
          (chain_temp_toolow[i] == 0)) || (temp_low[1] == 0)) {
        temp_low[1] = dev->chain_asic_mintemp[i][1];
      }
      if ((((dev->chain_asic_mintemp[i][2] < temp_low[2]) && (0 < dev->chain_asic_mintemp[i][2])) &&
          (chain_temp_toolow[i] == 0)) || (temp_low[2] == 0)) {
        temp_low[2] = dev->chain_asic_mintemp[i][2];
      }
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar4 = fopen(temp_log,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: Done read temp on Chain[%d]\n","temperature.c",0x421,
                  "read_temp_and_get_statistics",i);
        }
        fclose(pFVar4);
      }
    }
  }
  dev->temp_top1[0] = (int)temp_top[0];
  dev->temp_top1[1] = (int)temp_top[1];
  dev->temp_top1[2] = (int)temp_top[2];
  dev->temp_low1[0] = (int)temp_low[0];
  dev->temp_low1[1] = (int)temp_low[1];
  dev->temp_low1[2] = (int)temp_low[2];
  paVar1 = dev;
  if (temp_cnt == 0) {
    read_temp_error = true;
  }
  else {
    iVar5 = __aeabi_idiv(temp_sum,temp_cnt);
    paVar1->temp_avg = iVar5;
  }
  last_testpatten_lowest_pcb_temp = dev->temp_low1[0];
  last_testpatten_highest_pcb_temp = dev->temp_top1[0];
  last_testpatten_lowest_chip_temp = dev->temp_low1[1];
  last_testpatten_highest_chip_temp = dev->temp_top1[1];
  return;
}

