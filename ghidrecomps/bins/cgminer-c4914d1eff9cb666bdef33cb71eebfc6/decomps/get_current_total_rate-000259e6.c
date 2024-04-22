
/* WARNING: Unknown calling convention */

int get_current_total_rate(void)

{
  int iVar1;
  FILE *pFVar2;
  FILE *pFile;
  FILE *pFile_1;
  int tmp_rate;
  int tmp_freq;
  int total_rate;
  int chip;
  int chain;
  
  total_rate = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      tmp_freq = 0;
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        tmp_freq = tmp_freq + scan_result[chain].freq_eeprom[chip];
      }
      iVar1 = (tmp_freq * 0xd0) / 1000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] hash rate = %d\n","driver-btm-soc.c",0x1657,
                  "get_current_total_rate",chain,iVar1);
        }
        fclose(pFVar2);
      }
      total_rate = iVar1 + total_rate;
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: total rate = %d\n","driver-btm-soc.c",0x165b,
              "get_current_total_rate",total_rate);
    }
    fclose(pFVar2);
  }
  return total_rate;
}

