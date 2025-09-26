
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Single_Board_Reset_Low_Test(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t asic_num_record [2];
  char lcd_data [16];
  _Bool temp;
  int32_t thread_ret;
  
  gPattern_test_counter = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s, gPattern_test_counter = %d\n","Single_Board_Reset_Low_Test",
         "Single_Board_Reset_Low_Test",(uint)gPattern_test_counter);
  snprintf(tmp1,0x800,"Start %s, gPattern_test_counter = %d","Single_Board_Reset_Low_Test",
           (uint)gPattern_test_counter);
  log_to_file(tmp1,time_stamp);
  _Var1 = init_fpga();
  if (_Var1) {
    fan_turn_on(BOTH_SIZE);
    pwm_set(gFan,(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set fan speed as %d\n","Single_Board_Reset_Low_Test",
           (Local_Config_Information->Test_Info).Fan.Fan_Speed);
    snprintf(tmp1,0x800,"Set fan speed as %d",(Local_Config_Information->Test_Info).Fan.Fan_Speed);
    log_to_file(tmp1,time_stamp);
    reset_global_variables();
    _Var1 = check_chain();
    if (_Var1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set Chain %d baud: %d\n","Single_Board_Reset_Low_Test",gChain,0x1a);
      snprintf(tmp1,0x800,"Set Chain %d baud: %d",gChain,0x1a);
      log_to_file(tmp1,time_stamp);
      set_bt8d_chain(gChain,0x1a);
      reset_register_cache_value_to_default((uint8_t)gChain);
      chain_reset_low(gChain);
      sleep(1);
      gStart_show_on_lcd = true;
      iVar2 = pthread_create(&show_id,(pthread_attr_t *)0x0,(__start_routine *)0x5c6c1,(void *)0x0);
      if (iVar2 == 0) {
        _Var1 = init_pic();
        if (_Var1) {
          _Var1 = APW_power_on(g_power_version,
                               gHistory_Result[gPattern_test_counter].pre_open_core_voltage);
          if (_Var1) {
            _Var1 = pic_power_on_hashboard(gChain);
            if (_Var1) {
              _power_down(gChain);
              gStart_heart_beat = false;
              pthread_join(show_id,(void **)0x0);
              pthread_join(pic_heart_beat_id,(void **)0x0);
            }
            else {
              gStart_heart_beat = false;
              _power_down(gChain);
              pthread_join(show_id,(void **)0x0);
              pthread_join(pic_heart_beat_id,(void **)0x0);
              gHistory_Result[gPattern_test_counter].pic_ok = false;
              lcd_common_show("PIC Power on","fail",(char *)0x0);
            }
          }
          else {
            gStart_show_on_lcd = false;
            pwm_set(gFan,0);
            pthread_join(show_id,(void **)0x0);
          }
        }
        else {
          gStart_show_on_lcd = false;
          pwm_set(gFan,0);
          pthread_join(show_id,(void **)0x0);
        }
      }
      else {
        gStart_show_on_lcd = false;
        pthread_join(show_id,(void **)0x0);
        pwm_set(gFan,0);
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Show thread");
        lcd_show(2,"Creat  fail");
        lcd_show(3,"Start again");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Show thread creat fail, Start again\n","Single_Board_Reset_Low_Test");
        builtin_strncpy(tmp1,"Show thread creat fail, Start again",0x24);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      pwm_set(gFan,0);
    }
  }
  return;
}

