
void freq_tuning_save_result(freq_tuning_info *freq_info,int sub_proj_index)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int proj_sub_type;
  int work_mode;
  uint8_t chain;
  
  iVar3 = g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type;
  for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
    if (dev->chain_exist[chain] != 0) {
      while( true ) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Save freq to eeprom for chain %d...\n","freq_tuning.c",0x980,
                    "freq_tuning_save_result",(uint)chain);
          }
          fclose(pFVar1);
        }
        if (iVar3 == 0) {
          work_mode = 0;
        }
        else if (iVar3 == 1) {
          work_mode = 1;
        }
        iVar2 = eeprom_set_freq((uint)chain,work_mode,freq_info->freq_table[chain],'0');
        if (iVar2 != 0) break;
        sleep(1);
      }
      while( true ) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Save voltage to eeprom for chain %d...\n","freq_tuning.c",
                    0x995,"freq_tuning_save_result",(uint)chain);
          }
          fclose(pFVar1);
        }
        if (iVar3 == 0) {
          work_mode = 0;
        }
        else if (iVar3 == 1) {
          work_mode = 1;
        }
        iVar2 = eeprom_set_voltage((uint)chain,work_mode,(uint16_t)freq_info->vol_value_table[chain]
                                  );
        if (iVar2 != 0) break;
        sleep(1);
      }
      while( true ) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Save hash rate to eeprom for chain %d...\n","freq_tuning.c",
                    0x9aa,"freq_tuning_save_result",(uint)chain);
          }
          fclose(pFVar1);
        }
        if (iVar3 == 0) {
          work_mode = 0;
        }
        else if (iVar3 == 1) {
          work_mode = 1;
        }
        iVar2 = eeprom_set_hash_rate((uint)chain,work_mode,freq_info->ideal_hash_rate[chain]);
        if (iVar2 != 0) break;
        sleep(1);
      }
    }
  }
  eeprom_dump();
  return;
}

