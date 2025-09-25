
/* WARNING: Unknown calling convention */

int Single_Board_Sweep_Test(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  sweep_err_state err_state;
  int res_1;
  _Bool res;
  
  set_sweep_err_state(0,true);
  bitmain_power_off();
  _Var1 = temp_sensor_check();
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : first sensor check res:%d\n","Single_Board_Sweep_Test",(uint)_Var1);
  snprintf(tmp1,0x100,"first sensor check res:%d",(uint)_Var1);
  log_to_file(tmp1,time_stamp);
  if (_Var1) {
    if ((Local_Config_Information->Test_Info).Sweep_Cfg.Force_PT2_Before_Sweep == false) {
      lcd_common_show("Sweep init","waiting...",(char *)0x0);
      iVar2 = sweep_setup(1,gChain,Local_Config_Information,gTest_loop,-1);
      get_sweep_err_state(&err_state);
      if (err_state.consumed != true) {
        show_sweep_setup_err(err_state.err_val);
      }
      if (iVar2 == 0) {
        iVar2 = sweep_doing();
        pf_power_down(gChain);
        submit_test_result_to_mes();
        if (iVar2 == 0) {
          SWEEP_display_result_on_LCD();
          iVar2 = 0;
        }
        else {
          get_sweep_err_state(&err_state);
          if (err_state.consumed != true) {
            show_sweep_setup_err(err_state.err_val);
          }
          iVar2 = 0xc;
        }
      }
      else {
        pf_power_down(gChain);
        iVar2 = 0xc;
      }
    }
    else {
      Single_Board_PT2_Software_Pattern_Test();
      iVar2 = run_sweep_test_after_PT2_test();
    }
  }
  else {
    lcd_common_show("Sensor Check","Err",(char *)0x0);
    bitmain_power_off();
    iVar2 = 0xc;
  }
  return iVar2;
}

