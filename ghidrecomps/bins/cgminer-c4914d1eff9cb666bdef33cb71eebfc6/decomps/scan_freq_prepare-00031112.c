
/* WARNING: Unknown calling convention */

int scan_freq_prepare(void)

{
  FILE *pFVar1;
  int iVar2;
  FILE *pFile_1;
  FILE *pFile;
  int ret;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: scan_freq_prepare\n","freq_scan.c",0x37e,"scan_freq_prepare");
    }
    fclose(pFVar1);
  }
  scan_freq_init_info();
  iVar2 = scanfreq_get_works();
  if (iVar2 < 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: scanfreq get works failed\n","freq_scan.c",900,"scan_freq_prepare"
               );
      }
      fclose(pFVar1);
    }
    iVar2 = -1;
  }
  else {
    pthread_create(&receive_id,(pthread_attr_t *)0x0,scanfreq_receive_nonce_register + 1,(void *)0x0
                  );
    pthread_detach(receive_id);
    iVar2 = 0;
  }
  return iVar2;
}

