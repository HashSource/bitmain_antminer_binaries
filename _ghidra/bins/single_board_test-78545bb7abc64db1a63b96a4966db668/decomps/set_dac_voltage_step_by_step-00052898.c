
_Bool set_dac_voltage_step_by_step
                (char *board_name,uint8_t which_chain,uint32_t pre_voltage,uint32_t target_voltage,
                uint8_t step_num)

{
  _Bool _Var1;
  int extraout_r1;
  int extraout_r1_00;
  int iVar2;
  uint32_t target_voltage_local;
  uint32_t pre_voltage_local;
  uint8_t which_chain_local;
  char *board_name_local;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t target_N;
  uint32_t pre_N;
  uint8_t step_length;
  uint8_t i;
  uint32_t setting_N;
  uint32_t N_gap;
  
  N_gap = 0;
  pre_N = 0;
  target_N = 0;
  setting_N = 0;
  step_length = '\0';
  i = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pre_voltage = %d, target_voltage = %d, step_num = %d\n",
         "set_dac_voltage_step_by_step",pre_voltage,target_voltage,(uint)step_num);
  snprintf(tmp1,0x100,"pre_voltage = %d, target_voltage = %d, step_num = %d",pre_voltage,
           target_voltage,(uint)step_num);
  log_to_file(tmp1,time_stamp);
  _Var1 = convert_V_to_N(board_name,(double)pre_voltage / 100.0,&pre_N);
  if (_Var1) {
    _Var1 = convert_V_to_N(board_name,(double)target_voltage / 100.0,&target_N);
    if (_Var1) {
      if (target_N < pre_N) {
        N_gap = pre_N - target_N;
      }
      else {
        if (target_N <= pre_N) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : target_voltage = pre_voltage. Don\'t need do anything.\n",
                 "set_dac_voltage_step_by_step");
          builtin_strncpy(tmp1,"target_voltage = pre_voltage. Don\'t need do anything",0x34);
          tmp1[0x34] = '.';
          tmp1[0x35] = '\0';
          log_to_file(tmp1,time_stamp);
          return true;
        }
        N_gap = target_N - pre_N;
      }
      step_length = __aeabi_uidiv(N_gap,step_num);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pre_N = %d, target_N = %d, N_gap = %d, step_length = %d\n",
             "set_dac_voltage_step_by_step",pre_N,target_N,N_gap,(uint)step_length);
      snprintf(tmp1,0x100,"pre_N = %d, target_N = %d, N_gap = %d, step_length = %d",pre_N,target_N,
               N_gap,(uint)step_length);
      log_to_file(tmp1,time_stamp);
      if (step_length == '\0') {
        for (i = '\0'; i < N_gap; i = i + '\x01') {
          if (target_N < pre_N) {
            setting_N = pre_N - 1;
          }
          else {
            setting_N = pre_N + 1;
          }
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : setting_N = %d\n","set_dac_voltage_step_by_step",setting_N);
        snprintf(tmp1,0x100,"setting_N = %d",setting_N);
        log_to_file(tmp1,time_stamp);
        _Var1 = set_voltage_by_N(board_name,which_chain,setting_N);
        if (!_Var1) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Set ADC voltage");
          lcd_show(2,"fail");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Set adc voltage by N fail\n","set_dac_voltage_step_by_step");
          builtin_strncpy(tmp1,"Set adc voltage by N fail",0x1a);
          log_to_file(tmp1,time_stamp);
          return false;
        }
      }
      else {
        for (i = '\0'; i < step_num; i = i + '\x01') {
          if (i == '\0') {
            if (target_N < pre_N) {
              iVar2 = pre_N - step_length;
              __aeabi_uidivmod(N_gap,step_num);
              setting_N = iVar2 - extraout_r1;
            }
            else {
              iVar2 = step_length + pre_N;
              __aeabi_uidivmod(N_gap,step_num);
              setting_N = extraout_r1_00 + iVar2;
            }
          }
          else if (target_N < pre_N) {
            setting_N = setting_N - step_length;
          }
          else {
            setting_N = step_length + setting_N;
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : setting_N = %d, step=%d\n","set_dac_voltage_step_by_step",setting_N,(uint)i);
          snprintf(tmp1,0x100,"setting_N = %d, step=%d",setting_N,(uint)i);
          log_to_file(tmp1,time_stamp);
          _Var1 = set_voltage_by_N(board_name,which_chain,setting_N);
          if (!_Var1) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"Set ADC voltage");
            lcd_show(2,"fail");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Set adc voltage by N = %d fail\n","set_dac_voltage_step_by_step",setting_N)
            ;
            snprintf(tmp1,0x100,"Set adc voltage by N = %d fail",setting_N);
            log_to_file(tmp1,time_stamp);
            return false;
          }
          usleep(300000);
        }
      }
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

