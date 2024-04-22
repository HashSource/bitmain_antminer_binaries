
/* WARNING: Unknown calling convention */

_Bool need_mode2_startup(void)

{
  double dVar1;
  uint32_t chain_ideal_hash_rate;
  FILE *pFile_1;
  FILE *pFile;
  float chain_rt_hash_rate;
  _Bool mode0_failed;
  int chain;
  
  mode0_failed = false;
  for (chain = 0; chain < (int)(uint)dev->chain_num; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      dVar1 = atof(displayed_rate[chain]);
      chain_rt_hash_rate = (float)dVar1;
      eeprom_get_hashrate_mode2((uint8_t)chain,&chain_ideal_hash_rate);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: chain %d rt_hash_rate %.2f ideal_hash_rate %d\n",
                  "driver-btm-soc.c",0x18e4,"need_mode2_startup",chain,(double)chain_rt_hash_rate,
                  chain_ideal_hash_rate);
        }
        fclose((FILE *)pFile);
      }
      if ((int)((uint)(chain_rt_hash_rate < (float)(ulonglong)(chain_ideal_hash_rate >> 1)) << 0x1f)
          < 0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_1 = (FILE *)fopen(log_file,"a+");
          if (pFile_1 != (FILE *)0x0) {
            fprintf((FILE *)pFile_1,"%s:%d:%s: chain %d startup failed\n","driver-btm-soc.c",0x18e7,
                    "need_mode2_startup",chain);
          }
          fclose((FILE *)pFile_1);
        }
        mode0_failed = true;
      }
    }
  }
  return mode0_failed;
}

