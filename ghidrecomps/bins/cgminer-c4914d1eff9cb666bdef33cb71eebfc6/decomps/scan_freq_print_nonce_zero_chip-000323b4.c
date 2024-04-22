
void scan_freq_print_nonce_zero_chip(int chain)

{
  FILE *pFVar1;
  uint uVar2;
  float fVar3;
  int chain_local;
  FILE *pFile_2;
  int column;
  FILE *pFile_1;
  FILE *pFile;
  float nonce_rate;
  int bad_core_num;
  int m;
  int i;
  
  fVar3 = ((float)(longlong)scanfreq_info.valid_nonce_num[chain] /
          (float)(longlong)scanfreq_info.RequiredChainNonce) * DAT_000325fc;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Chain %d Nonce rate: %.2f\n","freq_scan.c",0x5a9,
              "scan_freq_print_nonce_zero_chip",chain,(double)fVar3);
    }
    fclose(pFVar1);
  }
  if ((int)((uint)(fVar3 < DAT_00032600) << 0x1f) < 0) {
    low_rate_error_now = true;
    low_rate_error = low_rate_error + 1;
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"low nonce rate on chain[%d]!!!      total [%d] times\n",chain,low_rate_error
               );
      }
      fclose(pFVar1);
    }
  }
  if (2 < low_rate_error) {
    stop_scan(0xe,(uint8_t)chain);
  }
  if (check_column_nonce != false) {
    for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
      if ((check_column_nonce == false) ||
         (uVar2 = get_logical_column_by_chip_no(i), uVar2 == scanfreq_info.current_column[chain])) {
        for (m = 0; m < 0xd0; m = m + 1) {
        }
      }
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}

