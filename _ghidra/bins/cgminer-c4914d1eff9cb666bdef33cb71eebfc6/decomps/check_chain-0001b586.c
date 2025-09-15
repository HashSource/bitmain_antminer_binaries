
/* WARNING: Unknown calling convention */

int check_chain(void)

{
  int iVar1;
  FILE *pFVar2;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int ret;
  int i;
  
  dev->chain_num = '\0';
  iVar1 = get_hash_on_plug();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: get_hash_on_plug is 0x%x\n","driver-btm-soc.c",0x35d,"check_chain",
              iVar1);
    }
    fclose(pFVar2);
  }
  if (iVar1 < 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get_hash_on_plug functions error\n","driver-btm-soc.c",0x360,
                "check_chain");
      }
      fclose(pFVar2);
    }
    iVar1 = -1;
  }
  else {
    for (i = 0; i < 0x10; i = i + 1) {
      if ((iVar1 >> (i & 0xffU) & 1U) == 0) {
        dev->chain_exist[i] = 0;
      }
      else {
        dev->chain_exist[i] = 1;
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: !! chain[%d]is exist\n","driver-btm-soc.c",0x369,"check_chain"
                    ,i);
          }
          fclose(pFVar2);
        }
        dev->chain_num = dev->chain_num + '\x01';
      }
    }
    if ((dev->chain_num == '\x03') || ((freq_mode != 0 && (freq_mode != 2)))) {
      iVar1 = 0;
    }
    else {
      for (i = 0; i < 3; i = i + 1) {
        if (dev->chain_exist[i] != 1) {
          freq_scan_error_code_set(2,i);
        }
      }
      iVar1 = -1;
    }
  }
  return iVar1;
}

