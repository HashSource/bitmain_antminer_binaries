
/* WARNING: Unknown calling convention */

_Bool check_PT1_EEPROM_marker(void)

{
  char time_stamp [48];
  char tmp1 [256];
  uint8_t marker_back;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : PT1 marker got... in customer repair mode\n","check_PT1_EEPROM_marker");
  builtin_strncpy(tmp1,"PT1 marker got... in customer repair mod",0x28);
  tmp1[0x28] = 'e';
  tmp1[0x29] = '\0';
  log_to_file(tmp1,time_stamp);
  return true;
}

