
int eeprom_get_freq(int chain,int mode,uint32_t *buf,int len)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  int len_local;
  uint32_t *buf_local;
  int mode_local;
  int chain_local;
  FILE *pFile;
  int i;
  
  if ((((dev->chain_exist[chain] == 0) || (2 < mode)) || (!g_is_eeprom_loaded)) || (len < 0x30)) {
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
        fprintf(__stream,"%s:%d:%s: Error: chain = %d, mode = %d, load_done = %s, len = %d.\n",
                "eeprom.c",0x1de,"eeprom_get_freq",chain,mode,uVar1 | 0xa0000,len);
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  else {
    for (i = 0; i < 0x30; i = i + 1) {
      buf[i] = (uint)g_eeprom_buf[chain].tuning_ret[mode].freq[i] * 5;
    }
    iVar2 = 0;
  }
  return iVar2;
}

