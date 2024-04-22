
/* WARNING: Unknown calling convention */

void scan_freq_start(void)

{
  int iVar1;
  working_mode_e working_mode;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  
  working_mode = MODE1;
  scan_freq_prepare_log();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: freq_scan_start .. \n","freq_scan.c",0xa16,"scan_freq_start")
      ;
    }
    fclose((FILE *)pFile);
  }
  freq_scan_status = 0;
  is_freq_scan_succeeded_flag = false;
  check_chain();
  check_hashboard_hardware_info();
  sleep(1);
  init_freq_adjust_index(g_sweep_config_eco.sweep_max_freq);
  iVar1 = scan_freq_prepare();
  if (iVar1 < 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        fprintf((FILE *)pFile_1,"%s:%d:%s: freq_scan_prepare failed\n","freq_scan.c",0xa21,
                "scan_freq_start");
      }
      fclose((FILE *)pFile_1);
    }
    freq_scan_status = 2;
    do {
      sleep(10);
    } while( true );
  }
  check_nonce_rate = true;
  do {
    scan_freq_reset_scan_mark();
    scan_freq_find_base_freq(working_mode);
    scan_freq_reset_scan_info();
    scan_freq_get_next_base_freq(&working_mode);
  } while (scanfreq_info.last_all_pass != true);
  eeprom_dump();
  scan_freq_done_mark();
  is_freq_scan_succeeded_flag = true;
  aging_start();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile_2 = (FILE *)fopen(log_file,"a+");
    if (pFile_2 != (FILE *)0x0) {
      fprintf((FILE *)pFile_2,"%s:%d:%s: cancel the receive thread\n","freq_scan.c",0xa3c,
              "scan_freq_start");
    }
    fclose((FILE *)pFile_2);
  }
  pthread_cancel(receive_id);
  freq_scan_status = 1;
  return;
}

