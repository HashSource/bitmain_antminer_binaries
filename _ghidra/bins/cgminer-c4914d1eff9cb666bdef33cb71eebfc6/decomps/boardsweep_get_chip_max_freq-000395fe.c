
int boardsweep_get_chip_max_freq(working_mode_e working_mode)

{
  bool bVar1;
  _Bool _Var2;
  int iVar3;
  FILE *__stream;
  working_mode_e working_mode_local;
  FILE *pFile;
  int ret;
  int count;
  _Bool first_time;
  
  bVar1 = true;
  count = 0;
  sweep_freq_set_base_freq(working_mode);
  scan_freq_reset_scan_info();
  do {
    if (bVar1) {
      shutdown_read_temp_thread_in_force();
      bVar1 = false;
      first_time_init = true;
      iVar3 = scan_freq_board_init(working_mode);
      if (iVar3 != 0) {
        return iVar3;
      }
      first_time_init = false;
      init_read_temp_thread_in_force();
    }
    else {
      boardsweep_get_next_freq(working_mode);
      _Var2 = scan_freq_is_all_chain_finished();
      if (_Var2) {
        shutdown_read_temp_thread_in_force();
        return 0;
      }
      shutdown_read_temp_thread_in_force();
      iVar3 = scan_freq_board_fast_init(working_mode);
      if (iVar3 != 0) {
        return iVar3;
      }
      init_read_temp_thread_in_force();
    }
    boardsweep_send_work_and_check_result();
    boardsweep_print_bad_cores();
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        count = count + 1;
        fprintf(__stream,"%s:%d:%s: scan freq for %d times \n","freq_scan.c",0xfc1,
                "boardsweep_get_chip_max_freq",count);
      }
      fclose(__stream);
    }
  } while( true );
}

