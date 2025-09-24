
_Bool set_pattern_test_voltage_by_step
                (uint32_t pre_voltage,uint32_t target_voltage,uint8_t step_num)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int32_t iVar6;
  char extraout_r1;
  char extraout_r1_00;
  int iVar7;
  uint8_t step_num_local;
  uint32_t target_voltage_local;
  uint32_t pre_voltage_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t step_length;
  uint8_t target_N;
  uint8_t pre_N;
  uint8_t i;
  uint8_t setting_N;
  uint8_t N_gap;
  float vol;
  int i_1;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : pre_voltage = %d, target_voltage = %d, step_num = %d\n",
         "set_pattern_test_voltage_by_step",pre_voltage,target_voltage,(uint)step_num);
  snprintf(tmp1,0x100,"pre_voltage = %d, target_voltage = %d, step_num = %d",pre_voltage,
           target_voltage,(uint)step_num);
  log_to_file(tmp1,time_stamp);
  if ((((g_apw_power_version == 0x62) || (g_apw_power_version == 100)) ||
      (g_apw_power_version == 0x65)) || (g_apw_power_version == 0x66)) {
    iVar7 = target_voltage - pre_voltage;
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (0 < iVar7) {
      step_num_local = step_num;
      if (step_num == '\0') {
        step_num_local = '\x01';
      }
      for (i_1 = 1; i_1 < (int)(step_num_local + 1); i_1 = i_1 + 1) {
        if (pre_voltage < target_voltage) {
          iVar7 = __aeabi_uidiv(i_1 * (target_voltage - pre_voltage),step_num_local);
        }
        else {
          iVar7 = __aeabi_uidiv(i_1 * (pre_voltage - target_voltage),step_num_local);
          iVar7 = -iVar7;
        }
        vol = (float)(pre_voltage + iVar7) / 100.0;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bitmain_set_voltage step %d to %f\n","set_pattern_test_voltage_by_step",i_1);
        snprintf(tmp1,0x100,"bitmain_set_voltage step %d to %f",i_1,(double)vol);
        log_to_file(tmp1,time_stamp);
        bitmain_set_voltage((double)vol);
      }
    }
  }
  else {
    setting_N = '\0';
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pre_voltage = %d, target_voltage = %d, step_num = %d\n",
           "set_pattern_test_voltage_by_step",pre_voltage,target_voltage,(uint)step_num);
    snprintf(tmp1,0x100,"pre_voltage = %d, target_voltage = %d, step_num = %d",pre_voltage,
             target_voltage,(uint)step_num);
    log_to_file(tmp1,time_stamp);
    uVar4 = bitmain_convert_V_to_N((double)pre_voltage / 100.0);
    bVar1 = (byte)uVar4;
    uVar5 = bitmain_convert_V_to_N((double)target_voltage / 100.0);
    bVar2 = (byte)uVar5;
    if ((uVar5 & 0xff) < (uVar4 & 0xff)) {
      N_gap = bVar1 - bVar2;
    }
    else {
      if ((uVar5 & 0xff) <= (uVar4 & 0xff)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : target_voltage = pre_voltage. Don\'t need do anything.\n",
               "set_pattern_test_voltage_by_step");
        builtin_strncpy(tmp1,"target_voltage = pre_voltage. Don\'t need do anything",0x34);
        tmp1[0x34] = '.';
        tmp1[0x35] = '\0';
        log_to_file(tmp1,time_stamp);
        return true;
      }
      N_gap = bVar2 - bVar1;
    }
    bVar3 = __aeabi_uidiv(N_gap,step_num);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pre_N = %d, target_N = %d, N_gap = %d, step_length = %d\n",
           "set_pattern_test_voltage_by_step",uVar4 & 0xff,uVar5 & 0xff,(uint)N_gap,(uint)bVar3);
    snprintf(tmp1,0x100,"pre_N = %d, target_N = %d, N_gap = %d, step_length = %d",uVar4 & 0xff,
             uVar5 & 0xff,(uint)N_gap,(uint)bVar3);
    log_to_file(tmp1,time_stamp);
    if (bVar3 == 0) {
      for (i = '\0'; i < N_gap; i = i + '\x01') {
        if ((uVar5 & 0xff) < (uVar4 & 0xff)) {
          setting_N = bVar1 - 1;
        }
        else {
          setting_N = bVar1 + 1;
        }
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : setting_N = %d\n","set_pattern_test_voltage_by_step",(uint)setting_N);
      snprintf(tmp1,0x100,"setting_N = %d",(uint)setting_N);
      log_to_file(tmp1,time_stamp);
      iVar6 = bitmain_set_voltage_by_n(setting_N);
      if ((iVar6 != 0) && (iVar6 = bitmain_set_voltage_by_n(setting_N), iVar6 != 0)) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Set APW voltage");
        lcd_show(2,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Set APW voltage by N fail\n","set_pattern_test_voltage_by_step");
        builtin_strncpy(tmp1,"Set APW voltage by N fail",0x1a);
        log_to_file(tmp1,time_stamp);
        return false;
      }
    }
    else {
      for (i = '\0'; i < step_num; i = i + '\x01') {
        if (i == '\0') {
          if (bVar2 < bVar1) {
            __aeabi_uidivmod(N_gap,step_num);
            setting_N = (bVar1 - bVar3) - extraout_r1;
          }
          else {
            __aeabi_uidivmod(N_gap,step_num);
            setting_N = extraout_r1_00 + bVar3 + bVar1;
          }
        }
        else if (bVar2 < bVar1) {
          setting_N = setting_N - bVar3;
        }
        else {
          setting_N = bVar3 + setting_N;
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : setting_N = %d\n","set_pattern_test_voltage_by_step",(uint)setting_N);
        snprintf(tmp1,0x100,"setting_N = %d",(uint)setting_N);
        log_to_file(tmp1,time_stamp);
        uVar4 = bitmain_set_voltage_by_n(setting_N);
        if ((uVar4 != setting_N) &&
           (uVar4 = bitmain_set_voltage_by_n(setting_N), uVar4 != setting_N)) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Set APW voltage");
          lcd_show(2,"fail");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Set APW voltage by N = %d fail\n","set_pattern_test_voltage_by_step",
                 (uint)setting_N);
          snprintf(tmp1,0x100,"Set APW voltage by N = %d fail",(uint)setting_N);
          log_to_file(tmp1,time_stamp);
          return false;
        }
      }
    }
  }
  return true;
}

