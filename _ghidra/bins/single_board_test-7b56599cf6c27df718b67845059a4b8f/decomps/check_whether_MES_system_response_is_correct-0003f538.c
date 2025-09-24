
/* WARNING: Unknown calling convention */

_Bool check_whether_MES_system_response_is_correct(void)

{
  json_t *json;
  json_t *pjVar1;
  char *pcVar2;
  int iVar3;
  char time_stamp [48];
  char tmp1 [256];
  json_t *msg;
  json_t *code;
  json_t *result;
  _Bool ret;
  
  json = json_object_get(MES_system_config_File,"result");
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Don\'t find");
    lcd_show(2,"result in MES");
    lcd_show(3,"system response");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Don\'t find result in MES system responce\n",
           "check_whether_MES_system_response_is_correct");
    builtin_strncpy(tmp1,"Don\'t find result in MES system responce",0x28);
    tmp1._40_2_ = (ushort)(byte)tmp1[0x29] << 8;
    log_to_file(tmp1,time_stamp);
    ret = false;
  }
  else {
    pjVar1 = json_object_get(json,"code");
    if ((pjVar1 == (json_t *)0x0) || (pjVar1->type != JSON_STRING)) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Don\'t find");
      lcd_show(2,"code in MES");
      lcd_show(3,"system response");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Don\'t get code in result\n","check_whether_MES_system_response_is_correct");
      builtin_strncpy(tmp1,"Don\'t get code in result",0x18);
      tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      ret = false;
    }
    else {
      pcVar2 = json_string_value(pjVar1);
      iVar3 = strcmp(pcVar2,"000000");
      if (iVar3 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Get MES system config information success\n",
               "check_whether_MES_system_response_is_correct");
        builtin_strncpy(tmp1,"Get MES system config information succes",0x28);
        tmp1[0x28] = 's';
        tmp1[0x29] = '\0';
        log_to_file(tmp1,time_stamp);
        ret = true;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        pcVar2 = json_string_value(pjVar1);
        printf("%s : Get MES system config information fail. code: %s\n",
               "check_whether_MES_system_response_is_correct",pcVar2);
        pcVar2 = json_string_value(pjVar1);
        snprintf(tmp1,0x100,"Get MES system config information fail. code: %s",pcVar2);
        log_to_file(tmp1,time_stamp);
        pjVar1 = json_object_get(json,"msg");
        if ((pjVar1 == (json_t *)0x0) || (pjVar1->type != JSON_STRING)) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Don\'t find");
          lcd_show(2,"msg in MES");
          lcd_show(3,"system response");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Don\'t get msg in result\n\n","check_whether_MES_system_response_is_correct")
          ;
          builtin_strncpy(tmp1,"Don\'t get msg in result\n",0x18);
          tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
        else {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"MES system");
          lcd_show(2,"return error");
          lcd_show(3,"response");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          pcVar2 = json_string_value(pjVar1);
          printf("%s : Get MES system config information fail. msg: %s\n",
                 "check_whether_MES_system_response_is_correct",pcVar2);
          pcVar2 = json_string_value(pjVar1);
          snprintf(tmp1,0x100,"Get MES system config information fail. msg: %s",pcVar2);
          log_to_file(tmp1,time_stamp);
          ret = false;
        }
      }
    }
  }
  if (json != (json_t *)0x0) {
    json_decref(json);
  }
  return ret;
}

