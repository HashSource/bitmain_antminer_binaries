
/* WARNING: Unknown calling convention */

void boardsweep_send_work_and_check_result(void)

{
  longlong lVar1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  int index;
  int chain_ideal_hash_rate;
  int chain_max_hash_rate;
  float chain_nonce_rate;
  float nonce_rate;
  int pass_nonce_num;
  FILE *pFile;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: send work and check result\n","freq_scan.c",0xf27,
              "boardsweep_send_work_and_check_result");
    }
    fclose(pFVar2);
  }
  lVar1 = (longlong)scanfreq_info.AsicWorkCount;
  scan_freq_reset_result();
  scan_freq_send_work();
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      iVar3 = scanfreq_info.valid_nonce_num[chain];
      iVar4 = scanfreq_info.send_work_num[chain];
      iVar5 = scanfreq_info.base_freq[chain];
      iVar6 = scanfreq_info.ideal_hash_rate_index[chain];
      scanfreq_info.ideal_hash_rate_freq[chain][iVar6] = scanfreq_info.base_freq[chain];
      scanfreq_info.ideal_hash_rate[chain][iVar6] =
           (int)((float)(longlong)((iVar5 * 0x30c0) / 1000) *
                ((float)(longlong)iVar3 / (float)(longlong)iVar4));
      scanfreq_info.ideal_hash_rate_index[chain] = scanfreq_info.ideal_hash_rate_index[chain] + 1;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: \n","freq_scan.c",0xf43,"boardsweep_send_work_and_check_result")
          ;
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] freq is %d, nonce_rate is %.3f, ideal hash %d\n",
                  "freq_scan.c",0xf45,"boardsweep_send_work_and_check_result",chain,
                  scanfreq_info.base_freq[chain]);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] total valid nonce number:    %d\n","freq_scan.c",0xf46
                  ,"boardsweep_send_work_and_check_result",chain,
                  scanfreq_info.valid_nonce_num[chain]);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] total send work number:      %d\n","freq_scan.c",0xf47
                  ,"boardsweep_send_work_and_check_result",chain,scanfreq_info.send_work_num[chain])
          ;
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] hw nonce number:       %d\n","freq_scan.c",0xf48,
                  "boardsweep_send_work_and_check_result",chain,scanfreq_info.HW_nonce_num[chain]);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] repeated nonce number: %d\n","freq_scan.c",0xf49,
                  "boardsweep_send_work_and_check_result",chain,
                  scanfreq_info.repeated_nonce_num[chain]);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] other nonce number:    %d\n","freq_scan.c",0xf4a,
                  "boardsweep_send_work_and_check_result",chain,scanfreq_info.other_nonce_num[chain]
                 );
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] required nonce number:       %d\n","freq_scan.c",0xf4b
                  ,"boardsweep_send_work_and_check_result",chain,(int)((float)lVar1 * 0.98));
        }
        fclose(pFVar2);
      }
    }
  }
  return;
}

