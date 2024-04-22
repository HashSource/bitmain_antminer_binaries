
/* WARNING: Unknown calling convention */

void eeprom_load(void)

{
  FILE *pFVar1;
  int iVar2;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  int chain;
  
  if (g_is_eeprom_loaded) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: EEPROM already loaded.\n","eeprom.c",0x155,"eeprom_load");
      }
      fclose(pFVar1);
    }
  }
  else {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        memset(g_eeprom_buf + chain,0xff,0x100);
        memcpy(g_eeprom_buf[chain].hash_board_sn,"deadbeefdeadbeefdead",0x14);
        iVar2 = _eeprom_load_one_chain(chain,g_eeprom_buf + chain);
        if (iVar2 == 0) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: Chain %d EEPROM load success.\n","eeprom.c",0x166,
                      "eeprom_load",chain);
            }
            fclose(pFVar1);
          }
        }
        else if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Chain %d EEPROM data fail, power off the hash board.\n",
                    "eeprom.c",0x16a,"eeprom_load",chain);
          }
          fclose(pFVar1);
        }
      }
    }
    g_is_eeprom_loaded = true;
  }
  return;
}

