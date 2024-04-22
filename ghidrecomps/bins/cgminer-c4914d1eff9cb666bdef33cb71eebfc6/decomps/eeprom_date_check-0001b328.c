
/* WARNING: Unknown calling convention */

int eeprom_date_check(void)

{
  _Bool _Var1;
  FILE *__stream;
  int iVar2;
  FILE *pFile;
  
  _Var1 = eeprom_load();
  if (_Var1) {
    iVar2 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: eeprom_load failed\n","driver-btm-soc.c",0x268,
                "eeprom_date_check");
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  return iVar2;
}

