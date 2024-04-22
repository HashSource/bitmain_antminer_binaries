
/* WARNING: Removing unreachable block (ram,0x0003a2fc) */
/* WARNING: Unknown calling convention */

int boardsweep_task(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  time_t tVar3;
  time_t tVar4;
  int iVar5;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_3;
  time_t search_end_time;
  FILE *pFile_2;
  time_t search_start_time;
  int ret;
  
  freq_scan_status = 0;
  _Var1 = scan_freq_already_done();
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: scan freq has already been done\n","freq_scan.c",0x1066,
                "boardsweep_task");
      }
      fclose(pFVar2);
    }
    freq_scan_status = 1;
    iVar5 = 0;
  }
  else {
    is_freq_scan_succeeded_flag = false;
    test_8pattern = true;
    check_column_nonce = false;
    tVar3 = time((time_t *)0x0);
    iVar5 = scan_freq_prepare();
    if (iVar5 < 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: sweep freq prepare failed\n","freq_scan.c",0x1071,
                  "boardsweep_task");
        }
        fclose(pFVar2);
      }
      freq_scan_status = 2;
      iVar5 = -1;
    }
    else {
      boardsweep_start(MODE2);
      check_chain();
      scan_freq_stop_hash_board();
      sleep(0x1e);
      iVar5 = eeprom_date_check();
      if (iVar5 == 0) {
        eeprom_dump();
        scan_freq_done_mark();
        is_freq_scan_succeeded_flag = true;
        aging_start();
        freq_scan_status = 1;
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: cancel the receive thread\n","freq_scan.c",0x108a,
                    "boardsweep_task");
          }
          fclose(pFVar2);
        }
        pthread_cancel(receive_id);
        tVar4 = time((time_t *)0x0);
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: total cost time %ld s \n","freq_scan.c",0x108e,
                    "boardsweep_task",tVar4 - tVar3);
          }
          fclose(pFVar2);
        }
        iVar5 = 0;
      }
    }
  }
  return iVar5;
}

