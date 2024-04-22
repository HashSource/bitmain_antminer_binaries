
void choose_best_freq_array(int freq_scan_times)

{
  FILE *pFVar1;
  uint32_t uVar2;
  float fVar3;
  float fVar4;
  int freq_scan_times_local;
  FILE *pFile_1;
  FILE *pFile;
  
  uVar2 = freq_scan_times - 1;
  if (uVar2 == 0) {
    memcpy(freq_adjust_record,freq_adjust_index,0x180);
    scanfreq_best_times = 0;
    memcpy(inbalance_info,inbalance_info_record,0x50);
  }
  else {
    fVar3 = calc_ability[uVar2];
    fVar4 = calc_ability[scanfreq_best_times];
    if (fVar3 != fVar4 && fVar3 < fVar4 == (NAN(fVar3) || NAN(fVar4))) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fwrite("replacing the best freq array...\n",1,0x21,pFVar1);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%5.3f [%d times]replace %5.3f [%d times]\n",
                  SUB84((double)(calc_ability[uVar2] / DAT_00033a64),0),
                  (int)((ulonglong)(double)(calc_ability[uVar2] / DAT_00033a64) >> 0x20),
                  freq_scan_times);
        }
        fclose(pFVar1);
      }
      scanfreq_best_times = uVar2;
      memcpy(freq_adjust_record,freq_adjust_index,0x180);
      memcpy(inbalance_info,inbalance_info_record,0x50);
    }
  }
  return;
}

