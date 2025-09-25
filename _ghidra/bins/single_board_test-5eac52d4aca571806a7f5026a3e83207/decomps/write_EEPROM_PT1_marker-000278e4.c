
/* WARNING: Unknown calling convention */

_Bool write_EEPROM_PT1_marker(void)

{
  char time_stamp [48];
  char tmp1 [256];
  uint8_t marker_back;
  uint8_t marker;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : do not write EEPROM PT1_marker for remote/customer repair mode\n",
         "write_EEPROM_PT1_marker");
  builtin_strncpy(tmp1,"do not write EEPROM PT1_marker for remote/customer repair mo",0x3c);
  tmp1[0x3c] = 'd';
  tmp1[0x3d] = 'e';
  tmp1[0x3e] = '\0';
  log_to_file(tmp1,time_stamp);
  return true;
}

