
_Bool check_whether_MES_system_submit_result_is_correct(json_t *response)

{
  json_t *json;
  char *pcVar1;
  int iVar2;
  json_t *response_local;
  char time_stamp [48];
  char tmp1 [2048];
  json_t *result;
  _Bool ret;
  json_t *msg;
  json_t *code;
  
  code = (json_t *)0x0;
  msg = (json_t *)0x0;
  json = json_object_get(response,"result");
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t find result in submit result responce\n",
           "check_whether_MES_system_submit_result_is_correct");
    builtin_strncpy(tmp1,"Don\'t find result in submit result responce",0x2c);
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    code = json_object_get(json,"code");
    if ((code == (json_t *)0x0) || (code->type != JSON_STRING)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Don\'t get code in result\n\n","check_whether_MES_system_submit_result_is_correct"
            );
      builtin_strncpy(tmp1,"Don\'t get code in result\n",0x1a);
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pcVar1 = json_string_value(code);
      iVar2 = strcmp(pcVar1,"000000");
      if (iVar2 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: submit result success\n\n","check_whether_MES_system_submit_result_is_correct");
        builtin_strncpy(tmp1,"submit result success\n",0x17);
        log_to_file(tmp1,time_stamp);
        ret = true;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        pcVar1 = json_string_value(code);
        printf("%s: submit result fail! code: %s\n\n",
               "check_whether_MES_system_submit_result_is_correct",pcVar1);
        pcVar1 = json_string_value(code);
        snprintf(tmp1,0x800,"submit result fail! code: %s\n",pcVar1);
        log_to_file(tmp1,time_stamp);
        msg = json_object_get(json,"msg");
        if ((msg == (json_t *)0x0) || (msg->type != JSON_STRING)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Don\'t get msg in result\n\n",
                 "check_whether_MES_system_submit_result_is_correct");
          builtin_strncpy(tmp1,"Don\'t get msg in result\n",0x18);
          tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          pcVar1 = json_string_value(msg);
          printf("%s: submit result fail! msg: %s\n\n",
                 "check_whether_MES_system_submit_result_is_correct",pcVar1);
          pcVar1 = json_string_value(msg);
          snprintf(tmp1,0x800,"submit result fail! msg: %s\n",pcVar1);
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
      }
    }
  }
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  if (code != (json_t *)0x0) {
    json_decref(code);
  }
  if (msg != (json_t *)0x0) {
    json_decref(msg);
  }
  return ret;
}

