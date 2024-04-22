
/* WARNING: Unknown calling convention */

void temp_get_statistics(void)

{
  all_parameters *paVar1;
  _Bool _Var2;
  FILE *pFVar3;
  int iVar4;
  FILE *pFile;
  FILE *pFile_1;
  int tmp_pos;
  int m;
  int temp_asic;
  int chain;
  
  _Var2 = is_hashboard_dead();
  if (_Var2) {
    if (1 < log_level) {
      print_crt_time_to_file(temp_log,1);
      pFVar3 = fopen(temp_log,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,
                "%s:%d:%s: error: no need to get statistics as hashboard is  dead for reason: %d\n",
                "temperature.c",699,"temp_get_statistics",status_value);
      }
      fclose(pFVar3);
    }
  }
  else {
    dev->temp_air_out_avg = 0;
    dev->temp_air_out_sum = 0;
    dev->temp_bad_count = 0;
    dev->temp_air_out_good_count = 0;
    dev->temp_air_in_bad_count = 0;
    dev->temp_top1[0] = 0;
    dev->temp_top1[1] = 0;
    dev->temp_top1[2] = 0;
    dev->temp_low1[0] = 1000;
    dev->temp_low1[1] = 1000;
    dev->temp_low1[2] = 1000;
    for (chain = 0; paVar1 = dev, chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        dev->chain_asic_maxtemp[chain][0] = 0;
        dev->chain_asic_maxtemp[chain][1] = 0;
        dev->chain_asic_maxtemp[chain][2] = 0;
        dev->chain_asic_mintemp[chain][0] = 1000;
        dev->chain_asic_mintemp[chain][1] = 1000;
        dev->chain_asic_mintemp[chain][2] = 1000;
        for (temp_asic = 0; temp_asic < dev->chain_asic_temp_num[chain]; temp_asic = temp_asic + 1)
        {
          if (dev->chain_asic_temp_status[chain][temp_asic] == '\x01') {
            if (((byte)(dev->TempChipAddr[chain][temp_asic] - 0x28) < 5) ||
               ((byte)(dev->TempChipAddr[chain][temp_asic] + 0x3d) < 5)) {
              dev->temp_air_out_good_count = dev->temp_air_out_good_count + 1;
              dev->temp_air_out_sum =
                   dev->temp_air_out_sum + (int)dev->chain_asic_temp[chain][temp_asic][0];
              if (3 < log_level) {
                print_crt_time_to_file(temp_log,3);
                pFVar3 = fopen(temp_log,"a+");
                if (pFVar3 != (FILE *)0x0) {
                  fprintf(pFVar3,"%s:%d:%s: ****temp_sum:%d, temp cnt: %d.\n","temperature.c",0x2e6,
                          "temp_get_statistics",dev->temp_air_out_sum,dev->temp_air_out_good_count);
                }
                fclose(pFVar3);
              }
            }
            for (m = 0; m < 3; m = m + 1) {
              if (dev->chain_asic_maxtemp[chain][m] < dev->chain_asic_temp[chain][temp_asic][m]) {
                dev->chain_asic_maxtemp[chain][m] = dev->chain_asic_temp[chain][temp_asic][m];
              }
              if (dev->chain_asic_temp[chain][temp_asic][m] < dev->chain_asic_mintemp[chain][m]) {
                dev->chain_asic_mintemp[chain][m] = dev->chain_asic_temp[chain][temp_asic][m];
              }
            }
          }
          else {
            dev->temp_bad_count = dev->temp_bad_count + 1;
            if (((byte)(dev->TempChipAddr[chain][temp_asic] - 0x37) < 5) ||
               ((byte)(dev->TempChipAddr[chain][temp_asic] + 0x4c) < 5)) {
              dev->temp_air_in_bad_count = dev->temp_air_in_bad_count + 1;
            }
          }
        }
        for (tmp_pos = 0; tmp_pos < 3; tmp_pos = tmp_pos + 1) {
          if (dev->temp_top1[tmp_pos] < (int)dev->chain_asic_maxtemp[chain][tmp_pos]) {
            dev->temp_top1[tmp_pos] = (int)dev->chain_asic_maxtemp[chain][tmp_pos];
          }
          if ((int)dev->chain_asic_mintemp[chain][tmp_pos] < dev->temp_low1[tmp_pos]) {
            dev->temp_low1[tmp_pos] = (int)dev->chain_asic_mintemp[chain][tmp_pos];
          }
        }
      }
    }
    if (dev->temp_air_out_good_count != 0) {
      iVar4 = __aeabi_idiv(dev->temp_air_out_sum,dev->temp_air_out_good_count);
      paVar1->temp_air_out_avg = iVar4;
    }
  }
  return;
}

