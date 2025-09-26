
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void submit_test_result_to_mes(void)

{
  _Bool _Var1;
  int iVar2;
  uint test_loop_index;
  char time_stamp [48];
  char tmp1 [256];
  
  if ((Local_Config_Information->Test_Info).Factory_Mode != false) {
    test_loop_index = (uint)gPattern_test_counter;
    iVar2 = strncmp(Local_Config_Information->Test_Process,"SWEEP",5);
    if (((iVar2 == 0) ||
        (iVar2 = strncmp(Local_Config_Information->Test_Process,"PT3",3), iVar2 == 0)) ||
       (iVar2 = strncmp(Local_Config_Information->Test_Process,"DropLevel",9), iVar2 == 0)) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
    _Var1 = prepare_MES_system_submit_information(test_loop_index,_Var1);
    if (_Var1) {
      _Var1 = submit_result_to_MES_system();
      if (_Var1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : submit result ok\n","submit_test_result_to_mes");
        builtin_strncpy(tmp1,"submit result ok",0x10);
        tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : save result into SD card\n","submit_test_result_to_mes");
        builtin_strncpy(tmp1,"save result into SD card",0x18);
        tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        _Var1 = save_MES_system_submit_result();
        if (_Var1) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : save result into SD card success\n","submit_test_result_to_mes");
          builtin_strncpy(tmp1,"save result into SD card success",0x20);
          tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : save result into SD card fail\n","submit_test_result_to_mes");
          builtin_strncpy(tmp1,"save result into SD card fail",0x1e);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : prepare submit result information fail\n","submit_test_result_to_mes");
      builtin_strncpy(tmp1,"prepare submit result information fa",0x24);
      tmp1[0x24] = 'i';
      tmp1[0x25] = 'l';
      tmp1[0x26] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  return;
}

