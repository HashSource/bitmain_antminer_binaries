
int run_sweep_test_after_by_PT2_info(int test_loop_counter)

{
  _Bool _Var1;
  int iVar2;
  int test_loop_counter_local;
  char time_stamp [48];
  char tmp1 [256];
  int res;
  
  lcd_common_show("Sweep init","waiting...",(char *)0x0);
  iVar2 = sweep_setup(1,gChain,Local_Config_Information,gTest_loop,test_loop_counter);
  _Var1 = show_sweep_setup_err(iVar2);
  if (_Var1) {
    lcd_common_show("Sweep start","waiting...",(char *)0x0);
    iVar2 = sweep_doing();
    if (iVar2 == 0) {
      SWEEP_display_result_on_LCD();
      iVar2 = 0;
    }
    else {
      show_sweep_failed();
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep fail\n","run_sweep_test_after_by_PT2_info");
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

