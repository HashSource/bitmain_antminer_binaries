
/* WARNING: Unknown calling convention */

int Single_Board_PT3_Test(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [2048];
  int ret;
  
  g_sweep_err_code = 0;
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
    ret = Single_Board_PT2_Software_Pattern_Test();
  }
  else {
    ret = Single_Board_PT2_Super_Software_Pattern_Test();
  }
  if (ret == 0xd) {
    lcd_common_show("ENV TEMP error","Or gap too large","Please try again");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ENV TEMP too low/high or gap too large, please test again\n","Single_Board_PT3_Test"
          );
    builtin_strncpy(tmp1,"ENV TEMP too low/high or gap too large, please test agai",0x38);
    tmp1[0x38] = 'n';
    tmp1[0x39] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  else if ((ret == 2) || ((ret & 0xffU) == 3)) {
    lcd_common_show("Find asic failed","Can not do sweep","Please try again");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Find asic failed, can not do sweep, please test again\n","Single_Board_PT3_Test");
    builtin_strncpy(tmp1,"Find asic failed, can not do sweep, please test again",0x36);
    log_to_file(tmp1,time_stamp);
    if (gWater_flow_reversal != false) {
      lcd_common_show("Water flow reversal","Water flow reversal","Water flow reversal");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Water flow reversal!\n","Single_Board_PT3_Test");
      builtin_strncpy(tmp1,"Water flow reversal!",0x14);
      tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
    }
    iVar1 = -1;
  }
  else {
    sleep(2);
    iVar1 = run_sweep_test_after_PT2_test();
  }
  return iVar1;
}

