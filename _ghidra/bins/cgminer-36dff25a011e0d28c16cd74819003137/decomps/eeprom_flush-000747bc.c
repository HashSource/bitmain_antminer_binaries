
/* WARNING: Unknown calling convention */

int eeprom_flush(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  int chain;
  
  ret = 0;
  if (g_is_eeprom_loaded) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        uVar1 = _eeprom_flush_one_chain(chain,g_eeprom_buf + chain);
        ret = ret | uVar1;
      }
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Note: Can\'t flush EEPROM data without load.\n","eeprom.c",0x18b
                ,"eeprom_flush");
      }
      fclose(__stream);
    }
    ret = -1;
  }
  return ret;
}

