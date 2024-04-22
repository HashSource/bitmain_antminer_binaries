
int sweep_freq_get_ideal_hashrate(working_mode_e working_mode)

{
  FILE *pFVar1;
  int iVar2;
  working_mode_e working_mode_local;
  int ideal_hash_rate [16];
  int max_hash_rate [16];
  int chip;
  int chain;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int ret;
  _Bool check_column_nonce_bak;
  
  check_column_nonce_bak = check_column_nonce;
  memset(max_hash_rate,0,0x40);
  memset(ideal_hash_rate,0,0x40);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \nget ideal hash rate\n","freq_scan.c",0xce9,
              "sweep_freq_get_ideal_hashrate");
    }
    fclose(pFVar1);
  }
  check_column_nonce = false;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      scanfreq_info.test_done[chain] = false;
      for (chip = 0; chip < 0x100; chip = chip + 1) {
        scan_result[chain].freq_eeprom[chip] =
             *(uint32_t *)
              (scanfreq_info.workdataPathPrefix +
              (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18);
        max_hash_rate[chain] =
             *(int *)(scanfreq_info.workdataPathPrefix +
                     (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) * 0xd0 +
             max_hash_rate[chain];
      }
    }
  }
  need_set_final_freq = true;
  iVar2 = scan_freq_board_init(working_mode);
  if (iVar2 == 0) {
    need_set_final_freq = false;
    scan_freq_reset_result();
    scan_freq_send_work();
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        max_hash_rate[chain] = max_hash_rate[chain] / 1000;
        scanfreq_info.chain_nonce_rate[chain] =
             (float)(longlong)scanfreq_info.valid_nonce_num[chain] /
             (float)(longlong)scanfreq_info.send_work_num[chain];
        ideal_hash_rate[chain] =
             (int)(scanfreq_info.chain_nonce_rate[chain] * (float)(longlong)max_hash_rate[chain]);
        scanfreq_info.max_hashrate[chain] = max_hash_rate[chain];
        scanfreq_info.ideal_hashrate[chain] = ideal_hash_rate[chain];
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] nonce rate:            %.2f\n","freq_scan.c",0xd10,
                    "sweep_freq_get_ideal_hashrate",chain,
                    (double)scanfreq_info.chain_nonce_rate[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] max hashrate:          %d\n","freq_scan.c",0xd11,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.max_hashrate[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] ideal hashrate:        %d\n","freq_scan.c",0xd12,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.ideal_hashrate[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] valid nonce number:    %d\n","freq_scan.c",0xd13,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.valid_nonce_num[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] send work number:      %d\n","freq_scan.c",0xd14,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.send_work_num[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] hw nonce number:       %d\n","freq_scan.c",0xd15,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.HW_nonce_num[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] repeated nonce number: %d\n","freq_scan.c",0xd16,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.repeated_nonce_num[chain]);
          }
          fclose(pFVar1);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] other nonce number:    %d\n\n","freq_scan.c",0xd17,
                    "sweep_freq_get_ideal_hashrate",chain,scanfreq_info.other_nonce_num[chain]);
          }
          fclose(pFVar1);
        }
      }
    }
    check_column_nonce = check_column_nonce_bak;
    iVar2 = 0;
  }
  return iVar2;
}

