
uint16_t eeprom_get_pcb_version(int chain)

{
  uint uVar1;
  FILE *__stream;
  uint16_t uVar2;
  int chain_local;
  FILE *pFile;
  
  if ((dev->chain_exist[chain] == 0) || (!g_is_eeprom_loaded)) {
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
        fprintf(__stream,"%s:%d:%s: Error: chain = %d, load_done = %s\n","eeprom.c",0x1ab,
                "eeprom_get_pcb_version",chain,uVar1 | 0xa0000);
      }
      fclose(__stream);
    }
    uVar2 = 0xffff;
  }
  else {
    uVar2 = g_eeprom_buf[chain].pcb_version;
  }
  return uVar2;
}

