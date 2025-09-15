
/* WARNING: Unknown calling convention */

int get_eeprom_total_hash_rate(void)

{
  uint32_t hashrate_tmp;
  FILE *pFile;
  int work_mode;
  int total_rate;
  int chain;
  
  total_rate = 0;
  hashrate_tmp = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      work_mode = (int)(opt_bitmain_economic_mode == false);
      eeprom_get_hash_rate(chain,work_mode,&hashrate_tmp);
      total_rate = total_rate + hashrate_tmp;
      usleep(100000);
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: total rate = %d\n","driver-btm-soc.c",0x68e,
              "get_eeprom_total_hash_rate",total_rate);
    }
    fclose((FILE *)pFile);
  }
  return total_rate;
}

