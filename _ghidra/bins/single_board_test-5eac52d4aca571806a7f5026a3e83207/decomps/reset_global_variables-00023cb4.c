
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_global_variables(void)

{
  int iVar1;
  uint uVar2;
  work_new *pwVar3;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t read_asic_num;
  work_new *work;
  work_new *works;
  uint32_t i;
  uint32_t num;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","reset_global_variables");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  send_id = 0;
  receive_id = 0;
  show_id = 0;
  pic_heart_beat_id = 0;
  read_temp_from_pic_id = 0;
  gStart_receive = false;
  gStart_heart_beat = false;
  gStart_show_on_lcd = false;
  gCooling = false;
  gHeating = false;
  gNoncing = false;
  gTemp_first_read_flag = false;
  gStart_read_temp_from_pic = false;
  gStart_read_temp_from_asic = false;
  gScanCodeGun_data_ready = '\0';
  gChain = 0xffffffff;
  gCode_gun_chain = 0xffffffff;
  gAsic_num = 0;
  gRead_Pic_Temperature_time_interval = 1;
  time_counter = 0;
  gSend_Work_Num = 0;
  gFind_dummy_data = false;
  gVol_comp = 0;
  if (reg_value_buf == (reg_buf *)0x0) {
    reg_value_buf = (reg_buf *)malloc(0x13ffc);
    if (reg_value_buf == (reg_buf *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : malloc reg_value_buf failed\n","reset_global_variables");
      builtin_strncpy(tmp1,"malloc reg_value_buf failed",0x1c);
      log_to_file(tmp1,time_stamp);
    }
    else {
      memset(reg_value_buf,0,0x13ffc);
    }
  }
  else {
    memset(reg_value_buf,0,0x13ffc);
  }
  iVar1 = strcmp(Local_Config_Information->Test_Process,"PT2");
  if (((((iVar1 == 0) || (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar1 == 0))
       || (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+"), iVar1 == 0)) &&
      ((((Local_Config_Information->Test_Info).Test_Method.Software_Pattern != false ||
        ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern != false)) ||
       ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern != false)))) &&
     ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != true)) {
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      uVar2 = (Local_Config_Information->Hash_Board).Asic_Num;
    }
    else {
      uVar2 = 1;
    }
    for (which_asic = 0; which_asic < uVar2; which_asic = which_asic + 1) {
      pwVar3 = pattern_info_new.works[which_asic];
      if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
        num = (Local_Config_Information->Hash_Board).Small_Core_Num;
      }
      else {
        num = (Local_Config_Information->Hash_Board).Big_Core_Num;
      }
      for (which_core = 0; which_core < num; which_core = which_core + 1) {
        for (which_pattern = 0;
            which_pattern < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
            which_pattern = which_pattern + 1) {
          pwVar3[which_pattern +
                 which_core * (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number].
          is_nonce_return_back = 0;
        }
      }
    }
  }
  init_history_result((uint)gPattern_test_counter);
  return;
}

