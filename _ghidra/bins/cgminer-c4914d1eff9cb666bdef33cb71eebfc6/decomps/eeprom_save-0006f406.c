
/* WARNING: Unknown calling convention */

_Bool eeprom_save(void)

{
  byte bVar1;
  byte bVar2;
  _Bool _Var3;
  FILE *pFVar4;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  uint8_t magic_num;
  _Bool save_flag;
  int j;
  int i;
  int try_time;
  
  if (!state_is_eeprom_all_chain_load_succeeded) {
    print_crt_time_to_file(log_file,1);
    pFVar4 = fopen(log_file,"a+");
    if (pFVar4 != (FILE *)0x0) {
      fprintf(pFVar4,"Assert fail!! %s:%d: warning: eeprom data hasnot been loaded into dram \n!",
              "eeprom.c",0x4f7);
    }
    fclose(pFVar4);
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","eeprom.c",0x4f7,"eeprom_save");
  }
  i = 0;
  do {
    if (0xf < i) {
      memset(eeprom_info,0,0x1000);
      for (j = 0; j < 0x10; j = j + 1) {
        state_is_eeprom_chain_load_succeeded[j] = false;
      }
      state_is_eeprom_all_chain_load_succeeded = false;
      return true;
    }
    if (dev->chain_exist[i] != 0) {
      try_time = 0;
      bVar1 = array_read_one_byte('\0',(uint8_t)i);
      bVar2 = eeprom_target_eeprom_version();
      if (bVar1 != bVar2) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar4 = fopen(log_file,"a+");
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: Warning, eeprom magic:%d number is wrong!\n","eeprom.c",0x50a,
                    "eeprom_save",(uint)bVar1);
          }
          fclose(pFVar4);
        }
        eeprom_dump_for_debug();
        freq_scan_error_code_set(3,i);
        return false;
      }
      do {
        _Var3 = eeprom_write_full_length((uint8_t)i,eeprom_info[i]);
        try_time = try_time + 1;
        if (3 < try_time) break;
      } while (!_Var3);
      if (!_Var3) {
        eeprom_dump_for_debug();
        freq_scan_error_code_set(3,i);
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar4 = fopen(log_file,"a+");
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: eeprom [%d] save fail! Please check the eeprom chip. \n",
                    "eeprom.c",0x51a,"eeprom_save",i);
          }
          fclose(pFVar4);
        }
        return false;
      }
    }
    i = i + 1;
  } while( true );
}

