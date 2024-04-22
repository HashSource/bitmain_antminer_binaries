
/* WARNING: Unknown calling convention */

void freq_tuning_config_dump(void)

{
  FILE *pFVar1;
  freq_tuning_project_conf *pfVar2;
  FILE *pFile_14;
  FILE *pFile_13;
  FILE *pFile_12;
  FILE *pFile_11;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile;
  FILE *pFile_1;
  freq_tuning_project_conf *conf;
  int sub_proj_index;
  
  for (sub_proj_index = 0; sub_proj_index < g_BHB91602_proj.sub_proj_count;
      sub_proj_index = sub_proj_index + 1) {
    pfVar2 = g_BHB91602_proj.conf_list + sub_proj_index;
    if (pfVar2->proj_type == 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: proj_type          : %s\n","freq_tuning.c",0x20e,
                  "freq_tuning_config_dump",&DAT_00097f50);
        }
        fclose(pFVar1);
      }
    }
    else if ((pfVar2->proj_type == 1) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: proj_type          : %s\n","freq_tuning.c",0x212,
                "freq_tuning_config_dump",&DAT_00097f54);
      }
      fclose(pFVar1);
    }
    if (pfVar2->proj_sub_type == 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: proj_sub_type      : %s\n","freq_tuning.c",0x217,
                  "freq_tuning_config_dump","Economy");
        }
        fclose(pFVar1);
      }
    }
    else if ((pfVar2->proj_sub_type == 1) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: proj_sub_type      : %s\n","freq_tuning.c",0x21b,
                "freq_tuning_config_dump","High Hashrate");
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: asic_num           : %d\n","freq_tuning.c",0x21e,
                "freq_tuning_config_dump",pfVar2->asic_num);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: base_voltage       : %d\n","freq_tuning.c",0x21f,
                "freq_tuning_config_dump",pfVar2->base_voltage);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: base_freq          : %d\n","freq_tuning.c",0x220,
                "freq_tuning_config_dump",pfVar2->base_freq);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: freq_step          : %d\n","freq_tuning.c",0x221,
                "freq_tuning_config_dump",pfVar2->freq_step);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: max_voltage        : %d\n","freq_tuning.c",0x222,
                "freq_tuning_config_dump",pfVar2->max_voltage);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Step_count         : %d\n","freq_tuning.c",0x223,
                "freq_tuning_config_dump",8);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: target_hash_rate   : %d\n","freq_tuning.c",0x224,
                "freq_tuning_config_dump",pfVar2->target_hash_rate);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: max_hash_rate      : %d\n","freq_tuning.c",0x225,
                "freq_tuning_config_dump",pfVar2->max_hash_rate);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: fan_pwm            : %d\n","freq_tuning.c",0x226,
                "freq_tuning_config_dump",pfVar2->fan_pwm);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: serial_level_count : %d\n","freq_tuning.c",0x227,
                "freq_tuning_config_dump",pfVar2->serial_level_count);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: \n","freq_tuning.c",0x228,"freq_tuning_config_dump");
      }
      fclose(pFVar1);
    }
  }
  return;
}

