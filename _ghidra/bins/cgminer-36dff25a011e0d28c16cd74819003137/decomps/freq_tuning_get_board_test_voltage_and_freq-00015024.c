
int freq_tuning_get_board_test_voltage_and_freq
              (int level,int *pVoltage,int *pFreq,int sub_proj_index)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int sub_proj_index_local;
  int *pFreq_local;
  int *pVoltage_local;
  int level_local;
  FILE *pFile_1;
  FILE *pFile;
  int freq_step;
  int target_vol;
  int base_freq;
  int ret;
  
  ret = 0;
  iVar2 = g_BHB91602_proj.conf_list[sub_proj_index].base_freq;
  iVar3 = g_BHB91602_proj.conf_list[sub_proj_index].base_voltage;
  iVar4 = g_BHB91602_proj.conf_list[sub_proj_index].freq_step;
  if (level < 8) {
    *pVoltage = iVar3;
    *pFreq = iVar4 * level + iVar2;
  }
  else {
    ret = -1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: base_freq = %d, step = %d, base_voltage = %d, max_scan_level = %d\n"
              ,"freq_tuning.c",0x31a,"freq_tuning_get_board_test_voltage_and_freq",iVar2,iVar4,iVar3
              ,8);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: level = %d, voltage = %d, freq = %d\n","freq_tuning.c",0x31b,
              "freq_tuning_get_board_test_voltage_and_freq",level,*pVoltage,*pFreq);
    }
    fclose(pFVar1);
  }
  return ret;
}

