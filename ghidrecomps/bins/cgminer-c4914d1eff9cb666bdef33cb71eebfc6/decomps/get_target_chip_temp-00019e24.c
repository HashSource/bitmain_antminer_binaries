
int get_target_chip_temp(int min_entrance_pcb_temp)

{
  _Bool _Var1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int min_entrance_pcb_temp_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int low_temp_exit_threshold;
  int low_temp_bingup_threshold;
  char *temp_log;
  
  _Var1 = is_economic_mode();
  iVar3 = low_temp_process_parm[1].low_temp;
  if (_Var1) {
    iVar3 = low_temp_process_parm[0].low_temp;
  }
  _Var1 = is_economic_mode();
  iVar4 = low_temp_process_parm[1].middle_temp;
  if (_Var1) {
    iVar4 = low_temp_process_parm[0].middle_temp;
  }
  if (get_target_chip_temp::low_temp_env_init != true) {
    get_target_chip_temp::low_temp_env_init = true;
    iVar5 = iVar3;
    if (min_entrance_pcb_temp < iVar3) {
      iVar5 = 1;
    }
    get_target_chip_temp::is_low_temp_env = SUB41(iVar5,0);
    if (iVar3 <= min_entrance_pcb_temp) {
      get_target_chip_temp::is_low_temp_env = false;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        if (get_target_chip_temp::is_low_temp_env == false) {
          puVar6 = &DAT_00080a5c;
        }
        else {
          puVar6 = &DAT_00080a58;
        }
        fprintf(pFVar2,"%s:%d:%s: if startup in low temp environment: %s\n","temperature.c",0x6db,
                "get_target_chip_temp",puVar6);
      }
      fclose(pFVar2);
    }
  }
  if (((min_entrance_pcb_temp < iVar3) && (get_target_chip_temp::is_low_temp_env != true)) &&
     (get_target_chip_temp::is_low_temp_env = true, 3 < log_level)) {
    print_crt_time_to_file("/var/log/temp",3);
    pFVar2 = fopen("/var/log/temp","a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: change to low temp pwm\n","temperature.c",0x6e1,
              "get_target_chip_temp");
    }
    fclose(pFVar2);
  }
  if (((iVar4 < min_entrance_pcb_temp) && (get_target_chip_temp::is_low_temp_env != false)) &&
     (get_target_chip_temp::is_low_temp_env = false, 3 < log_level)) {
    print_crt_time_to_file("/var/log/temp",3);
    pFVar2 = fopen("/var/log/temp","a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: change to normal pid pwm\n","temperature.c",0x6e7,
              "get_target_chip_temp");
    }
    fclose(pFVar2);
  }
  _Var1 = is_T11();
  if (_Var1) {
    iVar3 = _get_target_chip_temp_t11(get_target_chip_temp::is_low_temp_env,min_entrance_pcb_temp);
  }
  else {
    iVar3 = _get_target_chip_temp_t11a(get_target_chip_temp::is_low_temp_env,min_entrance_pcb_temp);
  }
  return iVar3;
}

