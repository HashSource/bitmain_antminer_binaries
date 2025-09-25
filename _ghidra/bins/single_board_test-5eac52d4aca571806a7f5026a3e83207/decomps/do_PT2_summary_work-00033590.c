
int do_PT2_summary_work(uint8_t test_loop_counter)

{
  _Bool _Var1;
  int iVar2;
  uint8_t test_loop_counter_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 eeprom_tmp;
  _Bool temp;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Pattern test done. gPattern_test_counter: %d\n\n","do_PT2_summary_work",
         (uint)test_loop_counter);
  snprintf(tmp1,0x100,"Pattern test done. gPattern_test_counter: %d\n",(uint)test_loop_counter);
  log_to_file(tmp1,time_stamp);
  if (((gHistory_Result[test_loop_counter].test_standard == '\0') &&
      (gHistory_Result[test_loop_counter].asic_ok != false)) &&
     (gHistory_Result[test_loop_counter].nonce_rate_ok != false)) {
    _Var1 = prepare_eeprom_data_pt2((uint)test_loop_counter,true);
    if (!_Var1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"prepare");
      lcd_show(2,"eeprom data");
      lcd_show(3,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : prepare eeprom data fail\n","do_PT2_summary_work");
      builtin_strncpy(tmp1,"prepare eeprom data fail",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      return 0xc;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : do no write eeprom for shmoo/customer repair mode\n\n","do_PT2_summary_work");
    builtin_strncpy(tmp1,"do no write eeprom for shmoo/customer repair mod",0x30);
    tmp1[0x30] = 'e';
    tmp1[0x31] = '\n';
    tmp1[0x32] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  iVar2 = strncmp(Local_Config_Information->Test_Process,"PT2",3);
  if (iVar2 == 0) {
    lcd_common_show("Report data","waiting...",(char *)0x0);
    submit_test_result_to_mes();
  }
  iVar2 = PT2_display_result_on_LCD((uint)test_loop_counter);
  return iVar2;
}

