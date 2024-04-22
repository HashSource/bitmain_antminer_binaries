
/* WARNING: Unknown calling convention */

void scan_freq_send_work_and_check_result(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  FILE *pFile_9;
  FILE *pFile_10;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int pass_nonce_num;
  _Bool is_pass;
  int i;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: send work and check result\n","freq_scan.c",0x45c,
              "scan_freq_send_work_and_check_result");
    }
    fclose(pFVar1);
  }
  if (check_column_nonce == false) {
    scanfreq_info.RequiredChainNonce = scanfreq_info.AsicNum * scanfreq_info.AsicWorkCount;
  }
  else {
    scanfreq_info.RequiredChainNonce = (scanfreq_info.AsicNum * scanfreq_info.AsicWorkCount) / 10;
  }
  pass_nonce_num =
       (int)(scanfreq_info.PassNonceRate * (float)(longlong)scanfreq_info.RequiredChainNonce);
  scan_freq_reset_result();
  scan_freq_send_work();
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] != 0) && (scanfreq_info.test_done[i] == false)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: \n","freq_scan.c",0x477,"scan_freq_send_work_and_check_result");
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] base freq is %d\n","freq_scan.c",0x478,
                  "scan_freq_send_work_and_check_result",i,scanfreq_info.base_freq[i]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] total valid nonce number:    %d\n","freq_scan.c",0x479
                  ,"scan_freq_send_work_and_check_result",i,scanfreq_info.valid_nonce_num[i]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] total send work number:      %d\n","freq_scan.c",0x47a
                  ,"scan_freq_send_work_and_check_result",i,scanfreq_info.send_work_num[i]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] require valid nonce number:  %d\n","freq_scan.c",0x47b
                  ,"scan_freq_send_work_and_check_result",i,pass_nonce_num);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] hw nonce number:       %d\n","freq_scan.c",0x47c,
                  "scan_freq_send_work_and_check_result",i,scanfreq_info.HW_nonce_num[i]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] repeated nonce number: %d\n","freq_scan.c",0x47d,
                  "scan_freq_send_work_and_check_result",i,scanfreq_info.repeated_nonce_num[i]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] other nonce number:    %d\n","freq_scan.c",0x47e,
                  "scan_freq_send_work_and_check_result",i,scanfreq_info.other_nonce_num[i]);
        }
        fclose(pFVar1);
      }
      if (check_nonce_rate == false) {
        is_pass = scan_freq_check_result(i);
      }
      else {
        iVar2 = scanfreq_info.valid_nonce_num[i];
        iVar3 = iVar2;
        if (pass_nonce_num < iVar2) {
          iVar3 = 1;
        }
        is_pass = SUB41(iVar3,0);
        if (iVar2 <= pass_nonce_num) {
          is_pass = false;
        }
      }
      if (is_pass == false) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: chain[%d] freq scan failed!\n","freq_scan.c",0x48e,
                    "scan_freq_send_work_and_check_result",i);
          }
          fclose(pFVar1);
        }
      }
      else if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] freq scan success!\n","freq_scan.c",0x488,
                  "scan_freq_send_work_and_check_result",i);
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

