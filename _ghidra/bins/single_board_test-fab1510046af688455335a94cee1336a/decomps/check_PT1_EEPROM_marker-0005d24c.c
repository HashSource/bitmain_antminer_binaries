
/* WARNING: Unknown calling convention */

_Bool check_PT1_EEPROM_marker(void)

{
  int32_t iVar1;
  int iVar2;
  bool bVar3;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t marker_back;
  int counter;
  int32_t ret;
  
  marker_back = '\0';
  ret = 0;
  counter = 3;
  while (iVar2 = counter + -1, bVar3 = counter != 0, counter = iVar2, bVar3) {
    iVar1 = eeprom_read(gChain,(char)gEEPROM_length + 0xff,&marker_back,1);
    if ((iVar1 == 0) && (ret = 0, marker_back == 'Z')) break;
    ret = -1;
  }
  bVar3 = ret != -1;
  if (bVar3) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PT1 marker got...\n","check_PT1_EEPROM_marker");
    builtin_strncpy(tmp1,"PT1 marker got..",0x10);
    tmp1[0x10] = '.';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"This hashboard");
    lcd_show(2,"didn\'t do PT1");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PT1 marker is 0x%02x...\n","check_PT1_EEPROM_marker",(uint)marker_back);
    snprintf(tmp1,0x800,"PT1 marker is 0x%02x...",(uint)marker_back);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: This board didn\'t do PT1\n","check_PT1_EEPROM_marker");
    builtin_strncpy(tmp1,"This board didn\'t do PT1",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return bVar3;
}

