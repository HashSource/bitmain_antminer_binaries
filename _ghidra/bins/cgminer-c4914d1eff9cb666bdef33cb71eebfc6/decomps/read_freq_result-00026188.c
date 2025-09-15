
/* WARNING: Unknown calling convention */

_Bool read_freq_result(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_3;
  _Bool ret;
  int asic;
  int chain;
  
  ret = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      _Var1 = eeprom_get_freq((uint8_t)chain,scan_result[chain].freq_eeprom);
      if (_Var1) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: chain[%d] freq in eeprom is:\n","driver-btm-soc.c",0x1704,
                    "read_freq_result",chain);
          }
          fclose(pFVar2);
        }
        for (asic = 0; asic < 0x3c; asic = asic + 1) {
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"IC[%03d]:%d ",asic,scan_result[chain].freq_eeprom[asic]);
            }
            fclose(pFVar2);
          }
          if (((asic + 1) % 10 == 0) && (3 < log_level)) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fputc(10,pFVar2);
            }
            fclose(pFVar2);
          }
        }
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: Fail to get freq from eeprom of chain %d!\n",
                    "driver-btm-soc.c",0x1710,"read_freq_result",chain);
          }
          fclose(pFVar2);
        }
        freq_scan_error_code_set(3,0xff);
        stop_mining("read freq error!");
        ret = false;
      }
    }
  }
  return ret;
}

