
/* WARNING: Unknown calling convention */

void sweep_freq_send_work_and_check_result(void)

{
  longlong lVar1;
  longlong lVar2;
  FILE *pFVar3;
  int iVar4;
  int chip_00;
  uint logical_col;
  int iVar5;
  FILE *pFile_10;
  FILE *pFile_9;
  int chip;
  int column_freq;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  int column;
  float b_nonce_rate;
  int domain_balance_num;
  float nonce_rate;
  int pass_nonce_num;
  FILE *pFile;
  int row;
  int i;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: send work and check result\n","freq_scan.c",0xb7f,
              "sweep_freq_send_work_and_check_result");
    }
    fclose(pFVar3);
  }
  lVar1 = (longlong)scanfreq_info.AsicWorkCount;
  lVar2 = (longlong)scanfreq_info.AsicWorkCount;
  scan_freq_reset_result();
  scan_freq_send_work();
  for (i = 0; i < 0x10; i = i + 1) {
    if (((dev->chain_exist[i] != 0) && (scanfreq_info.test_done[i] == false)) &&
       (logical_col = (uint)scanfreq_info.current_column[i],
       scanfreq_info.current_column_finish[i][logical_col] == false)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: \n","freq_scan.c",0xb97,"sweep_freq_send_work_and_check_result")
          ;
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] base freq is %d\n","freq_scan.c",0xb98,
                  "sweep_freq_send_work_and_check_result",i,scanfreq_info.base_freq[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] total valid nonce number:    %d\n","freq_scan.c",0xb99
                  ,"sweep_freq_send_work_and_check_result",i,scanfreq_info.valid_nonce_num[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] total send work number:      %d\n","freq_scan.c",0xb9a
                  ,"sweep_freq_send_work_and_check_result",i,scanfreq_info.send_work_num[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] hw nonce number:       %d\n","freq_scan.c",0xb9b,
                  "sweep_freq_send_work_and_check_result",i,scanfreq_info.HW_nonce_num[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] repeated nonce number: %d\n","freq_scan.c",0xb9c,
                  "sweep_freq_send_work_and_check_result",i,scanfreq_info.repeated_nonce_num[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] other nonce number:    %d\n","freq_scan.c",0xb9d,
                  "sweep_freq_send_work_and_check_result",i,scanfreq_info.other_nonce_num[i]);
        }
        fclose(pFVar3);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] required nonce number:       %d\n","freq_scan.c",0xb9e
                  ,"sweep_freq_send_work_and_check_result",i,(int)((float)lVar1 * 0.99));
        }
        fclose(pFVar3);
      }
      iVar4 = scanfreq_info.base_freq[i];
      iVar5 = scanfreq_info.freq_step * (uint)scanfreq_info.domain_freq_level[i][logical_col];
      for (row = 0; row < 6; row = row + 1) {
        chip_00 = get_physical_chip_no(row,logical_col);
        scanfreq_info.chip_sweep_failed[i][chip_00] = false;
        if ((scanfreq_info.asic_nonce_num[i][chip_00] < (int)((float)lVar1 * 0.99)) &&
           (scanfreq_info.chip_sweep_failed[i][chip_00] = true,
           scanfreq_info.chip_max_freq[i][chip_00] == 0)) {
          scanfreq_info.chip_max_freq[i][chip_00] = scanfreq_info.base_freq[i];
        }
        asic_sweep_stat(i,chip_00,(uint)scanfreq_info.domain_freq_level[i][logical_col],
                        *(_Bool *)(chip_00 + i * 0x100 + 0xb950a4));
        if (scanfreq_info.asic_nonce_num[i][chip_00] <= (int)((float)lVar2 * 0.75)) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"%s:%d:%s: chain %d chip %d nonce num:%d is too low,need to reinit.\n",
                      "freq_scan.c",0xbb6,"sweep_freq_send_work_and_check_result",i,chip_00,
                      scanfreq_info.asic_nonce_num[i][chip_00]);
            }
            fclose(pFVar3);
          }
          scanfreq_info.need_init = true;
        }
        if (scanfreq_info.chip_sweep_failed[i][chip_00] != true) {
          scanfreq_info.chip_max_freq[i][chip_00] = iVar5 + iVar4;
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,
                    "%s:%d:%s: chain %d chip[%03d] nonce %04d, nonce_rate %.2f, max freq %03d, is failed %d\n"
                    ,"freq_scan.c",0xbc1,"sweep_freq_send_work_and_check_result",i,chip_00,
                    scanfreq_info.asic_nonce_num[i][chip_00],
                    (double)((float)(longlong)scanfreq_info.asic_nonce_num[i][chip_00] /
                            (float)(longlong)scanfreq_info.AsicWorkCount),
                    scanfreq_info.chip_max_freq[i][chip_00],
                    (uint)scanfreq_info.chip_sweep_failed[i][chip_00]);
          }
          fclose(pFVar3);
        }
      }
    }
  }
  return;
}

