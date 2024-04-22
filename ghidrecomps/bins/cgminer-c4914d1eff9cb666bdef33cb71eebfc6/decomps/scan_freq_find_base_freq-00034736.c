
void scan_freq_find_base_freq(working_mode_e working_mode)

{
  bool bVar1;
  _Bool _Var2;
  FILE *pFVar3;
  working_mode_e working_mode_local;
  FILE *pFile_13;
  FILE *pFile_12;
  FILE *pFile_11;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_14;
  FILE *pFile_8;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int freq_scan_times;
  _Bool first_time;
  
  bVar1 = true;
  freq_scan_times = 0;
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fwrite("=======================================\n",1,0x28,pFVar3);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"        scanfreq mode is MODE[%d]\n",working_mode + MODE2);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fwrite("=======================================\n",1,0x28,pFVar3);
    }
    fclose(pFVar3);
  }
  while( true ) {
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"\nbegin to test ,[%d] times...\n\n",freq_scan_times + 1);
      }
      fclose(pFVar3);
    }
    if (bVar1) {
      bVar1 = false;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: first time to init the board...\n","freq_scan.c",0x962,
                  "scan_freq_find_base_freq");
        }
        fclose(pFVar3);
      }
      scan_freq_board_init(working_mode);
      first_time_init = false;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: first time to init the board,done!\n","freq_scan.c",0x966,
                  "scan_freq_find_base_freq");
        }
        fclose(pFVar3);
      }
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: re init...\n","freq_scan.c",0x96a,"scan_freq_find_base_freq");
        }
        fclose(pFVar3);
      }
      scan_freq_board_init(working_mode);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: re init,done!\n","freq_scan.c",0x96c,"scan_freq_find_base_freq")
          ;
        }
        fclose(pFVar3);
      }
    }
    low_rate_error_now = false;
    freq_scan_times = freq_scan_times + 1;
    init_read_temp_thread_in_force();
    print_freq_adjust_index();
    memset(&scanfreq_calc_nonce_info,0,0xc3f44);
    scan_freq_send_work_and_check_result();
    scan_freq_print_noncerate_badchips();
    scan_freq_print_inbalance_region(freq_scan_times);
    print_calculation_ability(freq_scan_times);
    choose_best_freq_array(freq_scan_times);
    shutdown_read_temp_thread_in_force();
    if (0x13 < freq_scan_times) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: reach the max try times [%d]","freq_scan.c",0x985,
                  "scan_freq_find_base_freq",0x14);
        }
        fclose(pFVar3);
      }
      force_scan_freq_is_all_chain_finished();
    }
    _Var2 = scan_freq_is_all_chain_finished();
    if (_Var2) break;
    if (low_rate_error_now == true) {
      if (3 < log_level) {
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fwrite("low nonce rate !!! No need to change freq!!!\n",1,0x2d,pFVar3);
        }
        fclose(pFVar3);
      }
    }
    else {
      adjust_freq_according_result(freq_scan_times,working_mode);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: copy the best freq array...","freq_scan.c",0x98c,
              "scan_freq_find_base_freq");
    }
    fclose(pFVar3);
  }
  memcpy(freq_adjust_index,freq_adjust_record,0x180);
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"freq scan [%d] times\n",freq_scan_times);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"best result at [%d] times\n",scanfreq_best_times + 1);
    }
    fclose(pFVar3);
  }
  print_freq_adjust_index();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: freq scan,Done!\n","freq_scan.c",0x994,"scan_freq_find_base_freq");
    }
    fclose(pFVar3);
  }
  scan_freq_save_result_with_new_format(working_mode);
  scan_freq_save_more_result(working_mode);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: final freq scan,done!\n","freq_scan.c",0x99a,
              "scan_freq_find_base_freq");
    }
    fclose(pFVar3);
  }
  return;
}

