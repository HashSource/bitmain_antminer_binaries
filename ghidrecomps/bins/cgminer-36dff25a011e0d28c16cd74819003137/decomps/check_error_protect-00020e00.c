
/* WARNING: Unknown calling convention */

void check_error_protect(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_3;
  
  _Var1 = is_hashboard_dead();
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: ***already dead: %d\n","temperature.c",0x3af,"check_error_protect"
                ,status_value);
      }
      fclose(pFVar2);
    }
  }
  else {
    update_error_status();
    switch(status_value) {
    case STATUS_INIT:
    case STATUS_OK:
      fatal_error_counter = 0;
      if (once_error != true) {
        status_error = false;
      }
      break;
    case ERROR_NETCONN_LOST:
      fatal_error_counter = fatal_error_counter + 1;
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: fatal_error_counter increase as: %d, error status: %d\n",
                  "temperature.c",0x3ba,"check_error_protect",fatal_error_counter,status_value);
        }
        fclose(pFVar2);
      }
      if (0x3b < fatal_error_counter) {
        killall_hashboard();
        print_crt_time_to_file(log_file,1);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"Assert fail!! %s:%d: assert_log: network connection lost!\n",
                  "temperature.c",0x3be);
        }
        fclose(pFVar2);
                    /* WARNING: Subroutine does not return */
        __assert_fail("0","temperature.c",0x3be,"check_error_protect");
      }
      if (once_error != true) {
        status_error = false;
      }
      break;
    case ERROR_OVER_MAXTEMP:
    case ERROR_FAN_LOST:
      fatal_error_counter = fatal_error_counter + 1;
      if (1 < log_level) {
        print_crt_time_to_file(log_file,1);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: fatal_error_counter increase as: %d, error status: %d\n",
                  "temperature.c",0x3ce,"check_error_protect",fatal_error_counter,status_value);
        }
        fclose(pFVar2);
      }
      if (fatal_error_counter < 1) {
        if (once_error != true) {
          status_error = false;
        }
      }
      else {
        killall_hashboard();
      }
    }
  }
  return;
}

