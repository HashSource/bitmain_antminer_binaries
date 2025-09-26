
/* WARNING: Unknown calling convention */

_Bool save_MES_system_submit_result(void)

{
  size_t sVar1;
  FILE *__s;
  _Bool _Var2;
  char time_stamp [48];
  char tmp1 [256];
  FILE *fp;
  
  memset(submit_result_file,0,200);
  strcpy(submit_result_file,base_submit_result_file);
  strcat(submit_result_file,(Local_Config_Information->Hash_Board).Miner_Type);
  sVar1 = strlen(submit_result_file);
  (submit_result_file + sVar1)[0] = '-';
  (submit_result_file + sVar1)[1] = '\0';
  strcat(submit_result_file,(Local_Config_Information->Hash_Board).Board_Name);
  sVar1 = strlen(submit_result_file);
  (submit_result_file + sVar1)[0] = '-';
  (submit_result_file + sVar1)[1] = '\0';
  strcat(submit_result_file,sn.board_sn);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Save MES system config information into %s\n","save_MES_system_submit_result",
         submit_result_file);
  snprintf(tmp1,0x100,"Save MES system config information into %s",submit_result_file);
  log_to_file(tmp1,time_stamp);
  __s = fopen(submit_result_file,"w");
  if (__s == (FILE *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Open %s fail\n","save_MES_system_submit_result",submit_result_file);
    snprintf(tmp1,0x100,"Open %s fail",submit_result_file);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Open %s success\n","save_MES_system_submit_result",submit_result_file);
    snprintf(tmp1,0x100,"Open %s success",submit_result_file);
    log_to_file(tmp1,time_stamp);
    sVar1 = fwrite(submit_result_handshake_information,mes_system_submit_result_file_length,1,__s);
    if (sVar1 == 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Write %s success\n","save_MES_system_submit_result",submit_result_file);
      snprintf(tmp1,0x100,"Write %s success",submit_result_file);
      log_to_file(tmp1,time_stamp);
      fclose(__s);
      system("sync");
      _Var2 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Write %s fail\n","save_MES_system_submit_result",submit_result_file);
      snprintf(tmp1,0x100,"Write %s fail",submit_result_file);
      log_to_file(tmp1,time_stamp);
      fclose(__s);
      _Var2 = false;
    }
  }
  return _Var2;
}

