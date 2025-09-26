
int upload_data_to_server(repaire_info_t *p_repaire)

{
  json_t *object;
  json_t *array;
  json_t *object_00;
  json_t *pjVar1;
  char *__s;
  size_t sVar2;
  size_t sVar3;
  char *__ptr;
  repaire_info_t *p_repaire_local;
  char time_stamp [48];
  char tmp1 [256];
  char time_str [24];
  char *resp;
  char *json_str;
  json_t *upload_item;
  json_t *fixtureList;
  json_t *upload_data;
  int upload_succ;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : upload data...\n","upload_data_to_server");
  builtin_strncpy(tmp1,"upload data.",0xc);
  tmp1[0xc] = '.';
  tmp1[0xd] = '.';
  tmp1[0xe] = '\0';
  log_to_file(tmp1,time_stamp);
  upload_succ = 0;
  object = json_object();
  array = json_array();
  object_00 = json_object();
  if (((object == (json_t *)0x0) || (array == (json_t *)0x0)) || (object_00 == (json_t *)0x0)) {
    upload_succ = 0;
  }
  else {
    pjVar1 = json_string(p_repaire->sn);
    json_object_set(object_00,"sn",pjVar1);
    pjVar1 = json_integer((longlong)p_repaire->err);
    json_object_set(object_00,"faultStatus",pjVar1);
    if (p_repaire->err != 0) {
      pjVar1 = json_string(p_repaire->err_code);
      json_object_set(object_00,"faultCode",pjVar1);
    }
    pjVar1 = json_integer((longlong)p_repaire->test_process);
    json_object_set(object_00,"testingPhase",pjVar1);
    json_array_append(array,object_00);
    json_object_set(object,"fixtureList",array);
    __s = json_dumps(object,0x200);
    if (__s == (char *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : json dumps err\n\n","upload_data_to_server");
      builtin_strncpy(tmp1,"json dumps err\n",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      sVar2 = json_object_size(object);
      sVar3 = strlen(__s);
      printf("%s : json keys:%d,json_str len:%d\n\n","upload_data_to_server",sVar2,sVar3);
      sVar2 = json_object_size(object);
      sVar3 = strlen(__s);
      snprintf(tmp1,0x100,"json keys:%d,json_str len:%d\n",sVar2,sVar3);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s\n","upload_data_to_server",__s);
      snprintf(tmp1,0x100,"%s",__s);
      log_to_file(tmp1,time_stamp);
      __ptr = post_request("https://mes.plm.bitmain.vip:443/public/api/mes/rma/uploadTextFixture.json"
                           ,__s);
      if (__ptr == (char *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : resp no info\n\n","upload_data_to_server");
        builtin_strncpy(tmp1,"resp no info",0xc);
        tmp1[0xc] = '\n';
        tmp1[0xd] = '\0';
        log_to_file(tmp1,time_stamp);
      }
      else {
        puts("upload data succ");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : resp:\n%s\n\n","upload_data_to_server",__ptr);
        snprintf(tmp1,0x100,"resp:\n%s\n",__ptr);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : \n\n","upload_data_to_server");
        tmp1[0] = '\n';
        tmp1[1] = '\0';
        log_to_file(tmp1,time_stamp);
        free(__ptr);
      }
      upload_succ = (int)(__ptr != (char *)0x0);
      free(__s);
    }
    json_delete(object);
  }
  return upload_succ;
}

