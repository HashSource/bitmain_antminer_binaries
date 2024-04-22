
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pcba_app_manual_test(void)

{
  undefined4 local_458;
  undefined4 uStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined4 local_448;
  undefined local_444;
  undefined2 local_28 [10];
  int local_14;
  
  local_14 = 1;
  bm1744_app_init();
  while( true ) {
    if (local_14 == 0) {
      return;
    }
    local_28[0] = 0;
    sleep(1);
    setbuf(stdin,(char *)0x0);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_458._0_1_ = s_Input_test_paramter__00034a68[0];
      local_458._1_1_ = s_Input_test_paramter__00034a68[1];
      local_458._2_1_ = s_Input_test_paramter__00034a68[2];
      local_458._3_1_ = s_Input_test_paramter__00034a68[3];
      uStack_454._0_1_ = s_Input_test_paramter__00034a68[4];
      uStack_454._1_1_ = s_Input_test_paramter__00034a68[5];
      uStack_454._2_1_ = s_Input_test_paramter__00034a68[6];
      uStack_454._3_1_ = s_Input_test_paramter__00034a68[7];
      uStack_450._0_1_ = s_Input_test_paramter__00034a68[8];
      uStack_450._1_1_ = s_Input_test_paramter__00034a68[9];
      uStack_450._2_1_ = s_Input_test_paramter__00034a68[10];
      uStack_450._3_1_ = s_Input_test_paramter__00034a68[11];
      uStack_44c._0_1_ = s_Input_test_paramter__00034a68[12];
      uStack_44c._1_1_ = s_Input_test_paramter__00034a68[13];
      uStack_44c._2_1_ = s_Input_test_paramter__00034a68[14];
      uStack_44c._3_1_ = s_Input_test_paramter__00034a68[15];
      local_448._0_1_ = s_Input_test_paramter__00034a68[16];
      local_448._1_1_ = s_Input_test_paramter__00034a68[17];
      local_448._2_1_ = s_Input_test_paramter__00034a68[18];
      local_448._3_1_ = s_Input_test_paramter__00034a68[19];
      local_444 = (undefined)ram0x00034a7c;
      _applog(2,&local_458,0);
    }
    __isoc99_fscanf(stdin,&DAT_00034a80,local_28);
    if ((byte)local_28[0] - 0x61 < 0x17) break;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      local_458._0_1_ = s_unknow_command_00034c94[0];
      local_458._1_1_ = s_unknow_command_00034c94[1];
      local_458._2_1_ = s_unknow_command_00034c94[2];
      local_458._3_1_ = s_unknow_command_00034c94[3];
      uStack_454._0_1_ = s_unknow_command_00034c94[4];
      uStack_454._1_1_ = s_unknow_command_00034c94[5];
      uStack_454._2_1_ = s_unknow_command_00034c94[6];
      uStack_454._3_1_ = s_unknow_command_00034c94[7];
      uStack_450._0_1_ = s_unknow_command_00034c94[8];
      uStack_450._1_1_ = s_unknow_command_00034c94[9];
      uStack_450._2_1_ = s_unknow_command_00034c94[10];
      uStack_450._3_1_ = s_unknow_command_00034c94[11];
      uStack_44c._0_1_ = s_unknow_command_00034c94[12];
      uStack_44c._1_1_ = s_unknow_command_00034c94[13];
      uStack_44c._2_1_ = s_unknow_command_00034c94[14];
      uStack_44c._3_1_ = s_unknow_command_00034c94[15];
      _applog(1,&local_458,0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000234f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_000234f8 + ((byte)local_28[0] - 0x61) * 4))();
  return;
}

