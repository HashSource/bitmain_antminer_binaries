
_Bool send_message_to_bitmain_MES_system(char *data,int32_t data_len)

{
  undefined4 uVar1;
  ssize_t sVar2;
  int32_t data_len_local;
  char *data_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t send_counter;
  ssize_t i;
  _Bool ret;
  uint8_t max_send_counter;
  
  max_send_counter = '\x05';
  ret = false;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","send_message_to_bitmain_MES_system");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  do {
    if (max_send_counter == '\0') {
LAB_0007671e:
      if (ret != true) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"send message to");
        lcd_show(2,"MES system");
        lcd_show(3,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: send message to MES system fail\n","send_message_to_bitmain_MES_system");
        builtin_strncpy(tmp1,"send message to MES system fail",0x20);
        log_to_file(tmp1,time_stamp);
      }
      return ret;
    }
    sVar2 = send(bitmain_MES_system_clientSocket,data,data_len,0);
    if (sVar2 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Timeout. MES close socket\n","send_message_to_bitmain_MES_system");
      uVar1 = tmp1._24_4_;
      builtin_strncpy(tmp1,"Timeout. MES close socket",0x1a);
      tmp1._26_2_ = SUB42(uVar1,2);
      log_to_file(tmp1,time_stamp);
    }
    else {
      if (-1 < sVar2) {
        ret = true;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: done\n","send_message_to_bitmain_MES_system");
        builtin_strncpy(tmp1,"done",4);
        tmp1._4_4_ = tmp1._4_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        goto LAB_0007671e;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Socket return back: %d\n","send_message_to_bitmain_MES_system",sVar2);
      snprintf(tmp1,0x800,"Socket return back: %d",sVar2);
      log_to_file(tmp1,time_stamp);
    }
    max_send_counter = max_send_counter + '\x01';
  } while( true );
}

