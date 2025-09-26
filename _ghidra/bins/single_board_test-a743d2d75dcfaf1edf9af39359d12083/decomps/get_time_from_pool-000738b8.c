
int get_time_from_pool(char *server_name,int server_port)

{
  int socket;
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *string;
  json_t *json;
  json_t *json_00;
  json_t *val_00;
  int server_port_local;
  char *server_name_local;
  char time_stamp [48];
  char tmp1 [2048];
  json_error_t err;
  char http_buf [8192];
  char *ntime;
  char *buf;
  json_t *params;
  json_t *method;
  char *msg;
  char *json_end_msg;
  json_t *val;
  int socket_fd;
  char *json_start_msg;
  int ret;
  
  memset(http_buf,0,0x2000);
  socket = http_tcpclient_create(server_name,server_port,false);
  ret = 0;
  if (socket < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: tcp client create failed\n","get_time_from_pool");
    builtin_strncpy(tmp1,"tcp client create failed",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    ret = -1;
  }
  else {
    memcpy(http_buf,"{\"id\":1, \"method\": \"mining.subscribe\", \"params\": [\"gominer/1.0.0\"]}",
           0x44);
    sVar1 = strlen(http_buf);
    (http_buf + sVar1)[0] = '\n';
    (http_buf + sVar1)[1] = '\0';
    sVar1 = strlen(http_buf);
    sVar1 = http_tcpclient_send(socket,http_buf,sVar1);
    sVar2 = strlen(http_buf);
    if (sVar1 == sVar2) {
      memcpy(http_buf,"{\"id\":2, \"method\": \"mining.authorize\", \"params\": [\"user\",\"123\"]}"
             ,0x41);
      sVar1 = strlen(http_buf);
      (http_buf + sVar1)[0] = '\n';
      (http_buf + sVar1)[1] = '\0';
      sVar1 = strlen(http_buf);
      sVar1 = http_tcpclient_send(socket,http_buf,sVar1);
      sVar2 = strlen(http_buf);
      if (sVar1 == sVar2) {
        iVar3 = http_tcpclient_recv(socket,http_buf);
        if (iVar3 < 1) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: tcp client recv failed\n","get_time_from_pool");
          builtin_strncpy(tmp1,"tcp client recv failed",0x17);
          log_to_file(tmp1,time_stamp);
          ret = -4;
        }
        else {
          json_start_msg = http_buf;
          while (pcVar4 = strchr(json_start_msg,10), pcVar4 != (char *)0x0) {
            string = (char *)malloc((size_t)(pcVar4 + (1 - (int)json_start_msg)));
            memcpy(string,json_start_msg,(int)pcVar4 - (int)json_start_msg);
            string[(int)pcVar4 - (int)json_start_msg] = '\0';
            json = json_loads(string,0,&err);
            free(string);
            json_start_msg = pcVar4 + 1;
            if (json == (json_t *)0x0) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: JSON decode failed(%d): %s\n","get_time_from_pool",err.line,err.text);
              snprintf(tmp1,0x800,"JSON decode failed(%d): %s",err.line,err.text);
              log_to_file(tmp1,time_stamp);
            }
            else {
              json_00 = json_object_get(json,"method");
              if (json_00 == (json_t *)0x0) {
                json_decref(json);
              }
              else {
                val_00 = json_object_get(json,"params");
                if (val_00 == (json_t *)0x0) {
                  json_decref(json);
                }
                else {
                  pcVar4 = json_string_value(json_00);
                  if (pcVar4 == (char *)0x0) {
                    json_decref(json);
                  }
                  else {
                    iVar3 = strncasecmp(pcVar4,"mining.notify",0xd);
                    if ((iVar3 == 0) &&
                       (pcVar4 = __json_array_string(val_00,7), pcVar4 != (char *)0x0)) {
                      set_time_based_notify_ntime(pcVar4);
                      json_decref(json);
                      goto LAB_00073ee8;
                    }
                    json_decref(json);
                  }
                }
              }
            }
          }
          ret = -5;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: tcp client send failed\n","get_time_from_pool");
        builtin_strncpy(tmp1,"tcp client send failed",0x17);
        log_to_file(tmp1,time_stamp);
        ret = -3;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: tcp client send failed\n","get_time_from_pool");
      builtin_strncpy(tmp1,"tcp client send failed",0x17);
      log_to_file(tmp1,time_stamp);
      ret = -2;
    }
LAB_00073ee8:
    http_tcpclient_close(socket);
  }
  return ret;
}

