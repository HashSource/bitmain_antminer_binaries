
/* WARNING: Unknown calling convention */

void scan_freq_scan_by_column(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  timeval diff;
  timeval tv_end;
  timeval tv_start;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  
  cgtime(&tv_start);
  _Var1 = scan_freq_already_done();
  if (_Var1) {
    freq_scan_status = 1;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: scan freq has already been done\n","freq_scan.c",0xa55,
                "scan_freq_scan_by_column");
      }
      fclose(pFVar2);
    }
    cgtime(&tv_end);
    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"\nFreq Scan Cost Time: %ld Minutes\n",diff.tv_sec / 0x3c);
      }
      fclose(pFVar2);
    }
  }
  else {
    check_column_nonce = true;
    test_8pattern = true;
    scan_freq_start();
    cgtime(&tv_end);
    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"\nFreq Scan Cost Time: %ld Minutes\n",diff.tv_sec / 0x3c);
      }
      fclose(pFVar2);
    }
    eeprom_save();
  }
  return;
}

