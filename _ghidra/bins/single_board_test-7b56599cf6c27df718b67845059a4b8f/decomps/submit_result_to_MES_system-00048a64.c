
/* WARNING: Unknown calling convention */

_Bool submit_result_to_MES_system(void)

{
  _Bool _Var1;
  char *buffer;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t length;
  json_error_t error;
  char *submit_result_response;
  _Bool ret;
  json_t *response;
  
  response = (json_t *)0x0;
  length = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","submit_result_to_MES_system");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  _Var1 = create_connection_to_MES_system_by_name(2);
  if (_Var1) {
    _Var1 = send_message_to_bitmain_MES_system
                      (submit_result_handshake_information,mes_system_submit_result_file_length);
    if (_Var1) {
      buffer = receive_message_from_bitmain_MES_system(&length);
      if (buffer == (char *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : submit result fail\n","submit_result_to_MES_system");
        builtin_strncpy(tmp1,"submit result fa",0x10);
        tmp1[0x10] = 'i';
        tmp1[0x11] = 'l';
        tmp1[0x12] = '\0';
        log_to_file(tmp1,time_stamp);
        ret = false;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : length:%d,submit_result_response:%s\n","submit_result_to_MES_system",length,
               buffer);
        snprintf(tmp1,0x100,"length:%d,submit_result_response:%s",length,buffer);
        log_to_file(tmp1,time_stamp);
        response = json_loadb(buffer,length - 1,0,&error);
        if ((response == (json_t *)0x0) || (response->type != JSON_OBJECT)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Don\'t get all respons after submit result\n","submit_result_to_MES_system");
          builtin_strncpy(tmp1,"Don\'t get all respons after submit resul",0x28);
          tmp1[0x28] = 't';
          tmp1[0x29] = '\0';
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          _Var1 = check_whether_MES_system_submit_result_is_correct(response);
          if (_Var1) {
            ret = true;
          }
          else {
            ret = false;
          }
        }
        free(buffer);
      }
      if (response != (json_t *)0x0) {
        json_decref(response);
      }
      if (bitmain_MES_system_clientSocket != -1) {
        close(bitmain_MES_system_clientSocket);
        bitmain_MES_system_clientSocket = -1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : close socket\n","submit_result_to_MES_system");
        builtin_strncpy(tmp1,"close socket",0xc);
        tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : send submit result information fail\n","submit_result_to_MES_system");
      builtin_strncpy(tmp1,"send submit result information fail",0x24);
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
  }
  else {
    ret = false;
  }
  return ret;
}

