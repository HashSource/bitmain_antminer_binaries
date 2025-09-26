
/* WARNING: Unknown calling convention */

_Bool write_EEPROM_PT1_marker(void)

{
  int32_t iVar1;
  char *pcVar2;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t marker_back;
  uint8_t marker;
  _Bool ret;
  
  marker = 'Z';
  marker_back = '\0';
  ret = true;
  if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
      pcVar2 = "false";
    }
    else {
      pcVar2 = "true";
    }
    printf("%s: gEEPROM_OK is %s, so no need write eeprom PT1 marker\n","write_EEPROM_PT1_marker",
           pcVar2);
    if (gHistory_Result[gPattern_test_counter].eeprom_ok == false) {
      pcVar2 = "false";
    }
    else {
      pcVar2 = "true";
    }
    snprintf(tmp1,0x800,"gEEPROM_OK is %s, so no need write eeprom PT1 marker",pcVar2);
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    iVar1 = eeprom_write(gChain,(char)gEEPROM_length + 0xff,&marker,1);
    if (iVar1 == 0) {
      iVar1 = eeprom_read(gChain,(char)gEEPROM_length + 0xff,&marker_back,1);
      if (iVar1 == 0) {
        if (marker_back == 'Z') {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: check marker saved in EEPROM success\n","write_EEPROM_PT1_marker");
          builtin_strncpy(tmp1,"check marker saved in EEPROM success",0x24);
          tmp1[0x24] = '\0';
          log_to_file(tmp1,time_stamp);
          ret = true;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: check EEPROM marker fail. read bak is: 0x%02x\n","write_EEPROM_PT1_marker",
                 (uint)marker_back);
          snprintf(tmp1,0x800,"check EEPROM marker fail. read bak is: 0x%02x",(uint)marker_back);
          log_to_file(tmp1,time_stamp);
          gHistory_Result[gPattern_test_counter].eeprom_ok = false;
          ret = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Read marker from EEPROM fail\n","write_EEPROM_PT1_marker");
        builtin_strncpy(tmp1,"Read marker from EEPROM fail",0x1c);
        tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        gHistory_Result[gPattern_test_counter].eeprom_ok = false;
        ret = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Write marker into EEPROM fail\n","write_EEPROM_PT1_marker");
      builtin_strncpy(tmp1,"Write marker into EEPROM fail",0x1e);
      log_to_file(tmp1,time_stamp);
      gHistory_Result[gPattern_test_counter].eeprom_ok = false;
      ret = false;
    }
  }
  return ret;
}

