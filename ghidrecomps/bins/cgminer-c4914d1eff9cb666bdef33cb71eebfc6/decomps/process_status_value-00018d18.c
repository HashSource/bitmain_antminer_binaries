
/* WARNING: Unknown calling convention */

_Bool process_status_value(void)

{
  FILE *pFVar1;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile_2;
  _Bool has_disabled_hash_board_flag;
  
  has_disabled_hash_board_flag = false;
  switch(status_value) {
  case STATUS_INIT:
  case STATUS_OK:
    status_error = false;
    break;
  case ERROR_OVER_MAXTEMP:
    status_error = true;
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fatal Error: Temperature is too high!\n","temperature.c",0x4ca,
                "process_status_value");
      }
      fclose(pFVar1);
    }
    has_disabled_hash_board_flag = disable_hash_board(status_value);
    break;
  case ERROR_FAN_LOST:
    status_error = true;
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fatal Error: Fan lost!\n","temperature.c",0x4d1,
                "process_status_value");
      }
      fclose(pFVar1);
    }
    has_disabled_hash_board_flag = disable_hash_board(status_value);
    break;
  case ERROR_NETWORK_LOST:
    process_status_value::lexical_block_2::network_err_count =
         process_status_value::lexical_block_2::network_err_count + 1;
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fatal Error: network connection lost!\n","temperature.c",0x4d9,
                "process_status_value");
      }
      fclose(pFVar1);
    }
    if (0x3c < process_status_value::lexical_block_2::network_err_count) {
      process_status_value::lexical_block_2::network_err_count = 0;
      status_error = true;
      has_disabled_hash_board_flag = disable_hash_board(status_value);
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Reboot system due to network connection lost!\n","temperature.c"
                  ,0x4e0,"process_status_value");
        }
        fclose(pFVar1);
      }
      sleep(0x23);
      system("reboot");
    }
  }
  return has_disabled_hash_board_flag;
}

