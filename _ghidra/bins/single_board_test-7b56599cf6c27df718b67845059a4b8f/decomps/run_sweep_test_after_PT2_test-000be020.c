
/* WARNING: Unknown calling convention */

int run_sweep_test_after_PT2_test(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  
  _Var1 = easy_check_base_PT2_result((uint)gPattern_test_counter);
  if (_Var1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Base PT2 is OK,continue run sweep test...\n","run_sweep_test_after_PT2_test");
    builtin_strncpy(tmp1,"Base PT2 is OK,continue run sweep test...",0x2a);
    log_to_file(tmp1,time_stamp);
    iVar2 = run_sweep_test_after_by_PT2_info((uint)gPattern_test_counter);
  }
  else if (((gHistory_Result[gPattern_test_counter].eeprom_ok == false) ||
           (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK == false)) ||
          ((Local_Config_Information->Hash_Board).Asic_Num != gAsic_num)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Base PT2 is failed cause hal Err,no need sweep.\n","run_sweep_test_after_PT2_test")
    ;
    builtin_strncpy(tmp1,"Base PT2 is failed cause hal Err,no need sweep.",0x30);
    log_to_file(tmp1,time_stamp);
    iVar2 = 0xc;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Base PT2 is fail, run sweep test to matche lowest level\n",
           "run_sweep_test_after_PT2_test");
    builtin_strncpy(tmp1,"Base PT2 is fail, run sweep test to matche lowest level",0x38);
    log_to_file(tmp1,time_stamp);
    iVar2 = run_sweep_test_after_by_PT2_info(-1);
  }
  return iVar2;
}

