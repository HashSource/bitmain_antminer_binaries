
int eeprom_set_freq(int chain,int mode,int *buf,uint8_t len)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  uint8_t len_local;
  int *buf_local;
  int mode_local;
  int chain_local;
  FILE *pFile;
  FILE *pFile_1;
  int i;
  
  if ((((dev->chain_exist[chain] == 0) || (!g_is_eeprom_loaded)) || (2 < mode)) || (len < 0x30)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        if (g_is_eeprom_loaded == false) {
          uVar1 = 0xbe7c;
        }
        else {
          uVar1 = 0xbe74;
        }
        fprintf(pFVar2,
                "%s:%d:%s: Invalid parameter: chain = %d, load_done = %s, mode = %d, len = %d.\n",
                "eeprom.c",0x210,"eeprom_set_freq",chain,uVar1 | 0xa0000,mode,(uint)len);
      }
      fclose(pFVar2);
    }
    iVar3 = -1;
  }
  else {
    for (i = 0; i < 0x30; i = i + 1) {
      if ((buf[i] % 5 != 0) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Note: buf[%d] = %d, which is not not multiple of %d\n",
                  "eeprom.c",0x218,"eeprom_set_freq",i,buf[i],5);
        }
        fclose(pFVar2);
      }
      g_eeprom_buf[chain].tuning_ret[mode].freq[i] = (uint8_t)(buf[i] / 5);
    }
    iVar3 = 0;
  }
  return iVar3;
}

