
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
      local_458._0_1_ = s_Input_test_paramter__00034f1c[0];
      local_458._1_1_ = s_Input_test_paramter__00034f1c[1];
      local_458._2_1_ = s_Input_test_paramter__00034f1c[2];
      local_458._3_1_ = s_Input_test_paramter__00034f1c[3];
      uStack_454._0_1_ = s_Input_test_paramter__00034f1c[4];
      uStack_454._1_1_ = s_Input_test_paramter__00034f1c[5];
      uStack_454._2_1_ = s_Input_test_paramter__00034f1c[6];
      uStack_454._3_1_ = s_Input_test_paramter__00034f1c[7];
      uStack_450._0_1_ = s_Input_test_paramter__00034f1c[8];
      uStack_450._1_1_ = s_Input_test_paramter__00034f1c[9];
      uStack_450._2_1_ = s_Input_test_paramter__00034f1c[10];
      uStack_450._3_1_ = s_Input_test_paramter__00034f1c[11];
      uStack_44c._0_1_ = s_Input_test_paramter__00034f1c[12];
      uStack_44c._1_1_ = s_Input_test_paramter__00034f1c[13];
      uStack_44c._2_1_ = s_Input_test_paramter__00034f1c[14];
      uStack_44c._3_1_ = s_Input_test_paramter__00034f1c[15];
      local_448._0_1_ = s_Input_test_paramter__00034f1c[16];
      local_448._1_1_ = s_Input_test_paramter__00034f1c[17];
      local_448._2_1_ = s_Input_test_paramter__00034f1c[18];
      local_448._3_1_ = s_Input_test_paramter__00034f1c[19];
      local_444 = (undefined)ram0x00034f30;
      _applog(2,&local_458,0);
    }
    __isoc99_fscanf(stdin,&DAT_00034f34,local_28);
    if ((byte)local_28[0] - 0x61 < 0x17) break;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      local_458._0_1_ = s_unknow_command_00035148[0];
      local_458._1_1_ = s_unknow_command_00035148[1];
      local_458._2_1_ = s_unknow_command_00035148[2];
      local_458._3_1_ = s_unknow_command_00035148[3];
      uStack_454._0_1_ = s_unknow_command_00035148[4];
      uStack_454._1_1_ = s_unknow_command_00035148[5];
      uStack_454._2_1_ = s_unknow_command_00035148[6];
      uStack_454._3_1_ = s_unknow_command_00035148[7];
      uStack_450._0_1_ = s_unknow_command_00035148[8];
      uStack_450._1_1_ = s_unknow_command_00035148[9];
      uStack_450._2_1_ = s_unknow_command_00035148[10];
      uStack_450._3_1_ = s_unknow_command_00035148[11];
      uStack_44c._0_1_ = s_unknow_command_00035148[12];
      uStack_44c._1_1_ = s_unknow_command_00035148[13];
      uStack_44c._2_1_ = s_unknow_command_00035148[14];
      uStack_44c._3_1_ = s_unknow_command_00035148[15];
      _applog(1,&local_458,0);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00023294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00023298 + ((byte)local_28[0] - 0x61) * 4))();
  return;
}

