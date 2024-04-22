
_Bool is_eeprom_chain_load_succeeded(uint8_t chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint8_t chain_local;
  FILE *pFile;
  FILE *pFile_1;
  
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] does not exist\n","eeprom.c",0x51,
                "is_eeprom_chain_load_succeeded",(uint)chain);
      }
      fclose(pFVar2);
    }
    _Var1 = false;
  }
  else if ((state_is_eeprom_all_chain_load_succeeded) || (_Var1 = eeprom_load(), _Var1)) {
    _Var1 = true;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d]: data load from eeprom to dram fail\n","eeprom.c",0x59,
                "is_eeprom_chain_load_succeeded",(uint)chain);
      }
      fclose(pFVar2);
    }
    _Var1 = false;
  }
  return _Var1;
}

