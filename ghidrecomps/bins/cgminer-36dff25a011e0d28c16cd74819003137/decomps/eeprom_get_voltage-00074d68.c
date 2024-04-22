
int eeprom_get_voltage(int chain,int mode,int *voltage)

{
  uint uVar1;
  FILE *__stream;
  int iVar2;
  int *voltage_local;
  int mode_local;
  int chain_local;
  FILE *pFile;
  
  if (((dev->chain_exist[chain] == 0) || (2 < mode)) || (!g_is_eeprom_loaded)) {
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
        fprintf(__stream,"%s:%d:%s: Error: chain = %d, mode = %d, load_done = %s.\n","eeprom.c",
                0x1ee,"eeprom_get_voltage",chain,mode,uVar1 | 0xa0000);
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  else {
    if (voltage != (int *)0x0) {
      *voltage = (uint)g_eeprom_buf[chain].tuning_ret[mode].voltage;
    }
    iVar2 = 0;
  }
  return iVar2;
}

