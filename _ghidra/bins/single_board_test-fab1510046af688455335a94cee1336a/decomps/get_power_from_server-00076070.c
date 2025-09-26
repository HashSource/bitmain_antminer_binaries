
int32_t get_power_from_server(char *server_ip,int32_t port,uint32_t *power_result)

{
  char *string;
  json_t *json;
  json_t *json_00;
  json_int_t jVar1;
  uint32_t *power_result_local;
  int32_t port_local;
  char *server_ip_local;
  char time_stamp [48];
  char tmp1 [2048];
  json_error_t err;
  char url [128];
  int32_t power_value;
  json_t *power_val;
  char *power_info_json;
  json_t *val;
  int32_t ret;
  
  ret = 0;
  memset(url,0,0x80);
  sprintf(url,"http://%s:%d/api/v1/power",server_ip,port);
  string = http_get(url,true,false);
  if (string == (char *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: http get failed\n","get_power_from_server");
    builtin_strncpy(tmp1,"http get failed",0x10);
    log_to_file(tmp1,time_stamp);
    ret = -1;
  }
  else {
    json = json_loads(string,0,&err);
    if (json == (json_t *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: JSON decode failed(%d): %s\n","get_power_from_server",err.line,err.text);
      snprintf(tmp1,0x800,"JSON decode failed(%d): %s",err.line,err.text);
      log_to_file(tmp1,time_stamp);
      ret = -1;
    }
    else {
      json_00 = json_object_get(json,"power");
      if (json_00 == (json_t *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: no json object [power] found\n","get_power_from_server");
        builtin_strncpy(tmp1,"no json object [power] found",0x1c);
        tmp1[0x1c] = '\0';
        log_to_file(tmp1,time_stamp);
        ret = -1;
      }
      else {
        jVar1 = json_integer_value(json_00);
        if ((int)(uint32_t)jVar1 < 1) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: IP not found.\n","get_power_from_server");
          builtin_strncpy(tmp1,"IP not found",0xc);
          tmp1[0xc] = '.';
          tmp1[0xd] = '\0';
          log_to_file(tmp1,time_stamp);
          ret = -1;
        }
        else {
          *power_result = (uint32_t)jVar1;
        }
      }
    }
    json_decref(json);
    free(string);
  }
  return ret;
}

