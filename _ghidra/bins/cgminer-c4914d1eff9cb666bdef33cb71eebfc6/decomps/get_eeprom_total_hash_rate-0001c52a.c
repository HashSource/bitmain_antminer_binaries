
/* WARNING: Unknown calling convention */

int get_eeprom_total_hash_rate(void)

{
  _Bool _Var1;
  int iVar2;
  bool bVar3;
  int hashrate_tmp;
  FILE *pFile;
  FILE *pFile_1;
  int try_times;
  int total_rate;
  int chain;
  
  total_rate = 0;
  hashrate_tmp = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      try_times = 3;
      do {
        _Var1 = is_economic_mode();
        if (_Var1) {
          eeprom_get_hashrate_mode1((uint8_t)chain,(uint32_t *)&hashrate_tmp);
        }
        else {
          eeprom_get_hashrate_mode2((uint8_t)chain,(uint32_t *)&hashrate_tmp);
        }
      } while ((hashrate_tmp == 0) &&
              (iVar2 = try_times + -1, bVar3 = try_times != 0, try_times = iVar2, bVar3));
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: chain[%d] hash rate = %d\n","driver-btm-soc.c",0x4ae,
                  "get_eeprom_total_hash_rate",chain,hashrate_tmp);
        }
        fclose((FILE *)pFile);
      }
      total_rate = hashrate_tmp + total_rate;
      usleep(100000);
    }
  }
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFile_1 = (FILE *)fopen(log_file,"a+");
    if (pFile_1 != (FILE *)0x0) {
      fprintf((FILE *)pFile_1,"%s:%d:%s: total rate = %d\n","driver-btm-soc.c",0x4b2,
              "get_eeprom_total_hash_rate",total_rate);
    }
    fclose((FILE *)pFile_1);
  }
  return total_rate;
}

