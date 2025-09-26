
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_global_variables(void)

{
  int iVar1;
  work_new *pwVar2;
  work *pwVar3;
  char time_stamp [48];
  char tmp1 [2048];
  work *work;
  work *works;
  work_new *work_new;
  work_new *works_new;
  uint32_t i;
  uint32_t which_core;
  uint32_t which_pattern;
  uint32_t which_small_core;
  uint32_t which_big_core;
  uint32_t which_asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","reset_global_variables");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  send_id = 0;
  receive_id = 0;
  show_id = 0;
  pic_heart_beat_id = 0;
  read_temp_from_pic_id = 0;
  read_temp_from_asic_id = 0;
  gStart_receive = false;
  gStart_heart_beat = false;
  gStart_show_on_lcd = false;
  gCooling = false;
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
    reg_value_buf = (reg_buf *)malloc(0x27fc);
    if (reg_value_buf == (reg_buf *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: malloc reg_value_buf failed\n","reset_global_variables");
      builtin_strncpy(tmp1,"malloc reg_value_buf failed",0x1c);
      log_to_file(tmp1,time_stamp);
    }
    else {
      memset(reg_value_buf,0,0x27fc);
    }
  }
  else {
    memset(reg_value_buf,0,0x27fc);
  }
  iVar1 = strcmp(Local_Config_Information->Test_Process,"PT2");
  if ((((iVar1 == 0) ||
       (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1&PT3"), iVar1 == 0)) ||
      (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar1 == 0)) ||
     (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+"), iVar1 == 0)) {
    if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
      if (((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern != false) &&
         ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != true)) {
        for (which_asic = 0; which_asic < (Local_Config_Information->Hash_Board).Asic_Num;
            which_asic = which_asic + 1) {
          pwVar3 = pattern_info.works[which_asic];
          for (which_big_core = 0;
              which_big_core < (Local_Config_Information->Hash_Board).Big_Core_Num;
              which_big_core = which_big_core + 1) {
            for (which_small_core = 0;
                which_small_core < (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core
                ; which_small_core = which_small_core + 1) {
              for (which_pattern = 0;
                  which_pattern < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number
                  ; which_pattern = which_pattern + 1) {
                pwVar3[which_pattern +
                       (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
                       (which_big_core * 0x10 + which_small_core)].is_nonce_return_back = 0;
              }
            }
          }
        }
      }
    }
    else if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != true) {
      for (which_asic = 0; which_asic < (Local_Config_Information->Hash_Board).Asic_Num;
          which_asic = which_asic + 1) {
        pwVar2 = pattern_info_new.works[which_asic];
        for (which_big_core = 0;
            which_big_core < (Local_Config_Information->Hash_Board).Big_Core_Num;
            which_big_core = which_big_core + 1) {
          for (which_small_core = 0;
              which_small_core < (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core;
              which_small_core = which_small_core + 1) {
            for (which_pattern = 0;
                which_pattern < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
                which_pattern = which_pattern + 1) {
              pwVar2[which_pattern +
                     (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number *
                     (which_big_core * 0x10 + which_small_core)].is_nonce_return_back = 0;
            }
          }
        }
      }
    }
  }
  init_history_result((uint)gPattern_test_counter);
  return;
}

