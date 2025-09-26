
int run_sweep_test_after_by_PT2_info(int8_t test_loop_counter)

{
  _Bool _Var1;
  int iVar2;
  int8_t test_loop_counter_local;
  char time_stamp [48];
  char tmp1 [2048];
  int res;
  
  lcd_common_show("Sweep init","waiting...",(char *)0x0);
  iVar2 = sweep_setup(1,gChain,Local_Config_Information,gTest_loop,(int)test_loop_counter);
  _Var1 = show_sweep_setup_err(iVar2);
  if (_Var1) {
    lcd_common_show("Init done","Sweep doing",(char *)0x0);
    iVar2 = sweep_doing();
    if (iVar2 == 0) {
      submit_test_result_to_mes();
      SWEEP_display_result_on_LCD();
      iVar2 = 0;
    }
    else {
      submit_test_result_to_mes();
      if (iVar2 == 1) {
        lcd_common_show("Find bad asic","Please check first!","Sweep failed");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: find bad asic, please check before next sweep test\n",
               "run_sweep_test_after_by_PT2_info");
        builtin_strncpy(tmp1,"find bad asic, please check before next sweep te",0x30);
        tmp1[0x30] = 's';
        tmp1[0x31] = 't';
        tmp1[0x32] = '\0';
        log_to_file(tmp1,time_stamp);
      }
      else {
        lcd_common_show("Sweep failed",(char *)0x0,(char *)0x0);
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: sweep fail\n","run_sweep_test_after_by_PT2_info");
      builtin_strncpy(tmp1,"sweep fa",8);
      tmp1[8] = 'i';
      tmp1[9] = 'l';
      tmp1[10] = '\0';
      log_to_file(tmp1,time_stamp);
      iVar2 = 0xc;
    }
  }
  else {
    iVar2 = 0xc;
  }
  return iVar2;
}

