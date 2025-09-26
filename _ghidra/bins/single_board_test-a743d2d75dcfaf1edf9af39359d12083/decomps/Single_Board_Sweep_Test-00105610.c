
/* WARNING: Unknown calling convention */

int Single_Board_Sweep_Test(void)

{
  _Bool _Var1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char time_stamp [48];
  char tmp1 [2048];
  char lcd_data2 [16];
  char lcd_data1 [16];
  int res;
  uint32_t err_value;
  uint32_t err_code;
  int ret;
  
  g_sweep_err_code = 0;
  if ((Local_Config_Information->Test_Info).Sweep_Cfg.Force_PT2_Before_Sweep == false) {
    lcd_common_show("Sweep init","waiting...",(char *)0x0);
    iVar2 = sweep_setup(1,gChain,Local_Config_Information,gTest_loop,-1);
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
        memset(lcd_data1,0,0x10);
        memset(lcd_data1,0,0x10);
        uVar3 = g_sweep_err_code & 0xff;
        uVar4 = g_sweep_err_code >> 8 & 0xff;
        if (uVar3 == 1) {
          builtin_strncpy(lcd_data1,"TEMP TOO HIG",0xc);
          lcd_data1[0xc] = 'H';
          lcd_data1[0xd] = '\0';
          sprintf(lcd_data2,"TEMP:%2d",uVar4);
        }
        else if (uVar3 == 2) {
          builtin_strncpy(lcd_data1,"TEMP TOO LOW",0xc);
          lcd_data1._12_2_ = lcd_data1._12_2_ & 0xff00;
          sprintf(lcd_data2,"TEMP:%2d",uVar4);
        }
        else if (uVar3 == 3) {
          builtin_strncpy(lcd_data1,"ASIC TEMP HI",0xc);
          lcd_data1[0xc] = 'G';
          lcd_data1[0xd] = 'H';
          lcd_data1[0xe] = '\0';
          sprintf(lcd_data2,"ASIC:%2d",uVar4);
        }
        else if (uVar3 == 5) {
          builtin_strncpy(lcd_data1,"ASIC TEMP DI",0xc);
          lcd_data1[0xc] = 'F';
          lcd_data1[0xd] = 'F';
          lcd_data1[0xe] = '\0';
          sprintf(lcd_data2,"ASIC:%2d",uVar4);
        }
        else if (uVar3 == 6) {
          builtin_strncpy(lcd_data1,"WATER_REVERS",0xc);
          lcd_data1[0xc] = 'E';
          lcd_data1[0xd] = '\0';
        }
        else if (uVar3 == 7) {
          builtin_strncpy(lcd_data1,"FIND ASIC ER",0xc);
          lcd_data1[0xc] = 'R';
          lcd_data1[0xd] = ':';
          lcd_data1[0xe] = '\0';
          sprintf(lcd_data2,"ONLY FIND:%2d",uVar4);
        }
        lcd_common_show("Sweep failed",lcd_data1,lcd_data2);
        iVar2 = 0xc;
      }
    }
    else {
      iVar2 = 0xc;
    }
  }
  else {
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
      printf("%s: ENV TEMP too low/high or gap too large, please test again\n",
             "Single_Board_Sweep_Test");
      builtin_strncpy(tmp1,"ENV TEMP too low/high or gap too large, please test agai",0x38);
      tmp1[0x38] = 'n';
      tmp1[0x39] = '\0';
      log_to_file(tmp1,time_stamp);
      iVar2 = -1;
    }
    else if ((ret == 2) || ((ret & 0xffU) == 3)) {
      lcd_common_show("Find asic failed","Can not do sweep","Please try again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Find asic failed, can not do sweep, please test again\n","Single_Board_Sweep_Test"
            );
      builtin_strncpy(tmp1,"Find asic failed, can not do sweep, please test again",0x36);
      log_to_file(tmp1,time_stamp);
      if (gWater_flow_reversal != false) {
        lcd_common_show("Water flow reversal","Water flow reversal","Water flow reversal");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Water flow reversal!\n","Single_Board_Sweep_Test");
        builtin_strncpy(tmp1,"Water flow reversal!",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
      iVar2 = -1;
    }
    else {
      sleep(2);
      iVar2 = run_sweep_test_after_PT2_test();
    }
  }
  return iVar2;
}

