
int do_PT2_summary_work(uint8_t test_loop_counter)

{
  _Bool _Var1;
  int32_t iVar2;
  int iVar3;
  uint8_t test_loop_counter_local;
  char time_stamp [48];
  char tmp1 [2048];
  size_t offset;
  size_t len;
  uint8_t eeprom_data_cmp [256];
  uint8_t eeprom_data [256];
  _Bool temp;
  
  temp = false;
  memset(eeprom_data,0,0x100);
  eeprom_data[0] = 0xff;
  memset(eeprom_data_cmp,0,0x100);
  eeprom_data_cmp[0] = 0xff;
  len = 0x100;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Pattern test done. gPattern_test_counter: %d\n\n","do_PT2_summary_work",
         (uint)test_loop_counter);
  snprintf(tmp1,0x800,"Pattern test done. gPattern_test_counter: %d\n",(uint)test_loop_counter);
  log_to_file(tmp1,time_stamp);
  if (((gHistory_Result[test_loop_counter].test_standard == '\0') &&
      (gHistory_Result[test_loop_counter].asic_ok != false)) &&
     (gHistory_Result[test_loop_counter].nonce_rate_ok != false)) {
    temp = true;
  }
  _Var1 = prepare_eeprom_data_pt2((uint)test_loop_counter,temp,eeprom_data,&len,&offset);
  if (_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: write 0x%x..+0x%x\n","do_PT2_summary_work",offset,len);
    snprintf(tmp1,0x800,"write 0x%x..+0x%x",offset,len);
    log_to_file(tmp1,time_stamp);
    iVar2 = eeprom_write(gChain,(uint8_t)offset,eeprom_data,len);
    if (iVar2 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Write EEPROM ok\n\n","do_PT2_summary_work");
      builtin_strncpy(tmp1,"Write EEPROM ok\n",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar2 = eeprom_read(gChain,(uint8_t)offset,eeprom_data_cmp,len);
      if (iVar2 == 0) {
        iVar3 = memcmp(eeprom_data,eeprom_data_cmp,len);
        if (iVar3 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Write EEPROM ok\n\n","do_PT2_summary_work");
          builtin_strncpy(tmp1,"Write EEPROM ok\n",0x10);
          tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
        }
        else {
          gHistory_Result[test_loop_counter].eeprom_ok = false;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Check EEPROM data fail\n\n","do_PT2_summary_work");
          builtin_strncpy(tmp1,"Check EEPROM data fail\n",0x18);
          log_to_file(tmp1,time_stamp);
        }
      }
      else {
        gHistory_Result[test_loop_counter].eeprom_ok = false;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Read EEPROM fail\n\n","do_PT2_summary_work");
        builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
        tmp1[0x10] = '\n';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
      }
    }
    iVar3 = strncmp(Local_Config_Information->Test_Process,"PT2",3);
    if (iVar3 == 0) {
      submit_test_result_to_mes();
    }
    iVar3 = PT2_display_result_on_LCD((uint)test_loop_counter);
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"prepare");
    lcd_show(2,"eeprom data");
    lcd_show(3,"fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: prepare eeprom data fail\n","do_PT2_summary_work");
    builtin_strncpy(tmp1,"prepare eeprom data fail",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar3 = 0xc;
  }
  return iVar3;
}

