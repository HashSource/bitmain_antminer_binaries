
void check_status_value(_Bool fatal_flag)

{
  all_parameters *paVar1;
  int16_t iVar2;
  uint uVar3;
  FILE *pFVar4;
  int iVar5;
  _Bool fatal_flag_local;
  timeval diff;
  FILE *pFile_1;
  FILE *pFile;
  int ret;
  int cur_fan_num;
  int j;
  int i;
  
  if (!fatal_flag) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        for (j = 0; j < dev->chain_asic_temp_num[i]; j = j + 1) {
          uVar3 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar1 = dev;
          iVar2 = get_local((ushort)uVar3 & 0xff);
          paVar1->chain_asic_temp[i][j][0] = iVar2;
          if (0x55 < dev->chain_asic_temp[i][j][0]) {
            sleep(3);
            uVar3 = check_reg_temp(DEVICEADDR[i],0,'\0','\0',dev->TempChipAddr[i][j],i);
            paVar1 = dev;
            iVar2 = get_local((ushort)uVar3 & 0xff);
            paVar1->chain_asic_temp[i][j][0] = iVar2;
            if (0x55 < dev->chain_asic_temp[i][j][0]) {
              status_value = ERROR_OVER_MAXTEMP;
              pcb_chip_over_temp = false;
              if (log_level < 4) {
                status_value = ERROR_OVER_MAXTEMP;
                pcb_chip_over_temp = false;
                return;
              }
              print_crt_time_to_file(temp_log,3);
              pFVar4 = fopen(temp_log,"a+");
              if (pFVar4 != (FILE *)0x0) {
                fprintf(pFVar4,"%s:%d:%s: High PCB temp = %d detected!!\n","temperature.c",0x492,
                        "check_status_value",(int)dev->chain_asic_temp[i][j][0]);
              }
              fclose(pFVar4);
              return;
            }
          }
          uVar3 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
          paVar1 = dev;
          iVar2 = get_remote((ushort)uVar3 & 0xff);
          paVar1->chain_asic_temp[i][j][1] = iVar2;
          if (0x69 < dev->chain_asic_temp[i][j][1]) {
            sleep(3);
            uVar3 = check_reg_temp(DEVICEADDR[i],1,'\0','\0',dev->TempChipAddr[i][j],i);
            paVar1 = dev;
            iVar2 = get_remote((ushort)uVar3 & 0xff);
            paVar1->chain_asic_temp[i][j][1] = iVar2;
            if (0x69 < dev->chain_asic_temp[i][j][1]) {
              status_value = ERROR_OVER_MAXTEMP;
              pcb_chip_over_temp = true;
              if (log_level < 4) {
                status_value = ERROR_OVER_MAXTEMP;
                pcb_chip_over_temp = true;
                return;
              }
              print_crt_time_to_file(temp_log,3);
              pFVar4 = fopen(temp_log,"a+");
              if (pFVar4 != (FILE *)0x0) {
                fprintf(pFVar4,"%s:%d:%s: High CHIP temp = %d detected!!\n","temperature.c",0x4a3,
                        "check_status_value",(int)dev->chain_asic_temp[i][j][1]);
              }
              fclose(pFVar4);
              return;
            }
          }
        }
      }
    }
    iVar5 = check_fan();
    if (iVar5 < 2) {
      status_value = ERROR_FAN_LOST;
    }
    else {
      if (startCheckNetworkJob != false) {
        cgtime(&tv_send);
        diff.tv_sec = tv_send.tv_sec - tv_send_job.tv_sec;
        if (tv_send.tv_usec - tv_send_job.tv_usec < 0) {
          diff.tv_sec = diff.tv_sec + -1;
        }
        if (0x78 < diff.tv_sec) {
          status_value = ERROR_NETWORK_LOST;
          return;
        }
      }
      status_error = false;
    }
  }
  return;
}

