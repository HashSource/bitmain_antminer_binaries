
int eeprom_set_hash_rate(int chain,int mode,uint32_t hash_rate)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  uint32_t hash_rate_local;
  int mode_local;
  int chain_local;
  FILE *pFile;
  
  if (((dev->chain_exist[chain] == 0) || (!g_is_eeprom_loaded)) || (2 < mode)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        if (g_is_eeprom_loaded == false) {
          uVar1 = 0xbe7c;
        }
        else {
          uVar1 = 0xbe74;
        }
        fprintf(__stream,"%s:%d:%s: Invalid parameter: chain = %d, load_done = %s, mode = %d.\n",
                "eeprom.c",0x231,"eeprom_set_hash_rate",chain,uVar1 | 0xa0000,mode);
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  else {
    g_eeprom_buf[chain].tuning_ret[mode].hash_rate = hash_rate;
    iVar2 = 0;
  }
  return iVar2;
}

