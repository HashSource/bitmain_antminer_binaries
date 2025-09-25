
_Bool Check_EEPROM(uint32_t EEPROM_length)

{
  uint32_t EEPROM_length_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : do not Check EEPROM for remote/customer repair mode\n","Check_EEPROM");
  builtin_strncpy(tmp1,"do not Check EEPROM for remote/customer repair mode",0x34);
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].eeprom_ok = true;
  return true;
}

