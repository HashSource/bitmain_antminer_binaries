
char * receive_message_from_bitmain_MES_system(uint32_t *received_data_len)

{
  size_t __n;
  uint32_t *received_data_len_local;
  char time_stamp [48];
  char tmp1 [2048];
  char buf [10240];
  ssize_t ret;
  char *data;
  uint32_t j;
  uint32_t i;
  uint32_t received_data_length;
  
  received_data_length = 0;
  j = 0;
  memset(buf,0,0x2800);
  data = (char *)0x0;
  while( true ) {
    memset(buf,0,0x2800);
    __n = recv(bitmain_MES_system_clientSocket,buf,0x2800,0);
    if (__n == 0) {
      j = j + 1;
      sleep(1);
    }
    else {
      if ((int)__n < 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Receive message fail: %d\n","receive_message_from_bitmain_MES_system",__n);
        snprintf(tmp1,0x800,"Receive message fail: %d",__n);
        log_to_file(tmp1,time_stamp);
        return (char *)0x0;
      }
      if (data == (char *)0x0) {
        data = (char *)malloc(__n);
        if (data == (char *)0x0) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"malloc for");
          lcd_show(2,"MES config");
          lcd_show(3,"infor fail");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: malloc for MES config infor fail\n","receive_message_from_bitmain_MES_system")
          ;
          builtin_strncpy(tmp1,"malloc for MES config infor fail",0x20);
          tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          return (char *)0x0;
        }
        memcpy(data,buf,__n);
        received_data_length = __n;
      }
      else {
        data = (char *)realloc(data,received_data_length + __n);
        if (data == (char *)0x0) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"realloc for");
          lcd_show(2,"MES config");
          lcd_show(3,"infor fail");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: realloc for MES config infor fail\n","receive_message_from_bitmain_MES_system"
                );
          builtin_strncpy(tmp1,"realloc for MES config infor fail",0x22);
          log_to_file(tmp1,time_stamp);
          return (char *)0x0;
        }
        memcpy(data + received_data_length,buf,__n);
        received_data_length = __n + received_data_length;
      }
      j = 0;
    }
    if (data[received_data_length - 1] == '\n') break;
    if (6 < j) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Only receive %d bytes message during last 6 seconds\n",
             "receive_message_from_bitmain_MES_system",received_data_length);
      snprintf(tmp1,0x800,"Only receive %d bytes message during last 6 seconds",received_data_length
              );
      log_to_file(tmp1,time_stamp);
      for (i = 0; i < received_data_length; i = i + 1) {
        putchar((uint)(byte)data[i]);
      }
      putchar(10);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Not receive all");
      lcd_show(2,"MES config");
      lcd_show(3,"information");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Not receive all MES config information\n",
             "receive_message_from_bitmain_MES_system");
      builtin_strncpy(tmp1,"Not receive all MES config informati",0x24);
      tmp1[0x24] = 'o';
      tmp1[0x25] = 'n';
      tmp1[0x26] = '\0';
      log_to_file(tmp1,time_stamp);
      return (char *)0x0;
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Receive total message length: %d\n","receive_message_from_bitmain_MES_system",
         received_data_length);
  snprintf(tmp1,0x800,"Receive total message length: %d",received_data_length);
  log_to_file(tmp1,time_stamp);
  *received_data_len = received_data_length;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Receive all message from MES system\n","receive_message_from_bitmain_MES_system");
  builtin_strncpy(tmp1,"Receive all message from MES system",0x24);
  log_to_file(tmp1,time_stamp);
  return data;
}

