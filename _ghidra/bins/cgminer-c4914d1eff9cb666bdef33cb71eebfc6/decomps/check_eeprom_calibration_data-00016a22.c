
void check_eeprom_calibration_data(int chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  int chain_local;
  FILE *pFile;
  FILE *pFile_1;
  
  _Var1 = is_eeprom_tempsensor_data_correct((uint8_t)chain);
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] no need to calibrate !\n","temperature.c",0x2e3,
                "check_eeprom_calibration_data",chain);
      }
      fclose(pFVar2);
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] start calibrate ...\n","temperature.c",0x2de,
                "check_eeprom_calibration_data",chain);
      }
      fclose(pFVar2);
    }
    re_calibrate_sensor_offset(0x98,chain);
  }
  return;
}

