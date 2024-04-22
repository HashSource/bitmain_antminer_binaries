
/* WARNING: Unknown calling convention */

void eeprom_dump(void)

{
  FILE *__stream;
  FILE *pFile;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,">>>> EEPROM of Chain %d:\n",chain);
        }
        fclose(__stream);
      }
      _eeprom_dump(g_eeprom_buf + chain);
    }
  }
  return;
}

