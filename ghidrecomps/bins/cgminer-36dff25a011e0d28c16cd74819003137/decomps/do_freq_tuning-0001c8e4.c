
/* WARNING: Unknown calling convention */

void do_freq_tuning(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  int iVar3;
  timeval diff;
  timeval end;
  timeval start;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Frequency tuning: start!\n","freq_tuning.c",0xb55,"do_freq_tuning");
    }
    fclose(pFVar2);
  }
  freq_tuning_get_proj_type();
  if (g_BHB91602_proj.proj_type == 3) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Unknown project type, chain asic num is %d\n","freq_tuning.c",
                0xb5a,"do_freq_tuning",0x30);
      }
      fclose(pFVar2);
    }
  }
  else {
    _Var1 = freq_tuning_already_done();
    if (_Var1) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Frequency tuning is alreay done.\n","freq_tuning.c",0xb60,
                  "do_freq_tuning");
        }
        fclose(pFVar2);
      }
    }
    else {
      cgtime(&start);
      freq_scan_status = 0;
      _Var1 = freq_tuning_alloc_works_buffer();
      if (_Var1) {
        iVar3 = freq_tuning_prepare_works();
        if (iVar3 == 0) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: Frequency tuning nonce rate theshold is %.2f\n",
                      "freq_tuning.c",0xb71,"do_freq_tuning");
            }
            fclose(pFVar2);
          }
          freq_tuning_test_based_voltage_domain();
        }
        freq_tuning_free_works_buffer();
        freq_scan_status = 1;
        cgtime(&end);
        diff.tv_sec = end.tv_sec - start.tv_sec;
        if (end.tv_usec - start.tv_usec < 0) {
          diff.tv_sec = diff.tv_sec + -1;
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: \n\n***Frequency tuning: done! time cost %ld minutes***\n\n",
                    "freq_tuning.c",0xb7f,"do_freq_tuning",diff.tv_sec / 0x3c);
          }
          fclose(pFVar2);
        }
      }
    }
  }
  return;
}

